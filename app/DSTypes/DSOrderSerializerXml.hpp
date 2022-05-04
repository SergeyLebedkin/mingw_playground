#pragma once

#include "DSOrderSerializer.hpp"
#include <pugixml.hpp>

// dental system order serializer interface
class DSOrderSerializerXml: public DSOrderSerializer {
private:
    // read from xml node
    void read_from_xml_node(const DSOrderElementListSPtr list,
                            const pugi::xml_node         node){};

    // write to xml node
    void write_to_xml_node(const DSOrderElementListSPtr list,
                           pugi::xml_node               node);

public:
    // deserialize to order list from file
    virtual bool read_from_file(const DSOrderElementListSPtr list,
                                const std::filesystem::path  path) {
        return false;
    };

    // serialize order list to file
    virtual bool write_to_file(const DSOrderElementListSPtr list,
                               const std::filesystem::path  path);
};