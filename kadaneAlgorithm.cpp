// Maximum Subarray Problem
// The maximum subarray problem is the task of finding the largest possible sum of a contiguous subarray, within a given one-dimensional array A[1…n] of numbers


#include <iostream>
#include <limits.h>

using namespace std;

//  Kadane’s Algorithm
void printSubArrayOfMaxSumUsingAlg(int* arr, int size){
    int gMax = INT_MIN;
    int lMax = 0;
    for(int i = 0; i < size; i++){
        lMax = lMax + arr[i];
        if(lMax > gMax) gMax = lMax;
        if(lMax < 0) lMax = 0;
    }
    cout<<"Max Sum Using  Kadane’s Algorithm :: " << gMax << endl;
}

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
    cout<<"Max Sum Using Brute Force :: " << maxSum<<endl;
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
    printSubArrayOfMaxSumUsingAlg(arr, size);
    return 0;
}

