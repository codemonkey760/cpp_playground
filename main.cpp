#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#include "ResourceWrapper.h"

using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::generate;

static vector<shared_ptr<ResourceWrapper>> createResources()
{
    vector<shared_ptr<ResourceWrapper>> resources(5);

    auto resourceGenerator = []() {
        return make_shared<ResourceWrapper>();
    };

    generate(begin(resources), end(resources), resourceGenerator);

    return resources;
}

int main() {
    auto resources = createResources();


}
