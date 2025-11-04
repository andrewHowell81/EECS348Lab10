#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;
//Updates version

bool getSign(string* num) // returns true if positive
{
    if (!isdigit((*num)[0]))
    {
        if((*num)[0]=='-')
        {
            (*num).erase(0,1);
            return false;
        }
        else if ((*num)[0]=='+')
        {
            (*num).erase(0,1);
            return true;
        }
    }
    return true; // This only happens during isDouble function
}

bool isDouble(string word)
{
    getSign(&word); // This removes the sign
    bool hasDecimal = false;
    int len = word.length();
    if (len == 0)
    {
        return false;
    }
    for (int i=0;i<len;i++)
    {
        char c = word[i];
        if (!isdigit(c))
        {
            if (c == '.' && !hasDecimal && i != len-1 && i != 0)
            {
                hasDecimal = true;
            }
            else
            {
                return false;
            }
        }
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

    if (num2>num1)
    {
        if(sign1 && sign2){return addNums('+'+num2,'+'+num1);}
        else if(sign1){return addNums('-'+num2,'+'+num1);}
        else if(sign2){return addNums('+'+num2,'-'+num1);}
        else {return addNums('-'+num2,'-'+num1);}
    }


    num2 = '0' + num2;
    num1 = '0' + num1;
    int index = num1.length()-1;
    char carry = '0';
    char next;
    char num1next;
    char num2next;
    std::string output = "";
    while (index>=0)
    {
        num1next = num1[index];
        num2next = num2[index];
        if(sign1 != sign2)
        {
            if (num1==num2)
            {
                return "0";
            }
            if (num1next != '.')
            {
                next = ((num1next-'0')-(num2next-'0')-(carry-'0')) + '0';
                if (next<'0')
                {
                    next+=10;
                    carry = '1';
                }
                else{
                    carry = '0';
                }
                output = next + output;
            }
            else
            {
                output = '.' + output;
            }
        }
        // else if (!sign1 && sign2)
        // {   
        //     if (num1next != '.')
        //     {
        //         next = ((num2next-'0')-(num1next-'0')-(carry-'0')) + '0';
        //         if (next<'0')
        //         {
        //             next+=10;
        //             carry = '1';
        //         }
        //         else{
        //             carry = '0';
        //         }
        //         output = next + output;
        //     }
        //     else
        //     {
        //         output = '.' + output;
        //     }
        // }
        else
        {
            if (num1next != '.')
            {
                next = (((num1next-'0')+(num2next-'0')+(carry-'0'))%10) + '0';
                output = next + output;
                carry = ((num1next-'0')+(num2next-'0')+(carry-'0'))/10 + '0';
            }
            else
            {
                output = '.' + output;
            }
        }
        index--;
    }
    if (num2>num1)
    {
        if (sign2){output='+'+output;}
        else {output='-'+output;}
    }
    else
    {
        if (sign1){output='+'+output;}
        else {output='-'+output;}
    }
    return output;
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
                cout << "(" << word1 << ") + (" << word2 << ") = " << addNums(word1,word2) << endl << endl;
            }
            else 
            {
                cout << "(" << word1 << ") (" << word2 << ") " << "Invalid Input" << endl;
            }
        }
    }
}