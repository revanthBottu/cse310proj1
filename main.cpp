/*
CSE 310 Hash Function DIY Contest
Instructor: Yiran "Lawrence" Luo
Your name(s):
Your team alias: 
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "hash.h"
using namespace std;

int main() {

    int k = 0;
    int n = 0;
    string texts[500];

    // WARNING: Start of the tokenizer that loads the input from std::cin, DO NOT change this part!
    cin >> k;
    string line;
    getline(cin, line);

    while (getline(cin, line)) {
        texts[n] = line;
        n++;
    }
    // WARNING: End of the tokenizer, DO NOT change this part!

    // By this point, k is the # of slots, and n is the # of tokens to fit in
    // texts[] stores the input sequence of tokens/keys to be inserted into your hash table

    // The template is able to be compiled by running 
    //   make
    //   ./encoder < inputs/sample_input.txt
    // which puts out the placeholders only.

    // Your time to shine starts now

    
    string hash_table[k][500];
    int slot_sizes[k];
    

    for (int i = 0; i < k; i++) {
        slot_sizes[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        int slot = hash_function(texts[i]) % k;
        hash_table[slot][slot_sizes[slot]] = texts[i];
        slot_sizes[slot]++;
    }

    cout << "==== Printing the contents of the first 5 slots ====" << endl;
    for (int i = 0; i < 5 && i < k; i++) {
        cout << "Slot " << i << ": ";
        for (int j = 0; j < slot_sizes[i]; j++) {
            cout << hash_table[i][j];
            if (j < slot_sizes[i] - 1) cout << " ";
        }
        cout << endl;
    }

    cout << "==== Printing the slot lengths ====" << endl;
    for (int i = 0; i < k; i++) {
        cout << "Slot " << i << ": " << slot_sizes[i] << endl;
    }

    cout << "==== Printing the standard deviation =====" << endl;

    double sum = 0.0;
    for (int i = 0; i < k; i++) {
        sum += slot_sizes[i];
    }
    double mean = sum / k;
    
    double variance_sum = 0.0;
    for (int i = 0; i < k; i++) {
        double diff = slot_sizes[i] - mean;
        variance_sum += diff * diff;
    }
    double variance = variance_sum / k;
    double std_dev = sqrt(variance);
    
    cout << std_dev << endl;

    return 0;
}