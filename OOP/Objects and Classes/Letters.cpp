#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <map>

#define DOT '.'
#define EMPTY_CONTENT "---"

// Singleton class
class Letters {
    Letters() = default;

    ~Letters() = default;

    void readAndAppendOnlyWords(std::map<std::string, std::set<char>>& wordsMap, std::stringstream& textLineStream) {
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
    }

    void filterWords(const std::map<std::string, std::set<char>>& wordsMap, const char& currentChar, std::set<std::string>& filteredWords) {
        for (const auto &word_map: wordsMap) {
            if (word_map.second.find(std::tolower(currentChar)) != word_map.second.end())
                filteredWords.insert(word_map.first);
        }
    }

public:
    void mainLogic() {
        std::string text;
        std::getline(std::cin, text);

        std::stringstream textLineStream{text};
        std::map<std::string, std::set<char> > wordsMap;

        readAndAppendOnlyWords(wordsMap, textLineStream);

        while (true) {
            char currentChar;
            std::cin >> currentChar;

            if (currentChar == DOT)
                break;

            std::set<std::string> filteredWords;

            filterWords(wordsMap, currentChar, filteredWords);

            if (filteredWords.empty())
                std::cout << EMPTY_CONTENT << '\n';

            else {
                for (auto &filteredWord: filteredWords)
                    std::cout << filteredWord << ' ';
                std::cout << '\n';
            }
        }
    }

    Letters(const Letters&) = delete;

    Letters& operator=(const Letters&) = delete;

    static Letters& getInstance() {
        static Letters instance;
        return instance;
    }
};


int main() {
    Letters& mainInstance = Letters::getInstance();

    mainInstance.mainLogic();

    return 0;
}
