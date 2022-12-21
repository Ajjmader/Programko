#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
  // Pomoc� jedni�ky zna��me �e se n�kde nach�z� lo�
  bool lode[4][4] = {
    { 0, 1, 1, 1 },
    { 0, 0, 0, 0 },
    { 0, 0, 1, 0 },
    { 0, 0, 1, 0 }
  };
  string mapa[4][4] = {
  { " 0 "," 0 "," 0 "," 0"},
  { " 0 "," 0 "," 0 "," 0"},
  { " 0 "," 0 "," 0 "," 0"},
  { " 0 "," 0 "," 0 "," 0"}
  };
  // Je ty to mas pekny - A dokonce je to zabezpeceny - a ted do vetve
  // Do techto promenn�ch zapisujeme pocet tahu a z�sahu
  int zasahy = 0;
  int tahy = 0;
  int radkymapy = 4;
  int sloupcemapy = 4;
  // Dokud nebude pocet zasahu odpovidat poctu zasahu 1 v poli program pob��
  while (zasahy < 4) {
        system("cls");
    int radek, sloupec;

    cout << "Zvolte misto strely\n";
    cout << " 0  1  2  3  Sloupec" <<"\n";
    cout << "--------------------" << "\n";
for (int a = 0; a < radkymapy; ++a)
    {
        for (int j = 0; j < sloupcemapy; ++j)
        {
        cout << mapa[a][j];
        }
        cout << "\n";
    }

    // Volba radku
    cout << "Vyberte pozici na radku mezi 0 az 3: ";
    cin >> radek;

    // Volba sloupce
    cout << "Vyberte pozici na sloupci mezi 0 az 3: ";
    cin >> sloupec;

    // Kontrola zda na sou�adnici je lo�
    if (lode[radek][sloupec]) {
      // Pokud dojde k zasahu zmenime 1 na 0
      lode[radek][sloupec] = 0;
      mapa[radek][sloupec] = " X ";

      // P�id�me z�sah
      zasahy++;

      // Ozn�m�me z�sah a kolik 1 zb�v�.
      cout << "Zasah! "  << " zbyva" << (4-zasahy) << "\n\n";
      Sleep(1000);
    } else {
      // Oznameni ze nebylo nic zasazeno
      cout << "Voda\n\n";
      mapa [radek][sloupec] = " V ";
      Sleep(1000);
    }

    // Pricteme tah
    tahy++;
  }

  cout << "Vitezstvi!\n";
  cout << "Vyhrali jste za " << tahy << " tahu";

  return 0;
}
