#pragma once

#include <string>
#include <vector>
#include <Poco/Types.h>
#include <common/strong_typedef.h>


namespace DB
{

/** Типы данных для представления значений из БД в оперативке.
  */

STRONG_TYPEDEF(char, Null);

using UInt8 = Poco::UInt8;
using UInt16 = Poco::UInt16;
using UInt32 = Poco::UInt32;
using UInt64 = Poco::UInt64;

using Int8 = Poco::Int8;
using Int16 = Poco::Int16;
using Int32 = Poco::Int32;
using Int64 = Poco::Int64;

using Float32 = float;
using Float64 = double;

using String = std::string;
using Strings = std::vector<String>;


template <typename T> struct IsNumber 	{ static const bool value = false; };

template <> struct IsNumber<UInt8> 		{ static const bool value = true; };
template <> struct IsNumber<UInt16> 	{ static const bool value = true; };
template <> struct IsNumber<UInt32> 	{ static const bool value = true; };
template <> struct IsNumber<UInt64> 	{ static const bool value = true; };
template <> struct IsNumber<Int8> 		{ static const bool value = true; };
template <> struct IsNumber<Int16> 		{ static const bool value = true; };
template <> struct IsNumber<Int32> 		{ static const bool value = true; };
template <> struct IsNumber<Int64> 		{ static const bool value = true; };
template <> struct IsNumber<Float32> 	{ static const bool value = true; };
template <> struct IsNumber<Float64> 	{ static const bool value = true; };


template <typename T> struct TypeName;

template <> struct TypeName<Null> 		{ static std::string get() { return "Null";		} };
template <> struct TypeName<UInt8> 		{ static std::string get() { return "UInt8";	} };
template <> struct TypeName<UInt16> 	{ static std::string get() { return "UInt16"; 	} };
template <> struct TypeName<UInt32> 	{ static std::string get() { return "UInt32"; 	} };
template <> struct TypeName<UInt64> 	{ static std::string get() { return "UInt64"; 	} };
template <> struct TypeName<Int8> 		{ static std::string get() { return "Int8"; 	} };
template <> struct TypeName<Int16> 		{ static std::string get() { return "Int16";	} };
template <> struct TypeName<Int32> 		{ static std::string get() { return "Int32";	} };
template <> struct TypeName<Int64> 		{ static std::string get() { return "Int64";	} };
template <> struct TypeName<Float32> 	{ static std::string get() { return "Float32"; 	} };
template <> struct TypeName<Float64> 	{ static std::string get() { return "Float64"; 	} };
template <> struct TypeName<String> 	{ static std::string get() { return "String"; 	} };

/// Этот тип не поддерживается СУБД, но используется в некоторых внутренних преобразованиях.
template <> struct TypeName<long double>{ static std::string get() { return "long double"; 	} };

}
