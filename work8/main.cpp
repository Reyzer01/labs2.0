#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
// Ôóíêöèÿ äëÿ ïðîâåðêè, ÿâëÿåòñÿ ëè ñèìâîë ñîãëàñíîé
bool isConsonant(char c) {
    c = std::tolower(c);
    return isalpha(c) && !std::strchr("aeiou", c);
}

// Ôóíêöèÿ äëÿ ïîäñ÷åòà ðàçëè÷íûõ ñîãëàñíûõ â ñëîâå
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

    // ×òåíèå ôàéëà è îáðàáîòêà ñëîâ
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
    // Ïåðåíîñ óíèêàëüíûõ ñëîâ â âåêòî
    for (const auto& word : uniqueWords){
        words.push_back(word);
    }

    // Ñîðòèðóåì ñëîâà ïî êîëè÷åñòâó ðàçëè÷íûõ ñîãëàñíûõ
    std::vector<std::pair<std::string, int>> sortedWords(wordConsonantCount.begin(), wordConsonantCount.end());
    std::sort(sortedWords.begin(), sortedWords.end(), [](const auto& a, const auto& b) {
        return a.second > b.second; // Ñîðòèðîâêà ïî óáûâàíèþ
        });

    // Îãðàíè÷èâàåì êîëè÷åñòâî ñëîâ äî N (2000)
    int N = std::min(2000, static_cast<int>(sortedWords.size()));

    for (int i = 0; i < N; ++i) {
        outputFile << sortedWords[i].first << " " << sortedWords[i].second << std::endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
