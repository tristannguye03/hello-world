#include <iostream>

using namespace std;

void printArray();
void userInput();

int arr[15];
int *ptr = &arr[0];

int main()
{
    userInput();
    std::sort(std::begin(arr),std::end(arr) );
    printArray();
    return 0;
}
void userInput()
{
    for (int i=0; i < 15 ; i++)
    {
        cout<<"Enter a number: ";
        cin>>arr[i];
    }
}
void printArray()
{
    for(int i = 0; i < 15; i++)
    {
        cout<< *ptr <<" ";
        ptr++;
    }
}



