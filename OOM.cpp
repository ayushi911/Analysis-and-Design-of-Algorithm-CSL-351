#include <iostream>
#include<vector>
using namespace std;

void max_sumset(int arr[],int n){
   int freq[n];//taking the frequency of each image
   for(int i=0;i<n;++i)//first initializing all elements as 0
      freq[i]=0;
   for(int i=0;i<n;++i)
        freq[arr[i]-1]++;
   for(int i=0;i<n;++i){
     if(freq[i]==0 && arr[i]!=0){
       int temp=i;
       while(freq[temp]==0 && arr[temp]!=0){
         int p=arr[temp]-1;
         freq[p]--;
         arr[temp]=0;
         temp=p;
       }
     }
   }
vector <int> v;
for(int i=0;i<n;++i){
  if(freq[i]!=0 && freq[i]==1)
    v.push_back(i+1);
}
//displaying the subset S
for(int i=0;i<v.size();++i)
	cout<<v[i]<<" ";
}
int main() {
int n;
   cin>>n; //size of the Set A
   int arr[n];//array representing the range of the Set A
   //Each element in A represents the image of the (i+1)th element in arr
   //as A is afinite set from 1 to n
   for(int i=0;i<n;++i)
        cin>>arr[i];
  max_sumset(arr,n);
}

/*FOR EXAMPLE
input:

5
2 3 4 5 5

output:
5

*/
