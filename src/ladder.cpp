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
    if (d > 1) return false;

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

    // if strings not same length, have to account for extra characters
    if (iter1 < len1 || iter2 < len2) {
        num_differences += abs(len1-len2) - 1;
        if (iter1 == iter2) {
            ++num_differences;
        }
    }

    return num_differences <= d;
}

bool is_adjacent(const string& word1, const string& word2) {
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, 
const set<string>& word_list) {
    queue<vector<string>> ladder_q;
    ladder_q.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);

    while (!ladder_q.empty()) {
        vector<string> ladder = ladder_q.front();
        ladder_q.pop();
        string last_word = ladder.back();
        for (const string & word : word_list) {
            if (is_adjacent(last_word, word)) {
                if (!visited.contains(word)) {
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if (word == end_word) return new_ladder;
                    ladder_q.push(new_ladder);
                }
            }
        }
    }
    return vector<string>();
}

void load_words(set<string> & word_list, const string& file_name) {
    ifstream file(file_name);
    for (string word; file >> word;) {
        word_list.insert(word);
    }
    file.close();
}

void print_word_ladder(const vector<string>& ladder) {
    if (ladder.empty()) {
        cout << "No word ladder found.";
    }
    else {
        cout << "Word ladder found: ";
        for (const string & str : ladder) {
            cout << str << " ";
        }
    }
    cout << endl;
}

#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}
void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}