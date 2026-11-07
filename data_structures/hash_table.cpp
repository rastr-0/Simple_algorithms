#include <iostream>
#include <list>
#include <string>
#include <algorithm>

class HashTable{
private:
    // hash_groups is a constant variable which defines number of items to store in HashTable
    static const int hash_groups = 100;
    std::list<std::pair<int, std::string>> table[hash_groups];
public:
    void insert_item(const int key, const std::string value) {
        int hash_value = hash_function(key);
        auto& cell = table[hash_value];
        auto begin_itr = std::begin(cell);
        bool key_exists = false;
        for (; begin_itr != std::end(cell); begin_itr++){
            if (begin_itr->first == key){
                begin_itr->second = value;
                key_exists = true;
                std::cout << "Key exists, values was replaced" << std::endl;
                break;
            }
        }
        if (!key_exists){
            std::cout << "Key was inserted" << std::endl;
            cell.emplace_back(key, value);
        }
    }
    void remove_item(const int key) {
        int hash_value = hash_function(key);
        
        auto& cell = table[hash_value];
        auto itr = std::find_if(cell.begin(), cell.end(), [&](const auto& pair) { return pair.first == key; });
        
        if (itr != cell.end()) {
            cell.erase(itr);
            std::cout << "Item with key: " << key << " was erased" << std::endl;
        } else {
            std::cout << "Item with key: " << key << " was not found and not erased" << std::endl;
        }
    }
    bool is_empty() const {
        int sum = 0;
        for (int i = 0; i < hash_groups; i++){
            sum += table[i].size();
            if (sum > 0)
                return false;
        }
        return true;
    }
    int hash_function(const int key) const {
        // simple hash function which distributes numbers based on their last two digits
        // 101 -> 1 hash group
        // 2 -> 2 hash group
        // 100005 -> 5 hash group
        // -5 -> 95 hash group (C++ % can be negative, so shift it back into [0, hash_groups))
        return ((key % hash_groups) + hash_groups) % hash_groups;
    }
    void search_table(const int key) {
        int hash_value = hash_function(key);
        for (const auto& i : table[hash_value]) {
            if (i.first == key) {
                std::cout << "Value for key: " << key <<" was found: " << i.second << std::endl;
                return;
            }
        }
        std::cout << "Item for: " << key << " was not found" << std::endl;
    }
    void print() {
        for (int i = 0; i < hash_groups; i++){
            if (table[i].size() == 0)
                continue;
            for (const auto& item : table[i]) {
                std::cout << "Key: " << item.first << " and Value: " << item.second << std::endl;
            }
        }
    }
};

int main(){
    HashTable table;
    table.insert_item(0, "zero");
    table.insert_item(10005, "one");
    table.insert_item(2, "two");

    table.insert_item(-5, "minus five");
    table.insert_item(2, "two again");

    table.search_table(10005);
    table.search_table(1005);
    table.remove_item(0);
    table.search_table(0);
    table.print();
}