#include "../repo/vector.h"

void initializeController(Vector*, int length);

char* addOrUpdateMedication(Vector*, Medication*);

char* tryRemoveMedication(Vector*, Id*);

Vector* getMedicationByName(Vector*, char*);

Vector* getMedicationInShortSupply(Vector*, int);