// Maximum Subarray Problem
// The maximum subarray problem is the task of finding the largest possible sum of a contiguous subarray, within a given one-dimensional array A[1…n] of numbers


#include <iostream>

using namespace std;

int main()
{
    int size;
    cin>>size;
    int *arr = new int[size];
    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }
    return 0;
}
