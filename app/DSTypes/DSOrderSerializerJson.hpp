#pragma once

#include "DSOrderSerializer.hpp"

// dental system order serializer interface
class DSOrderSerializerJson: public DSOrderSerializer {
public:
    // deserialize to order list from file
    virtual DSOrderElementListSPtr
    read_from_file(const std::filesystem::path path) {
        return DSOrderElementList::create();
    }

    // serialize order list to file
    virtual void write_to_file(const DSOrderElementListSPtr list,
                               const std::filesystem::path  path) {}
};