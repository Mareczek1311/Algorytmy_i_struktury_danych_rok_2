#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>


using namespace std;

#define INF 100000

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;

    unordered_map<int, vector<int> > mapa;

    int from;
    int to;
    for(int i=0; i<m; i++){
        cin >> from >> to;
        mapa[from].push_back(to);
    }

    cin >> from >> to;

    vector<int> dist(n, INF);
    vector<int> prev(n, -1);

    queue<pair<int, int> > q;


    pair<int,int> para;
    para.first = -1;
    para.second = from;

    q.push(para);
    bool first = false;
    while(!q.empty()){
        para.first = q.front().first;
        para.second = q.front().second;

        q.pop();

        if(first == false){
            dist[para.second] = 0;
            prev[para.second] = -1;
            pair<int, int> p;
            for(int i=0; i<mapa[para.second].size(); i++){
                p.first = para.second;
                p.second = mapa[para.second][i];
                q.push(p);
            }
            first = true;
        }
        else{
            if(dist[para.first]  >= dist[para.second]){
                continue;
            }
            dist[para.second] = dist[para.first] + 1;
            prev[para.second] = para.first;

            pair<int, int> p;
            for(int i=0; i<mapa[para.second].size(); i++){
                p.first = para.second;
                p.second = mapa[para.second][i];
                q.push(p);
            }
        }


    }



    int curr = prev[to];

    if(curr == -1){
        cout << "nie ma drogi";
        return 0;
    }

    stack<int> st;
    curr = to;
    while(curr != -1){
        st.push(curr);
        curr = prev[curr];
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }


    return 0;
}
