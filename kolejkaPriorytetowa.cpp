#include<iostream>

using namespace std;

//priorytet



struct elem{
    int wartosc;
    elem* nast;
};


struct KolejkaPrio{
    elem* start;
    elem* koniec;
    int maxWartosc;
};

KolejkaPrio* inicjalizacja(){
    KolejkaPrio* nowaKolejka = new KolejkaPrio;
    nowaKolejka->start = NULL;
    nowaKolejka->koniec = NULL;
    nowaKolejka->maxWartosc = -1;
    return nowaKolejka;
}

elem* inicjalizacjaElementu(int wartosc){
    elem* nowyElem = new elem;

    nowyElem->nast = NULL;
    nowyElem->wartosc = wartosc;

    return nowyElem;
}

void dodajElement(KolejkaPrio* kolejka, int wartosc){
    elem* nowyElem = inicjalizacjaElementu(wartosc);

    if(kolejka->koniec == NULL && kolejka->start == NULL){
        kolejka->start = nowyElem;
        kolejka->koniec = nowyElem;
        kolejka->maxWartosc = wartosc;
        return;
    }

    nowyElem->nast = kolejka->koniec;
    kolejka->koniec = nowyElem;

    if(wartosc > kolejka->maxWartosc){
        kolejka->maxWartosc = wartosc;
    }
    

}

int findNewMaxElement(KolejkaPrio* kol){

    if(kol->koniec == NULL){
        cout << "Brak elementow" << endl;
        return -1;
    }

    int max = kol->koniec->wartosc;

    elem* obecnyElem = kol->koniec->nast;

    while(obecnyElem != NULL){
        if(obecnyElem->wartosc > max){
            max = obecnyElem->wartosc;
        }

        obecnyElem = obecnyElem->nast;
    }


    return max;
    
}

//Usuniecie najwiekszej wartsci
void usunElement(KolejkaPrio* kolejka){


    if(kolejka->koniec == NULL){
        cout << "Brak elementow" << endl;
        return;
    }


    if(kolejka->koniec == kolejka->start){
        delete kolejka->koniec;
        kolejka->start = NULL;
        kolejka->koniec = NULL;
        return;
    }

    elem* obecnyElem = kolejka->koniec;

    if(kolejka->maxWartosc == obecnyElem->wartosc){
        kolejka->koniec = obecnyElem->nast;
        delete obecnyElem;
        return;
    }
    

    while(kolejka->maxWartosc != obecnyElem->nast->wartosc){
        obecnyElem = obecnyElem->nast;
    }


    if(kolejka->start == obecnyElem->nast){

        kolejka->start = obecnyElem;
        delete obecnyElem->nast;
        kolejka->start->nast = NULL;

        return;
    }

    obecnyElem->nast = obecnyElem->nast->nast;

}


void print(KolejkaPrio* kol){
    if(kol->koniec == NULL){
        cout << "Brak elementow" << endl;
        return;
    }

    elem* obecnyElem = kol->koniec;
    
    while(obecnyElem != NULL){
        cout << obecnyElem->wartosc << " -> ";
        obecnyElem = obecnyElem->nast;
    }

    
    cout << endl;
}

void clear(KolejkaPrio* kol){
    elem* obecnyElem = kol->koniec;
    elem* ostatniElem = obecnyElem;
    while(obecnyElem != NULL){
        obecnyElem = obecnyElem->nast;
        delete ostatniElem;
        ostatniElem = obecnyElem;
    }

    delete kol;
}

int main(){

    KolejkaPrio* kolejkaPrio;

    kolejkaPrio = inicjalizacja();

    dodajElement(kolejkaPrio, 3);
    dodajElement(kolejkaPrio, 2);
    dodajElement(kolejkaPrio, 1);
    print(kolejkaPrio);

    usunElement(kolejkaPrio);
    kolejkaPrio->maxWartosc = findNewMaxElement(kolejkaPrio);

    print(kolejkaPrio);

    usunElement(kolejkaPrio);
    kolejkaPrio->maxWartosc = findNewMaxElement(kolejkaPrio);

    print(kolejkaPrio);

    usunElement(kolejkaPrio);
    kolejkaPrio->maxWartosc = findNewMaxElement(kolejkaPrio);

    print(kolejkaPrio);
    /*

    usunElement(kolejkaPrio);
    print(kolejkaPrio);

    usunElement(kolejkaPrio);
    print(kolejkaPrio);
    */

    clear(kolejkaPrio);

    return 0;
}