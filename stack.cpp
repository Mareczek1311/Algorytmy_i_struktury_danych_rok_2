#include <iostream>
#include <stdio.h>

using namespace std;

struct Element{
    Element* poprzedni;
    int wartosc;
};

void push(Element* &stos, int wartosc){

    //Tworzenie nowego elementu na gore stosu
    Element* nowyElement = new Element;
    nowyElement->wartosc = wartosc;

    //Ustawienie poprzedniego elementu na poprzedni szczyt stosu
    nowyElement->poprzedni = stos;

    //Aktualizacja ostatniego elementu na ten nowy
    stos = nowyElement;

}

int pop(Element* &stos){

    if(!stos){
        return -1;
    }

    //Zapisanie ostatniego elementu
    Element* ostatniElement = stos;
    int ostatniaWartosc = ostatniElement->wartosc;

    //Zaktualizowanie ostatniego elementu na poprzedni
    stos = stos->poprzedni;

    //Usuniecie ostatniego zapisalego elementu z pamieci
    delete ostatniElement;

    //Zwrocenie wartosci z ostatniego elementu ktory wyrzucilismy
    return ostatniaWartosc; 
}

int main(){

    Element* stos = NULL;
    
    //Dodaje 1, 2, 3 oraz usuwam 4 elementy aby sprawdzic czy poprawnie sie usuna oraz czy dziala zabezpieczenie przed bledami


    push(stos, 1);
    push(stos, 2);
    push(stos, 3);

    cout << pop(stos) << endl;
    cout << pop(stos) << endl;
    cout << pop(stos) << endl;
    cout << pop(stos) << endl;

    return 0;
}