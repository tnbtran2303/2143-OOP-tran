#include <fstream>
#include <iostream>
using namespace std;

/*
 $$$$$$\    $$\ $$\   $$\  $$$$$$\                                                    
$$  __$$\ $$$$ |$$ |  $$ |$$ ___$$\                                                   
\__/  $$ |\_$$ |$$ |  $$ |\_/   $$ |                                                  
 $$$$$$  |  $$ |$$$$$$$$ |  $$$$$ /                                                   
$$  ____/   $$ |\_____$$ |  \___$$\                                                   
$$ |        $$ |      $$ |$$\   $$ |                                                  
$$$$$$$$\ $$$$$$\     $$ |\$$$$$$  |                                                  
\________|\______|    \__| \______/                                                   
                                                                                      
                                                                                      
                                                                                      
$$$$$$$\   $$$$$$\   $$$$$$\                                                          
$$  __$$\ $$$ __$$\ $$  __$$\                                                         
$$ |  $$ |$$$$\ $$ |\__/  $$ |                                                        
$$$$$$$  |$$\$$\$$ | $$$$$$  |                                                        
$$  ____/ $$ \$$$$ |$$  ____/                                                         
$$ |      $$ |\$$$ |$$ |                                                              
$$ |      \$$$$$$  /$$$$$$$$\                                                         
\__|       \______/ \________|                                                        
                                                                                      
                                                                                      
                                                                                      
$$\   $$\  $$$$$$\   $$$$$$\   $$$$$$\        $$$$$$$$\ $$$$$$$\   $$$$$$\  $$\   $$\ 
$$$\  $$ |$$  __$$\ $$  __$$\ $$  __$$\       \__$$  __|$$  __$$\ $$  __$$\ $$$\  $$ |
$$$$\ $$ |$$ /  \__|$$ /  $$ |$$ /  \__|         $$ |   $$ |  $$ |$$ /  $$ |$$$$\ $$ |
$$ $$\$$ |$$ |$$$$\ $$ |  $$ |$$ |               $$ |   $$$$$$$  |$$$$$$$$ |$$ $$\$$ |
$$ \$$$$ |$$ |\_$$ |$$ |  $$ |$$ |               $$ |   $$  __$$< $$  __$$ |$$ \$$$$ |
$$ |\$$$ |$$ |  $$ |$$ |  $$ |$$ |  $$\          $$ |   $$ |  $$ |$$ |  $$ |$$ |\$$$ |
$$ | \$$ |\$$$$$$  | $$$$$$  |\$$$$$$  |         $$ |   $$ |  $$ |$$ |  $$ |$$ | \$$ |
\__|  \__| \______/  \______/  \______/          \__|   \__|  \__|\__|  \__|\__|  \__|
*/

/*
STRUCT NODE
*/

// A support struct for Linked Vector
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

    // Over load << operator
    friend ostream &operator<<(ostream &os, const Node &node) {
        os << node.val;
        return os;
    }

    // Over load = operator
    Node &operator=(const int &val) {
        this->val = val;
        return *this;
    }
};

