#include <iostream>
#include<fstream>
#include<string>

using namespace std;

void menu();
int getSom(int[], int);
int getMoy(int);
void setInv(int[], int);
void copyTab(int [], int);

int column;
int *numTab;

int main() {

    cout << "TP1 C++ Charles-Olivier Marsolais 2017" << endl;
    cout << "Bonjour cher ami, voici ce que je comprend des bases en C++." << endl << endl;

    string nameFile = "myFile.txt";

    ifstream myFile (nameFile.c_str());

        if (!myFile) {
            cerr << "Erreur! Pas de service a ce numero!" << endl;
            return -1;
        }

    cout << "Lecture du fichier et entrer des donnees dans un tableau" << endl;
    int numRead;

    myFile >> column;
    cout << column << endl;

    numTab = new int[column];
    int i = 0;
    while(!myFile.eof()){
        myFile >> numRead;
        cout << numRead << " ";
        numTab[i] = numRead;
        i++;
    }
    //for(int i = 0; i < column; i++){
    //    cout << numTab[i] << endl;
    //}
    myFile.close();

    menu();

return 0;
}

void menu() {

    int menuNumber;

    cout << endl << endl << "Menu" << endl << "1.Somme" << endl << "2.Moyenne" << endl << "3.Inversion" << endl << "4.Memoire dynamique" << endl << "5.Quitter" << endl;
    cout << "Entrez le numero de votre choix : ";
    cin >> menuNumber;

    switch (menuNumber) {

        case 1 : // Somme
            cout << endl << "La somme des nombres du fichier est : " << getSom(numTab, column);
            menu();
            break;
        case 2 : // Moyenne
            cout << endl << "La moyenne des nombres du fichier est : " << getMoy(column);
            menu();
            break;
        case 3 : // Inversion
            setInv(numTab, column);
            cout << endl << "Le tableau inverse est : " << endl;
            for(int i = 0; i < column; i++){
                cout << numTab[i] << " ";
            }
            menu();
            break;
        case 4 : // Mémoire dynamique
            copyTab(numTab, column);
            menu();
            break;
        case 5 : // Quitter
            cout << endl << "Merci et Bonne Correction!" << endl;
            break;
        default : //
            cout << endl << "Entree Invalide!";
            menu();
    }
}

int getSom(int numTab[], int column) {
    int som = 0;
    for(int i = 0; i < column; i++){
        som = som + numTab[i];
    }
return som;
}

int getMoy(int column) {
    int moy;
    moy = getSom(numTab, column)/column;
return moy;
}

void setInv(int numTab[], int column) {
    for(int i = 0; i < (column - i); i++){
        int temp = numTab[i];
        numTab[i] = numTab[column - (i+1)];
        numTab[column - (i+1)] = temp;
    }
}

void copyTab(int numTab[], int column) {

    int *numTabCopy;
    numTabCopy = new int[column];

    for(int i = 0; i < column; i++){
        numTabCopy[i] = numTab[i];
    }
    cout << endl << "Le tableau copie est : " << endl;
    for(int i = 0; i < column; i++){
        cout << numTabCopy[i] << " ";
    }

    delete [] numTabCopy;

}










