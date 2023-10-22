#include <iostream>
#define MAX_SIZE 5
using std::cout;
using std::cin;
using std::endl;

/*
Napisz funkcję UsuńX, która z kolejki prostej usunie element o wartości x, jeśli taki element w
kolejce się znajduje. Dla kolejki przyjmij implementację tablicową. Zdefiniuj wszystkie użyte
funkcje i struktury danych oraz zmienne
*/

//FIFO
class Queue{
 private:
    int myQueue[MAX_SIZE];
    int front, rear;
 public:
    Queue(): front(-1), rear(-1){};
    bool isFull();
    bool isEmpty();
    void push_back(int value);
    int pop_back();
    void display_queue();
    void peek();
    void delete_value(int value);
};
bool Queue::isFull(){
    return rear == MAX_SIZE - 1;
}
bool Queue::isEmpty(){
    return front == -1;
}
void Queue::push_back(int value){
    if(!isFull()){
        myQueue[++rear] = value;
        if(isEmpty())
            ++front;
    }
    else{
        cout << "Overflow, can't add value " << value << "\n";
    }
}
int Queue::pop_back(){
     if(front > rear){
        front = -1;
        rear = -1;
    }
    if(!isEmpty()){
        /* check whether it's last element*/
       
        // cout << "Front: " << front << endl;
        // cout << "Rear: " << front << endl;
        cout << "Pop: ";
        return myQueue[front++];
        
    }else{
        cout << "Underflow\n";
        return -1;
    }
}
void Queue::display_queue(){
    if(isEmpty()){
        cout << "Empty queue\n";
        return;
    }
    for(int id = front; id <= rear; id++){
        cout << "[ " << myQueue[id] << " ] ";
    }
    cout << endl;
}
void Queue::delete_value(int value){
    bool valueExists = false;
    if(isEmpty()){
        cout << "Empty queue\n";
    }
    for(int id = front; id <= rear; id++ ){
        if(myQueue[id] == value){
            valueExists = true;
            //id staje sie automatycznie pointerem na element <= rear
            cout << "Deleted value " << value << "on position [ " << id << " ]\n";
            int aux_iteration = 0;
            for(int num_to_right = id+1; num_to_right <= rear; num_to_right++ && aux_iteration++ ){
                myQueue[id + aux_iteration] = myQueue[num_to_right]; 
            }
            if(front > --rear){
                front = -1;
                rear = -1;
            }
        }
    }
    if(!valueExists){
        cout << "No matching value in queue!\n";
    }
}

int main(){
    Queue queue;
    queue.push_back(2);
    // queue.push_back(4);
    // queue.push_back(6);
    // queue.push_back(7);
    // queue.push_back(8);
    // queue.push_back(9);
    queue.display_queue();
    
    // cout << queue.pop_back() << endl;
    
    // queue.display_queue();
    
    // cout << queue.pop_back() << endl;
    
    // queue.display_queue();

    // cout << queue.pop_back() << endl;
   
    // queue.display_queue();

    // cout << queue.pop_back() << endl;

    queue.delete_value(3);
    queue.display_queue();
    return 0;
}