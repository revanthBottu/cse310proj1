#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int hash_function(string text) {
    int hash = 0;
    for (char c : text) {
       hash += (static_cast<int>(c) * 31) % 1200000000007;
    }
    return hash;
}