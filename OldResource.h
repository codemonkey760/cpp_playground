#ifndef CPP_MOVE_OLDRESOURCE_H
#define CPP_MOVE_OLDRESOURCE_H

#include <cstdint>
#include <algorithm>
#include <iostream>
#include <string>

#define INVALID_REFERENCE UINT8_MAX
#define MAX_RESOURCES 16

#define NO_ERROR 0
#define ERROR_NO_FREE_RESOURCES 1
#define ERROR_INVALID_ARGUMENT 2
#define ERROR_INVALID_MODE 3
#define ERROR_NO_RESOURCE_BOUND 4

#define MODE_INVALID 0
#define MODE_1 1
#define MODE_2 2
#define MODE_3 3

using std::uint8_t;
using std::begin;
using std::end;
using std::find;
using std::count;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

static uint8_t references[MAX_RESOURCES] = {INVALID_REFERENCE};
static uint8_t nextReference = 0;
static int lastError = NO_ERROR;

static uint8_t boundReference = INVALID_REFERENCE;
static uint8_t selectedMode = MODE_INVALID;

uint8_t createResource();
void destroyResource(uint8_t reference);
int freeResourceCount();
int getLastError();

void bindResource(uint8_t reference, uint8_t mode);
void useResource();

static uint8_t getNewReference();

#endif //CPP_MOVE_OLDRESOURCE_H
