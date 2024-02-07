//2022 Podstawy Programowania Projekt
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;
void monthlyAmount(double[][5]);
void displayData(double[][5], string[], int[]);
void totalPrecipitation(double[][5], double[]);
void annualAverage(double[], double[]);
void monthAverage(double[][5], double[]);
void highestPrecipitation(double[][5], int[], string[]);
void editData(double[][5], int[], string[], int, int);

int main()
{
//Deklaracja i inicjalizacja danych
  srand(time(0));
  double data[12][5]; //Tabela z danymi
  string months[12] = {"Sty", "Lut", "Mar", "Kwi", "Maj", "Cze", "Lip", "Sie", "Wrz", "Paz", "Lis", "Gru"};
  int years[5] = {2018, 2019, 2020, 2021, 2022};
  double precipitationSum[5]; //Suma opadow
  double precipitationAverageYear[5]; //Srednia roczna
  double precipitationAverageMonth[12]; //Srednia mieisieczna
  char edit, repeat; //Zmienne kontrolujace menu
  int year, month; //Zmienne przechowujace indeksy do edycji danych

  do {
    //Wywolanie funkcji generujacej losowe wartosci opadow
    monthlyAmount(data);

    do {
      //Naglowek
      cout << "Program do przechowywania wielkosci opadow w latach 2018-2022." << endl;
      cout << "Tabelaryczne zestawienie wielkosci opadow w milimetrach w kazdym miesiacu." << endl;
      cout << endl;

      //Wywolanie funkcji wyswietlajacej tabele z danymi
      displayData(data, months, years);
      cout << endl;

      //Wywolanie funkcji obliczajcej sume opadow
      totalPrecipitation(data, precipitationSum);
      cout << "Suma opadow w kazdym roku w latach 2018-2022 jest nastepujaca:" << endl;
      for (int i = 0; i < 5; i++) {
        cout << years[i] << ": " << precipitationSum[i] << " mm" << setw(8);
      }
      cout << endl << endl;

      //Wywolanie funkcji obliczajacej srednia roczna opadow
      annualAverage(precipitationSum, precipitationAverageYear);
      cout << "Srednia roczna opadow z lat 2018-2022 jest nastepujaca:" << endl;
      for (int j = 0; j < 5; j++) {
        cout << years[j] << ": " << precipitationAverageYear[j] << " mm" << setw(9);
      }
      cout << endl << endl;

      //Wywolanie funkcji obliczajacej srednia opadow z kazdego miesiaca
      monthAverage(data, precipitationAverageMonth);
      cout << "W latach 2018-2022 srednia opadow dla kazdego miesiaca wynosi:" << endl;
      int counter = 0;
      for (int k = 0; k < 12; k++) {
        cout << months[k] << ": " << precipitationAverageMonth[k] << " mm" << setw(9);
        counter++;
        if (counter >= 6) {
          cout << months[k] << ": " << precipitationAverageMonth[k] << " mm";
          cout << endl;
          counter = 0;
        }
      }
      cout << endl;

      //Wywolanie funkcji obliczajacej nawieksza ilosc opadow
      highestPrecipitation(data, years, months);
      cout << endl << endl;

      //Menu umozliwiajace korekte danych lub powtorzenie programu
      cout << "Czy chcesz wprowadzic korekte danych? t/n: ";
      cin >> edit;
      cout << endl;
      if (edit == 't') {
        cout << "Podaj miesiac, dla ktorego chcesz zmienic dane, w postaci liczby (np. Styczen: 1, Luty: 2, Marzec: 3, ...): ";
        cin >> month;
        cout << endl;
        cout << "Podaj rok dla ktorego chcesz zmienic dane (np. 2018, 2019, ...): ";
        cin >> year;
        cout << endl;
        editData(data, years, months, year, month);
        cout << endl << endl;
      }
    } while (edit == 't');

    cout << "Czy chcesz powtorzyc program? Program wylosuje nowe dane." << endl;
    cout << "Wybierz t/n: ";
    cin >> repeat;
    cout << endl << endl;
  } while (repeat == 't');
  return 0;
}

