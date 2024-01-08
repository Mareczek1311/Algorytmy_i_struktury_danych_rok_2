#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>  // For system function
#include <fstream>
#include <sstream>

////Opcjonalne dodatki:
/*
    DODANIE OPCJI UTWORZENIA NOWEGO PROTOPLASTY
    POSPRZATANIE KODU
    DODANIE ENUMA
    UPIEKSZENIE WYPISYWANIA DRZEWA NP. DODANIE NAZWISKA PROTOPLASTY NA SZCZYCIE NP. RODZINA -NAZWISKO_PROTOPLASTY-


*/
//DODANIE WIECEJ INFO DO PLIKU ZAPISUJACEGO!!!!!

using namespace std;

struct Osoba{

    //informacje
    string imie;
    string nazwisko;
    int dzien;
    int miesiac;
    int rok;
    int index;
    int poziom;
    //0 men 1 woman
    int plec;
    int indexMalzonka;

    int czy_glowny;

    int obca;

    //wskazniki
    Osoba* malzonek;
    Osoba* ojciec;
    Osoba* matka;
    vector<Osoba*> osobyPotomne;

    Osoba(string imie, string nazwisko, int dzien, int miesiac, int rok, int inx, int poz, int p)
            : imie(imie), nazwisko(nazwisko), dzien(dzien), miesiac(miesiac), rok(rok),
              malzonek(nullptr), ojciec(nullptr), matka(nullptr), index(inx), poziom(poz), plec(p) {
    }
    Osoba(string imie, int poziom)
            : imie(imie), nazwisko("puste"), dzien(-1), miesiac(-1), rok(-1),
              malzonek(nullptr), ojciec(nullptr), matka(nullptr), index(-1), poziom(poziom), plec(-1) {
    }
    Osoba(){

    }
};

void usun_z_tablicy(vector<Osoba*>& osoby, Osoba* osoba){

    int a = -1;
    cout << "Osoby size:" << osoby.size() << endl;
    for(int i=0; i<osoby.size(); i++){
        if(osoba == osoby[i]){
            a = i;
            break;
        }
    }

    if(a != -1){
        cout << "Osoba usunieta" << endl;
        swap(osoby[a], osoby[osoby.size()-1]);
        osoby.pop_back();
    }

    cout << "Osoby size:" << osoby.size() << endl;

}

struct Drzewo{
    int poziomy;
    vector<vector<Osoba*> > struktura_drzewa;
    int aktualny_index;
    Osoba* protoplasta;
};


void wypisz_osobe(Osoba* osoba){
    cout << "-----" << endl;
    cout << "Imie: " << osoba->imie << endl;
    cout << "Nazwisko: " << osoba->nazwisko << endl;
    cout << "Data urodzenia: " << osoba->dzien << "-" << osoba->miesiac << "-" << osoba->rok << endl;

    if(osoba->plec == 0){
        cout << "Plec: Mezczyzna" << endl;
    }
    else{
        cout << "Plec: Kobieta" << endl;
    }

    cout << "Matka: " << osoba->matka->imie << endl;
    cout << "Ojciec: " << osoba->ojciec->imie << endl;

    cout << "-----" << endl;
}


Osoba* dodaj_malzonka(Osoba* osoba){
    if(osoba->malzonek  != nullptr){
        return osoba->malzonek;
    }
    return nullptr;
}

//BFS
Osoba* znajdz_osobe(Drzewo* drzewo, Osoba* start, int szukana_index){
    queue<Osoba*> q;
    vector<Osoba*> visited;

    q.push(start);

    while(!q.empty()){
        Osoba* curr;
        curr = q.front();
        q.pop();


        if(curr->index == szukana_index){
            return curr;
        }


        Osoba* malzonek = curr->malzonek;
        if(malzonek != nullptr){
            q.push(malzonek);
            visited.push_back(malzonek);
        }

        for(int i =0; i<curr->osobyPotomne.size(); i++){
            Osoba* potomek = curr->osobyPotomne[i];
            q.push(potomek);
            visited.push_back(potomek);
        }

    }
}

