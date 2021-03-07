#include <iostream>
using namespace std;

#define MAXDATA 100000 //哨兵

typedef struct HNode* Heap;
struct HNode
{
    int *data;    //存储元素的数组
    int size;     //堆中当前元素的个数
    int capacity; //堆的最大容量
};
typedef Heap MaxHeap; //最大堆
typedef Heap MinHeap; //最小堆

MaxHeap createHeap(int MaxSize); //创建空的最大堆
void BuildHeap(MaxHeap H);       //最大堆元素下滤调整
void PercDown(MaxHeap H, int p);
bool insert(MaxHeap H, int x);   //插入
int deleteMax(MaxHeap H);        //删除


int main() {
    MaxHeap H;
    int MaxSize = 100;
    H = createHeap(MaxSize);
    for(int i=1; i<=10; i++)
    {
        H->data[i] = i-1;
        H->size++;
    }
    BuildHeap(H);
//    insert(H, 11);
    cout<<deleteMax(H)<<endl;
    for(int i=1; i<=H->size; i++)
    {
        cout << H->data[i] << " ";
    }
    return 0;
}


//创建容量为MaxSize的空的最大堆
MaxHeap createHeap(int MaxSize)
{
    MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
    H->data = (int *)malloc((MaxSize+1)* sizeof(int));
    H->size = 0;
    H->capacity = MaxSize;
    H->data[0] = MAXDATA;  //定义"哨兵"大于堆中所有可能元素的值。堆中的结点从下标1开始。
    return H;
}


//最大堆的建立
void BuildHeap(MaxHeap H)
{
    /*
     * 调整 H->Data[] 中的元素，使满足最大堆的有序性。
     * 这里假设所有 H->Size 个元素已经存在 H->Data[]中
     */

    int i;
    /*
     * 从最后一个节点的父节点开始，到根结点1
     */
    for(i = H->size/2; i>0; i--)
    {
        PercDown(H, i);
    }
}


//下滤
void PercDown(MaxHeap H, int p)
{
    /*
     * 每个节点与它的子孙结点进行比较过滤
     */

    int parent, child;
    int x;
    x = H->data[p];
    for(parent = p; parent*2 <= H->size; parent = child)
    {
        child = parent*2;
        if((child != H->size) && H->data[child]<H->data[child+1])
        {
            child++;  //child指向左右子节点的较大者
        }
        if(x > H->data[child]) break;
        else { //下滤
            H->data[parent] = H->data[child];
        }
    }
    H->data[parent] = x;
}

//插入结点
bool insert(MaxHeap H, int x)
{
    /*
     * 时间复杂度T(N)=O(logN):树的高度
     */
    int i;
    if(H->size == H->capacity) return false;  //堆已满
    i = ++H->size;
    for( ; H->data[i/2] < x; i/=2)
    {
        H->data[i] = H->data[i/2]; //上滤
    }
    H->data[i] = x;
    return true;
}

//删除结点
int deleteMax(MaxHeap H)
{
    if(H->size == 0) return -1;
    int parent, child;
    int MaxItem, x;
    MaxItem = H->data[1]; //取出根结点存放的最大值
    /*
     * 用最大堆中最后一个元素从根结点开始向上过滤下层结点
     */
    x = H->data[H->size--];
    for(parent=1; parent*2<=H->size; parent = child)   // parent*2<=H->size 判断是否有左儿子
    {
        child = parent*2;
        if((child != H->size) && (H->data[child] < H->data[child+1]))
            child++; //child指向左右子结点中的较大者
        if(x >= H->data[child]) break; //找到了合适的位置
        else {
            H->data[parent] = H->data[child];
        }
    }
    H->data[parent] = x;

    return MaxItem;
}