#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <sstream>


using namespace std;

#define d 256

void search(string pat, string txt, int q)
{
    int M = pat.length();
    int N = txt.length();
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;

    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= N - M; i++) {

        if (p == t) {
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }


            if (j == M)
                cout << "Pattern found at index " << i
                     << endl;
        }

        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            if (t < 0)
                t = (t + q);
        }
    }
}

void brute_force_search(string txt, string pattern){
    int n = pattern.length();
    int m = txt.length();
    int j;
    for(int i=0; i<m; i++){
        for(j=0; j<n; j++){
            if(tolower(pattern[j]) != tolower(txt[j+i])){
                break;
            }
        }
        if(j == n){
            cout << "Pattern found at index: " << i << endl;
        }
    }
}

void brute_force_oblicz_statystyki(unordered_map<char, int>& znaki, unordered_map<string, int>& wyrazy, string linia){
    int n = linia.size();
    istringstream strumien(linia);
    string slowo;
    vector<std::string> slowa;

    while (strumien >> slowo) {
        for(int i =0; i<slowo.length(); i++){
            slowo[i] = tolower(slowo[i]);
        }

        slowa.push_back(slowo);
    }

    for(int i=0; i<slowa.size(); i++){
        if (wyrazy.find(slowa[i]) == wyrazy.end()) {
            wyrazy[slowa[i]] = 1;
        }
        else{
            wyrazy[slowa[i]] += 1;
        }
    }

    for(int i=0; i<n; i++){
        znaki[linia[i]] += 1;
    }


}

void wyswietl_opcje(){
    cout << "Podaj Opcje:" << endl;
    cout << "1. Wczytaj tekst" << endl;
    cout << "2. Wypisz tekst" << endl;
    cout << "3. Wyszukaj wyrazu/frazy" << endl;
    cout << "4. Oblicz statystyki tekstu" << endl;
    cout << "5. Slownik T9" << endl;
    cout << "0. Zakoncz program" << endl;
}


string czytaj_tekst(fstream& my_file, int& flag){
    string line;
    char znak;
    if (!my_file) {
        cout << "Plik nie istnieje!";
    }

    int licznik = 0;
    string fragment;
    while(my_file.get(znak) && (znak != ' ' || licznik <= 16) && znak != '\n'){
        fragment += znak;
        licznik+=1;
    }

    if(znak == '\n'){
        flag = 1;
    }
    else{
        flag = 0;
    }

    return fragment;
}

int levenstein(string a, string b){

    int mini;

    int m = a.length() + 1;
    int n = b.length() + 1;

    int arr[m][n];

    arr[0][0] = 0;
    for(int i=1; i<n; i++){
        arr[0][i] = i;
    }
    for(int i=1; i<m; i++){
        arr[i][0] = i;
    }

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(a[i-1] != b[j-1]){
                mini = min(arr[i][j-1], arr[i-1][j]);
                mini = min(mini, arr[i-1][j-1]);
                arr[i][j] = mini+1;
            }
            else{
                arr[i][j] = arr[i - 1][j - 1];
            }
        }
    }

    return arr[m-1][n-1];
}

vector<string> utworz_slownik(string nazwaSlownika){
    string slowo;
    fstream plik;
    vector<string> slownik;
    plik.open(nazwaSlownika);

    if (!plik) {
        cout << "Plik nie istnieje!";
    }

    while(getline(plik, slowo)){
        slownik.push_back(slowo);
    }

    plik.close();

    return slownik;
}

