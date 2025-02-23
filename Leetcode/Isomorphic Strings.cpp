class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        std::unordered_map<char, char> charMapper{};
        std::stringstream replacedFirstStringStream{};
        std::set<char> usedValues;

        for (int i = 0; i < s.size(); ++i) {
            if (const char& currentChKey = s.at(i); charMapper.find(currentChKey) != charMapper.end())
                replacedFirstStringStream << charMapper[currentChKey];
            else {
                const char newestAddedValue = t.at(i);
                if (usedValues.contains(newestAddedValue))
                    return false;

                charMapper[currentChKey] = newestAddedValue;
                usedValues.insert(newestAddedValue);
                replacedFirstStringStream << newestAddedValue;
            }
        }
        // std::cout << replacedFirstStringStream.str();

        return replacedFirstStringStream.str() == t;
    }
};
