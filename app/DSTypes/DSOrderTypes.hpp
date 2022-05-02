#pragma once

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

// dental system types predefinitions
class DSToothElement;
class DSModelElement;
class DSScanElement;
class DSOrder;

// dental system types shared pointer predefinitions
typedef std::shared_ptr<DSToothElement> DSToothElementSPtr;
typedef std::shared_ptr<DSModelElement> DSModelElementSPtr;
typedef std::shared_ptr<DSScanElement>  DSScanElementSPtr;
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

// dental system tooth element list
class DSToothElementList {
private:
    // container
    std::vector<DSToothElementSPtr> list;

public:
    // contructors
    DSToothElementList(const std::initializer_list<DSToothElementSPtr> il = {})
        : list(il){};

    // append tooth element
    void append(const DSToothElementSPtr item) {
        // check for nullptr
        if (item)
            if (!exists(item->id))
                list.push_back(item);
    }

    // remove tooth element by id
    void remove(const std::string_view id) {
        auto find_id = [&](const auto& item) { return item->id == id; };
        auto it = std::remove_if(list.begin(), list.end(), find_id);
        list.erase(it, list.end());
    }

    // check if tooth element exists by id
    bool exists(const std::string_view id) const {
        auto find_id = [&](const auto& item) { return item->id == id; };
        auto it = std::find_if(list.begin(), list.end(), find_id);
        return it != list.end();
    }

    // find tooth element by id
    auto find(const std::string_view id) const {
        auto find_id = [&](const auto& item) { return item->id == id; };
        auto it = std::find_if(list.begin(), list.end(), find_id);
        return it == list.end() ? nullptr : *it;
    }

    // operator [id]
    const auto operator[](const std::string_view id) const { return find(id); }

    // get as vector
    const auto& as_vector() const { return list; }
};

// dental system model element
class DSModelElement {
public:
    // base properties
    std::string id = "";
    // tooth element list
    DSToothElementList toothElements;

private:
    // contructors
    DSModelElement(const std::string_view id) : id(id) {}

public:
    // static functions
    static DSModelElementSPtr create(const std::string_view id = "") {
        return std::make_shared<DSModelElement>(DSModelElement(id));
    }
};

// dental system model element list
class DSModelElementList {
private:
    // container
    std::vector<DSModelElementSPtr> list;

public:
    // contructors
    DSModelElementList(const std::initializer_list<DSModelElementSPtr> il = {})
        : list(il){};

    // append tooth element
    void append(const DSModelElementSPtr item) {
        // check for nullptr
        if (item)
            if (!exists(item->id))
                list.push_back(item);
    }

    // remove tooth element by id
    void remove(const std::string_view id) {
        auto find_id = [&](const auto& item) { return item->id == id; };
        auto it = std::remove_if(list.begin(), list.end(), find_id);
        list.erase(it, list.end());
    }

    // check if tooth element exists by id
    bool exists(const std::string_view id) const {
        auto find_id = [&](const auto& item) { return item->id == id; };
        auto it = std::find_if(list.begin(), list.end(), find_id);
        return it != list.end();
    }

    // find tooth element by id
    auto find(const std::string_view id) const {
        auto find_id = [&](const auto& item) { return item->id == id; };
        auto it = std::find_if(list.begin(), list.end(), find_id);
        return it == list.end() ? nullptr : *it;
    }

    // operator [id]
    const auto operator[](const std::string_view id) const { return find(id); }

    // get as vector
    const auto& as_vector() const { return list; }
};

// dental system scan element
class DSScanElement {
public:
    // base properties
    std::string id = "";
    std::string fileName = "";

private:
    // contructors
    DSScanElement(const std::string_view id) : id(id) {}

public:
    // static functions
    static DSScanElementSPtr create(const std::string_view id = "") {
        return std::make_shared<DSScanElement>(DSScanElement(id));
    }
};

// dental system scan element list
class DSScanElementList {
private:
    // container
    std::vector<DSScanElementSPtr> list;

public:
    // contructors
    DSScanElementList(const std::initializer_list<DSScanElementSPtr> il = {}) : list(il){};

    // append tooth element
    void append(const DSScanElementSPtr item) {
        // check for nullptr
        if (item)
            if (!exists(item->id))
                list.push_back(item);
    }

    // remove tooth element by id
    void remove(const std::string_view id) {
        auto find_id = [&](const auto& item) { return item->id == id; };
        auto it = std::remove_if(list.begin(), list.end(), find_id);
        list.erase(it, list.end());
    }

    // check if tooth element exists by id
    bool exists(const std::string_view id) const {
        auto find_id = [&](const auto& item) { return item->id == id; };
        auto it = std::find_if(list.begin(), list.end(), find_id);
        return it != list.end();
    }

    // find tooth element by id
    auto find(const std::string_view id) const {
        auto find_id = [&](const auto& item) { return item->id == id; };
        auto it = std::find_if(list.begin(), list.end(), find_id);
        return it == list.end() ? nullptr : *it;
    }

    // operator [id]
    const auto operator[](const std::string_view id) const { return find(id); }

    // get as vector
    const auto& as_vector() const { return list; }
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
    DSModelElementList modelElements;
    // scan elements
    DSScanElementList scanElements;

private:
    // contructors
    DSOrder(const std::string_view id = "") : id(id) {}

public:
    // static functions
    static DSOrderSPtr create(const std::string_view id = "") {
        return std::make_shared<DSOrder>(DSOrder(id));
    }
};

// dental system order list
class DSOrderList {
private:
    // container
    std::vector<DSOrderSPtr> list;

public:
    // contructors
    DSOrderList(const std::initializer_list<DSOrderSPtr> il = {}) : list(il){};

    // append tooth element
    void append(const DSOrderSPtr item) {
        // check for nullptr
        if (item)
            if (!exists(item->id))
                list.push_back(item);
    }

    // remove tooth element by id
    void remove(const std::string_view id) {
        auto find_id = [&](const auto& item) { return item->id == id; };
        auto it = std::remove_if(list.begin(), list.end(), find_id);
        list.erase(it, list.end());
    }

    // check if tooth element exists by id
    bool exists(const std::string_view id) const {
        auto find_id = [&](const auto& item) { return item->id == id; };
        auto it = std::find_if(list.begin(), list.end(), find_id);
        return it != list.end();
    }

    // find tooth element by id
    auto find(const std::string_view id) const {
        auto find_id = [&](const auto& item) { return item->id == id; };
        auto it = std::find_if(list.begin(), list.end(), find_id);
        return it == list.end() ? nullptr : *it;
    }

    // operator [id]
    const auto operator[](const std::string_view id) const { return find(id); }

    // get as vector
    const auto& as_vector() const { return list; }
};