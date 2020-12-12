#include <iostream>
#include <math.h>
#include "main.h"

using std::cin;
using std::cout;


// Constants
#define	MAX_DIVERGE_EXTENT 100


int main() {
  double x0;

  cout << "Enter x0: ";
  cin >> x0;
  fixedpoint(x0);

  return 0;
}


void fixedpoint(double x0) {
  int i = 1;
  double fx, olddiff = 0.0, newdiff, divergeextent = 0.0;

  cout << "Iteration #" << i << ": x0 = " << x0 << "\n";
  i++;
  while (1) {
    fx = equation(x0);
    newdiff = modulus(fx - x0);
    if (newdiff > olddiff) { divergeextent += log(modulus(newdiff - olddiff)); }
    if (divergeextent > MAX_DIVERGE_EXTENT) { cout << "\n" << "Failed to reach root from this point" << "\n"; return; }
    if (newdiff == olddiff) {
      if (modulus(fx-x0) > pow(10, -10)) { cout << "\nCant converge to the root.\n"; return; }
      break;
    }
    olddiff = newdiff;
    x0 = fx;
    cout << "Iteration #" << i << ": x0 = " << x0 << "\n";
    i++;
  }

  cout << "\n" << "Final Result = " << fx << "\n";
}


double equation(double x) {
  return 1 / sin(x);
}


inline double modulus(double x) {
  if (x < 0) x = -x;
  return x;
}
