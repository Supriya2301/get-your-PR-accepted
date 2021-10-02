/* HACKTOBER FEST 2021 */
/* 
Topic : Dynamic Programming
Solution by: Supriya2301

Problem Statement:  Subset Sum problem
   -> Given an array and a sum. we have to search in an array that whether there is any subset whose sum is equal to the given sum.

   e.g, arr[] = {1,2,3,4,5};
        sum = 12

        o/p = true (as there is a subset {3,4,5} in array whose sum = 12)

Solution approach: Brute force would be to find all subsets and find its sum and then check.But this is not efficient as it can take exponential time.

efficient: We can use DP here as we need optimal solution and also we have choices for each element that whether to include it or not

Here i am using DP top down approach for solving this problem. 
This problem can be seen as a variaton of 0/1 knapsack problem.

*/


#include<bits/stdc++.h>
using namespace std;
bool subsetSum(int arr[],int n,int sum)
{
    // creating dp matrix
   int dp[n+1][sum+1];

 // initialising matrix
   for(int i=0;i<n+1;i++)
   {
       for(int j=0;j<sum+1;j++)
       {
           if(i==0) dp[i][j] = false;
           if(j==0) dp[i][j] = true;
       }
   }
   // Filling the rows and columns  in matrix
   for(int i=1;i<n+1;i++)
   {
       for(int j=1;j<sum+1;j++)
       {   
              if(arr[i-1] <= sum)  // if sum is less , then we have choices to select it or leave it
              {
                  dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
              }
              else  // if sum is more , then we can't select it
              {
                  dp[i][j] = dp[i-1][j];
              }
       }
   }

   // the last grid of matrix will contain the desired output
     return dp[n][sum];
}




int main()
{
// taking size of array and array elements and sum from user.


     int n;
     cout<<"Enter number of elements: "<<endl;
     cin>>n;

     int arr[n];
     cout<<"Enter elements: "<<endl;
     for(int i=0;i<n;i++)
     {
         cin>>arr[i];
     }

     int sum;
     cout<<"Enter sum : "<<endl;
     cin>>sum; 
   // storing the ans in a variable
     bool isPresent = subsetSum(arr,n,sum);

     if(isPresent) cout<<"There is subset available in the given array for given sum";
     else cout<<"No such subset present";



}
