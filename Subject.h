//
// Created by Andrea Ferritti on 24/02/24.
//

#ifndef NOTES_MANAGER_SUBJECT_H
#define NOTES_MANAGER_SUBJECT_H

#include "Observer.h"


class Subject {
public:
    virtual void addObserver(Observer *o) = 0;
    virtual void removeObserver(Observer *o) = 0;
    virtual void notify() = 0;
    virtual ~Subject() = default;
};


#endif //NOTES_MANAGER_SUBJECT_H
