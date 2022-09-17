#include <fstream>
#include <iostream>
using namespace std;

/*

   /$$$$$$    /$$ /$$   /$$  /$$$$$$
  /$$__  $$ /$$$$| $$  | $$ /$$__  $$
 |__/  \ $$|_  $$| $$  | $$|__/  \ $$
   /$$$$$$/  | $$| $$$$$$$$   /$$$$$/
  /$$____/   | $$|_____  $$  |___  $$
 | $$        | $$      | $$ /$$  \ $$
 | $$$$$$$$ /$$$$$$    | $$|  $$$$$$/
 |________/|______/    |__/ \______/



  /$$$$$$$   /$$$$$$    /$$
 | $$__  $$ /$$$_  $$ /$$$$
 | $$  \ $$| $$$$\ $$|_  $$
 | $$$$$$$/| $$ $$ $$  | $$
 | $$____/ | $$\ $$$$  | $$
 | $$      | $$ \ $$$  | $$
 | $$      |  $$$$$$/ /$$$$$$
 |__/       \______/ |______/



  /$$   /$$  /$$$$$$   /$$$$$$   /$$$$$$        /$$$$$$$$ /$$$$$$$   /$$$$$$  /$$   /$$
 | $$$ | $$ /$$__  $$ /$$__  $$ /$$__  $$      |__  $$__/| $$__  $$ /$$__  $$| $$$ | $$
 | $$$$| $$| $$  \__/| $$  \ $$| $$  \__/         | $$   | $$  \ $$| $$  \ $$| $$$$| $$
 | $$ $$ $$| $$ /$$$$| $$  | $$| $$               | $$   | $$$$$$$/| $$$$$$$$| $$ $$ $$
 | $$  $$$$| $$|_  $$| $$  | $$| $$               | $$   | $$__  $$| $$__  $$| $$  $$$$
 | $$\  $$$| $$  \ $$| $$  | $$| $$    $$         | $$   | $$  \ $$| $$  | $$| $$\  $$$
 | $$ \  $$|  $$$$$$/|  $$$$$$/|  $$$$$$/         | $$   | $$  | $$| $$  | $$| $$ \  $$
 |__/  \__/ \______/  \______/  \______/          |__/   |__/  |__/|__/  |__/|__/  \__/

*/


// A support struct for Linked List
struct Node {
    // Each node has a value
    int val;
    // and a pointer to the next node
    Node *next;

    // Init an empty node
    Node() {
        val = 0;
        next = NULL;
    }

    // Init a node with a value
    Node(int val) {
        this->val = val;
        next = NULL;
    }
};

/*

@method:
    -> Constructor
    List();
    List(int *array, int size);
    List(const string &filename);
    List(const List &list);

    -> Methods
    Node *getHead() const;
    int getLength() const;
    void pushFront(int val);
    void pushFront(const List &list);
    void pushRear(int val);
    void pushRear(const List &list);
    void pushAt(int loc, int val);
    void inOrderPush(int val);

    int popFront();
    int popRear();
    int popAt(int loc);
    int find(int val);
    int popByValue(int val);

    -> Overload operators
    friend ostream &operator<<(ostream &write, const List &list);

    -> Destructor
    ~List();
*/

// A support class for Vector
class List {
   private:
    // The head node of the list
    Node *head;
    // The tail node of the list
    Node *tail;
    // The number of nodes in the list
    int length;

   public:
    // Default constructor, init an empty list
    List();
    // A constructor to init a list with a given array
    List(int *array, int size);
    // A constructor to read from a file and init a list
    List(const string &filename);
    // Copy constructor, copy the values of another list
    List(const List &list);

    // Get the head node of the list
    Node *getHead() const;
    // Get the length of the list
    int getLength() const;
    // Push a value to the head of the list
    void pushFront(int val);
    // Concatenate another list to the head of current list
    void pushFront(const List &list);
    // Push a value to the tail of the list
    void pushRear(int val);
    // Concatenate another list to the tail of current list
    void pushRear(const List &list);
    // Push a value to a specific location
    void pushAt(int loc, int val);
    // Push a value to a proper location to keep the list sorted
    void inOrderPush(int val);

    // Remove a value from the head of the list
    int popFront();
    // Remove a value from the tail of the list
    int popRear();
    // Remove a value from a specific location
    int popAt(int loc);
    // Search for a value in the list and return its location, otherwise return -1
    int find(int val) const;
    // Remove a value from the list if it exists
    int popByValue(int val);

