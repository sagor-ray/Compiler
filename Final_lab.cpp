#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>

using namespace std;

void deleteComtWithConstValue();
void variableCheck();
void KeywordCheck();
void SpecialSymbol();

string line,name[5],value[5],store="",storeValue="",word="",take="";
    int i,flag=0,n=0,j=0,k=0,m,flag2=0,count=1,active[5]= {1,1,1,1,1};
    char Symbol[]= {'+','-','=','*','/','&','|','<','>',',','%','(',')',';','{','}','[',']'};
    string keyword[] = {"int","float","void","string","bool","char","double","if","else","for","while","long"
                        ,"do","break","continue","goto","cout","cin","return","endl","switch","case","typedef"
                        ,"try","catch","throw","count","new","ifstream","ofstream","auto","true","this","struct"
                        ,"default","namespace","std","public","private","protected","class","friend","sizeof","short"
                       };

  string SymbolName[] =
            {
                "Exclamation","Quote", "Hash", "Dollar",
                "Percent", "Ampersand","First Bracket Start","First Bracket End",
                "Asterisk Sign","Plus","Comma", "Minus","Full Stop",
                "Forward Slash", "Colon", "Semi Colon",
                "Less Than","Assignment Operator", "Equal", "Greater than", "Question Mark Sign", "At the rate","Exponent",
                "Back Slash","Underscore", "Apostrophe","Second Bracket Start",
                "Bar","Second Bracket End","Third Bracket Start","Third Bracket End","Tilde"
            };

            char symbol[] =
            {
                '!', '"', '#', '$', '%', '&',
                '(', ')', '*', '+', ',', '-',
                '.', '/', ':', ';', '<', '=',
                '==','>', '?', '@', '^', '\'',
                '_', '`', '{', '|', '}', '[',']'
            };
string dataType[] = {"int","float","double","string","bool","char"};
string newStore="";

int main()
{
    deleteComtWithConstValue();
    SpecialSymbol();
    variableCheck();
    KeywordCheck();

    return 0;
}

void deleteComtWithConstValue()
{
           flag = 0,k = 0,store="",word="",j=0;
            ifstream input("C:\\Users\\sagor\\OneDrive\\Desktop\\Coding\\Compiler Lab\\read.txt");
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
                    }
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
                        for(m=0; m<(sizeof(Symbol)/sizeof(Symbol[0])); m++)
                        {
                            if(line[i] == Symbol[m])       //bracket or other symbol er aga o pore word create korar jonno(max*min)
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

void variableCheck()
{
    cout<<endl<<"**********Variable Checking************"<<endl;
     ifstream input("C:\\Users\\sagor\\OneDrive\\Desktop\\Coding\\Compiler Lab\\read.txt");
    while(getline(input,line))
            {
                for(i=0; i<line.size(); i++)
                {
                    if(line[i] != ' ' && line[i] != '\0')
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
There:
                                i++;
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
                                if(flag == 0 && line[i] == ',')     //for multi variable in a line
                                {
                                    goto There;
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

void KeywordCheck()
{
            word = "",count=1,k=0;
            ifstream input("C:\\Users\\sagor\\OneDrive\\Desktop\\Coding\\Compiler Lab\\read.txt");
            cout<<endl<<"**********Variable Checking************"<<endl;
            cout<<"Keyword List: "<<endl;

            while(getline(input,line))
            {
                cout<<endl<<"Line No: "<<count<<endl;
                count++;
                for(i=0; i<=line.size(); i++)
                {
                    if(line[i] != ' ' && line[i] != '\0' && line[i] != '(' && line[i] != ')' && line[i] != ';' &&
                            line[i] != '<' && line[i] != '>' && line[i] != '.' && line[i] != ':')
                    {
                        word += line[i];
                    }
                    else
                    {
                        if(word == "")
                        {
                            continue;
                        }
                        else
                        {
                            for(j=0; j<44; j++)
                            {
                                if(keyword[j] == word)
                                {
                                    cout<<word<<endl;
                                    word = "";
                                    break;
                                }
                            }
                            word = "";
                        }
                    }
                }
            }
}

void SpecialSymbol()
{
    ifstream input("C:\\Users\\sagor\\OneDrive\\Desktop\\Coding\\Compiler Lab\\read.txt");
    cout<<endl<<"**********Variable Checking************"<<endl;
     while (getline(input, line))
            {
                cout << "\n\nSymbol list in Line " << count << " :\n";
                count++;
                for(int i = 0; i < line.length(); i++)
                {
                    for(int j = 0; j < 30; j++)
                    {
                        if(line[i] == symbol[j])
                        {
                            cout << line[i] << " = " << SymbolName[j] << "\n";
                            break;
                        }
                    }
                }
            }
}

