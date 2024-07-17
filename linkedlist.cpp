#include <iostream>
#include <stdlib.h>
using namespace std;

/* The Node class */
class Node
{
public:
    int get() { return object; }
    void set(int object) { this->object = object; }
    Node* getNext() { return nextNode; }
    void setNext(Node* nextNode) { this->nextNode = nextNode; }

private:
    int object;
    Node* nextNode;
};

/* The List class */
class List
{
public:
    // Constructor
    List() {
        headNode = new Node();
        headNode->setNext(NULL);
        currentNode = NULL;
        lastCurrentNode = NULL;
        size = 0;
    }

    // add() method
    void add(int addObject) {
        Node* newNode = new Node();
        newNode->set(addObject);
        if (currentNode != NULL) {
            newNode->setNext(currentNode->getNext());
            currentNode->setNext(newNode);
            lastCurrentNode = currentNode;
            currentNode = newNode;
        } else {
            newNode->setNext(NULL);
            headNode->setNext(newNode);
            lastCurrentNode = headNode;
            currentNode = newNode;
        }
        size++;
    }

    // get() method
    int get() {
        if (currentNode != NULL)
            return currentNode->get();
        return -1; // Return -1 if currentNode is NULL
    }

    // next() method
    bool next() {
        if (currentNode == NULL) return false;
        lastCurrentNode = currentNode;
        currentNode = currentNode->getNext();
        if (currentNode == NULL || size == 0)
            return false;
        else
            return true;
    }

    // start() method
    void start() {
        lastCurrentNode = headNode;
        currentNode = headNode;
    }

    // remove() method
    void remove() {
        if (currentNode != NULL && currentNode != headNode) {
            lastCurrentNode->setNext(currentNode->getNext());
            delete currentNode;
            currentNode = lastCurrentNode;
            size--;
        }
    }

    // length() method
    int length() {
        return size;
    }

    friend void traverse(List list);
    friend List addNodes();

private:
    int size;
    Node* headNode;
    Node* currentNode;
    Node* lastCurrentNode;
};

/* Friend function to traverse linked list */
void traverse(List list) {
    Node* savedCurrentNode = list.currentNode;
    list.start();  // Use start() to position at the beginning
    for (int i = 1; list.next(); i++) {
        cout << "\n Element " << i << " " << list.get();
    }
    list.currentNode = savedCurrentNode;
}

/* Friend function to add Nodes into the list */
List addNodes() {
    List list;
    list.add(2);
    list.add(6);
    list.add(8);
    list.add(7);
    list.add(1);
    cout << "\n List size = " << list.length() << '\n';
    return list;
}

int main() {
    List list = addNodes();
    traverse(list);
    return 0;
}