    // Print the list
    friend ostream &operator<<(ostream &write, const List &list);

    // Free the allocated memory
    ~List();
};

/*
Constructor
*/

List::List() {
    head = NULL;
    tail = NULL;
    length = 0;
}

List::List(int *array, int size) {
    head = NULL;
    tail = NULL;
    length = 0;

    for (int i = 0; i < size; i++) {
        // Push the value to the tail of the list
        pushRear(array[i]);
    }
}

List::List(const string &filename) {
    head = NULL;
    tail = NULL;
    length = 0;

    // Open a file to read
    ifstream read(filename);
    int val;

    // Read the file until the end
    while (read >> val) {
        // Push the value to the tail of the list
        pushRear(val);
    }

    // Close the file
    read.close();
}

List::List(const List &list) {
    head = NULL;
    tail = NULL;
    length = 0;

    // Copy the head node of the list in order not to lose track of the head node
    Node *temp = list.head;

    // While its not the end of the list
    while (temp != NULL) {
        // Push the value to the tail of the list
        pushRear(temp->val);
        // Move to the next node
        temp = temp->next;
    }
}

/*
Method
*/

Node *List::getHead() const {
    return head;
}

int List::getLength() const {
    return length;
}

void List::pushFront(int val) {
    // Create a new node
    Node *temp = new Node(val);

    // If the list is empty
    if (head == NULL) {
        // Set the head and tail to the new node
        head = temp;
        tail = temp;
    }
    // If the list is not empty
    else {
        // Set the new node's next to the head
        temp->next = head;
        // Set the head to the new node
        head = temp;
    }

    // Increase the length of the list
    length++;
}

void List::pushFront(const List &list) {
    Node *temp = list.head;

    while (temp != NULL) {
        pushFront(temp->val);
        temp = temp->next;
    }
}

void List::pushRear(int val) {
    Node *temp = new Node(val);

    if (head == NULL) {
        head = temp;
        tail = temp;
    }
    // If the list is not empty
    else {
        // Set the tail's next to the new node
        tail->next = temp;
        // Set the tail to the new node
        tail = temp;
    }

    length++;
}

void List::pushRear(const List &list) {
    Node *temp = list.head;

    while (temp != NULL) {
        pushRear(temp->val);
        temp = temp->next;
    }
}

void List::pushAt(int loc, int val) {
    // If the location is invalid
    if (loc < 0 || loc > length) {
        return;
    }

    // If the location is the head
    if (loc == 0) {
        pushFront(val);
        return;
    }

    // If the location is the tail
    if (loc == length) {
        pushRear(val);
        return;
    }

    // If the location is in the middle

    // Create a new node
    Node *temp = new Node(val);
    // Copy the head node
    Node *curr = head;

    // Move to the node before the location
    for (int i = 0; i < loc - 1; i++) {
        curr = curr->next;
    }

    // Set the new node's next to the current node's next
    temp->next = curr->next;
    // Set the current node's next to the new node
    curr->next = temp;

    length++;
}

void List::inOrderPush(int val) {
    // If the list is empty
    if (head == NULL) {
        pushFront(val);
        return;
    }

    // If the list is not empty

    // Create a new node
    Node *temp = new Node(val);
    // Current node is to check if we had move to the right location
    Node *curr = head;
    // Previous node is to support inserting the new node
    Node *prev = NULL;

    // Find the location to insert the new node
    // Keep looping until the end of the list or the current node's value is larger than the new node's value
    while (curr != NULL && curr->val < val) {
        prev = curr;
        curr = curr->next;
    }

    // Add to head
    if (prev == NULL) {
        temp->next = head;
        head = temp;
    }
    // Add to middle
    else {
        temp->next = curr;
        prev->next = temp;
    }

    // Add to tail
    if (curr == NULL) {
        tail = temp;
    }

    length++;
}

int List::popFront() {
    // If the list is empty, we cannot pop
    if (head == NULL) {
        return -1;
    }

    // Keep track of the old head before deleting it
    Node *temp = head;
    // Get the value before deleting the node
    int val = temp->val;

    // Move head to the next node
    head = head->next;
    // Free the memory of previous head
    delete temp;

    length--;

    return val;
}

int List::popRear() {
    // If the list is empty, we cannot pop
    if (head == NULL) {
        return -1;
    }

    Node *curr = head;
    Node *prev = NULL;

    // Move to the last node
    while (curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }

    // Get the value before deleting the node
    int val = curr->val;

    // If the list has only one node
    if (prev == NULL) {
        head = NULL;
        tail = NULL;
    }
    // Delete tail
    else {
        prev->next = NULL;
        tail = prev;
    }

    // Free the memory of previous tail
    delete curr;

    length--;

    return val;
}

