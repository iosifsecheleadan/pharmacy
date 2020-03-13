#include <stdio.h>
#include "ui/pharmacy.h"


void help(){
    printf("Help screen:\n"
           "  type in : help - opens this menu\n"
           "            add - addMedication a medicine to your pharmacy\n"
           "            remove - remove a existing medicine from your pharmacy\n"
           "            search - display all medicine with a given phrase\n"
           "            supply - display all medicine in short supply\n"
           "            exit - exit pharmacy (all modifications are lost)\n");
}

int compareStrings(char string1[], char string2[]){
    /* Compares two strings.
     * pre:     string1 - char[]
     *          string2 - char[]
     * post:    Returns 1 if they are the same.
     *                  or 0 if they are different.
     */
    for (int index = 0; string1[index] != NULL && string2[index] != NULL; index += 1){
        if (string1[index] != string2[index]){
            return 0;
        }
    }
    return 1;
}

int main() {
    Vector* pharmacy = (Vector*) malloc(sizeof(Vector));
    start(pharmacy);

    char* userInput = (char*) malloc(16 * sizeof(char));
    printf("\n    Type in \"help\" for function explanation.\n");
    while (1){
        printf("\nEnter command: ");
        scanf("%s", userInput);
        if (compareStrings(userInput, "help")){
            help();
        } else if (compareStrings(userInput, "hardcoded")) {
            addHardcodedMedication(pharmacy);
        } else if (compareStrings(userInput, "addMedication")) {
            addMedication(pharmacy);
        } else if (compareStrings(userInput, "remove")) {
            removeMedication(pharmacy);
        } else if (compareStrings(userInput, "search")) {
            searchMedicationByName(pharmacy);
        } else if (compareStrings(userInput, "supply")) {
            shortSupply(pharmacy);
        } else if (compareStrings(userInput, "print")) {
            printAll(pharmacy);
        } else if (compareStrings(userInput, "exit")){
            //destroyVector(pharmacy);
            return 0;
        } else { printf("Wrong input. Try learning to use a keyboard before using this application.\n"
                      "  https://www.wikihow.com/Use-a-Computer-Keyboard"); }
    }
}
