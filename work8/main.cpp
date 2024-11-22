#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <vector>
#include <algorithm>
#include <cctype>

bool isConsonant(char c) {
    c = std::tolower(c);
    return std::isalpha(c) && !std::strchr("aeiou", c);
}

int countUniqueConsonants(const std::string& word) {
    std::set<char> consonants;
    for (char c : word) {
        if (isConsonant(c)) {
            consonants.insert(std::tolower(c));
        }
    }
    return consonants.size();
}

int main() {
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string text;
    std::string word;
    std::set<std::string> uniqueWords;

    // Чтение текста из файла
    while (inputFile >> word) {
        // Убираем знаки препинания
        word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
        if (!word.empty()) {
            uniqueWords.insert(word);
        }
    }

    std::vector<std::pair<std::string, int>> wordConsonantCount;

    // Подсчет различных согласных для каждого уникального слова
    for (const auto& uniqueWord : uniqueWords) {
        int count = countUniqueConsonants(uniqueWord);
        wordConsonantCount.emplace_back(uniqueWord, count);
    }


    // Сортировка по количеству различных согласных
    std::sort(wordConsonantCount.begin(), wordConsonantCount.end(),
        [](const auto& a, const auto& b) {
            return a.second > b.second;

    // Сортировка слова по количеству различных согласных
    std::vector<std::pair<std::string, int>> sortedWords(wordConsonantCount.begin(), wordConsonantCount.end());
    std::sort(sortedWords.begin(), sortedWords.end(), [](const auto& a, const auto& b) {
        return a.second > b.second; 

        });

    // Запись результата в выходной файл
    for (const auto& pair : wordConsonantCount) {
        outputFile << pair.first << " " << pair.second << "\n"; // Используем pair.first и pair.second
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

