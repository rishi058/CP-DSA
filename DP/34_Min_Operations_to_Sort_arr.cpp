#include <bits/stdc++.h> 
using namespace std; 

// function to find minimum number of increment or decrement (by 1) operations to make the array in increasing order. 
// https://iq.opengenus.org/minimum-increment-decrement-operation-increasing-order/

int Get_Minimum_Opr(vector<int> &a, int n) 
{ 

    // Finding the smallest element in the array 
    int s = *min_element(a.begin(), a.end()); 
  
    // Finding the largest element in the array 
    int l = *max_element(a.begin(), a.end()); 
  
    /* 
    dp(i, j) represents the minimum number of operations needed to make the array[0 .. i] sorted in increasing order with ith element is j. 
    */
    
    int dp[n][l + 1]; 
  
    // Filling the dp[][] array for base cases 
    for (int j = s; j <= l; j++) { 
        dp[0][j] = abs(a[0] - j); 
    } 
  
    /* 
    Using results for the first (i - 1) elements, calculate the result for the ith element. 
    */
    
    for (int i = 1; i < n; i++) { 
        int minimum = INT_MAX; 
        for (int j = s; j <= l; j++) { 
        
        /* 
            If the ith element is j then we can have any value from s to j for the (i-1)th element 
            We choose the one that requires the minimum number of operations. 
        */
        
            minimum = min(minimum, dp[i - 1][j]); 
            dp[i][j] = minimum + abs(a[i] - j); 
        } 
    } 
  
    /* 
        If we made the (n - 1)th element equal to j we would require dp(n-1, j) operations.
        We choose the minimum among all possible dp(n-1, j) where j goes from small to large 
    */
    
    int ans = INT_MAX; 
    for (int j = s; j <= l; j++) { 
        ans = min(ans, dp[n - 1][j]); 
    } 
    
    // return required answer 
    return ans; 
} 

// Driver code 
int main() 
{ 
    vector<int> arr ;
  	int n,a;
    cout<<"Enter the total number of elements in the array"<<endl;
  	cin>>n;
    for(int i=0;i<n;i++)
    {
            cout<<"Enter the element"<<endl;
            cin>>a;
            arr.push_back(a);
    } 
    cout << Get_Minimum_Opr(arr,n); 
    return 0; 
} 
