//
// Created by Andrea Ferritti on 28/02/24.
//

#ifndef NOTES_MANAGER_NOTESCOLLECTION_H
#define NOTES_MANAGER_NOTESCOLLECTION_H

/*Ogni nota fa parte di una collezione specificata con nome, la collezione può essere importante.*/

#include <iostream>
#include "Note.h"
#include <list>
#include <utility>
#include "Subject.h"
#include "Observer.h"

class NotesCollection : public Subject{
public:
    NotesCollection(int noteNum, std::string  n, bool i) : noteNum(noteNum), name(std::move(n)), importantCollection(i){}

    void addObserver(Observer *o) override;
    void removeObserver(Observer *o) override;
    void notify() override;

    int getNoteNum() const;
    void setNoteNum(int num);

    const std::string &getName() const;
    void setName(const std::string &n);

    void addNote(const std::shared_ptr<Note>& note);
    void removeNote(const std::shared_ptr<Note>& note);

    bool isImportantCollection() const {
        return importantCollection;
    }

    void setImportantCollection(bool i) {
        importantCollection = i;
    }

private:
    int noteNum;
    std::string name;
    std::list <std::shared_ptr<Note>> notes;
    std::list <Observer*> observers;
    bool importantCollection;
};


#endif //NOTES_MANAGER_NOTESCOLLECTION_H
