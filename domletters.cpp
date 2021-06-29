// Jeffrey Jernstrom
// CS461 - Open Sourse Dev Lab
// Homework 1

#define SIZE 100

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int count_dom(char * word);



int main() {

  int total = 0;
  char word[SIZE];

  // Confirm input
  cout << endl
       << "Input: ";

  // Read in all of the words separated by white space until the eof
  while (cin.peek() != EOF) {
    cin >> word;
    cout << " " << word;
    // Process word and add to running total
    total += count_dom(word);
  }

  // Print result
  cout << endl 
       << "The total count of dominant letters from the input: "
       << total
       << endl;

  return 0;
}



// Process the word and return the number of dom letters
int count_dom(char * word) {
  int count = 0;
  unordered_map<char, int> occurrence_map;
  
  // Count the number of dom letters
  for (int i = 0; word[i] != '\0' && i < SIZE; ++i) {

    // Check for only alphabetic words
    if (word[i] > 'z' || word[i] < 'A')
      return 0;

    // Convert to one case
    word[i] = toupper(word[i]);

    // Count letter freq 
    ++occurrence_map[word[i]];

    // Update count if larger
    if (occurrence_map[word[i]] > count)
      count = occurrence_map[word[i]];
  }

  return count;
}
