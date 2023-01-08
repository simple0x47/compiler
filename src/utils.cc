//
// Created by Gabriel Amihalachioaie on 08.01.2023.
//

#include "utils.h"

optional<list<string>> string_split(string value, string delimiter) {
  if (value.empty() || delimiter.empty()) {
    return nullopt;
  }

  list<string> split_result = list<string>();

  size_t offset = 0;
  offset = value.find(delimiter, offset);

  if (offset != string::npos) {

  }

  return nullopt;
}