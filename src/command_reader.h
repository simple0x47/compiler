//
// Created by Gabriel Amihalachioaie on 08.01.2023.
//

#ifndef COMPILER_COMMAND_READER_H
#define COMPILER_COMMAND_READER_H

#include <string>
#include <optional>
#include "command.h"

class CommandReader {
public:
    std::optional<Command> ReadCommandFromLine(std::string line);
};

#endif //COMPILER_COMMAND_READER_H
