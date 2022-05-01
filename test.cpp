#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    int countfirstOpen=0,countfirstClose=0,countsecOpen=0,countsecClose=0,countthirdOpen=0,countthirdClose=0;
    ifstream input ("E:\\read.txt");

     if (input.is_open()) {
    string temp;

    while (getline(input, temp)) {

      for(int i = 0; i < temp.length(); i++) {
            if(temp[i] == '(')
            {
                countfirstOpen++;
            }
            if(temp[i] == ')')
            {
                countfirstClose++;
            }
            if(temp[i] == '{')
            {
                countsecOpen++;
            }
            if(temp[i] == '}')
            {
                countsecClose++;
            }if(temp[i] == '[')
            {
                countthirdOpen++;
            }
            if(temp[i] == ']')
            {
                countthirdClose++;
            }
          }

      }
      if(countfirstOpen == countfirstClose)
      {
          cout<<"First bracket= Balanced\n";
      }
      else
      {
          cout<<"First bracket = Not Balanced\n";
      }
       if(countsecOpen == countsecClose)
      {
          cout<<"second bracket= Balanced\n";
      }
      else
      {
          cout<<"second bracket = Not Balanced\n";
      }
       if(countthirdOpen == countthirdClose)
      {
          cout<<"third bracket= Balanced\n";
      }
      else
      {
          cout<<"third bracket = Not Balanced\n";
      }

      cout<<"\n\nFirst Bracket Opening: "<<countfirstOpen;
      cout<<"\n\nFirst Bracket Closing: "<<countfirstClose;

    }
  }


