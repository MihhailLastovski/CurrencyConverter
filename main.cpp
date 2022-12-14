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
  double exchangeRates[] = {1.0, 1.06, 1.24, 1.46};
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

  double exchangeRate = exchangeRates[fromCurrencyChoice - 1] / exchangeRates[toCurrencyChoice - 1];
  double convertedAmount = convert(amount, exchangeRate);

  cout << "The converted amount is: " << convertedAmount << endl;

  return 0;
}
