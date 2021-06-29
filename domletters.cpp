// Jeffrey Jernstrom
// CS4
// Homework 1

#define SIZE 100

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int count_dom(const char * word);



int main() {

  int total = 0;
  char word[SIZE];

  // Check for input
  /*
  if (cin.peek() == EOF || '\n') {
    cout << endl
         << "No input provided!"
         << endl;

    return 0;
  }
  */

  // Confirm input
  cout << endl
       << "Input: ";

  // Read in all of the words separated by white space until the eof
  while (cin.peek() != EOF) {
    cin >> word;
    cout << " " << word;
    // Process word
    total += count_dom(word);
  }

  cout << endl 
       << "The total count of dominant letters from the input: "
       << total
       << endl;

  return 0;
}



int count_dom(const char * word) {
  int count = 0;
  unordered_map<char, int> occurrence_map;
  
  // Count the number of dom letters
  for (int i = 0; word[i] != '\0' && i < SIZE; ++i) {

    // Check for only alphabetic words
    if (word[i] > 'z' || word[i] < 'A')
      return 0;

    // Count letter freq 
    ++occurrence_map[word[i]];

    // Update count if larger
    if (occurrence_map[word[i]] > count)
      count = occurrence_map[word[i]];
  }

  if (count < 2)
    return 0;
  else
    return count;
}
