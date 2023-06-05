#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#endif //LINKEDLIST_LINKEDLIST_H

#include <iostream>

template <typename T>
class List {
public:
    List();
    ~List();

    void push_back(T data);           // add element in the end
    void push_front(T data);          // add element in the beginning
    void insert(T data, int index);   // add element by index
    void removeAt(int index);           // remove element by index
    void remove(T data);              // remove element by its value
    T& operator[] (int index) const;  // find element by index
    int find(T data);                // find element by its value
    void printElements();               // console output


    int getSize() const {return size;};
    void pop_front();
    void clear();



private:
    // class for elements of our linked list
    class Node{
    public:
        Node *ptrNext;  // pointer to the next element
        T data;       // value of the element

        // constructor of the class Node
        Node(T data = 0, Node *ptrNext = nullptr){
            this->data = data;
            this->ptrNext = ptrNext;
        }

    };

    Node *head;     // pointer to head of list
    int size;       // number of items in the list
};





// constructor and destructor of the class List (separated)
template <typename T>
List<T>::List() {
    size = 0;
    head = nullptr;
}
template <typename T>
List<T>::~List() {
    clear();
}

// Method PUSH_FRONT - add element in the beginning
template <typename T>
void List<T>::push_front(T data) {
    head = new Node(data, head);        // assign the newly created node to the new head
    size++;
}

// Method PUSH_BACK - add element to the end of the linked list
template <typename T>
void List<T>::push_back(T data) {

    // if head is empty -> create first element
    if (head == nullptr) {
        head = new Node(data);
    }
        // if head is NOT empty:
    else {
        Node *current = this->head;             // start from the head node
        while (current->ptrNext != nullptr){    // looking for the last node in list and create new node
            current = current->ptrNext;
        }
        current->ptrNext = new Node(data);      // when next ptr is null -> create new node
    }
    size++;                                     // increasing the size of the list
}

// Method - Find element by index
template <typename T>
T& List<T>::operator[](int index) const {

    int counter = 0;
    Node *current = this->head;             // start from the head node

    while (current != nullptr) {
        if (counter == index){              // if counter is equal to index -> we found our element
            return current->data;
        }
        else {
            current = current->ptrNext;     // assign the current iterator a pointer to the next element
            counter++;
        }
    }

}

// Method find - search for an element by its value and return its index
template <typename T>
int List<T>::find(T data) {

    int index = 0;
    Node *current = this->head;             // start from the head node

    while (current != nullptr) {
        if (current->data == data) {        // if the data of current node is equal to searched data -> return the index
            return index;
        }
        else {
            current = current->ptrNext;     // assign the current iterator a pointer to the next element
            index++;
        }
    }

    // if element wasn't found, return -1
    return -1;
}

// Method - print all the elements of our linked list
template <typename T>
void List<T>::printElements() {

    if (this->head != nullptr) {            // checking that head node is not empty
        Node *current = this->head;         // start from the head node
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->ptrNext;     // assign the current iterator a pointer to the next element
        }
        std::cout<<std::endl;
    }
    else {
        std::cout << "Nothing to print. List is empty!" << std::endl;
    }
}

// Method INSERT - add element by index
template <typename T>
void List<T>::insert(T data, int index) {

    if (index < 0 || index > size) {
        std::cout << "Given index out of list borders" << std::endl;
    }
    else if (index == 0) {       // if the index of adding element equals to 0
        push_front(data);
    }
    else if (index == size) {   // if it's the last element
        push_back(data);
    }
    else {
        Node *previous = head;
        for (int i = 0; i < index - 1; i++) {   // looking for the pointer of the previous element
            previous = previous->ptrNext;
        }

        Node *newNode = new Node(data, previous->ptrNext);
        previous->ptrNext = newNode;
        size++;
    }

}

// Method removeAt - delete element by index
template <typename T>
void List<T>::removeAt(int index) {
    if (index == 0) {
        pop_front();
    } else {
        Node *previous = head;
        for (int i = 0; i < index - 1; i++) {     // looking for the pointer of the previous element
            previous = previous->ptrNext;
        }

        Node *toDelete = previous->ptrNext;      // the address of the next element is placed in the temp variable to delete
        previous->ptrNext = toDelete->ptrNext;
        delete toDelete;

        size--;
    }
}

// Method remove - delete element by its value
template <typename T>
void List<T>::remove(T data) {

    if (head == nullptr) {      // if list is empty
        return;
    }
    else if (head->data == data) {      // if head node contains the value to remove
        pop_front();                    // deleting the head node
        return;
    }
    Node *previous = this->head;
    Node *toDelete = previous->ptrNext;

    while (toDelete != nullptr) {
        if (toDelete->data == data) {   // if the value in the node is found
            previous->ptrNext = toDelete->ptrNext;   // skip the node to delete
            delete toDelete;            // delete the node
            size--;                     // decrease the size of the list
            return;
        }
        previous = toDelete;            // assign the current iterator to the previous node
        toDelete = toDelete->ptrNext;   // assign the next iterator to the current node
    }
}





// delete first element
template <typename T>
void List<T>::pop_front() {

    Node *temp = head;
    head = head->ptrNext;

    delete temp;
    size--;
}

// delete all the elements of list
template <typename T>
void List<T>::clear() {
    while (size)
    {
        pop_front();
    }
}