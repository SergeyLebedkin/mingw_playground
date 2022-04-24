#include <iostream>
#include "DSOrderTypes.hpp"

int main(int argc, char** argv) {
    auto order = DSOrder::create();
    order->ModelElements = {
        DSModelElement::create("ME-01"),
        DSModelElement::create("ME-02")
    };
    std::cout << "Hello, World!" << std::endl;
    return 0;
}