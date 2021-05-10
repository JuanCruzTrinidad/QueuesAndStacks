#pragma once
#include <cstddef>
struct BST {
    int value;
    BST* left;
    BST* right;
};

void insertBST(int val);
bool search(int val);
//BST& remove(int val, BST* parentNode = NULL);
int getMinValue();
int getMaxValue();