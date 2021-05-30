#pragma once
class IgraZivota
{
public:
	IgraZivota();
	void start();
private:
	static const unsigned int COLUMNS = 40;
	static const unsigned int ROWS = 20;
	char PlocaSada[ROWS][COLUMNS];
	char PlocaSljedeca[ROWS][COLUMNS];
	void inicijaliziraj();
	void play();
	void kreirajObrazacPloce();
	void prikaz();
	void generirajPlocu();
	void kopiraj();
	int celijaSusjeda(int row, int column);
	int celija(int max, int min);
	int exit();
};

