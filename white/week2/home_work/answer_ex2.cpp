#include<iostream>
#include<string>
using namespace std;

//FRO Answer
bool IsPalindrom(string s) {
    // Замечание: более правильным было бы использовать здесь тип size_t вместо int
    // О причинах Вы узнаете на Жёлтом поясе
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

bool IsPalindrom(std::string word)
{
	for (uint32_t begin = 0, end = word.size() - 1;
		begin < word.size() && end > 0;
		begin++, end--)
	{
		if (word[begin] != word[end])
		{
			return false;
		}
	}
	return true;
}

bool IsPalindrom(const std::string &word)
{
	const size_t length = word.length();
	for (size_t i = 0; i < length / 2; i++)
	{
		if (word[i] != word[length - i - 1])
		{
			return false;
		}
	}
	return true;
}