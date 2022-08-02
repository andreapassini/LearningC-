#include <iostream>
#include <string>
#include "ListaDellaSpesa.h"
using namespace std;

struct Articolo {
    string nome;
    string marca;
    int prezzo;
    int quantita;
};

void PrintArticolo(Articolo a) {
    // Check if articolo vuoto
    if (a.nome == "") {
        return;
    }

    cout << "Nome: " << a.nome << endl;
    cout << "Marca: " << a.marca << endl;
    cout << "Prezzo: " << a.prezzo << endl;
    cout << "Quantita': " << a.quantita << endl;
    cout << endl;
}

Articolo NuovoArticolo() {
    Articolo nuovoArticolo;

    cout << "Nuovo Articolo: " << endl;
    cout << "Nome: ";
    cin >> nuovoArticolo.nome;
    //getline(cin, nuovoArticolo.nome); // cin stops at -space-, getline at the end of the line

    cout << "Marca: ";
    //getline(cin, nuovoArticolo.marca);
    cin >> nuovoArticolo.marca;

    cout << "Prezzo: ";
    cin >> nuovoArticolo.prezzo;
    cout << endl;

    cout << "Quantità: ";
    cin >> nuovoArticolo.quantita;
    cout << endl;

    return nuovoArticolo;
}

int FindElement(string nome, Articolo lista[], int length) {
    // articolovuoto
    Articolo articoloVuoto;
    articoloVuoto.nome = "";
    articoloVuoto.marca = "";
    articoloVuoto.prezzo = -1;
    articoloVuoto.quantita = 0;

    int i = 0;

    while (i < length && lista[i].nome != "") {
        i++;
    }
    
    if (i >= length)
    {
        i = -1;
    }

    return i;
}

void AddMenu(Articolo lista[], int length) {
    cout << "Inserimento di un nuovo Articolo" << endl;

    int pos = FindElement("", lista, length);
    
    // Check Free Space
    if (pos == -1) {
        cout << "Lista Piena, impossibile inserire elemento" << endl;
        return;
    }

    Articolo articoloDaInserire = NuovoArticolo();

    lista[pos] = articoloDaInserire;

    cout << "Articolo correttamente inserito" << endl;
}

void ElimMenu(Articolo lista[], int length) {
    // articolovuoto
    Articolo articoloVuoto;
    articoloVuoto.nome = "";
    articoloVuoto.marca = "";
    articoloVuoto.prezzo = -1;
    articoloVuoto.quantita = 0;

    cout << "Eliminazione di un elemento" << endl;

    string search;

    cout << "Inserire nome dell'elemento da eliminare: ";
    cin >> search;
    //getline(cin, search);

    int pos = FindElement(search, lista, length);

    if (pos == -1) {
        cout << "articolo non trovato" << endl;
        return;
    }

    lista[pos] = articoloVuoto;
    cout << "articolo rimosso correttamente" << endl;
}

void ModifyMenu(Articolo lista[], int length) {
    cout << "Modificazione di un elemento" << endl;
    cout << "Inserisci il nome dell'elemento che vuoi modificare: ";
    string nome;
    cin >> nome;

    int pos = FindElement(nome, lista, length);

    if (pos == -1) {
        cout << "Articolo non trovato" << endl;
        return;
    }

    cout << "Modifica articolo: " << endl;
    PrintArticolo(lista[pos]);

    Articolo modArticolo = NuovoArticolo();

    lista[pos] = modArticolo;
}

void PrintList(Articolo lista[], int length) {
    for (int i = 0; i < length; i++) {
        PrintArticolo(lista[i]);
    }
}

int main()
{
    // Lista della spesa
    Articolo lista[100];

    // scelta
    int a = -1;

    // articolovuoto
    Articolo articoloVuoto;
    articoloVuoto.nome = "";
    articoloVuoto.marca = "";
    articoloVuoto.prezzo = -1;
    articoloVuoto.quantita = 0;

    // Inizializzazione lista
    for (int i = 0; i < sizeof(lista) / sizeof(Articolo); i++) {
        lista[i] = articoloVuoto;
    }

    // Menu
    while (a != 0) {

        cout << "Menu: \n" << endl <<
            " - 1 - Inserisci nuovo articolo" << endl <<
            " - 2 - Elimina un articolo" << endl <<
            " - 3 - Modifica un aticolo" << endl <<
            " - 4 - Stampare la Lista" << endl <<
            " - 0 - Chiuduere la Lista della Spesa" << endl;

        cin >> a;

        // 1 Add
        switch (a)
        {
        case 1:
            AddMenu(lista, sizeof(lista)/sizeof(Articolo));
            break;
        case 2:
            ElimMenu(lista, sizeof(lista)/sizeof(Articolo));
            break;
        case 3:
            ModifyMenu();
            break;
        case 4:
            PrintList(lista, sizeof(lista) / sizeof(Articolo));
            break;
        default:
            break;
        }
    }
}

