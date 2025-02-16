#include <iostream>

struct node{  //Struct of a node
    int data;
    node* next;
    node* pre;
};

class DoubleLinkedList{  
private:
    node* head;  //Head node
    node* tail;  //Tail node
public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}  //Constructor 
    void insertFront(int value){  //Function to insert a node at the start
        node* n = new node();
        n->data = value;
        if (head == nullptr){
            head = tail = n;
        }
        else{
            n->next = head;
            head->pre = n;
            head = n;
        }
    }
    void insertBack(int value){  //Function to insert a node at the end
        node* n = new node();
        n->data = value;
        if (head == nullptr){
            head = tail = n;
        }
        n->pre = tail;
        tail->next = n;
        tail = n;
    }
    void displayForward(){  //Function to diplay list start-->end
        node* ptr = head;
        while (ptr != nullptr){
            std::cout << ptr->data << std::endl;
            ptr = ptr->next;
        }
        std::cout << std::endl;
    }
    void displayBackwards(){  //Function to display list end-->start
        node* ptr = tail;
        while (ptr != nullptr){
            std::cout << ptr->data << std::endl;
            ptr = ptr->pre;
        }
        std::cout << std::endl;
    }
    void deleteNode(int value){  //Function to delete a node based on its value
        if (head == nullptr){
            return;
        }
        node* ptr = head;
        while (ptr != nullptr && ptr->data != value){
            ptr = ptr->next;
        }
        if (ptr == nullptr){
            return;
        }
        if (ptr->pre != nullptr){
            ptr->pre->next = ptr->next;
        }
        else{
            head = ptr->next;
        }
        if (ptr->next != nullptr){
            ptr->next->pre = ptr->pre;
        }
        delete ptr;
    }
    ~DoubleLinkedList(){  //Destructor to free any allocated memory
        node* ptr = head;
        while (head != nullptr){
            head = head->next;
            delete ptr;
        }
    }
};

int main()
{
    DoubleLinkedList list;

    list.insertFront(12);
    list.insertBack(88);
    list.insertFront(33);

    list.displayBackwards();

    list.deleteNode(12);

    list.displayForward();

    return 0;
}