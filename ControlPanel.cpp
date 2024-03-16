//
// Created by Andrea Ferritti on 04/03/24.
//

#include "ControlPanel.h"

ControlPanel::ControlPanel(const std::list<Subject*>& c) : collections(c) {
    for (const auto &c : collections) {
        auto collection = dynamic_cast<NotesCollection *>(c);
        if (collection)
            collection->addObserver(this);
    }
}

void ControlPanel::addCollection(Subject* c) {
    auto collection = dynamic_cast<NotesCollection*>(c);
    if(collection){
        collections.push_back(collection);
        collection->addObserver(this);
    }
}

void ControlPanel::removeCollection(Subject* c) {
    auto collection = dynamic_cast<NotesCollection*>(c);
    if (collection){
        collections.remove(collection);
        c->removeObserver(this);
    }
}

void ControlPanel::update() {
    for (const auto &c: collections) {
        auto collection = dynamic_cast<NotesCollection *>(c);
        if (collection)
            std::cout << "Collection " << collection->getName() << " has " << collection->getNoteNum() << " notes";
    }
}