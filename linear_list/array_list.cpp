#include "array_list.h"

bool list::initList(elemType *list, int initLength, int initMaxLength)
{
    if (listPtr != nullptr)
        return false;
    else
    {
        listPtr = new elemType[initMaxLength];
        maxLength = initMaxLength;
        length = initLength;
        for (int i = 0; i < length; i++)
        {
            listPtr[i] = list[i];
        }
        return true;
    }
}

bool list::clearList()
{
    if (listPtr == nullptr)
        return false;
    else
    {
        delete listPtr;
        maxLength = 0;
        length = 0;
        return true;
    }
}

bool list::listEmpty()
{
    if (listPtr == nullptr)
        return true;
    else
        return false;
}

bool list::getElem(int idx, elemType *ret)
{
    if (listPtr == nullptr)
    {
        std::cout << "err: list empty, cannot get element\n";
        return false;
    }
    else if (idx < length)
    {
        *ret = listPtr[idx];
        return true;
    }
    else
    {
        std::cout << "err: idx too big, cannot get element\n";
        return false;
    }
}

bool list::locateElem(elemType target, bool (*compare)(elemType, elemType), int *ret)
{
    if (listPtr == nullptr)
    {
        std::cout << "err: list empty, cannot get element\n";
        return false;
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            if (compare(listPtr[i], target))
            {
                *ret = i;
                return true;
            }
        }
        return false;
    }
}

bool list::priorElem(elemType target, elemType *ret)
{
    if (listPtr == nullptr)
    {
        std::cout << "err: list empty, cannot get element\n";
        return false;
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            if (listPtr[i] == target)
            {
                if (i == 0)
                {
                    std::cout << "err: target is first one, no prior\n";
                    return false;
                }
                else
                {
                    *ret = listPtr[i - 1];
                    return true;
                }
            }
        }
        std::cout << "err: cannot find target, return NULL\n";
        return false;
    }
}

bool list::nextElem(elemType target, elemType *ret)
{
    if (listPtr == nullptr)
    {
        std::cout << "err: list empty, cannot get element\n";
        return false;
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            if (listPtr[i] == target)
            {
                if (i == length - 1)
                {
                    std::cout << "err: target is last one, no next\n";
                    return false;
                }
                else
                {
                    *ret = listPtr[i + 1];
                    return true;
                }
            }
        }
        std::cout << "err: cannot find target, return NULL\n";
        return false;
    }
}

bool list::insertElem(elemType target, int idx)
{
    if (listPtr == nullptr)
    {
        std::cout << "err: list empty, cannot get element\n";
        return false;
    }
    else if (length == maxLength)
    {
        std::cout << "err: length has reach the limit, cannot insert element\n";
        return false;
    }
    else if (idx > length)
    {
        std::cout << "err: idx is not inside the list, cannot insert element\n";
        return false;
    }
    else
    {
        for (int i = length; i > idx; i--)
        {
            listPtr[i] = listPtr[i - 1];
        }
        listPtr[idx] = target;
        length++;
        return true;
    }
    return false;
}

bool list::deleteElem(int idx)
{
    if (listPtr == nullptr)
    {
        std::cout << "err: list empty, cannot get element";
        return false;
    }
    else if (length == 0)
    {
        std::cout << "err: length is 0, cannot delete element\n";
        return false;
    }
    else if (idx >= length)
    {
        std::cout << "err: idx is not inside the list, cannot delete element\n";
        return false;
    }
    else
    {
        for (int i = idx; i < length - 1; i++)
        {
            listPtr[i] = listPtr[i + 1];
        }
        length--;
        return true;
    }
    return false;
}

bool list::listTraverse(void (*visit)(elemType *target))
{
    if (listPtr == nullptr)
    {
        std::cout << "err: list empty, cannot get element";
        return false;
    }
    else
    {
        for (int i = 0; i < length; i++)
        {
            visit(&listPtr[i]);
        }
        return true;
    }
    return false;
}

int list::getLength()
{
    return length;
}

int list::getMaxLength()
{
    return maxLength;
}