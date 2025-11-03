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

bool getSign(string* num)
{
    if (!isdigit((*num)[0]))
    {
        if((*num)[0]=='-')
        {
            (*num).erase(0,1);
            return false;
        }
        (*num).erase(0,1);
    }
    return true;
}

string addNums(string num1, string num2)
{   
    int decimal1 = num1.find('.');
    int decimal2 = num2.find('.');

    bool sign1 = getSign(&num1);
    bool sign2 = getSign(&num2);

    if (decimal1 == -1){num1 = num1 + ".0";}
    if (decimal2 == -1) {num2 = num2 + ".0";}
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
        decimal1 = num1.find('.');
        decimal2 = num2.find('.');
    }
    int diff = num1.length()-num2.length();
    while (diff!=0){
        if (diff<0)
        {
            num1 = num1 + '0';
            diff++;
        }
        else if (diff>0)
        {
            num2 = num2 + '0';
            diff--;
        }
    }
    int index = num1.length()-1;
    char carry = '0';
    int next;
    char num1next;
    char num2next;
    std::string output = "Hello";
    while (index>=0)
    {
        num1next = num1[index];
        num2next = num2[index];
        if(sign1 && !sign2)
        {

        }
        else if (!sign1 && sign2)
        {

        }
        else
        {
            //next = (num1[index] + num2[index] + carry - 3 * '0') / 10;
            if (num1next != '.')
            {
                next = (num1next + num2next - (2 * '0')) % 10;
                cout << next << endl;
                // This works: cout << (num1next + num2next - (2 * '0')) % 10 << endl;
                output = next + output;
            }
            
            //carry = (num1[index] + num2[index] + carry - 3 * '0') % 10;
        }
        index--;
    }
    return "balls";
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
                cout << word1 << "+" << word2 << " = " << addNums(word1,word2) << endl;
            }
            else 
            {
                cout << word1 << " " << word2 << " " << "Invalid Input" << endl;
            }
        }
    }
}