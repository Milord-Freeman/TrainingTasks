class BuyCar
{

  public:
  static std::vector<int> nbMonths(int startPriceOld, 
                                   int startPriceNew, 
                                   int savingperMonth, 
                                   double percentLossByMonth){
  std::vector<int> result(2,0);
    
  int newPriceOld=startPriceOld, newPriceNew=startPriceNew, howMonths=0;
  double newPercentLossByMonth=percentLossByMonth, increasePercentEveryTwoMonts = 0.5;
  
  while ((newPriceOld + (savingperMonth * howMonths)) < newPriceNew){
    howMonths++;
    if (!howMonths%2) newPercentLossByMonth+=increasePercentEveryTwoMonts; // Если четный месяц, то увеличиваем процент удешевления. 
    int bufferForPercent = 1-(newPercentLossByMonth/100); // Остаток вычитания из 100 процентов процента удешевления, переведенный в норм вид для умножения.
    newPriceOld*=bufferForPercent;
    newPriceNew*=bufferForPercent;
    };
  
  result[0] = howMonths;
  result[1] = static_cast<int> (newPriceOld + (savingperMonth * howMonths)) - newPriceNew;
  
  return result;
  }
};
