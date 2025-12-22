#include "GroceryTracker.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cctype>

std::string GroceryTracker::ToLower(const std::string& s) {
    std::string out = s;
    std::transform(out.begin(), out.end(), out.begin(),
        [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return out;
}

bool GroceryTracker::LoadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        return false;
    }

    std::string item;
    while (std::getline(inFile, item)) {
        if (item.empty()) {
            continue;
        }

        std::string key = ToLower(item);

        // Save display name the first time we see this item
        if (displayNameByKey.find(key) == displayNameByKey.end()) {
            displayNameByKey[key] = item;
        }

        freqByKey[key]++;
    }

    return true;
}

bool GroceryTracker::WriteBackupFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        return false;
    }

    for (const auto& pair : freqByKey) {
        const std::string& key = pair.first;
        int count = pair.second;
        outFile << displayNameByKey.at(key) << " " << count << "\n";
    }

    return true;
}

int GroceryTracker::GetFrequency(const std::string& item) const {
    std::string key = ToLower(item);
    auto it = freqByKey.find(key);
    if (it == freqByKey.end()) {
        return 0;
    }
    return it->second;
}

void GroceryTracker::PrintAllFrequencies() const {
    for (const auto& pair : freqByKey) {
        const std::string& key = pair.first;
        int count = pair.second;
        std::cout << displayNameByKey.at(key) << " " << count << std::endl;
    }
}

void GroceryTracker::PrintHistogram(char symbol) const {
    for (const auto& pair : freqByKey) {
        const std::string& key = pair.first;
        int count = pair.second;

        std::cout << displayNameByKey.at(key) << " ";
        for (int i = 0; i < count; ++i) {
            std::cout << symbol;
        }
        std::cout << std::endl;
    }
}
