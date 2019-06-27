#include <iostream>

using namespace std;

int a[10] = {11,52,211,317,442,542,1358,1432,3111,4433};

//递归方法
int binarySearch(int* p, int l, int r, int k)
{
    if(l > r)
    {
        return -1;
    }

    int mid = (l+r)/2;
    if(p[mid] == k) return mid;
    else if(p[mid] > k) return binarySearch(p, l, mid-1, k);
    else return binarySearch(p, l+1, r, k);
}

//非递归方法
int binarySearch_(int* p, int l, int r, int k)
{
    int mid;
    int left = l;
    int right = r;

    while(left <= right)
    {
        mid = (left+right)/2;
        if(p[mid]==k) return mid;
        else if(p[mid]>k) right = mid-1;
        else if(p[mid]<k) left = mid+1;
    }

    return -1;
}

int main() {
    cout<<binarySearch_(a, 0, 9, 542)<<endl;
}
