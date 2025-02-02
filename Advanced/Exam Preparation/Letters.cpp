#include <iostream>
#include <vector>
#include <set>
#include <sstream>

#define DOT '.'
#define EMPTY_RESULT "---"


std::string keepOnlyLetters(const std::string &);

std::set<std::string> filterVectorByContainingALetterOrdered(const std::vector<std::string> &, const char &);


int main() {
    std::string text;
    // Read the line of text
    std::getline(std::cin, text);

    std::vector<std::string> words;

    std::stringstream strStream{text};
    std::string currentWord;

    // Add all words (filtered only the letters) to the vector
    while (strStream >> currentWord)
        words.push_back(keepOnlyLetters(currentWord));

    while (true) {
        char currentSearchedChar;
        std::cin >> currentSearchedChar;

        if (currentSearchedChar == DOT)
            break;

        auto resultWords = filterVectorByContainingALetterOrdered(words, currentSearchedChar);

        if (resultWords.empty())
            std::cout << EMPTY_RESULT;

        else {
            std::stringstream resultStream{};
            for (const std::string& word : resultWords)
                resultStream << word << ' ';

            std::cout << resultStream.str() << '\n';
        }
    }

    return 0;
}


std::string keepOnlyLetters(const std::string &str) {
    std::stringstream resultStream{};

    for (const char &ch: str)
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch << 'Z')
            resultStream << ch;
        // else // TODO: Should you just ignore the non-letter chars or end the word if such is found? 
        //     break; 

    return resultStream.str();
}


std::set<std::string> filterVectorByContainingALetterOrdered(
    const std::vector<std::string> &words, const char &searchedLetter
) {
    std::set<std::string> filteredWords;
    const char searchedLetterLowercase = std::tolower(searchedLetter);

    for (const std::string& word : words)
        for (const char& ch : word)
            if (std::tolower(ch) == searchedLetterLowercase) {
                filteredWords.insert(word);
                break;
            }

    return filteredWords;
}

/*
You are given a text in English. Let's define a word as any sequence of alphabetical characters. Each of those characters we'll call a letter, but we will consider the uppercase and lowercase variant of a character in a word as the same letter.
L
Y
h
.
*/
