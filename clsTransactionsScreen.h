#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsDepositScreen.h"
#include"clsWithDrawScreen.h"
#include"clsTrancferScreen.h"
#include"clsTrancferLogScreen.h"


using namespace std;

class clsTransactionsScreen:protected clsScreen
{
private:
	enum   enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eTrancfer=4, eTrancferLog=5,eShowMainMenue = 6
    };
    static short ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }
    static void _ShowDepositScreen() {
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        clsWithDrawScreen::ShowWithDrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        cout << "\n Balances Screen will be here.\n";
    }

    static void _ShowTrancferScreen() {
        clsTrancferScreen::ShowTranferScreen();
    }

    static void  _ShowTrancferLogScreen() {
        clsTrancferLogScreen::ShowTrancferLogIn();
    }

    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowTrancactionScreen();

    }

    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption) {
        switch (TransactionsMenueOption) {
        case enTransactionsMenueOptions::eDeposit:
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eTrancfer:
            system("cls");
            _ShowTrancferScreen();
            _GoBackToTransactionsMenue();
            break;

        case enTransactionsMenueOptions::eTrancferLog:
            system("cls");
            _ShowTrancferLogScreen();
            _GoBackToTransactionsMenue();
            break;
        case enTransactionsMenueOptions::eShowMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }

        }
    }
         
public:
    static void ShowTrancactionScreen() {

        if (!CheckAccessRights(clsUser::enPermissions::pTranactions)) {
            return;
        }



        system("cls");
        clsScreen::_DrawScreenHeader("\t Transation Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Trancfer.\n";
        cout << setw(37) << left << "" << "\t[5] Trancfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption(enTransactionsMenueOptions(ReadTransactionsMenueOption()));
    }

    






};

