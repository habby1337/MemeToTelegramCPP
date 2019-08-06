#ifndef _PLIB_
#define _PLIB_
#pragma once
#pragma warning(disable: 4996)
// Developed with Xcode 10.4, Apple LLVM 9.0.0 & Visual Studio 2019
#include <iostream>
#include <any>
#include <iomanip>
#include <unordered_set>
#include <cstring>
#include <string>
#include <string_view>
#include <deque>
#include <regex>
#include <iterator>
#include <utility>
#include <tuple>
#include <algorithm>
#include <type_traits>
#include <exception>
#include <typeinfo>
#include <limits>
#include <cstdlib>
#include <functional>
#include <future>
#include <memory>
#include <cmath>
#include <sstream>
#include <map>
#include <cstdio>
#include <numeric>
#include <ctime>
#include <chrono>
#include <random>
#include <mutex>
#include <stdexcept>
#include <fstream>
#include <array>
#include <variant>
#include <cassert>
#include <cstdarg>
#include <new>
#include <atomic>
#include <cctype>
#include <set>
#include <cstdint>
#include <bitset>

#ifdef _MSC_VER
_STD_BEGIN
#else
namespace std {
#endif
// C++ Ver Detect,Cross-Compiler
#ifdef _MSC_VER
#if _HAS_CXX17
#define DEF_CXX_17
#endif
#else
#if __cplusplus >= 201703L
#define DEF_CXX_17
#endif
#endif
#if 2 + 2 == 5
#error evacuate asap, maths has broken
#endif
// Utility types
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
// START class var (fucking annoying)
class var {
	// Might change this to "union"
	struct DATA {
		DATA() = default;
		// Temporary
		long long& in() { return a; }
		long double& db() { return b; }
		std::string& str() { return c; }
		bool& bl() { return d; }
		char& ch() { return e; }
		unsigned long long& uin() { return f; }
		void* vp() const { return p; }
		long long inc() const { return a; }
		long double dbc() const { return b; }
		std::string strc() const { return c; }
		bool blc() const { return d; }
		char chc() const { return e; }
		unsigned long long uinc() const { return f; }
		void* vpc() const { return p; }
	private:
		long long a = 0;
		long double b = 0.0;
		std::string c{};
		bool d = false;
		char e = 0x0;
		unsigned long long f = 0;
		void* p = nullptr;
	} Data;
	enum class TYPE {
		I = 0,
		D,
		S,
		B,
		C,
		U,
		O
	} Type_;
	TYPE& Get_ty() { return Type_; }
	TYPE Get_tyc() const { return Type_; }
public:
	// Just some annoying constructor shit (it works so nice)
	var() = default;
	var(var& Other_) noexcept {
		this->Get_ty() = Other_.Get_ty();
		this->Data = Other_.Data;
	}
	var(var&& Other_) noexcept {
		this->Get_ty() = Other_.Get_ty();
		this->Data = Other_.Data;
	}
	var(const var& Other_) noexcept {
		this->Get_ty() = Other_.Get_tyc();
		this->Data = Other_.Data;
	}
	var(const var&& Other_) noexcept {
		this->Get_ty() = Other_.Get_tyc();
		this->Data = Other_.Data;
	}
	var(long long const Av_) {
		Data.uin() = Av_;
		Data.in() = Av_;
		Data.db() = Av_;
		Get_ty() = TYPE::I;
	}
	var(unsigned const Av_) {
		Data.uin() = Av_;
		Data.in() = Av_;
		Data.db() = Av_;
		Get_ty() = TYPE::U;
	}
	var(unsigned long const Av_) {
		Data.uin() = Av_;
		Data.in() = Av_;
		Data.db() = Av_;
		Get_ty() = TYPE::U;
	}
	var(unsigned long long const Av_) {
		Data.uin() = Av_;
		Data.in() = Av_;
		Data.db() = Av_;
		Get_ty() = TYPE::U;
	}
	var(int const Av_) {
		Data.uin() = Av_;
		Data.in() = Av_;
		Data.db() = Av_;
		Get_ty() = TYPE::I;
	}
	var(long const Av_) {
		Data.uin() = Av_;
		Data.in() = Av_;
		Data.db() = Av_;
		Get_ty() = TYPE::I;
	}
	var(long double const Av_) {
		Data.uin() = Av_;
		Data.in() = Av_;
		Data.db() = Av_;
		Get_ty() = TYPE::D;
	}
	var(double const Av_) {
		Data.uin() = Av_;
		Data.in() = Av_;
		Data.db() = Av_;
		Get_ty() = TYPE::D;
	}
	var(std::string const& Av_) {
		Data.str() = Av_;
		Get_ty() = TYPE::S;
	}
	var(const char* Av_) {
		Data.str() = Av_;
		Get_ty() = TYPE::S;
	}
	var(char const Av_) {
		Data.ch() = Av_;
		Get_ty() = TYPE::C;
	}
	var(bool const Av_) {
		Data.bl() = Av_;
		Get_ty() = TYPE::B;
	}
	template <typename Ob>
	var(Ob& obj) {
		Data.vp() = &obj;
		Get_ty() = TYPE::O;
	}
	// REALLY Annoying operator shit.
	template <typename Ob>
	var& operator =(Ob& obj) {
		Data.vp() = &obj;
		Get_ty() = TYPE::O;
		return *this;
	}
	var& operator =(var& Other_) noexcept {
		this->Get_ty() = Other_.Get_ty();
		this->Data = Other_.Data;
		return *this;
	}
	var& operator =(var&& Other_) noexcept {
		this->Get_ty() = Other_.Get_ty();
		this->Data = Other_.Data;
		return *this;
	}
	var& operator =(const var& Other_) noexcept {
		this->Get_ty() = Other_.Get_tyc();
		this->Data = Other_.Data;
		return *this;
	}
	var& operator =(const var&& Other_) noexcept {
		this->Get_ty() = Other_.Get_tyc();
		this->Data = Other_.Data;
		return *this;
	}
	var& operator =(int const Av_) {
		Data.uin() = Av_;
		Data.in() = Av_;
		Data.db() = Av_;
		Get_ty() = TYPE::I;
		return *this;
	}
	var& operator =(long const Av_) {
		Data.uin() = Av_;
		Data.in() = Av_;
		Data.db() = Av_;
		Get_ty() = TYPE::I;
		return *this;
	}
	var& operator =(long double const Av_) {
		Data.uin() = Av_;
		Data.in() = Av_;
		Data.db() = Av_;
		Get_ty() = TYPE::D;
		return *this;
	}
	var& operator =(long long const Av_) {
		Data.uin() = Av_;
		Data.in() = Av_;
		Data.db() = Av_;
		Get_ty() = TYPE::I;
		return *this;
	}
	var& operator =(unsigned const Av_) {
		Data.uin() = Av_;
		Data.in() = Av_;
		Data.db() = Av_;
		Get_ty() = TYPE::U;
		return *this;
	}
	var& operator =(unsigned long const Av_) {
		Data.uin() = Av_;
		Data.in() = Av_;
		Data.db() = Av_;
		Get_ty() = TYPE::U;
		return *this;
	}
	var& operator =(unsigned long long const Av_) {
		Data.uin() = Av_;
		Data.in() = Av_;
		Data.db() = Av_;
		Get_ty() = TYPE::U;
		return *this;
	}
	var& operator =(double const Av_) {
		Data.uin() = Av_;
		Data.in() = Av_;
		Data.db() = Av_;
		Get_ty() = TYPE::D;
		return *this;
	}
	var& operator =(std::string const& Av_) {
		Data.str() = Av_;
		Get_ty() = TYPE::S;
		return *this;
	}
	var& operator =(const char* Av_) {
		Data.str() = Av_;
		Get_ty() = TYPE::S;
		return *this;
	}
	var& operator =(bool const Av_) {
		Data.bl() = Av_;
		Get_ty() = TYPE::B;
		return *this;
	}
	var& operator =(char const Av_) {
		Data.ch() = Av_;
		Get_ty() = TYPE::C;
		return *this;
	}
	// Must update istream's operator >> to a better type recognition
	friend std::istream& operator >>(std::istream& Is_, var& Te_) {
		std::string Temp_;
		Is_ >> Temp_;
		std::vector<char> Buf_ { Temp_.begin(), Temp_.end() };
		Te_.Data.str() = std::string{ std::vector<char>::iterator(Buf_.begin()), std::vector<char>::iterator(Buf_.end()) };
		bool al = false;
		if (Temp_.find("true") != std::string::npos) {
			Te_.Data.bl() = true;
			Te_.Data.ch() = '1';
		}
		if (Temp_.find("false") != std::string::npos) {
			Te_.Data.bl() = false;
			Te_.Data.ch() = '0';
		}
		if (Buf_.size() == 1 && Buf_.at(0) == '0') {
			Te_.Data.ch() = '0';
			Te_.Data.bl() = false;
		}
		if (Buf_.size() == 1 && Buf_.at(0) == '1') {
			Te_.Data.ch() = '1';
			Te_.Data.bl() = true;
		}
		if (Buf_.size() == 1)
			Te_.Data.ch() = Buf_.at(0);
		if (Buf_.size() == 1 && isalpha(Buf_.at(0))) {
			Te_.Data.ch() = Buf_.at(0);
			Te_.Get_ty() = TYPE::C;
			return Is_;
		}
		for (auto a : Buf_)
			if (isalpha(a)) {
				al = true;
				break;
			}
		if (Temp_.find('.') != std::string::npos && !al) {
			Te_.Data.db() = std::stold(std::string{ std::vector<char>::iterator(Buf_.begin()), std::vector<char>::iterator(Buf_.end()) });
			Te_.Data.in() = std::stoll(std::string{ std::vector<char>::iterator(Buf_.begin()), std::vector<char>::iterator(Buf_.end()) });
			Te_.Data.uin() = std::stoull(std::string{ std::vector<char>::iterator(Buf_.begin()), std::vector<char>::iterator(Buf_.end()) });
			Te_.Get_ty() = TYPE::D;
			return Is_;
		}
		if (Buf_.size() >= 17 && Buf_.size() <= 20) {
			Te_.Data.db() = std::stold(std::string{ std::vector<char>::iterator(Buf_.begin()), std::vector<char>::iterator(Buf_.end()) });
			Te_.Data.in() = std::stoll(std::string{ std::vector<char>::iterator(Buf_.begin()), std::vector<char>::iterator(Buf_.end()) });
			Te_.Data.uin() = std::stoull(std::string{ std::vector<char>::iterator(Buf_.begin()), std::vector<char>::iterator(Buf_.end()) });
			Te_.Get_ty() = TYPE::U;
			return Is_;
		}
		if (!al) {
			Te_.Data.db() = std::stold(std::string { std::vector<char>::iterator(Buf_.begin()), std::vector<char>::iterator(Buf_.end()) });
			Te_.Data.in() = std::stoll(std::string { std::vector<char>::iterator(Buf_.begin()), std::vector<char>::iterator(Buf_.end()) });
			Te_.Data.uin() = std::stoull(std::string { std::vector<char>::iterator(Buf_.begin()), std::vector<char>::iterator(Buf_.end()) });
			Te_.Get_ty() = TYPE::I;
			return Is_;
		}
		Te_.Get_ty() = TYPE::S;
		return Is_;
	}
	friend std::ostream& operator <<(std::ostream& Os_, const var& Te_) {
		if (Te_.Get_tyc() == TYPE::I)
			return Os_ << Te_.Data.inc();
		if (Te_.Get_tyc() == TYPE::D)
			return Os_ << Te_.Data.dbc();
		if (Te_.Get_tyc() == TYPE::S)
			return Os_ << Te_.Data.strc();
		if (Te_.Get_tyc() == TYPE::B)
			return Os_ << Te_.Data.blc();
		if (Te_.Get_tyc() == TYPE::C)
			return Os_ << Te_.Data.chc();
		if (Te_.Get_tyc() == TYPE::U)
			return Os_ << Te_.Data.uinc();
		return Os_;
	}
	var operator +(const var& Other_) const {
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::I)
			return Data.inc() + Other_.Data.inc();
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::D)
			return Data.inc() + Other_.Data.dbc();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::I)
			return Data.dbc() + Other_.Data.inc();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::D)
			return Data.dbc() + Other_.Data.dbc();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::I)
			return Data.uinc() + Other_.Data.inc();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::D)
			return Data.uinc() + Other_.Data.dbc();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::U)
			return Data.uinc() + Other_.Data.dbc();
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::U)
			return Data.inc() + Other_.Data.uinc();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::U)
			return Data.dbc() + Other_.Data.uinc();
		if (Get_tyc() == TYPE::S && Other_.Get_tyc() == TYPE::S)
			return Data.strc() + Other_.Data.strc();
		return *this;
	}
	var& operator +=(const var& Other_) {
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::I)
			Data.in() += Other_.Data.inc();
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::D)
			Data.in() += Other_.Data.dbc();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::I)
			Data.db() += Other_.Data.inc();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::D)
			Data.db() += Other_.Data.dbc();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::I)
			Data.uin() += Other_.Data.inc();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::D)
			Data.uin() += Other_.Data.dbc();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::U)
			Data.uin() += Other_.Data.dbc();
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::U)
			Data.in() += Other_.Data.uinc();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::U)
			Data.db() += Other_.Data.uinc();
		if (Get_tyc() == TYPE::S && Other_.Get_tyc() == TYPE::S)
			Data.str() += Other_.Data.strc();
		return *this;
	}
	var operator -(const var& Other_) const {
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::I)
			return Data.inc() - Other_.Data.inc();
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::D)
			return Data.inc() - Other_.Data.dbc();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::I)
			return Data.dbc() - Other_.Data.inc();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::D)
			return Data.dbc() - Other_.Data.dbc();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::I)
			return Data.uinc() - Other_.Data.inc();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::D)
			return Data.uinc() - Other_.Data.dbc();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::U)
			return Data.uinc() - Other_.Data.dbc();
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::U)
			return Data.inc() - Other_.Data.uinc();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::U)
			return Data.dbc() - Other_.Data.uinc();
		return *this;
	}
	var operator *(var& Other_) {
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::I)
			return Data.in() * Other_.Data.in();
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::D)
			return static_cast<long double>(Data.in() * Other_.Data.db());
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::I)
			return static_cast<long double>(Data.db() * Other_.Data.in());
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::D)
			return Data.db() * Other_.Data.db();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::I)
			return Data.uin() * Other_.Data.in();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::D)
			return Data.uin() * Other_.Data.db();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::U)
			return Data.uin() * Other_.Data.db();
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::U)
			return Data.in() * Other_.Data.uin();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::U)
			return Data.db() * Other_.Data.uin();
		return *this;
	}
	var operator %(const var& Other_) const {
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::I)
			return Data.inc() % Other_.Data.inc();
		return *this;
	}
	var operator /(const var& Other_) const {
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::I)
			return Data.inc() / Other_.Data.inc();
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::D)
			return static_cast<long double>(Data.inc() / Other_.Data.dbc());
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::I)
			return static_cast<long double>((Data.dbc() / static_cast<long double>(Other_.Data.inc())));
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::D)
			return Data.dbc() / Other_.Data.dbc();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::I)
			return Data.uinc() / Other_.Data.inc();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::D)
			return Data.uinc() / Other_.Data.dbc();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::U)
			return Data.uinc() / Other_.Data.dbc();
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::U)
			return Data.inc() / Other_.Data.uinc();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::U)
			return Data.dbc() / Other_.Data.uinc();
		return *this;
	}
	var& operator -=(const var& Other_) {
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::I)
			Data.in() -= Other_.Data.inc();
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::D)
			Data.in() -= Other_.Data.dbc();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::I)
			Data.db() -= Other_.Data.inc();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::D)
			Data.db() -= Other_.Data.dbc();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::I)
			Data.uin() -= Other_.Data.inc();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::D)
			Data.uin() -= Other_.Data.dbc();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::U)
			Data.uin() -= Other_.Data.dbc();
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::U)
			Data.in() -= Other_.Data.uinc();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::U)
			Data.db() -= Other_.Data.uinc();
		return *this;
	}
	var& operator *=(var& Other_) {
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::I)
			Data.in() *= Other_.Data.in();
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::D)
			Data.in() *= Other_.Data.db();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::I)
			Data.db() *= static_cast<double>(Other_.Data.in());
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::D)
			Data.db() *= Other_.Data.db();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::I)
			Data.uin() *= Other_.Data.in();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::D)
			Data.uin() *= Other_.Data.db();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::U)
			Data.uin() *= Other_.Data.db();
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::U)
			Data.in() *= Other_.Data.uin();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::U)
			Data.db() *= Other_.Data.uin();
		return *this;
	}
	var& operator /=(var& Other_) {
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::I)
			Data.in() /= Other_.Data.in();
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::D)
			Data.in() /= Other_.Data.db();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::I)
			Data.db() /= static_cast<double>(Other_.Data.in());
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::D)
			Data.db() /= Other_.Data.db();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::I)
			Data.uin() /= Other_.Data.in();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::D)
			Data.uin() /= Other_.Data.db();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::U)
			Data.uin() /= Other_.Data.db();
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::U)
			Data.in() /= Other_.Data.uin();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::U)
			Data.db() /= Other_.Data.uin();
		return *this;
	}
	bool operator ==(var& Other_) {
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::I)
			return Data.in() == Other_.Data.in();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::D)
			return Data.db() == Other_.Data.db();
		if (Get_tyc() == TYPE::S && Other_.Get_tyc() == TYPE::S)
			return Data.str() == Other_.Data.str();
		if (Get_tyc() == TYPE::C && Other_.Get_tyc() == TYPE::C)
			return Data.ch() == Other_.Data.ch();
		if (Get_tyc() == TYPE::B && Other_.Get_tyc() == TYPE::B)
			return Data.bl() == Other_.Data.bl();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::U)
			return Data.uin() == Other_.Data.uin();
		return {};
	}
	bool operator !=(var& Other_) {
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::I)
			return Data.in() != Other_.Data.in();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::D)
			return Data.db() != Other_.Data.db();
		if (Get_tyc() == TYPE::S && Other_.Get_tyc() == TYPE::S)
			return Data.str() != Other_.Data.str();
		if (Get_tyc() == TYPE::C && Other_.Get_tyc() == TYPE::C)
			return Data.ch() != Other_.Data.ch();
		if (Get_tyc() == TYPE::B && Other_.Get_tyc() == TYPE::B)
			return Data.bl() != Other_.Data.bl();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::U)
			return Data.uin() != Other_.Data.uin();
		return {};
	}
	var& operator ++() {
		if (Get_tyc() == TYPE::I)
			++Data.in();
		if (Get_tyc() == TYPE::D)
			++Data.db();
		if (Get_tyc() == TYPE::U)
			++Data.uin();
		return *this;
	}
	var operator ++(int) {
		if (Get_tyc() == TYPE::I)
			return Data.in()++;
		if (Get_tyc() == TYPE::D)
			return Data.db()++;
		if (Get_tyc() == TYPE::U)
			return Data.uin()++;
		return *this;
	}
	var& operator --() {
		if (Get_tyc() == TYPE::I)
			--Data.in();
		if (Get_tyc() == TYPE::D)
			--Data.db();
		if (Get_tyc() == TYPE::U)
			--Data.uin();
		return *this;
	}
	var operator --(int) {
		if (Get_tyc() == TYPE::I)
			return Data.in()--;
		if (Get_tyc() == TYPE::D)
			return Data.db()--;
		if (Get_tyc() == TYPE::U)
			return Data.uin()--;
		return *this;
	}
	bool operator >(var& Other_) {
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::I)
			return Data.in() > Other_.Data.in();
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::D)
			return Data.in() > Other_.Data.db();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::I)
			return Data.db() > Other_.Data.in();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::D)
			return Data.db() > Other_.Data.db();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::I)
			return Data.uin() > Other_.Data.in();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::D)
			return Data.uin() > Other_.Data.db();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::U)
			return Data.uin() > Other_.Data.db();
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::U)
			return Data.in() > Other_.Data.uin();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::U)
			return Data.db() > Other_.Data.uin();
		if (Get_tyc() == TYPE::S && Other_.Get_tyc() == TYPE::S)
			return Data.str() > Other_.Data.str();
		if (Get_tyc() == TYPE::C && Other_.Get_tyc() == TYPE::C)
			return Data.ch() > Other_.Data.ch();
		if (Get_tyc() == TYPE::B && Other_.Get_tyc() == TYPE::B)
			return Data.bl() > Other_.Data.bl();
		return {};
	}
	std::bitset<32> operator ^(const var& Other_) const {
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::I)
			return Data.inc() ^ Other_.Data.inc();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::I)
			return Data.uinc() ^ Other_.Data.inc();
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::U)
			return Data.inc() ^ Other_.Data.uinc();
		return {};
	}
	bool operator <(const var& Other_) const {
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::I)
			return Data.inc() < Other_.Data.inc();
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::D)
			return Data.inc() < Other_.Data.dbc();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::I)
			return Data.dbc() < Other_.Data.inc();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::D)
			return Data.dbc() < Other_.Data.dbc();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::I)
			return Data.uinc() < Other_.Data.inc();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::D)
			return Data.uinc() < Other_.Data.dbc();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::U)
			return Data.uinc() < Other_.Data.dbc();
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::U)
			return Data.inc() < Other_.Data.uinc();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::U)
			return Data.dbc() < Other_.Data.uinc();
		if (Get_tyc() == TYPE::S && Other_.Get_tyc() == TYPE::S)
			return Data.strc() < Other_.Data.strc();
		if (Get_tyc() == TYPE::C && Other_.Get_tyc() == TYPE::C)
			return Data.chc() < Other_.Data.chc();
		if (Get_tyc() == TYPE::B && Other_.Get_tyc() == TYPE::B)
			return Data.blc() < Other_.Data.blc();
		return {};
	}
	bool operator >=(const var& Other_) const {
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::I)
			return Data.inc() >= Other_.Data.inc();
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::D)
			return Data.inc() >= Other_.Data.dbc();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::I)
			return Data.dbc() >= Other_.Data.inc();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::D)
			return Data.dbc() >= Other_.Data.dbc();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::I)
			return Data.uinc() >= Other_.Data.inc();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::D)
			return Data.uinc() >= Other_.Data.dbc();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::U)
			return Data.uinc() >= Other_.Data.dbc();
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::U)
			return Data.inc() >= Other_.Data.uinc();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::U)
			return Data.dbc() >= Other_.Data.uinc();
		if (Get_tyc() == TYPE::S && Other_.Get_tyc() == TYPE::S)
			return Data.strc() >= Other_.Data.strc();
		if (Get_tyc() == TYPE::C && Other_.Get_tyc() == TYPE::C)
			return Data.chc() >= Other_.Data.chc();
		if (Get_tyc() == TYPE::B && Other_.Get_tyc() == TYPE::B)
			return Data.blc() >= Other_.Data.blc();
		return {};
	}
	bool operator <=(const var& Other_) const {
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::I)
			return Data.inc() <= Other_.Data.inc();
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::D)
			return Data.inc() <= Other_.Data.dbc();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::I)
			return Data.dbc() <= Other_.Data.inc();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::D)
			return Data.dbc() <= Other_.Data.dbc();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::I)
			return Data.uinc() <= Other_.Data.inc();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::D)
			return Data.uinc() <= Other_.Data.dbc();
		if (Get_tyc() == TYPE::U && Other_.Get_tyc() == TYPE::U)
			return Data.uinc() <= Other_.Data.dbc();
		if (Get_tyc() == TYPE::I && Other_.Get_tyc() == TYPE::U)
			return Data.inc() <= Other_.Data.uinc();
		if (Get_tyc() == TYPE::D && Other_.Get_tyc() == TYPE::U)
			return Data.dbc() <= Other_.Data.uinc();
		if (Get_tyc() == TYPE::S && Other_.Get_tyc() == TYPE::S)
			return Data.strc() <= Other_.Data.strc();
		if (Get_tyc() == TYPE::C && Other_.Get_tyc() == TYPE::C)
			return Data.chc() <= Other_.Data.chc();
		if (Get_tyc() == TYPE::B && Other_.Get_tyc() == TYPE::B)
			return Data.blc() <= Other_.Data.blc();
		return {};
	}
	bool operator !() const {
		if (Get_tyc() == TYPE::B)
			return !Data.blc();
		return {};
	}
	bool operator &&(const var& Other_) const {
		if (Get_tyc() == TYPE::B && Other_.Get_tyc() == TYPE::B)
			return Data.blc() && Other_.Data.blc();
		return {};
	}
	bool operator ||(var& Other_) {
		if (Get_tyc() == TYPE::B && Other_.Get_tyc() == TYPE::B)
			return Data.bl() || Other_.Data.bl();
		return {};
	}
	template <typename Ty>
	Ty& get() { return *reinterpret_cast<Ty*>(Data.vp()); }
	// End of annoying operators (fml)
	// Cast operators & implicit/explicit conversions (just an utility)
	explicit operator int&() { return reinterpret_cast<int&>(Data.in()); }
	explicit operator double&() { return reinterpret_cast<double&>(Data.db()); }
	explicit operator long long&() { return reinterpret_cast<long long&>(Data.in()); }
	explicit operator long&() { return reinterpret_cast<long&>(Data.in()); }
	explicit operator unsigned long long&() { return reinterpret_cast<unsigned long long&>(Data.uin()); }
	explicit operator unsigned long&() { return reinterpret_cast<unsigned long&>(Data.uin()); }
	explicit operator unsigned&() { return reinterpret_cast<unsigned&>(Data.uin()); }
	explicit operator std::string&() { return reinterpret_cast<std::string&>(Data.str()); }
	explicit operator const char*() { return reinterpret_cast<const char*>(Data.str().c_str()); }
	explicit operator bool&() { return reinterpret_cast<bool&>(Data.bl()); }
	explicit operator char&() { return reinterpret_cast<char&>(Data.ch()); }
	template <typename Ty>
	explicit operator Ty&() { return this->get<Ty>(); }
}; // TODO: MOAR OPERATORS and.. (better type recognition && actual useful methods for users and not for me(smh))
// END class var, prototype, ver: almost-final
// START class better_vector
template <typename _Ty, class _Al = std::allocator<_Ty>, class _Traits = std::allocator_traits<_Al>>
class better_vector {
public:
	using value_type = _Ty;
	using iterator = _Ty*;
	using const_iterator = const _Ty*;
	using ptr_type = _Ty*; // Using a smart pointer is impossible.
private:
	_Al _Alloc;
	size_t _Capacity = 0, _Size = 0;
	ptr_type _Strg = nullptr;
	template <typename ...Args>
	void _Construct_arg(ptr_type _Ptr_beg, ptr_type _Ptr_end, Args&& ..._Args) {
		std::for_each(_Ptr_beg, _Ptr_end, [&](const value_type& _Val) {
			_Traits::construct(_Alloc, &_Val, std::forward<Args>(_Args)...);
		});
	}
	constexpr void _Construct_def(ptr_type _Ptr_beg, ptr_type _Ptr_end) {
		if constexpr (std::is_default_constructible<_Ty>())
			std::for_each(_Ptr_beg, _Ptr_end, [&](const value_type& _Val) {
				_Traits::construct(_Alloc, &_Val);
			});
	}
	constexpr void _Construct_def(_Ty& _Val) {
		if constexpr (std::is_default_constructible<_Ty>()) {
			_Traits::construct(_Alloc, &_Val);
		}
	}
	void _Realloc() {
		ptr_type _Temp = _Alloc.allocate(_Size);
		_Construct_def(_Temp, _Temp + _Size);
		// std::memcpy(_Temp, _Strg, _Size * sizeof _Strg[0]);
		std::copy(_Strg, _Strg + _Size, _Temp);
		_Alloc.deallocate(_Strg, _Capacity);
		_Capacity += _Size - int(_Size / 2.8225);
		_Strg = _Alloc.allocate(_Capacity);
		// std::memcpy(_Strg, _Temp, _Size * sizeof _Strg[0]);
		std::copy(_Temp, _Temp + _Size, _Strg);
		_Alloc.deallocate(_Temp, _Size);
	}
	void _Realloc_exactly(const size_t _Sz) {
		assert(_Sz > 0);
		ptr_type _Temp = _Alloc.allocate(_Sz);
		_Construct_def(_Temp, _Temp + _Size);
		// std::memcpy(_Temp, _Strg, _Size * sizeof _Strg[0]);
		std::copy(_Strg, _Strg + _Size, _Temp);
		_Alloc.deallocate(_Strg, _Capacity);
		_Strg = _Alloc.allocate(_Capacity = _Sz);
		// std::memcpy(_Strg, _Temp, _Size * sizeof _Strg[0]);
		std::copy(_Temp, _Temp + _Size, _Strg);
		_Alloc.deallocate(_Temp, _Sz);
	}
public:
	~better_vector() {
		_Alloc.deallocate(_Strg, _Capacity);
	}
	better_vector() = default;
	better_vector(const better_vector& _Other) noexcept {
		this->_Size = _Other.size();
		this->_Capacity = _Other.capacity();
		this->_Strg = _Alloc.allocate(_Capacity);
		_Construct_def(_Strg, _Strg + _Size);
		std::copy(_Other._Strg, _Other._Strg + _Other._Size, _Strg[0]);
	}
	better_vector& operator =(const better_vector& _Other) noexcept {
		this->_Size = _Other.size();
		this->_Capacity = _Other.capacity();
		this->_Strg = _Alloc.allocate(_Capacity);
		_Construct_def(_Strg, _Strg + _Size);
		std::copy(_Other._Strg, _Other._Strg + _Other._Size, _Strg[0]);
		return *this;
	}
	better_vector(better_vector&& _Other) noexcept {
		this->_Size = _Other._Size;
		this->_Capacity = _Other._Capacity;
		this->_Strg = _Alloc.allocate(_Capacity);
		_Construct_def(_Strg, _Strg + _Size);
		std::move(_Other._Strg, _Other._Strg + _Other._Size, _Strg);
	}
	better_vector& operator =(better_vector&& _Other) noexcept {
		this->_Size = _Other._Size;
		this->_Capacity = _Other._Capacity;
		this->_Strg = _Alloc.allocate(_Capacity);
		_Construct_def(_Strg, _Strg + _Size);
		std::move(_Other._Strg, _Other._Strg + _Other._Size, _Strg);
		return *this;
	}
	better_vector(const size_t _Sz) {
		_Strg = _Alloc.allocate(_Sz);
		_Construct_def(_Strg, _Strg + _Size);
		_Size = _Capacity = _Sz;
	}
	better_vector(const std::initializer_list<_Ty>& _Ls) {
		_Size = _Capacity = _Ls.size();
		_Strg = _Alloc.allocate(_Size);
		_Construct_def(_Strg, _Strg + _Size);
		for (auto _Idx = 0u; _Idx < _Size; ++_Idx)
			_Traits::construct(_Alloc, _Strg + _Idx, _Ls.begin()[_Idx]);
	}
	size_t capacity() const { return _Capacity; }
	size_t size() const { return _Size; }
	template <typename ..._Arg>
	void emplace_back(_Arg&& ..._Args) {
		if (_Strg == nullptr) {
			_Strg = _Alloc.allocate(++_Capacity);
			_Traits::construct(_Alloc, &_Strg[_Size++], std::forward<_Arg>(_Args)...);
			return;
		}
		if (_Size < _Capacity)
			_Traits::construct(_Alloc, &_Strg[_Size++], std::forward<_Arg>(_Args)...);
		else {
			_Realloc();
			_Traits::construct(_Alloc, &_Strg[_Size++], std::forward<_Arg>(_Args)...);
		}
	}
	auto& emplace_back() {
		if (_Strg == nullptr) {
			_Strg = _Alloc.allocate(++_Capacity);
			_Construct_def(_Strg[_Size++]);
			return _Strg[0];
		}
		if (_Size < _Capacity) {
			_Construct_def(_Strg[_Size++]);
			return _Strg[_Size - 1];
		}
		_Realloc();
		_Construct_def(_Strg[_Size++]);
		return _Strg[_Size - 1];
	}
	void push_back(_Ty&& _Obj) {
		this->emplace_back(std::move(_Obj));
	}
	void push_back(const _Ty& obj) {
		this->emplace_back(std::move(obj));
	}
	void reserve(const size_t _New_cap) {
		if (_New_cap == _Capacity)
			return;
		_Capacity = _New_cap > _Capacity ? _Realloc_exactly(_New_cap), _New_cap : _New_cap;
	}
	void resize(const size_t _New_size) {
		if (_New_size == _Size)
			return;
		if (_New_size < _Capacity) {
			if (_New_size < _Size)
				std::for_each(_Strg + _New_size, _Strg + _Size, [&](const _Ty& ty) {
					_Traits::destroy(_Alloc, &ty);
				});
			else
				_Construct_def(_Strg + _Size, _Strg + _New_size);
		} else {
			_Realloc_exactly(_New_size);
			_Construct_def(_Strg + _Size, _Strg + _New_size);
		}
		_Size = _New_size;
	}
	void resize(const size_t _New_size, const _Ty& _Val) {
		if (_New_size == _Size)
			return;
		if (_New_size < _Capacity) {
			if (_New_size < _Size)
				std::for_each(_Strg + _New_size, _Strg + _Size, [&](const _Ty& ty) {
					_Traits::destroy(_Alloc, &ty);
				});
			else
				_Construct_arg(_Strg + _Size, _Strg + _New_size, _Val);
		} else {
			_Realloc_exactly(_New_size);
			_Construct_arg(_Strg + _Size, _Strg + _New_size, _Val);
		}
		_Size = _New_size;
	}
	_Ty& operator [](const size_t _Idx) {
		assert(_Idx <= _Size);
		return _Strg[_Idx];
	}
	_Ty& at(const size_t _Idx) {
		return (*this)[_Idx];
	}
	void pop_back() {
		assert(_Size > 0);
		_Traits::destroy(_Alloc, _Strg + --_Size);
	}
	bool empty() const {
		return _Size == 0;
	}
	void shrink_to_fit() {
		if (_Capacity > _Size) {
			if (!_Size)
				this->~better_vector();
			_Realloc_exactly(_Size);
		}
	}
	void removeat(const size_t _Idx) {
		assert(_Size > 0);
		for (auto i = _Idx; i < _Size - 1; ++i)
			_Strg[i] = _Strg[i + 1];
		pop_back();
	}
	void insert(const size_t _Where, const _Ty& _Val) {
		if (_Size < _Capacity) {
			for (auto i = _Size; i > _Where; --i)
				_Strg[i] = _Strg[i - 1];
			_Strg[_Where] = _Val;
			++_Size;
		} else {
			_Realloc_exactly(_Size + 2);
			insert(_Where, _Val);
		}
	}
	explicit operator bool() const {
		return _Strg == nullptr;
	}
	void fill(const _Ty& _Elem) {
		std::fill(begin(), end(), _Elem);
	}
	friend std::ostream& operator <<(std::ostream& _Os, const better_vector<_Ty>& _Vc) {
		if (_Vc.empty())
			return _Os << "[]";
		_Os << "[";
		std::copy(_Vc.cbegin(), _Vc.cend() - 1, std::ostream_iterator<_Ty>(_Os, ", "));
		_Os << _Vc.cend()[-1] << "]";
		return _Os;
	}
	iterator begin() { return _Strg; }
	const_iterator cbegin() const { return _Strg; }
	iterator end() { return _Strg + _Size; }
	const_iterator cend() const { return _Strg + _Size; }
};
// END class better_vector, ver: final
// TODO: More utility methods.
// START class better_list
template <typename Ty, typename Alloc = std::allocator<Ty>, typename Traits = std::allocator_traits<Alloc>>
class better_list {
	Alloc al;
	struct Node {
		Node* next = nullptr;
		Ty data;
	} head;
	using node_allocator_type = std::allocator<Node>;
	node_allocator_type aln;
	size_t s = 0;
	void free(Node*& n) {
		if (n == nullptr)
			return;
		free(n->next);
		aln.deallocate(n);
	}
	Node* get_last() {
		Node* curr = head.next;
		while (curr->next != nullptr)
			curr = curr->next;
		return curr;
	}
public:
	using value_type = Ty;
	using reference = Ty&;
	using const_reference = const Ty&;
	using size_type = size_t;
	using iterator = Ty*;
	using const_iterator = const Ty*;
	~better_list() {
		/*auto curr = head.next;
		for (int i = 0; i < s; ++i) {
		Node *next = curr->next;
		aln.deallocate(curr, 1);
		curr = next;
		}*/
		free(head.next);
	}
	template <typename ...Ts>
	void emplace_back(Ts&& ...Args) {
		if (!head.next) {
			Node* n = aln.allocate(1);
			n->next = nullptr;
			head.next = n;
			Traits::construct(al, &head.data, std::forward<Ts>(Args)...);
			s++;
		} else {
			Node* n = aln.allocate(1);
			n->next = nullptr;
			auto temp = get_last();
			temp->next = n;
			Traits::construct(al, &temp->data, std::forward<Ts>(Args)...);
			s++;
		}
	}
	void push_back(const value_type& obj) {
		emplace_back(obj);
	}
	void push_back(value_type&& obj) {
		emplace_back(std::move(obj));
	}
	value_type& operator [](const size_type idx) {
		if (!idx)
			return head.data;
		auto curr = head.next;
		for (int i = 1; i < idx; ++i)
			curr = curr->next;
		return curr->data;
	}
	value_type& at(const size_type idx) {
		return (*this)[idx];
	}
	size_type size() const {
		return s;
	}
}; // END class better_list, ver 0.1 | prototype
// START standard mersenne generator
#if defined(_WINDOWS_)
#undef min
#undef max
template <typename Uy = std::random_device, typename Ty>
Ty random(const Ty& Min, const Ty& Max) {
	static_assert(is_arithmetic<Ty>() && !_Is_any_of_v<Ty, char, const char, char16_t, char32_t, wchar_t, unsigned char>, "Error, type must be a number");
	static Uy seed{};
	std::mt19937_64 rng{ seed() };
	if constexpr (is_integral<Ty>()) {
		std::uniform_int_distribution<Ty> dist(Min, Max);
		return dist(rng);
	} else if constexpr (is_floating_point<Ty>()) {
		std::uniform_real_distribution<Ty> dist(Min, Max);
		return dist(rng);
	}
	return Ty();
}
#elif !defined(_WINDOWS_) && !defined(__MINGW64__) && !defined(__MINGW32__)
template <typename Uy = std::random_device, typename Ty>
Ty random(const Ty& Min, const Ty& Max) {
	static_assert(is_arithmetic<Ty>() && !_Is_any_of_v<Ty, char, const char, char16_t, char32_t, wchar_t, unsigned char>, "Error, type must be a number");
	static Uy seed{};
	std::mt19937_64 rng{ seed() };
	if constexpr (is_integral<Ty>()) {
		std::uniform_int_distribution<Ty> dist(Min, Max);
		return dist(rng);
	} 
	if constexpr (is_floating_point<Ty>()) {
		std::uniform_real_distribution<Ty> dist(Min, Max);
		return dist(rng);
	}
	return Ty();
}
#endif // _WINDOWS_
#if defined(__MINGW32__) || defined(__MINGW64__)
template <class Ty = int>
Ty random(const Ty Min = std::numeric_limits<Ty>::min(), const Ty Max = std::numeric_limits<Ty>::max()) {
	srand(time(nullptr));
	return rand() % Max + Min;
}
#endif // __MINGW32__, __MINGW64__
// END standard mersenne generator, ver FINAL

