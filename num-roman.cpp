//https://www.codewars.com/kata/roman-numerals-encoder/train/cpp
#include <map>
#include <string>

using namespace std;

string solution(int number){
  map <int, string> decToRoman = {{1, "I"},
                                  {4, "IV"},
                                  {5, "V"},
                                  {9, "IX"},
                                  {10, "X"},
                                  {40, "XL"},
                                  {50, "L"},
                                  {90, "XC"},
                                  {100, "C"},
                                  {400, "CD"},
                                  {500, "D"},
                                  {900, "CM"},
                                  {1000, "M"}};
  string result = "";

  for (auto num = decToRoman.rbegin(); (num != decToRoman.rend()) and (number > 0); num++){
    while (number >= (*num).first){
      number-=(*num).first;
      result+=(*num).second;
    }
  }
  
  return result;
}
