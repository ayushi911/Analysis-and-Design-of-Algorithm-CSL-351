#include<iostream>
#include<cmath>
#include<vector>
#include <iomanip>
using namespace std;

//This function displays the required 'n' length long gray sequence.
void graycode(int n){
  vector<long long int> v;
  int l;
  if(n==0 || n==1) l=1;
  else l=ceil(log(n)/log(2));//this calculates the number of bits in the representation of the gray sequence.
  for(int i=0;i<n;++i){
    int gray=i^(i>>1);//this produces the decimal equivalent gray number for the respective i
    int k=0;
    long long int binaryNum=0;// binaryNum stores the binary equivalent of the decimal gray number produced.
    while(gray>0){
      binaryNum = binaryNum+(gray % 2*pow(10,k)); 
      gray = gray / 2; 
      k++;
    }
    v.push_back(binaryNum);
  }

  for(int i=0;i<v.size();++i){
  cout.fill('0');
  cout<<setw(l)<<v[i]<<endl;
  }
}
 
int main() {
  int n;
  cin>>n;
  graycode(n);
  return 0;
}
/*
INPUT: 13

OUTPUT:
0000
0001
0011
0010
0110
0111
0101
0100
1100
1101
1111
1110
1010

*/
