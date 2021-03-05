#include <iostream>
#include <algorithm>

using namespace std;

int a[10] = {11,52,21,17,2,52,18,1,3,44};

int compare(int a, int b)
{
    return a>b;
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int findKthMax(int* a, int left, int right, int k)
{
    if(left > right)
    {
        return -1;
    }

    int l = left, r = right;
    int anchor = a[left];

    while(l < r)
    {
        while(l < r && a[r] < anchor) r--;
        while(l < r && a[l] >= anchor) l++;

        if (l < r)
        {
            swap(a[l], a[r]);
        }
    }

    swap(a[left], a[l]);

    if(k > (l-left+1)) return findKthMax(a, l+1, right, k-(l-left+1));
    else if(k < (l-left+1)) return findKthMax(a, left, l-1, k);
    else return a[l];
}

int main()
{
    sort(a, a+10, compare);
    for(int i=0; i<10; i++) {
        cout<<a[i]<<endl;
    }

    cout << findKthMax(a, 0, 9, 0);
    return 0;
}