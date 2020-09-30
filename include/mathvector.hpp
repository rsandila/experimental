//
//  mathvector.hpp
//  experimental
//
//  Created by Robert Sandilands on 9/28/20.
//  Copyright © 2020 Robert Sandilands. All rights reserved.
//
//  Check LICENSE file for License

#pragma once

#if SUPPORTS_CPP_20
#include <compare>
#endif
#include <exception>
#include <math.h> 
#include <vector>

namespace experimental {
	/*! \brief A class to do simple vector math
	* 
	* Called MathVector so as to not confuse with std::vector
	*/
	template <typename T> class MathVector {
	private:
		std::vector<T> contents;
	protected:
	public:
		/*! \brief Default constructor
		*/
		MathVector() {
		}
		/*! \brief Fill constructor 
		\param size The size of the vector
		\param fill The value to populate the vector with */
		MathVector(size_t size, T fill) {
			contents.resize(size, fill);			
		}
		/*! \brief Copy constructor 
		* \param other Other vector to copy
		*/
		MathVector(const MathVector& other) {
			contents = other.contents;
		}
		/*! \brief Move constructor
		* \param other Other vector to move from
		*/
		MathVector(MathVector&& other) {
			contents = other.contents;
			other.contents.clear();
		}
		/*! \brief List constructor
		* \param list List of values to assign
		*/
		MathVector(const std::initializer_list<T> list) {
			contents = list;
		}
		/*! \brief Assignment operator 
		* \param other Other vector to assign
		*/
		MathVector<T>& operator=(const MathVector<T>& other) {
			if (this != &other) {
				contents = other.contents;
			}
			return *this;
		}
		/*! \brief Move operator 
		\param other Other vector to move from */
		MathVector<T>& operator=(MathVector<T>&& other) noexcept {
			if (this != &other) {
				contents = std::move(other.contents);
				other.contents.clear();
			}
			return *this;
		}
		/*! \brief Returns the size of the vector 
		\returns Size of the vector */
		inline size_t size() const noexcept {
			return contents.size();
		}
		/*! \brief Calculates the magnitude of the vector 
		\returns The magnitude of the vector */
		inline T magnitude() const noexcept {
			T value = 0;
			for (auto v : contents) {
				value += (v * v);
			}
			return (T)sqrt(value);
		}
#if SUPPORTS_CPP_20
		inline std::strong_ordering operator<=>(const MathVector<T>& rhs) const {
			if (contents.size() != rhs.contents.size()) {
				throw new std::logic_error();
			}
			auto myMag = magnitude();
			auto rhsMag = rhs.magnitude();
			if (myMag < rhsMag) {
				return std::strong_ordering::less;
			}
			if (myMag > rhsMag) {
				return std::strong_ordering::greater;
			}
			for (size_t i = 0; i < lhs.contents.size(); i++) {
				if (lhs.contents[i] != rhs.contents[i]) {
					return std::strong_ordering::equivalent;
				}
			}
			return std::strong_ordering::equal;
		}
#endif
		/*! \brief Less than operator
		* \param lhs First vector to compare
		* \param rhs Second vector to compare
		* \returns True if rhs < lhs
		*/
		inline friend bool operator< (const MathVector<T>& lhs, const MathVector<T>& rhs) {
			return lhs.magnitude() < rhs.magnitude();
		}
		/*! \brief Greater than operator
		* \param lhs First vector to compare
		* \param rhs Second vector to compare
		* \returns True if rhs > lhs
		*/
		inline friend bool operator> (const MathVector<T>& lhs, const MathVector<T>& rhs) { return rhs < lhs; }
		/*! \brief Less than or equal operator
		* \param lhs First vector to compare
		* \param rhs Second vector to compare
		* \returns True if rhs <= lhs
		*/
		inline friend bool operator<=(const MathVector<T>& lhs, const MathVector<T>& rhs) { return !(lhs > rhs); }
		/*! \brief Greater than or equal operator
		* \param lhs First vector to compare
		* \param rhs Second vector to compare
		* \returns True if rhs < lhs
		*/
		inline friend bool operator>=(const MathVector<T>& lhs, const MathVector<T>& rhs) { return !(lhs < rhs); }
		/*! \brief Equal operator
		* \param lhs First vector to compare
		* \param rhs Second vector to compare
		* \returns True if rhs == lhs
		*/
		inline friend bool operator==(const MathVector<T>& lhs, const MathVector<T>& rhs) {
			if (lhs.contents.size() != rhs.contents.size()) {
				return false;
			}
			for (size_t i = 0; i < lhs.contents.size(); i++) {
				if (lhs.contents[i] != rhs.contents[i]) {
					return false;
				}
			}
			return true;
		}
		/*! \brief Not equal operator
		* \param lhs First vector to compare
		* \param rhs Second vector to compare
		* \returns True if rhs != lhs
		*/
		inline friend bool operator!=(const MathVector<T>& lhs, const MathVector<T>& rhs) { return !(lhs == rhs); }
		/*! \brief Array subscript operator. Allows individual scalars in the vector to be accessed. Will throw exception on out of bounds access 
		\param idx Offset into vector 
		\returns Indexed scalar from vector */
		inline T& operator[](std::size_t idx) { 
			if (idx >= contents.size()) {
				throw new std::out_of_range("idx too big");
			}
			return contents[idx]; 
		}
		inline const T& operator[](std::size_t idx) const {
			return contents.at(idx);
		}
		/*! \brief operator +=. Adds a vector to the current one. If the vectors are not the same size then it will throw an exception
		\param rhs vector to add 
		\returns An instance of the target vector */
		inline MathVector<T>& operator+=(const MathVector<T>& rhs) {
			if (contents.size() != rhs.contents.size()) {
				throw new std::logic_error("Vector math on unequally sized vectors");
			}
			for (size_t i = 0; i < contents.size(); i++) {
				contents[i] += rhs[i];
			}
			return *this;
		}
		/*! \brief + operator. Adds two operators and returns the updated vector 
		\param lhs First vector
		\param rhs Second vector
		\returns Updated vector */
		inline friend MathVector<T> operator+(MathVector<T> lhs, const MathVector<T>& rhs) {
			lhs += rhs; 
			return lhs; 
		}
		// operator -=
		/*! \brief operator -=. Subtracts a vector from the current one. If the vectors are not the same size then it will throw an exception
		* \param rhs vector to subtract 
		* \returns An instance of the target vector */
		inline MathVector<T>& operator-=(const MathVector<T>& rhs) {
			if (contents.size() != rhs.contents.size()) {
				throw new std::logic_error("Vector math on unequally sized vectors");
			}
			for (size_t i = 0; i < contents.size(); i++) {
				contents[i] -= rhs[i];
			}
			return *this;
		}
		/*! \brief - operator. Subtracts two operators and returns the updated vector
		* \param lhs First vector
		* \param rhs Second vector
		* \returns Updated vector */
		inline friend MathVector<T> operator-(MathVector<T> lhs, const MathVector<T>& rhs) {
			lhs -= rhs;
			return lhs;
		}
		/*! \brief dotproduct. Multiplies two vectors and returns a scalar representing the dotproduct. If the vectors are not the same size then it will throw an exception
		* \param lhs First vector
		* \param rhs Second vector
		* \returns Updated vector */
		inline friend T operator*(MathVector<T> lhs, const MathVector<T>& rhs) {
			if (lhs.contents.size() != rhs.contents.size()) {
				throw new std::logic_error("Vector math on unequally sized vectors");
			}
			T retval = 0;
			for (size_t i = 0; i < lhs.contents.size(); i++) {
				retval += (lhs[i] * rhs[i]);
			}
			return retval;
		}
		/*! \brief Multiply a vector with a scalar
		\param rhs Scalar
		\returns Updated vector */
		inline MathVector<T>& operator*=(const T & rhs) {
			for (size_t i = 0; i < contents.size(); i++) {
				contents[i] *= rhs;
			}
			return *this;
		}
		/*! \brief Multiply a vector with a scalar
		* \param lhs Target vector
		* \param rhs Scalar
		* \returns Updated vector */
		inline friend MathVector<T> operator*(MathVector<T> lhs, const T & rhs) {
			lhs *= rhs;
			return lhs;
		}
	};
}