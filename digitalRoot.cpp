
https://www.codewars.com/kata/sum-of-digits-slash-digital-root/train/cpp

bool isSingleDigit(int n){
  int integralPart = n/10;
  if (integralPart) return false; 
  else return true;
}

int digital_root(int number)
{
  if (isSingleDigit(number)){ return number; }
  else {
    int newSum = 0;
    while (number != 0) {
      newSum += number % 10;
      number /= 10;
    }
    return digital_root(newSum);}
}
