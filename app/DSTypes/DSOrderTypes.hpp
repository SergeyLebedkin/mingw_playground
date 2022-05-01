#pragma once

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

// dental system types predefinitions
class DSToothElement;
class DSModelElement;
class DSScan;
class DSOrder;

// dental system types shared pointer predefinitions
typedef std::shared_ptr<DSToothElement> DSToothElementSPtr;
typedef std::shared_ptr<DSModelElement> DSModelElementSPtr;
typedef std::shared_ptr<DSScan>         DSScanSPtr;
typedef std::shared_ptr<DSOrder>        DSOrderSPtr;

// dental system tooth element
class DSToothElement {
public:
    // base properties
    std::string id = "";
    uint32_t    unn = 0;

private:
    // contructors
    DSToothElement(const std::string_view id, const uint32_t unn)
        : id(id), unn(unn) {}

public:
    // static functions
    static DSToothElementSPtr create(const std::string_view id = "") {
        return std::make_shared<DSToothElement>(DSToothElement(id, 0));
    }
};

// dental system model element
class DSModelElement {
public:
    // base properties
    std::string id = "";
    // tooth elements
    std::vector<DSToothElementSPtr> ToothElements;

private:
    // contructors
    DSModelElement(const std::string_view id) : id(id) {}

public:
    // static functions
    static DSModelElementSPtr create(const std::string_view id = "") {
        return std::make_shared<DSModelElement>(DSModelElement(id));
    }
};

// dental system scan
class DSScan {
public:
    // base properties
    std::string id = "";
    std::string fileName = "";

private:
    // contructors
    DSScan(const std::string_view id) : id(id) {}

public:
    // static functions
    static DSScanSPtr create(const std::string_view id = "") {
        return std::make_shared<DSScan>(DSScan(id));
    }
};

// dental system order
class DSOrder {
public:
    // base properties
    std::string id = "";
    std::string description = "";
    std::string firstName = "";
    std::string lastName = "";
    // model elements
    std::vector<DSModelElementSPtr> ModelElements;
    // scans
    std::vector<DSScanSPtr> Scans;

private:
    // contructors
    DSOrder(const std::string_view id = "") : id(id) {}

public:
    // static functions
    static DSOrderSPtr create(const std::string_view id = "") {
        return std::make_shared<DSOrder>(DSOrder(id));
    }
};