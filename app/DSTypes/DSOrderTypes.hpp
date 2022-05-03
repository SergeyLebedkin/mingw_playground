#pragma once

#include <algorithm>
#include <iostream>
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

// dental system types shared pointer lists predefinitions
typedef std::shared_ptr<DSToothElementList> DSToothElementListSPtr;
typedef std::shared_ptr<DSModelElementList> DSModelElementListSPtr;
typedef std::shared_ptr<DSScanElementList>  DSScanElementListSPtr;
typedef std::shared_ptr<DSOrderElementList> DSOrderElementListSPtr;

// dental system initializer list
typedef std::initializer_list<DSToothElementSPtr> DSToothElementInitList;
typedef std::initializer_list<DSModelElementSPtr> DSModelElementInitList;
typedef std::initializer_list<DSScanElementSPtr>  DSScanElementInitList;
typedef std::initializer_list<DSOrderElementSPtr> DSOrderElementInitList;

// base dental system element
class DSElement {
public:
    // properties
    std::string id = "";

protected:
    DSElement(const std::string_view id) : id(id) {}
};

// base dental system element list template
template <typename DSElementSPtr> class DSElementList {
protected:
    // container
    std::vector<DSElementSPtr> list;

    // contructors
    DSElementList(const std::initializer_list<DSElementSPtr> il) {
        auto append_item = [&](const auto& item) { this->append(item); };
        std::for_each(il.begin(), il.end(), append_item);
    };

public:
    // append element
    void append(const DSElementSPtr item) {
        // check for nullptr
        if (item)
            if (!exists(item->id))
                list.push_back(item);
    }

    // append element list
    void append_list(const DSElementList& lst) {
        auto append_item = [&](const auto& item) { this->append(item); };
        auto vec = lst.as_vector();
        std::for_each(vec.cbegin(), vec.cend(), append_item);
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
    DSElementSPtr find(const std::string_view id) const {
        auto find_id = [&](const auto& item) { return item->id == id; };
        auto it = std::find_if(list.begin(), list.end(), find_id);
        return it == list.end() ? nullptr : *it;
    }

    // operator [id]
    const auto operator[](const std::string_view id) const { return find(id); }

    // clear elements
    void clear() noexcept { list.clear(); }

    // size elements
    size_t size() const noexcept { return list.size(); }

    // get as vector
    const auto& as_vector() const noexcept { return list; }
};

// dental system tooth element
class DSToothElement: public DSElement {
public:
    // properties
    uint32_t unn = 0;

protected:
    // contructor
    DSToothElement(const std::string_view id, uint32_t unn)
        : DSElement(id), unn(unn) {}

public:
    // create
    static DSToothElementSPtr create(const std::string_view id = "",
                                     const uint32_t         unn = 0) {
        return std::make_shared<DSToothElement>(DSToothElement(id, unn));
    }
};

// dental system tooth element list
class DSToothElementList: public DSElementList<DSToothElementSPtr> {
protected:
    // contructors
    DSToothElementList(const DSToothElementInitList il)
        : DSElementList<DSToothElementSPtr>(il) {}

public:
    // remove element by unn
    void remove_unn(const uint32_t unn) {
        auto find_unn = [&](const auto& item) { return item->unn == unn; };
        auto it = std::remove_if(list.begin(), list.end(), find_unn);
        list.erase(it, list.end());
    }

public:
    // create
    static DSToothElementListSPtr create(const DSToothElementInitList il = {}) {
        return std::make_shared<DSToothElementList>(DSToothElementList(il));
    }
};

// dental system model element
class DSModelElement: public DSElement {
public:
    // element list
    DSToothElementListSPtr toothElementList;

private:
    // contructors
    DSModelElement(const std::string_view id, const DSToothElementInitList teil)
        : DSElement(id), toothElementList(DSToothElementList::create(teil)) {}

public:
    // static functions
    static DSModelElementSPtr create(const std::string_view       id = "",
                                     const DSToothElementInitList teil = {}) {
        return std::make_shared<DSModelElement>(DSModelElement(id, teil));
    }
};

// dental system model element list
class DSModelElementList: public DSElementList<DSModelElementSPtr> {
protected:
    // contructors
    DSModelElementList(const DSModelElementInitList il)
        : DSElementList<DSModelElementSPtr>(il) {}

public:
    // create
    static DSModelElementListSPtr create(const DSModelElementInitList il = {}) {
        return std::make_shared<DSModelElementList>(DSModelElementList(il));
    }
};

// dental system scan element
class DSScanElement: public DSElement {
public:
    // base properties
    std::string fileName = "";

private:
    // contructors
    DSScanElement(const std::string_view id) : DSElement(id) {}

public:
    // static functions
    static DSScanElementSPtr create(const std::string_view id = "") {
        return std::make_shared<DSScanElement>(DSScanElement(id));
    }
};

// dental system scan element list
class DSScanElementList: public DSElementList<DSScanElementSPtr> {
protected:
    // contructors
    DSScanElementList(const DSScanElementInitList il)
        : DSElementList<DSScanElementSPtr>(il) {}

public:
    // create
    static DSScanElementListSPtr create(const DSScanElementInitList il = {}) {
        return std::make_shared<DSScanElementList>(DSScanElementList(il));
    }
};

// dental system order element
class DSOrderElement: public DSElement {
public:
    // base properties
    std::string description = "";
    std::string firstName = "";
    std::string lastName = "";
    // model elements
    DSModelElementListSPtr modelElementList;
    // scan elements
    DSScanElementListSPtr scanElementList;

private:
    // contructors
    DSOrderElement(const std::string_view id, const DSModelElementInitList meil,
                   const DSScanElementInitList seil)
        : DSElement(id), modelElementList(DSModelElementList::create(meil)),
          scanElementList(DSScanElementList::create(seil)) {}

public:
    // static functions
    static DSOrderElementSPtr create(const std::string_view       id = "",
                                     const DSModelElementInitList meil = {},
                                     const DSScanElementInitList  seil = {}) {
        return std::make_shared<DSOrderElement>(DSOrderElement(id, meil, seil));
    }
};

// dental system order element list
class DSOrderElementList: public DSElementList<DSOrderElementSPtr> {
protected:
    // contructors
    DSOrderElementList(const DSOrderElementInitList il)
        : DSElementList<DSOrderElementSPtr>(il) {}

public:
    // create
    static DSOrderElementListSPtr create(const DSOrderElementInitList il = {}) {
        return std::make_shared<DSOrderElementList>(DSOrderElementList(il));
    }
};