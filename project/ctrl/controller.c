#include "controller.h"



// private:
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


// public :
void initializeController(Vector * vector, int length) {
    initializeVector(vector, length);
}

char* addOrUpdateMedication(Vector* vector, Medication *med) {
    char* string;
    for (int index = 0; index < size(vector); index += 1) {
        if (compareId(getId(getElement(vector, index)), getId(*med))) {
            updateQuantity(&(vector->array[index]), getQuantity(*med));

            //destroyMedication(tempMed);
            string = "Medication updated.";
            return string;
        }
    }

    if(size(vector) >= vector->length){
        string = "The initialized array cannot take more than is already given.\n"
                       "Either remove elements, or restart application with more elemets.\n"
                       "We apologize for the inconvenience.";
        return string;
    }

    setElement(vector, *med, size(vector));     // in order to be able to free later, tempMed should be deep-copied into pharmacy
    increseNoElements(vector);

    string = "Medication added.";
    return string;
}

char* tryRemoveMedication(Vector * vector, Id* medId) {
    char* string;
    for (int index = 0; index < size(vector); index += 1){
        if (compareId(getId(getElement(vector, index)), medId)) {
            //destroyMedication(&(pharmacy->array[index]));
            removePosition(vector, index);
            destroyId(medId);

            string = "Medication removed";
            return string;
        }
    }
    destroyId(medId);

    string = "Medication not found. Not removed.";
    return string;
}

Vector* getMedicationByName(Vector* vector, char* name) {
    Vector *toReturn = (Vector*) malloc(sizeof(Vector));
    initializeVector(toReturn, size(vector));
    for (int index = 0; index < size(vector); index += 1) {
        if (stringIncludes(getName(getElement(vector, index)), name)) {
            setElement(toReturn, getElement(vector, index), size(toReturn));
            increseNoElements(toReturn);
        }
    }
    return toReturn;
}

Vector *getMedicationInShortSupply(Vector* vector, int supplyLimit) {
    Vector* toReturn = (Vector*) malloc(sizeof(Vector));
    initializeVector(toReturn, size(vector));
    for (int index = 0; index < size(vector); index += 1) {
        if (getQuantity(getElement(vector, index)) < supplyLimit){
            setElement(toReturn, getElement(vector, index), size(toReturn));
            increseNoElements(toReturn);
        }
    }
    return toReturn;
}
