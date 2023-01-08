//
// Created by Gabriel Amihalachioaie on 08.01.2023.
//

#ifndef COMPILER_COMMAND_H
#define COMPILER_COMMAND_H

#include <string>
#include <list>

class Command {
private:
    std::list<std::string> arguments;

public:
    Command(std::list<std::string> arguments) {
        this->arguments = arguments;
    }
};

#endif //COMPILER_COMMAND_H
