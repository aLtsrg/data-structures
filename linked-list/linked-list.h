#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class LinkedList
{
public:
    
    struct Node 
    { 
        int value; 
        Node *next;

    private:
        // keep constructor private but expose the struct
        // so user can traverse linked list but not create nodes
        // friend keyword allows LinkedList class to access the constructor
        Node(int v, Node *n) : value(v), next(n) {}
        friend class LinkedList;
    };

    LinkedList() : head(nullptr), tail(nullptr) {}
    ~LinkedList()
    {
        if(head == nullptr) return;
        Node *current = head;
        Node *next = head->next;

        while (current != nullptr){
            delete current;
            current = next;
            if(next != nullptr) next = next->next;
        }

        head = nullptr;
        tail = nullptr;
    }

    void push_front(const int& item)
    {
        Node *newNode = new Node(item, head);
        if(tail == nullptr) tail = newNode;
        head = newNode;

        ++size;
    }

    void push_back(const int& item)
    {
        Node *newNode = new Node(item, nullptr);
        if(head == nullptr) head = newNode;
        if(tail != nullptr) tail->next = newNode;
        tail = newNode;
        
        ++size;
    }

    void pop_front()
    {
        //maybe let it segfault?
        if(size == 0) return; 
        if(tail == head) tail = nullptr;

        Node *next = head->next;
        delete head;
        head = next;

        --size;
    }
    
    Node* begin() const { return head; }

    void reverse()
    {
        if(head == nullptr || head == tail) return;
        Node *current = head;
        Node *next = head->next;
        Node *prev = nullptr;

        while (current != nullptr){
            current->next = prev;
            prev = current;
            current = next;
            if(next != nullptr) next = next->next;
        }

        tail = head;
        head = prev;
    }
    

private:

    

    Node *head;
    Node *tail;
    int size{};

};

#endif // LINKED_LIST_H
