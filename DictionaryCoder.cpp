#include "DictionaryCoder.h"
using namespace std;

DictionaryCoder::DictionaryCoder() : next_id(0) {}

string DictionaryCoder::encode(string input_text) {
    stringstream encoded_text;
    string word;
    stringstream ss(input_text);

    while (ss >> word) {
        if (dictionary.find(word) == dictionary.end()) {
            dictionary[word] = next_id;
            reverse_dictionary[next_id] = word; // Update reverse dictionary
            next_id++;
        }
        encoded_text << dictionary[word] << " ";
    }

    return encoded_text.str();
}

string DictionaryCoder::decode(string encoded_text) {
    stringstream decoded_text;
    int id;
    stringstream ss(encoded_text);

    while (ss >> id) {
        decoded_text << reverse_dictionary[id] << " ";
    }

    return decoded_text.str();
}