// START template function compact python-like range
template <class Ty>
std::vector<Ty> range(Ty Start, Ty End, Ty Step) {
	if (Step == Ty(0))
		throw std::invalid_argument("step for range must be non-zero");
	std::vector<Ty> r;
	if (Step < 0)
		for (Ty i = End + Step; i >= Start + Step; i += Step)
			r.push_back(i);
	else
		for (Ty i = Start; i < End; i += Step)
			r.push_back(i);
	return r;
}
template <class Ty>
std::vector<Ty> range(Ty Start, Ty End) {
	return range(Start, End, Ty(1));
}
template <class Ty>
std::vector<Ty> range(Ty End) {
	return range(Ty(0), End, Ty(1));
} // END template function compact python-like range, ver FINAL.
// Gay shit for vector (cuz they couldn't do this themselves)
template <typename Ty>
std::ostream& operator <<(std::ostream& os, const std::vector<Ty>& v) {
	if (v.empty())
		return os << "[]";
	os << "[";
	std::copy(v.begin(), v.end() - 1, std::ostream_iterator<Ty>{ os, ", " });
	os << v.end()[-1] << "]";
	return os;
}
// Might change parsing so that it resembles python more.
#ifdef _MSC_VER
#define forceinline __forceinline
#elif defined(__GNUC__)
#define forceinline inline __attribute__((__always_inline__))
#elif defined(__clang__)
#if __has_attribute(__always_inline__)
#define forceinline inline __attribute__((__always_inline__))
#else
#define forceinline inline
#endif // __CLANG__
#else
#define forceinline inline
#endif // _MSC_VER
// START class validate user input
inline class check_istream {
	std::istream& is{ std::cin };
	const char* msg = "Error, cannot bind rvalue to variable, check the type.\n";
public:
	void cmsg(const char* _Msg) {
		this->msg = _Msg;
	}
	template <class Ty>
	void operator >>(Ty& _Val) {
		while (!(is >> _Val)) {
			std::cerr << msg;
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
} ccin;
// END class validate user input, ver 0.1, might change this.
// STAR class custom operators for output

namespace {
	struct ccout_t {
		template <typename Ty>
		ccout_t& operator ,(const Ty& elem) {
			std::cout << elem;
			return *this;
		}
	};
}

inline struct helper {
	template <typename Ty>
	ccout_t operator <<(const Ty& elem) const {
		return ccout_t(), elem;
	}
} ccout;
// START template function to find closest index in a container.
enum class basicix {
	idx = 0,
	val
};
struct basic_vi {
	static constexpr basicix Idx = basicix(0);
	static constexpr basicix Val = basicix(1);
};
template <typename _Iter, typename _Ty>
constexpr forceinline _Ty closest(_Iter First, _Iter Last, _Ty Val, const basicix td = basic_vi::Idx) {
	if (td == basicix::idx)
		return std::distance(First, std::min_element(First, Last, [&](_Ty x, _Ty y) {
			return std::abs(x - Val) < std::abs(y - Val);
		}));
	if (td == basicix::val)
		return *std::min_element(First, Last, [&](_Ty x, _Ty y) {
			return std::abs(x - Val) < std::abs(y - Val);
		});
	throw std::invalid_argument("Error, 4th parameter must be an idx or val");
} // END template function to find closest index in a container
// START Access Nth element in parameter pack
template <size_t index, typename Ty, typename ...Ts, typename std::enable_if<index == 0>::type* = nullptr>
forceinline constexpr decltype(auto) acs(Ty&& t, Ts&& ...ts) { return std::forward<Ty>(t); }
template <size_t index, typename Ty, typename ...Ts, typename std::enable_if<(index > 0 && index <= sizeof...(Ts))>::type* = nullptr>
forceinline constexpr decltype(auto) acs(Ty&& t, Ts&& ...ts) { return acs<index - 1>(std::forward<Ts>(ts)...); }
template <long long index, typename... Ts>
forceinline constexpr bool index_ok() { return index >= 0 && index < static_cast<long long>(sizeof...(Ts)); }
template <long long index, typename Ty, typename ...Ts, typename std::enable_if<(!index_ok<index, Ty, Ts...>())>::type* = nullptr>
forceinline constexpr decltype(auto) acs(Ty&& t, Ts&& ...ts) {
	static_assert(index_ok<index, Ty, ts...>(), "Invalid index");
	return std::forward<Ty>(t);
}
template <int Idx, class ...Ts>
constexpr decltype(auto) acs2(Ts&& ...ts) {
	static_assert(Idx < sizeof...(ts) && Idx >= 0, "Invalid index");
	return std::get<Idx>(std::forward_as_tuple(ts...));
} // END Access Nth element in parameter pack
// START word up/low case scrambling
inline void uplowgen(std::string& str) {
	for (auto& a : str)
		random(0, 1) ? a = toupper(a) : a = tolower(a);
} // END Meme word scrambling, ver: final
// START Various utility functions
template <typename ...Ts>
void print(Ts&& ...args) {
	((std::cout << std::forward<Ts>(args) << ' '), ...);
}

inline auto split(const std::string& s, const std::string& delimiter) {
	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	std::vector<std::string> res;
	while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
		auto token = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.emplace_back(token);
	}
	res.emplace_back(s.substr(pos_start));
	return res;
}

inline void replace(std::string& _Str, const char* const _Oldval, const char* const _Newval) {
	const auto old_len = strlen(_Oldval);
	const auto new_len = strlen(_Newval);
	size_t pos_start = 0, pos_end;
	while ((pos_end = _Str.find(_Oldval, pos_start)) != std::string::npos) {
		_Str.replace(_Str.begin() + pos_end, _Str.begin() + pos_end + old_len, _Newval);
		if (new_len)
			pos_start = pos_end - new_len + old_len;
		else
			pos_start = pos_end - new_len + old_len - 1;
	}
}

template <typename Obj>
constexpr auto make_object() {
	static_assert(std::is_default_constructible_v<Obj>, "Object is not default constructible");
	return Obj{};
}

template <typename Obj, typename ...Args>
constexpr auto make_object(Args&& ...args) {
	return Obj(std::forward<Args>(args)...);
}

template <typename Obj, typename Ty>
constexpr auto make_object(const std::initializer_list<Ty>& List) {
	return Obj{ List };
}

inline void add_space(std::string& str) {
	for (auto i = 0u; i < str.size(); i++) {
		if (str[i + 1] == ' ') {
			i++;
			continue;
		}
		str.insert(str.begin() + ++i, ' ');
	}
}

inline auto add_space(std::string&& str) {
	auto temp(std::move(str));
	for (auto i = 0u; i < temp.size(); i++) {
		if (temp[i + 1] == ' ') {
			i++;
			continue;
		}
		temp.insert(temp.begin() + ++i, ' ');
	}
	return temp;
}
// END Various utility functions, up: constantly added
// START template metaprogramming (just random tests for learning purposes, ignore.)
template <long long N> struct Factorial { static const long long result = N * Factorial<N - 1>::result; };
template <> struct Factorial<0> { static const long long result = 1; };
template <long long N> struct Fib { static const long long result = Fib<N - 1>::result + Fib<N - 2>::result; };
template <> struct Fib<0> { static const long long result = 0; };
template <> struct Fib<1> { static const long long result = 1; };
template <long long X, long long Y> struct MCD { static const long long result = MCD<Y, X % Y>::result; };
template <long long X> struct MCD<X, 0> { static const long result = X; };
template <long long N, long long D>
struct Frac {
	static constexpr long Num = N;
	static constexpr long Den = D;
};
template <long long N, class X> struct Scalar { typedef Frac<N * X::Num, N * X::Den> result; };
template <class F> struct Simpl {
	static constexpr long long mcd = MCD<F::Num, F::Den>::result;
	typedef Frac<F::Num / mcd, F::Den / mcd> result;
};
template <class X, class Y> struct SameBase {
	typedef typename Scalar<Y::Den, X>::result X1;
	typedef typename Scalar<X::Den, Y>::result Y1;
};
template <typename X, typename Y> struct Sum {
	typedef SameBase<X, Y> B;
	static constexpr long long Num = B::X1::Num + B::Y1::Num;
	static constexpr long long Den = B::Y1::Den;
	typedef typename Simpl<Frac<Num, Den>>::result result;
};
template <long long N> struct E {
	static constexpr long long Den = Factorial<N>::result;
	typedef Frac<1, Den> term;
	typedef typename E<N - 1>::result next_term;
	typedef typename Sum<term, next_term>::result result;
};
template <size_t Idx, typename Ty, typename ...Ts>
struct GetNTy {
	using type = typename GetNTy<Idx - 1, Ts...>::type;
};
template <typename Ty, typename ...Ts>
struct GetNTy<0, Ty, Ts...> {
	using type = Ty;
};
template <> struct E<0> { typedef Frac<1, 1> result; };
template <int N> struct Integer { constexpr static int val = N; };
// Trait to detecting STL and STL-Like containers
template<typename Tx, typename = void>
struct is_container : std::false_type {};
template<typename Tx>
struct is_container<Tx,
	std::void_t<typename Tx::value_type,
	typename Tx::iterator,
	typename Tx::const_iterator,
	decltype(std::declval<Tx>().size()),
	decltype(std::declval<Tx>().begin()),
	decltype(std::declval<Tx>().end()),
	decltype(std::declval<Tx>().cbegin()),
	decltype(std::declval<Tx>().cend())>> :
std::true_type {};
#ifdef _MSC_VER
_STD_END
#else
}
#endif
struct Nil {
	using Head = Nil;
	using Tail = Nil;
};
template <typename H, typename T = Nil> struct List_T {
	using Head = H;
	using Tail = T;
};
template <typename L> struct Length {
	static constexpr unsigned int result = 1 + Length<typename L::Tail>::result;
};
template <> struct Length<Nil> { static constexpr unsigned int result = 0; };
// START TMP Sorting
template <class T> struct tag { using type = T; };
template <class Tag> using type_t = typename Tag::type;
template <int... Xs> struct values { constexpr values() = default; };
template <int... Xs> constexpr values<Xs...> values_v = {};
template <class... Vs> struct append;
template <class... Vs> using append_t=type_t<append<Vs...>>;
template <class... Vs> constexpr append_t<Vs...> append_v = {};
template <> struct append<> : tag<values<>> {};
template <int... Xs> struct append<values<Xs...>> : tag<values<Xs...>> {};
template <int... Lhs, int... Rhs, class... Vs>
struct append<values<Lhs...>, values<Rhs...>, Vs...> :
		tag<append_t<values<Lhs..., Rhs...>, Vs...>> {
};
template <int...Lhs>
constexpr values<Lhs...> simple_merge(values<Lhs...>, values<>) { return {}; }
template <int...Rhs>
constexpr values<Rhs...> simple_merge(values<>, values<Rhs...>) { return {}; }
constexpr values<> simple_merge(values<>, values<>) { return {}; }
template <int L0, int...Lhs, int R0, int...Rhs>
constexpr auto simple_merge(values<L0, Lhs...>, values<R0, Rhs...>)
-> std::conditional_t<
		(R0 < L0),
		append_t<values<R0>, decltype(simple_merge(values<L0, Lhs...>{}, values<Rhs...>{}))>,
		append_t<values<L0>, decltype(simple_merge(values<Lhs...>{}, values<R0, Rhs...>{}))>> {
	return {};
}
template <class Lhs, class Rhs>
using simple_merge_t = decltype(simple_merge(Lhs{}, Rhs{}));
template <class Lhs, class Rhs>
constexpr simple_merge_t<Lhs, Rhs> simple_merge_v = {};
template <class Values, size_t I> struct split {
private:
	using one = split<Values, I / 2>;
	using two = split<typename one::rhs, I - I / 2>;
public:
	using lhs = append_t<typename one::lhs, typename two::lhs>;
	using rhs = typename two::rhs;
};
template <class Values, size_t I> using split_t=type_t<split<Values, I>>;
template <class Values> struct split<Values, 0> {
	using lhs = values<>;
	using rhs = Values;
};
template <int X0, int...Xs> struct split<values<X0, Xs...>, 1> {
	using lhs = values<X0>;
	using rhs = values<Xs...>;
};
template <class Values, size_t I> using before_t = typename split<Values, I>::lhs;
template <class Values, size_t I> using after_t = typename split<Values, I>::rhs;
template <size_t I> using index_t = std::integral_constant<size_t, I>;
template <int I> using int_t = std::integral_constant<int, I>;
template <int I> constexpr int_t<I> int_v = {};
template <class Values> struct front;
template <int X0, int...Xs> struct front<values<X0, Xs...>> : tag<int_t<X0>> {};
template <class Values> using front_t = type_t<front<Values>>;
template <class Values> constexpr front_t<Values> front_v = {};
template <class Values, size_t I>
struct get : tag<front_t<after_t<Values, I>>> {};
template <class Values, size_t I> using get_t = type_t<get<Values, I>>;
template <class Values, size_t I> constexpr get_t<Values, I> get_v = {};
template <class Values>
struct length;
template <int... Xs>
struct length<values<Xs...>> : tag<index_t<sizeof...(Xs)>> {};
template <class Values> using length_t = type_t<length<Values>>;
template <class Values> constexpr length_t<Values> length_v = {};
template <class Values> using front_half_t = before_t<Values, length_v<Values> / 2>;
template <class Values> constexpr front_half_t<Values> front_half_v = {};
template <class Values> using back_half_t = after_t<Values, length_v<Values> / 2>;
template <class Values> constexpr back_half_t<Values> back_half_v = {};
template <class Lhs, class Rhs>
struct least : tag<std::conditional_t<(Lhs{} < Rhs{}), Lhs, Rhs> > {
};
template <class Lhs, class Rhs> using least_t = type_t<least<Lhs, Rhs>>;
template <class Lhs, class Rhs>
struct most : tag<std::conditional_t<(Lhs{} > Rhs{}), Lhs, Rhs> > {
};
template <class Lhs, class Rhs> using most_t = type_t<most<Lhs, Rhs>>;
template <class Values>
struct pivot {
private:
	using a = get_t<Values, 0>;
	using b = get_t<Values, length_v<Values> / 2>;
	using c = get_t<Values, length_v<Values> - 1>;
	using d = most_t<least_t<a, b>, most_t<least_t<b, c>, least_t<a, c>>>;
public:
	using type = d;
};
template <int X0, int X1>
struct pivot<values<X0, X1>> : tag<most_t<int_t<X0>, int_t<X1>>> {};
template <class Values> using pivot_t = type_t<pivot<Values>>;
template <class Values> constexpr pivot_t<Values> pivot_v = {};
template <int P>
constexpr values<> lower_split(int_t<P>, values<>) { return {}; }
template <int P, int X0>
constexpr std::conditional_t<(X0 < P), values<X0>, values<>> lower_split(int_t<P>, values<X0>) { return {}; }
template <int P, int X0, int X1, int... Xs>
constexpr auto lower_split(int_t<P>, values<X0, X1, Xs...>)
-> append_t<
		decltype(lower_split(int_v<P>, front_half_v<values<X0, X1, Xs...>>)),
		decltype(lower_split(int_v<P>, back_half_v<values<X0, X1, Xs...>>))