int List::popAt(int loc) {
    // If the location is invalid
    if (loc < 0 || loc >= length) {
        return -1;
    }

    // If the location is the head
    if (loc == 0) {
        return popFront();
    }

    // If the location is the tail
    if (loc == length - 1) {
        return popRear();
    }

    // If the location is in the middle
    Node *curr = head;
    Node *prev = NULL;

    for (int i = 0; i < loc; i++) {
        prev = curr;
        curr = curr->next;
    }

    int val = curr->val;

    prev->next = curr->next;
    delete curr;

    length--;

    return val;
}

int List::find(int val) const {
    Node *curr = head;

    // Loop through the list
    for (int i = 0; i < length; i++) {
        // If the value is found, return it and end the function
        if (curr->val == val) {
            return i;
        }

        curr = curr->next;
    }

    // If the value is not found, return -1
    return -1;
}

int List::popByValue(int val) {
    // Find the location of the value
    int loc = find(val);

    return popAt(loc);
}

/*
Overload Operator
*/

ostream &operator<<(ostream &write, const List &list) {
    Node *curr = list.head;
    write << "[";
    // Loop through the list and print each node
    while (curr->next != NULL) {
        write << curr->val << ", ";
        curr = curr->next;
    }

    // Print the last node
    write << curr->val << "]";

    // Return the ostream object
    return write;
}

/*
 Destructor
*/

List::~List() {
    // We should be very careful when using destructors
    // because they are called automatically
    // and we don't want to delete the same memory twice
    // or delete memory while assigning a list to another
    // Therefore, we should do nothing here,
    // Let the vector destructor do the work
}

/*
Vector class
@method:
    -> Constructor
    Vector();
    Vector(int *array, int size);
    Vector(const string &filename);
    Vector(const Vector &vector);

    -> Methods
    int size() const;
    void pushFront(int val);
    void pushFront(const Vector &vector);
    void pushRear(int val);
    void pushRear(const Vector &vector);
    void pushAt(int loc, int val);
    void inOrderPush(int val);

    int popFront();
    int popRear();
    int popAt(int loc);
    int find(int val);
    int popByValue(int val);

    -> Overload operators
    friend ostream &operator<<(ostream &write, const Vector &vector);

    -> Destructor
    ~Vector();

*/

// Linked List based Vector class
class Vector {
   private:
    // A Linked List to store the values of vector
    List list;

   public:
    // Default constructor, init an empty vector
    Vector();
    // A constructor to init a vector with a given array
    Vector(int *array, int size);
    // A constructor to read from a file and init a vector
    Vector(const string &filename);
    // Copy constructor, copy the values of another vector
    Vector(const Vector &vector);

    // Get the length of the vector
    int size() const;
    // Push a value to the head of the vector
    void pushFront(int val);
    // Concatenate another vector to the head of current vector
    void pushFront(const Vector &vector);
    // Push a value to the tail of the vector
    void pushRear(int val);
    // Concatenate another vector to the tail of current vector
    void pushRear(const Vector &vector);
    // Push a value to a specific location
    void pushAt(int loc, int val);
    // Push a value to a proper location to keep the vector sorted
    void inOrderPush(int val);

    // Remove a value from the head of the vector
    int popFront();
    // Remove a value from the tail of the vector
    int popRear();
    // Remove a value from a specific location
    int popAt(int loc);
    // Search for a value in the vector and return its location, otherwise return -1
    int find(int val);
    // Remove a value from the vector ìf it exists
    int popByValue(int val);

    // Print the vector
    friend ostream &operator<<(ostream &write, const Vector &vector);

    // Free the allocated memory
    ~Vector();
};

/*
Constructor
*/

Vector::Vector() {
    // Nothing to do here
}

Vector::Vector(int *array, int size) {
    // Use the List constructor to init the vector's list
    this->list = List(array, size);
}

Vector::Vector(const string &filename) {
    // Use the List constructor to init the vector's list
    this->list = List(filename);
}

Vector::Vector(const Vector &vector) {
    // Use the List constructor to init the vector's list
    this->list = List(vector.list);
}

