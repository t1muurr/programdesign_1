#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <list>
#include <windows.h>
#include "Search.h"


int main(int argc, char* argv[]) {
    if (argc < 2){
        return 1;
    }
    std::string tags[4]{ "<br>","<title>","<pre>","<i>" };

    SetConsoleOutputCP(1251);
    std::list<std::string> titles, paragraphs, boldTexts;
    std::string path = argv[1];

    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << path << std::endl;
        return 1;
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    file.close();

    for (int i = 0; i < 4; i++) {
        searchAndPringAllTags(tags[i], content);
    }
    //extractHtmlElements(titles,paragraphs,boldTexts,path);
    //printElements(titles, "Заголовки");
    //printElements(paragraphs, "Абзацы");
    //printElements(boldTexts, "Жирный текст");

    return 0;
}