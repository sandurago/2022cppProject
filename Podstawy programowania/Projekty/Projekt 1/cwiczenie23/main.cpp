#include <iostream>

using namespace std;

int main()
{
  cout << "Program obliczajacy odleglosc punktow od srodka ukladu wspolrzednych oraz zwracajacy liczbe punktow";
  cout << "znajdujacych sie wewnatrz okregu." << endl;
  //Deklaracja danych
  struct Punkt {
    double x;
    double y;
    double odl;
  };
  int N;

  cout << "Podaj liczbe elementow tablicy: ";
  cin >> N;

  Punkt *arr = new Punkt[N];

  delete[] arr;

  return 0;
}

//Funkcja wypelniajaca tablice danymi
void fillArray() {
  for (int i = 0; i < n; i++) {

  }
}
