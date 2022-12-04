#pragma once
#include <type_traits>

namespace utils
{

template<class T>
std::underlying_type_t<T> enum_cast(T val) { return static_cast<std::underlying_type_t<T>>(val); }

}

#define DEF_ENUM_OPERATORS(EnumT) \
	inline EnumT operator|(EnumT l, EnumT r) { return static_cast<EnumT>(static_cast<std::underlying_type_t<EnumT>>(l) | static_cast<std::underlying_type_t<EnumT>>(r)); } \
	inline EnumT operator&(EnumT l, EnumT r) { return static_cast<EnumT>(static_cast<std::underlying_type_t<EnumT>>(l) & static_cast<std::underlying_type_t<EnumT>>(r)); }
