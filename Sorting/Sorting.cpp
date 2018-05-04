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
using namespace std;


/*
        KONSTANTER
*/
const int LENGTH = 100;
const int MAXINT = 100;


/*
        FUNKSJONSDEKLARASJONER
*/
void createArray(int list[], const int LEN);
void printList(int list[], const int LEN);
void quickSort(int list[], int left, int right);





/*
 * Startpunktet til programmet.  
 */
int main(int argc, char** argv) {

    // En liste med tall som skal sorteres
    int list[LENGTH];

    // Legg inn tall og stokk dem rundt
    createArray(list, LENGTH);
    // Skriv ut innholdet i listen
    printList(list, LENGTH);

    quickSort(list, 0, LENGTH - 1);

    printList(list, LENGTH);


    return 0;
}






/*
 * Fyller en liste med tilfeldige tall.
 */
void createArray(int list[], const int LEN) {
    // Gjør tallene tilfeldige hver gang
    srand(time(nullptr));

    // Legg tallene i listen
    for (int i = 0; i < LEN; i++) {
        list[i] = rand() % MAXINT;
    }
}

/*
 * Skriver ut en liste
 */
void printList(int list[], const int LEN) {

    for (int i = 0; i < LEN; i++) {
        cout << list[i] << ", ";

        if ((i + 1) % 10 == 0) 
            cout << endl; // Skriv ut ti tall på hver linje
    }

    cout << endl;
}

/*
 * Bytter plass på to tall i en array
 */
void swap(int & a, int & b) {
    int temp = a;
    a = b;
    b = temp;
}




/*
 *  SORTERINGSFUNKSJONER
 */





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
