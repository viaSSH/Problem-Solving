#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

int N; int M;
ll bo[1001][1001];
ll INF = 99999999999;
bool visited[1001];
ll d[1001];

int getSmall() {
    ll min = INF;
    int index = 0;
    for(int i=1 ; i<=N ; i++) {
        if(d[i] < min && !visited[i]) {
            min = d[i];
            index = i;

        }
    }
    return index;
}

void dij(int start) {
    for(int i=1 ; i<=N ; i++) {
        d[i] = bo[start][i];
    }
    visited[start] = false;

    for(int i=1 ; i<N-1 ; i++) {
        int current = getSmall();
        visited[current] = true;
        for(int j=1 ; j<=N ; j++) {
            if(!visited[j]) {
                if(d[current] + bo[current][j] < d[j]) {
                    d[j] = d[current] + bo[current][j];
                }
            }
        }
    }
}

int main() {
    
    int start, end;


    cin >> N; cin >> M;
    for(int i=1 ; i<=N ; i++) {
        for(int j=1 ; j<=N ; j++) {
            bo[i][j] = INF;
        }
    }
    for(int i=1 ; i<=N ; i++) {
        // bo[i][i] = 0;
    }
    for(int i=0 ; i<M ; i++) {
        ll f, t, c;
        cin >> f >> t >> c;
        bo[f][t] = min(bo[f][t], c);
        // bo[t][f] = min(bo[t][f], c);
    }
    cin >> start >> end;

    dij(start);
    // for(int k=1 ; k<=N ; k++) {
    //     for(int i=1 ; i<=N ; i++) {
    //         for(int j=1 ; j<=N ; j++) {
    //             bo[i][j] = min(bo[i][j], bofv[i][k] + bo[k][j]); 
    //         }
    //     }
    // }
    
    // cout << bo[start][end] << endl;
    cout << d[end] << endl;
    // cout << bo[end][start] << endl;

    return 0;
}

