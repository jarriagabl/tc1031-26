#ifndef TREE_NODE_H
#define TREE_NODE_H

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(): data{}, left{nullptr}, right{nullptr}
    {
    }

    TreeNode(T data): data{data}, left{nullptr}, right{nullptr}
    {
    }
};
#endif