#include "vector.h"

// Vector structure based on dynamically allocated array (in "Vector.h")
// + iterator

int size(Vector *v) {
    // returns size of Vector

    return v->noElements;
}

void initializeVector(Vector* v, int length) {
    // Initializes a Vector of given length
    v->length = length;
    v->noElements = 0;
    v->array = (Telem*) malloc(length * sizeof(Telem));
}

Telem getElement(Vector* v, int position){
    // returns element on given position of Vector
    return v->array[position];
}

void setElement(Vector* v, Telem element, int position){
    // sets given element to given position in Vector
    v->array[position] = element;
    /* Somehow I think element should be deep-copied into v->array[position]
    v->array[position].id->name = element.id->name;
    v->array[position].id->concentration = element.id->concentration;
    v->array[position].quantity = element.quantity;
    v->array[position].price = element.price;
     */

}

void destroyVector(Vector* v) {
    // Frees allocated memeory
    if(v->length < 0){
        return;
    }
    for(int index = 0; index < v->length; index += 1){
        free(v->array[index].id->name);
        free(v->array[index].id);
    }
    free(v->array);
    free(v);
}

Telem removePosition(Vector* v, int position) {
    // Removes and returns element on given position
    Telem temp = v->array[position];
    //destroyMedication(&(v->array[position]));
    decreaseNoElements(v);
    for (; position < v->noElements; position += 1) {
        setElement(v, getElement(v, position + 1), position);
    }

    return temp;
}

void increseNoElements(Vector* v) {
    v->noElements += 1;
}

void decreaseNoElements(Vector *v) {
    v->noElements -= 1;
}































































