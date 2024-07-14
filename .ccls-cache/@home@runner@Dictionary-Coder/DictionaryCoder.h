#pragma once
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;

class DictionaryCoder {
public:
    DictionaryCoder();
    string encode(string input_text);
    string decode(string encoded_text);

private:
    unordered_map<string, int> dictionary;
    unordered_map<int, string> reverse_dictionary; // For efficient decoding
    int next_id;
};
