#include "tp2.h"

tableau::tableau(int e){
    n = e;
    T = new int[n];
    T2= new int[n];
    Temp=0;
    for(int i = 0; i < n; i++) {
        T[i] = rand() % 100;
        T2[i]=T[i];
    }
}

tableau::~tableau(){
    delete[] T;
    
}

void tableau::affiche(){
    for (int i = 0; i < n; i++)
    {
        std::cout<<"T["<<i<<"] ="<<T[i]<<std::endl;
    }   
}
void tableau::copie(){
    for (int i = 0; i < n; i++)
    {
        T2[i]=T[i];
    }
    
}

int tableau::triBulle(){
    count=0;
    int money;
    clockp=clock();
    for (int i=n; i >1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (T2[j]>T2[j+1])
            {
                money=T2[j];
                T2[j]=T2[j+1];
                T2[j+1]=money;
                count++;
            }
        }
    }
    clocka=clock();
    Temp=(double)(clocka - clockp) * 1000.0 / CLOCKS_PER_SEC;
    return count;
    
}
int tableau::triInsertion() {
    int i, j, cle;
    count=0;
    clockp=clock();
    for(i = 1; i < n; i++) {
        cle = T2[i];
        j = i - 1;
        while(j >= 0 && T[j] > cle) {
            T2[j + 1] = T2[j];
            j = j - 1;
        }           
        T2[j + 1] = cle;
        count++;
    }
    clocka=clock();
    Temp=(double)(clocka - clockp) * 1000.0 / CLOCKS_PER_SEC;
    return count;
}

void tableau::transfer(int k) {
    std::swap(T2[0], T2[k-1]); 
}


void tableau::reorganiser(int v, int k) {
    int largest = v;
    int left = 2 * v + 1;  
    int right = 2 * v + 2; 
    
    if (left < k && T2[left] > T2[largest])
        largest = left;
    
    if (right < k && T2[right] > T2[largest])
        largest = right;
    
    if (largest != v) {
        std::swap(T2[v], T2[largest]);
        count++;
        reorganiser(largest, k);
    }
}

int tableau::triTas() {
    count = 0;
    clockp=clock();
    for (int i = n/2 - 1; i >= 0; i--) {
        reorganiser(i, n);
    }
    
    for (int i = n; i > 1; i--) {
        std::swap(T2[0], T2[i-1]);
        count++;
        reorganiser(0, i-1);
    }
    clocka=clock();
    Temp=(double)(clocka - clockp) * 1000.0 / CLOCKS_PER_SEC;
    return count;
}
int tableau::partition(int low, int high) {
    int pivot = T2[high];  // On choisit le dernier élément comme pivot
    int i = low - 1;       // Position de l'élément plus petit
    for (int j = low; j < high; j++) {
        if (T2[j] <= pivot) {
            i++;
            std::swap(T2[i], T2[j]);
            count++;
        }
    }
    std::swap(T2[i + 1], T2[high]);
    count++;
    return i + 1;  // Retourne l'index du pivot
}

void tableau::quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int tableau::triRapide() {
    count = 0;
    clockp = clock();
    quickSort(0, n - 1);
    clocka = clock();
    Temp = (double)(clocka - clockp) * 1000.0 / CLOCKS_PER_SEC;
    return count;
}

int tableau::test(int n) {
    std::cout << std::left << std::setw(5) << "n"
              << std::setw(15) << "Nom du Tri"
              << std::setw(20) << "Nombre d'échanges"
              << std::setw(20) << "Temps d'exécution" << std::endl;
    std::cout << std::string(60, '-') << std::endl;

    for (int i = 0; i < n; i++) {
        copie();
        int echangesBulle = this->triBulle();
        std::cout << std::left << std::setw(5) << i + 1
                  << std::setw(15) << "Tri à bulles"
                  << std::setw(20) << echangesBulle
                  << std::fixed << std::setprecision(6) << Temp << " ms" << std::endl;

        copie();
        int echangesInsertion = this->triInsertion();
        std::cout << std::left << std::setw(5) << i + 1
                  << std::setw(15) << "Tri insertion"
                  << std::setw(20) << echangesInsertion
                  << std::fixed << std::setprecision(6) << Temp << " ms" << std::endl;

        copie();
        int echangesTas = this->triTas();
        std::cout << std::left << std::setw(5) << i + 1
                  << std::setw(15) << "Tri par tas"
                  << std::setw(20) << echangesTas
                  << std::fixed << std::setprecision(6) << Temp << " ms" << std::endl;

        copie();
        int echangesRapide = this->triRapide();
        std::cout << std::left << std::setw(5) << i + 1
                  << std::setw(15) << "Tri rapide"
                  << std::setw(20) << echangesRapide
                  << std::fixed << std::setprecision(6) << Temp << " ms" << std::endl;
    }

    return 0;
}