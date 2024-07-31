//
// Created by Mahmoud Elshafei on 7/7/2024.
//

#include "Single_List.h"

// Check My List after delete || insert
void Single_List::black_box_debugging() const {
    if (length == 0) {
        if (head != nullptr || tail != nullptr)
            throw out_of_range("Length is zero, but head and/or tail are not null.\n");
    } else {
        if (head == nullptr)
            throw out_of_range("Length is greater than zero, but head is null.\n");
        if (tail == nullptr)
            throw out_of_range("Length is greater than zero, but tail is null.\n");
        if (tail->next != nullptr)
            throw out_of_range("Tail's next pointer should be null.\n");
    }
}

Single_List::~Single_List() { // O(n) time - O(1) memory
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    length = 0;
}


// traversal functions
void Single_List::print() const { // O(n) time - O(1) memory
    for (Node *cur = head; cur; cur = cur->next)
        cout << cur->data << " ";
    cout << '\n';
}

int Single_List::min_element() const { // o(n) time - O(1) memory
    int num = INT_MAX;
    for (Node *cur = head; cur; cur = cur->next) {
        if (cur->data < num)
            num = cur->data;
    }
    return num;
}

int Single_List::max_element() const { // o(n) time - O(1) memory
    int num = INT_MIN;
    for (Node *cur = head; cur; cur = cur->next) {
        if (cur->data > num)
            num = cur->data;
    }
    return num;
}

int Single_List::max_rec(Node* cur , bool first_call) const { // O(n) time - O(n) memory
    if(!length)
        throw out_of_range("The List is Empty");
    if(length == 1)
        return head->data;
    if(first_call)
        return max_rec(cur = this->head , false);
    // base case
    if(!cur)
        return INT_MIN;
    return max(cur->data , max_rec(cur->next , false));
}


//search for an element
Node *Single_List::find(int val) const { // O(n) time - O(1) memory
    for (Node *cur = head; cur; cur = cur->next) {
        if (cur->data == val)
            return cur;
    }
    return nullptr;
}

int Single_List::search(int val) const { // O(n) time - O(1) memory
    int idx = 0;
    for (Node *cur = head; cur; idx++, cur = cur->next) {
        if (cur->data == val)
            return idx;
    }
    return -1;
}

int Single_List::nodes_sum() const { // O(n) time - O(1) memory
    if (length == 0)
        return 0;

    int sum = 0;
    for (Node *cur = head; cur; cur = cur->next)
        sum += cur->data;

    return sum;
}

bool Single_List::is_sorted() const { // O(n) time - O(1) memory
    if(length <= 1)
        return true;
    int pre = head->data;
    for (Node *cur = head; cur; pre = cur->data, cur = cur->next) {
        if (cur->data < pre)
            return false;
    }
    return true;
}

int Single_List::improved_search(int val) const { // O(n) time - O(1) memory
    if (length == 0)
        throw out_of_range("The List is Empty.");
    Node *pre = nullptr; // keep pointer for previous Node
    int idx = 0;
    for (Node *cur = head; cur; ++idx, pre = cur, cur = cur->next) {
        if (cur->data == val) {
            if (!pre)
                return idx;
            else {
                swap(cur->data, pre->data);
                return idx - 1;
            }
        }
    }
    return -1;
}

Node *Single_List::get_nth(int n) const { // O(n) time - O(1) memory
    int pos = -1;
    for (Node *cur = head; cur; cur = cur->next) {
        //++pos then pos == n ?
        if (++pos == n)
            return cur;
    }
    return nullptr; // NOT FOUND !!
}

Node *Single_List::get_nth_back(int n) const { // O(n) time - O(1) memory
    int index = length - n; // calculate the 0-based index from front
    return get_nth(index);
}

bool Single_List::is_same(const Single_List &other) { // O(n) time - O(1) memory
    if (length != other.length)
        return false;
    Node *cur = head;
    Node *cur2 = other.head;
    while (cur && cur2) {
        if (cur->data != cur2->data)
            return false;
        cur = cur->next;
        cur2 = cur2->next;
    }
    return true;
}

// add - remove functions
void Single_List::insert_end(int val) { // O(1) time - O(1) memory
    Node *cur = new Node(val);
    if (length == 0) {
        head = tail = cur;
    } else {
        tail->next = cur;
        tail = cur;
    }
    length++;
    black_box_debugging();
}

void Single_List::insert_front(int val) { // O(1) time - O(1) memory
    Node *cur = new Node(val);
    if (length == 0) {
        head = tail = cur;
    } else {
        cur->next = head;
        head = cur;
    }
    length++;
    black_box_debugging();
}

void Single_List::remove_last() { // O(1) time - O(1) memory
    if (length == 0) // if we don't have any elements
        throw out_of_range("The List is Empty");

    if (head->next == nullptr) // if we have one element
    {
        delete head;
        head = tail = nullptr;
        length = 0;
    } else {
        Node *cur = head;
        while (cur->next && cur->next != tail)
            cur = cur->next;
        delete tail;
        tail = cur;
        tail->next = nullptr;
        length--;
    }
    black_box_debugging();
}

void Single_List::remove_front() { // O(1) time - O(1) memory
    if (length == 0) // if we don't have any elements
        throw out_of_range("The List is Empty");

    Node *cur = head;
    head = head->next;
    if (head == nullptr)
        tail = nullptr;

    length--;
    delete cur;
    black_box_debugging();
}

