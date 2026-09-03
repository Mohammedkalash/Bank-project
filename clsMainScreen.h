#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsIUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "LoginRigesterScreen.h"
#include "clsCurrencyExchangScreen.h"


using namespace std;
class clsMainScreen :protected clsScreen
{
private:
	enum enMainMenueOptions {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7,eRegisterLogIn=8, eCurrencyExcharge=9,eExit = 10

	};

	static short _ReadMainMenue() {
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 9]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 9, "Enter Number between [1 to 9]? ");

		return Choice;
	}
	
	static void _GoBackToMainMenue() {
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");
        ShowMainMenueScreen();

	}

    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::PrintcClientRecoredLine();


    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClintesScreen();

    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();

    }

    static void _ShowUpdateClientScreen()
    {
        clsIUpdateClientScreen::ShowUpdateClientScreen();

    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();

    }

    static void _ShowTransactionsMenue()
    {
        clsTransactionsScreen::ShowTrancactionScreen();

    }

    static void _ShowManageUsersMenue()
    {
        clsManageUsersScreen::ShowManageUsersMenue();

    }

    static void _ShowRegisterLogIn(){
        LoginRigesterScreen::ShowRegisterLogIn();
   }

    static void _ShowCurrencyExcharge() {
        clsCurrencyExchangScreen::ShowCurencyExchargeScreen();
    }

    static void _ShowEndScreen()
    {
        _LogOut();
        

    }

    static void _LogOut() {
        CurrentUser = clsUser::Find("", "");
    }

    static void PerfromMainMenueOption(enMainMenueOptions MainMenueOption) {

        switch (MainMenueOption) {
        case enMainMenueOptions::eListClients:
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eRegisterLogIn:
            system("cls");
            _ShowRegisterLogIn();
            _GoBackToMainMenue();
            break;
            case enMainMenueOptions::eCurrencyExcharge:
            system("cls");
            _ShowCurrencyExcharge();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _ShowEndScreen();
            
            break;

        }
    }

    public:
        static void ShowMainMenueScreen() {
            system("cls");
            clsScreen::_DrawScreenHeader("\t\t Main Menue");

            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
            cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
            cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
            cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
            cout << setw(37) << left << "" << "\t[5] Find Client.\n";
            cout << setw(37) << left << "" << "\t[6] Transactions.\n";
            cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
            cout << setw(37) << left << "" << "\t[8] Login Register.\n";
            cout << setw(37) << left << "" << "\t[9] Currency Excharge.\n";
            cout << setw(37) << left << "" << "\t[10] Logout.\n";
            cout << setw(37) << left << "" << "===========================================\n";
            PerfromMainMenueOption(enMainMenueOptions(_ReadMainMenue()));
        

        }





};

