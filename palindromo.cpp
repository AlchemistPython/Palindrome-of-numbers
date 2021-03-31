#include <iostream>
#include <vector>

using namespace std;

// prototipe 
int numberLength(int &number);
void showArray(vector<int> &arr, int &size);
void savingArray(vector<int> &arr, int &number, int &size);
void reverseArray(vector<int> &arr, vector<int> &reverse,int &number, int &size);

bool isPalindrome(int x)
{
    //complete the function
    vector <int> originalNumbers;
    vector <int> reverseNumbers;
    int lenght, cont = 0;
    // save in lenght the length of the number to know if  it's palindrome
    lenght = numberLength(x);
    // here create the reverse array with every number of the main number
    savingArray(reverseNumbers,x, lenght);
    // only change the direction of the first array with another array
    reverseArray(reverseNumbers, originalNumbers,x,lenght);
    // to compare the two arrays and know if there are palindrome
    
    for(int i = 0; i < lenght; i++)
    {
        if(originalNumbers[i] == reverseNumbers[i])
        {
            // if the cont comes to the same lenght will be palindrome
            cont++;
            // here it would be true, but if a number finds it the same,
            // it will return true and that sould not do it 
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
// this is a simple counter only want to know if there are tens, hundreds
int numberLength(int &number)
{
    bool exit = true;
    int temp_value = number;
    int counting = 0;
    // this list is esencial only for check 
    int list[] = {0,1,2,3,4,5,6,7,8,9};
    // infinite loop
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
        // if the value is greater than 10
        temp_value /= 10;
        // and the counting increase
        counting++; 
        // like if a have 10, the counting will be 2
        // or if a have 4564, the counting will be 4
    }
    return counting;
}
// this function creates an array, but the values will be backwards
void savingArray(vector<int> &arr, int &number, int &size)
{
    int temp = number;
    for(int a = 0; a < size; a++)
    {
        arr.push_back(temp%10);
        temp /= 10; 
    }
}
// I create another arrangement where to accommodate the values ​​of the first fixes its original position
void reverseArray(vector<int> &arr, vector<int> &reverse,int &number, int &size)
{
    for(int n = size-1; n >= 0; n--)
    {
        reverse.push_back(arr[n]);
    }
}
// this function was only created to know if i was putting well the values in the array
void showArray(vector<int> &arr, int &size)
{
    for(int b = 0; b < size; b++)
    {
        cout << arr[b];
    }
}
