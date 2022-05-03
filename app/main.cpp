#include "DSTypes/DSOrderTypes.hpp"
#include <chrono>
#include <filesystem>
#include <iostream>

// PrintOrderDescription
void PrintOrderDescription(DSOrderElementSPtr order) {
    std::cout << order->id << std::endl;
    // model elements
    const DSModelElementList& models = *(order->modelElementList);
    for (const auto& model: models.as_vector()) {
        std::cout << "\t" << model->id << std::endl;
        // tooth elements
        const DSToothElementList& teeth = *(model->toothElementList);
        for (const auto& tooth: teeth.as_vector())
            std::cout << "\t\t" << tooth->id << std::endl;
    }
    // scan elements
    const DSScanElementList& scans = *(order->scanElementList);
    for (const auto& scan: scans.as_vector())
        std::cout << "\t" << scan->id << std::endl;
}

int main(int argc, char** argv) {
    // bsae types
    DSOrderElementSPtr order;
    DSScanElementSPtr  scan;
    DSModelElementSPtr model;
    DSToothElementSPtr tooth;
    // create order
    order = DSOrderElement::create("OrderID_01");
    // create scans
    scan = DSScanElement::create("ScanID_01");
    order->scanElementList->append(scan);
    scan = DSScanElement::create("ScanID_02");
    order->scanElementList->append(scan);
    // create model elements
    model = DSModelElement::create("ModelID_01");
    order->modelElementList->append(model);
    // create tooth elements
    tooth = DSToothElement::create("ToothID_01");
    model->toothElementList->append(tooth);
    tooth = DSToothElement::create("ToothID_02");
    model->toothElementList->append(tooth);
    tooth = DSToothElement::create("ToothID_03");
    model->toothElementList->append(tooth);
    // create model elements
    model = DSModelElement::create("ModelID_02");
    order->modelElementList->append(model);
    // create tooth elements
    tooth = DSToothElement::create("ToothID_04");
    model->toothElementList->append(tooth);
    tooth = DSToothElement::create("ToothID_05");
    model->toothElementList->append(tooth);
    tooth = DSToothElement::create("ToothID_06");
    model->toothElementList->append(tooth);

    // print order description
    PrintOrderDescription(order);

    return 0;
}