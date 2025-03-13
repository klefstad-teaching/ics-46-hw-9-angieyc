#include "ladder.h"
#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
    // set<string> word_list;
    // load_words(word_list, "words.txt");
    // vector<string> word_ladder = generate_word_ladder("angie", "curls", word_list);
    // print_word_ladder(word_ladder);
    // verify_word_ladder();

    cout << edit_distance_within("apple", "apple", 1) << endl;;
    return 0;
}