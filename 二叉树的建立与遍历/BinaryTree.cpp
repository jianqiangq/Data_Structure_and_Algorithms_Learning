#include <iostream>
#include <stack>
#include <queue>

using namespace std;

typedef struct TNode* BinaryTree;

struct TNode
{
    int data;
    TNode* left;
    TNode* right;
};

//层序生成树算法
int CreateBinaryTree(BinaryTree &BT)
{
    queue<TNode*> q;
    int data;
    TNode* tnode = NULL;
    cin >> data;
    if(data == 0) return 0;
    else {
        BT = tnode = new TNode();
        tnode->data = data;
        tnode->left = NULL;
        tnode->right = NULL;
        q.push(tnode);
    }

    while(!q.empty())
    {
        tnode = q.front();
        q.pop();

        cin >> data;
        if(data == 0)
        {
            tnode->left = NULL;
        }
        else {
            tnode->left = new TNode();
            tnode->left->data = data;
            tnode->left->left = tnode->left->right = NULL;
            q.push(tnode->left);
        }

        cin >> data;
        if(data == 0)
        {
            tnode->right = NULL;
        }
        else {
            tnode->right = new TNode();
            tnode->right->data = data;
            tnode->right->left = tnode->right->right = NULL;
            q.push(tnode->right);
        }
    }
    return 0;
}

//递归先序遍历
int PreOder(BinaryTree BT)
{
    BinaryTree T = BT;
    if(T) {
        cout<<T->data<<endl;
        PreOder(T->left);
        PreOder(T->right);
    }
    return 0;
}

// 非递归中序遍历（先序可简单修改实现；后序需要二次入栈，然后从该节点的右子树继续深入，与前面类同，
// 仍为进入一个节点入栈一个节点，深入不下去再返回，直到第二次从栈中弹出该节点，才访问之）
int InorderTravesal(BinaryTree BT)
{
    BinaryTree T = BT;
    stack<BinaryTree> st;
    while(T!=NULL || !st.empty()) //注意是或，不是与！！
    {
        while(T!=NULL) //一直向左并将沿途结点压入堆栈
        {
            st.push(T);
            T = T->left;
        }
        T = st.top(); //结点弹出堆栈
        cout << T->data << endl; //访问结点
        st.pop();
        T = T->right;
    }
    return 0;
}

//非递归先序遍历
int PreOrderTravesal(BinaryTree BT)
{
    BinaryTree T = BT;
    stack<BinaryTree> st;
    while(T!=NULL || !st.empty()) //注意是或，不是与！！
    {
        while(T!=NULL) //一直向左并将沿途结点压入堆栈
        {
            cout << T->data << endl; //访问结点
            st.push(T);
            T = T->left;
        }
        T = st.top(); //结点弹出堆栈
        st.pop();
        T = T->right;
    }
    return 0;
}

//非递归后序遍历
int LastOrderTravesal(BinaryTree BT)
{
    BinaryTree T = BT;
    stack<BinaryTree> st;
    while(T!=NULL || !st.empty()) //注意是或，不是与！！
    {
        while(T!=NULL) //一直向左并将沿途结点压入堆栈
        {
            st.push(T);
            T = T->left;
        }

        int flag = 1;                     // 辅助变量flag为1表示当前结点的左孩子为空或者已被访问
        BinaryTree pre = NULL;            // 指针变量p指向当前结点的前驱结点

        while(flag == 1 && !st.empty())
        {
            T = st.top();                 // 注意：这里只是获取栈顶元素，而并没有出栈
            if(T->right == pre)           // 如果当前结点右孩子为空，或者已经被访问过，则访问当前结点
            {
                cout << T->data << endl;
                st.pop();                 // 当前结点出栈
                pre = T;                  // 指针变量指向当前结点
                T = NULL;
            }
            else                          // 如果当前结点右孩子不为空，则先去处理右孩子
            {
                T = T->right;             // 处理右孩子
                flag = 0;                 // T的左孩子未被访问，flag置为0
            }
        }
    }
    return 0;
}


//层序遍历
int LevelorderTraversal(BinaryTree BT)
{
    BinaryTree T;

    if(BT == NULL) return 0;
    queue<BinaryTree> q;
    q.push(BT);
    while(!q.empty())
    {
        T = q.front();
        cout << T->data << endl;
        q.pop();
        if(T->left != NULL) q.push(T->left);
        if(T->right != NULL) q.push(T->right);
    }
    return 0;
}


int main()
{
    BinaryTree BT = NULL;
    CreateBinaryTree(BT);
//    PreOder(BT);
//    InorderTravesal(BT);
    LastOrderTravesal(BT);
//    LevelorderTraversal(BT);
    return 0;
}

