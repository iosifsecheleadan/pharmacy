#include "medication.h"


// Medication structure
// + possibly functions upon them


Id* initializeId(char *name, float concentration) {
    Id* id = (Id*) malloc (sizeof(id));
    id->name = name;
    id->concentration = concentration;
    return id;
}

Medication* initializeMedicine(char* name, float concentration, int quantity, float price) {
    // Returns medicine with given properties
    Medication* med = (Medication*) malloc(sizeof(Medication)); // allocation of medicine
    med->id = (Id*) malloc(sizeof(Id));                         // allocation of Id

    med->id->name = name;                   // initialization of name
    med->id->concentration = concentration; // initialization of concentration
    med->quantity = quantity;               // initialization of quantity
    med->price = price;                     // initialization of price
    return med;
}

int compareId(Id* id1, Id* id2){
    return ( (strcmp(id1->name, id2->name) == 0) && (id1->concentration == id2->concentration) );
}

Id* getId(Medication med) {
    // Returns Id of Medication
    return med.id;
}

char* getName(Medication med) {
    // Returns name of Medication
    return med.id->name;
}

float getConcentration(Medication* med) {
    // Returns concentration of Medication
    return med->id->concentration;
}

int getQuantity(Medication med) {
    // Returns quantity of Medication
    return med.quantity;
}

void setQuantity(Medication* med, int quantity) {
    // Sets given quantity to given Medication
    med->quantity = quantity;
}

void updateQuantity(Medication* med, int quantity) {
    // Adds given quantity to medicine quantity
    med->quantity += quantity;
}

float getPrice(Medication* med) {
    // Returns price of Medication
    return med->price;
}

void setPrice(Medication* med, float price) {
    // Sets given price to given Medication
    med->price = price;
}

void destroyId(Id* id) {
    //Frees allocated space
    free(id->name);
    free(id);
}

void destroyMedication(Medication* med) {
    // Frees allocated space
    free(med->id->name);
    free(med->id);
}

void printMedication(Medication med) {
    printf("There is %d g of %s, of %.2f concentration at %.0f RON in stock.\n", med.quantity, med.id->name, med.id->concentration, med.price);
}
