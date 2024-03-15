//
// Created by Andrea Ferritti on 04/03/24.
//

#include "gtest/gtest.h"
#include "../Note.h"

TEST(NoteTest, ConstructorTest) {
    Note n("title", "text", false);
    ASSERT_EQ(n.getTitle(), "title");
    ASSERT_EQ(n.getText(), "text");
    ASSERT_FALSE(n.isLocked());
}

TEST(NoteTest, GettersTest) {
    Note n("title", "text", false);
    ASSERT_EQ(n.getTitle(), "title");
    ASSERT_EQ(n.getText(), "text");
    ASSERT_FALSE(n.isLocked());
}

TEST(NoteTest, SettersTest) {
    Note n("title", "text", false);
    n.setTitle("new title");
    n.setText("new text");
    n.setLocked(true);
    ASSERT_EQ(n.getTitle(), "new title");
    ASSERT_EQ(n.getText(), "new text");
    ASSERT_TRUE(n.isLocked());
}

TEST(NoteTest, LockedTest) {
    Note n("title", "text", false);
    n.setLocked(true);
    ASSERT_THROW(n.setTitle("new title"), std::runtime_error);
    ASSERT_THROW(n.setText("new text"), std::runtime_error);
}

TEST(NoteTest, ExceptionNoteTest) {
    Note n("title", "text", true);
    try {
        n.setTitle("new title");
    } catch (std::runtime_error &e) {
        ASSERT_STREQ(e.what(), "Note is blocked");
    }

    try {
        n.setText("new text");
    } catch (std::runtime_error &e) {
        ASSERT_STREQ(e.what(), "Note is blocked");
    }
}
