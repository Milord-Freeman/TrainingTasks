//https://www.codewars.com/kata/5287e858c6b5a9678200083c/cpp/

#include <vector>

int powerTo(int base, int power){
  if (power>1) return (base * powerTo(base, power-1)); else if (power==0) return 1; else return base;
}

bool narcissistic( const int value ){
  int sumOfPoweredDigits = 0;
  int buffer = value;
  int power = 0;
  std::vector<int> digits;
  
  while (buffer){
    power++;
    digits.push_back(buffer%10);
    buffer/=10;
  }
  
  for (auto digit : digits){
    sumOfPoweredDigits += powerTo(digit, power);
  }
  
  if (sumOfPoweredDigits == value) return true;
  else return false;
}
