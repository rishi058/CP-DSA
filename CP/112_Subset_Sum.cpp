#include <bits/stdc++.h>
using namespace std;

/*
Q.1 -> Given and array A & sum S, Find it is possible that a subset Sum of A = S.
Q.2 -> Given an array A, is it possible to divide it into two Subset that there sum are equal..

***********  APPROACH  **********8
using generating subset algo, we can solve this brute-forcly..
Q.2 -> generate all subset and check any subset has sum = S/2,

*/


int n, sum;
vector<vector<int> > dp(n + 1, vector<int>(sum + 1, -1));

bool func(int i, int sum, vector<int> v){
    if(sum ==0 ){return true;}
    if( i<0 ){return false;}

    // not cosider ith index
    bool is_possible = func(i-1, sum, v);

    // consider ith index
    is_possible |= func(i-1, sum-v[i], v);  // or is equal to...

    return  is_possible;
}

bool can_partition(vector<int> v){
    int sum = accumulate(v.begin(), v.end(), 0);
    if(sum%2==1){return false;}
    sum = sum/2;
    return func(v.size()-1, sum, v);
}

int main()
{
    cin>>n;
    vector<int> v(n);
    sum=0;
    for(int i=0; i<n; i++){
        cin>>v[i];
        sum+=v[i];
    }

    cout<<can_partition(v);
}

/*
// A recursive C++ program for partition problem
#include <bits/stdc++.h>
using namespace std;

// A utility function that returns true if there is
// a subset of arr[] with sun equal to given sum
bool isSubsetSum(int arr[], int n, int sum,
				vector<vector<int> >& dp)
{
	// Base Cases
	if (sum == 0)
		return true;
	if (n == 0 && sum != 0)
		return false;

	// return solved subproblem
	if (dp[n][sum] != -1) {
		return dp[n][sum];
	}

	// If last element is greater than sum, then
	// ignore it
	if (arr[n - 1] > sum)
		return isSubsetSum(arr, n - 1, sum, dp);

	/* else, check if sum can be obtained by any of
		the following
		(a) including the last element
		(b) excluding the last element
	*/
	// // also store the subproblem in dp matrix
	// return dp[n][sum]
	// 	= isSubsetSum(arr, n - 1, sum, dp)
	// 		|| isSubsetSum(arr, n - 1, sum - arr[n - 1],
	// 						dp);
// }

// Returns true if arr[] can be partitioned in two
// subsets of equal sum, otherwise false
// bool findPartiion(int arr[], int n)
// {
	// Calculate sum of the elements in array
	// int sum = 0;
	// for (int i = 0; i < n; i++)
	// 	sum += arr[i];

	// If sum is odd, there cannot be two subsets
	// with equal sum
	// if (sum % 2 != 0)
	// 	return false;

	// To store overlapping subproblems
	// vector<vector<int> > dp(n + 1,
	// 						vector<int>(sum + 1, -1));

	// Find if there is subset with sum equal to
	// half of total sum
// 	return isSubsetSum(arr, n, sum / 2, dp);
// }

// Driver code
// int main()
// {
// 	int arr[] = { 3, 1, 5, 9, 12 };
// 	int n = sizeof(arr) / sizeof(arr[0]);

// 	// Function call
// 	if (findPartiion(arr, n) == true)
// 		cout << "Can be divided into two subsets "
// 				"of equal sum";
// 	else
// 		cout << "Can not be divided into two subsets"
// 				" of equal sum";

// 	int arr2[] = { 3, 1, 5, 9, 14 };
// 	int n2 = sizeof(arr2) / sizeof(arr2[0]);

// 	if (findPartiion(arr2, n2) == true)
// 		cout << endl
// 			<< "Can be divided into two subsets "
// 				"of equal sum";
// 	else
// 		cout << endl
// 			<< "Can not be divided into two subsets"
// 				" of equal sum";
// 	return 0;
// }
