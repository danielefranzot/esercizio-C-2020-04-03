/*
 * soluzione-esercizio-C-2020-04-03.c
 *
 *  Created on: 17 apr 2020
 *      Author: Daniele Franzot
 */
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define NAME_LEN 64
#define PHONE_LEN 20

typedef struct {
   int id; // id numerico del contatto (valore univoco)
   char name[NAME_LEN + 1]; // nome della persona
   char phone[PHONE_LEN + 1]; // numero di telefono
} contact_type;

int id_counter = 0;

contact_type * create_contact(char * name,char * phone_number){
	contact_type * contact;
	contact = malloc(sizeof(contact_type));

	contact->id = id_counter;
	memcpy(contact->name,name,NAME_LEN +1);
	memcpy(contact->phone,phone_number,PHONE_LEN+1);

	id_counter++;

	return contact;
}

void print_contact(contact_type * person){
	printf("name: '%s' phone number: '%s' id: %d\n\n",person->name,person->phone,person->id);
}

int main(int argc, char *argv[]) {

	contact_type * pino = create_contact("pino rossi", "+393331234567");

	if (pino == NULL) {
		printf("errore in create_contact!\n");
		exit(EXIT_FAILURE);
	}

	contact_type * gino = create_contact("gino verdi", "+393487654321");

	if (gino == NULL) {
		printf("errore in create_contact!\n");
		exit(EXIT_FAILURE);
	}

	print_contact(pino);

	print_contact(gino);

	return 0;
}
