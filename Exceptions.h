//
// Created by eXtreme PC on 1/5/2026.
//

#ifndef Exceptions_H
#define Exceptions_H

#include <stdexcept>

class FileException : public std::runtime_error {
public:
    explicit FileException(const std::string& msg) : runtime_error("Error archivo" + msg) {}
};

#endif