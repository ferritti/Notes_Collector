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
    n.setTitle("newTitle");
    n.setText("newText");
    n.setLocked(true);
    ASSERT_EQ(n.getTitle(), "newTitle");
    ASSERT_EQ(n.getText(), "newText");
    ASSERT_TRUE(n.isLocked());
}


