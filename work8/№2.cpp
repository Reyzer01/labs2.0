#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>

bool hasRepeatedVowels(const std::string& word) {
    std::set<char> vowels;
    for (char ch : word) {
        if (std::string("aeiouAEIOU").find(ch) != std::string::npos) {
            if (vowels.count(ch) > 0) {
                return true; // Найдены повторяющиеся гласные
            }
            vowels.insert(ch);
        }
    }
    return false;
}

std::string reverseString(const std::string& str) {
    return std::string(str.rbegin(), str.rend());
}

int main() {
    std::string text = "Some example of the text with words"; // Пример

    std::istringstream iss(text);
    std::vector<std::string> words;
    std::vector<std::string> repeatedVowelWords;
    std::vector<std::string> invertedWords;

    // Разбивка текста на слова
    std::string word;
    while (iss >> word) {
        if (hasRepeatedVowels(word)) {
            repeatedVowelWords.push_back(word);
        }
        else {
            invertedWords.push_back(reverseString(word));
        }
    }

    // Сортировка слов с повторяющимися гласными
    std::sort(repeatedVowelWords.begin(), repeatedVowelWords.end());

    //  Вывод результата
    std::cout << "Words with repeated vowels (in alphabetical order):\n";
    for (const auto& w : repeatedVowelWords) {
        std::cout << w << "\n";
    }

    std::cout << "Inverted words:\n";
    for (const auto& w : invertedWords) {
        std::cout << w << "\n";
    }

    return 0;
}
