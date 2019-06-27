#include <iostream>
using namespace std;

int a[10] = {11,52,21,17,2,52,18,1,3,44};

void quicksort(int* p, int left, int right);
void swap(int&, int&);

int compare(int a, int b) {
    return a>b;
}

int main() {

//    sort(a, a+10, compare);
//    for(int i=0; i<10; i++) {
//        cout<<a[i]<<endl;
//    }

    quicksort(a, 0, 9);
    for(int i = 0; i < 10; i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}


void quicksort(int* p, int left, int right)
{
    if(left >= right) return;

    int anchor = p[left];
    int i = left;
    int j = right;

    while(i < j)
    {
        while(i < j && p[j] > anchor) j--;
        while(i < j && p[i] <= anchor) i++;

        if(i < j)
        {
            swap(p[i], p[j]);
        }
    }

    swap(anchor, p[i]);


    quicksort(p, left, i-1);
    quicksort(p, i+1, right);

}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
