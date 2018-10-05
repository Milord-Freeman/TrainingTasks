//https://www.codewars.com/kata/square-into-squares-protect-trees/train/cpp
#include <cmath>
#include <vector>

using namespace std;

class Decomp
{
  public:
  static vector<long long> decompose(long long number);
  static bool isSquare(long long number);
  static vector<long long> recDecompose(long long difference, long long prevSquare);
};

vector<long long> Decomp::decompose(long long number){
  vector<long long> resultVector;
  long long squaredNumber = pow(number, 2);
  while (resultVector.empty() and number>0) {
    number--;
    resultVector = recDecompose(squaredNumber - pow(number, 2), number);
  }
  return resultVector;
}

vector<long long> Decomp::recDecompose(long long difference, long long prevSquare){
  vector<long long> result;
  
  if (isSquare(difference)){ 
    result.push_back(sqrt(difference));
    return result;
  } 
  else {
    for (long long i = prevSquare - 1; i > 0; i--){
      if (difference - pow(i, 2) > 0) {
        result = recDecompose(difference - pow(i, 2), i);
      }
    }
  }
  result.clear();
  return result; 
}

bool Decomp::isSquare(long long number){
  if ((number > 0) and (pow(trunc(sqrt(number)), 2) == number)) return true; else return false;
}
