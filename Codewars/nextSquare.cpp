//https://www.codewars.com/kata/56269eb78ad2e4ced1000013/cpp/

#include <cmath>

using namespace std;

long int findNextSquare(long int sq) {
  double firstSquare = sqrt(sq);
  int trunkedFirstSquare = trunc(firstSquare);
  if (pow(trunkedFirstSquare, 2) == sq) return pow(trunkedFirstSquare + 1, 2);
  else return -1;
}
