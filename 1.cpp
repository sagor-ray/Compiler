#include <iostream>
#include <string.h>
#include <ctype.h>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("C:\\Users\\sagor\\OneDrive\\Desktop\\Coding\\Compiler Lab\\read.txt");    //call input file
    ofstream out("C:\\Users\\sagor\\OneDrive\\Desktop\\Coding\\Compiler Lab\\write.txt");

    /*variable
        deceleration*/
    string line,name[5],value[5],store="",storeValue="",word="",take="";
    int i,flag=0,n=0,j=0,k=0,m,flag2=0,active[5]={1,1,1,1,1};
    char symbol[]={'+','-','=','*','/','&','|','<','>',',','%','(',')',';','{','}','[',']'};

    if(input.is_open())
    {
        while(getline(input,line))
        {
            for(i=0; i<=line.length(); i++)
            {
                //for comment delete
                if(line[i] == '/' && line[i+1] == '/')
                    break;
                if(line[i] == '/' && line[i+1] == '*')
                    flag = 1;
                if(line[i] == '*' && line[i+1] == '/')
                {
                    i = i+2;
                    flag = 0;
                }   //comment delete done


                if(line[i] == '#' && line[i+1] == 'd' && line[i+2] == 'e' && line[i+3] == 'f' &&line[i+4] == 'i' && line[i+5] == 'n' && line[i+6] == 'e')
                {
                    //taking constant name
                   k = i+8;
                   while(line[k] != ' ')
                   {
                       store = store + line[k];
                       k++;
                   }
                    name[j] = store;
                    store = "";
                    j++;
                    //taking value
                    while(line[k+1] != '\0')
                    {
                        storeValue = storeValue + line[k+1];
                        k++;
                    }
                    value[n] = storeValue;
                    storeValue = "";
                    n++;
                }

                //change name by value
                 if(line[i] != ' ' && line[i] != '\0' && flag == 0)
                 {
                     for(m=0; m<(sizeof(symbol)/sizeof(symbol[0])); m++)
                     {
                         if(line[i] == symbol[m])       //bracket or other symbol er aga o pore word create korar jonno(max*min)
                         {
                             take = line[i];
                             goto there;
                         }
                     }
                     word += line[i];
                     flag2 = 1;
                 }
                 else if(line[i] == ' ' || line[i] == '\0')
                 {
                     there:
                    flag2 = 0;
                     for( m=0; m<(sizeof(name)/sizeof(name[0])); m++)
                     {
                         if(word == name[m])
                         {
                           if(active[m] == 0)
                           {
                               cout<<value[m];
                               word = "";
                           }
                           active[m] = 0;
                           break;
                         }
                     }
                 }

                if(flag == 0 && flag2 == 0)
                {
                   cout<<word<<take<<" ";
                   word = "";
                   take = "";
                }
            }
        cout<<endl;
        }
    }
    return 0;
}
