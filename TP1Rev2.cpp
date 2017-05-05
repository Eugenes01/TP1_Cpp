#include <iostream>
#include<fstream>
#include<string>

using namespace std;

int menu(int[], int);
int getSom(int[], int);
int getMoy(int[], int);
void setInv(int[], int);
void copyTab(int[], int);

int main() {

    cout << "TP1 C++ Charles-Olivier Marsolais 2017" << endl;
    cout << "Bonjour cher ami, voici ce que je comprend des bases en C++." << endl << endl;

    // Il ne faut pas allouer un tableau sur la pile (stack) car cela la surchargerait, rendant le programme inefficace
    // et pouvant causer un crash du à un manque de mémoire. C'est pourquoi il faut allouer un tableau sur le tas (heap).

    string nameFile = "myFile.txt";

    ifstream myFile (nameFile.c_str());

        if(!myFile) {
            cerr << "Erreur! Pas de service a ce numero!" << endl;
            return -1;
        }

    cout << "Lecture du fichier et entrer des donnees dans un tableau" << endl;
    int numRead;


    int column;
    myFile >> column;
    cout << column << endl;


    int * const numTab = new int[column];
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

    menu(numTab, column);

    return 0;
}

int menu(int numTab[], int column) {

    int menuNumber;
    while(true) {
        cout << endl << endl << "Menu" << endl << "1.Somme" << endl << "2.Moyenne" << endl << "3.Inversion" << endl << "4.Memoire dynamique" << endl << "5.Quitter" << endl;
        cout << "Entrez le numero de votre choix : ";
        cin >> menuNumber;

        switch(menuNumber) {

            case 1 : // Somme
                cout << endl << "La somme des nombres du fichier est : " << getSom(numTab, column);
                break;
            case 2 : // Moyenne
                cout << endl << "La moyenne des nombres du fichier est : " << getMoy(numTab, column);
                break;
            case 3 : // Inversion
                setInv(numTab, column);
                cout << endl << "Le tableau inverse est : " << endl;
                for(int i = 0; i < column; i++) {
                    cout << numTab[i] << " ";
                }
                break;
            case 4 : // Mémoire dynamique
                copyTab(numTab, column);
                break;
            case 5 : // Quitter
                cout << endl << "Merci et Bonne Correction!" << endl;
                return 0; // Pour Quitter
            default : //
                cout << endl << "Entree Invalide!";
        }
    }
}

int getSom(int numTab[], int column) {
    int som = 0;
    for(int i = 0; i < column; i++) {
        som = som + numTab[i];
    }
    return som;
}

int getMoy(int numTab[], int column) {
    return getSom(numTab, column)/column;
}

void setInv(int numTab[], int column) {
    for(int i = 0; i < (column - i); i++) {
        int temp = numTab[i];
        numTab[i] = numTab[column - (i+1)];
        numTab[column - (i+1)] = temp;
    }
}

void copyTab(int numTab[], int column) {

    int * const numTabCopy = new int[column];

    for(int i = 0; i < column; i++) {
        numTabCopy[i] = numTab[i];
    }
    cout << endl << "Le tableau copie est : " << endl;
    for(int i = 0; i < column; i++) {
        cout << numTabCopy[i] << " ";
    }

    delete [] numTabCopy;

}
