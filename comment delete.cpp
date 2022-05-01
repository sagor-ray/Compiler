#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
using namespace std;

int main()
{
    ifstream input("C:\\Users\\sagor\\OneDrive\\Desktop\\Coding\\Compiler Lab\\read.txt");
    ofstream output("C:\\Users\\sagor\\OneDrive\\Desktop\\Coding\\Compiler Lab\\write.txt");

    string line;
    int flag = 0;
    if(input.is_open())
    {
        while(getline(input,line))
        {

            for(int i=0;i<line.length();i++)
            {
                if(line[i] == '/' && line[i+1] == '/')
                {
                    break;
                }

                if(line[i] == '/' && line[i+1]=='*')
                {
                    flag = 1;

                }
                if(line[i] == '*' && line[i+1]=='/')
                {
                    flag = 0;
                    i = i+2;
                }

                if(flag == 0)
                {
                    output<<line[i];
                }
            }
            output<<endl;

        }
    }

    return 0;
}
