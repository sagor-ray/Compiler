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

      for(int i = 0; i < temp.length(); i++)
        {
            cout<<temp[i];
        }
        cout<<endl;
   }
  }
 }


