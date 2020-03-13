#include "../ctrl/controller.h"


void start(Vector *);
// Initialize pharmacy

void addHardcodedMedication(Vector*);
// Adds some medication

void addMedication(Vector *pharmacy);
// Reads and adds a Medication to list. If Medication already exists, updates quantity

void removeMedication(Vector *pharmacy);
// Reads a medicine Id and removes element with given Id

void searchMedicationByName(Vector* );
// Reads a string and prints all medications containing given word

void shortSupply(Vector* );
// Reads a integer and prints all medications with smaller quantity

void printAll(Vector* );
// Prints all medications.
