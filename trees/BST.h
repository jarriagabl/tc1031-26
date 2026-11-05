#ifndef BST_H
#define BST_H

#include "TreeNode.h"

template <typename T>
class BST
{
private:
    TreeNode<T> *root;
    int num_elements;

    bool contains(T element, TreeNode<T> *current)
    {
        if(!current)
        {
            return false;
        } else if(element == current->data)
        {
            return true;
        } else if(element < current->data)
        {
            return contains(element, current->left);
        } else
        {
            return contains(element, current->right);
        }
    }

    TreeNode<T>* add(T element, TreeNode<T> *current)
    {
        if(!current)
        {
            TreeNode<T> *new_node{new TreeNode<T>{element}};
            ++num_elements;
            return new_node;
        } else if(element < current->data)
        {
            current->left = add(element, current->left);
        } else if(element > current->data)
        {
            current->right = add(element, current->right);
        }
        return current;
    }

    T predecessor(TreeNode<T> *current)
    {
        current = current->left;
        while(current->right)
        {
            current = current->right;
        }
        return current->data;
    }

    TreeNode<T>* remove(T element, TreeNode<T> *current)
    {
        if(current)
        {
            if(element < current->data)
            {
                current->left = remove(element, current->left);
            } else if(element > current->data)
            {
                current->right = remove(element, current->right);
            } else // Found to delete
            {
                if(current->left and current->right) // 2 kids
                {
                    T pred{predecessor(current)};
                    current->data = pred;
                    current->left = remove(pred, current->left);
                } else if(current->left or current->right) // 1 kid
                {
                    TreeNode<T> *child{current->left};
                    if(current->right)
                    {
                        child = current->right;
                    }
                    delete current;
                    --num_elements;
                    return child;
                } else // Leaf
                {
                    delete current;
                    --num_elements;
                    return nullptr;
                }
            }
        }
        return current;
    }

public:
    BST(): root{nullptr}, num_elements{0}
    {
    }

    BST(T value): root{new TreeNode<T>{value}}, num_elements{1}
    {
    }

    bool contains(T element)
    {
        return contains(element, root);
    }

    void add(T element)
    {
        root = add(element, root);
    }

    void remove(T element)
    {
        root = remove(element, root);
    }

    /**
    bool contains(T element)
    {
        TreeNode<T> *i{root};
        while(i)
        {
            if(element == i->data)
            {
                return true;
            } else if(element < i->data)
            {
                i = i->left;
            } else 
            {
                i = i->right;
            }
        }
        return false;
    }
    */
};
#endif