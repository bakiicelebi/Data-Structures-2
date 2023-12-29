/**
 * @file            LinkedList.hpp
 * @description     Veri dosyasını AVL ağaçlarına yerleştirip Post Order ve Stack kullanımı ile ağaçları tarama işlemleri
 * @course          Birinci Öğretim Veri Yapıları Dersi B Grubu
 * @assignment      2
 * @date            19.12.2023
 * @author          github.com/bakiicelebi -- abdulbaki.celebi@ogr.sakarya.edu.tr
 */
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include "BinarySearchTree.hpp"
#include "TreeNode.hpp"
using namespace std;

class LinkedList
{
private:
    TreeNode *firstOfTree;
    int counter;
    void deturn();
    void postOrder();
    void findTheSmallest();
    void findTheBiggest();
    void clearLink(TreeNode *);
    void scanStack(int);
    int bringSum(TreeNode *);
    string bringASCII(TreeNode *);
    void print();

public:
    LinkedList();
    void addObjTree(BinarySearchTree *);
    void execute();
};

#endif