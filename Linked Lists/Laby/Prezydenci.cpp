#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <limits.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
 /*
    klasa prezydent - jest jednocześnie listą prezydentów samą w sobie
    funkcje getPresident(), getYearStart(), getYearEnd(), getParty() to pozostałość po 
        domyślnym modelu klasy posiadającej prywatne pola i konstruktor wieloargumentowy, który w 
        późniejszych etapach wykonywania zadań generował problemy (głównie z utworzeniem nowej listy
        zawierającej pole klasy Prezydent)
 */
struct Prezydent{
    string year_start;
    string year_end;
    string party;
    string full_name;
 
    void getPresident(){
        cout << year_start << " - " << year_end << " " << party << " " << full_name <<  endl;
        cout << "---------------------------\n";
    }
    int getYearStart(){
        int year = stoi(year_start);
        return year;
    }
    int getYearEnd(){
        int year = stoi(year_end);
        return year;
    }
    string getParty(){
        return party;
    }
    Prezydent* next;
}* head = NULL;

/*
    klasa Odpowiedzi - klasa przetrzymująca odpowiedzi do zadań 1), 2), 3), po wykonaniu każdego
        zadania jest opróżniana za pomocą funkcji deleteList(Odpowiedzi**);
*/
class Odpowiedzi{
    public: 
    Prezydent prez;
    Odpowiedzi* next;
}*head1 = NULL;

