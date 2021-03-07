#include <iostream>

using namespace std;

int a[10] = {11,52,21,17,2,52,18,1,3,44};

int findKthMax(int*, int, int, int);
int swap(int&, int&);

int compare(int a, int b) {
    return a>b;
}

int main() {

//    sort(a, a+10, compare);
//    for(int i=0; i<10; i++) {
//        cout<<a[i]<<endl;
//    }


    cout<<findKthMax(a, 0 ,9, 5)<<endl;

}

int findKthMax(int* p, int left, int right, int k)
{
    int anchor = p[left];
    int l = left;
    int r = right;

    while(true)
    {
        while(l<r && anchor <= p[l]) l++;
        while(l<r && anchor > p[r]) r--;
        if(l<r)
        {
            swap(p[l], p[r]);
        }
        else {   //l和r相遇
            break;
        }
    }

    swap(p[left], p[l-1]);   //anchor元素位于l-1位置

    if(l-1-left >= k) return findKthMax(p, left, l-1, k);                //左边
    else if(l-left < k) return  findKthMax(p, l+1, r, k-(l-left+1));     //右边
    else return p[l-1];



}

int swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}
