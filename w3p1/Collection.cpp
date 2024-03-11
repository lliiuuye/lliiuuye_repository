#include "Collection.h"
//#include "Pair.h"
#include <iostream>
#include <array>
#include <typeinfo>
#include <type_traits>

//using namespace seneca;
namespace seneca {
	template <typename T, int CAPACITY>
	Collection<T, CAPACITY>::Collection()
	{


		if constexpr (std::is_same_v<T, long>) {
			m_dummyObject = 0;
		}
		else if constexpr (std::is_same_v<T, double>) {
			m_dummyObject = 0.0;
		}
		else if constexpr (std::is_same_v<T, Pair>) {
			m_dummyObject = Pair("", "");
		}
	};


	template <typename T, int CAPACITY>
	int Collection<T, CAPACITY>::size() const
	{
		return m_size;
	};

	template <typename T, int CAPACITY>
	void Collection<T, CAPACITY>::display(std::ostream& os) const
	{
		std::cout << "----------------------" << std::endl;
		std::cout << "| Collection Content |" << std::endl;
		std::cout << "----------------------" << std::endl;
		for (int i = 0; i < m_size; ++i)
		{
			os << m_elements[i] << std::endl;
		}
		std::cout << "----------------------" << std::endl;
	};

	template <typename T, int CAPACITY>
	bool Collection<T, CAPACITY>::add(const T& item)
	{
		if (m_size < CAPACITY)
		{
			m_elements[m_size++] = item;
			return true;
		}

		return false;
	};


	template <typename T, int CAPACITY>
	T Collection<T, CAPACITY>::operator[](int index)
	{
		if (index < m_size)
		{
			return m_elements[index];
		}

		return m_dummyObject;
	};



	template <typename T, int CAPACITY>
	std::ostream& operator<<(std::ostream& os, const Collection<T, CAPACITY>& collection)
	{
		collection.display(os);
		return os;
	};
}