//Funkcja generujaca opady w poszczegolnych miesiacach
void monthlyAmount(double data[12][5]) {
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 5; j++) {
      data[i][j] = double(rand() % 99 + 1)/10;
    }
  }
  return;
}

//Funkcja wyswietlajaca tablice
void displayData(double data[12][5], string months[], int years[]) {
  for (int year = 0; year < 5; year++) {
    cout << setw(16) << years[year];
  }
  cout << endl;
  for (int i = 0; i < 12; i++) {
    cout << months[i];
    for (int j = 0; j < 5; j++) {
      if (j == 0) { //Jesli jest to pierwsza liczba przy nazwie miesiaca, to zmniejszyc szerokosc, aby zrownac kolumny
        cout << setw(12) << setprecision(1) << fixed << data[i][j];
      } else {
        cout << setw(16) << setprecision(1) << fixed << data[i][j];
      }
    }
    cout << endl;
  }
}

//Funkcja obliczajaca sumy opadow w kazdym roku
void totalPrecipitation(double data[12][5], double precipitationSum[]) {
  float sum = 0.0;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 12; j++) {
      sum += data[j][i];
    }
    precipitationSum[i] = sum;
    sum = 0.0;
  }
  return;
}

//Funkcja obliczajaca srednia roczna opadow
void annualAverage(double precipitationSum[], double precipitationAverageYear[]) {
  for (int i = 0; i < 5; i++) {
      precipitationAverageYear[i] = precipitationSum[i]/12;
  }
  return;
}

//Funkcja obliczajaca srednia dla danego miesiaca
void monthAverage(double data[][5], double precipitationAverageMonth[]) {
  float sum = 0.0;
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 5; j++) {
      sum += data[i][j];
    }
    precipitationAverageMonth[i] = sum/5;
    sum = 0.0;
  }
  return;
}

//Funkcja, ktora oblicza najwieksze opady
void highestPrecipitation(double data[][5], int years[], string months[]) {
  double highestAmount = 0.0;
  int index = 0; //Zmienna bedaca indeksem dla tablic dynamicznych
  int counter = 0; //Zmienna zapamietujaca ile razy pojawily sie najwieksze opady

  //Szukamy najwiekszych opadow i ile razy sie pojawily
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 5; j++) {
      if (data[i][j] == highestAmount) {
        counter++;
      } else if (data[i][j] > highestAmount) {
        counter = 1;
        highestAmount = data[i][j];
      }
    }
  }

  //Deklaracja tablic zapamietujacych lata i miesiace z najwiekszymi opadami
  int *highestAmountYear = new int[counter];
  string *highestAmountMonth = new string[counter];

  //Wypelniamy tablice dynamiczne latami i miesiacami
  for (int k = 0; k < 5; k++) {
    for (int l = 0; l < 12; l++) {
      if (data[l][k] == highestAmount && index < counter) {
        highestAmountYear[index] = years[k];
        highestAmountMonth[index] = months[l];
        index++;
      }
    }
  }

  //Wypisujemy dane
  cout << "Najwieksza ilosc opadow wystapila w ";
  for (int m = 0; m < counter; m++) {
    cout << highestAmountMonth[m] << " " << highestAmountYear[m];
    if (m < counter-1) {
      cout << ", ";
    }
  }
  cout << " w ilosci " << highestAmount << " mm.";

  delete[] highestAmountYear;
  delete[] highestAmountMonth;

  return;
}

//Funkcja, ktora szuka w tabeli wybranych danych i dokonuje edycji
void editData(double data[][5], int years[], string months[], int year, int month) {
  int yearIndex = 0;
  int monthIndex = month-1;

  //Szukamy indeksu, pod ktorym znajduje sie wybrany przez uzytkownika rok
  for (int i = 0; i < 5; i++) {
    if(year == years[i]) {
      yearIndex = i;
    }
  }

  cout << "Edytujesz dane dla " << months[monthIndex] << " " << year << "." << endl;
  cout << "Po zatwierdzeniu program wyswietli tabele i obliczenia ze zmienionymi danymi." << endl;
  cout << "Wpisz nowa wartosc (w mm) i zatwierdz Enter: ";
  cin >> data[monthIndex][yearIndex];
  return;
}
