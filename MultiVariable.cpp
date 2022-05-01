#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    ifstream input("C:\\Users\\sagor\\OneDrive\\Desktop\\Coding\\Compiler Lab\\read.txt");

     string dataType[] = {"int","float","double","string","bool","char"};
     string newStore="",line,store,word="";
     int flag=0,i,j;
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
                            there:
                            i=i+1;
                            while(line[i] != ' ' && line[i] != '\0' && line[i] != ',' && line[i] != ';')
                            {
                                newStore +=line[i];
                                i++;
                            }
                            if(newStore[newStore.length()-1] == ')' && newStore[newStore.length()-2] == '(')
                            {
                                flag = 1;
                                newStore="";
                            }

                            if(flag == 0)
                            {
                                if(newStore[0] >= 'a' && newStore[0] <= 'z' ||newStore[0] >= 'A' && newStore[0] <= 'Z' || newStore[0] == '_'
                                        || newStore[0] == '$' || newStore[0] == '*')
                                {
                                    cout<<store<<"\t"<<newStore<<"\t Valid";
                                    cout<<endl;
                                    newStore="";
                                }
                                else
                                {
                                    cout<<store<<"\t"<<newStore<<"\t Invalid";
                                    cout<<endl;
                                    newStore="";
                                }

                            }
                            if(flag == 0 && line[i] == ',')
                            {
                                goto there;
                            }
                            newStore="";
                            break;
                        }
                    }
                }
            }

            word="";
        }
}
