#include <iostream>
#include "DSOrderTypes.hpp"

int main(int argc, char** argv) {
    auto order = DSOrder::create("OrderId_01");
    order->ModelElements = {
        DSModelElement::create("ModelElementId_01"),
        DSModelElement::create("ModelElementId_02")
    };
    std::cout << "Hello, World!" << std::endl;
    return 0;
}