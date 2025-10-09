#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int hash_function(string text) {
    int hash = 0x5F5E1009; // This is a large 32-bit prime
    
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        int weight = (i * 7 + 3) % 13; // Give a character a weight based on its position in the string
        hash += (text.length() % 10 + c) * weight; // Update hash with weighted character value
        hash = (hash << 17) | (hash >> 1);  // Rotate hash left by 3 bits, then rotate bits 29 positions to the right
        hash ^= c * 18; // Mix in the actual character value at the very end
    }
    return hash & 0x7FFFFFFF;
}   