#include "ladder.h"
#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
    set<string> word_list;
    load_words(word_list, "words.txt");
    vector<string> word_ladder = generate_word_ladder("code", "data", word_list);
    print_word_ladder(word_ladder);
    return 0;
}