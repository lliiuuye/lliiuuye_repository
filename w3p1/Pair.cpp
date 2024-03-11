//#include "Collection.h"
#include "Pair.h"
#include <iostream>
#include <array>
#include <typeinfo>
#include <type_traits>
#include <iomanip>

//using namespace seneca;
namespace seneca {

    Pair::Pair() : m_key("void"), m_value("void") {};

    Pair::Pair(const std::string& key, const std::string& value) : m_key(key), m_value(value) {};

    Pair::~Pair()
    {
    };

    const std::string& Pair::getKey() const
    {
        return m_key;
    };

    const std::string& Pair::getValue() const
    {
        return m_value;
    };

    bool Pair::operator==(const Pair& other) const
    {
        return (m_key == other.m_key);
    };

    bool Pair::operator!=(const Pair& other) const
    {
        return !(*this == other);
    };

    std::ostream& operator<<(std::ostream& os, const Pair& pair)
    {
        //os << std::setw(20) << std::right << m_Object[i].getKey() << ": "
        //    << std::setw(20) << std::left << m_Object[i].getValue() << std::endl;

        os << std::setw(20) << std::right << pair.m_key << ": "
            << std::left << pair.m_value;
        //os << pair.m_key << ": " << pair.m_value;
        return os;
    };

}