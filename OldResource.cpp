#include "OldResource.h"

uint8_t createResource()
{
    auto freeSlot = find(begin(references), end(references), INVALID_REFERENCE);
    if (end(references) == freeSlot) {
        lastError = ERROR_NO_FREE_RESOURCES;

        return INVALID_REFERENCE;
    }

    auto newReference = getNewReference();
    (*freeSlot) = newReference;
    lastError = NO_ERROR;

    return newReference;
}

void destroyResource(uint8_t reference)
{
    if (INVALID_REFERENCE == reference) {
        lastError = ERROR_INVALID_ARGUMENT;

        return;
    }

    auto target = find(begin(references), end(references), reference);
    if (end(references) == target) {
        lastError = ERROR_INVALID_ARGUMENT;

        return;
    }

    (*target) = INVALID_REFERENCE;
    lastError = NO_ERROR;
}

int freeResourceCount()
{
    lastError = NO_ERROR;

    return count(begin(references), end(references), INVALID_REFERENCE);
}

int getLastError()
{
    return lastError;
}

void bindResource(uint8_t reference, uint8_t mode)
{
    auto refSlot = find(begin(references), end(references), reference);
    if (end(references) == refSlot) {
        lastError = ERROR_INVALID_ARGUMENT;

        return;
    }

    if (mode == MODE_INVALID || mode > MODE_3) {
        lastError = ERROR_INVALID_MODE;

        return;
    }

    boundReference = reference;
    selectedMode = mode;
    lastError = NO_ERROR;
}

void useResource()
{
    if (INVALID_REFERENCE == boundReference) {
        lastError = ERROR_NO_RESOURCE_BOUND;

        return;
    }

    if (MODE_INVALID == selectedMode || selectedMode > MODE_3) {
        lastError = ERROR_INVALID_MODE;

        return;
    }



    lastError = NO_ERROR;
    cout << "Resource with id: " << to_string(boundReference) << " used with mode: " << to_string(selectedMode) << endl;
}

uint8_t getNewReference()
{
    auto newReference = nextReference++;
    if (INVALID_REFERENCE == nextReference) {
        newReference = 0;
    }

    return newReference;
}