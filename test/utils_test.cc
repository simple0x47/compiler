//
// Created by Gabriel Amihalachioaie on 08.01.2023.
//

#include "gtest/gtest.h"
#include "../src/utils.h"

TEST(Utils, NullOptWhenEmptyArguments) {
  optional<list<string>> result = string_split("", "");

  ASSERT_EQ(nullopt, result);
}