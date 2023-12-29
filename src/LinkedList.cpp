/**
 * @file            LinkedList.cpp
 * @description     Veri dosyasını AVL ağaçlarına yerleştirip Post Order ve Stack kullanımı ile ağaçları tarama işlemleri
 * @course          Birinci Öğretim Veri Yapıları Dersi B Grubu
 * @assignment      2
 * @date            19.12.2023
 * @author          github.com/bakiicelebi -- abdulbaki.celebi@ogr.sakarya.edu.tr 
 */
#include "LinkedList.hpp"

void LinkedList::deturn()
{
    int count = 1;
    for (TreeNode *printer = firstOfTree; printer != nullptr; printer = printer->next)
    {
        printer->data->setTurn(count);
        ++count;
    }
}
void LinkedList::postOrder()
{
    for (TreeNode *temp = firstOfTree; temp != nullptr; temp = temp->next)
    {
        temp->data->postOrder();
    }
}
void LinkedList::findTheSmallest()
{
    int comparator = 9999999;
    TreeNode *holder;
    for (TreeNode *temp = firstOfTree; temp != nullptr; temp = temp->next)
    {
        if (temp->data->getTop()->data < comparator)
        {
            comparator = temp->data->getTop()->data;
            holder = temp;
        }
    }
    holder->data->pop();
    if (holder->data->getTop() == nullptr)
    {
        clearLink(holder);
        if (firstOfTree->next)
        {
            system("CLS");
            print();
        }
        postOrder();
    }
}
void LinkedList::findTheBiggest()
{
    int comparator = -9999999;
    TreeNode *holder;
    for (TreeNode *temp = firstOfTree; temp != nullptr; temp = temp->next)
    {
        if (temp->data->getTop()->data > comparator)
        {
            comparator = temp->data->getTop()->data;
            holder = temp;
        }
    }
    holder->data->pop();
    if (holder->data->getTop() == nullptr)
    {
        clearLink(holder);
        if (firstOfTree->next)
        {
            system("CLS");
            print();
        }
        postOrder();
        
    }
}
void LinkedList::clearLink(TreeNode *deleting)
{
    deleting->data->deleteTree();
    if (deleting == firstOfTree)
    {
        firstOfTree = deleting->next;
        delete deleting;
    }
    else
    {
        TreeNode *prev = firstOfTree;
        while (prev->next != deleting)
        {
            prev = prev->next;
        }
        prev->next = deleting->next;
        delete deleting;
    }
    counter = 0;
}
void LinkedList::scanStack(int counter)
{
    if (counter % 2 == 1)
    {
        findTheSmallest();
    }
    else
    {
        findTheBiggest();
    }
}
int LinkedList::bringSum(TreeNode *sumVal)
{
    int ascii = sumVal->data->getSum() % (90 - 65 + 1) + 65;
    return ascii;
}
string LinkedList::bringASCII(TreeNode *tree)
{
    string output = "";
    output = bringSum(tree);
    return output;
}
void LinkedList::print()
{
    for (TreeNode *printer = firstOfTree; printer != nullptr; printer = printer->next)
    {
        cout << bringASCII(printer);
    }
    cout << endl;
}
LinkedList::LinkedList()
{
    this->firstOfTree = nullptr;
    this->counter = 1;
}
void LinkedList::addObjTree(BinarySearchTree *pointer)
{
    TreeNode *newNode = new TreeNode(pointer);
    if (firstOfTree == 0)
    {
        firstOfTree = newNode;
    }
    else
    {
        TreeNode *tmp = firstOfTree;
        while (tmp->next != 0)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}
void LinkedList::execute()
{
    deturn();
    postOrder();
    print();
    while (firstOfTree->next != nullptr)
    {
        scanStack(counter);
        ++counter;
    }
    system("CLS");
    cout << "==============================" << endl;
    cout << "|                            |" << endl;
    cout << "|                            |" << endl;
    cout << "|     Son Karakter: " << bringASCII(firstOfTree) << "        |" << endl;
    cout << "|     AVL No      : " << firstOfTree->data->getTurn() << "      |" << endl;
    cout << "|                            |" << endl;
    cout << "|                            |" << endl;
    cout << "==============================" << endl;
    firstOfTree->data->deleteTree();
    delete firstOfTree;
}
