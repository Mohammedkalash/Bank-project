#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsUser.h"

class LoginRigesterScreen :protected clsScreen
{

private:
	
    static void PrintRegisterLogIn(clsUser::stLoginRegisterRecord LoginRegister) {
		
			cout << setw(8) << left << "" << "| " << setw(15) << left;
			cout << setw(8) << left << "" << "| " << setw(35) << left<< LoginRegister.Date;
			cout << "| " << setw(20) << left << LoginRegister.UserName;
			cout << "| " << setw(20) << left << LoginRegister.Password;
			cout << "| " << setw(10) << left << LoginRegister.Permissions;

    }



public:
	static void ShowRegisterLogIn() {

		if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister)) {
			return;
		}
		vector<clsUser::stLoginRegisterRecord>vLoginRegister = clsUser::_LoadRigestrDataFromFile();
		clsScreen::_DrawScreenHeader("Rigester Login Screen");

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vLoginRegister.size() == 0) {
			cout << "\t\t\t\tNo Logins Available In the System!";
		}
		else

			for (clsUser::stLoginRegisterRecord& R : vLoginRegister) {
				PrintRegisterLogIn(R);
				cout << endl;
	    	}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;



		

	}



};

