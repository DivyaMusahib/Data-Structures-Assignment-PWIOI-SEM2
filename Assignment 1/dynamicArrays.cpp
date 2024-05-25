#include<bits/stdc++.h>
using namespace std;

class DynamicArray {
    private:
    int* arr;
    int capacity;
    int size;

    void resize(int newCapacity){
        int* newArr = new int[newCapacity];
        for(int i = 0; i < size; ++i){
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

    public:
    DynamicArray(int initialCapacity = 2) : capacity(initialCapacity), size(0){
        arr = new int[capacity];
    }

    ~DynamicArray(){
        delete[] arr;
    }

    void insert(int index, int value){
        if(index < 0 || index > size) return;
        if(size == capacity) resize(capacity * 2);
        for(int i = size; i > index; --i){
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        ++size;
    }

    void remove(int index) {
        if(index < 0 || index >= size) return;
        for(int i = index; i < size - 1; ++i){
            arr[i] = arr[i + 1];
        }
        --size;
        if(size > 0 && size == capacity / 4) resize(capacity / 2);
    }

    int getSize() const{
        return size;
    }

    bool isEmpty() const{
        return size == 0;
    }

    void rotate(int k) {
        if(size == 0 || k % size == 0) return;
        k = k % size;
        int* temp = new int[size];
        for(int i = 0; i < size; ++i){
            temp[(i + k) % size] = arr[i];
        }
        for(int i = 0; i < size; ++i){
            arr[i] = temp[i];
        }
        delete[] temp;
    }

    void reverse(){
        for (int i = 0; i < size / 2; ++i) {
            swap(arr[i], arr[size - 1 - i]);
        }
    }

    void append(int value){
        if (size == capacity) resize(capacity * 2);
        arr[size++] = value;
    }

    void prepend(int value){
        insert(0, value);
    }

    void merge(DynamicArray& other){
        for(int i = 0; i < other.size; ++i) {
            append(other.arr[i]);
        }
    }

    void interleave(DynamicArray& other) {
        int newSize = size + other.size;
        int* newArr = new int[newSize];
        int i = 0, j = 0, k = 0;
        while (i < size && j < other.size){
            newArr[k++] = arr[i++];
            newArr[k++] = other.arr[j++];
        }
        while (i < size){
            newArr[k++] = arr[i++];
        }
        while (j < other.size){
            newArr[k++] = other.arr[j++];
        }
        delete[] arr;
        arr = newArr;
        size = newSize;
        capacity = newSize;
    }

    int getMiddle() const{
        if (size == 0) return -1;
        return arr[size / 2];
    }

    int indexOf(int value) const{
        for(int i = 0; i < size; ++i) {
            if(arr[i] == value) return i;
        }
        return -1;
    }

    DynamicArray split(int index){
        DynamicArray newArr;
        if(index < 0 || index >= size) return newArr;
        for(int i = index; i < size; ++i){
            newArr.append(arr[i]);
        }
        size = index;
        if(size > 0 && size == capacity / 4) resize(capacity / 2);
        return newArr;
    }

    void print() const{
        for(int i = 0; i < size; ++i){
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {

    // Inserts an element at the specified index. Function name -> insert
    // Deletes the element at the specified index. Fnction name -> remove
    // Returns the size of the dynamic array. Function name -> getSize
    // Returns true if the dynamic array is empty, false otherwise. Function name -> isEmpty
    // Rotates the dynamic array by k positions to the right. Function name -> rotate  
    // Reverses the dynamic array. Function -> reverse 
    // Appends an element to the end of the dynamic array. Function name -> append
    // Prepends an element to the beginning of the dynamic array. Function name -> prepend
    // Merges two dynamic arrays into a single dynamic array. Function name -> merge
    // Interleaves two dynamic arrays into a single dynamic array. Function name -> interleave
    // Returns the middle element of the dynamic array. Function name -> getMiddle
    // Returns the index of the first occurrence of the specified element in the dynamic array, or -1 if the element is not found. Function name -> indexOf
    // Splits the dynamic array into two dynamic arrays at the specified index. Function name -> split

    DynamicArray arr1;
    arr1.append(1);
    arr1.append(2);
    arr1.append(3);
    arr1.prepend(0);
    arr1.insert(2, 5);
    arr1.print(); // 0 1 5 2 3
    arr1.remove(2);
    arr1.print(); // 0 1 2 3
    arr1.reverse();
    arr1.print(); // 3 2 1 0
    arr1.rotate(2);
    arr1.print(); // 1 0 3 2
    cout << arr1.getSize() << "\n"; // 4
    cout << arr1.isEmpty() << "\n"; // 0
    cout << arr1.getMiddle() << "\n"; // 3
    cout << arr1.indexOf(3) << "\n"; // 2

    DynamicArray arr2;
    arr2.append(4);
    arr2.append(5);
    arr1.merge(arr2);
    arr1.print(); // 1 0 3 2 4 5

    DynamicArray arr3;
    arr3.append(6);
    arr3.append(7);
    arr1.interleave(arr3);
    arr1.print(); // 1 6 0 7 3 2 4 5

    DynamicArray arr4 = arr1.split(4);
    arr1.print(); // 1 6 0 7
    arr4.print(); // 3 2 4 5

}