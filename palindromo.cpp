#include <iostream>
#include <vector>
using namespace std;

int numberLength(int &number);
void showArray(vector<int> &arr, int &size);
void savingArray(vector<int> &arr, int &number, int &size);
void reverseArray(vector<int> &arr, vector<int> &reverse,int &number, int &size);

bool isPalindrome(int x)
{
    //completa la función
    vector <int> originalNumbers;
    vector <int> reverseNumbers;
    int lenght, cont = 0;

    lenght = numberLength(x);
    savingArray(reverseNumbers,x, lenght);
    reverseArray(reverseNumbers, originalNumbers,x,lenght);
    
    for(int i = 0; i < lenght; i++)
    {
        if(originalNumbers[i] == reverseNumbers[i])
        {
            cont++;
        }
    }
    if(cont == lenght)
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    if(isPalindrome(n)) {
        cout <<n<<" is a palindrome";
    }
    else {
        cout << n<<" is NOT a palindrome";
    }
    
    
    return 0;
}
// to get if the number is a one, ten, hundred, thousand ... 
int numberLength(int &number)
{
    bool exit = true;
    int temp_value = number;
    int counting = 0;
    int list[] = {0,1,2,3,4,5,6,7,8,9};
    while(exit)
    {
        for(int num = 0; num < 10; num++)
        {
            if(temp_value == list[num])
            {
                exit = false;
                break;
            }
        }
        temp_value /= 10;
        counting++; 
    }
    return counting;
}
void savingArray(vector<int> &arr, int &number, int &size)
{
    int temp = number;
    for(int a = 0; a < size; a++)
    {
        arr.push_back(temp%10);
        temp /= 10; 
    }
}
void reverseArray(vector<int> &arr, vector<int> &reverse,int &number, int &size)
{
    for(int n = size-1; n >= 0; n--)
    {
        reverse.push_back(arr[n]);
    }
}
void showArray(vector<int> &arr, int &size)
{
    for(int b = 0; b < size; b++)
    {
        cout << arr[b];
    }
}
