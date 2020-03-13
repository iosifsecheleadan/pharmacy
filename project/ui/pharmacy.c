#include <stdio.h>
#include "pharmacy.h"


//private:

int readInt() {
    // Reads and returns a integer
    int integer;

    printf("Please give a integer:");
    scanf("%d", &integer);

    return integer;
}

char* readString(){
    // Reads and returns a string
    char* string = (char*) malloc (64 * sizeof(char));

    printf("Input word:");
    scanf("%s", string);

    return string;
}


Id* readID() {
    // Read name and concentration of a medicine
    // Return Id composed of read name and concentration
    printf("Give name and concetration of medicine separated by enter:");
    char *name = (char*) malloc (64 * sizeof(char));
    float concentration;

    scanf("%s", name);
    scanf("%f", &concentration);

    return initializeId(name, concentration);
}

Medication* readMedication(){
    // Read and return a Medication
    printf("Give name, concentration, quantity and price of medicine separated by enter:");
    char *name = (char*) malloc(64 * sizeof(char));
    float concentration;
    int quantity;
    float price;

    scanf("%s", name);
    scanf("%f", &concentration);
    scanf("%d", &quantity);
    scanf("%f", &price);

    return initializeMedicine(name, concentration, quantity, price);
}

void printMedicationVector(Vector* vector) {
    for(int index = 0; index < size(vector); index += 1) {
        printMedication(getElement(vector, index));
    }
}

char ascii(int index) {
    return (char) (60 + index);
}

//public:
void start(Vector *pharmacy) {
    // Initialize pharmacy
    int noItems;
    printf("How many medical items will you have? ");
    scanf("%d", &noItems);
    printf("Intializing with %d items. ", noItems);

    initializeController(pharmacy, noItems);
}


void addHardcodedMedication(Vector* pharmcay) {
    // Adds some medication
    int noItems = readInt();
    for(int index = 0; index < noItems; index += 1) {
        Medication* tempMed = initializeMedicine((char*) "med", (float) index / 10, index, (float) index * 10);
        addOrUpdateMedication(pharmcay, tempMed);
    }
}


void addMedication(Vector *pharmacy) {
    // Reads and adds a Medication to list. If Medication already exists, updates quantity
    Medication* tempMed;
    tempMed = readMedication();

    char* string = addOrUpdateMedication(pharmacy, tempMed);
    printf("%s", string);
}

void removeMedication(Vector* pharmacy) {
    // Reads a medicine Id and removes element with given Id
    Id* tempId;
    tempId = readID();

    char* string = tryRemoveMedication(pharmacy, tempId);
    printf("%s", string);
}

void searchMedicationByName(Vector* pharmacy) {
    // Reads a string and prints all medications containing given word
    char* string;
    string = readString();
    printf("Medications with given word are: \n");

    Vector* toPrint = getMedicationByName(pharmacy, string);
    printMedicationVector(toPrint);
}

void shortSupply(Vector* pharmacy) {
    // Reads a integer and prints all medications with smaller quantity
    int supplyLimit = readInt();
    printf("Medicine in short supply (less than %d g) are:\n", supplyLimit);

    Vector* toPrint = getMedicationInShortSupply(pharmacy, supplyLimit);
    printMedicationVector(toPrint);
}

void printAll(Vector* pharmacy) {
    printMedicationVector(pharmacy);
}


