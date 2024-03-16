//
// Created by Andrea Ferritti on 28/02/24.
//

#include "NotesCollection.h"

void NotesCollection::addObserver(Observer *o) {
    observers.push_back(o);
}

void NotesCollection::removeObserver(Observer *o) {
    observers.remove(o);
}

void NotesCollection::notify() {
    for (const auto &o : observers)
        o->update();
}

const std::string &NotesCollection::getName() const {
    return name;
}

void NotesCollection::setName(const std::string &n) {
    name = n;
}

void NotesCollection::addNote(const std::shared_ptr<Note> &note) {
    for (const auto &n : notes) {
        if (n->getTitle() == note->getTitle())
            throw std::runtime_error("Note already exists");
    }
    notes.push_back(note);
    notify();
}

void NotesCollection::removeNote(const std::string &title) {
    for (const auto &n : notes) {
        if (n->getTitle() == title) {
            if (n->isLocked())
                throw std::runtime_error("Note is blocked");
            else {
                notes.remove(n);
                notify();
                break;
            }
        }
        if (n == notes.back())
            throw std::runtime_error("Note not found");
    }
}


