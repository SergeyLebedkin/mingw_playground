#include "DSOrderSerializerXml.hpp"
#include <fstream>

// write to xml node
void DSOrderSerializerXml::write_to_xml_node(const DSOrderElementListSPtr list,
                                             pugi::xml_node node) {
    // create order element list node
    auto orderListNode = node.append_child("OrderElementList");
    for (const auto& order: list->as_vector()) {
        // create order element node
        auto orderNode = orderListNode.append_child("OrderElement");
        orderNode.append_child("ID").text() = order->id.c_str();
        orderNode.append_child("Description").text() = order->description.c_str();
        orderNode.append_child("FirstName").text() = order->firstName.c_str();
        orderNode.append_child("LastName").text() = order->lastName.c_str();
        // create model element list node
        auto modelListNode = orderNode.append_child("ModelElementList");
        for (const auto& model: order->modelElementList->as_vector()) {
            // create model element node
            auto modelNode = modelListNode.append_child("ModelElement");
            modelNode.append_child("ID").text() = model->id.c_str();
            // create tooth element list node
            auto toothListNode = modelNode.append_child("ToothElementList");
            for (const auto& tooth: model->toothElementList->as_vector()) {
                // create tooth element node
                auto toothNode = toothListNode.append_child("ToothElement");
                toothNode.append_child("ID").text() = tooth->id.c_str();
                toothNode.append_child("Unn").text() = tooth->unn;
            }
        }
        // create scan element list node
        auto scanListNode = orderNode.append_child("ScanElementList");
        for (const auto& scan: order->scanElementList->as_vector()) {
            // create scan element node
            auto scanNode = scanListNode.append_child("ScanElement");
            scanNode.append_child("ID").text() = scan->id.c_str();
            scanNode.append_child("FileName").text() = scan->fileName.c_str();
        }
    }
}

// serialize order list to file
bool DSOrderSerializerXml::write_to_file(const DSOrderElementListSPtr list,
                                         const std::filesystem::path  path) {
    // create xml document
    pugi::xml_document doc;

    // write to xml node
    write_to_xml_node(list, doc);
    
    // save to file
    return doc.save_file(path.c_str());
}
