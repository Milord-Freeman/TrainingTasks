//https://www.codewars.com/kata/square-into-squares-protect-trees/train/cpp
#include <cmath>
#include <vector>

using namespace std;

class Decomp
{
  public:
  static vector<long long> decompose(long long n);
  static bool isSquare(long long number);
  static vector<long long> recDecompose(long long difference, long long prevSquare);
};

vector<long long> Decomp::decompose(long long n){
  vector<long long> resultVector = recDecompose(pow(n, 2)-pow(n-1, 2), n);
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
      result = recDecompose(difference - pow(i, 2), i);
      if (!result.empty()) return result;
    }
  }
  return result; 
}

bool Decomp::isSquare(long long number){
  if (pow(trunc(sqrt(number)), 2) == number) return true; else return false;
}
