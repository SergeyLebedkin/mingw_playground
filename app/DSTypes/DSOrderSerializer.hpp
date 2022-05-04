#pragma once

#include "DSOrderTypes.hpp"
#include <filesystem>

// dental system order serializer interface
class DSOrderSerializer {
public:
    // deserialize to order list from file
    virtual bool read_from_file(const DSOrderElementListSPtr list,
                                const std::filesystem::path  path) = 0;

    // serialize order list to file
    virtual bool write_to_file(const DSOrderElementListSPtr list,
                               const std::filesystem::path  path) = 0;
};