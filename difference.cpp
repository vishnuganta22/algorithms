// Recursive algorithm that will display whether it is possible to choose 2 intergers from a list of integers such that the difference between the two equals a given value.


#include <iostream>
#include <cstdlib>

using namespace std;

bool checkForResult(int* arr, int diff, int start, int next, int size, bool result){
    if(next >= size || start >= next) return result;
    result = result || (abs(arr[start] - arr[next]) == diff);
    result = result || checkForResult(arr, diff, start, next + 1, size, result);
    result = result || checkForResult(arr, diff, start + 1, next, size, result);
    return result;
}

int main()
{
    int size, difference;
    cin>>size;
    int* arr = new int[size];
    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }
    cin>>difference;
    cout<<"Result :: "<<checkForResult(arr, difference, 0, 1, size, false);
    return 0;
}
