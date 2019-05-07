#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int getCP(vector<vector<int> > path, vector<int> camino){
    int suma = 0;
    vector<bool> taken(path.size());
    for(int i=1; i<camino.size(); i++){
        taken[camino[i]] = true;
        suma += path[camino[i]][camino[i-1]];
    }
    if(camino.size()==path.size()) return suma+path[camino.back()][0];
    int min = INT_MAX;
    for(int j=1; j<path.size(); j++){
        if(!taken[j] && path[camino.back()][j]<min){
            min = path[camino.back()][j];
        }
    }
    if(min!=INT_MAX){
        suma += min;
    } else {
        return INT_MAX;
    }
    for(int i=1; i<path.size(); i++){
        if(taken[i]) continue;
        min = INT_MAX;
        for(int j=0; j<path.size(); j++){
            if(!taken[j] && path[i][j]<min){
                min = path[i][j];
            }
        }
        if(min!=INT_MAX){
            suma += min;
        } else {
            suma = INT_MAX;
            break;
        }
    }
    return suma;
}

int travel(vector<vector<int> > path,
            priority_queue<pair<int,vector<int> >, 
            vector<pair<int,vector<int> > >, 
            greater<pair<int,vector<int> > > > nodos){
    int costoMin = INT_MAX;
    cout << endl << endl;
    while(!nodos.empty()){
        pair<int,vector<int> > nodo = nodos.top();

        cout << nodos.top().first << " ";

        nodos.pop();
        if(nodo.first > costoMin) continue;
        vector<bool> taken(path.size());
        for(int i=1; i<nodo.second.size(); i++){
            taken[nodo.second[i]] = true;
        }
        if(nodo.second.size() == path.size()){
            int costo = nodo.first;
            cout << costo << " ";
            if(costo < costoMin) costoMin = costo;
            continue;
        }
        for(int i=1; i<path.size(); i++){
            if(!taken[i] && path[nodo.second.back()][i]!=INT_MAX){
                vector<int> newCamino(nodo.second);
                newCamino.push_back(i);
                int newCP = getCP(path,newCamino);
                cout << newCP << " ";
                if(newCP!=INT_MAX) nodos.push(make_pair(newCP,newCamino));
            }
        }
        cout << endl;
    }
    return costoMin;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector< vector<int> > path(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            path[i][j] = path[j][i] = INT_MAX;
        }
    }
    char init, ending;
    int dist;
    for(int i=0; i<m; i++){
        cin >> init >> ending >> dist;
        path[(int)init-'A'][(int)ending-'A'] = dist;
        path[(int)ending-'A'][(int)init-'A'] = dist;
    }

    cout << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << path[i][j] << "\t\t";
        } cout << endl;
    } 

    vector<int> camino;
    camino.push_back(0);
    priority_queue<pair<int,vector<int> > , vector<pair<int,vector<int> > >, greater<pair<int,vector<int> > > > nodos;
    int costPerf = 0;
    int min;
   
    for(int i=0; i<path.size(); i++){
        min = INT_MAX;
        for(int j=0; j<path.size(); j++){
            if(path[i][j]<min){
                min = path[i][j];
            }
        }
        costPerf += min;
    }

    cout << endl << min << " " << costPerf <<" " << camino[0] << endl;
    nodos.push(make_pair(costPerf,camino));

    int output = travel(path,nodos);
    if(output != INT_MAX){
        cout << output << endl;
    } else {
        cout << "INF" << endl;
    }
}
