#include "medication.h"

typedef Medication Telem;

typedef struct {
    int length;
    Telem *array;
    int currentPosition;
} Vector;

void initializeVector(Vector*, int length);
// Initializes Vector of given length

int size(Vector*);
// returns size of Vector

Telem getElement(Vector*, int position);
// returns element on given position of Vector

void setElement(Vector*, Telem element, int position);
// sets given element to given position in Vector
// returns old element on given position

void destroyVector(Vector*);
// Frees allocated memeory

Telem removePosition(Vector* , int position);
// Removes and returns element on given position

void increaseCurrent(Vector*);

void decreaseCurrent(Vector *v);

/*Iteration example:
 *  for (int index = 0; index < size(Vector); index += 1) {
 *      ...
 *      getElement(Vector, index);
 *      ...
 *      Telem example = setElement(Vector, newElement, index);
 *      ...
 *  }
 */
