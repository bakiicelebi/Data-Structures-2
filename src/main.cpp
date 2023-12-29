/**
 * @file            main.cpp
 * @description     Veri dosyasını AVL ağaçlarına yerleştirip Post Order ve Stack kullanımı ile ağaçları tarama işlemleri
 * @course          Birinci Öğretim Veri Yapıları Dersi B Grubu
 * @assignment      2
 * @date            19.12.2023
 * @author          github.com/bakiicelebi -- abdulbaki.celebi@ogr.sakarya.edu.tr 
 */
#include <fstream>
#include "LinkedList.hpp"

int main()
{
    ifstream file("veri.txt");
    if (!file)
    {
        cout << "File couldn't be opened" << endl;
    }
    int number;
    char character;
    BinarySearchTree *treeVar;                 // object for tree
    LinkedList *objectLink = new LinkedList(); // object to hold object of trees to delete in the end
    int counter = 0;
    while (file >> number)
    {
        if (counter == 0)
        {
            treeVar = new BinarySearchTree();
            objectLink->addObjTree(treeVar);
            ++counter;
        }
        treeVar->addingAVL(number);
        file.get(character);
        if (character == '\n')
        {
            counter = 0;
        }
    }
    file.close();
    objectLink->execute();
    delete objectLink;
}