int maxDzieci(Osoba* osoba){
    queue<Osoba*> q;

    q.push(osoba);
    Osoba* os = osoba;

    while(!q.empty()){
        Osoba* curr = q.front();
        q.pop();

        if(curr->osobyPotomne.size() > os->osobyPotomne.size()){
            os = curr;
        }

        for(int i=0; i<curr->osobyPotomne.size(); i++){
            q.push(curr->osobyPotomne[i]);

            Osoba* malzonek = dodaj_malzonka(curr->osobyPotomne[i]);
            if(malzonek != nullptr){
                q.push(malzonek);
            }
        }

    }


    // jeszcze liczenie malzenstwa

    int max = 0;
    for(int i=0; i<os->osobyPotomne.size(); i++){
        max += 6;
        max += os->osobyPotomne[i]->imie.length();
        max += to_string(os->osobyPotomne[i]->index).length();

        if(os->osobyPotomne[i]->malzonek != nullptr){
            max += 4; // dodanie <-->
            max += 6; // dodanie |   | ." "
            max += os->osobyPotomne[i]->malzonek->imie.length();
            max += to_string(os->osobyPotomne[i]->malzonek->index).length();

        }
    }

    return max;
}

void wypisz(Drzewo* drzewo){
    queue<Osoba*> tablica_osob;

    tablica_osob.push(drzewo->protoplasta);

    int currPoziom = 0;

    while(!tablica_osob.empty()){
        Osoba* curr = tablica_osob.front();
        tablica_osob.pop();

        if(currPoziom != curr->poziom){
            currPoziom += 1;
            cout << endl;
        }

        if(curr->imie == "pusta2"){
            //cout << "Rok: " << curr->rok ;
            for(int i=0; i<curr->rok; i++){
                cout << " ";
            }

            delete curr;
            continue;
        }

        if(curr->imie == "puste"){

            if(curr->ojciec != nullptr && curr->ojciec->malzonek != nullptr){
                cout << "    ";
            }

            if(curr->ojciec != nullptr){
                for(int i=0; i<curr->ojciec->imie.length(); i++){
                    cout << " ";
                }
                cout << "      ";

                for(int i=0; i< to_string(curr->ojciec->index).length(); i++){
                    cout << " ";
                }
            }

            if(curr->matka != nullptr){
                for(int i=0; i<curr->matka->imie.length(); i++){
                    cout << " ";
                }
                cout << "      ";

                for(int i=0; i< to_string(curr->matka->index).length(); i++){
                    cout << " ";
                }
            }

            delete curr;
            continue;
        }
        int offset = 0;

        cout <<  " |" + to_string(curr->index) + ". " + curr->imie + "| ";
        offset += 2+to_string(curr->index).size() + 2+ curr->imie.size() + 2;

        if(curr->malzonek != nullptr){
            cout << "<-->";
            cout << " |" << curr->malzonek->index << ". " << curr->malzonek->imie << "| ";
            offset += 2+to_string(curr->malzonek->index).size() + 2+ curr->malzonek->imie.size() + 2 + 4;

        }

        if(curr->osobyPotomne.size() == 0){
            Osoba* newOsoba  = new Osoba("puste", curr->poziom+1);
            newOsoba->ojciec = curr;
            newOsoba->poziom = newOsoba->ojciec->poziom + 1;
            tablica_osob.push(newOsoba);
        }



        int max;
        if(curr->osobyPotomne.size() == 0){
            max = 0;

        }
        else {

            for(int i=0; i<curr->osobyPotomne.size(); i++){
                tablica_osob.push(curr->osobyPotomne[i]);
            }
            max = maxDzieci(curr);
            //cout << max << " " << offset;
            if(max > offset){
                max -= offset;
            }
            else if(max < offset){
                Osoba* pusta2 = new Osoba();
                pusta2->imie = "pusta2";
                pusta2->rok = offset - max;
                pusta2->poziom = curr->poziom +1;
                max = 0;
                tablica_osob.push(pusta2);
            }
            for(int i=0;i<max;i++){
                cout << " ";
            }
        }
    }
}

