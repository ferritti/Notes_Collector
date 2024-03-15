//
// Created by Andrea Ferritti on 05/03/24.
//

#include "gtest/gtest.h"
#include "../ControlPanel.h"
#include "../NotesCollection.h"

class ControlPanelTest : public ::testing::Test {
    protected:
    void SetUp() override {
        collection1 = new NotesCollection("Collection 1");
        collection2 = new NotesCollection("Collection 2");
        controlPanel = new ControlPanel({collection1, collection2});
    }
    void TearDown() override {
        delete collection1;
        delete collection2;
        delete controlPanel;
    }
    NotesCollection* collection1;
    NotesCollection* collection2;
    ControlPanel* controlPanel;
};

TEST_F(ControlPanelTest, ConstructorTest) {
    ASSERT_EQ(controlPanel->getCollectionNum(), 2);
}

TEST_F(ControlPanelTest, AddCollectionTest) {
    auto* collection3 = new NotesCollection("Collection 3");
    controlPanel->addCollection(collection3);
    ASSERT_EQ(controlPanel->getCollectionNum(), 3);
    delete collection3;
}

TEST_F(ControlPanelTest, RemoveCollectionTest) {
    controlPanel->removeCollection(collection1);
    ASSERT_EQ(controlPanel->getCollectionNum(), 1);
    controlPanel->removeCollection(collection2);
    ASSERT_EQ(controlPanel->getCollectionNum(), 0);
}

TEST_F(ControlPanelTest, UpdateTest) {
    try {
        controlPanel->update();
    }
    catch (std::runtime_error& e) {
        ASSERT_STREQ(e.what(), "There is no collections");
    }

    controlPanel->addCollection(collection1);
    try{
        controlPanel->update();
    }
    catch (std::runtime_error& e){
        ASSERT_STREQ(e.what(), "Collection Collection 1 has 0 notes");
    }

    collection1->addNote(std::make_shared<Note>("Note 1", "Text 1"));
    try {
        controlPanel->update();
    }
    catch (std::runtime_error& e) {
        ASSERT_STREQ(e.what(), "Collection Collection 1 has 1 note");
    }

    controlPanel->addCollection(collection2);
    try {
        controlPanel->update();
    }
    catch (std::runtime_error& e) {
        ASSERT_STREQ(e.what(), "Collection Collection 1 has 1 notesCollection Collection 2 has 0 notes");
    }

    collection2->addNote(std::make_shared<Note>("Note 2", "Text 2"));
    collection2->addNote(std::make_shared<Note>("Note 3", "Text 3"));
    try {
        controlPanel->update();
    }
    catch (std::runtime_error& e) {
        ASSERT_STREQ(e.what(), "Collection Collection 1 has 1 notesCollection Collection 2 has 2 notes");
    }
}



