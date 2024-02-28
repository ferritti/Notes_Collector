//
// Created by Andrea Ferritti on 28/02/24.
//

#ifndef NOTES_MANAGER_NOTE_H
#define NOTES_MANAGER_NOTE_H

#include <iostream>

/*Ogni nota è composta da titolo e testo, può essere bloccata per evitarne cancellazione/modifica*/

class Note {
public:
    Note(std::string ti, std::string te, bool l = false) : title(std::move(ti)), text(std::move(te)), locked(l){}

    const std::string &getTitle() const {
        return title;
    }

    void setTitle(const std::string &ti) {
        title = ti;
    }

    const std::string &getText() const {
        return text;
    }

    void setText(const std::string &te) {
        text = te;
    }

    bool isLocked() const {
        return locked;
    }

    void setLocked(bool l) {
        locked = l;
    }

private:
    std::string title;
    std::string text;
    bool locked;

};

#endif //NOTES_MANAGER_NOTE_H
