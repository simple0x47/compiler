//
// Created by Gabriel Amihalachioaie on 08.01.2023.
//

#include "gtest/gtest.h"
#include "../src/utils.h"

TEST(StringSplit, NullOptWhenEmptyArguments) {
  optional<list<string>> result = string_split("", "");

  ASSERT_EQ(nullopt, result);
}

TEST(StringSplit, FirstEmptyWhenDelimiterAppearsAtTheStart) {
  optional<list<string>> result = string_split(";ABCD", ";");

  ASSERT_NE(nullopt, result);
  ASSERT_FALSE(result.value().empty());
  ASSERT_EQ("", *result.value().begin());
}

TEST(StringSplit, SingleItemReturnedWhenDelimiterIsNotWithinString) {
  optional<list<string>> result = string_split("ABCD", ";");

  ASSERT_NE(nullopt, result);
  ASSERT_FALSE(result.value().empty());
  ASSERT_EQ("ABCD", *result.value().begin());
}

TEST(StringSplit, SplitMultipleItemsCorrectly) {
  const int EXPECTED_ITEMS = 5;
  const string VALUE_TO_BE_SPLIT = ";A;B;C;D;";

  optional<list<string>> result = string_split(VALUE_TO_BE_SPLIT, ";");

  ASSERT_NE(nullopt, result);
  ASSERT_EQ(EXPECTED_ITEMS, result.value().size());

  auto value = result.value().begin();

  ASSERT_EQ("", *value);

  for (int i = 0; i < EXPECTED_ITEMS - 1; i++) {
    advance(value, 1);

    // Characters fall on odd numbers.
    // Therefore, we use the odd numbers' formula: 2n + 1.
    ASSERT_EQ(VALUE_TO_BE_SPLIT.substr((2 * i) + 1, 1), *value);
  }
}

TEST(StringSplit, EmptyElementForEachDelimiter) {
  const int EXPECTED_ITEMS = 4;

  optional<list<string>> result = string_split(";;;;", ";");

  ASSERT_NE(nullopt, result);
  ASSERT_EQ(EXPECTED_ITEMS, result.value().size());

  auto value = result.value().begin();

  for (int i = 0; i < EXPECTED_ITEMS; i++) {
    ASSERT_EQ("", *value);
    advance(value, 1);
  }
}