#include <iostream>
#include <limits.h>

using namespace std;
class Answer{
    public:
        int start;
        int last;
        int value;
        Answer(int start=0,int last=0,int value=0){
            this->start=start;
            this->last=last;
            this->value=value;}
        void print(){
        if (value==0){
            cout<<0;}
        else{
        cout<<"The indexes are ("<<start;
        cout<<","<<last;
        cout<<")"<<endl;
        cout<<"The maximum sum is "<<value<<endl;}}

};
Answer equal_smallset(Answer one,Answer two,Answer three){
    int first=one.last-one.start;
    int second=two.last-two.start;
    int third=three.last-three.start;
    if (one.value==two.value && two.value==three.value){
        if (first<=second && first<=third){
            return one;}
        else if (first>=second && second<=third){
            return two;}
        else if (third<=second && first>=third){
            return three;}}
    else if (one.value==two.value ){
        if (first>=second){
            return two;}
        else{
            return one;}
        }
    else if (three.value==two.value ){
        if (third>=second){
            return two;}
        else{
            return three;}
        }
    else if (one.value==three.value ){
        if (first>=third){
            return three;}
        else{
            return one;}
        }
}


Answer max(Answer a, Answer b, Answer c) {
    if (a.value>b.value && a.value>c.value){
        return a;}
    else if (b.value>a.value && b.value>=c.value){
        return b;}
    else if (c.value>b.value && c.value>a.value){
        return c;}
    return equal_smallset(a,b,c);
}


Answer maxCrossingSum(int arr[], int l, int m, int h)
{

    int sum = 0;
    int max_left;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum){
          left_sum = sum;
          max_left=i;}}


    sum = 0;
    int right_sum = INT_MIN;
    int max_right;
    for (int i = m+1; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum){
          right_sum = sum;
          max_right=i;}
    }
  return Answer(max_left,max_right,left_sum+right_sum);

}


Answer maxSubArraySum(int arr[], int l, int h){

   if (l == h)
     return Answer(l,h,arr[l]);

   int m = (l + h)/2;

   return max(maxSubArraySum(arr, l, m),
              maxSubArraySum(arr, m+1, h),
              maxCrossingSum(arr, l, m, h));
}

int main()
{
    int num;
    cin>>num;
    int arr[num];
    for (int i=0;i<num;i++){
        cin>>arr[i];}
   Answer max_sum;
   max_sum=maxSubArraySum(arr, 0, num-1);
   max_sum.print();

   return 0;
}
/*-----------------------------INPUT/OUTPUT FORMAT----------------------------

INPUT: 
8
-2 -5 6 -2 -3 1 5 -6

OUTPUT:

The indexes are (2,6)
The maximum sum is 7
*/

