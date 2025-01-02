#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *root = nullptr;

Node *createNode(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node *insertNode(Node *root, int value)
{
    if (root == nullptr)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insertNode(root->left, value);
    }
    else
    {
        root->right = insertNode(root->right, value);
    }
    return root;
}

void preOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " | ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int findDepth(Node* root) {
    if(root == nullptr) {
        return 0;
    }
    int leftSide = findDepth(root->left);
    int rightSide = findDepth(root->right);
    return 1 + max(leftSide, rightSide);
}

int main()
{
    int num;
    while (1)
    {
        cout << "Enter number: ";
        cin >> num;
        root = insertNode(root, num);
        preOrderTraversal(root);
        cout << endl;
        cout << "DEPTH of tree is: " << findDepth(root) << endl;
    }
}