/*

  /$$      /$$ /$$$$$$$$ /$$$$$$$$ /$$   /$$  /$$$$$$  /$$$$$$$
 | $$$    /$$$| $$_____/|__  $$__/| $$  | $$ /$$__  $$| $$__  $$
 | $$$$  /$$$$| $$         | $$   | $$  | $$| $$  \ $$| $$  \ $$
 | $$ $$/$$ $$| $$$$$      | $$   | $$$$$$$$| $$  | $$| $$  | $$
 | $$  $$$| $$| $$__/      | $$   | $$__  $$| $$  | $$| $$  | $$
 | $$\  $ | $$| $$         | $$   | $$  | $$| $$  | $$| $$  | $$
 | $$ \/  | $$| $$$$$$$$   | $$   | $$  | $$|  $$$$$$/| $$$$$$$/
 |__/     |__/|________/   |__/   |__/  |__/ \______/ |_______/

*/

int Vector::size() const {
    // Use the List's getLength method
    return this->list.getLength();
}

void Vector::pushFront(int val) {
    // Use the List's pushFront method
    this->list.pushFront(val);
}

void Vector::pushFront(const Vector &vector) {
    // Use the List's pushFront method
    this->list.pushFront(vector.list);
}

void Vector::pushRear(int val) {
    // Use the List's pushRear method
    this->list.pushRear(val);
}

void Vector::pushRear(const Vector &vector) {
    // Use the List's pushRear method
    this->list.pushRear(vector.list);
}

void Vector::pushAt(int loc, int val) {
    // Use the List's pushAt method
    this->list.pushAt(loc, val);
}

void Vector::inOrderPush(int val) {
    // Use the List's inOrderPush method
    this->list.inOrderPush(val);
}

int Vector::popFront() {
    // Use the List's popFront method
    return this->list.popFront();
}

int Vector::popRear() {
    // Use the List's popRear method
    return this->list.popRear();
}

int Vector::popAt(int loc) {
    // Use the List's popAt method
    return this->list.popAt(loc);
}

int Vector::find(int val) {
    // Use the List's find method
    return this->list.find(val);
}

int Vector::popByValue(int val) {
    // Use the List's popByValue method
    return this->list.popByValue(val);
}

/*
Overloading Operator
*/

ostream &operator<<(ostream &write, const Vector &vector) {
    // Use the List's operator<< method
    write << vector.list;
    return write;
}

/*
Destructor
*/

Vector::~Vector() {
    // Use the List's destructor
    Node *curr = list.getHead();

    // Loop through the list and delete each node
    while (curr != NULL) {
        // Store the old node
        Node *temp = curr;
        // Move to the next node
        curr = curr->next;
        // Delete the old node
        delete temp;
    }
}

// A function to test the Vector class
void test(ostream &write) {
    int x = 0;

    Vector v1;
    v1.pushFront(18);
    v1.pushFront(20);
    v1.pushFront(25);
    v1.pushRear(18);
    v1.pushRear(20);
    v1.pushRear(25);
    write << v1 << "\n";
    // [25, 20, 18, 18, 20, 25]

    int A[5] = {11, 25, 33, 47, 51};
    Vector v2(A, 5);
    write << v2 << "\n";
    // [11, 25, 33, 47, 51]

    v2.pushFront(9);
    // v2.inOrderPush(27);
    v2.pushRear(63);
    write << v2 << "\n";
    // [9, 11, 25, 33, 47, 51, 63]

    v1.pushRear(v2);
    write << v1 << "\n";
    // [25, 20, 18, 18, 20, 25, 9, 11, 25, 33, 47, 51, 63]

    x = v1.popFront();
    x = v1.popFront();
    x = v1.popFront();
    write << v1 << "\n";
    // [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
    write << x << endl;
    // 18

    x = v1.popRear();
    x = v1.popRear();
    x = v1.popRear();
    write << v1 << "\n";
    // [18, 20, 25, 9, 11, 25, 27, 33]
    write << x << endl;
    // 47

    x = v2.popAt(3);
    write << v2 << "\n";
    // [9, 11, 25, 33, 47, 51, 63]
    write << x << endl;
    // 27

    x = v2.find(51);
    write << x << endl;
    // 5

    x = v2.find(99);
    write << x << endl;
    // -1

    Vector v3(v1);
    write << v3 << "\n";
    // [18, 20, 25, 9, 11, 25, 27, 33]

    v3.pushFront(v2);
    write << v3 << "\n";
    //[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

    Vector v4("input.dat");
    v4.pushRear(v3);
    write << v4 << "\n";
}
int main() {
    test(cout);
    ofstream write("test.out");
    test(write);
    write.close();
    return 0;
}