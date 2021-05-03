/*
    spicoli piersilvio
    offuscamento password
    parte del codice è parte dell'esercitazione 9.2
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define LUNG_NOME 20 // lunghezza massima del nome
#define LUNG_COGNOME 20 // lunghezza massima del cognome
#define LUNG_SIMBOLI 5 // vocabolario dei simboli (estendibile)

#define LUNG_PASSWORD 9 // lunghezza della password (aggiungere il terminatore!)
#define NUM_CAR_NOME_PASSWORD 3 // numero di caratteri estratti dal nome da inserire nella password
#define NUM_CAR_COGNOME_PASSWORD 3 // numero di caratteri estratti dal cognome da inserire nella password
#define NUM_SIMBOLI_PASSWORD 2 // numero di simboli nella password
#define CAR_INIZIALI_OFFUSCATI 3 //lunghezza massima per offuscare

//prototipi
char*generaPassword(char*, char*);
char* offuscaPw(char*);

int main()
{

	char nome[LUNG_NOME]; // variabili locali per input e output
	char cognome[LUNG_COGNOME];
	char* password;
	char* offuscamento;

	printf("Inserisci nome: "); // inserimento input da tastiera
	scanf("%20s", nome);
	printf("\nInserisci cognome: ");
	scanf("%20s", cognome);

    password = generaPassword(nome, cognome);
    offuscamento = offuscaPw(password);

    printf("\n la password offuscata e': %s\n", offuscamento);

    return 0;
}

/* La funzione prende in input il nome e il cognome di una persona e restituisce
   una password di 8 caratteri che combina nome, cognome e simboli generati random.
*/
char* generaPassword(char* n, char* c) {

	char simboli[LUNG_SIMBOLI] = {'$', '#', '*', '^', '%'};
	int idSimbolo;
	char* p = (char*)  calloc(LUNG_PASSWORD, sizeof(char));// alloco un numero sufficiente di caratteri per generare la nuova password
	int car_nome = 0; // variabile di controllo per verificare la lunghezza del nome
	int car_cognome = 0;
	srand(time(0));

	// verifico che il nome sia lungo a a sufficienza, altrimenti lo inserisco tutto
	if( strlen(n) < NUM_CAR_NOME_PASSWORD )
		car_nome = strlen(n);
	else
		car_nome = NUM_CAR_NOME_PASSWORD;

	// i primi caratteri della password sono estratti dal nome.
	// utilizza la funzione tolower( ) per convertire tutto in minuscolo
	for(int i = 0; i < car_nome; i++)
    {
		*(p + i) = tolower( *(n + i) );
	}

	// i primi caratteri della password sono estratti dal cognome.
	// i = contatore che scorre tra gli elementi del cognome
	// j = contatore che scorre tra gli elementi della password (viene inizializzata
	// in base al numero di caratteri estratti dal nome contenuti nella password
	int j = car_nome;

	// verifico che il cognome sia lungo a a sufficienza, altrimenti lo inserisco tutto
	if( strlen(c) < NUM_CAR_COGNOME_PASSWORD )
		car_cognome = strlen(c);
	else
		car_cognome = NUM_CAR_COGNOME_PASSWORD;

	for(int i = 0; i < car_cognome; i++)
    {
		*(p + j) = tolower( *(c + i) );
		j++; // incremento il contatore per puntare all'elemento successivo
	}

	int k = car_nome + car_cognome;

	for(int i = 0; i < NUM_SIMBOLI_PASSWORD; i++)
    {
		idSimbolo = rand() % LUNG_SIMBOLI;

		*(p + k) = simboli[idSimbolo]; // genero un simbolo random
		k++;
	}

	return p; // restituisco la password generata
}

char* offuscaPw(char* pw)
{
    //allochiamo nell'area di memoria passata i caratteri per generare la pw
    char* p = (char*) calloc(LUNG_PASSWORD, sizeof(char));
    int i;

    int lunghezza = strlen(pw); //memorizzo la lunghezza della stringa passata

    for(i = 0; i < CAR_INIZIALI_OFFUSCATI; i++) //copio i primi tre caratteri
    {
        *(p + i) = *(pw + i);
    }

    i = CAR_INIZIALI_OFFUSCATI;
    for(i; i < lunghezza - CAR_INIZIALI_OFFUSCATI; i++) //sostituisco i caratteri centrali con '*'
    {
        *(p + i) = '*';
    }

    i = lunghezza - CAR_INIZIALI_OFFUSCATI;
    for(i; i < lunghezza; i++) //copio gli ultimi caratteri
    {
        *(p + i) = *(pw + i);
    }

    return p;
}


