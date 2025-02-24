class Solution {
    static bool containsOnlyOfOneLineChars(const std::string& word, const std::set<char>& rowChars) {
        for (const char &chr: word)
            if (!rowChars.contains(std::tolower(chr))) {
                return false;
            }
        return true;
    }
    
public:
    vector<string> findWords(vector<string> &words) {
        std::set<char> firstRowChars{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        std::set<char> secondRowChars{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        std::set<char> thirdRowRowChars{'z', 'x', 'c', 'v', 'b', 'n', 'm'};

        std::vector<std::string> oneLineWords;
        oneLineWords.reserve(words.size());

        for (const std::string &word: words) {
            const char ch = std::tolower(*word.begin());
            bool oneLineWord = false;

            if (firstRowChars.contains(ch)) {
                oneLineWord = containsOnlyOfOneLineChars(word, firstRowChars);

            } else if (secondRowChars.contains(ch)) {
                oneLineWord = containsOnlyOfOneLineChars(word, secondRowChars);

            } else if (thirdRowRowChars.contains(ch)) {
                oneLineWord = containsOnlyOfOneLineChars(word, thirdRowRowChars);
            }
            if (oneLineWord)
                oneLineWords.push_back(word);
        }

        return oneLineWords;
    }
};
