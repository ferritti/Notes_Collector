//
// Created by Andrea Ferritti on 04/03/24.
//

#include "ControlPanel.h"

ControlPanel::ControlPanel(const std::list<Subject*>& c) : collections(c), collectionNum(c.size()) {
    for (const auto &c : collections) {
        auto collection = dynamic_cast<NotesCollection *>(c);
        if (collection) {
            collection->addObserver(this);
        }
        else
            throw std::runtime_error("The collection is not a NotesCollection");
    }
}

void ControlPanel::addCollection(Subject* c) {
    auto collection = dynamic_cast<NotesCollection*>(c);
    if(collection){
        collections.push_back(collection);
        collection->addObserver(this);
        collectionNum++;
    }
    else
        throw std::runtime_error("The collection is not a NotesCollection");
}

void ControlPanel::removeCollection(Subject* collection) {
    if (collection){
        collections.remove(collection);
        collection->removeObserver(this);
        collectionNum--;
    }
    else
        throw std::runtime_error("The collection is not a NotesCollection");
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
            else
                throw std::runtime_error("The collection is not a NotesCollection");
        }
    }
    else
        throw std::runtime_error("There is no collections");
}

