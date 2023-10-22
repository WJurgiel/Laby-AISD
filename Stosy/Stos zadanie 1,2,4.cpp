#include <iostream>
#include <time.h>
using std::cout;
using std::cin;
using std::endl;

class StackNode{
 public: 
    int data;
    static int index;
    StackNode* next;
};

StackNode* newNode(int data){
    StackNode* newStackNode = new StackNode();
    newStackNode->data = data;
    newStackNode->next = NULL;

    return newStackNode;
}

bool isEmpty(StackNode *root){
    // if(!root){
    //     cout << "STACK EMPTY\n";
    // }
    return !root;
}

void push(StackNode** root, int new_data){
    StackNode* stackNode = newNode(new_data);
    stackNode->next = *root;
    *root = stackNode;
    StackNode::index++;
}

int pop(StackNode** root){
    if(isEmpty(*root))
        return -1;
    StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    delete temp;

    StackNode::index--;
    return popped;
}

int peek(StackNode* root){
    if(isEmpty(root))
        return -1;
    return root->data;
}


void generateArray(int array[], int size){
    cout << "Generated array of ints for Task 1:\n";
    for(int i = 0; i < size; i++){
        array[i] = rand()%30+1;
        cout << array[i] << " ";
    }
    cout << endl;
}
void StackL(StackNode** root, int number, int array[], int arrSize){
    cout << "Multiples of " << number << ":\n";
    for(int i = 0; i < arrSize; i++){
        if(array[i] % number == 0){
            push(root, array[i]);
            cout << array[i] << " ";
        }
    }
    cout << endl;
}
int getSizeOfList(StackNode* root){
    int size_elems = 0;
    StackNode* tmp = root;
    while(root->next != NULL){
        size_elems++;
        (root) = (root)->next;
    }
    root = tmp;
    size_elems++; //add the last element that isn't being counted in while (last element's next is null)
    return size_elems;
}
void ReverseA(StackNode** root, StackNode** root2){
    while(!isEmpty(*root)){
        int x = pop(root);
        cout << x << " ";
        push(root2, x);
    }
    cout << endl;
    //cout << "---REVERSEDa PEEK FOR ROOT2--- "; cout << peek(*root2); cout << endl;
}
/*
    AT THIS MOMENT ELEMENTS COUNTER IS A STATIC INT index, IT MAY CAUSE PROBLEMS SO KEEP IT
        IN MIND :D
*/
void ReverseB(StackNode** root){
    
    int size_temp_tab = getSizeOfList(*root);
    int* tempTab = new int[size_temp_tab];
    for(int i = 0; i < size_temp_tab; i++){
        tempTab[i] = pop(root);
    }
    for(int j = 0; j < size_temp_tab; j++){
        push(root, tempTab[j]);
        cout << tempTab[j] << " ";
    }
    //cout << "\n---REVERSEDB PEEK FOR ROOT2--- ";cout << peek(*root); cout << endl;
    delete tempTab;
}


void Combine(StackNode** root, StackNode** root2){
    int size_elems1 = getSizeOfList(*root);
    int size_elems2 = getSizeOfList(*root2);
    
    int* elems1 = new int[size_elems1];
    int* elems2 = new int[size_elems2];
    
    //add elements of list1
    cout << "ELEMS LIST1: ";
    for(int i = size_elems1 -1; i >= 0 ; i--){
        elems1[i] = pop(root);
        cout << elems1[i] << " ";
    }
    cout << endl;
    //add elements of list2
    cout << "ELEMS LIST2: ";
    for(int k = size_elems2 -1; k >= 0 ; k--){
        elems2[k] = pop(root2);
        cout << elems2[k] << " ";
    }
    cout << endl;
    
    for(int element = 0; element < size_elems2; element++){
        if(element < size_elems1){
            push(root, elems1[element]);  
        }
        push(root, elems2[element]);
    }
    
    delete elems1;
    delete elems2;
}
int StackNode::index = 0;
int main(){
    srand(time(NULL));
    StackNode* root = NULL;
    StackNode* root2 = NULL; // 2a)
    /*
        //TEST OF STACK
        //==========================
        push(&root, 0);
        push(&root, 1);
        push(&root, 2);

        cout << "Top element: " << peek(root) << "\n";

        cout << "Popped elements:\n";
        while(!isEmpty(root)){
            cout << pop(&root) << " ";
        }
        //=============================
    */
    /*
        ZADANIE 1
        ============================
    */
    const int arrSize = 14;
    int array[arrSize];
    int number;
    cout << "-----------------UWAGA---------------------------\n";
    cout << "W PODANYCH WYNIKACH DLA ZADAN 1-2:\n\tLEWA STRONA - DÓŁ STOSU\n\tPRAWA STRONA - WIERZCHOŁEK STOSU\n";
    cout << "DLA ZADANIA 4: ODWROTNIE (powod - w zadaniu 4 popuje wszystkie elementy a nie jak w poprzednich zadaniach wyswietlam je po forze z tablicy\n)";
    cout << "--------------------------------------------------\n";
    cout << "=================ZADANIE 1=======================\n";
    generateArray(array, arrSize);
    cout << "Give number in range (0,10>: ";
    do{
        cin >> number;
    }while(number <= 0 || number > 10);

    StackL(&root, number, array, arrSize);
    cout << "*PEEK [ROOT]: " << peek(root) << endl;
    cout << "*PEEK [ROOT 2]: " << peek(root2) << endl;
    cout << "=================ZADANIE 2A=======================\n";

    /*
        =============================
        ZADANIE 2
        A)
        =============================
    */
    cout << "Reversed: [stack 1 -> stack 2| stack 1 empty after that]\n";
    ReverseA(&root, &root2);
    cout << "*PEEK [ROOT]: " << peek(root) << endl;
    cout << "*PEEK [ROOT 2]: " << peek(root2) << endl;
    cout << "==================ZADANIE 2B======================\n";
    //UWAGA: ROOT JEST PUSTY, ROOT2 ZAWIERA WSZYSTKIE DANE Z ROOT
    //MIEĆ TO NA UWADZE 
    /*
        =============================
        ZADANIE 2
        B)
        =============================
    */
    cout << "Reversed [stack 2]:\n";
    ReverseB(&root2);
    cout << "\n*PEEK [ROOT]: " << peek(root) << endl;
    cout << "*PEEK [ROOT 2]: " << peek(root2) << endl;

    cout << "\n================ZADANIE 4========================\n";
    push(&root, 100);
    push(&root, 101);
    push(&root, 102);
    cout << "Testowa lista:\n100,101,102\n";

    Combine(&root, &root2);

    cout << "*PEEK [ROOT]: " << peek(root) << endl;
    cout << "*PEEK [ROOT 2]: " << peek(root2) << endl;
    
    cout << "PEAK -> ";
    while(!isEmpty(root)){
        cout << pop(&root) << " ";
    }
    cout << " <- ROOT";
    cout << endl;
    
    return 0;
}