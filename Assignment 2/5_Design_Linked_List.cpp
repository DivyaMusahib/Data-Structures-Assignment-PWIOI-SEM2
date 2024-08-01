// leetcode implementation
// https://leetcode.com/problems/design-linked-list/submissions/1339637730

class Node {
  public:
    int val;
    Node* next;
    Node(int x): val(x), next(nullptr) {}
};

class MyLinkedList {
public:
    Node* head;
    int size;
    MyLinkedList(): head(nullptr), size(0) {}

    int get(int ind) {
        if(ind>=size || ind < 0) {
            return -1;
        }
        Node* current=head;
        for(int i=0;i<ind;++i) {
            current= current->next;
        }
        return current->val;
    }
    

    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);       
    }
    
    void addAtIndex(int ind, int val) {
        if (ind>size || ind < 0) {
            return;
        }
        Node* current= head;
        Node* newNode = new Node(val);
        if (ind == 0) {
            newNode->next = current;
            head = newNode;
        }
        else {
            for(int i=0;i<ind-1;++i) {
                current= current->next;
            }      
            newNode->next = current->next;
            current->next = newNode;
        }
        size++;
    }
    
    void deleteAtIndex(int ind) {
        if(ind>=size || ind < 0) {
            return;
        }
        if (ind == 0) {
            Node* nextNode = head->next;
            delete head;
            head = nextNode;            
        }
        else {
            Node* current= head;
            for(int i=0;i<ind-1;++i) {
                current= current->next;
            }

            Node* nextNode = current->next->next;
            delete current->next;
            current->next = nextNode;
        }
            size--;
    }
    ~MyLinkedList()
    {
        Node *p = head;
        while (head!=nullptr)
        {
            head= head->next;
            delete p;
            p=head;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(ind);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtind(ind,val);
 * obj->deleteAtind(ind);
 */

// classroom
#include<bits/stdc++.h>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int data, Node*next){
        this -> data = data;
        this -> next = next;
    }

    Node(int data){
        this->data = data;
        next = nullptr;
    }

};


class LinkedList{
    private:
    Node* head;
    int size;

    public:
    LinkedList(){
        head = nullptr;
        size = 0;
    }

    int getSize() const{
        return size;
    }
    bool isEmpty() const{
        return getSize() == 0;
    }
    void append(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
           head = newNode; 
        }
        else{
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp-> next;
            }
            temp->next = newNode;
        }
        size++;
    }
    void addFirst(int data){
        Node* newNode = new Node(data);
        newNode -> next = head;
        head =newNode;
        size++;
    }
    void addAt(int index, int data){
        if(index<0 || index>size){
            cout << "Invalid Index\n";
            return;           
        }
        if(index==0){
            addFirst(data);
        }
        else if(index==size){
            append(data);
        }
        else{
            Node* trav = head;
            int id = 0;
            while(id != index-1){
                id ++;
                trav = trav->next;
            }
            Node* newNode = new Node(data);
            newNode->next = trav->next;
            trav->next = newNode;
            size++;
        }
    }
    void removeFirst(){
        if (head == nullptr) return;
        Node * temp = head;
        head = head->next;
        delete temp;
        size--;        
    }
    void removeEnd(){
        if(isEmpty()){
            cout << "List is already empty\n";
            return;
        }
        else if(size==1){
            head = nullptr;
        }
        else{
            Node* temp = head;
            while((temp->next)->next != nullptr){
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
        size--;    
    }

    void print(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << "  ";
            temp = temp-> next;
        }
    }

    bool contains(int data) const {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == data) return true;
            temp = temp->next;
        }
        return false;
    }

    int indexOf(int data) const {
        Node* temp = head;
        int index = 0;
        while (temp != nullptr) {
            if (temp->data == data) return index;
            temp = temp->next;
            index++;
        }
        return -1;
    }

};




int main(){
    LinkedList* divya = new LinkedList();
    cout << divya->getSize() << " iz the size\n";
    divya->append(5);
    cout << divya->getSize() << " iz the size\n";
    divya->print();
    cout << "\n";
    divya->append(89);
    cout << divya->getSize() << " iz the size\n";
    divya->print();
    divya->addFirst(435);
    cout << divya->getSize() << " iz the size\n";
    divya->print();
    cout << "\n";
    divya->addAt(2,78);
    cout << divya->getSize() << " iz the size\n";
    divya->print();
    cout << "\n";
}