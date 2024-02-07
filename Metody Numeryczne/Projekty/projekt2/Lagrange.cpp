#include "Lagrange.h"

double laGrange(int nodeNum, double x[], double y[], double xV) {
  double f = 0;
  for (int i = 0; i < nodeNum; i++) {
    int j = 0;
    double product = 1;
    for (int j = 0; j < nodeNum; j++) {
      if (j != i) {
        double expression;
        expression = (xV - x[j])/(x[i] - x[j]);
        product *= expression;
      }
    }
    f += y[i] * product;
  }
  return f;
}

