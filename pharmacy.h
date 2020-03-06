#include "vector.h"


void start(Vector *);
// Initialize pharmacy

void addMedication(Vector*);
// Reads and adds a Medication to list. If Medication already exists, updates quantity
// Returns 1 if successful or 0 if Medication already exists

void removeMedicine(Vector* );
// Reads a medicine Id and removes element with given Id
// Returns 1 if successful or 0 otherwise

void searchMedicationByName(Vector* );
// Reads a string and prints all medications containing given word

void shortSupply(Vector* );
// Reads a integer and prints all medications with smaller quantity

void printAll(Vector* );
// Prints all medications.
