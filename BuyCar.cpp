
// https://www.codewars.com/kata/buying-a-car/cpp

class BuyCar
{

  public:
  static std::vector<int> nbMonths(int startPriceOld, 
                                   int startPriceNew, 
                                   int savingperMonth, 
                                   double percentLossByMonth){
  std::vector<int> result(2,0);
    
  double newPriceOld=startPriceOld, 
         newPriceNew=startPriceNew, 
         newPercentLossByMonth=percentLossByMonth, 
         increasePercentEveryTwoMonts = 0.5;
  int howMonths=0;
  
  while ((newPriceOld + (savingperMonth * howMonths)) < newPriceNew){
    howMonths++;
    if (howMonths%2 == 0) newPercentLossByMonth+=increasePercentEveryTwoMonts; // Если четный месяц, то увеличиваем процент удешевления. 
    newPriceOld-=(newPriceOld/100)*newPercentLossByMonth;
    newPriceNew-=(newPriceNew/100)*newPercentLossByMonth;
    };
  
  int savingMoney = static_cast<int> ((newPriceOld + (savingperMonth * howMonths)) - newPriceNew);
  result[0] = howMonths;
  result[1] = savingMoney;
  
  return result;
  }
};
