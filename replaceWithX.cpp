#include <iostream>

using namespace std;

void replaceChar(char input[]);

int main()
{
    //Ask user for input and for every 'a', switch with 'x'
    char input[10];
    cout << "Enter input: ";
    cin >> input;
    
    replaceChar(input);
    cout << input;

    return 0;
}

//Recursive function takes in characters from user and switches all 
//letter a with letter x
void replaceChar(char input[])
{
    if(input[0] == '\0')
        return;

    if(input[0] == 'a')
        input[0] = 'x';

    replaceChar(input+1);
}