#include <iostream>
#define SIZE 10

using namespace std;
void calculate(double[][3]);

int main()
{
    double arr[SIZE][3];
    calculate(arr);

    cout << "Tablica: " << endl;
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < 3; j++) {
        cout << arr[i][j] << " ";
      }
      cout << endl;
    }
    return 0;
}

void calculate(double arr[][3]) {
  for (int i = 0; i < SIZE; i++) {
    int num = i+1;
      arr[i][0] = num;
      arr[i][1] = num * num;
      arr[i][2] = num * num * num;
  }
  return;
}
