//
// Created by nikita on 11/30/19.
//
#pragma once

#include <vector>
#include <map>
#include <fstream>
#include "../entities/Schedule.h"

class ScheduleReader {
public:
    ScheduleReader(const std::map<std::string, Company> &nameToCompanyMap);

    std::optional<std::vector<Schedule>> Read(const std::string& fileName);

private:
    Schedule ReadLine();

private:
    std::ifstream _fileStream;
    const std::map<std::string, Company>& _nameToCompanyMap;
};


