//
// Created by Andrea Ferritti on 04/03/24.
//

#ifndef NOTES_MANAGER_CONTROLPANEL_H
#define NOTES_MANAGER_CONTROLPANEL_H

#include "Observer.h"
#include <list>
#include "Subject.h"
#include "NotesCollection.h"


class ControlPanel : public Observer{
public:
    explicit ControlPanel(const std::list<Subject*>& c);

    void addCollection(Subject* collection);
    void removeCollection(Subject* c);

    void update() override;

    int getCollectionNum() const {
        return collections.size();
    }


private:
    std::list<Subject*> collections;
};


#endif //NOTES_MANAGER_CONTROLPANEL_H
