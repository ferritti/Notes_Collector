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
    ControlPanel();

    ~ControlPanel() override;

    void update() override;

    int getCollectionNum() const;


private:
    std::list<Subject*> collections;
    int collectionNum;
};


#endif //NOTES_MANAGER_CONTROLPANEL_H
