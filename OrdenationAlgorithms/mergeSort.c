#include <stdio.h> 


void merge (int *v, int esq, int meio, int dir) {
    int n1 = meio - esq + 1; 
    int n2 = dir - meio; 

    int L[n1], R[n2];  
    for (int i = 0; i < n1; i++) { 
        L[i] = v[esq + i]; 
    }
    for (int j = 0; j < n2; j++) { 
        R[j] = v[meio + 1 + j]; 
    }

    int i = 0; 
    int j = 0;  
    int k = esq; 

    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            v[k] = L[i]; 
            i++; 
        } else { 
            v[k] = R[j]; 
            j++; 
        }
        k++; 
    }

    while (i < n1) { 
        v[k] = L[i]; 
        i++; 
        k++; 
    }

    while (j < n2) 
    {
        v[k] = R[j]; 
        j++; 
        k++; 
    }
    
}


void mergeSort(int *v, int esq, int dir) { 
    if (esq < dir) { 
        int meio = (esq+dir)/2; 
        mergeSort(v, esq, meio); 
        mergeSort(v, meio+1, dir); 

        merge(v, esq, meio, dir); 
    }
}

int main () { 
    int v[] = {3, 2, 9, 43, 1, 4, 10, 39};
    mergeSort(v, 0, 7); 

    for (int i = 0; i < 8; i++) {
        printf("%d ", v[i]); 
    } 
    return 0; 
}