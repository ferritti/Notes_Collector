//
// Created by Andrea Ferritti on 04/03/24.
//

#include "ControlPanel.h"


ControlPanel::ControlPanel() : collectionNum(0) {
    for (const auto &c : collections) {
        auto collection = dynamic_cast<NotesCollection *>(c);
        if (collection) {
            collection->addObserver(this);
            collectionNum++;
        }
    }
}

ControlPanel::~ControlPanel() noexcept {
    for (const auto &c : collections) {
        auto collection = dynamic_cast<NotesCollection *>(c);
        if (collection){
            collection->removeObserver(this);
            collectionNum--;
        }
    }
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