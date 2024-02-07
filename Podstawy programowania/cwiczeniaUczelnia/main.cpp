//Sandra Liu, nr indeksu 156146, gr. D2
#include <iostream>
#include <iomanip>

using namespace std;
//Deklaracje funkcji
void getData(int&, int&);
void fillArray(int[], int[], int, int, int);
void displayArray(int[], int);
void displayArray(int[], int);
int squaresX(int[], int);
void maxElement(int[], int, int&, int*);
void EvenElements(int[], int[], int);

int main()
{
  char choice;
  do {
  srand(time(0));
  const int SIZE = 50;
  int p, k, maximum, ind;
  int X[SIZE];
  int Y[SIZE];
  //Pobranie danych
  getData(p, k);
  //Wypelnienie tablicy
  fillArray(X, Y, SIZE, p, k);
  cout << "Tablica z wartosciami X" << endl;
  //Wyswietlenie tablicy X
  displayArray(X, SIZE);
  cout << "Tablica z wartosciami Y" << endl;
  //Wyswietlenie tablicy Y
  displayArray(Y, SIZE);
  //Suma kwadratow liczb nieparzystych
  cout << "Suma kwadratow liczb nieparzystych z tablic X rowna sie: " <<  squaresX(X, SIZE);
  cout << endl;
  //Element maksymalny i indeks
  maxElement(Y, SIZE, maximum, &ind);
  cout << "Maksymalny element w tablicy Y to: " << maximum << endl;
  cout << "Jego ostatni indeks to: " << ind << endl;
  cout << endl;
  //Elementy parzyste i tablica P
  EvenElements(X, Y, SIZE);
  cout << "Czy powtorzyc? Tak -'t'/Nie - 'n': ";
  cin >> choice;
  cout << endl;
  } while (choice == 't');
  return 0;
}

//Funkcja pobierajaca poczatek i koniec przedzialu
void getData(int& p, int& k) {
  cout << "Operacje na tablicach." << endl;
  cout << endl;
  cout << "Podaj poczatek przedzialu: ";
  cin >> p;
  cout << "Podaj koniec przedzialu: ";
  cin >> k;
  cout << endl;
  return;
}

//Funkcja wypelniajaca tablice
void fillArray(int X[], int Y[], int SIZE, int p, int k) {
  for (int i = 0; i < SIZE; i++) {
    X[i] = p + rand() % (k - p +1);
    Y[i] = p + rand() % (k - p +1);
  }
  return;
}

//Funkcja wyswietlajaca tablice
void displayArray(int arr[], int SIZE) {
  int counter = 0;
  for (int i = 0; i < SIZE; i++) {
    cout << setw(5) << arr[i];
    counter++;
    if (counter == 5) { //Przejscie do nowej linii
      cout << endl;
      counter = 0;
    }
  }
  cout << endl << endl;
  return;
}

//Funkcja obliczajaca kwadraty liczb nieparzystych z tablicy X
int squaresX(int arr[], int SIZE) {
  int sum = 0;
  for (int i = 0; i < SIZE; i++) {
    if (arr[i] % 2 != 0) {
      int xSquare = arr[i] * arr[i];
      sum += xSquare;
    }
  }
  return sum;
}

//Funkcja obliczajaca element maksymalny oraz index w tablicy Y
void maxElement(int Y[], int SIZE, int& maximum, int* ind) {
  maximum = Y[0];
  for (int i = 0; i < SIZE; i++) {
    if (Y[i] >= maximum) {
      maximum = Y[i];
      *ind = i;
    }
  }
  return;
}

//Funkcja obliczajaca elementy parzyste - tworzy, wypelnia, wyswietla tablice P
void EvenElements(int X[], int Y[], int SIZE) {
  int pSIZE = 0; //Inicjalizacja rozmiaru dla tablicy P
  int pIndex = 0; //Inicjalizacja indeksu dla tablicy P

  //Policzenie ilosci elementow parzystych w tablicy X i Y
  for (int i = 0; i < SIZE; i++) {
    if (X[i] % 2 == 0) {
      pSIZE++;
    }
    if(Y[i] % 2 == 0) {
      pSIZE++;
    }
  }

  int* P = new int[pSIZE];

  //Wypelnienie tablicy P wartosciami parzystymi z tablicy X i Y
  for (int k = 0; k < SIZE; k++) {
    if (X[k] % 2 == 0) {
      P[pIndex] = X[k];
      pIndex++;
    }
    if (Y[k] % 2 == 0) {
      P[pIndex] = Y[k];
      pIndex++;
    }
  }

  cout << "Liczba elementow parzystych w obu tablicach to: " << pSIZE << endl;
  cout << "Tablica P z liczbami parzystymi z tablic X oraz Y " << endl;
  displayArray(P, pSIZE);
  delete[] P;
  return;
}
