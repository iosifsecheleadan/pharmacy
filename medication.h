#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    char* name;
    float concentration;
} Id;


typedef struct {
    Id* id;
    int quantity;           // in g
    float price;            // in whatever you want
} Medication;

Id* initializeId(char *name, float concentration);


Medication* initializeMedicine(char* name, float concentration, int quantity, float price);
// Returns medicine with given properties

int compareId(Id* id1, Id* id2);


Id* getId(Medication);
// Returns Id of Medication

char* getName(Medication);
// Returns name of Medication

float getConcentration(Medication*);
// Returns concentration of Medication

int getQuantity(Medication);
// Returns quantity of Medication

void setQuantity(Medication* , int quantity);
// Sets given quantity to given Medication

void updateQuantity(Medication* , int quantity);
// Adds given quantity to medicine quantity

float getPrice(Medication*);
// Returns price of Medication

void setPrice(Medication* , float price);
// Sets given price to given Medication

void destroyMedication(Medication *);
// Frees allocated space

void destroyId(Id* );
// Frees allocated space

void printMedication(Medication);
// Prints given Medication
