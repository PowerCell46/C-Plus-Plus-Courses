#include <iostream>
#include <list>
#include <sstream>


class SentenceShifter {
    std::list<std::string> words;

public:
    SentenceShifter() {
        std::string line;
        std::getline(std::cin, line);

        std::stringstream lineStream{line};
        std::string currentWord;
        while (lineStream >> currentWord)
            this->words.push_back(currentWord);
    }

    SentenceShifter(const std::list<std::string>& words) :
        words(words) {}

    std::list<std::string> getShiftedSentence() {
        const std::string shiftedElement =  this->words.back();
        this->words.pop_back();
        this->words.push_front(shiftedElement);

        return this->words;
    }

    friend std::ostream& operator<<(std::ostream&, const SentenceShifter&);
};

std::ostream& operator<<(std::ostream& os, const SentenceShifter& sentenceShifter) {
    for (const std::string& word : sentenceShifter.words)
        os << word << '\n';
    return os;
}


int main() {
    SentenceShifter sentenceShifter{};

    int shifts;
    std::cin >> shifts;

    for (int i = 0; i < shifts; ++i)
        sentenceShifter.getShiftedSentence();

    std::cout << sentenceShifter;

    return 0;
}
