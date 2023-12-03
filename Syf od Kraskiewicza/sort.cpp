#include<iostream>
#include<string>
using namespace std;

int maxLen(string* tab, int size){
    int maxi = tab[0].length();
    int len;
    for(int i=1; i<size; i++){
        len = tab[i].length();
        if(maxi < len){
            maxi = len;
        }
    }
    return maxi;
}

void print_vector(vector<vector<string> > tab){

}

int main(){

    string* A = new string[5];
    string C[5] = {"ola", "ala", "olek", "alicja", "arek"};
    for(int i=0; i < 5; i++){
        A[i] = C[i];
    }

    string* B = new string[5];

    vector<vector<string> > slownik;
    for(int i = 0; i<27; i++){
        slownik.push_back(vector<string>());
    }


    int lenTab = 5;
    int maxi = maxLen(A, lenTab) - 1;
    int z=0;
    while(maxi >= 0){
        z = 0;
        print_vector(slownik);
        for(int i=0; i< lenTab; i++){
            if(A[i].length() - 1 >= maxi){
                int inx = A[i][maxi] - 'a';
                slownik[inx].push_back(A[i]);    
            }
            else{
                slownik[26].push_back(A[i]);
            }
        }    

        while(z < slownik[26].size()){
            B[z] = slownik[26][z];
            z++;
        }

        for(int i=0; i<26; i++){
            for(int j=0; j<slownik[i].size(); j++){
                B[z] = slownik[i][j];
                z++;
            }
        }

  
        A = B;
        maxi--;

        for(int i=0; i<27; i++){
            slownik[i].clear();
        }
        
    }

    for(int i=0; i<lenTab; i++){
        cout << B[i] << endl;
    }
    
    return 0;
}