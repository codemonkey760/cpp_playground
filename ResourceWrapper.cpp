#include <stdexcept>

#include "OldResourceException.h"
#include "OldResource.h"
#include "ResourceWrapper.h"

using std::runtime_error;
using std::to_string;

ResourceWrapper::ResourceWrapper()
{
    this->reference = createResource();
    if (this->reference == INVALID_REFERENCE) {
        throw OldResourceException("Could not allocate resource", getLastError());
    }
}

ResourceWrapper::~ResourceWrapper()
{
    if (INVALID_REFERENCE == this->reference) {
        return;
    }

    destroyResource(this->reference);
}

void ResourceWrapper::bind(uint8_t mode) const
{
    bindResource(this->reference, mode);

    auto errorCode = getLastError();
    if (NO_ERROR != errorCode) {
        throw OldResourceException("Could not bind resource", errorCode);
    }
}

void ResourceWrapper::use() const
{
    useResource();

    auto errorCode = getLastError();
    if (NO_ERROR != errorCode) {
        throw OldResourceException("Could not use resource", errorCode);
    }
}