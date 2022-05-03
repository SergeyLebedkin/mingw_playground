#pragma once

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

// dental system types predefinitions
class DSToothElement;
class DSModelElement;
class DSScanElement;
class DSOrderElement;

// dental system lists predefinitions
class DSToothElementList;
class DSModelElementList;
class DSScanElementList;
class DSOrderElementList;

// dental system types shared pointer predefinitions
typedef std::shared_ptr<DSToothElement> DSToothElementSPtr;
typedef std::shared_ptr<DSModelElement> DSModelElementSPtr;
typedef std::shared_ptr<DSScanElement>  DSScanElementSPtr;
typedef std::shared_ptr<DSOrderElement> DSOrderElementSPtr;

// dental system types shared pointerlists  predefinitions
typedef std::shared_ptr<DSToothElementList> DSToothElementListSPtr;
typedef std::shared_ptr<DSModelElementList> DSModelElementListSPtr;
typedef std::shared_ptr<DSScanElementList>  DSScanElementListSPtr;
typedef std::shared_ptr<DSOrderElementList> DSOrderElementListSPtr;

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

    // contructors
    DSToothElementList(const std::initializer_list<DSToothElementSPtr> il = {})
        : list(il){};

public:
    // append element
    void append(const DSToothElementSPtr item) {
        // check for nullptr
        if (item)
            if (!exists(item->id))
                list.push_back(item);
    }

    // remove element by id
    void remove(const std::string_view id) {
        auto find_id = [&](const auto& item) { return item->id == id; };
        auto it = std::remove_if(list.begin(), list.end(), find_id);
        list.erase(it, list.end());
    }

    // check if element exists by id
    bool exists(const std::string_view id) const {
        auto find_id = [&](const auto& item) { return item->id == id; };
        auto it = std::find_if(list.begin(), list.end(), find_id);
        return it != list.end();
    }

    // find element by id
    auto find(const std::string_view id) const {
        auto find_id = [&](const auto& item) { return item->id == id; };
        auto it = std::find_if(list.begin(), list.end(), find_id);
        return it == list.end() ? nullptr : *it;
    }

    // clear elements
    void clear() noexcept { list.clear(); }

    // operator [id]
    const auto operator[](const std::string_view id) const { return find(id); }

    // get as vector
    const auto& as_vector() const noexcept { return list; }

public:
    // create
    static DSToothElementListSPtr
    create(const std::initializer_list<DSToothElementSPtr> il = {}) {
        return std::make_shared<DSToothElementList>(DSToothElementList(il));
    }
};

// dental system model element
class DSModelElement {
public:
    // base properties
    std::string id = "";
    // element list
    DSToothElementListSPtr toothElementList;

private:
    // contructors
    DSModelElement(const std::string_view id)
        : id(id), toothElementList(DSToothElementList::create()) {}

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

    // contructors
    DSModelElementList(const std::initializer_list<DSModelElementSPtr> il = {})
        : list(il){};

public:
    // append element
    void append(const DSModelElementSPtr item) {
        // check for nullptr
        if (item)
            if (!exists(item->id))
                list.push_back(item);
    }

    // remove element by id
    void remove(const std::string_view id) {
        auto find_id = [&](const auto& item) { return item->id == id; };
        auto it = std::remove_if(list.begin(), list.end(), find_id);
        list.erase(it, list.end());
    }

    // check if element exists by id
    bool exists(const std::string_view id) const {
        auto find_id = [&](const auto& item) { return item->id == id; };
        auto it = std::find_if(list.begin(), list.end(), find_id);
        return it != list.end();
    }

    // find element by id
    auto find(const std::string_view id) const {
        auto find_id = [&](const auto& item) { return item->id == id; };
        auto it = std::find_if(list.begin(), list.end(), find_id);
        return it == list.end() ? nullptr : *it;
    }

    // clear elements
    void clear() noexcept { list.clear(); }

    // operator [id]
    const auto operator[](const std::string_view id) const { return find(id); }

