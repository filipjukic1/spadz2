#include "IgraZivota.h"
#include <iostream>

using namespace std;

IgraZivota::IgraZivota()
{
	srand(time(0));
	this->inicijaliziraj();
}

void IgraZivota::start()
{
	int izbor = 0;
	

	do
	{
		do
		{
			cout << "Izbornik" << endl
				<< "(1) Igraj" << endl
				<< "(2) Izadi" << endl;
			cout << "Odaberi opciju: ";
			cin >> izbor;
		} while (izbor > 2 || izbor < 1);

		switch (izbor)
		{
		case 1:
			this->play();
			break;
		case 2:
			this->exit();
			break;

		default:
			break;
		}
	} while (izbor != 2);
}

void IgraZivota::inicijaliziraj()
{
	this->PlocaSada[0][0] = '-';
	this->PlocaSljedeca[0][0] = '-';
}

void IgraZivota::play()
{
	char sljedeca = 0;
	this->kreirajObrazacPloce();

	do {

		this->prikaz();
		this->generirajPlocu();
		this->kopiraj();
		cout << "Nastaviti?(1/0): ";
		cin >> sljedeca;
	} while (sljedeca == '1');
}

void IgraZivota::kreirajObrazacPloce()
{
	for (int i = 0; i < this->ROWS; ++i)
	{
		for (int ix = 0; ix < this->COLUMNS; ++ix)
		{
			this->PlocaSada[i][ix] = '-';
		}
	}

	for (int i = 0; i < this->ROWS; i += 2)
	{
		for (int ix = 0; ix < this->COLUMNS; ix++)
		{
			if (this->celija(4, 1) == 4) {
				this->PlocaSada[i][ix] = '*';
			}
		}
	}
}

void IgraZivota::prikaz()
{
	for (int i = 0; i < this->ROWS; i++)
	{
		cout << "|";
		for (int ix = 0; ix < this->COLUMNS; ix++)
		{
			if (this->PlocaSada[i][ix] != '*')
				this->PlocaSada[i][ix] = ' ';

			cout << this->PlocaSada[i][ix];

		}
		cout << "|" << endl;
	}
}

void IgraZivota::generirajPlocu()
{
	int neighbors;

	for (int i = 0; i < this->ROWS; i++)
	{
		for (int ix = 0; ix < this->COLUMNS; ix++)
		{
			neighbors = this->celijaSusjeda(i, ix);
			if (neighbors < 2)
				this->PlocaSljedeca[i][ix] = '-';
			else if (neighbors > 3)
				this->PlocaSljedeca[i][ix] = '-';
			else if (neighbors == 3)
				this->PlocaSljedeca[i][ix] = '*';
			else if (this->PlocaSada[i][ix] == '*' && neighbors == 2)
				this->PlocaSljedeca[i][ix] = '*';
			else
				PlocaSljedeca[i][ix] = '-';
		}

	}
}

void IgraZivota::kopiraj()
{
	for (int i = 0; i < this->ROWS; i++)
	{
		for (int ix = 0; ix < this->COLUMNS; ix++)
		{
			this->PlocaSada[i][ix] = this->PlocaSljedeca[i][ix];
		}
	}
}

int IgraZivota::celijaSusjeda(int row, int column)
{
	int  susjedna_celija= 0;

	if (this->PlocaSada[row - 1][column - 1] == '*')
		++susjedna_celija;
	if (this->PlocaSada[row][column - 1] == '*')
		++susjedna_celija;
	if (this->PlocaSada[row - 1][column] == '*')
		++susjedna_celija;
	if (this->PlocaSada[row - 1][column + 1] == '*')
		++susjedna_celija;
	if (this->PlocaSada[row + 1][column - 1] == '*')
		++susjedna_celija;
	if (this->PlocaSada[row + 1][column] == '*')
		++susjedna_celija;
	if (this->PlocaSada[row][column + 1] == '*')
		++susjedna_celija;
	if (this->PlocaSada[row + 1][column + 1] == '*')
		++susjedna_celija;

	return susjedna_celija;
}

int IgraZivota::celija(int max, int min)
{
	return rand() % (max - min + 1) + min;
}

int IgraZivota::exit()
{

	return 0;
}
