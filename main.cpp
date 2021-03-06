#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Dictionary Class
class Dictionary {

public:
  // Method to search for a word & display a meaning if found
  // else display not found message
  void findWord(string word) {
    ifstream file("oxford.txt");
    string line;

    // Converting the given input into Title-Cased
    // to match with the word in dictionary file
    if (word[0] >= 97 && word[0] <= 122)
      word[0] -= 32;

    while (getline(file, line)) {

      // storing first word of line in firstWord variable
      // every first word of the dictionary is stored in the variable
      // and matched with user given input till EOF
      stringstream ss{line};
      string firstWord;
      ss >> firstWord;

      if (firstWord == word) {
        cout << line << endl;
      }
    }
    // line variable is empty if word doesn't match
    // display word not found error
    if (line == "") {
      cout << "\nNo other word related to '" << word << "' found!";
    }
  }

  // method to write fav. file
  void setFav(string word) {
    ofstream fav;
    fav.open("fav.txt", ios::app); // ios::app => append mode
    fav << word + "\n";
    fav.close();
  }

  // method to write history file
  void setHistory(string word) {
    ofstream historyfile;
    historyfile.open("history.txt", ios::app); // ios::app => append mode
    historyfile << word + "\n";
    historyfile.close();
  }

  // method to read fav file
  void getFav() {
    fstream fav;
    fav.open("fav.txt", ios::in);
    if (!fav) {
      cout << "File not found!!";
    } else {
      string ch;
      while (getline(fav, ch)) {
        cout << ch << "\n";
      }
    }
    fav.close();
  }

  // method to read history file
  void getHistory() {
    fstream history;
    history.open("history.txt", ios::in);
    if (!history) {
      cout << "File not found!!";
    } else {
      string ch;
      while (getline(history, ch)) {
        cout << ch << "\n";
      }
    }
    history.close();
  }
};

// Main function
int main() {
  Dictionary dict;
  string w;
  int choice;

  // Home Screen
  do {
    cout << "\n\nMAIN MENU";
    cout << "\n1. Search Word";
    cout << "\n2. Read Fav";
    cout << "\n3. Write Fav";
    cout << "\n4. Read History";
    cout << "\n5. Exit";

    cout << "\nEnter your choice (1-5) : ";
    cin >> choice;
    switch (choice) {
    case 1:
      cout << "Enter a word to search: ";
      cin >> w;
      cout<<"\n";
      // calling method to search the word
      dict.findWord(w);
      // writing into history file immediately
      dict.setHistory(w);
      break;
    case 2:
      // calling method to read fav file
      dict.getFav();
      break;
    case 3:
      // if user wants he/she can write a word
      // just searched into fav file
      dict.setFav(w);
      break;
    case 4:
      // invoking method to read history file
      dict.getHistory();
      break;
    case 5:
      exit(0);
      break;
    default:
      cout << "\n....Invalid Choice....\nTry Again !!!\n";
      exit(0);
      break;
    }
  } while (choice != 5);

  return 0;
}