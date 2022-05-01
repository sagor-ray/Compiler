#include <iostream>
#include <fstream>
#include <string.h>

bool is_letter(char ch);
bool is_digit(char ch);
bool is_delemeter(char ch);
void lexical(string str);

int main()
{

}

bool is_letter(char ch)
{
    if(ch >= 'a' && ch <='z' || ch >='A' && ch>='Z')
        return true;
    else
        return false;
}
bool is_digit(char ch)
{
    if(ch >= '0' && ch <='9')
        return true;
    else
        return false;
}
bool is_delemeter(char ch)
{
    if(ch == ''  ch =='\t' || ch =='\n')
        return true;
    else
        return false;
}
void lexical(string str)
{
    int state = 0;
    int i=0,flag = 1;
    string lexime;
    char c = '\0';

    while(str[i]!= '\0')
    {
        c = str[i];

        switch(state)
        {
        case 0:
            if(is_letter(c))
            {
                state = 1;
            }
            else if(is_digit(c))
            {
                state = 2;
            }
            else if(is_delemeter(c))
            {
                state = 2;
            }

            break;
        }
        i++;
        lexime +=c;
    }
}

