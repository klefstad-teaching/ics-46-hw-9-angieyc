#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>

#include "ladder.h"

using namespace std;

void error(string word1, string word2, string msg) {
    cout << "ERROR ON " << word1 << ", " << word2 << ": " << msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    if (d != 1) return false;

    int len1 = str1.size();
    int len2 = str2.size();

    int num_differences = 0;
    int iter1 = 0;
    int iter2 = 0;

    while (iter1 < len1 && iter2 < len2) {
        if(str1[iter1] != str2[iter2]) {
            ++num_differences;
            if (len1 == len2) {
                ++iter1;
                ++iter2;
            }
            else if (len1 > len2) { //deletion
                ++iter1; // skip the deleted character in str1 to continue comparing the rest
            }
            else { //len1 < len2 --> insertion
                ++iter2;
            }
        }
        else { // keep comparing
            ++iter1;
            ++iter2;
        }
        if (num_differences > d) return false;
    }

    if (iter1 == iter2) {
        num_differences += abs(len1-len2);
    }

    return num_differences == d;
}