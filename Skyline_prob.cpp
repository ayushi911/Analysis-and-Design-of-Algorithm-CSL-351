#include <iostream>

using namespace std;
//This class contains the 3 defining value for a building.
class Building {
  public:
    int left;
    int right;
    int value;
    Building(int left=0,int value=0,int right=0){
        this->left=left;
        this->right=right;
        this->value=value;}
};

class Strip{
    public:
        int left;
        int value;
        Strip(int left=0,int value=0){
            this->left=left;
            this->value=value;}
};

//This class is to calculate the skyline
class SkyLine
{
    Strip *arr;
    int capacity;
    int n;
public:
    SkyLine(int capacity)
    {
        this->capacity = capacity;
        arr =new Strip[capacity];
        n = 0;
    }
    ~SkyLine() {  delete[] arr;  }
    int count()  { return n; }

    void append(Strip *st)
    {

        if (n>0 && arr[n-1].value == st->value)
            return;
        if (n>0 && arr[n-1].left == st->left)
        {
            arr[n-1].value = max(arr[n-1].value, st->value);
            return;
        }

        arr[n] = *st;
        n++;
    }
    void print()
    {   cout<<"(";
        for (int i=0; i<n-1; i++)
        {
            cout << arr[i].left << ", "<< arr[i].value <<", ";
        }
        cout << arr[n-1].left<< ")";

    }

//merging the skyline of the buildings.
  SkyLine* Merge(SkyLine *other){
    SkyLine *res = new SkyLine(this->n + other->n);
    int h1 = 0, h2 = 0, i = 0, j = 0;
    while (i < this->n && j < other->n)
    {

        if (this->arr[i].left < other->arr[j].left)
        {
            int x1 = this->arr[i].left;
            h1 = this->arr[i].value;


            int maxh = max(h1, h2);

            res->append(new Strip(x1, maxh));
            i++;
        }
        else
        {
            int x2 = other->arr[j].left;
            h2 = other->arr[j].value;
            int maxh = max(h1, h2);
            res->append(new Strip(x2, maxh));
            j++;
        }
    }


    while (i < this->n)
    {
        res->append(&arr[i]);
        i++;
    }
    while (j < other->n)
    {
        res->append(&other->arr[j]);
        j++;
    }
    return res;
}

};

SkyLine *findSkyline(Building arr[], int l, int h)
{
    if (l == h)
    {
        SkyLine *res = new SkyLine(2);
        res->append(new Strip(arr[l].left, arr[l].value));
        res->append(new Strip(arr[l].right, 0));
        return res;
    }

    int mid = (l + h)/2;

    SkyLine *sl = findSkyline(arr, l, mid);
    SkyLine *sr = findSkyline(arr, mid+1, h);
    SkyLine *res = sl->Merge(sr);

    delete sl;
    delete sr;

    return res;
}

int main()

{   int n;
    cin>>n;
    Building arr[n];
for (int i=0;i<n;i++){
        int l,m,n;
        cin>>l;
        cin>>m;
        cin>>n;
        arr[i]=Building(l,m,n);
        }
 //= {{1, 11, 5}, {2, 6, 7}, {3, 13, 9},{12, 7, 16}, {14, 3, 25}, {19, 18, 22},{23, 13, 29}, {24, 4, 28}};
    SkyLine *ptr = findSkyline(arr, 0, n-1);
    cout <<"\nSkyline for given buildings is :";
    ptr->print();
    return 0;
}

/*-----------------------INPUT/OPTPUT FORMAT----------------------------
INPUT:
8
1 11 5
2 6 7
3 13 9
12 7 16
14 3 25
19 18 22
23 13 29
24 4 28

OUTPUT:

Skyline for given buildings is :(1, 11, 3,13, 9, 0,12, 7, 16, 3, 19, 18, 22, 3, 23, 13, 29)
*/

