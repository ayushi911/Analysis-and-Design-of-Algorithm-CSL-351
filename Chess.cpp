#include <iostream>
#include<vector>
using namespace std;

void magnus(vector<vector<int>> matrix,int n){
int s=0,t=s+1;
while(t<n){
  if(matrix[s][t]==2)t++;
  else {
    s=t;
    t=s+1;
  }
}
int magnus=1;
for(int i=0;i<s;++i){
  if(matrix[s][i]==2)continue;
  else magnus=0;
} 
if(magnus)cout<<"\nMAGNUS is "<<s+1<<"\n";
else cout<<"\nNO MAGNUS";
}
int main() {
  int n;//let no. of players be n
  cin>>n;
  //entering 0 for loose, 1 for draw and 2 for win of i against j
  vector<vector<int>> matrix; 
	for(int i=0;i<n;++i) { 
	  vector<int> row; 
		for(int j=0;j<n;++j){ 
			int value; 
			cin >> value; 
			row.push_back(value); 
		} 
		//Push the row in matrix 
		matrix.push_back(row); 
	} 
  magnus(matrix,n);
}
/*FOR EXAMPLE
input:

12
2 1 0 1 1 0 0 2 2 0 1 0
1 2 0 1 2 0 0 2 1 0 1 1  
2 2 2 0 0 0 2 0 0 1 1 0
1 1 2 2 1 0 2 0 1 0 0 2
1 0 2 1 2 0 0 1 2 2 0 1
2 2 2 2 2 2 2 2 2 2 2 2
2 2 0 0 2 0 2 2 0 1 1 0
0 0 2 2 1 0 0 2 1 1 2 2
0 1 2 1 0 0 2 1 2 0 0 1
2 2 1 2 0 0 1 1 2 2 1 2
1 1 1 2 2 0 1 0 2 1 2 1
2 1 2 0 1 0 2 0 1 0 1 2



output:
MAGNUS is 6

*/
