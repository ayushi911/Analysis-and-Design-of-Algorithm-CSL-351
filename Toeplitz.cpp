#include <iostream>
using namespace std;

int main() {
  int i,j,n;
  cout<<"Enter the size of the Matrix :";
  cin>>n;
  int arr[n][n];
  int v[n];
  cout<<"\nEnter the elements of first row :";
  for(i=0;i<n;++i)
    cin>>arr[0][i];
  cout<<"\nEnter the elements of first column except the elements at (0,0) :";
  for(i=1;i<n;++i)
    cin>>arr[i][0];

  for(i=1;i<n;++i){
    for(j=1;j<n;++j){
      arr[i][j] = arr[i-1][j-1];
    }
  }
  cout<<"\nTherefore the matrix is :\n";
  for(i=0;i<n;++i){
    for(j=0;j<n;++j){
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }

  cout<<"\nEnter the elements of column vector v :";
  for(i=0;i<n;++i)
    cin>>v[i];
  int res[n];
  for(i=0;i<n;++i){
    int sum=0;
    for(j=0;j<n;++j){
      sum+=arr[i][j]*v[j];
    }
    res[i]=sum;
  }
  cout<<"\nThe result of Av is :\n";
  for(i=0;i<n;++i)
    cout<<res[i]<<"\n";
  return 0;
}
/*--------------------------INPUT/OUTPUT--------------------------

Enter the size of the Matrix :4

Enter the elements of first row :1 2 3 4

Enter the elements of first column except the elements at (0,0) :5 6 7

Therefore the matrix is :
1 2 3 4
5 1 2 3
6 5 1 2
7 6 5 1

Enter the elements of column vector v :10 20 30 40

The result of Av is :
300
250
270
380

*/
