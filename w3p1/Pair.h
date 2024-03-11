#ifndef SENECA_PAIR_H
#define SENECA_PAIR_H

#include <iostream>
#include <string>
//#include "Collection.h"


namespace seneca {
    class Pair
    {
        std::string m_key{};
        std::string m_value{};

    public:
        Pair();
        Pair(const std::string& key, const std::string& value);
        ~Pair();
        const std::string& getKey() const;
        const std::string& getValue() const;

        bool operator==(const Pair& other) const;
        bool operator!=(const Pair& other) const;
        friend std::ostream& operator<<(std::ostream& os, const Pair& pair);
    };

}
#endif //SENECA_PAIR_H