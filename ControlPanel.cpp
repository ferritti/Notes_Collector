//
// Created by Andrea Ferritti on 04/03/24.
//

#include "ControlPanel.h"

ControlPanel::ControlPanel(const std::list<Subject*>& c) : collections(c), collectionNum(c.size()) {
    for(const auto& collection : collections){
        collection->addObserver(this);
    }
}

void ControlPanel::addCollection(Subject* collection) {
    collections.push_back(collection);
    collection->addObserver(this);
    collectionNum++;
}

void ControlPanel::removeCollection(Subject* collection) {
    collections.remove(collection);
    collection->removeObserver(this);
    collectionNum--;
}

void ControlPanel::update() {
    if(collectionNum!=0){
        for(const auto& c : collections){
            auto collection = dynamic_cast<NotesCollection*>(c);
            if(collection){
                if(collection->getNoteNum() == 1)
                    std::cout<<"Collection"<<collection->getName()<< "has 1 note";
                else
                    std::cout<<"Collection"<<collection->getName()<< "has" << collection->getNoteNum() << "notes";
            }
        }
    }
    else
        throw std::runtime_error("There is no collections");
}