void usun_osobe(int index, Drzewo* drzewo){
    Osoba* osoba = znajdz_osobe(drzewo, drzewo->protoplasta, index);

    if(osoba->osobyPotomne.size() != 0)
    {
        osoba->imie = "nieznane";
        osoba->nazwisko = "nieznane";
        osoba->dzien = -1;
        osoba->miesiac = -1;
        osoba->rok = -1;
    }
    else{
        if(osoba->ojciec != nullptr){
            usun_z_tablicy(osoba->ojciec->osobyPotomne, osoba);
        }
        if(osoba->matka != nullptr) {
            usun_z_tablicy(osoba->matka->osobyPotomne, osoba);
        }
        if(osoba->malzonek != nullptr) {
            osoba->malzonek->malzonek = nullptr;
        }
        else{
            usun_osobe(osoba->malzonek->index, drzewo);
        }
        delete osoba;
    }
}

void dodaj_dziecko(Osoba* rodzic, Osoba* dziecko){
    rodzic->osobyPotomne.push_back(dziecko);
    if(rodzic->malzonek != nullptr){
        rodzic->malzonek->osobyPotomne.push_back(dziecko);
    }
}

void dodaj_rodzica(Osoba* rodzic, Osoba* dziecko){
    if(rodzic->plec == 0){
        //ojciec
        dziecko->ojciec = rodzic;

        if(rodzic->malzonek != nullptr){
            dziecko->matka = rodzic->malzonek;
        }
    }
    else{
        dziecko->matka = rodzic;
        if(rodzic->malzonek != nullptr){
            dziecko->ojciec = rodzic->malzonek;
        }
    }

}

void utworz_malzenstwo(Osoba* a, Osoba* b){
    a->malzonek = b;
    b->malzonek = a;
    b->osobyPotomne = a->osobyPotomne;

    for(int i=0; i<b->osobyPotomne.size(); i++){
        dodaj_rodzica(a, b->osobyPotomne[i]);
    }
}

string zmien_state(string state, int lvl, int plec){

    if(state == "-1"){
        return "-1";
    }

    if(lvl == 1){

        //PRAWDOPODOBNIE UZYJEMY ENUMA

        //meskie
        if(state == "wuj" || state == "ciotka"){
            if(plec == 0){
                return "kuzyn";
            }
            else{
                return "kuzynka";
            }
        }
        if(state == "ojciec" || state == "matka"){
            if(plec == 0){
                return "brat";
            }
            else{
                return "siostra";
            }
        }
        if(state == "dziadek" || state == "babcia"){
            if(plec == 0){
                return "wuj";
            }
            else{
                return "ciotka";
            }
        }
        if(state == "brat" || state == "bratowa"){
            if(plec == 0){
                return "bratanek";
            }
            else{
                return "bratanica";
            }
        }
        if(state == "pradziadek" || state == "prababcia"){
            if(plec == 0){
                return "dziadek";
            }
            else{
                return "babcia";
            }
        }
        if(state == "probant" || state == "zona" || state == "maz"){
            if(plec == 0){
                return "syn";
            }
            else{
                return "corka";
            }
        }
        if(state == "syn" || state == "corka"){
            if(plec == 0){
                return "wnuk";

            }
            else{
                return "wnuczka";
            }
        }
    }

    else if(lvl == -1){
        if(state == "kuzyn" || state == "kuzynka"){
            if(plec == 0){
                return "wuj";
            }
            else{
                return "ciotka";
            }
        }
        if(state == "ojciec" || state == "matka"){
            if(plec == 0){
                return "dziadek";

            }
            else{
                return "babcia";
            }
        }
        if(state == "dziadek" || state == "babcia"){
            if(plec == 0){
                return "pradziadek";

            }
            else{
                return "prababcia";
            }
        }
        if(state == "syn" || state == "probant" || state == "corka"){
            if(plec == 0){
                return "ojciec";

            }
            else{
                return "matka";
            }
        }
        if(state == "wuj" || state == "ciotka"){
            if(plec == 0){
                return "dziadek";

            }
            else{
                return "babcia";
            }
        }
    }
    return "nieokreslony";
}


