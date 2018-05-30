/*

In this kata you have to create all permutations of an input string and remove duplicates, if present. This means, you have to shuffle all letters from the input in all possible orders.

Examples:

permutations("a"); // => vector<string> {"a"}
permutations("ab"); // => vector<string> {"ab", "ba"}
permutations("aabb"); // => vector<string> {"aabb", "abab", "abba", "baab", "baba", "bbaa"}
The order of the permutations doesn't matter.

 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> permutations(string s) {
  
  std::vector<string> result;
  std::sort (s.begin(), s.end());
  
  do {
        result.push_back(s);
    } while(std::next_permutation(s.begin(), s.end()));
    
  
  return result;
}