#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
double x;
int anzahl;
vector<double> argumente;
vector<double> wahrscheinlichkeiten;

void input() {
	cout << "Wie viele Werte möchtest du jeweils eintragen?: " << endl;
	cin >> anzahl;
	cout << "Zahlen: ";
	for (int i = 0; i < anzahl; i++) {

		cin >> x;
		argumente.push_back(x);
	}
	
	for (int i = 0; i < anzahl; i++) {
		cout << to_string(argumente[i]) + " ";
	}
	
	x = 0;

	cout << "\nWahrscheinlichkeiten: ";
	for (int i = 0; i < anzahl; i++) {
		cin >> x;
		wahrscheinlichkeiten.push_back(x);
	}
	for (int i = 0; i < anzahl; i++) {
		cout << to_string(wahrscheinlichkeiten[i]) + " ";
	}
}

void calc() {
	//Müüüüüh berechnen
	double mü = 0; //Erwartungswert
	double varianz = 0;
	double standardabweichung_in_klammern_sigma = 0;

	for (int i = 0; i < anzahl; i++) {
		mü = argumente[i] * wahrscheinlichkeiten[i] + mü;
	}
	cout << "\nErwartungswert ist: " + to_string(mü) << endl;

	for (int i = 0; i < anzahl; i++) {
		varianz = (argumente[i] - mü) * (argumente[i] - mü) * wahrscheinlichkeiten[i] + varianz;
	}
	cout << "Die Varianz betraegt: " + to_string(varianz) << endl;
	
	standardabweichung_in_klammern_sigma = sqrt(varianz);
	cout << "Die Standardabweichung ist demnach: " + to_string(standardabweichung_in_klammern_sigma) << endl;
	
}


int main() {
	input();
	calc();
	string y;
	cout << "\n\nWrite a button to exit... ";
	cin >> y;
	return 0;
}
