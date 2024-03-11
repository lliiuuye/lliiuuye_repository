#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <iostream>
#include <array>
#include "Pair.h"

namespace seneca {
    template <typename T, int CAPACITY>
    class Collection
    {
    private:
        std::array<T, CAPACITY> m_elements{};
        int m_size = 0;
        T m_dummyObject;

    public:
        Collection();
        int size() const;
        void display(std::ostream& os = std::cout) const;
        bool add(const T& item);
        T operator[](int index);


        friend std::ostream& operator<<(std::ostream& os, const Collection<T, CAPACITY>& collection);
    };
}
#endif //SENECA_COLLECTION_H