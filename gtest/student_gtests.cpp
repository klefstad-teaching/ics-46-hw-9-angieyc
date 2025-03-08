#include <gtest/gtest.h>
#include <set>
#include <vector>

#include "dijkstras.h"
#include "ladder.h"

// TEST(Replace, Me) {
//   EXPECT_TRUE(false);
// }

TEST(EditDistance, Neighbors) {
	ASSERT_TRUE(edit_distance_within("cat", "chat", 1));
}

TEST(EditDistance, NotNeighbors) {
	ASSERT_FALSE(edit_distance_within("cat", "cheat", 1));
}

TEST(EditDistance, Neighbors2) {
	ASSERT_TRUE(edit_distance_within("cat", "cats", 1));
}

TEST(EditDistance, NotNeighbors2) {
	ASSERT_FALSE(edit_distance_within("hello", "hello", 1));
}

TEST(EditDistance, Neighbors3) {
	ASSERT_TRUE(edit_distance_within("cog", "cot", 1));
}

TEST(EditDistance, NotNeighbors3) {
	ASSERT_FALSE(edit_distance_within("chat", "cheating", 1));
}

TEST(EditDistance, NotNeighbors4) {
	ASSERT_FALSE(edit_distance_within("phone", "airphone", 1));
}

TEST(IsAdjacent, Neighbors) {
	ASSERT_TRUE(is_adjacent("chat", "cheat"));
}

TEST(IsAdjacent, NotNeighbors) {
	ASSERT_FALSE(is_adjacent("chat", "cheating"));
}
