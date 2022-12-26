#define CURL_STATICLIB
#include <iostream>
#include <string.h>
#include <curl/curl.h>
#include <string>
#include <rapidjson/document.h>
#include <iomanip>
#include <cmath>
#include <array> 
#include <fstream>

using namespace std;


size_t write_callback(void* ptr, size_t size, size_t nmemb, void* userdata) {
    char* data = (char*)ptr;
    size_t data_size = size * nmemb;

    rapidjson::Document d;
    d.Parse(data);

    if (d.HasMember("success") && d["success"].GetBool()) {
        double result = d["result"].GetDouble();
        cout << "The converted amount is: " << ceil(result * 100.0) / 100.0 << endl;
    }
    else {
        cout << "Conversion failed" << endl;
    }

    return data_size;
}


void curlGet(string toCurrency, string fromCurrency, double amount) {
    CURL* curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        ifstream file("apikey.txt");
        string firstLine;
        getline(file, firstLine);

        string url = "https://api.apilayer.com/exchangerates_data/convert?to=" + toCurrency + "&from=" + fromCurrency + "&amount=" + to_string(amount);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, firstLine.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        res = curl_easy_perform(curl);
    }
    curl_easy_cleanup(curl);
}
int main()
{
    string currencies[] = { "USD", "EUR", "GBP", "AUD" };
    int toCurrencyChoice;
    int fromCurrencyChoice;
    bool check = true;
    int arraySize = sizeof(currencies) / sizeof(currencies[0]);
    while (check)
    {
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
        if (fromCurrencyChoice <= arraySize && toCurrencyChoice <= arraySize && (fromCurrencyChoice && toCurrencyChoice) > 0)
        {
            check = false;
        }
        else
        {
            cout << "You entered an invalid value!" << endl << endl;
        }
    }

    double amount;
    cout << "Please enter the amount to convert: ";
    cin >> amount;
    curlGet(currencies[toCurrencyChoice - 1], currencies[fromCurrencyChoice - 1], amount);
    return 0;
}

