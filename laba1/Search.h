#include <iostream>
#include <string>
#include <list>

// list
// const std::string& str vs std::string_view str


void printElements(const std::list<std::string>&, const std::string&);

void extractHtmlElements(
    std::list<std::string>&, std::list<std::string>&,
    std::list<std::string>& , const std::string& );

void searchAndPringAllTags(const std::string&, std::string&);