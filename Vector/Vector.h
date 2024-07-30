#ifndef VECTOR_H
#define VECTOR_H

class Vector {
private:
    int* arr{};
    int size{};
    int capacity{};
    void expand_capacity();
public:
    Vector();
    Vector(int size, int x = 0);
    ~Vector();
    Vector(const Vector& other);
    Vector& operator=(Vector other);
    int getSize() const;
    int getCapacity() const;
    int get(int index) const;
    int front() const;
    int back() const;
    void PushBack(int val);
    void PushFront(int val);
    void PopBack();
    void insert(int index, int val);
    void remove(int index);
    void set(int index, int val);
    void clear();
    void Resize(int);
    void swap(Vector& other);
    static void Swap(Vector& a, Vector& b);
    bool isEmpty() const;
    int find(int) const;
    void print() const;
    void right_rotation();
    void right_rotation(int);
    void left_rotation();
    int find_transposition(int);
};

void swap(Vector& a, Vector& b);

#endif // VECTOR_H
