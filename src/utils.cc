//
// Created by Gabriel Amihalachioaie on 08.01.2023.
//

#include "utils.h"

optional<list<string>> string_split(const string& value, const string& delimiter) {
  if (value.empty() || delimiter.empty()) {
    return nullopt;
  }

  list<string> split_result = list<string>();

  size_t offset = 0;
  offset = value.find(delimiter, offset);

  if (offset == string::npos) {
    split_result.emplace_back(value);
    return split_result;
  }

  if (offset == 0) {
    split_result.emplace_back("");
  }

  size_t start = offset + delimiter.size();
  while (offset != string::npos && start < value.size()) {
    offset = value.find(delimiter, start);

    split_result.emplace_back(value.substr(start, offset - start));

    if (offset != string::npos) {
      start = offset + delimiter.size();
    }
  }

  return split_result;
}