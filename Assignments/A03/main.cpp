/*
 
   _______   _____  ___   ___  ________                                                         
  /  ___  \ / __  \|\  \ |\  \|\_____  \                                                        
 /__/|_/  /|\/_|\  \ \  \\_\  \|____|\ /_                                                       
 |__|//  / ||/ \ \  \ \______  \    \|\  \                                                      
     /  /_/__   \ \  \|_____|\  \  __\_\  \                                                     
    |\________\  \ \__\     \ \__\|\_______\                                                    
     \|_______|   \|__|      \|__|\|_______|                                                    
                                                                                                
                                                                                                
                                                                                                
  ________  ________  ___   ___                                                                 
 |\   __  \|\   __  \|\  \ |\  \                                                                
 \ \  \|\  \ \  \|\  \ \  \\_\  \                                                               
  \ \   __  \ \  \\\  \ \______  \                                                              
   \ \  \ \  \ \  \\\  \|_____|\  \                                                             
    \ \__\ \__\ \_______\     \ \__\                                                            
     \|__|\|__|\|_______|      \|__|                                                            
                                                                                                
                                                                                                
                                                                                                
  ________   ________  ________  ________          _________  ________  ________  ________      
 |\   ___  \|\   ____\|\   __  \|\   ____\        |\___   ___\\   __  \|\   __  \|\   ___  \    
 \ \  \\ \  \ \  \___|\ \  \|\  \ \  \___|        \|___ \  \_\ \  \|\  \ \  \|\  \ \  \\ \  \   
  \ \  \\ \  \ \  \  __\ \  \\\  \ \  \                \ \  \ \ \   _  _\ \   __  \ \  \\ \  \  
   \ \  \\ \  \ \  \|\  \ \  \\\  \ \  \____            \ \  \ \ \  \\  \\ \  \ \  \ \  \\ \  \ 
    \ \__\\ \__\ \_______\ \_______\ \_______\           \ \__\ \ \__\\ _\\ \__\ \__\ \__\\ \__\
     \|__| \|__|\|_______|\|_______|\|_______|            \|__|  \|__|\|__|\|__|\|__|\|__| \|__|
                                                                                                
                                                                                                
                                                                                                
 
*/

#include <iostream>

using namespace std;

/**
 * CircularArrayQue
 * 
 * Description:
 *      Description of a queue where last element connecting
 *      to the first element of queue forming a circle
 * 
 * Public Methods:
 *      void        Push() 
 *      int         Pop()
 *      
 * 
 * Private Methods:
 *      void        init(int size) 
 *      bool        Full()
 *      
 */
class CircularArrayQue {
private:
    int *Container;         //container for CircularArrayQue class
    int Front;              //front of queue
    int Rear;               //rear of queue
    int QueSize;            //items in the queue
    int CurrentSize;        //size of queue

    /**
     * Private : init()
     * 
     * Description:
     *      to initialize size of queue
     * 
     * Params:
     *      int     :       size 
     */
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

    /**
     * Private : Full()
     * 
     * Description:
     *      to see if the queue is full
     * 
     * Returns:
     *      bool: True if number of item in queue = size of queue
     */
    bool Full() {
        return CurrentSize == QueSize;
    }

public:
    /**
    * Default constructor sets size of container to 10
    */
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }

    /**
    * Overload constructor sets size of container to 'size'
    */
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }

    /**
     * Public : Push()
     * 
     * Description:
     *      add item to front of queue
     * 
     * Params:
     *      int item    :   item to be added
     * 
     * Returns:
     *      none
     */
    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }

    /**
     * Private : Pop()
     * 
     * Description:
     *      to remove item from queue
     * 
     * Params:
     *      none
     * 
     * Returns:
     *      int: item removed from front of queue
     */
    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }

    // make friends with ostream so it can access private members of this class when printing
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};


/**
 * Overload ostream to print a vector to std out.
 * @params:
 *      ostream : copy of ostream (cout) so we can print to stdout
 *      other : the vector to be printed
 * @returns:
 *      ostream& : the copy of ostream (cout) we printed to
 */
ostream &operator<<(ostream &os, const CircularArrayQue &other) {
    //loop through the container
    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    //set size of array to 5
    CircularArrayQue C1(5); 

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}