> {
	return {};
}
template <int P>
constexpr values<> upper_split(int_t<P>, values<>) { return {}; }
template <int P, int X0>
constexpr std::conditional_t<(X0 > P), values<X0>, values<>> upper_split(int_t<P>, values<X0>) { return {}; }
template <int P, int X0, int X1, int... Xs>
constexpr auto upper_split(int_t<P>, values<X0, X1, Xs...>) -> append_t<decltype(upper_split(int_v<P>, front_half_v<values<X0, X1, Xs...>>)), decltype(upper_split(int_v<P>, back_half_v<values<X0, X1, Xs...>>))> { return {}; }
template <int P>
constexpr values<> middle_split(int_t<P>, values<>) { return {}; }
template <int P, int X0>
constexpr std::conditional_t<(X0 == P), values<X0>, values<> > middle_split(int_t<P>, values<X0>) { return {}; }
template <int P, int X0, int X1, int... Xs>
constexpr auto middle_split(int_t<P>, values<X0, X1, Xs...>) -> append_t<decltype(middle_split(int_v<P>, front_half_v<values<X0, X1, Xs...>>)),
		decltype(middle_split(int_v<P>, back_half_v<values<X0, X1, Xs...>>))> { return {}; }
template <class Values>
using lower_split_t = decltype(lower_split(pivot_v<Values>, Values{}));
template <class Values> constexpr lower_split_t<Values> lower_split_v = {};
template <class Values>
using upper_split_t = decltype(upper_split(pivot_v<Values>, Values{}));
template <class Values> constexpr upper_split_t<Values> upper_split_v = {};
template <class Values>
using middle_split_t = decltype(middle_split(pivot_v<Values>, Values{}));
template <class Values> constexpr middle_split_t<Values> middle_split_v = {};
constexpr values<> simple_merge_sort(values<>) { return {}; }
template <int X>
constexpr values<X> simple_merge_sort(values<X>) { return {}; }
template <class Values>
using simple_merge_sort_t = decltype(simple_merge_sort(Values{}));
template <class Values>
constexpr simple_merge_sort_t<Values> simple_merge_sort_v = {};
template <int X0, int X1, int...Xs>
constexpr auto simple_merge_sort(values<X0, X1, Xs...>) -> simple_merge_t<simple_merge_t<simple_merge_sort_t<lower_split_t<values<X0, X1, Xs...>>>, simple_merge_sort_t<upper_split_t<values<X0, X1, Xs...>>>>, middle_split_t<values<X0, X1, Xs...>>> { return {}; }
template <class Values> constexpr Values cross_add(Values) { return {}; }
template <class Values> constexpr values<> cross_add(values<>, Values) { return {}; }
template <int A0, int... B> constexpr values<(B + A0)...> cross_add(values<A0>, values<B...>) { return {}; }
template <int A0, int A1, int...A, int...B>
constexpr auto cross_add(values<A0, A1, A...>, values<B...>) -> append_t<decltype(cross_add(front_half_v<values<A0, A1, A...>>, values_v<B...>)), decltype(cross_add(back_half_v<values<A0, A1, A...>>, values_v<B...>))> { return {}; }
template <class V0, class V1, class V2, class... Vs>
constexpr auto cross_add(V0, V1, V2, Vs...) -> decltype(cross_add(cross_add(V0{}, V1{}), V2{}, Vs{}...)) { return {}; }
template <class... Vs>
using cross_add_t = decltype(cross_add(Vs{}...));
template <class... Vs>
constexpr cross_add_t<Vs...> cross_add_v = {};
template <int X, int...Xs>
constexpr values<(X * Xs)...> scale(int_t<X>, values<Xs...>) { return {}; }
template <class X, class Xs>
using scale_t = decltype(scale(X{}, Xs{}));
template <class X, class Xs> constexpr scale_t<X, Xs> scale_v = {};
template <int X0, int...Xs> struct generate_values : generate_values<X0 - 1, X0 - 1, Xs...> {};
template <int...Xs> struct generate_values<0, Xs...> : tag<values<Xs...>> {};
template <int X0> using generate_values_t = type_t<generate_values<X0>>;
// END TMP Sorting
//END template metaprogramming

// START Virtual Inheritance
/*class Base {
 protected:
 int val = 0;
 public:
 Base() { std::cout << "Base class constructor called\n"; }
 void set(const int val) { this->val = val; }
 };
 class A : virtual public Base {
 public:
 A() { std::cout << "A constructor called\n"; }
 };
 class B : virtual public Base {
 public:
 B() { std::cout << "B constructor called\n"; }
 };
 class C : public B, public A {
 public:
 C() { std::cout << "C constructor called\n"; }
 int get() const {
 return this->val;
 }
 };*/
// END Virtual Inheritance
#endif // _PLIB_