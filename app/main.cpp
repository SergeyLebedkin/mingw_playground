#include "DSTypes/DSOrderTypes.hpp"
#include <iostream>
#include <chrono>

int main(int argc, char** argv) {
    auto order = DSOrder::create("OrderId_01");
    order->modelElements.append(DSModelElement::create("ModelElementId_01"));
    order->modelElements.append(DSModelElement::create("ModelElementId_02"));
    auto& toothElements = order->modelElements["ModelElementId_02"]->toothElements;
    //toothElements.append(DSToothElement::create("ToothlElementId_01"));
    //toothElements.append(DSToothElement::create("ToothlElementId_02"));
    //toothElements.append(DSToothElement::create("ToothlElementId_03"));
    toothElements.append(DSToothElement::create("ToothlElementId_03"));
    std::cout << toothElements.exists("ToothlElementId_03") << std::endl;
    toothElements.remove("ToothlElementId_03");
    std::cout << toothElements.exists("ToothlElementId_03") << std::endl;
    std::cout << toothElements.exists("ToothlElementId_04") << std::endl;
    std::cout << toothElements.exists("ToothlElementId_04") << std::endl;
    //std::cout << toothElements.find("ToothlElementId_03")->id << std::endl;
    //std::cout << toothElements["ToothlElementId_00"]->id << std::endl;
    std::cout << "===============" << std::endl;
    for (const auto& te: toothElements.as_vector())
        std::cout << te->id << std::endl;
    return 0;
}