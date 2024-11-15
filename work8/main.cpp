#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
// ������� ��� ��������, �������� �� ������ ���������
bool isConsonant(char c) {
    c = std::tolower(c);
    return isalpha(c) && !std::strchr("aeiou", c);
}

// ������� ��� �������� ��������� ��������� � �����
int countDistinctConsonants(const std::string& word) {
    std::set<char> consonants;
    for (char c : word) {
        if (isConsonant(c)) {
            consonants.insert(std::tolower(c));
        }
    }
    return consonants.size();
}

int main(){
    std::ifstream inputFile("input.txt");
    std::ofstream outputFile("output.txt");
    std::vector<std::string> words;
    std::set<std::string> uniqueWords;
    std::string line;

    // ������ ����� � ��������� ����
    while (std::getline(inputFile, line)){
        std::istringstream iss(line);
        std::string word;
        while (iss >> word){
            if (countDistinctConsonants(word)){
                uniqueWords.insert(word);
            }
        }
    }
    std::string word;
    std::map<std::string, int> wordConsonantCount;
    // ������� ���������� ���� � ������
    for (const auto& word : uniqueWords){
        words.push_back(word);
    }

    // ��������� ����� �� ���������� ��������� ���������
    std::vector<std::pair<std::string, int>> sortedWords(wordConsonantCount.begin(), wordConsonantCount.end());
    std::sort(sortedWords.begin(), sortedWords.end(), [](const auto& a, const auto& b) {
        return a.second > b.second; // ���������� �� ��������
        });

    // ������������ ���������� ���� �� N (2000)
    int N = std::min(2000, static_cast<int>(sortedWords.size()));

    for (int i = 0; i < N; ++i) {
        outputFile << sortedWords[i].first << " " << sortedWords[i].second << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}