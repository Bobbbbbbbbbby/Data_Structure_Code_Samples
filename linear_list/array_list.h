#include <iostream>
#include <stdlib.h>

typedef int elemType;

class list
{
public:
    list()
    {
        maxLength = 0;
        length = 0;
        listPtr = nullptr;
    }

    /**
     * @return if return true, list is cleared; else the list is already empty and no need to clear
     */
    bool clearList();

    /**
     * @param initMaxLength - the initial maxLength of the list
     * @return if return true, list is initiated and length is param, else the list has already existed
    */
    bool initList(elemType* list, int length, int initMaxLength);

    bool listEmpty();

    bool getElem(int idx, int* ret);

    bool locateElem(elemType target, bool (*compare)(elemType, elemType), int* ret);

    bool priorElem(elemType target, elemType* ret);

    bool nextElem(elemType target, elemType* ret);

    bool insertElem(elemType target, int idx);

    bool deleteElem(int idx);

    bool listTraverse(void (*visit)(elemType *target));

    int getLength();

    int getMaxLength();

private:
    elemType *listPtr;
    int length;
    int maxLength;
};