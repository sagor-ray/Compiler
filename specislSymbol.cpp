#include <iostream>
#include <fstream>

using namespace std;

int main() {
  string symbolArr[] = {
  "Exclamation","Qoute", "Hash", "Dollar",
  "Percent", "Ampersand","First Bracket Start","First Bracket End",
  "Asterisk Sign","Plus","Comma", "Minus","Full Stop" ,
  "Forward Slash", "Colon", "Semi Colon",
  "Less Than","Assignment Operator", "Equal", "Greater than", "Question Mark Sign", "At the rate","Exponent",
   "Back Slash","Underscore", "Apostrophe","Second Bracket Start",
   "Bar","Second Bracket End","Third Bracket Start","Third Bracket End","Tilde"
  };

  char symbols[] = {
    '!', '"', '#', '$', '%', '&',
    '(', ')', '*', '+', ',', '-',
    '.', '/', ':', ';', '<', '=',
    '==','>', '?', '@', '^', '\'',
    '_', '`', '{', '|', '}', '[',']'
  };

  ifstream input("E:\\read.txt");


  if (input.is_open()) {
    string temp;
    int n=0;
    int line = 1;

    while (getline(input, temp)) {
      cout << "Symbol list in Line " << line << " :\n";
      line++;
      for(int i = 0; i < temp.length(); i++) {
        for(int j = 0; j < 30; j++){
          if(temp[i] == symbols[j]){
            cout << temp[i] << " = " << symbolArr[j] << "\n";
            n++;
            break;
          }
        }
      }
    }
    cout<<n<<endl;
  }

  return 0;
}
