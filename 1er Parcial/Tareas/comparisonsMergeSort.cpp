#include <iostream>
#include <vector>		

using namespace std;

int contComp = 0;

void Une(vector<int> &d, int ini, int m, int fin){
	
    int i, j, k; 
    int n1 = m - ini + 1; 
    int n2 =  fin - m;

    //create temp arrays 
    int L[n1], R[n2]; 
  
    //Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++) {
        L[i] = d[ini + i]; 
    }

    for (j = 0; j < n2; j++) {
        R[j] = d[m + 1 + j]; 
    }
  
    //Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = ini; // Initial index of merged subarray 
    
    while (i < n1 && j < n2) { 
        
        if (L[i] < R[j]) { 
            d[k] = L[i];
            i++; 
        } 

        else { 
            d[k] = R[j]; 
            j++; 
        } 

        contComp++;
        k++; 
    } 
  
    //Copy the remaining elements of L[], if there are any
    while (i < n1) {
        d[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    //Copy the remaining elements of R[], if there are any
    while (j < n2) { 
        d[k] = R[j]; 
        j++; 
        k++; 
    }
}

void MergeSort (vector<int> &d, int ini, int fin){
	if (ini < fin) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = ini+(fin-ini)/2; 
  
        // Sort first and second halves 
        MergeSort(d, ini, m); 
        MergeSort(d, m+1, fin); 
  
        Une(d, ini, m, fin); 
    } 
}

int main(){

    int n;
    cin >> n;
    vector<int> datos(n);

    for (int i=0; i<n; i++){
        cin>>datos[i];
    }

	cout << endl;
    MergeSort(datos, 0, n-1);
    cout << contComp << endl;

    for (int i=0; i<n; i++){
        cout<<datos[i]<< " ";
    } 

    return 0;
}
