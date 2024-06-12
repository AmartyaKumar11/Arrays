//Problem Statement: Given an array that contains both negative and positive integers, find the maximum product subarray.
//Brute Force Approach :
/*
Approach:
Find all possible subarrays of the given array. Find the product of each subarray. Return the maximum of all them.

Following are the steps for the approach:-

Run a loop on the array to choose the start point for each subarray.
Run a nested loop to get the end point for each subarray.
Multiply elements present in the chosen range.*/




#include<bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int>& nums) {
    int result = INT_MIN;
    for(int i=0;i<nums.size()-1;i++) {
        for(int j=i+1;j<nums.size();j++) {
            int prod = 1;
            for(int k=i;k<=j;k++) 
                prod *= nums[k];
            result = max(result,prod);    
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}
/*
Time Complexity: O(N3)
Reason: We are using 3 nested loops for finding all possible subarrays and their product.

Space Complexity: O(1)
Reason: No extra data structure was used
*/

//Better Aproach :
/*
Approach:
We can optimize the brute force by making 3 nested iterations to 2 nested iterations

Following are the steps for the approach:

Run a loop to find the start of the subarrays.
Run another nested loop
Multiply each element and store the maximum value of all the subarray.
*/



#include<bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int>& nums) {
    int result = nums[0];
    for(int i=0;i<nums.size()-1;i++) {
        int p = nums[i];
        for(int j=i+1;j<nums.size();j++) {
           result = max(result,p);
           p *= nums[j];
        }
        result = max(result,p);//manages (n-1)th term 
    }
    return result;
}

int main() {
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductSubArray(nums);
    return 0;
}

/*
Time Complexity: O(N2)
Reason: We are using two nested loops

Space Complexity: O(1)
Reason: No extra data structures are used for computation
*/

//Optimal Approach :
/*
Algorithm / Intuition
We will optimize the solution through some observations.

Observations:

If the given array only contains positive numbers: If this is the case, we can confidently say that the maximum product subarray will be the entire array itself.
If the given also array contains an even number of negative numbers: As we know, an even number of negative numbers always results in a positive number. So, also, in this case, the answer will be the entire array itself.
If the given array also contains an odd number of negative numbers: Now, an odd number of negative numbers when multiplied result in a negative number. 
Removal of 1 negative number out of the odd number of negative numbers will leave us with an even number of negatives. 
Hence the idea is to remove 1 negative number from the result. 
Now we need to decide which 1 negative number to remove such that the remaining subarray yields the maximum product.

Upon observation, we notice that each chosen negative number divides the array into two parts.
The answer will either be the prefix or the suffix of that negative number.
To find the answer, we will check all possible prefix subarrays (starting from index 0) and all possible suffix subarrays (starting from index n-1).
The maximum product obtained from these prefix and suffix subarrays will be our final answer.
If the array contains 0’s as well: We should never consider 0’s in our answer(as considering 0 will always result in 0) and we want to obtain the maximum possible product. 
So, we will divide the given array based on the location of the 0’s and apply the logic of case 3 for each subarray.
*/

/*
Algorithm: 
We will first declare 2 variables i.e. ‘pre’(stores the product of the prefix subarray) and ‘suff’(stores the product of the suffix subarray). They both will be initialized with 1(as we want to store the product).
Now, we will use a loop(say i) that will run from 0 to n-1.
We have to check 2 cases to handle the presence of 0:
If pre = 0: This means the previous element was 0. So, we will consider the current element as a part of the new subarray. So, we will set ‘pre’ to 1.
If suff = 0: This means the previous element was 0 in the suffix. So, we will consider the current element as a part of the new suffix subarray. So, we will set ‘suff’ to 1.
Next, we will multiply the elements from the starting index with ‘pre’ and the elements from the end with ‘suff’. 
To incorporate both cases inside a single loop, we will do the following:
We will multiply arr[i] with ‘pre’ i.e. pre *= arr[i].
We will multiply arr[n-i-1] with ‘suff’ i.e. suff *= arr[n-i-1].
After each iteration, we will consider the maximum among the previous answer, ‘pre’ and ‘suff’ i.e. max(previous_answer, pre, suff).
Finally, we will return the maximum product.
*/




#include <bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int> &arr) {
    int n = arr.size(); //size of array.

    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (pre == 0) pre = 1;
        if (suff == 0) suff = 1;
        pre *= arr[i];
        suff *= arr[n - i - 1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, -3, 0, -4, -5};
    cout << "The maximum product subarray is: "
         << maxProductSubArray(arr) << "\n";
    return 0;
}

/*
Time Complexity: O(N), N = size of the given array.
Reason: We are using a single loop that runs for N times.

Space Complexity: O(1) as No extra data structures are used for computation.
*/