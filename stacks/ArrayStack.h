#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

template <typename T>
class ArrayStack
{
private:
    int next;
    T *stack;

public:
    ArrayStack(int capacity): next{0}, stack{new T[capacity]}
    {
    }

    T peek()
    {
        return stack[next - 1];
    }

    T pop()
    {
        return stack[--next];
    }

    void push(T new_element)
    {
        stack[next++] = new_element;
    }

    bool is_empty()
    {
        return next == 0;
    }

    int size()
    {
        return next;
    }

    ~ArrayStack()
    {
        delete[] stack;
    }
};

#endif