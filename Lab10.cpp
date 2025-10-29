#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;


bool isDouble(string word)
{
    bool hasDecimal = false;
    int len = word.length();
    for (int i=0;i<len;i++)
    {
        char c = word[i];
        if (!isdigit(c))
        {
            if (c == '.' && !hasDecimal && i != len-1 && i != 0)
            {
                hasDecimal = true;
            }
            else if (c == '+' || c == '-')
            {
                if (i!=0)
                {
                    return false; 
                }
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

// '8' == '0' + 8


// '9' + '3' == ('9' + '3' - 2 * '0') / 10
// ('9' + '3' - 2 * '0') % 10

// 943.92
// 9546.129

bool getSign(string num)
{
    if (!isDigit(num[0]))
    {
        if(num[0]=='-')
        {
            num.erase(0,1);
            return false
        }
        num.erase(0,1);
    }
    return true
}

string signless()
{
    
}

string addNums(string num1, string num2)
{   
    int decimal1 = num1.find('.');
    int decimal2 = num2.find('.');
    bool sign1 = getSign(num2)
    bool sign2 = getSign(num2);
    
    while (decimal1 != decimal2)
    {
        if (decimal1 < decimal2)
        {
            num1 = '0' + num1;
        }
        else if (decimal1 > decimal2)
        {
            num2 = '0' + num2;
        }
    }
    cout << num1;
    cout << num2;

    if(num1[0] == '-' && num2[0] != '-')
    {

    }
    else if (num1[0] != '-' && num2[0] == '-')
    {

    }
    else
    {
        
    }
    return "Balls";
}

int main() 
{
    string filename;
    cout << "Please enter your file name: ";
    cin >> filename;

    ifstream myfile(filename);
    string word1;
    string word2;

    if (myfile.is_open()){
        while (myfile >> word1 && myfile >> word2)
        {
            if (isDouble(word1) && isDouble(word2))
            {
                cout << "Valid" << endl;
                addNums(word1,word2);
            }
            else 
            {
                cout << "invalid" << endl;
            }
        }
    }
}