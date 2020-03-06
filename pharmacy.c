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

int stringIncludes(char* text, char* string){
    // Returns 1 if string is in text and 0 otherwise.
    if (string[0] == NULL || text[0] == NULL){
        return 0;
    }

    int sIndex;
    for (int tIndex = 0; text[tIndex] != NULL; tIndex += 1) {
        sIndex = 0;
        if(text[tIndex] == string[sIndex]) {
            while (text[tIndex] == string[sIndex]) {
                if (string[sIndex + 1] == NULL) {
                    return 1;
                }
                tIndex += 1;
                sIndex += 1;
            }
            tIndex -= 1;
        }
    }
    return 0;
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




//public:
void start(Vector *pharmacy) {
    // Initialize pharmacy
    int noItems;
    printf("How many medical items will you have? ");
    scanf("%d", &noItems);
    printf("Intializing with %d items. ", noItems);

    initializeVector(pharmacy, noItems);
}

void addMedication(Vector *pharmacy) {
    // Reads and adds a Medication to list. If Medication already exists, updates quantity
    // Returns 1 if successful or 0 if Medication already exists
    Medication* tempMed;
    tempMed = readMedication();

    for (int index = 0; index < size(pharmacy); index += 1) {
        if (compareId(getId(getElement(pharmacy, index)), getId(*tempMed))) {
            updateQuantity(&(pharmacy->array[index]), getQuantity(*tempMed));

            //destroyMedication(tempMed);
            printf("Medication updated.");
            return;
        }
    }

    if(size(pharmacy) >= pharmacy->length){
        printf("The initialized array cannot take more than is already given.\n"
               "Either remove elements, or restart application with more elemets.\n"
               "We apologize for the inconvenience.");
        return;
    }

    setElement(pharmacy, *tempMed, size(pharmacy));     // in order to be able to free later, tempMed should be deep-copied into pharmacy
    increaseCurrent(pharmacy);

    printf("Medication added.\n");

    //destroyMedication(tempMed);     // if I free here, name and concentration (meaning id), are not properly allocated...
}

void removeMedicine(Vector* pharmacy) {
    // Reads a medicine Id and removes element with given Id
    // Returns 1 if successful or 0 otherwise
    Id* tempId;
    tempId = readID();

    for (int index = 0; index < size(pharmacy); index += 1){
        if (compareId(getId(getElement(pharmacy, index)), tempId)) {
            //destroyMedication(&(pharmacy->array[index]));
            removePosition(pharmacy, index);

            destroyId(tempId);

            printf("Medication removed");

            return;
        }
    }
    destroyId(tempId);
    printf("Medication not removed.");
    return;
}

void searchMedicationByName(Vector* pharmacy) {
    // Reads a string and prints all medications containing given word
    char* string;
    string = readString();
    printf("Medications with given word are: \n");

    for (int index = 0; index < size(pharmacy); index += 1) {
        if (stringIncludes(getName(getElement(pharmacy, index)), string)) {
            printMedication(getElement(pharmacy, index));
        }
    }
}

void shortSupply(Vector* pharmacy) {
    // Reads a integer and prints all medications with smaller quantity
    int supplyLimit = readInt();

    printf("Medicine in short supply (less than %d g) are:\n", supplyLimit);
    for (int index = 0; index < size(pharmacy); index += 1) {
        if (getQuantity(getElement(pharmacy, index)) < supplyLimit){
            printMedication(getElement(pharmacy, index));
        }
    }
}


void printAll(Vector* pharmacy) {
    for (int index = 0; index < size(pharmacy); index += 1) {
        printMedication(getElement(pharmacy, index));
    }
}

