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
   LevelorderTraversal(BT);
    return 0;
}

