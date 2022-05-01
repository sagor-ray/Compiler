#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>

using namespace std;
int main()
{
    ifstream input("C:\\Users\\sagor\\OneDrive\\Desktop\\Coding\\Compiler Lab\\read.txt");    //call input file
    ofstream out("C:\\Users\\sagor\\OneDrive\\Desktop\\Coding\\Compiler Lab\\write.txt");

    string dataType[] = {"int","float","double","string","bool","char","void"};
    string line,word="",store,newStore="";
    int i,j,flag=0;
     while(getline(input,line))
    {
        for(i=0; i<line.size(); i++)
        {
            if(line[i] != ' ')
            {
                word += line[i];
            }
            else
            {
                flag = 0;
                store  = word;
                word   = "";
                for(j=0; j<6; j++)
                {
                    if(store == dataType[j])
                    {

                        i=i+1;
                        while(line[i] != ' ' && line[i] != '\0')
                        {
                            newStore +=line[i];
                            i++;

                        }
                        int n = newStore.length()-1;
                        if(newStore[n] == ')')
                        {
                            flag = 1;
                        }

                        if(flag == 0)
                        {
                            if(newStore[0] >= 'a' && newStore[0] <= 'z' ||newStore[0] >= 'A' && newStore[0] <= 'Z' || newStore[0] == '_'
                               || newStore[0] == '$' || newStore[0] == '*' )
                            {
                                cout<<store<<"\t"<<newStore<<"\t Valid";
                                cout<<endl;
                            }
                            else
                            {
                                cout<<store<<"\t"<<newStore<<"\t Invalid";
                                cout<<endl;
                            }

                        }
                        newStore="";
                        break;
                    }
                }
            }
        }

        word="";
    }
    return 0;
}
