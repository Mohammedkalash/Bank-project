#pragma once
#include<iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListCurenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include"clsUpdateCurrency.h"
#include "clsCurencyCalculaterScreen.h"
using namespace std;
class clsCurrencyExchangScreen :protected clsScreen
{
private:
	enum enMainCurencyExchange {
		enListCurrencies=1,enFindCurency=2,enUpdateCurency=3,
		enCurencyCalculatar=4,enMainMenue=5
	};

	static short _ReadMainMenue() {
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between [1 to 5]? ");

		return Choice;
	}

	static void _ShowListCurecies() {
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}
	static void _ShowFindCurency() {
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
	static void _ShowUpdateCurency() {
		clsUpdateCurrency::ShowUpdateCurrencyRateScreen();
	}
	static void _ShowCurencyCalculater() {
		clsCurencyCalculaterScreen::ShowCurencyCalculaterScreen();
	}
	static void _ShowmainMenue() {
		
	}
	static void _GoBackMainMenue() {
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");
		ShowCurencyExchargeScreen();
	}

	static void PerfromMainMenueOption(enMainCurencyExchange MainCurecyExcharge) {
		switch (MainCurecyExcharge) {

		case enMainCurencyExchange::enListCurrencies:
			system("cls");
			_ShowListCurecies();
			_GoBackMainMenue();
			break;
		case enMainCurencyExchange::enFindCurency:
			system("cls");
			_ShowFindCurency();
			_GoBackMainMenue();
			break;
		case enMainCurencyExchange::enUpdateCurency:
			system("cls");
			_ShowUpdateCurency();
			_GoBackMainMenue();
			break;
		case enMainCurencyExchange::enCurencyCalculatar:
			system("cls");
			_ShowCurencyCalculater();
			_GoBackMainMenue();
			break;
			case enMainCurencyExchange::enMainMenue:
			system("cls");
			
			_GoBackMainMenue();
			break;



		}
	}

public:
	static void ShowCurencyExchargeScreen() {


		system("cls");
		clsScreen::_DrawScreenHeader("\t Curency Exchange Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Curency Exchcnge Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Curencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Curency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Curency.\n";
		cout << setw(37) << left << "" << "\t[4] Curency Calculater.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		PerfromMainMenueOption(enMainCurencyExchange(_ReadMainMenue()));




	}



















};

