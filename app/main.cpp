#include "DSTypes/DSOrderTypes.hpp"
#include <iostream>

int main(int argc, char** argv) {
    auto order = DSOrder::create("OrderId_01");
    order->ModelElements = { DSModelElement::create("ModelElementId_01"),
                             DSModelElement::create("ModelElementId_02") };
    for (const auto& me: order->ModelElements)
        std::cout << me->id << std::endl;
    return 0;
}