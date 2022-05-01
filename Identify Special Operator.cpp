#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string SymbolName[] =
    {
        "Exclamation","Qoute", "Hash", "Dollar",
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

    ifstream input("C:\\Users\\sagor\\OneDrive\\Desktop\\Coding\\Compiler Lab\\read.txt");
    ofstream out("C:\\Users\\sagor\\OneDrive\\Desktop\\Coding\\Compiler Lab\\write.txt");

    if (input.is_open())
    {
        string temp;
        int n=0;
        int line = 1;

        while (getline(input, temp))
        {
            out << "\n\nSymbol list in Line " << line << " :\n";
            line++;
            for(int i = 0; i < temp.length(); i++)
            {
                for(int j = 0; j < 30; j++)
                {
                    if(temp[i] == symbol[j])
                    {
                        out << temp[i] << " = " << SymbolName[j] << "\n";
                        n++;
                        break;
                    }
                }
            }
        }
        out<<endl<<"Total Symbol: "<<n<<endl;
        return 0;
    }
}
