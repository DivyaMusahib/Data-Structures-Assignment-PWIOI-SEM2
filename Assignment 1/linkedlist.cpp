#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList{
    private:
    Node* head;
    int size;

    public:
    LinkedList() : head(nullptr), size(0) {}

    void insert(int index, int value){
        if(index < 0 || index > size) return;
        Node* newNode = new Node(value);

        if(index == 0){
            newNode->next = head;
            head = newNode;
        }
        else{
            Node* temp = head;
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        ++size;
    }

    void remove(int index){
        if(index < 0 || index >= size) return;
        Node* temp = head;

        if(index == 0) {
            head = head->next;
            delete temp;
        }
        else{
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
        }
        --size;
    }

    int getSize() const{
        return size;
    }

    bool isEmpty() const{
        return size == 0;
    }

    void rotate(int k){
        if(size == 0 || k % size == 0) return;
        k = k % size;
        Node* temp = head;
        int count = 1;

        while(count < size - k && temp != nullptr){
            temp = temp->next;
            ++count;
        }

        Node* newHead = temp->next;
        temp->next = nullptr;
        Node* current = newHead;

        while(current->next != nullptr){
            current = current->next;
        }
        current->next = head;
        head = newHead;
    }

    void reverse(){
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while(current != nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void append(int value){
        Node* newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
        }
        else{
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        ++size;
    }

    void prepend(int value){

        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        ++size;
    }

    void merge(LinkedList& other){
        if(other.head == nullptr) return;
        if(head == nullptr){
            head = other.head;
        }
        else{
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = other.head;
        }
        size += other.size;
        other.head = nullptr;
        other.size = 0;
    }

    void interleave(LinkedList& other) {
        Node* temp1 = head;
        Node* temp2 = other.head;
        Node* next1;
        Node* next2;
        while(temp1 != nullptr && temp2 != nullptr){
            next1 = temp1->next;
            next2 = temp2->next;
            temp1->next = temp2;
            if (next1 == nullptr) break;
            temp2->next = next1;
            temp1 = next1;
            temp2 = next2;
        }
        if (temp1 == nullptr){
            temp1->next = temp2;
        }
        other.head = nullptr;
        other.size = 0;
    }

    int getMiddle() const{
        if(head == nullptr) return -1;
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    int indexOf(int value) const{
        Node* temp = head;
        int index = 0;
        while(temp != nullptr){
            if (temp->data == value) return index;
            temp = temp->next;
            ++index;
        }
        return -1;
    }

    LinkedList split(int index){
        
        LinkedList newList;
        
        if(index < 0 || index >= size) return newList;
        if(index == 0){
            newList.head = head;
            head = nullptr;
            newList.size = size;
            size = 0;
            return newList;
        }

        Node* temp = head;
        for(int i = 0; i < index - 1; ++i){
            temp = temp->next;
        }
        newList.head = temp->next;
        temp->next = nullptr;
        newList.size = size - index;
        size = index;
        return newList;
    }

    void print() const{
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    
    // Inserts an element at the specified index. Function name -> insert
    // Deletes the element at the specified index. Function name -> remove
    // Returns the size of the linked list. Function name -> getSize
    // Returns true if the linked list is empty, false otherwise. -> isEmpty
    // Rotates the linked list by k positions to the right. -> rotate
    // Reverses the linked list. -> reverse
    // Appends an element to the end of the linked list. -> append
    // Prepends an element to the beginning of the linked list. -> prepend
    // Merges two linked lists into a single linked list. -> merge
    // Interleaves two linked lists into a single linked list. -> interleave
    // Returns the middle element of the linked list. -> getMiddle
    // Returns the index of the first occurrence of the specified element in the linked list, or -1 if the element is not found. ->indexOf
    // Splits the linked list into two linked lists at the specified index. -> split


    LinkedList list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);
    list1.prepend(0);
    list1.insert(2, 5);
    list1.print(); // 0 1 5 2 3
    list1.remove(2);
    list1.print(); // 0 1 2 3
    list1.reverse();
    list1.print(); // 3 2 1 0
    list1.rotate(2);
    list1.print(); // 1 0 3 2
    cout << "Size: " << list1.getSize() << "\n"; // 4
    cout << "Is empty: " << list1.isEmpty() << "\n"; // 0 (false)
    cout << "Middle element: " << list1.getMiddle() << "\n"; // 0
    cout << "Index of 3: " << list1.indexOf(3) << "\n"; // 2

    LinkedList list2;
    list2.append(4);
    list2.append(5);
    list1.merge(list2);
    list1.print(); // 1 0 3 2 4 5

    LinkedList list3;
    list3.append(6);
    list3.append(7);
    list1.interleave(list3);
    list1.print(); // 1 6 0 7 3 2 4 5

    LinkedList list4 = list1.split(4);
    list1.print(); // 1 6 0 7
    list4.print(); // 3 2 4 5

    return 0;
}
