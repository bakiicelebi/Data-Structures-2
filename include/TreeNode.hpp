/**
 * @file            TreeNode.hpp
 * @description     Veri dosyasını AVL ağaçlarına yerleştirip Post Order ve Stack kullanımı ile ağaçları tarama işlemleri
 * @course          Birinci Öğretim Veri Yapıları Dersi B Grubu
 * @assignment      2
 * @date            19.12.2023
 * @author          github.com/bakiicelebi -- abdulbaki.celebi@ogr.sakarya.edu.tr 
 */
#ifndef TREENODE_HPP
#define TREENODE_HPP
#include "BinarySearchTree.hpp"

using namespace std;

class TreeNode
{
public:
    TreeNode(BinarySearchTree *);
    BinarySearchTree *data;
    TreeNode *next;
};

#endif