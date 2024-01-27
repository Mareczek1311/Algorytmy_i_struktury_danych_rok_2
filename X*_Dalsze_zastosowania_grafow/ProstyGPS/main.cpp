#include <iostream>

using namespace std;

void najkrotszaDroga(unordered_map<string, vector<pair<string, int> > > mapa){
    unordered_map<string, int> odleglosc;

    unordered_map<string, int> poprzedni;



}

int main() {

    unordered_map<string, vector<pair<string, int> > > mapa;

    int n;

    cin >> n;
    string start;
    string end;
    int odleglosc;
    pair<string, int> para;
    for(int i=0; i<n; i++){
        cin >> start;
        cin >> end;
        cin >> odleglosc;

        para.first = end;
        para.second = odleglosc;

        mapa[start].push_back(para);

    }
    for (const auto& pair : mapa) {
        std::cout << "Klucz: " << pair.first << std::endl;
        for (const auto& subpair : pair.second) {
            std::cout << "  Wartość: " << subpair.first << ", " << subpair.second << std::endl;
        }
    }



    return 0;
}
