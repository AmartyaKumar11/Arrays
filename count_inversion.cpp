//Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort).

//Brute Force Approach :
/*
Solution:

Let’s understand the Question more deeply. 
We are required to give the total number of inversions and the inversions are: For i & j < size of an array if i < j then you have to find pair (a[i], a[j]) such that a[i] > a[j].

For example, for the given array: [5,3,2,1,4], (5, 3) will be a valid pair as 5 > 3 and
index 0 < index 1. But (1, 4) cannot be valid pair.

Naive Approach (Brute force): 

Approach:

The steps are as follows:

First, we will run a loop(say i) from 0 to N-1 to select the first element in the pair.
As index j should be greater than index i, inside loop i, we will run another loop i.e. j from i+1 to N-1.
Inside this second loop, we will check if a[i] > a[j] i.e. if a[i] and a[j] can be a pair. If they satisfy the condition, we will increase the count by 1.
Finally, we will return the count i.e. the number of such pairs.
Intuition: The naive approach is pretty straightforward. We will use nested loops to solve this problem. We know index i must be smaller than index j. 
So, we will fix i at one index at a time through a loop, and with another loop, we will check(the condition a[i] > a[j]) the elements from index i+1 to N-1  if they can form a pair with a[i]. 
This is the first naive approach we can think of.
*/



#include <bits/stdc++.h>
using namespace std;

int numberOfInversions(vector<int>&a, int n) {

    // Count the number of pairs:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<int> a = {5, 4, 3, 2, 1};
    int n = 5;
    int cnt = numberOfInversions(a, n);
    cout << "The number of inversions is: "
         << cnt << endl;
    return 0;
}

/*
Time Complexity: O(N2), where N = size of the given array.
Reason: We are using nested loops here and those two loops roughly run for N times.

Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/

//Optimal Approach :
/*
Approach:
The steps are basically the same as they are in the case of the merge sort algorithm. The change will be just a one-line addition inside the merge() function. 
Inside the merge(), we need to add the number of pairs to the count when a[left] > a[right].

The steps of the merge() function were the following:

In the merge function, we will use a temp array to store the elements of the two sorted arrays after merging.
 Here, the range of the left array is low to mid and the range for the right half is mid+1 to high.
Now we will take two pointers left and right, where left starts from low and right starts from mid+1.
Using a while loop( while(left <= mid && right <= high)), we will select two elements, one from each half, and will consider the smallest one among the two. 
Then, we will insert the smallest element in the temp array. 
After that, the left-out elements in both halves will be copied as it is into the temp array.
Now, we will just transfer the elements of the temp array to the range low to high in the original array.
Modifications in merge() and mergeSort(): 

In order to count the number of pairs, we will keep a count variable, cnt, initialized to 0 beforehand inside the merge().
While comparing a[left] and a[right] in the 3rd step of merge(), if a[left] > a[right], we will simply add this line:
cnt += mid-left+1 (mid+1 = size of the left half)
Now, we will return this cnt from merge() to mergeSort(). 
Inside mergeSort(), we will keep another counter variable that will store the final answer.
With this cnt, we will add the answer returned from mergeSort() of the left half, mergeSort() of the right half, and merge().
Finally, we will return this cnt, as our answer from mergeSort().
*/


#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //Modification 1: cnt variable to count the pairs:
    int cnt = 0;

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); //Modification 2
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt; // Modification 3
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

int numberOfInversions(vector<int>&a, int n) {

    // Count the number of pairs:
    return mergeSort(a, 0, n - 1);
}

int main()
{
    vector<int> a = {5, 4, 3, 2, 1};
    int n = 5;
    int cnt = numberOfInversions(a, n);
    cout << "The number of inversions are: "
         << cnt << endl;
    return 0;
}


/*
Time Complexity: O(N*logN), where N = size of the given array.
Reason: We are not changing the merge sort algorithm except by adding a variable to it. So, the time complexity is as same as the merge sort.

Space Complexity: O(N), as in the merge sort We use a temporary array to store elements in sorted order.
*/