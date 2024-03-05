#include <iostream>
#include "Note.h"
#include "NotesCollection.h"
#include "ControlPanel.h"
#include <list>


int main() {
    std::shared_ptr<Note> Note1 = std::make_shared<Note>("Note 1", "This is the first note.");
    std::shared_ptr<Note> Note2 = std::make_shared<Note>("Note 2", "This is the second note.");

    auto collection1 = new NotesCollection("First Collection");
    auto collection2 = new NotesCollection("Second Collection");

    collection1->addNote(Note1);
    collection1->addNote(Note2);

    collection1->removeNote("Note 1");

    std::cout << "First collection has: " << collection1->getNoteNum() << " notes" << "\n" << std::endl;
    std::cout << "Second collection has: " << collection2->getNoteNum() << " notes" << "\n" << std::endl;

    auto collection3 = new NotesCollection("Third Collection");

    auto controlPanel = new ControlPanel({collection1, collection2});
    controlPanel->addCollection(collection3);
    std::cout << "Control panel has: " << controlPanel->getCollectionNum() << " collections" << std::endl;

    return 0;
}

/*Classi che rappresentano note (es. Bear / Evernote). Ogni nota è composta da titolo e testo, può essere
bloccata per evitarne cancellazione/modifica e fa parte di una collezione specificata con nome.
Può anche far parte di una collezione di note importanti oltre che di una collezione specifica.
Usare Observer per indicare quante note stanno in una collezione.*/