int load(string fileName, Drzewo* drzewo){

    ifstream plik(fileName);
    if (!plik.is_open()) {
        cerr << "Nie można otworzyć pliku!" << std::endl;
        return 1;
    }
    string linia;

    getline(plik, linia);
    istringstream iss(linia);
    int poziomy;

    drzewo->poziomy = poziomy;

    iss >> poziomy;

    vector<Osoba*> osoby;
    vector<vector<int> > dzieci;

    int k = 0;
    vector<int> a;
    while (getline(plik, linia)) {
        istringstream iss(linia);
        string imie;
        iss >> imie;
        Osoba* osoba = new Osoba;

        osoba->imie = imie;

        int liczba;

        iss >> osoba->index;
        iss >> osoba->poziom;
        iss >> osoba->plec;

        if(osoba->poziom == -1){
            iss >> osoba->indexMalzonka;
            dzieci.push_back(a);
            osoba->obca = 1;
        }
        else{
            osoba->obca = 0;
            if(osoba->index == 0){
                drzewo->protoplasta = osoba;
            }

            if(drzewo->aktualny_index <= osoba->index){
                drzewo->aktualny_index = osoba->index + 1;
            }

            dzieci.push_back(a);

            while(iss >> liczba){
                dzieci[k].push_back(liczba);
            }

        }
        k++;

        osoby.push_back(osoba);

    }

    for(int i=0; i<osoby.size(); i++){
        cout << osoby[i]->index << " ";
        for(int j=0;j<dzieci[i].size(); j++){
            cout << dzieci[i][j] << " ";
        }
        cout << endl;
    }

    for(int i=0; i< osoby.size(); i++) {
        if(osoby[i]->obca == 1){
            continue;
        }
        for(int j=0; j<dzieci[i].size(); j++) {
            for(int k=0; k<osoby.size(); k++){
                if(dzieci[i][j] == osoby[k]->index){
                    cout << osoby[i]->imie << " " << osoby[k]->imie << endl;
                    dodaj_rodzica(osoby[i], osoby[k]);
                    dodaj_dziecko(osoby[i], osoby[k]);
                }
            }
        }
    }
    cout << endl;
    for(int i=0; i<osoby.size(); i++){
        if(osoby[i]->poziom == -1){

            Osoba* mazlonek = znajdz_osobe(drzewo, drzewo->protoplasta, osoby[i]->indexMalzonka);
            osoby[i]->poziom = mazlonek->poziom;
            cout << osoby[i]->imie << " " << mazlonek->imie << endl;

            utworz_malzenstwo(mazlonek, osoby[i]);
        }
    }

    plik.close();

    return 0;
}

int save(string nazwaPliku, Drzewo* drzewo){
    cout << "Zapisywanie... " << endl;
    ofstream stream(nazwaPliku);
    if (!stream)
        return 1;

    queue<Osoba*> q;
    q.push(drzewo->protoplasta);

    stream << drzewo->poziomy << "\n";

    while(!q.empty()) {
        Osoba *curr = q.front();
        q.pop();

        if (curr->obca == 1) {
            stream << curr->imie << " " << curr->index << " " << -1 << " "  << curr->plec << " " << curr->malzonek->index << " \n";
        }
        else {
            stream << curr->imie << " " << curr->index << " " << curr->poziom  << " "<< curr->plec << " ";

            if (curr->malzonek != nullptr) {
                q.push(curr->malzonek);
            }

            for (int i = 0; i < curr->osobyPotomne.size(); i++) {
                stream << curr->osobyPotomne[i]->index << " ";
                q.push(curr->osobyPotomne[i]);
            }
            stream << "\n";
        }
    }
    stream.close();


    cout << "Zapisano!" << endl;

    return 0;
}