/*
VECTOR
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

// Linked Vector based Vector class
class Vector {
   private:
    // The head node of the vector
    Node *head;
    // The tail node of the vector
    Node *tail;
    // The number of nodes in the vector
    int length;
    // Check if the vector is sorted or not
    bool sorted;

   public:
    // Default constructor, init an empty vector
    Vector();
    // A constructor to init a vector with a given array
    Vector(int *array, int size);
    // A constructor to read from a file and init a vector
    Vector(const string &filename);
    // Copy constructor, copy the values of another vector
    Vector(const Vector &vector);

    // Get the head node of the vector
    Node *getHead() const;
    // Get the length of the vector
    int getLength() const;
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
    // Sort the vector
    void sort();
    // Push a value to a proper location to keep the vector sorted
    void inOrderPush(int val);
    // Remove a value from the head of the vector
    int popFront();
    // Remove a value from the tail of the vector
    int popRear();
    // Remove a value from a specific location
    int popAt(int loc);
    // Search for a value in the vector and return its location, otherwise return -1
    int find(int val) const;
    // Remove a value from the vector if it exists
    int popByValue(int val);
    // Deallocate the vector
    void clear();

    // Overload << operator
    friend ostream &operator<<(ostream &os, const Vector &vector) {
        if (vector.head == NULL) {
            os << "[]";
            return os;
        }
        Node *curr = vector.head;
        os << "[";
        // Loop through the vector and print each node
        while (curr->next != NULL) {
            os << curr->val << ", ";
            curr = curr->next;
        }

        // Print the last node
        os << curr->val << "]";

        // Return the ostream object
        return os;
    }

    // Overload [] operator
    Node &operator[](int loc) {
        Node *it = new Node;
        // Check if the location is valid
        if (loc < 0 || loc >= length) {
            // throw out_of_range("Invalid location");
            return *it;
        }

        it = head;

        // Loop through the vector to find the node at the given location
        for (int i = 0; i < loc; i++) {
            it = it->next;
        }

        // Return the value of the node
        return *it;
    }

    // Overload + operator
    Vector operator+(const Vector &vector) const {
        // Create a new vector to store the result
        Vector newVector;

        // Create to iterators to loop through the vectors
        Node *i = head;
        Node *j = vector.head;

        // Loop through the vectors and push the sum values to the new vector
        while (i != NULL && j != NULL) {
            newVector.pushRear(i->val + j->val);
            i = i->next;
            j = j->next;
        }

        // Push the remainders of the first vector to the new vector
        while (i != NULL) {
            newVector.pushRear(i->val);
            i = i->next;
        }

        // Push the remainders of the second vector to the new vector
        while (j != NULL) {
            newVector.pushRear(j->val);
            j = j->next;
        }

        // Return the new vector
        return newVector;
    }

    // Overload - operator
    Vector operator-(const Vector &vector) const {
        // Create a new vector to store the result
        Vector newVector;

        // Create to iterators to loop through the vectors
        Node *i = head;
        Node *j = vector.head;

        // Loop through the vectors and push the difference values to the new vector
        while (i != NULL && j != NULL) {
            newVector.pushRear(i->val - j->val);
            i = i->next;
            j = j->next;
        }

        // Push the remainders of the first vector to the new vector
        while (i != NULL) {
            newVector.pushRear(i->val);
            i = i->next;
        }

        // Push the remainders of the second vector to the new vector
        while (j != NULL) {
            newVector.pushRear(j->val);
            j = j->next;
        }

        // Return the new vector
        return newVector;
    }

    // Overload * operator
    Vector operator*(const Vector &vector) const {
        // Create a new vector to store the result
        Vector newVector;

        // Create to iterators to loop through the vectors
        Node *i = head;
        Node *j = vector.head;

        // Loop through the vectors and push the product values to the new vector
        while (i != NULL && j != NULL) {
            newVector.pushRear(i->val * j->val);
            i = i->next;
            j = j->next;
        }

        // Push the remainders of the first vector to the new vector
        while (i != NULL) {
            newVector.pushRear(i->val);
            i = i->next;
        }

        // Push the remainders of the second vector to the new vector
        while (j != NULL) {
            newVector.pushRear(j->val);
            j = j->next;
        }

        // Return the new vector
        return newVector;
    }

    // Overload / operator
    Vector operator/(const Vector &vector) const {
        // Create a new vector to store the result
        Vector newVector;

        // Create to iterators to loop through the vectors
        Node *i = head;
        Node *j = vector.head;

        // Loop through the vectors and push the quotient values to the new vector
        while (i != NULL && j != NULL) {
            newVector.pushRear(i->val / j->val);
            i = i->next;
            j = j->next;
        }

        // Push the remainders of the first vector to the new vector
        while (i != NULL) {
            newVector.pushRear(i->val);
            i = i->next;
        }

        // Push the remainders of the second vector to the new vector
        while (j != NULL) {
            newVector.pushRear(j->val);
            j = j->next;
        }

        // Return the new vector
        return newVector;
    }

    // Overload == operator
    bool operator==(const Vector &vector) const {
        // Check if the lengths of the vectors are equal
        if (length != vector.length) {
            return false;
        }

        // Create to iterators to loop through the vectors
        Node *i = head;
        Node *j = vector.head;

        // Loop through the vectors and check if the values are equal
        while (i != NULL && j != NULL) {
            if (i->val != j->val) {
                return false;
            }
            i = i->next;
            j = j->next;
        }

        // Return true if the vectors are equal
        return true;
    }

    // Overload = operator
    Vector operator=(const Vector &vector) {
        // Some people may think of the below implementation:
        // this->head = vector.head
        // this->tail = vector.tail
        // this->length = vector.length
        // But this is totally wrong, because the above implementation will only copy the address of the head, tail and length
        // Therefore, when the Destructor is called, the head and tail pointer will be deallocated twice

        // Instead, we must clear the current vector and then copy the values of the input vector to the current vector
        clear();
        Node *curr = vector.head;
        while (curr != NULL) {
            pushRear(curr->val);
            curr = curr->next;
        }
        return *this;
    }

    // Free the allocated memory
    ~Vector();
};

/*
CONSTRUCTOR
*/

