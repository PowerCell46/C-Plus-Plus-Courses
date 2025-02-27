class Solution {
	void appendCharAndMoveIter(std::stringstream& strStream, std::string::iterator& iter) {
		strStream << *iter;
		++iter;
	}

public:
	string mergeAlternately(string word1, string word2) {
		std::stringstream resultStream{};

		auto word1Iter = word1.begin();
		auto word2Iter = word2.begin();

		while (word1Iter != word1.end() && word2Iter != word2.end()) {
			appendCharAndMoveIter(resultStream, word1Iter);
			appendCharAndMoveIter(resultStream, word2Iter);
		}

		while (word1Iter != word1.end())
			appendCharAndMoveIter(resultStream, word1Iter);
		
		while (word2Iter != word2.end())
			appendCharAndMoveIter(resultStream, word2Iter);

		return resultStream.str();
	}
};
