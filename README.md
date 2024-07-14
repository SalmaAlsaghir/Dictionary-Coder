# Dictionary Coder

Welcome to the Dictionary Coder! This system encodes and decodes text using a dictionary-based compression method. It maps each unique word to an integer ID, allowing efficient encoding and decoding of text.

## Table of Contents

1. [Overview](#overview)
2. [Classes](#classes)
3. [Functions](#functions)
4. [Usage](#usage)
5. [Performance Measurement](#performance-measurement)
6. [File Structure](#file-structure)
7. [Error Handling](#error-handling)

## Overview

The Dictionary Coder system comprises a main class that manages the encoding and decoding of text using dictionaries. It also includes a utility function for generating random sentences for testing purposes and performance measurement functions.

## Classes

### DictionaryCoder

The `DictionaryCoder` class is responsible for encoding and decoding text using a dictionary-based approach.

#### Methods

- **DictionaryCoder()**: Constructor to initialize the coder with an empty dictionary.
- **string encode(string input_text)**: Encodes the input text by mapping each word to a unique integer ID.
- **string decode(string encoded_text)**: Decodes the encoded text by mapping each integer ID back to the original word.

## Functions

### generateRandomSentence

Generates a random sentence with a specified number of words from a predefined list of words.

#### Parameters

- **int num_words**: The number of words in the generated sentence (default is 10).

#### Returns

- **string**: The generated random sentence.

### measureDictionaryCoder

Measures the performance of the Dictionary Coder, including compression speed, compression ratio, and memory usage.

#### Parameters

- **const string& input_text**: The input text to be encoded and measured.

## Usage

1. **Compile the Program**: Compile the program using a C++ compiler.
    ```sh
    g++ -o DictionaryCoder DictionaryCoder.cpp
    ```

2. **Run the Program**: Execute the compiled program.
    ```sh
    ./DictionaryCoder
    ```

3. **Main Menu**: The main program will automatically run tests and display results for encoding, decoding, and performance measurement.

## Performance Measurement

The performance of the Dictionary Coder is measured using the `measureDictionaryCoder` function, which reports:

- **Compression Speed**: The time taken to encode the input text, measured in microseconds.
- **Compression Ratio**: The ratio of the size of the original text to the size of the encoded text.
- **Memory Usage**: The approximate memory usage for storing the input and encoded text.

Performance is tested with varying numbers of words to demonstrate scalability.

## File Structure

- **DictionaryCoder.h**: Header file containing the declarations of the `DictionaryCoder` class and utility functions.
- **DictionaryCoder.cpp**: Implementation file containing the definitions of the `DictionaryCoder` class and utility functions.
- **main.cpp**: Main file containing the `main` function and performance measurement tests.

## Error Handling

- Input validation is performed for the encoding and decoding processes to ensure valid text.
- Errors in dictionary operations are managed by checking the existence of words and IDs before accessing them.

Enjoy using the Dictionary Coder for efficient text encoding and decoding!