int main() {


    unordered_map<char, int> hm_znaki;
    pair<char, int> a;

    string nazwaSlownika = "slownik2.txt";
    vector<string> slownik = utworz_slownik(nazwaSlownika);

    for(int i=0; i<127; i++){
        a.first = i;
        a.second = 0;
        hm_znaki.insert(a);
    }

    unordered_map<string, int> hm_wyrazy;

    int opcja;
    fstream plik;

    fstream my_file;
    string nazwaPliku;
    string line;
    string fraza;
    string ret;
    string slowo;
    pair<int, string> para;
    int q = INT_MAX;

    int i = 0;

    int max = -1;
    int flag;

    vector<pair<int, string> > pary;
    int mini = -1;
    wyswietl_opcje();
    cin >> opcja;

    while(opcja != 0){
        switch(opcja){
            case 1:
                cout << "Podaj nazwe pliku: ";
                cin >> nazwaPliku;
                break;
            case 2:
                plik.open(nazwaPliku);
                while(!plik.eof()){
                    cout << czytaj_tekst(plik, flag);
                    if(flag == 1){
                        cout << endl;
                    }
                    else{
                        cout << " ";
                    }
                }
                cout << endl;
                plik.close();

                break;
            case 3:
                cout << "Podaj wyraz lub fraze: ";
                cin >> fraza;

                plik.open(nazwaPliku);
                i=0;
                while(!plik.eof()){
                    ret =  czytaj_tekst(plik, flag);

                    cout << "W linii " << i << ": " << endl;
                    brute_force_search(ret, fraza);
                    if(flag == 1){
                        i++;
                    }
                }

                plik.close();

                break;
            case 4:
                cout << "Obliczanie statystyk tekstu...";

                plik.open(nazwaPliku);
                while(!plik.eof()){
                    ret =  czytaj_tekst(plik, flag);

                    brute_force_oblicz_statystyki(hm_znaki, hm_wyrazy, ret);
                }
                plik.close();

                for (const auto& a : hm_znaki) {
                    if(a.second > max || max == -1){
                        max = a.second;
                    }
                    if((a.second < mini || mini == -1) && a.second != 0){
                        mini = a.second;
                    }
                }

                cout << "Statystyki: ";

                cout << "---Statystyki tekstu---" << endl;
                cout << "Minimum: " << endl;
                if(mini == -1){
                    cout << "Brak"<< endl;
                }
                else{
                    for (const auto& a : hm_znaki) {
                        if(a.second == mini){
                            cout << a.first << " " << a.second << endl;
                        }
                    }
                }

                cout << "Maksimum: " << endl;

                if(max == -1){
                    cout << "Brak" << endl;
                }
                else{
                    for (const auto& a : hm_znaki) {
                        if(a.second == max){
                            cout << a.first << " " << a.second << endl;
                        }
                    }
                }

                cout << "------" << endl;
                cout << "---Statystyki wyrazow---" << endl;

                max = -1;

                for (const auto& a : hm_wyrazy) {
                    if(a.second > max || max == -1){
                        max = a.second;
                    }
                    if((a.second < mini || mini == -1) && a.second != 0){
                        mini = a.second;
                    }
                }

                cout << "Minimum: " << endl;
                if(mini == -1){
                    cout << "Brak"<< endl;
                }
                else{
                    for (const auto& a : hm_wyrazy) {
                        if(a.second == mini){
                            cout << a.first << " " << a.second << endl;
                        }
                    }
                }

                cout << "Maksimum: " << endl;

                if(max == -1){
                    cout << "Brak" << endl;
                }
                else{
                    for (const auto& a : hm_wyrazy) {
                        if(a.second == max){
                            cout << a.first << " " << a.second << endl;
                        }
                    }
                }

                cout << "---KONIEC STATYSTYK---";
                break;
            case 5:

                cout << "Podaj slowo: ";
                cin >> slowo;

                cout << "Obliczanie..." << endl;

                for(int i=0; i<slownik.size(); i++){
                    para.first = levenstein(slowo, slownik[i]);
                    para.second = slownik[i];
                    pary.push_back(para);
                    if(mini == -1){
                        mini = pary[i].first;
                    }
                    else{
                        mini = min(mini, pary[i].first);
                    }
                }


                cout << "Sugerowane poprawki: " << endl;

                for(int i=0; i<pary.size(); i++){
                    if(pary[i].first == mini){
                        cout << pary[i].second << endl;
                    }
                }
                pary.clear();

                cout << "------" << endl;

                break;
            default:
                cout << "Brak takiej opcji!" << endl;
                break;
        }

        wyswietl_opcje();
        cin >> opcja;
    }

    cout << "---KONIEC PROGRAMU---";


    return 0;
}
