#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <map>
#include <string>

class GroceryTracker {
public:
    // Loads items from input file (one item per line)
    bool LoadFromFile(const std::string& filename);

    // Writes backup data file (item + frequency)
    bool WriteBackupFile(const std::string& filename) const;

    // Returns frequency for an item (case-insensitive)
    int GetFrequency(const std::string& item) const;

    // Prints "Item count" for all items
    void PrintAllFrequencies() const;

    // Prints histogram: Item ***** (count stars)
    void PrintHistogram(char symbol = '*') const;

private:
    // Store items as lowercase keys for case-insensitive lookup
    std::map<std::string, int> freqByKey;

    // Preserve original display name (first-seen capitalization)
    std::map<std::string, std::string> displayNameByKey;

    static std::string ToLower(const std::string& s);
};

#endif

