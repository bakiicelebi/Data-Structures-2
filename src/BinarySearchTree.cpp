/**
 * @file            BinarySearchTree.cpp
 * @description     Veri dosyasını AVL ağaçlarına yerleştirip Post Order ve Stack kullanımı ile ağaçları tarama işlemleri
 * @course          Birinci Öğretim Veri Yapıları Dersi B Grubu
 * @assignment      2
 * @date            19.12.2023
 * @author          github.com/bakiicelebi -- abdulbaki.celebi@ogr.sakarya.edu.tr 
 */
#include "BinarySearchTree.hpp"

using namespace std;

Node *BinarySearchTree::turnRight(Node *elderParent)
{
    Node *leftChild = elderParent->left;
    elderParent->left = leftChild->right;
    leftChild->right = elderParent;
    return leftChild;
}
Node *BinarySearchTree::turnLeft(Node *elderParent)
{
    Node *rightChild = elderParent->right;
    elderParent->right = rightChild->left;
    rightChild->left = elderParent;
    return rightChild;
}
int BinarySearchTree::height(Node *active)
{
    if (active)
    {
        return 1 + max(height(active->left), height(active->right));
    }
    return -1;
}
Node *BinarySearchTree::addingAVL(int addingData, Node *active)
{
    if (active == nullptr)
    {
        return new Node(addingData);
    }
    else if (active->data > addingData)
    {
        active->left = addingAVL(addingData, active->left);
        if (height(active->left) - height(active->right) > 1)
        {
            if (addingData < active->left->data)
            {
                active = turnRight(active);
            }
            else
            {
                active->left = turnLeft(active->left);
                active = turnRight(active);
            }
        }
    }
    else if (active->data < addingData)
    {
        active->right = addingAVL(addingData, active->right);
        if (height(active->right) - height(active->left) > 1)
        {
            if (addingData > active->right->data)
            {
                active = turnLeft(active);
            }
            else
            {
                active->right = turnRight(active->right);
                active = turnLeft(active);
            }
        }
    }
    return active;
}
void BinarySearchTree::toStackWithPO(Node *active)
{
    if (active)
    {
        toStackWithPO(active->left);
        toStackWithPO(active->right);
        if (!(active->left || active->right))
        {
            push(active->data);
        }
        if (active->left || active->right)
        {
            sum = sum + active->data;
        }
    }
}
void BinarySearchTree::push(int data)
{
    StackNode *newStackNode = new StackNode(data);
    if (top != nullptr)
    {
        newStackNode->next = top;
    }
    top = newStackNode;
}
void BinarySearchTree::deleteTree(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}
BinarySearchTree::BinarySearchTree()
{
    this->root = nullptr;
    this->top = nullptr;
    this->sum = 0;
    this->turn = 0;
}
void BinarySearchTree::addingAVL(int addingData)
{
    root = addingAVL(addingData, root);
}
void BinarySearchTree::postOrder()
{
    clearStack();
    toStackWithPO(root);
}
void BinarySearchTree::clearStack()
{
    StackNode *temp = top;
    while (temp != nullptr)
    {
        StackNode *deleting = temp;
        temp = temp->next;
        delete deleting;
    }
    top = nullptr;
    sum = 0;
}
Node *BinarySearchTree::getRoot()
{
    return this->root;
}
StackNode *BinarySearchTree::getTop()
{
    return top;
}
void BinarySearchTree::pop()
{
    if (top != nullptr)
    {
        StackNode *deleting = top;
        top = top->next;
        delete deleting;
    }
}
int BinarySearchTree::getSum()
{
    return sum;
}
int BinarySearchTree::setTurn(int sayac)
{
    this->turn = sayac;
}
int BinarySearchTree::getTurn()
{
    return turn;
}
void BinarySearchTree::deleteTree()
{
    clearStack();
    deleteTree(root);
    root = nullptr;
}