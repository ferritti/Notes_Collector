//
// Created by Andrea Ferritti on 24/02/24.
//

#ifndef NOTES_MANAGER_OBSERVER_H
#define NOTES_MANAGER_OBSERVER_H


class Observer {
public:
    virtual void update() = 0;
    virtual ~Observer() = default;
};

#endif //NOTES_MANAGER_OBSERVER_H
