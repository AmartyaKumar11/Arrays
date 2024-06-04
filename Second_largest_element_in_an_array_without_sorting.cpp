Brute Force Approach
This Approach only works when there are no duplicates in the array
Approach :
Sort the array in ascending order
The element present at the second index is the second smallest element
The element present at the second index from the end is the second largest element
Time Complexity: O(NlogN), For sorting the array
Space Complexity: O(1)

Better Approach
Approach :
Find the smallest and largest element in the array in a single traversal
After this, we once again traverse the array and find an element that is just greater than the smallest element we just found.
Similarly, we would find the largest element which is just smaller than the largest element we just found
Indeed, this is our second smallest and second largest element.

Time Complexity: O(N), We do two linear traversals in our array
Space Complexity: O(1)

Optimal Approach
Second Smallest Algo:
If the current element is smaller than ‘small’, then we update second_small and small variables
Else if the current element is smaller than ‘second_small’ then we update the variable ‘second_small’
Once we traverse the entire array, we would find the second smallest element in the variable second_small.
Here’s a quick demonstration of the same.

Second Largest Algo:
If the current element is larger than ‘large’ then update second_large and large variables
Else if the current element is larger than ‘second_large’ then we update the variable second_large.
Once we traverse the entire array, we would find the second largest element in the variable second_large.
Here’s a quick demonstration of the same.
  
Time Complexity: O(N), Single-pass solution
Space Complexity: O(1)

  


