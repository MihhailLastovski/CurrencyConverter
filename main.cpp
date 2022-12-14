#include <iostream>
using namespace std;

double convert(double amount, double exchangeRate)
{
  double convertedAmount = amount * exchangeRate;
  return convertedAmount;
}

int main()
{
  string currencies[] = {"USD", "EUR", "GBP", "AUD"};
  double exchangeRates[] = {1.0, 0.94, 0.8, 1.45};
  int toCurrencyChoice;
  int fromCurrencyChoice;

  cout << "Please choose a currency to convert to:" << endl;
  for (int i = 0; i < 4; i++)
  {
    cout << i + 1 << ". " << currencies[i] << endl;
  }
  cin >> toCurrencyChoice;

  cout << "Please choose a currency to convert from:" << endl;
  for (int i = 0; i < 4; i++)
  {
    cout << i + 1 << ". " << currencies[i] << endl;
  }
  cin >> fromCurrencyChoice;

  double amount;
  cout << "Please enter the amount to convert: ";
  cin >> amount;

  double toDollar = amount / exchangeRates[fromCurrencyChoice - 1];
  double convertedAmount = convert(toDollar, exchangeRates[toCurrencyChoice - 1]);

  cout << "The converted amount is: " << convertedAmount << endl;

  return 0;
}
