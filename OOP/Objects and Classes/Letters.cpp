#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <map>

#define DOT '.'
#define EMPTY_CONTENT "---"


int main() {
    std::string text;
    std::getline(std::cin, text);

    std::stringstream textLineStream{text};
    std::map<std::string, std::set<char>> wordsMap;

    std::string currentWord;
    while (textLineStream >> currentWord) {
        auto currentWordIter = currentWord.cbegin();
        std::set<char> currentWordSet;
        std::stringstream currentWordStream{};

        while (currentWordIter != currentWord.cend()) {
            if (const auto currentChar = std::tolower(*currentWordIter); currentChar >= 'a' && currentChar <= 'z') {
                currentWordStream << *currentWordIter;
                currentWordSet.insert(currentChar);
            } else {
                wordsMap.insert({currentWordStream.str(), currentWordSet});
                currentWordSet.clear();
                currentWordStream.str("");
            }
            ++currentWordIter;
        }
        if (!currentWord.empty())
            wordsMap.insert({currentWordStream.str(), currentWordSet});
    }

    while (true) {
        char currentChar;
        std::cin >> currentChar;
        if (currentChar == DOT)
            break;

        std::set<std::string> filteredWords;

        for (const auto& word_map : wordsMap) {
            if (word_map.second.find(std::tolower(currentChar)) != word_map.second.end())
                filteredWords.insert(word_map.first);
        }

        if (filteredWords.empty())
            std::cout << EMPTY_CONTENT << '\n';
        else {
            for (auto& filteredWord : filteredWords)
                std::cout << filteredWord << ' ';
            std::cout << '\n';
        }
    }

    return 0;
}
