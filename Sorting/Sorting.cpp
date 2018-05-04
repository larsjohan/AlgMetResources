/*
    Startpunktet til applikasjonen

    PENSUM: Kap. 8, Kap. 9 (s. 115-120, 122-126, 131), Kap. 11 (s. 154-159) og Kap. 12 (s. 163-168, 171-176)
        - Selection sort
        - Insertion Sort
        - Bubble Sort
        - Shell Sort
        - Distribution Counting
        - Quick Sort
            - Recursion
            - No Recursion
            - Small subfiles
            - Median of Three
        - Heap Sort
        - Merge Sort

*/
#include <iostream>
#include <random>
#include <time.h>
#include <string>
using namespace std;


/*
        KONSTANTER
*/
const int LENGTH = 100;         // Maksimal lengde på array
const int MAXINT = 100;         // Største verdi (+1) på tall i array 
const int SEED = time(nullptr); // Passer på at samme liste blir generert for hver sorteringsmetode


/*
        FUNKSJONSDEKLARASJONER
*/
void createArray(int list[], const int LEN);            // Oppretter en array med tilfeldige tall
void printList(string txt, int list[], const int LEN);  // Skriver ut listen
void swap(int & a, int & b);                            // Bytter plass på to verdier

void selectionSort(int list[], const int LEN);
void InsertionSort();
void bubbleSort(int list[], const int LEN);
void shellSort();
void distributedCounting();
void heapSort();
void mergeSort();
void quickSort(int list[], int left, int right);
void quickSortNonRecursive();
void quickSortSmallSubfiles();
void quickSortMedianOfThree();





/*
 * Startpunktet til programmet.  
 */
int main(int argc, char** argv) {

    // Opprett en sorterbar liste
    int list[LENGTH];
    createArray(list, LENGTH);
    printList("Original liste", list, LENGTH);


    // SELECTIONSORT
    selectionSort(list, LENGTH);
    printList("SELECTIONSORT:", list, LENGTH);

    createArray(list, LENGTH);

    // BUBBLESORT
    bubbleSort(list, LENGTH);
    printList("BUBBLESORT:", list, LENGTH);

    createArray(list, LENGTH);

    // QUICKSORT
    quickSort(list, 0, LENGTH - 1);
    printList("QUICKSORT:", list, LENGTH);


    return 0;
}





/*
 *  SORTERINGSFUNKSJONER
 */





/*
 *  Utfører selectionsort på en gitt array
 */
void selectionSort(int list[], const int LEN) {

    for (int i = 0; i < LEN; i++) {                     // Start på venstre side (i = 0)

        int lowestRemainingIndex = i;                   // Det elementet du er på nå er det minste til nå (her ikke startet å lete)

        for (int j = i + 1; j < LEN; j++) {             // Gå gjennom alle resterende elementer
            if (list[j] < list[lowestRemainingIndex]) { // Dersom det eksisterer ett element som er mindre enn det minste hittil: 
                lowestRemainingIndex = j;               //      Oppdater indeksen, siden dette nå er minst
            }
        }

        swap(list[i], list[lowestRemainingIndex]);      // Bytt plass med det minste elementet som ble funnet
    }

}

/*
 * Utfører bubblesort på en gitt array
 */
void bubbleSort(int list[], const int LEN) {

    for (int i = LEN - 1; i >= 0; i--) {        // Start på slutten av arrayen og tell nedover
        for (int j = 1; j <= i; j++) {          // start til venstr, og sammenlign to og to verdier

            if (list[j - 1] > list[j]) {        // Dersom verdien til venstre er større, bytt plass. Fortsett helt til du når element "i"
                swap(list[j - 1], list[j]);     // elementet med indeks "i" er nå det største elementet av de som ikke er sortert fra før
            }                                   // "i" kan nå telles ned på nytt, og de resterende elementene sorteres på samme måte.
                                                // Alle elementene til høyre for "i" er ferdig sortert i stigende rekkefølge.
        }
    }

}



/*
 * Utfører Quicksort rekursift på en gitt array.
 * Ingen optimalisering.
 */
void quickSort(int list[], int left, int right) {

    if (left < right) {                                         // Avslutt rekursjon dersom det ikke er mer å sortere (left og right peker på samme element)

        int pivot = list[right];                                // Element helt til høyre i arrayen er ofte brukt som pivot pga. optimalisering
        int leftCounter = left - 1;                             // Trekk fra 1 siden denne økes med 1 før sjekk
        int rightCounter = right;                               // Ikke legg til 1 her, siden vi vil starte én plass til venstre for pivot. Samme konsept som for left

        while (leftCounter < rightCounter) {                    // Denne løkken står for partisjonering av arrayen. 
                                                                // Dvs. at alle elementer som er mindre enn pivot flyttes til høyre, og de som er mindre til venstre

            while (list[++leftCounter] < pivot);                // Start fra venstre (fra 0) og sammenlign alle tallene med pivot til man finner ett tall som har en høyere verdi enn pivot

            while (list[--rightCounter] > pivot);               // Start fra høyre (1 til venstre fra pivot) og sammenlign alle allene med pibot til man finner ett tall som har en lavere verdi enn pivot

            if (leftCounter < rightCounter)                     // Bytt plass på de to tallene som er funnet, og gjenta til de to "pekerene" krysser hverandre. 
                swap(list[leftCounter], list[rightCounter]);    // Alle tall på venstre side av leftCounter er nå mindre enn pivot, og alle tall på høyre side av rightCounter er høyere enn pivot
                
        }

        swap(list[leftCounter], list[right]);                   // leftCounter vil alltid peke på det første tallet (fra venstre) som er større enn pivot. Det og pivot kan nå bytte plass, og pivot er ferdig sortert.

        quickSort(list, left, leftCounter - 1);                 // Gjenta dette rekursivt for alle tall på venstre side av den nye plasseringen til pivot (der leftCounter peker)
        quickSort(list, leftCounter + 1, right);                // Gjenta også rekursivt for høyre side av pivot
    }
}



/*
* HJELPEFUNKSJONER
*/



/*
* Fyller en liste med tilfeldige tall.
*/
void createArray(int list[], const int LEN) {
    // Gjør tallene tilfeldige hver gang
    srand(SEED);

    // Legg tallene i listen
    for (int i = 0; i < LEN; i++) {
        list[i] = rand() % MAXINT;
    }
}

/*
* Skriver ut en liste
*/
void printList(string txt, int list[], const int LEN) {

    cout << txt << endl;
    cout << "--------------------------------------\n";

    for (int i = 0; i < LEN; i++) {
        cout << list[i] << ", ";

        if ((i + 1) % 10 == 0)
            cout << endl; // Skriv ut ti tall på hver linje
    }

    cout << "--------------------------------------\n";
}

/*
* Bytter plass på to tall i en array
*/
void swap(int & a, int & b) {
    int temp = a;
    a = b;
    b = temp;
}
