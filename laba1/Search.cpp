#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <list>
#include <windows.h>

// list
// const std::string& str vs std::string_view str
void searchAndPringAllTags(const std::string& tag, std::string& content) {
        std::regex all(tag);
        int count = 0;

        std::sregex_iterator headerBegin = std::sregex_iterator(content.begin(), content.end(), all);
        std::sregex_iterator headerEnd = std::sregex_iterator();
        for (std::sregex_iterator i = headerBegin; i != headerEnd; ++i) {
            count++;
        }
        std::cout << "тэг "<< tag << " встречается " << count << " раз " << std::endl;


}

void printElements(const std::list<std::string>& elements, const std::string& type) {
    std::cout << type << ":\n";
    for (const std::string& element : elements) {
        std::cout << element << "\n";
    }
    std::cout << std::endl;
}

void extractHtmlElements(
    std::list<std::string>& titles, std::list<std::string>& paragraphs,
    std::list<std::string>& boldTexts, const std::string& filePath, const std::string& content) {

    // Регулярные выражения для поиска заголовков, абзацев и жирного текста
    std::regex headerRegex("<h([1-6])>(.*?)</h\\1>");
    std::regex paragraphRegex("<p>(.*?)</p>");
    std::regex boldTextRegex("<b>(.*?)</b>");
 
    // Поиск заголовков
    std::sregex_iterator headerBegin = std::sregex_iterator(content.begin(), content.end(), headerRegex);
    std::sregex_iterator headerEnd = std::sregex_iterator();
    for (std::sregex_iterator i = headerBegin; i != headerEnd; ++i) {
        titles.push_back((*i)[2].str());
    }

    // Поиск абзацев
    std::sregex_iterator paragraphBegin = std::sregex_iterator(content.begin(), content.end(), paragraphRegex);
    std::sregex_iterator paragraphEnd = std::sregex_iterator();
    for (std::sregex_iterator i = paragraphBegin; i != paragraphEnd; ++i) {
        paragraphs.push_back((*i)[1].str());
    }

    // Поиск жирного текста
    std::sregex_iterator boldTextBegin = std::sregex_iterator(content.begin(), content.end(), boldTextRegex);
    std::sregex_iterator boldTextEnd = std::sregex_iterator();
    for (std::sregex_iterator i = boldTextBegin; i != boldTextEnd; ++i) {
        boldTexts.push_back(i->str(1));
    }

}