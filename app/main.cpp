#include "DSTypes/DSOrderTypes.hpp"
#include <chrono>
#include <filesystem>
#include <iostream>

// PrintOrderDescription
void PrintOrderDescription(DSOrderElementListSPtr orders) {
    for (const auto& order: orders->as_vector()) {
        std::cout << order->id << std::endl;
        // model elements
        for (const auto& model: order->modelElementList->as_vector()) {
            std::cout << "\t" << model->id << std::endl;
            // tooth elements
            for (const auto& tooth: model->toothElementList->as_vector())
                std::cout << "\t\t" << tooth->id << ", unn: " << tooth->unn
                          << std::endl;
        }
        // scan elements
        for (const auto& scan: order->scanElementList->as_vector())
            std::cout << "\t" << scan->id << std::endl;
    }
}

int main(int argc, char** argv) {
    // create order
    auto orders = DSOrderElementList::create({
        DSOrderElement::create("OrderID_01", {
            DSModelElement::create("ModelID_01", {
                DSToothElement::create("ToothID_01", 4),
                DSToothElement::create("ToothID_02", 5),
                DSToothElement::create("ToothID_03", 6) 
            }),
            DSModelElement::create("ModelID_02", { 
                DSToothElement::create("ToothID_04", 22),
                DSToothElement::create("ToothID_05", 23),
                DSToothElement::create("ToothID_06", 24)
            })},{
            DSScanElement::create("ScanID_01"),
            DSScanElement::create("ScanID_02")
        }),
        DSOrderElement::create("OrderID_02", {
            DSModelElement::create("ModelID_03", {
                DSToothElement::create("ToothID_07", 4),
                DSToothElement::create("ToothID_08", 5),
                DSToothElement::create("ToothID_09", 6) 
            }),
            DSModelElement::create("ModelID_03", { 
                DSToothElement::create("ToothID_10", 22),
                DSToothElement::create("ToothID_11", 23),
                DSToothElement::create("ToothID_11", 24)
            })},{
            DSScanElement::create("ScanID_01"),
            DSScanElement::create("ScanID_02")
        }),
    });

    // print order description
    PrintOrderDescription(orders);

    return 0;
}