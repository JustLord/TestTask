#include <unordered_map>
#include <vector>
#include "entities/Schedule.h"
#include "readers/ScheduleReader.h"
#include "processors/ScheduleProcessor.h"
#include "writers/ScheduleWriter.h"

//
//enum class Company {
//    Posh,
//    Grotty,
//};
//
//
//const std::string &getCompanyName(Company company) {
//    static std::unordered_map<Company, std::string> companyNameMap{{Company::Posh,   "Posh"},
//                                                                   {Company::Grotty, "Grotty"}};
//    return companyNameMap[company];
//}
//
//Company getCompany(const std::string &str) {
//    static std::unordered_map<std::string, Company> nameCompanyMap{{"Posh",   Company::Posh},
//                                                                   {"Grotty", Company::Grotty}};
//
//    return nameCompanyMap[str];
//}
//
//
//class string_split_iterator {
//public:
//    string_split_iterator() : _from{}, _to{} {};
//
//    string_split_iterator(const std::string &str) : _str{str}, _from{}, _to{} {}
//
//    bool operator!=(const string_split_iterator &other) const {
//        return _str.has_value() && other._str.has_value()
//               && _from == other._from
//               && *_str == *other._str;
//    }
//
//    string_split_iterator &operator++() {
//        _from = _to;
//        _to = _str.value().find(' ', _from);
//        return *this;
//    }
//
//    std::string_view operator*() const { return std::string_view(_str.data() + _from, _to - _from); }
//
//private:
//    std::optional<const std::string &> _str;
//    int _from;
//    int _to;
//};
//
//class spliter {
//public:
//    spliter(const std::string &str) : _str{str} {}
//
//    string_split_iterator begin() { return string_split_iterator(_str); }
//
//    string_split_iterator end() { return string_split_iterator(); }
//
//private:
//    const std::string &_str;
//};



int main() {
    std::map<std::string, Company> companies{{"Grotty", Company("Grotty", 0)},
                                             {"Posh",   Company("Posh", 1)}};
    ScheduleReader reader(companies);
    auto schedules = reader.Read("./input.txt");

    if(!schedules)
        return 1;

    ScheduleProcessor processor;
    auto processedSchedules = processor.process(std::move(schedules.value()));

    ScheduleWriter writer;
    writer.write("./output.txt", processedSchedules);

    return 0;
}