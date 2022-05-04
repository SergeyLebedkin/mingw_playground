#pragma once

#include "DSOrderSerializer.hpp"

// dental system order serializer interface
class DSOrderSerializerJson: public DSOrderSerializer {
public:
    // deserialize to order list from file
    virtual bool read_from_file(const DSOrderElementListSPtr list,
                                const std::filesystem::path  path) {
        return false;
    }

    // serialize order list to file
    virtual bool write_to_file(const DSOrderElementListSPtr list,
                               const std::filesystem::path  path) {
        return false;
    }
};