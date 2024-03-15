//
// Created by Andrea Ferritti on 28/02/24.
//

#include "Note.h"

void Note::setTitle(const std::string &ti){
    if(!locked)
        title = ti;
    else
        throw std::runtime_error("Note is blocked");
}

void Note::setText(const std::string &te){
    if(!locked)
        text = te;
    else
        throw std::runtime_error("Note is blocked");
}

