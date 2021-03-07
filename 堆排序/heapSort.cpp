#include <iostream>

using namespace std;

void percDown(int A[], int p, int N)
{
    int parent, child;
    int x = A[p];
    for(parent=p; (parent*2+1)<N; parent=child) // (parent*2+1)<N: 父节点有左孩子
    {
        child = parent*2+1;
        if((child+1<N) && (A[child]<A[child+1]))
            child++;
        if(A[child] <= x) break;
        A[parent] = A[child];
    }
    A[parent]=x;
}

void heapSort(int A[], int N)
{
    int i;
    for(int i=N/2-1; i>=0; i--)
    {
        percDown(A, i, N);
    }

    for(int i=N-1; i>0; i--)  // i为待排序的数组大小
    {
        swap(A[0], A[i]);
        percDown(A, 0, i);
    }
}

int main()
{
    int a[10] = {3,4,1,6,7,9,12,52,5,33};
    heapSort(a, 10);
    for(int i=0; i<10; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
