#include<bits/stdc++.h> 
using namespace std; 
// this solution is a variation of Largest Sum Contiguous subarray which is bases on the Kadane's algorithm  
void maxSum(int size) 
{ 
  int maxTillHere = INT_MIN, maxEndsHere = 0, StartIndex =0, EndIndex = 0, s=0; 
  int a[size];
  for(int i=0;i<size;++i) cin>>a[i];//tke the input in the array of "size"  
    for (int i=0; i< size; i++ ) 
    { 
        maxEndsHere += a[i]; 
  
        if (maxTillHere < maxEndsHere) 
        { 
            maxTillHere = maxEndsHere; 
            StartIndex = s; // we have tje start index here
            EndIndex = i; // we have the end index here
        } 
  
        if (maxEndsHere < 0) 
        { 
            maxEndsHere = 0; 
            s = i + 1; 
        } 
    } 
    pair<int,int>p;
    p.first=StartIndex;
    p.second=EndIndex;
    int sum=0;
    for(int i=StartIndex; i<=EndIndex;++i)
	sum+=a[i];
    if(sum!=0)
	cout<<"("<<p.first<<","<<p.second<<")"<<endl;// when the sum is non-zero(either negative or positive) the output is the index
    else
	cout<<"NULL"<<endl;// when the sum is zero NULL is displayed
    
} 

int main() 
{ 
    int n;
    cin>>n; 
    maxSum(n); 
    return 0; 
}
/*
INPUT: 
9
4 5 7 8 0 2 -9

OUTPUT:
(0,5)

 */
