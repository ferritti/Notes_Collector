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
    NotesCollection* collection3 = new NotesCollection("Collection 3");
    controlPanel->addCollection(collection3);
    ASSERT_EQ(controlPanel->getCollectionNum(), 3);
    delete collection3;
}

TEST_F(ControlPanelTest, RemoveCollectionTest) {
    controlPanel->removeCollection(collection1);
    ASSERT_EQ(controlPanel->getCollectionNum(), 1);
}

