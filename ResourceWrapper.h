#ifndef CPP_MOVE_RESOURCEWRAPPER_H
#define CPP_MOVE_RESOURCEWRAPPER_H

#include "OldResource.h"

class ResourceWrapper {
public:
    ResourceWrapper();
    ~ResourceWrapper();

    ResourceWrapper(ResourceWrapper const &other) = delete;
    ResourceWrapper& operator= (ResourceWrapper const &other) = delete;

    void bind(uint8_t mode) const;
    void use() const;

private:
    uint8_t reference;
};

#endif //CPP_MOVE_RESOURCEWRAPPER_H
