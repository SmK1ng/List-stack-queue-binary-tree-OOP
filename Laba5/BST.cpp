#include "BST.h"

#include<iostream>

BST::BST() : root(NULL) { }

BSTNode* BST::Insert(BSTNode* node, int key)
{
    if (node == NULL)
    {
        node = new BSTNode;
        node->Key = key;
        node->Left = NULL;
        node->Right = NULL;
        node->Parent = NULL;
    }

    else if (node->Key < key)
    {
        node->Right = Insert(node->Right, key);
        node->Right->Parent = node;
    }

    else
    {
        node->Left = Insert(node->Left, key);
        node->Left->Parent = node;
    }

    return node;
}

void BST::Insert(int key)
{
    root = Insert(root, key);
}

void BST::PrintTreeInOrder(BSTNode* node)
{
    if (node == NULL)
        return;

    PrintTreeInOrder(node->Left);

    std::cout << node->Key << " ";

    PrintTreeInOrder(node->Right);
}

void BST::PrintTreeInOrder()
{
    PrintTreeInOrder(root);
    std::cout << std::endl;
}

BSTNode* BST::Search(BSTNode* node, int key)
{

    if (node == NULL)
        return NULL;

    else if (node->Key == key)
        return node;

    else if (node->Key < key)
        return Search(node->Right, key);

    else
        return Search(node->Left, key);
}

bool BST::Search(int key)
{

    BSTNode* result = Search(root, key);

    return result == NULL ?
        false :
        true;
}

int BST::FindMin(BSTNode* node)
{
    if (node == NULL)
        return -1;
    else if (node->Left == NULL)
        return node->Key;
    else
        return FindMin(node->Left);
}

int BST::FindMin()
{
    return FindMin(root);
}

int BST::FindMax(BSTNode* node)
{
    if (node == NULL)
        return -1;
    else if (node->Right == NULL)
        return node->Key;
    else
        return FindMax(node->Right);
}

int BST::FindMax()
{
    return FindMax(root);
}

int BST::Successor(BSTNode* node)
{

    if (node->Right != NULL)
    {
        return FindMin(node->Right);
    }

    else
    {
        BSTNode* parentNode = node->Parent;
        BSTNode* currentNode = node;

        while ((parentNode != NULL) &&
            (currentNode == parentNode->Right))
        {
            currentNode = parentNode;
            parentNode = currentNode->Parent;
        }

        return parentNode == NULL ?
            -1 :
            parentNode->Key;
    }
}

int BST::Successor(int key)
{

    BSTNode* keyNode = Search(root, key);

    return keyNode == NULL ?
        -1 :
        Successor(keyNode);
}

int BST::Predecessor(BSTNode* node)
{

    if (node->Left != NULL)
    {
        return FindMax(node->Left);
    }

    else
    {
        BSTNode* parentNode = node->Parent;
        BSTNode* currentNode = node;

        while ((parentNode != NULL) &&
            (currentNode == parentNode->Left))
        {
            currentNode = parentNode;
            parentNode = currentNode->Parent;
        }

        return parentNode == NULL ?
            -1 :
            parentNode->Key;
    }
}

int BST::Predecessor(int key)
{

    BSTNode* keyNode = Search(root, key);

    return keyNode == NULL ?
        -1 :
        Predecessor(keyNode);
}

BSTNode* BST::Remove(
    BSTNode* node,
    int key)
{

    if (node == NULL)
        return NULL;

    if (node->Key == key)
    {

        if (node->Left == NULL && node->Right == NULL)
            node = NULL;

        else if (node->Left == NULL && node->Right != NULL)
        {

            node->Right->Parent = node->Parent;

            node = node->Right;
        }

        else if (node->Left != NULL && node->Right == NULL)
        {

            node->Left->Parent = node->Parent;


            node = node->Left;
        }

        else
        {

            int successorKey = Successor(key);

            node->Key = successorKey;

            node->Right = Remove(node->Right, successorKey);
        }
    }

    else if (node->Key < key)
        node->Right = Remove(node->Right, key);

    else
        node->Left = Remove(node->Left, key);

    return node;
}

void BST::Remove(int key)
{
    root = Remove(root, key);
}