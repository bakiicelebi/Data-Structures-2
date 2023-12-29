/**
 * @file            Node.hpp
 * @description     Veri dosyasını AVL ağaçlarına yerleştirip Post Order ve Stack kullanımı ile ağaçları tarama işlemleri
 * @course          Birinci Öğretim Veri Yapıları Dersi B Grubu
 * @assignment      2
 * @date            19.12.2023
 * @author          github.com/bakiicelebi -- abdulbaki.celebi@ogr.sakarya.edu.tr 
 */
#ifndef NODE_HPP
#define NODE_HPP
#include<iostream>

using namespace std;

class Node
{
public:
    Node(int);
    int data;
    Node *left;
    Node *right;
};

#endif