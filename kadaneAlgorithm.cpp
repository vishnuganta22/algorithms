// Maximum Subarray Problem
// The maximum subarray problem is the task of finding the largest possible sum of a contiguous subarray, within a given one-dimensional array A[1…n] of numbers


#include <iostream>
#include <limits.h>

using namespace std;

// Brute force method
void printSubArrayOfMaxSum(int* arr, int size){
    int maxSum = INT_MIN;
    for(int i = 0; i < size; i++){
        maxSum = arr[i] > maxSum ? arr[i] : maxSum;
        int previous = arr[i];
        for(int j = i + 1; j < size; j++){
            previous = previous + arr[j];
            if(previous > maxSum) maxSum = previous;
        }
    }
    cout<<"Max Sum :: " << maxSum<<endl;
}

int main()
{
    int size;
    cin>>size;
    int *arr = new int[size];
    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }
    printSubArrayOfMaxSum(arr, size);
    return 0;
}
