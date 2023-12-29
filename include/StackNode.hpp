/**
 * @file            StackNode.hpp
 * @description     Veri dosyasını AVL ağaçlarına yerleştirip Post Order ve Stack kullanımı ile ağaçları tarama işlemleri
 * @course          Birinci Öğretim Veri Yapıları Dersi B Grubu
 * @assignment      2
 * @date            19.12.2023
 * @author          github.com/bakiicelebi -- abdulbaki.celebi@ogr.sakarya.edu.tr 
 */
#ifndef STACKNODE_HPP
#define STACKNODE_HPP
#include <iostream>

using namespace std;

class StackNode
{
public:
    StackNode(int);
    int data;
    StackNode *next;
};

#endif