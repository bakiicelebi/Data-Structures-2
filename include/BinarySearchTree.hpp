/**
 * @file            BinarySearchTree.hpp
 * @description     Veri dosyasını AVL ağaçlarına yerleştirip Post Order ve Stack kullanımı ile ağaçları tarama işlemleri
 * @course          Birinci Öğretim Veri Yapıları Dersi B Grubu
 * @assignment      2
 * @date            19.12.2023
 * @author          github.com/bakiicelebi -- abdulbaki.celebi@ogr.sakarya.edu.tr 
 */
#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP
#include "Node.hpp"
#include "StackNode.hpp"

class BinarySearchTree
{
private:
    Node *root;
    StackNode *top;
    int sum;
    int turn;
    Node *turnRight(Node *);
    Node *turnLeft(Node *);
    int height(Node *);
    Node *addingAVL(int, Node *);
    void toStackWithPO(Node *);
    void push(int);
    void deleteTree(Node *);

public:
    BinarySearchTree();
    void addingAVL(int);
    void postOrder();
    void clearStack();
    Node *getRoot();
    StackNode *getTop();
    void pop();
    int getSum();
    int setTurn(int);
    int getTurn();
    void deleteTree();
};

#endif