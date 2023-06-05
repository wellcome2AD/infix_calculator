#ifndef POSTFIX_CALCULATOR_STACK_H
#define POSTFIX_CALCULATOR_STACK_H

#endif //POSTFIX_CALCULATOR_STACK_H

#include "LinkedList.h"

template <typename T>
class Stack {
public:
    // constructor and destructor
    Stack();
    ~Stack();

    // prototypes of all the functions:
    void push(T data);
    T pop();
    int size() const;
    T top() const;
    bool empty() const;

private:
    List<T> list;
};


template <typename T>
Stack<T>::Stack()
= default;


template <typename T>
Stack<T>::~Stack()
= default;


// TO GET THE SIZE OF THE STACK
template <typename T>
int Stack<T>::size() const
{
    return list.getSize();
}


// TO CHECK IF STACK IS CURRENTLY EMPTY
template <typename T>
bool Stack<T>::empty() const
{
    return list.getSize() == 0;
}


// TO PUSH THE ELEMENTS ON TOP
template <typename T>
void Stack<T>::push(T data)
{
    list.push_front(data);
}


// TO EXTRACT THE TOP ELEMENT FROM THE STACK
template <typename T>
T Stack<T>::pop()
{
    T data = list[0]; // getting the top element
    list.pop_front(); // removing the element from the stack
    return data;
}


// TO GET THE TOP ELEMENT FROM THE STACK
template <typename T>
T Stack<T>::top() const
{
    return list[0];
}