/*
    append - funkcja dodająca element klasy Prezydent do listy typu Prezydent, funkcja dodaje
        nowy element na koniec listy
*/
void append(Prezydent** head, Prezydent* president){
    class Prezydent* newPrezydent = new Prezydent(*president);
    class Prezydent* last = *head;

    //newPrezydent = &president;
    newPrezydent->next = NULL;

    if(*head == NULL){
        *head = newPrezydent;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last -> next = newPrezydent;

    //newPrezydent->getPresident();
    return;
}
/*
    addOdpowiedzi - funkcja dodająca elementy klasy prezydent do listy Odpowiedzi. Dodaje element
        na początek
*/
void addOdpowiedzi(Odpowiedzi*& head, Prezydent x) {
    Odpowiedzi* tmp = new Odpowiedzi;
    tmp->prez = x;
    tmp->next = head;
    head = tmp;
}

void loadData(string path);
string* split(string s, string delimiter);

/*
    DisplayOdpowiedzi - wypisz liste z odpowiedziami do zadan 1), 2), 3)
*/
void DisplayOdpowiedzi(Odpowiedzi* head1){
    Odpowiedzi* tmp = head1;
    while(tmp != NULL){
        tmp->prez.getPresident();
        tmp = tmp->next;
    }
        
}
/*
    deleteList - opróżnij całą listę Odpowiedzi
*/
void deleteList(Odpowiedzi** head1) {
    Odpowiedzi* tmp = *head1;
    Odpowiedzi* next;
    while (tmp != NULL) {
        next = tmp->next;
        delete tmp;
        tmp = next;
    }
    *head1 = NULL;
}

/*
    findShortest - zadanie 1
    Algorytm: ustal shortestYear -> dla kazdego elementu listy znajdz czas panowania (difference) 
        -> ?difference< shortestYear to shortestYear = difference -> po znalezieniu najkrotszego
        czasu panowania dodaj prezydentow o takim wlasnie czasie panowania do listy Odpowiedzi
        -> zwroc head1 listy Odpowiedzi
*/
Odpowiedzi* findShortest(Prezydent* head){
    
    Prezydent* tmp = head;
    
    int difference;
    int shortestYear = INT_MAX;

    while(tmp != NULL){
        int yearStart = tmp->getYearStart();
        int yearEnd = tmp->getYearEnd();
         
        difference = yearEnd - yearStart;
        if(difference < shortestYear)
            shortestYear = difference;

        tmp = tmp->next;
    }

    cout << "a) Presidents with the shortest presidential term ( " << shortestYear << " ): " << endl;
    tmp = head;
    while(tmp != NULL){
        int yearStart = tmp->getYearStart();
        int yearEnd = tmp->getYearEnd();
        if((yearEnd - yearStart) == shortestYear){
            addOdpowiedzi(head1, *tmp);
        }
        tmp = tmp->next;
    }
    return head1;
}

/*
    findTheParty - Zadanie 2)
    Algorytm: jesli element listy prezydent nalezy do partii podanej jako argument dodaj go do Odpowiedzi
        -> zwroc head1 listy Odpowiedzi
*/
Odpowiedzi* findTheParty(Prezydent* head, string party){
    Prezydent* tmp = head;

    cout << "b) Presidents from the " << party << " party: " << endl;
    while(tmp != NULL){
        if(tmp->getParty() == party){
            addOdpowiedzi(head1, *tmp);
        }
        tmp = tmp->next;
    }
    return head1;
}
/*
    WhoRuledThen - Zadanie 3)
    Algorytm: ?podany rok jest w granicach <YearStart, YearEnd> dodaj prezydenta do listy Odpowiedzi
        -> zwroc head1 listy Odpowiedzi
*/
Odpowiedzi* WhoRuledThen(Prezydent* head, int year){
    Prezydent* tmp = head;
    cout << "In " << year << " the US was ruled by: " << endl;

    while(tmp!=NULL){
        if(year >= tmp->getYearStart() && year <= tmp->getYearEnd()){
            addOdpowiedzi(head1, *tmp);
        }
        tmp = tmp->next;
    }
    return head1;
}
int main() {
    loadData("C:/Users/Wojtek/Desktop/STUDIA/SEMESTR 3/AiSD/Linked Lists/Laby/prezydenci.txt");
    
    /*
        Zadanie 1)
    */
    Odpowiedzi* o1 = findShortest(head);
    DisplayOdpowiedzi(o1);
    deleteList(&head1);
    
    /*
        Zadanie 2)
    */
    string party = "Democratic";
    unsigned short choice = 0; 
    
    cout << "Choose party:\n[0] - Democratic\n[1] - Whig\n[2] - Republican\n[3] - Federalist\n[4] - Unaffiliated\n[5] - Democratic-Republican\nYour choice: ";
    cin >> choice;
    switch(choice){
        case 0: party = "Democratic"; break;
        case 1: party = "Whig"; break;
        case 2: party = "Republican"; break;
        case 3: party = "Federalist"; break;
        case 4: party = "Unaffiliated"; break;
        case 5: party = "Democratic-Republican"; break;
        default: choice = 404;
    }
    if (choice != 404){
        Odpowiedzi* o2 = findTheParty(head, party);
        DisplayOdpowiedzi(o2);
        deleteList(&head1);
    }else{
        cout << "Wrong input\n";
    }
        
    
    /*
        Zadanie 3)
    */
    unsigned short year = 0;
    cout << "Input year of ruling: "; cin >> year;
    Odpowiedzi* o3;
    if(year < 1789){
            cout << "no one, there was no US back then " << endl;
            cout << "---------------------------\n";
    }
    else if(year > 1901){
            cout << "TOP SECRET" << endl;
            cout << "---------------------------\n";
    }
    else{
        o3 = WhoRuledThen(head,year);
        DisplayOdpowiedzi(o3); 
        deleteList(&head1); 
    }
     
    
    return 0;
}
string* split(string s, string delimiter) {

    int pos_start = 0;
    int pos_end;
    int delim_len = delimiter.length();

    string token;
    static string buffer[10];

    int idx = 0;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {

        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;

        buffer[idx] = token;
        idx++;

        //cout << idx << endl;

    }

    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    buffer[idx] = token;

    //cout << buffer[0] << endl;

    return buffer;

}

void loadData(string path) {
	string line;
	std::ifstream myFile("" + path);
	if (myFile.is_open()) {
		while (std::getline(myFile, line)) {
			string* buffer = split(line, " ");
            Prezydent* president = new Prezydent;
            president->year_start = buffer[0];
            president->year_end = buffer[1];
            president->party = buffer[2];
            president->full_name = buffer[3] + " " + buffer[4] + " " + buffer[5] + " " + buffer[6];
            append(&head, president);
            
        }
		myFile.close();
	}
	else cout << "Error\n";
}