#include "Vector.h"
#include <iostream>
#include <algorithm>

using namespace std;
using std::cout;

//suppose n = size

void Vector::expand_capacity() { // O(n)
    // Double the actual array size
    capacity *= 2;
    int* arr2 = new int[capacity];
    //copy(arr,arr + size , arr2);
    for (int i = 0; i < size; ++i)
        arr2[i] = arr[i]; // copy data

    std::swap(arr, arr2);
    delete[] arr2;
}

// Default constructor
Vector::Vector() = default; // O(1)

// Parameterized constructor
Vector::Vector(int size, int x) : size(size), capacity(size + 10) // O(n)
{
    if (size < 0)
        this->size = 1;
    arr = new int[capacity] {};
    for (int i = 0; i < this->size; ++i)
        arr[i] = x;
}

// Destructor
Vector::~Vector() // O(n)
{
    delete[] arr;
    arr = nullptr;
}

// Copy constructor
Vector::Vector(const Vector& other) : size(other.size), capacity(other.capacity) // O(n)
{
    arr = new int[capacity];
    copy(other.arr, other.arr + size, arr);
}

// Copy assignment operator
Vector& Vector::operator=(Vector other){ // O(1)
    swap(other);
    return *this;
}

// Accessor methods
int Vector::getSize() const // O(1)
{
    return size;
}

int Vector::getCapacity() const // O(1)
{
    return capacity;
}

int Vector::get(int index) const // O(1)
{
    if (index < 0 || index >= size) // out of bounds
        throw out_of_range("Index out of range");
    return arr[index];
}

int Vector::front() const // O(1)
{
    if (size == 0)
        throw out_of_range("Vector is empty");
    return arr[0];
}

int Vector::back() const // O(1)
{
    if (size == 0)
        throw out_of_range("Vector is empty");
    return arr[size - 1];
}

// Modification methods
void Vector::PushBack(int val) { // O(1)
    if (size == capacity)
        expand_capacity();
    arr[size++] = val;
}

void Vector::PushFront(int val) // O(n)
{
    if (size == capacity)
        expand_capacity();
    for (int i = size; i > 0; --i)
        arr[i] = arr[i - 1];
    arr[0] = val;
    ++size;
}

void Vector::PopBack() // O(1)
{
    if (size > 0)
        --size;
}

void Vector::insert(int index, int val) { // O(n)
    if (index < 0 || index > size) // out of bounds
        throw out_of_range("Index out of range");

    if (size == capacity)
        expand_capacity();

    for (int i = size; i > index; --i)
        arr[i] = arr[i - 1];
    arr[index] = val;
    ++size;
}

void Vector::remove(int index) // O(n)
{
    if (index < 0 || index >= size) // out of bounds
        throw out_of_range("Index out of range");

    cout << "Deleted Element : " << arr[index] << '\n';
    for (int i = index; i < size - 1; ++i)
        arr[i] = arr[i + 1];
    --size;
}

void Vector::set(int index, int val) // O(1)
{
    if (index < 0 || index >= size) // out of bounds
        throw out_of_range("Index out of range");

    arr[index] = val;
}

void Vector::clear() // O(1)
{
    size = 0;
    capacity = 1;
    delete []arr;
    arr = nullptr;
}

void Vector::Resize(int newSize) // O(n)
{
    size = newSize;
    capacity = size + 5;
    int* newArr = new int[capacity];
    copy(arr, arr + size, newArr);
    delete[] arr;
    arr = newArr;
}

// Swap member function
void Vector::swap(Vector& other) { // O(1)
    std::swap(arr, other.arr);
    std::swap(size, other.size);
    std::swap(capacity, other.capacity);
}

// Static swap function
void Vector::Swap(Vector& a, Vector& b) // O(1)
{
    a.swap(b);
}

// Utility methods
bool Vector::isEmpty() const // O(1)
{
    return size == 0;
}

int Vector::find(int val) const { // O(n)
    for (int i = 0; i < size; ++i) {
        if (arr[i] == val)
            return i;
    }
    return -1; // not found
}

void Vector::print() const { // O(n)
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << '\n';
}

//The function shifts every element 1 step towards the right.
void Vector::right_rotation() { // O(n)
    if(size <= 1)
        return;

    int temp = arr[size - 1];
    for(int i = size - 1 ; i > 0 ; --i)
        arr[i] = arr[i - 1];
    arr[0] = temp;
}
//The function shifts every element many steps towards the right.
void Vector::right_rotation(int times) { // O(n)
    int rotated_times = times % size;

    //we can call the implemented function ,but I had to implement this function to practise
    //while(rotated_times--)
    //right_rotation();

    if(rotated_times == 0)
        return;
    int *newArr = new int [size];
    for (int i = 0; i < rotated_times; ++i)
        newArr[i] = arr[size - rotated_times + i];

    for (int i = rotated_times; i < size; ++i)
        newArr[i] = arr[i - rotated_times];

    delete []arr;
    arr = newArr;
}

//The function rotates the whole array 1 step to the left
void Vector::left_rotation() { // O(n)
    if(size <= 1)
        return;

    int temp = arr[0];
    for(int i = 0 ; i < size - 1 ; ++i)
        arr[i] = arr[i + 1];
    arr[size - 1] = temp;
}

// improved search
//each time you find the value, you shift it one step to the left
int Vector::find_transposition(int val) { // O(n)
    if(size <= 1)
        return 0;
    int pos = find(val);
    if(pos == 0) // special case
        return 0;
    else if(pos > 0)
    {
        int temp = arr[pos];
        arr[pos] = arr[pos - 1];
        arr[pos - 1] = temp;
        return pos - 1;
    }
    return -1; // not found
}
