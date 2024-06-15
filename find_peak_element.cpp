//Peak element in Array
/*
Problem Statement: Given an array of length N. 
Peak element is defined as the element greater than both of its neighbors. Formally, if 'arr[i]' is the peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'. 
Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number.

What is a peak element?
A peak element in an array refers to the element that is greater than both of its neighbors. Basically, if arr[i] is the peak element, arr[i] > arr[i-1] and arr[i] > arr[i+1].
*/

/*
How to identify if an element arr[i] is a peak:

We know that if arr[i] is the peak, arr[i] > arr[i-1] and arr[i] > arr[i+1]. So, we can check this condition for all the elements and identify the peak. 
But there are the following edge cases:

If n == 1: The aforementioned condition will not be applicable. 
In this scenario, when the array size is 1, the single element within the array serves as the peak, and thus we should return its index. 
Prior information specifies that for the first element, we should treat the previous element as negative infinity, and similarly, for the last element, we should consider the next element as negative infinity.

If i == 0: The aforementioned condition will not be applicable as arr[i-1] will refer to arr[-1] which is invalid. 
So, in this case, we should check if arr[0] > arr[1]. If this condition holds, we can conclude that arr[0] is a peak. 
Prior information specifies that for the first element, we should treat the previous element as negative infinity.

If i == n-1: The aforementioned condition will not be applicable as arr[i+1] will refer to arr[n] which is again invalid. 
So, in this case, we should check if arr[n-1] > arr[n-2]. If this condition holds, we can conclude that arr[n-1] is a peak. 
Prior information specifies that for the last element, we should treat the next element as negative infinity.
*/

//Brute Force :
/*
Naive Approach: 
A simple approach involves iterating through the array and checking specific conditions for each element to determine the peak. 
By considering all the necessary conditions, including edge cases, our final condition can be summarized as follows:
If ((i == 0 or arr[i-1] < arr[i]) and (i == n-1 or arr[i] > arr[i+1])), we have found a peak. In such cases, we can return the index of the element satisfying this condition.

Algorithm:
We will start traversing the array and for every index, we will check the below condition.
If((i == 0 or arr[i-1] < arr[i]) and (i == n-1 or arr[i] > arr[i+1])): whenever this condition is true for an element, we should return its index.
also update the 'index' variable with the corresponding index value, 'i'.
Finally, we will return ‘index’ as our answer.
*/




#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr) {
    int n = arr.size(); //Size of array.

    for (int i = 0; i < n; i++) {
        //Checking for the peak:
        if ((i == 0 || arr[i - 1] < arr[i])
                && (i == n - 1 || arr[i] > arr[i + 1])) {
            return i;
        }
    }
    // Dummy return statement
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}

/*
Time Complexity: O(N), N = size of the given array.
Reason: We are traversing the entire array.

Space Complexity: O(1) as we are not using any extra space.
*/

//Optimal Approach :
/*
We are going to use the Binary Search algorithm to optimize the approach.
The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. 
It does this by determining a specific condition that ensures that the target is not present in that half.
Until now, we have found how to identify if an element is a peak. 
But since binary search works by reducing the search space by half, we have to find a way to identify the halves and then eliminate them accordingly.

How to identify the halves:

The left half of the peak element has an increasing order. This means for every index i, arr[i-1] < arr[i].
On the contrary, the right half of the peak element has a decreasing order. This means for every index i, arr[i+1] < arr[i].
Now, using the above observation, we can easily identify the left and right halves, just by checking the property of the current index, i, like the following:

If arr[i] > arr[i-1]: we are in the left half.
If arr[i] > arr[i+1]: we are in the right half.

How to eliminate the halves accordingly:
If we are in the left half of the peak element, we have to eliminate this left half (i.e.    
low = mid+1). Because our peak element appears somewhere on the right side.
If we are in the right half of the peak element, we have to eliminate this right half (i.e.     high = mid-1). Because our peak element appears somewhere on the left side


in an array with multiple peaks, an index has four possible positions as follows:
The index is a common point where a decreasing sequence ends and an increasing sequence begins.
The index might be on the left half.
The index might be the peak itself.
The index might be on the right half.

If an index is a common point where a decreasing sequence ends and an increasing sequence begins, we can actually eliminate either the left or right half. 
Because both halves of such an index contain a peak. 
So, we decide to merge this case with the condition If arr[i+1] < arr[i]. You can choose otherwise as well.

Algorithm:
Note: At the start of the algorithm, we address the edge cases of identifying the peak element without requiring separate conditions during the check for arr[mid] inside the loop. 
And the search space will be from index 1 to n-2 as indices 0 and n-1 have already been checked in the edge cases.

The final steps will be as follows:

If n == 1: This means the array size is 1. If the array contains only one element, we will return that index i.e. 0.
If arr[0] > arr[1]: This means the very first element of the array is the peak element. So, we will return the index 0.
If arr[n-1] > arr[n-2]: This means the last element of the array is the peak element. So, we will return the index n-1.
Place the 2 pointers i.e. low and high: Initially, we will place the pointers excluding index 0 and n-1 like this: low will point to index 1, and high will point to index n-2 i.e. the second last index.
Calculate the ‘mid’: Now, inside a loop, we will calculate the value of ‘mid’ using the following formula:
mid = (low+high) // 2 ( ‘//’ refers to integer division)
Check if arr[mid] is the peak element:
If arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1]: If this condition is true for arr[mid], we can conclude arr[mid] is the peak element. We will return the index ‘mid’.
If arr[mid] > arr[mid-1]: This means we are in the left half and we should eliminate it as our peak element appears on the right. So, we will do this:
low = mid+1.
Otherwise, we are in the right half and we should eliminate it as our peak element appears on the left. So, we will do this: high = mid-1. 
This case also handles the case for the index ‘mid’ being a common point of a decreasing and increasing sequence. It will consider the left peak and eliminate the right peak.
The steps from 5 to 8 will be inside a loop and the loop will continue until low crosses high.
*/




#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr) {
    int n = arr.size(); //Size of array.

    // Edge cases:
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;

        //If arr[mid] is the peak:
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        // If we are in the left:
        if (arr[mid] > arr[mid - 1]) low = mid + 1;

        // If we are in the right:
        // Or, arr[mid] is a common point:
        else high = mid - 1;
    }
    // Dummy return statement
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}

/*
Time Complexity: O(logN), N = size of the given array.
Reason: We are basically using binary search to find the minimum.

Space Complexity: O(1)
Reason: We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).
*/
