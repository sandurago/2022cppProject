//Sandra Liu, nr indeksu 156146, gr.D2
#include <iostream>
#include <iomanip>

using namespace std;
//Deklaracje funkcji
void getNodeNumber(int&, double&);
void getValues(int, double[], double[]);
double laGrange(int, double[], double[], double);
void approximation(int, double, double[][4], double[], double[]);

int main()
{
  cout << "Program do wyznaczania wartosci interpolowanych, ekstrapolowanych oraz wyznaczania wielomianu aproksymujacego" << endl;
  cout << "drugiego stopnia dla funkcji dyskretnej." << endl << endl;
  int nodeNum; //Ilosc wezlow
  double xV; //Szukana niewiadoma
  //Pobranie liczby wezlow interpolacji oraz niewiadomej
  getNodeNumber(nodeNum, xV);
  //Zadeklarowanie tablic z danymi
  double x[nodeNum];
  double y[nodeNum];
  double matrix[3][4];
  double increment = 0.01; // Wielkosc kroku

  cout << endl;
  //Pobranie wezlow
  getValues(nodeNum, x, y);
  cout << endl;

  cout << "Wartosc funkcji f(x) w punkcie " << xV << " jest rowna: " << setprecision(5) << laGrange(nodeNum, x, y, xV)<< endl << endl;
  cout << "Wielomian aproksymujacy drugiego stopnia funkcji f(x) to: p(x) = ";
  approximation(nodeNum, xV, matrix, x, y);
  cout << endl << endl;

  //Interpolacja
  cout << "Wartosci interpolowane (x, y): " << endl;
  for (double i = x[0]; i < x[nodeNum - 1] + increment; i+=increment) {
    cout << setprecision(3) << fixed << "(" << i << ", " << laGrange(nodeNum, x, y, i) << ")" << endl;
  }

  cout << endl;
  //Sprawdzenie czy xV lezy poza funkcja, jesli tak, wyswietlic wartosci ekstrapolacji
  if (xV < x[0] || xV > x[nodeNum-1]) {
    //Ekstrapolacja
    cout << "Wartosci ekstrapolowane (x, y): " << endl;
    // Jesli xV jest dodatnie
    if(xV > x[nodeNum-1]) {
      for (double i = x[nodeNum-1] + increment; i <= xV; i+=increment) {
        cout << setprecision(3) << fixed << "(" << i << ", " << laGrange(nodeNum, x, y, i) << ")" << endl;
      }
    } else {
      // Jesli xV jest ujemne
      for (double i = xV; i <= x[0]; i+=increment) {
        cout << setprecision(3) << fixed << "(" << i << ", " << laGrange(nodeNum, x, y, i) << ")" << endl;
      }
    }
  }
  cout << "Wpisz dowolny znak, aby zakonczyc: ";
  char exit;
  cin >> exit;
  return 0;
}

//Funkcja pobierajaca liczbe wezlow interpolacji oraz x
void getNodeNumber(int& nodeNum, double& xV) {
  cout << "Podaj liczbe wezlow interpolacji: ";
  cin >> nodeNum;
  cout << "Podaj wartosc szukanego x: ";
  cin >> xV;
  return;
}

// Funkcja pobierajaca argumenty i wartosci
void getValues(int nodeNum, double x[], double y[]) {
  cout << "Podaj wezly interpolacji:" << endl;
 for (int i = 0; i < nodeNum; i++) {
    cout << "x" << i+1 << " = ";
    cin >> x[i];
    cout << "y" << i+1 << " = ";
    cin >> y[i];
  }
}

//Metoda Lagrange'a
double laGrange(int nodeNum, double x[], double y[], double xV) {
  double f = 0.0;
  for (int i = 0; i < nodeNum; i++) {
    double polynomial = 1;
    for (int j = 0; j < nodeNum; j++) {
      if (j != i) {
        // Obliczenie wielomianow Lagrange'a
        double expression;
        expression = (xV - x[j])/(x[i] - x[j]);
        polynomial *= expression;
      }
    }
    // Pomnozenie wielomianu przez wartosc funkcji
    f += y[i] * polynomial;
   }
  return f;
}

//Aproksymacja funkcja kwadratowa
void approximation(int nodeNum, double xV, double matrix[][4], double x[], double y[]) {
  double results[3] = {0.0, 0.0, 0.0};
  //Wyliczenie pochodnych i wpisanie ich do macierzy
  for (int i = 0; i < nodeNum; i++) {
    //Po a
    matrix[0][0] += x[i] * x[i] * x[i] * x[i];
    matrix[0][1] += x[i] * x[i] * x[i];
    matrix[0][2] += x[i] * x[i];
    matrix[0][3] += x[i] * x[i] *(y[i]);
    //Po b
    matrix[1][0] += x[i] * x[i] * x[i];
    matrix[1][1] += x[i] * x[i];
    matrix[1][2] += x[i];
    matrix[1][3] += x[i]* y[i];
    //Po c
    matrix[2][0] += x[i] * x[i];
    matrix[2][1] += x[i];
    matrix[2][2] += 1;
    matrix[2][3] += y[i];
  }

  // Metoda Gaussa
  for (int j = 0; j < 2; j++){
    // Petla: Tworzenie wspolczynnika
    for (int k = j; k < 2; k++) {
      double coefficient = -(matrix[k+1][j]/matrix[j][j]);
      // Petla: Mnozenie kolumny przez wspolczynnik
      for (int m = 0; m < 4; m++) {
      matrix[k+1][m] += (coefficient * matrix[j][m]);
      }
    }
  }

  // Petla wyliczajaca niewiadome a, b, c
  for (int g = 2; g >= 0; g--) {
    double sum = 0.0;
    // Policzenie sumy iloczynow
    for (int h = 2; h >= 0; h--) {
      sum += matrix[g][h] * results[h];
    }
    // Wpisanie wyniku z dzielenia do tablicy (obliczenie niewiadomej)
    results[g] = (matrix[g][3] - sum)/matrix[g][g];
  }

  //Wielomian aproksymacyjny
  cout << setprecision(2) << fixed << results[0] << "x^2 + " << results[1] << "x + " << results[2];

  return;
}
