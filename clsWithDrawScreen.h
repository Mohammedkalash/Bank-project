#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;
class clsWithDrawScreen :protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }

public:
    static void ShowWithDrawScreen() {
        string AccountNumber = _ReadAccountNumber();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";

            AccountNumber = _ReadAccountNumber();
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);
        double Amount = 0;
        cout << "\n Please enter withdraw amount?  ";
        Amount= clsInputValidate::ReadDblNumber();
        while (Amount > Client1.AccountBalance) {
            cout << "Amount is Large than balance";
            Amount = clsInputValidate::ReadDblNumber();
        }
        char Answer;
        cout << "\nAre you sure WithDraw y/n?  ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            Client1.WithDraw(Amount);
            cout << "WithDraw Sucssefully\n";
            cout << "\nNew Balance Is: " << Client1.AccountBalance;
        }
        else
            cout << "\nOperation was cancelled.\n";

    }



};

