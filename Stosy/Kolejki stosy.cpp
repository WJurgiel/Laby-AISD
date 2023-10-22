#include <iostream>
#include <time.h>
using std::cout;
using std::cin;
using std::endl;

const int MAX = 1000;

class MyStack {

    int top;

public:
    MyStack() {
        top = -1;
        size = 0;
    }
    int a[MAX];
    int size;
    bool push(int a);
    int pop();
    int peek();
    bool isEmpty();
    void display();
    void generateRandomStack(MyStack&);
    void removeElement(int index);
};

bool MyStack::push(int val) {

    if (top >= MAX) {

        printf("Stack overflow!");
        return false;

    }
    else {
        size++;
        top++;
        this->a[top] = val;
        return true;
    }

}
int MyStack::pop() {
    if (top <= -1) {
        cout << "Stack underflow!\n";
        return 0;
    }
    else {
        int x = a[top--];
        /*cout << "Pop: ";*/
        return x;
    }
}
bool MyStack::isEmpty() {
    return (top < 0);
}
int MyStack::peek() {
    if (isEmpty()) {
        cout << "Stack's empty!\n";
        return 0;
    }
    else {
        int x = a[top];
        cout << "Peek: ";
        return x;
    }
}
void MyStack::display() {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
}
void MyStack::generateRandomStack(MyStack& stack){
    unsigned short size = rand() % 13 + 5;
    for (int j = 0; j < size; j++) {
        stack.push(rand() % 30 + 1);
    }
    
}
void MyStack::removeElement(int index){
    //liczone od wierzcholka - top 
    // przyklad: index = 2 -> usun top -2
    // top - index
    int toRemove = top - index;
    int aux_iteration = 0;
    cout << "Deleted element of index from top of stack ["<< index << "]( " << a[toRemove] << " )" << endl;
    for(int rightNum = toRemove + 1; rightNum <= top; rightNum++ && aux_iteration++){
        a[toRemove + aux_iteration] = a[rightNum];
    }
    top--;   
    size--;
}
/*
 Napisz funkcję, która ze stosu usunie element znajdujący się na pozycji n (licząc od
wierzchołka stosu). Dla stosu przyjmij implementację tablicową. 
*/

int main()
{
    srand(time(NULL));
    /*
        Zadanie 1
    ===================================================
    */
    MyStack stosik;
    int n;

    stosik.generateRandomStack(stosik);
    cout << "Stack size: " << stosik.size << endl;
    cout << stosik.peek() << endl;
    stosik.display(); cout << endl;

    cout << "Give the index of element (from top) that you want to remove [0 - " << stosik.size-1 << "]: ";
    do{
        cin >> n;
    }while(n < 0 || n > stosik.size);

    stosik.removeElement(n);
    stosik.display(); cout << endl;

}