Vector::Vector() {
    head = NULL;
    tail = NULL;
    length = 0;
    sorted = false;
}

Vector::Vector(int *array, int size) {
    head = NULL;
    tail = NULL;
    length = 0;
    sorted = false;
    for (int i = 0; i < size; i++) {
        // Push the value to the tail of the vector
        pushRear(array[i]);
    }
}

Vector::Vector(const string &filename) {
    head = NULL;
    tail = NULL;
    length = 0;
    sorted = false;
    // Open a file to read
    ifstream read(filename);
    int val;

    // Read the file until the end
    while (read >> val) {
        // Push the value to the tail of the vector
        pushRear(val);
    }

    // Close the file
    read.close();
}

Vector::Vector(const Vector &vector) {
    head = NULL;
    tail = NULL;
    length = 0;
    sorted = false;
    // Copy the head node of the vector in order not to lose track of the head node
    Node *temp = vector.head;

    // While its not the end of the vector
    while (temp != NULL) {
        // Push the value to the tail of the vector
        pushRear(temp->val);
        // Move to the next node
        temp = temp->next;
    }
}

/*
METHOD
*/

Node *Vector::getHead() const {
    return head;
}

int Vector::getLength() const {
    return length;
}

void Vector::pushFront(int val) {
    sorted = false;
    // Create a new node
    Node *temp = new Node(val);

    // If the vector is empty
    if (head == NULL) {
        // Set the head and tail to the new node
        head = temp;
        tail = temp;
    }
    // If the vector is not empty
    else {
        // Set the new node's next to the head
        temp->next = head;
        // Set the head to the new node
        head = temp;
    }

    // Increase the length of the vector
    length++;
}

void Vector::pushFront(const Vector &vector) {
    sorted = false;
    Node *temp = vector.head;

    while (temp != NULL) {
        pushFront(temp->val);
        temp = temp->next;
    }
}

void Vector::pushRear(int val) {
    sorted = false;
    Node *temp = new Node(val);

    if (head == NULL) {
        head = temp;
        tail = temp;
    }
    // If the vector is not empty
    else {
        // Set the tail's next to the new node
        tail->next = temp;
        // Set the tail to the new node
        tail = temp;
    }

    length++;
}

void Vector::pushRear(const Vector &vector) {
    sorted = false;
    Node *temp = vector.head;

    while (temp != NULL) {
        pushRear(temp->val);
        temp = temp->next;
    }
}

