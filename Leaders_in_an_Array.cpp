//Brute Force 
/*
Solution 1:
Intuition:
There is no special intuition needed here. Just a common fact that we need to compare elements in order to find the greatest is more than enough.

Approach:
In this brute force approach, we start checking all the elements from the start of the array to the end to see if an element is greater than all the elements on its right (i.e, the leader).
For this, we will use nested loops where the outer loop will check for each element in the array whether it is a leader or not.
The inner loop checks if there is any element to the right that is greater than the element currently traversed by the outer loop.
We start by initializing the outer loop pointer to the start element and setting it as the current leader.
If any element traversed is found greater than the element currently set as a leader, it will not go to the ans array and we increment the outer loop pointer by 1 and set the next element as the current leader.
If we don’t find any other element to the right greater than the current element, then we push the current element to the ans array stating that is it the leader element.
*/




#include<bits/stdc++.h>
using namespace std;

vector<int> printLeadersBruteForce(int arr[], int n) {

  vector<int> ans;
  
  for (int i = 0; i < n; i++) {
    bool leader = true;

    //Checking whether arr[i] is greater than all 
    //the elements in its right side
    for (int j = i + 1; j < n; j++)
      if (arr[j] > arr[i]) {
          
        // If any element found is greater than current leader
        // curr element is not the leader.
        leader = false;
        break;
      }

    // Push all the leaders in ans array.
    if (leader)
    ans.push_back(arr[i]);

  }
  
  return ans;
}

int main() {
    
  // Array Initialization.
  int n = 6;
  int arr[n] = {10, 22, 12, 3, 0, 6};

  vector<int> ans = printLeadersBruteForce(arr,n);
  
  for(int i = 0;i<ans.size();i++){
      
      cout<<ans[i]<<" ";
  }
  
  cout<<endl;
  return 0;
}


/*
Time Complexity: O(N^2) { Since there are nested loops being used, at the worst case n^2 time would be consumed }.

Space Complexity: O(N) { There is no extra space being used in this approach. But, a O(N) of space for ans array will be used in the worst case }.
*/

//Optimal Approach :
/*
In the above approach, we do a fresh traversal for each candidate. If we think carefully, we only want to compare the elements on the right side. 
So, what if we start from the last element?
That is, we'll try to remember the greatest element encountered so far and we'll use that to decide whether a candidate is a leader or not.
First, we'll start the traversal from the right. Then, we move toward the left. Whenever we encounter a new element, we check with the greatest element obtained so far.
If the current element is greater than the greatest so far, then the current element is one of the leaders and we update the greatest element.
Else, we proceed with the further elements on the left. This method prints the leaders in the reverse direction of their occurrences. 
If we are concerned about the order, we can use an extra array or a string to order.
*/




#include<bits/stdc++.h>
using namespace std;

vector<int> printLeaders(int arr[], int n) {

  vector<int> ans;
  
 // Last element of an array is always a leader,
 // push into ans array.
 int max = arr[n - 1];
 ans.push_back(arr[n-1]);

  // Start checking from the end whether a number is greater
  // than max no. from right, hence leader.
  for (int i = n - 2; i >= 0; i--)
    if (arr[i] > max) {
      ans.push_back(arr[i]);
      max = arr[i];
    }

  
  return ans;
}

int main() {
    
  // Array Initialization.
  int n = 6;
  int arr[n] = {10, 22, 12, 3, 0, 6};

  vector<int> ans = printLeaders(arr,n);
  
  
  for(int i = ans.size()-1;i>=0;i--){
      
      cout<<ans[i]<<" ";
  }
  
  cout<<endl;
  return 0;
}

/*
Time Complexity: O(N) { Since the array is traversed single time back to front, it will consume O(N) of time where N = size of the array }.

Space Complexity: O(N) { There is no extra space being used in this approach. But, a O(N) of space for ans array will be used in the worst case }.
*/