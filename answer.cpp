#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <array>
#include <string>
#include <chrono>

class Trie {
public:
    char ch;
    std::array<Trie*, 26> child;
    bool isEnd;

    Trie(char c) : ch(c), isEnd(false) {
        child.fill(nullptr);
    }
};

class Solution {
public:
    std::vector<std::string> findAllConcatenatedWordsInADict(std::vector<std::string>& words) {
        std::vector<std::string> result;
        std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
            return a.length() < b.length();
        });

        int counter = 0;
        Trie* root = new Trie('*');
        for (const std::string& word : words) {
            if (!isEndThere(root, word, true)) {
                addStringToTrie(root, word);
            }
            else {
                result.push_back(word);
            }
        }
        return result;
    }

    void addStringToTrie(Trie* root, const std::string& str) {
        Trie* temp = root;
        for (char ch : str) {
            if (temp->child[ch - 'a'] == nullptr) {
                temp->child[ch - 'a'] = new Trie(ch);
            }
            temp = temp->child[ch - 'a'];
        }
        temp->isEnd = true;
    }

    bool isEndThere(Trie* root, const std::string& str, bool isSecond) {
        Trie* temp = root;
        bool result = false;
        int count = 0;
        for (char ch : str) {
            count++;
            if (temp->child[ch - 'a'] == nullptr) {
                return false;
            }
            temp = temp->child[ch - 'a'];
            if (temp->isEnd) {
                if (str.length() > count) {
                    result = result || isEndThere(root, str.substr(count), false);
                }
                else {
                    result = true;
                }
            }
            if (result) {
                return true;
            }
        }
        return result;
    }
};

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    Solution obj;
    std::vector<std::string> result;
    std::vector<std::string> list;
    std::ifstream inputFile("Input_01.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open the input file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        result.push_back(line);
    }
    inputFile.close();

    list = obj.findAllConcatenatedWordsInADict(result);
    std::string last = list.back();
    std::string secondLast = list[list.size() - 2];
    auto end = std::chrono::high_resolution_clock::now();
    double elapsedTime = std::chrono::duration<double>(end - start).count() * 1000; // Convert to milliseconds

    std::cout << "Longest Compound Word: " << last << std::endl;
    std::cout << "Second Longest Compound Word: " << secondLast << std::endl;
    std::cout << "Time taken to process the input file: " << elapsedTime << " Milli Seconds" << std::endl;

    return 0;
}
