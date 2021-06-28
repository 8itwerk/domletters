// Jeffrey Jernstrom
// CS4
// Homework 1

#define SIZE 100

#include <iostream>
#include <string>
using namespace std;

int count_dom(const char * word);

int main() {

  int total = 0;
  char word[SIZE];

  // Check for input

  // Read in all of the words separated by white space until the eof
  while (cin.peek() != EOF) {
    cin >> word;
    // Process word
    total += count_dom(word);
  }

  return 0;
}



int count_dom(const char * word) {
  int count = 0;
  
  // Count the number of dom letters
  for (int i = 0; i != '\0' && i < SIZE; ++i) {
    // Check for only alphabetic words
    if (word[i] > 'z' || word[i] < 'A')
      return 0;
  }

  return count;
}