string znajdz_pokrewienstwoBFS(Osoba* od_, Osoba* do_){
    vector<Osoba*> visited;
    queue<pair <Osoba*, string> > q;
    string state = "probant";

    pair<Osoba*,string> para;
    pair<Osoba*,string> para2;
    para.first = od_;
    para.second = state;

    q.push(para);

    visited.push_back(od_);

    while(!q.empty()){
        pair<Osoba*, string> curr = q.front();
        q.pop();
        visited.push_back(curr.first);

        if(curr.first == nullptr){
            continue;
        }

        cout << curr.first->imie << endl;
        if(curr.first == do_){
            return curr.second;
        }

        if(curr.first->obca == 1){
            continue;
        }
        int found = -1;
        for(int i =0; i<curr.first->osobyPotomne.size(); i++){
            found = -1;
            for(int j=0; j< visited.size(); j++){
                if(visited[j] == curr.first->osobyPotomne[i]){
                    found = 1;
                }
            }

            if(found == -1 && curr.first->osobyPotomne[i] != nullptr){
                visited.push_back(curr.first);
                para.first = curr.first->osobyPotomne[i];
                para.second = zmien_state(curr.second, 1, para.first->plec);
                q.push(para);

                Osoba* malzonek = dodaj_malzonka(para.first);
                if(malzonek != nullptr){
                    para2.first = malzonek;
                    para2.second = zmien_state(curr.second, 1, para.first->plec);
                }
                q.push(para2);
            }
        }
        int found2 = -1;
        found = -1;



        for(int j=0; j< visited.size(); j++){
            if(curr.first->ojciec != nullptr && visited[j] == curr.first->ojciec){
                found = 1;
            }
            if(curr.first->matka != nullptr && visited[j] == curr.first->matka){
                found2 = 1;
            }
        }

        if(found == -1 && curr.first->ojciec != nullptr){
            para.first = curr.first->ojciec;
            para.second = zmien_state(curr.second, -1, para.first->plec);
            q.push(para);
        }

        if(found2 == -1 && curr.first->matka != nullptr){
            para.first = curr.first->matka;
            para.second = zmien_state(curr.second, -1, para.first->plec);
            q.push(para);
        }

    }

}

Osoba* stworz_osobe(int index, int poziom, int obca){

    string imie, nazwisko;
    int dzien, miesiac, rok, plec;

    cout << "Imie: ";
    cin >> imie;
    /*
    cout << "Nazwisko: ";
    cin >> nazwisko;
    cout << "Dzien: ";
    cin >> dzien;
    cout << "Miesiac: ";
    cin >> miesiac;
    cout << "rok: ";
    cin >> rok;
    */

    cout << "Plec: ";
    cin >> plec;

    Osoba* osoba = new Osoba(imie,nazwisko,dzien,miesiac,rok, index, poziom, plec);
    osoba->obca = obca;
    return osoba;
}

void usun_drzewo(Osoba* protoplasta){
    queue<Osoba*> q;
    Osoba* curr;

    q.push(protoplasta);

    while(!q.empty()){
        curr = q.front();
        q.pop();
        if(curr->malzonek != nullptr){
            delete curr->malzonek;
        }
        for(int i=0; i<curr->osobyPotomne.size(); i++){
            q.push(curr->osobyPotomne[i]);
        }
        delete curr;
    }
}

