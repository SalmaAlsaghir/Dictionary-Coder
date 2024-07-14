#include "DictionaryCoder.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

string generateRandomSentence(int num_words = 10) { // Default value is 10
    vector<string> words = {"apple", "banana", "cat", "dog", "elephant", "fish", "gorilla", "house", "iguana", "jungle"};
    string sentence;

    for (int i = 0; i < num_words; ++i) {
        int index = rand() % words.size();
        sentence += words[index] + " ";
    }

    return sentence;
}


void measureDictionaryCoder(const string& input_text) {
    DictionaryCoder coder;

    // Measure compression speed
    auto start = steady_clock::now();
    string encoded_text = coder.encode(input_text);
    auto end = steady_clock::now();
    auto compression_speed = duration_cast<microseconds>(end - start).count();
    cout << "Compression Speed: " << compression_speed << " microseconds" << endl;

    // Measure compression ratio
    double compression_ratio = static_cast<double>(input_text.size()) / encoded_text.size();
    cout << "Compression Ratio: " << compression_ratio << endl;

    // Measure memory usage (approximately)
    cout << "Memory Usage: " << (input_text.size() + encoded_text.size()) * sizeof(char) << " bytes" << endl;
}

int main() {
    srand(time(0)); // Seed for random number generation

    // Test with random input text
    string input_text = generateRandomSentence();
    cout << "Random Input Text: " << input_text << endl;

    DictionaryCoder coder;

    string encoded_text = coder.encode(input_text);
    cout << "Encoded Text: " << encoded_text << endl;

    string decoded_text = coder.decode(encoded_text);
    cout << "Decoded Text: " << decoded_text << endl;

    measureDictionaryCoder(input_text);

    // Test with varying number of words
    cout << "\nTesting with varying number of words:" << endl;
    for (int num_words = 10; num_words <= 100000; num_words *= 10) {
        string test_input = generateRandomSentence(num_words); // Generate a sentence with 'num_words' words
        cout << "\nNumber of Words: " << num_words << endl;

        encoded_text = coder.encode(test_input);
        cout << "Encoded Text Size: " << encoded_text.size() << endl;

        decoded_text = coder.decode(encoded_text);
        cout << "Decoded Text Matches: " << (decoded_text == test_input ? "Yes" : "No") << endl;

        measureDictionaryCoder(test_input);
    }

    return 0;
}



