//
// Created by Andrea Ferritti on 05/03/24.
//

#include "gtest/gtest.h"
#include "../Note.h"
#include "../NotesCollection.h"

class NotesCollectionTest : public ::testing::Test {
protected:
    void SetUp() override {
        note1 = std::make_shared<Note>("Note 1", "Text 1");
        note2 = std::make_shared<Note>("Note 2", "Text 2");
    }
    void TearDown() override {
        note1.reset();
        note2.reset();
    }
    NotesCollection collection = NotesCollection("Collection");
    std::shared_ptr<Note> note1;
    std::shared_ptr<Note> note2;
};

TEST_F(NotesCollectionTest, ConstructorTest) {
    ASSERT_EQ(collection.getName(), "Collection");
    ASSERT_EQ(collection.getNoteNum(), 0);
}

TEST_F(NotesCollectionTest, AddNoteTest) {
    collection.addNote(note1);
    ASSERT_EQ(collection.getNoteNum(), 1);
    collection.addNote(note2);
    ASSERT_EQ(collection.getNoteNum(), 2);
}

TEST_F(NotesCollectionTest, RemoveNoteTest) {
    collection.addNote(note1);
    collection.addNote(note2);
    collection.removeNote("Note 1");
    ASSERT_EQ(collection.getNoteNum(), 1);
    collection.removeNote("Note 2");
    ASSERT_EQ(collection.getNoteNum(), 0);
}

TEST_F(NotesCollectionTest, SettersTest) {
    collection.setName("New Name");
    ASSERT_EQ(collection.getName(), "New Name");
    collection.setImportantCollection(true);
    ASSERT_TRUE(collection.isImportantCollection());
    collection.setImportantCollection(false);
    ASSERT_FALSE(collection.isImportantCollection());
    collection.setNoteNum(5);
    ASSERT_EQ(collection.getNoteNum(), 5);
}

TEST_F(NotesCollectionTest, GettersTest) {
    collection.addNote(note1);
    collection.addNote(note2);
    ASSERT_EQ(collection.getNoteNum(), 2);
    ASSERT_EQ(collection.getName(), "Collection");
    ASSERT_FALSE(collection.isImportantCollection());
}

TEST_F(NotesCollectionTest, AddNoteExceptionTest) {
    collection.addNote(note1);
    ASSERT_THROW(collection.addNote(note1), std::runtime_error);
}

TEST_F(NotesCollectionTest, RemoveNoteExceptionTest) {
    collection.addNote(note1);
    note1->setLocked(true);
    ASSERT_THROW(collection.removeNote("Note 1"), std::runtime_error);
    note1->setLocked(false);
    ASSERT_THROW(collection.removeNote("Note 2"), std::runtime_error);
    ASSERT_THROW(collection.removeNote("Note 3"), std::runtime_error);
}

