int main() {

    Drzewo* drzewo = new Drzewo;
    drzewo->poziomy = 0;
    drzewo->aktualny_index = 0;
    drzewo->protoplasta = nullptr;
    Osoba* do_;
    Osoba* od_;
    int opcja;
    int index;
    Osoba* osoba;
    int idx1;
    int idx2;
    string nazwaPliku;

    cout << "Podaj opcje: " << endl;
    cout << "1. Dodaj osobę" << endl;
    cout << "2. Sprzwdz osobe" << endl;
    cout << "3. Wypisz drzewo" << endl;
    cout << "4. Usun osobe" << endl;
    cout << "5. Sprawdz pokrewienstwo " << endl;
    cout << "6. Zapisz drzewo" << endl;
    cout << "7. Wczytaj drzewo" << endl;
    cout << "8. Zakoncz program" << endl;

    cin >> opcja;

    while(opcja != 8){
        //system("clear");


        switch(opcja){
            //Dodanie osoby
            case 1:
                //Sprawdzenie i < pokolenia
                if(drzewo->aktualny_index == 0){
                    cout << "Dodajemy protoplaste..." << endl;
                    Osoba* protoplasta = stworz_osobe(drzewo->aktualny_index, 0, 0);
                    drzewo->protoplasta = protoplasta;
                    drzewo->aktualny_index++;
                    osoba->czy_glowny = 1;
                }
                else {
                    int index;
                    
                    //Potomek czy malzonek
                    int opcja;
                    cout << "Potomek czy malzonek (0, 1): ";
                    cin >> opcja;

                    if(opcja == 0) {

                        cout << "Potomek kogo: ";
                        cin >> index;

                        Osoba *rodzic = znajdz_osobe(drzewo, drzewo->protoplasta, index);

                        int poz = rodzic->poziom;
                        poz += 1;

                        osoba = stworz_osobe(drzewo->aktualny_index, poz, 0);
                        dodaj_dziecko(rodzic, osoba);
                        dodaj_rodzica(rodzic, osoba);

                        if (osoba->poziom > drzewo->poziomy) {
                            drzewo->poziomy += 1;
                        }

                        osoba->czy_glowny = 1;

                        drzewo->aktualny_index++;
                    }
                    else{

                        cout << "Malzonek kogo: ";
                        cin >> index;

                        Osoba *malzonek = znajdz_osobe(drzewo, drzewo->protoplasta, index);

                        if(malzonek->malzonek == nullptr){
                            osoba = stworz_osobe(drzewo->aktualny_index, malzonek->poziom, 1);
                            if(malzonek->plec == osoba->plec){
                                cout << "Nie mozna tworzyc homoseksualnych malzenstw" << endl;
                                delete osoba;
                            }
                            else{
                                utworz_malzenstwo(malzonek, osoba);
                                drzewo->aktualny_index++;
                                osoba->czy_glowny = 0;
                            }
                        }
                        else{
                            cout << "Ta osoba ma juz malzonka" << endl;
                        }

                    }
                }

                break;
            //Sprawdzenie osoby
            case 2:
                cout << "Podaj indeks osoby ktora chcesz sprawdzic: ";
                cin >>index;
                osoba = znajdz_osobe(drzewo, drzewo->protoplasta, index);
                wypisz_osobe(osoba);
                break;
            case 3:
                wypisz(drzewo);
                cout << endl;
                break;
            case 4:
                cout<<"Podaj index osoby do usuniecia: ";
                cin >> index;
                usun_osobe(index, drzewo);
                break;

            case 5:
                cout << "Podaj index osoby ktora chcesz pokrewienstwo sprawdzic: ";
                cin >> idx1;
                cout << "Podaj index z ktora: ";
                cin >> idx2;

                od_ = znajdz_osobe(drzewo, drzewo->protoplasta, idx1);
                do_ = znajdz_osobe(drzewo, drzewo->protoplasta, idx2);

                cout <<"Osoba od: " << od_->imie << endl;
                cout <<"Osoba do: " << do_->imie << endl;
                cout << endl;
                cout <<  "Stopien pokrewienstwa " << od_->imie << " z " << do_->imie << ": " << znajdz_pokrewienstwoBFS(od_, do_) << endl;
                cout << endl;

                break;
            case 6:
                cout << "Podaj nazwe pliku do ktorego chcesz zapisac: ";
                cin >> nazwaPliku;
                save(nazwaPliku, drzewo);
                break;
            case 7:
                cout << "Podaj nazwe pliku z ktorego chcesz odczytac: ";
                cin >> nazwaPliku;
                load(nazwaPliku, drzewo);
                break;
            case 8:
                cout << "Program konczy dzialanie... " << endl;
                break;
            default:
                cout << "Nie ma takiej opcji!" << endl;
                break;

        }

        cout << "Podaj opcje: " << endl;
        cout << "1. Dodaj osobę" << endl;
        cout << "2. Sprzwdz osobe" << endl;
        cout << "3. Wypisz drzewo" << endl;
        cout << "4. Usun osobe" << endl;
        cout << "5. Sprawdz pokrewienstwo " << endl;
        cout << "6. Zapisz drzewo" << endl;
        cout << "7. Wczytaj drzewo" << endl;
        cout << "8. Zakoncz program" << endl;
        cin >> opcja;

    }

    usun_drzewo(drzewo->protoplasta);

    delete drzewo;

    cout << "---KONIEC---" << endl;

    return 0;
}
