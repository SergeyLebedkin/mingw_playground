#include "DSTypes/DSOrderTypes.hpp"
#include <iostream>

int main(int argc, char** argv) {
    auto order = DSOrder::create("OrderId_01");
    order->modelElements = { DSModelElement::create("ModelElementId_01"),
                             DSModelElement::create("ModelElementId_02") };
    for (const auto& me: order->modelElements)
        std::cout << me->id << std::endl;
    return 0;
}