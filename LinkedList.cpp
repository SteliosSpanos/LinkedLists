#include <iostream>

struct node{  //Struct of a node
    int data;
    node* next;
};

class LinkedList{
private:
    node* h;  //Head node
public:
    LinkedList(): h(nullptr) {}  //Constructor
    void insertFront(int value){  //Function to insert a new node at the start
        node* n = new node();
        n->data = value;
        n->next = h;
        h = n;
    }
    void insertBack(int value){  //Function to insert a new node at the end
        node* n = new node();
        n->data = value;
        n->next = nullptr;
        if (h == nullptr){
            h = n;
            return;
        }
        else{
            node* last = h;
            while (last->next != nullptr){
                last = last->next;
            }
            last->next = n;
        }
    }
    void insertAfter(int value, node* prev){  //Function to insert a new node after a node
        if (prev == nullptr){
            std::cout << "Previous cannot be NULL" << std::endl;
            return;
        }
        node* n = new node();
        n->data = value;
        n->next = prev->next;
        prev->next = n;
    }
    void displayList(){  //Function to print list
        node* tmp = h;
        while (tmp != nullptr){
            std::cout << tmp->data << std::endl;
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }
    void deleteNode(int value){  //Function to delete a node based on its value
        if (h == nullptr){
            return;
        }
        node* tmp = h;
        node* prev = nullptr;
        while (tmp != nullptr && tmp->data != value){
            prev = tmp;
            tmp = tmp->next;
        }
        if (tmp == nullptr){
            return;
        }
        prev->next = tmp->next;
        delete tmp;
    }
    ~LinkedList(){  //Destructor to free any allocated memory
        node* ptr = h;
        while (h != nullptr){
            h = h->next;
            delete ptr;
        }
    }
};

int main()
{
    LinkedList list;

    list.insertFront(15);
    list.insertBack(12);
    list.insertBack(33);
    list.insertBack(120);
    list.insertBack(1);

    list.displayList();

    list.deleteNode(120);

    list.displayList();

    return 0;
}