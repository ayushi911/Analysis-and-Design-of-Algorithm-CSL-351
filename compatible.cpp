#include <iostream>

using namespace std;


class Request{
    public:
        int index;
        int s;
        int f;
        Request(int index=0,int s=0,int f=0){
            this->index=index;
            this->s=s;
            this->f=f;}
};


void merge(Request arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    Request L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i].f <= R[j].f) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Request arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void Intreval(Request arr[],int n){
    cout<<"The requests that are compatible are numbered : ";
    int last;
    last=arr[0].f;
    cout<<arr[0].index;
    for (int i=1;i<n;i++){
        if (arr[i].s>=last){
            cout<<","<<arr[i].index;
            last=arr[i].f;}
        }}
int main()
{
    int n;
    cin>>n;
    Request arr[n];
    for (int i=1;i<=n;i++){
        int p,q;
        cin>>p;
        cin>>q;
        arr[i-1]=Request(i,p,q);
        }
    //Request arr[] = { Request(1,1,2), Request(2,3,4), Request(3,0,6), Request(4,5,7), Request(5,8,9), Request(6,5,9) };
    mergeSort(arr, 0, n-1);
    Intreval(arr,n);
    return 0;
}
/*-------------------------------------INPUT/OUTPUT FORMAT--------------------------------------

INPUT:
6
1 2
3 4
0 6
5 7
8 9
5 9

OUTPUT:
The requests that are compatible are numbered : 1, 2, 4, 5
*/
