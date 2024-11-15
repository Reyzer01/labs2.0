#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>

bool isLetter(char ch) {
    return std::isalpha(ch);
}

void getMostFrequentLetters(const std::string& text, char mostFrequent[], int count) {
    std::map<char, int> frequency;

    for (char ch : text) {
        if (isLetter(ch)) {
            frequency[std::tolower(ch)]++;
        }
    }

    // Сортируем буквы по частоте
    std::vector<std::pair<char, int>> sortedFreq(frequency.begin(), frequency.end());
    std::sort(sortedFreq.begin(), sortedFreq.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
        });

    // Заполняем массив наиболее частыми буквами
    for (int i = 0; i < count && i < sortedFreq.size(); i++) {
        mostFrequent[i] = sortedFreq[i].first;
    }
}

bool containsEnoughFrequentLetters(const std::string& word, const char mostFrequent[], int freqCount) {
    int foundCount = 0;
    for (int i = 0; i < freqCount; i++) {
        if (word.find(mostFrequent[i]) != std::string::npos) {
            foundCount++;
        }
    }
    return foundCount >= 5;
}

std::string processWord(const std::string& word, const char mostFrequent[], int freqCount) {
    if (containsEnoughFrequentLetters(word, mostFrequent, freqCount)) {
        std::string upperWord = word;
        std::string foundLetters = "(";

        // Преобразуем слово в заглавные буквы
        for (size_t i = 0; i < upperWord.length(); i++) {
            upperWord[i] = std::toupper(upperWord[i]);
        }

        for (int i = 0; i < freqCount; i++) {
            if (word.find(mostFrequent[i]) != std::string::npos) {
                foundLetters += mostFrequent[i];
                foundLetters += ", ";
            }
        }
        if (foundLetters.length() > 1) {
            foundLetters.erase(foundLetters.size() - 2); // Удаляем последнюю запятую и пробел
        }
        foundLetters += ")";
        return upperWord + foundLetters;
    }
    return word;
}

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Ошибка при открытии файла!" << std::endl;
        return 1;
    }

    std::string text((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    char mostFrequent[8];
    getMostFrequentLetters(text, mostFrequent, 8);

    std::string processedText;
    std::string word;
    for (size_t i = 0; i < text.length(); i++) {
        // Считываем слово
        if (isLetter(text[i])) {
            word.clear();
            while (i < text.length() && (isLetter(text[i]) || text[i] == '\'' || text[i] == '-')) {
                word += text[i];
                i++;
            }
            processedText += processWord(word, mostFrequent, 8);
        }
        else {
            processedText += text[i]; // Добавляем символы, которые не являются буквами
        }
    }

    outputFile << processedText;

    inputFile.close();
    outputFile.close();

    return 0;
}