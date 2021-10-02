/* Hacktoberfest 2021 */

/* Problem : Equal Sum partition
   Topic : Dynamic programming
  Solution by: Supriya2301

  Problem statement: Given an array and we have to check whether the array can be partitioned into equal sum

   e.g.  arr[] = {1,2,3,6}
         
         o/p: Yes (as this array can be divided into {1,2,3} and {6} both having equal sum)

  Solution approach : we can solve this question using the same approach for subset sum problem

     At first, we need to find the sum of given array elements, and check that whether it is even or odd.
     Second, If it is odd then it can not be partioned into two parts for sure
             If it is even , then only we can partition into equal sum.

    We can find (sum/2) and we can check that if there is any subset with (sum/2) (same as subset sum problem)
      if yes , then there will be another subset having sum = sum/2 for sure
      if no, then its not possible


*/

#include<bits/stdc++.h>
using namespace std;
bool subsetsum(int arr[], int n, int sum)
{

   bool dp[n+1][sum+1];

   for(int i=0;i<n+1;i++)
   {
       for(int j=0;j<sum+1;j++)
       {
           if(i==0) dp[i][j] = false;
           if(j==0) dp[i][j] = true;
       }
   }

   for(int i=1;i<n+1;i++)
   {
       for(int j=1;j<sum+1;j++)
       {
           if(arr[i-1]<=j)
           {
               dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
           }
           else{
               dp[i][j] = dp[i-1][j];
           }
       }
   }

  return dp[n][sum];
}

int main()
{    // taking array as user input
     int n;
     cout<<"Enter number of elements: "<<endl;
     cin>>n;

     int arr[n];
     cout<<"Enter array elements: "<<endl;
     for(int i=0;i<n;i++)
     {
         cin>>arr[i];
     }

     // finding sum of array
     int sum = 0;
  for(int i=0;i<n;i++)
  {
      sum += arr[i];
  }
  // if sum is odd , then we can not partition into equal sum
  if(sum%2 != 0 )  cout<<"Not possible";
  else{
      if(subsetsum(arr,n,sum/2)) // we will check for subset having sum = sum/2
      {
          cout<<"Possible";
      }
      else{
          cout<<"Not possible";
      }
  }

    return 0;
}