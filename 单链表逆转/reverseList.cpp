#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* Next;
};
typedef struct Node* List;

List reverse(List L)
{
    List new_head, old_head, temp;
    new_head = NULL;
    old_head = L;

    while(old_head) //循环不变式
    {
        temp = old_head->Next;
        old_head-> Next = new_head;
        new_head = old_head;
        old_head = temp;
    }

    L = new_head;
    return L;
}


List createList(int N)
{
    List head, temp;
    for(int i=0; i<N; i++)
    {
        temp = (List)malloc(sizeof(Node));
        temp->data = 10-i;
        temp->Next = NULL;
        if(i==0) head = temp;
        else {
            temp->Next = head;
            head = temp;
        }
    }
    return head;
}

int main()
{
    List list = createList(10);
    list = reverse(list);
    List temp = list;
    for(int i=0; i<10; i++)
    {
        cout << temp->data << " ";
        temp = temp->Next;
    }
    return 0;
}