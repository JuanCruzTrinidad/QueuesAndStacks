#include <cstddef>
//https://13dipty.medium.com/binary-search-tree-implementation-in-c-537b9a9cedf8
class BST
{
public:
    int value;
    BST* left;
    BST* right;
    BST(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }

    BST& insert(int val)
    {
        BST* currentNode = this;
        while (true)
        {
            if (val < currentNode->value)
            {
                //SI el valor es menor, se busca hacia la izquierda.
                if (currentNode->left == NULL)
                {
                    // If left node of current node is end of the BST, iserting the value there
                    //Si el nodo izquierdo del nodo actual es el final de la BST, se anula el valor allí.
                    BST* newNode = new BST(val);
                    currentNode->left = newNode;
                    break;
                }
                else {
                    //initializing current node to the left node
                    //Se cambia el nodo actual por el de la izquierda
                    currentNode = currentNode->left;
                }
            }
            else {
                // Si el valor es mayor que el valor actual, explorar el subárbol derecho
                if (currentNode->right == NULL) {
                    //Si este nodo es el final, creo el nuevo nodo.
                    BST* newNode = new BST(val);
                    currentNode->right = newNode;
                    break;
                }
                else {
                    //Se cambia el nodo por el de la derecha.
                    currentNode = currentNode->right;
                }
            }
        }
        return *this;
    }
    bool search(int val) {
        BST* currentNode = this;
        while (currentNode != NULL) {
            if (val < currentNode->value) {
                //if value is less than the current nodes value exploring left sub-tree
                currentNode = currentNode->left;
            }
            else if (val > currentNode->value) {
                \
                    //if value is greater than the current nodes value exploring right sub-tree
                    currentNode = currentNode->right;
            }
            else {
                //value is found
                return true;
            }
        }
        return false;
    }
    BST& remove(int val, BST* parentNode = NULL) {
        BST* currentNode = this;
        while (currentNode != NULL) {
            //searching the value
            if (val < currentNode->value) {
                parentNode = currentNode;
                currentNode = currentNode->left;
            }
            else if (val > currentNode->value) {
                parentNode = currentNode;
                currentNode = currentNode->right;
            }
            else {
                //when the value is found
                if (currentNode->left != NULL && currentNode->right != NULL) {
                    //if the node has two children we are finding the minimum value of right sub-tree
                    currentNode->value = currentNode->right->getMinValue();
                    currentNode->right->remove(currentNode->value, currentNode);
                }
                else if (parentNode == NULL) {
                    //if the to deleted node is the root node
                    if (currentNode->left != NULL) {
                        //if it has only left child
                        currentNode->value = currentNode->left->value;
                        currentNode->right = currentNode->left->right;
                        currentNode->left = currentNode->left->left;
                    }
                    else if (currentNode->right != NULL) {
                        //if it has only right child
                        currentNode->value = currentNode->right->value;
                        currentNode->left = currentNode->right->left;
                        currentNode->right = currentNode->right->right;
                    }
                    else {
                        //if it has no child nodes
                        currentNode->value = 0;
                    }
                }
                else if (parentNode->left == currentNode) {
                    //if the value is not in the root node and has left child node
                    if (currentNode->left != NULL) {
                        //if this node has left child node
                        parentNode->left = currentNode->left;
                    }
                    else if (currentNode->right != NULL) {
                        //if this node has right child node
                        parentNode->right = currentNode->right;
                    }
                }
                else if (parentNode->right == currentNode) {
                    //if the value is not in the root node and has righ child node
                    if (currentNode->left != NULL) {
                        //if this node has left child node
                        parentNode->right = currentNode->left;
                    }
                    else {
                        //if this node has right child node
                        parentNode->right = currentNode->right;
                    }
                }
                break;
            }
        }
        return  *this;
    }
    int getMinValue() {
        BST* currentNode = this;
        while (currentNode->left != NULL) {
            currentNode = currentNode->left;
        }
        return currentNode->value;

    }

    int getMaxValue() {
        BST* currentNode = this;
        while (currentNode->right != NULL) {
            currentNode = currentNode->right;
        }
        return currentNode->value;

    }
};