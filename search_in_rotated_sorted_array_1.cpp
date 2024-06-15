//Search Element in a Rotated Sorted Array
/*
Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values) and a target value k. 
Now the array is rotated at some pivot point unknown to you. Find the index at which k is present and if k is not present return -1.
*/

//Brute Force :
/*
Naive Approach (Brute force): 
One straightforward approach we can consider is using the linear search algorithm. Using this method, we will traverse the array to find the location of the target value. 
If it is found we will simply return the index and otherwise, we will return -1.

Algorithm:
We will traverse the array and check every element if it is equal to k. If we find any element, we will return its index.
Otherwise, we will return -1.
*/


#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int n, int k) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == k)
            return i;
    }
    return -1;
}

int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = 9, k = 1;
    int ans = search(arr, n, k);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
    return 0;
}

/*
Time Complexity: O(N), N = size of the given array.
Reason: We have to iterate through the entire array to check if the target is present in the array.

Space Complexity: O(1)
Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).
*/