#pragma once

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

// dental system types predefinitions
class DSToothElement;
class DSModelElement;
class DSOrder;

//  dental system types shared pointer predefinitions
typedef std::shared_ptr<DSToothElement> DSToothElementSPtr;
typedef std::shared_ptr<DSModelElement> DSModelElementSPtr;
typedef std::shared_ptr<DSOrder>        DSOrderSPtr;

// dental system tooth element
class DSToothElement {
public:
    // base properties
    std::string Id = "";
    uint32_t    Unn = 0;

private:
    // contructors
    DSToothElement(const std::string_view id, const uint32_t unn)
        : Id(id.begin(), id.end()), Unn(unn) {}

public:
    // static functions
    static DSToothElementSPtr create(const std::string_view id = "") {
        return std::make_shared<DSToothElement>(id, 0);
    }
};

// dental system model element
class DSModelElement {
public:
    // base properties
    std::string Id = "";
    // tooth elements
    std::vector<DSToothElementSPtr> ToothElements;

private:
    // contructors
    DSModelElement(const std::string_view id) : Id(id.begin(), id.end()) {}

public:
    // static functions
    static DSModelElementSPtr create(const std::string_view id = "") {
        return std::make_shared<DSModelElement>(id);
    }
};

// dental system order
class DSOrder {
public:
    // base properties
    std::string Id = "";
    std::string FirstName = "";
    std::string LastName = "";
    // model elements
    std::vector<DSModelElementSPtr> ModelElements;

private:
    // contructors
    DSOrder(const std::string_view Id = "") : Id(Id.begin(), Id.end()) {}

public:
    // static functions
    static DSOrderSPtr create(const std::string_view Id = "") {
        return std::make_shared<DSOrder>(Id);
    }
};