    // get as vector
    const auto& as_vector() const noexcept { return list; }

public:
    // create
    static DSModelElementListSPtr
    create(const std::initializer_list<DSModelElementSPtr> il = {}) {
        return std::make_shared<DSModelElementList>(DSModelElementList(il));
    }
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

    // contructors
    DSScanElementList(const std::initializer_list<DSScanElementSPtr> il = {})
        : list(il){};

public:
    // append element
    void append(const DSScanElementSPtr item) {
        // check for nullptr
        if (item)
            if (!exists(item->id))
                list.push_back(item);
    }

    // remove element by id
    void remove(const std::string_view id) {
        auto find_id = [&](const auto& item) { return item->id == id; };
        auto it = std::remove_if(list.begin(), list.end(), find_id);
        list.erase(it, list.end());
    }

    // check if element exists by id
    bool exists(const std::string_view id) const {
        auto find_id = [&](const auto& item) { return item->id == id; };
        auto it = std::find_if(list.begin(), list.end(), find_id);
        return it != list.end();
    }

    // find element by id
    auto find(const std::string_view id) const {
        auto find_id = [&](const auto& item) { return item->id == id; };
        auto it = std::find_if(list.begin(), list.end(), find_id);
        return it == list.end() ? nullptr : *it;
    }

    // clear elements
    void clear() noexcept { list.clear(); }

    // operator [id]
    const auto operator[](const std::string_view id) const { return find(id); }

    // get as vector
    const auto& as_vector() const noexcept { return list; }

public:
    // create
    static DSScanElementListSPtr
    create(const std::initializer_list<DSScanElementSPtr> il = {}) {
        return std::make_shared<DSScanElementList>(DSScanElementList(il));
    }
};

// dental system order
class DSOrderElement {
public:
    // base properties
    std::string id = "";
    std::string description = "";
    std::string firstName = "";
    std::string lastName = "";
    // model elements
    DSModelElementListSPtr modelElementList;
    // scan elements
    DSScanElementListSPtr scanElementList;

private:
    // contructors
    DSOrderElement(const std::string_view id = "")
        : id(id), modelElementList(DSModelElementList::create()),
          scanElementList(DSScanElementList::create()) {}

public:
    // static functions
    static DSOrderElementSPtr create(const std::string_view id = "") {
        return std::make_shared<DSOrderElement>(DSOrderElement(id));
    }
};

// dental system order list
class DSOrderElementList {
private:
    // container
    std::vector<DSOrderElementSPtr> list;

    // contructors
    DSOrderElementList(const std::initializer_list<DSOrderElementSPtr> il = {})
        : list(il){};

public:
    // append element
    void append(const DSOrderElementSPtr item) {
        // check for nullptr
        if (item)
            if (!exists(item->id))
                list.push_back(item);
    }

    // remove element by id
    void remove(const std::string_view id) {
        auto find_id = [&](const auto& item) { return item->id == id; };
        auto it = std::remove_if(list.begin(), list.end(), find_id);
        list.erase(it, list.end());
    }

    // check if element exists by id
    bool exists(const std::string_view id) const {
        auto find_id = [&](const auto& item) { return item->id == id; };
        auto it = std::find_if(list.begin(), list.end(), find_id);
        return it != list.end();
    }

    // find element by id
    auto find(const std::string_view id) const {
        auto find_id = [&](const auto& item) { return item->id == id; };
        auto it = std::find_if(list.begin(), list.end(), find_id);
        return it == list.end() ? nullptr : *it;
    }

    // clear elements
    void clear() noexcept { list.clear(); }

    // operator [id]
    const auto operator[](const std::string_view id) const { return find(id); }

    // get as vector
    const auto& as_vector() const noexcept { return list; }

public:
    // create
    static DSOrderElementListSPtr
    create(const std::initializer_list<DSOrderElementSPtr> il = {}) {
        return std::make_shared<DSOrderElementList>(DSOrderElementList(il));
    }
};