void Single_List::remove_node_with_index(int idx) { // O(n) time - O(1) memory
    if (length == 0) // if we don't have any elements
        throw out_of_range("The List is Empty");
    Node *prev = nullptr;
    int cnt = -1;
    for (Node *cur = head; cur; prev = cur, cur = cur->next) {
        if (++cnt == idx) {
            if (!prev)
                remove_front();
            else if (cur->next == nullptr)
                remove_last();
            else {
                Node *next_element = cur->next;
                delete cur;
                prev->next = next_element;
                length--;
            }
            black_box_debugging();
            return;
        }
    }
    cout << "This Index Doesn't Exist !!.\n";
}

void Single_List::remove_node_with_key(int val) { // O(n) time - O(1) memory
    int idx = search(val);
    remove_node_with_index(idx);
}

void Single_List::swap_pairs() { // O(n/2) time - O(1) memory
    int num_of_swaps = length / 2;
    Node *cur = head;
    while (num_of_swaps--) {
        swap(cur->data, cur->next->data);
        cur = cur->next->next;
    }
}

void Single_List::reverse() { // O(n) time - O(1) memory
    if (length <= 1)
        return;

    tail = head;
    Node *prev = head;
    head = head->next;
    while (head) {
        Node *next = head->next;
        head->next = prev;

        prev = head;
        head = next;
    }
    head = prev;
    tail->next = nullptr;
    black_box_debugging();
}

void Single_List::delete_even_position() { // O(n) time - O(1) memory
    if (length == 0)
        return;
    int i = 0;
    Node *prev = nullptr;
    for (Node *cur = head; cur; i++) {
        if(i & 1)
        {
            Node* deleted = cur;
            if (prev != nullptr)
                prev->next = cur->next;
            else
                head = cur->next;
            if (cur->next == nullptr)
                tail = prev;
            cur = cur->next;
            delete deleted;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    length = (length + 1) / 2;
}

void Single_List::insert_sorted(int val) { // O(n) time - O(1) memory
    Node* new_val = new Node(val);
    if (length == 0 || head->data >= val) {
        insert_front(val);
        return;
    }
    Node* prev = nullptr;
    Node* cur = head;
    while (cur != nullptr && cur->data < val) {
        prev = cur;
        cur = cur->next;
    }
    new_val->next = cur;
    if (prev != nullptr)
        prev->next = new_val;

    if (cur == nullptr)
        tail = new_val;
    length++;
}

void Single_List::swap_head_tail() { // O(n) time - O(1) memory
     if(length <= 1)
         return;

     if(length == 2)
     {
         swap(head,tail);
         head->next = tail;
         tail->next = nullptr;
         return;
     }

     Node* head_next = head->next;
     Node* prev = head;
     for(Node* cur = head_next ; cur != tail; prev = cur , cur = cur->next)
     {

     }
     prev->next = head;
     tail->next = head_next;
     Node* temp = head;
     head = tail;
     tail = temp;
     tail-> next = nullptr;
     black_box_debugging();
}

void Single_List::left_rotate(int k) { // O(n) time - O(1) memory
    k %= length;
    if(length <= 1 || (length == 2 && k % 2 == 0))
        return;
    if(length == 2 && k & 1)
    {
        swap(head,tail);
        head->next = tail;
        tail->next = nullptr;
        return;
    }
    Node* old_head = head;
    int r = k;
    while(r--)
        head = head->next;

    tail->next = old_head;
    r = k;
    while(r--)
        tail = tail->next;

    tail->next = nullptr;
    black_box_debugging();
}

void Single_List::remove_duplicates() { // O(n) time - O(1) memory
    if(length <= 1)
        return;

    unordered_map<int,int> freq;
    Node* prev = nullptr;
    Node* cur = head;
    while(cur)
    {
        if(freq.find(cur->data) != freq.end())
        {
            Node* deleted = cur;
            cur = cur->next;
            if(prev)
               prev->next = cur;
            else
                head = cur;
            delete deleted;
            length--;
        }
        else
        {
            freq[cur->data]++;
            prev = cur;
            cur = cur->next;
        }
    }
    tail = prev;
    if(tail)
        tail->next = nullptr;
    black_box_debugging();
}


void Single_List::remove_last_occurrence(int key) { // O(n) time - O(1) memory
    if(length == 0)
        return;
     reverse();
     Node* prev = nullptr;
    Node* cur = head;
     while(cur)
     {
         if(cur->data == key)
         {
             if(cur->next == nullptr) // if tail is the key
             {
                 tail = prev;
                 delete cur;
                 tail->next = nullptr;
             }
             else if(!prev) // if head is the key
             {
                 Node* deleted = head;
                 head = head->next;
                 delete deleted;
             }
             else
             {
                 Node* deleted = cur;
                 cur = cur->next;
                 prev->next = cur;
                 delete deleted;
             }
             length--;
             break;
         }
         prev = cur;
         cur = cur->next;
     }
    black_box_debugging();
     reverse();
    black_box_debugging();

}

void Single_List::move_occurrence_to_last(int key) { // O(n) time - O(1) memory
    if(!length)
        return;

    int len = length; // to avoid infinite loop while using cur Node
    Node* cur = head;
    Node* prev = nullptr;
    while(len--)
    {
        if(cur->data == key)
        {
            insert_end(key);
            Node* deleted = cur;
            if(!prev)
            {
                head = head->next;
                cur = head;
            }
            else
            {
                cur = cur->next;
                prev->next = cur;
            }
            delete deleted;
        }
        else {
            prev = cur;
            cur = cur->next;
        }
    }
    black_box_debugging();
}


// utility functions
int Single_List::size() const {// O(1) time - O(1) memory
    return length;
}

void Single_List::print_address() {
     cout << "Head Address : " << head << "\n";
     cout << "tail Address : " << tail << "\n";
}













































