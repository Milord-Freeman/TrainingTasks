//https://www.codewars.com/kata/square-into-squares-protect-trees/train/cpp
#include <cmath>
#include <vector>

using namespace std;

class Decomp
{
  public:
  static std::vector<long long> decompose(long long n);
  static bool isSquare(long long number);
  static long long recursivelyDecompose(long long n);
};

vector<long long> Decomp::decompose(long long n){
  vector<long long> result;
  //TODO: some code here
  return result; 
}

bool Decomp::isSquare(long long number){
  if (pow(trunc(sqrt(number)), 2) == number) return true; else return false;
}


testing(50, {1,3,5,8,49});
        testing(44, {2,3,5,7,43});
        testing(2, {});