void Vector::pushAt(int loc, int val) {
    sorted = false;
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

void Vector::sort() {
    // If the vector is already sorted
    if (sorted) {
        return;
    }

    sorted = true;

    // If the vector is empty
    if (head == NULL) {
        return;
    }

    // Using bubble sort
    for (Node *i = head; i != NULL; i = i->next) {
        for (Node *j = i->next; j != NULL; j = j->next) {
            if (i->val > j->val) {
                swap(i->val, j->val);
            }
        }
    }
}

void Vector::inOrderPush(int val) {
    if (!sorted) {
        sort();
    }

    // If the vector is empty
    if (head == NULL) {
        pushFront(val);
        return;
    }

    // If the vector is not empty

    // Create a new node
    Node *temp = new Node(val);
    // Current node is to check if we had move to the right location
    Node *curr = head;
    // Previous node is to support inserting the new node
    Node *prev = NULL;

    // Find the location to insert the new node
    // Keep looping until the end of the vector or the current node's value is larger than the new node's value
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

int Vector::popFront() {
    // If the vector is empty, we cannot pop
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

int Vector::popRear() {
    // If the vector is empty, we cannot pop
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

    // If the vector has only one node
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

int Vector::popAt(int loc) {
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

int Vector::find(int val) const {
    Node *curr = head;

    // Loop through the vector
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

int Vector::popByValue(int val) {
    // Find the location of the value
    int loc = find(val);

    return popAt(loc);
}

void Vector::clear() {
    // Loop through the vector and delete each node
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL;
    length = 0;
}

/*
DESTRUCTOR
*/

Vector::~Vector() {
    clear();
}

// A function to test the Vector class
void test(ostream &os) {
    int a1[] = {1, 2, 3, 4, 5};
    int a2[] = {10, 20, 30};

    Vector v1(a1, 5);
    Vector v2(a2, 3);

    ofstream outfile;
    outfile.open("output.txt");

    // writes out 3
    cout << v1[2] << endl;
    // writes out 3 to file
    outfile << v1[2] << endl;

    v1[4] = 9;
    // v1 now = [1,2,3,4,9]

    // writes out [1,2,3,4,9] to console.
    cout << v1 << endl;
    // writes out [1,2,3,4,9] to file.
    outfile << v1 << endl;

    // writes out [1,2,3,4,9] to your output file.

    Vector v3 = v1 + v2;
    // writes out [11,22,33,4,9] to console.
    cout << v3 << endl;
    // writes out [11,22,33,4,9] to file.
    outfile << v3 << endl;

    v3 = v1 - v2;
    // writes out [-9,-18,-27,4,9] to console.
    cout << v3 << endl;
    // writes out [-9,-18,-27,4,9] to file.
    outfile << v3 << endl;

    v3 = v2 - v1;
    // writes out [9,18,27,4,9] to console.
    cout << v3 << endl;
    // writes out [9,18,27,4,9] to file.
    outfile << v3 << endl;

    v3 = v2 * v1;
    // writes out [10,40,90,4,9] to console.
    cout << v3 << endl;
    // writes out [10,40,90,4,9] to file.
    outfile << v3 << endl;

    v3 = v1 * v2;
    // writes out [10,40,90,4,9] to console.
    cout << v3 << endl;
    // writes out [10,40,90,4,9] to file.
    outfile << v3 << endl;

    v3 = v1 / v2;
    // writes out [0,0,0,4,9] to console.
    cout << v3 << endl;
    // writes out [0,0,0,4,9] to file.
    outfile << v3 << endl;

    v3 = v2 / v1;
    // writes out [10,10,10,4,9] to console.
    cout << v3 << endl;
    // writes out [10,10,10,4,9] to file.
    outfile << v3 << endl;

    // writes 0 to console (false) .
    cout << (v2 == v1) << endl;
    // writes 0 to console (false) file
    outfile << (v2 == v1) << endl;

    Vector v4 = v1;
    // writes 1 to console (true) .
    cout << (v4 == v1) << endl;
    // writes 1 to console (true) file
    outfile << (v4 == v1) << endl;
}

int main() {
    test(cout);
    ofstream outfile("test.out");
    test(outfile);
    outfile.close();
    return 0;
}
