//
// Created by nikita on 11/30/19.
//
#pragma once

#include <string>

class Company {
public:
    Company(const std::string &name, int priority) {
        this->name = name;
        this->priority = priority;
    }

public:
    std::string name;
    int priority;
};