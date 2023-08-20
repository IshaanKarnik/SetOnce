/// @file  SetOnce.hxx
/// @brief This file contains all required definations and implementation for the SetOnce library
/// @author Ishaan Karnik
/// @date 20-08-2023

#pragma once
#include <mutex>
#include <atomic>

namespace set_once
{
	/// @brief This class is used to throw excetion stating data nas not been set for the SetOnce object
	class DataNotSetException : public std::exception
	{
	private:
		const char* message{ "Data Not Set before Get Operation" };
	public:
		/// @brief returns the human readable exception in string format
		/// @return Returns the exception in const char * format
		const char* what() const override
		{
			return message;
		}
	};

	/// @brief This class allows teh object to be initialized only once but can be read any number of times.
	/// @tparam Any Plain Old Data (POD)
	template<typename T>
	class SetOnce
	{
	private:
		T data;
		std::once_flag flag;
		std::atomic_bool data_set{ false };
		void do_once(const T& data);

#ifdef DELETE_COPY_CONSTRUCTOR
		SetOnce(const SetOnce& copy_from_me) = delete; //Delete Copy Constructor
		SetOnce& operator=(const SetOnce& copy_assign_from_me) = delete; // Delete copy-assignments
#endif // DELETE_COPY_CONSTRUCTOR

#ifdef DELETE_MOVE_CONSTRUCTOR
		SetOnce(SetOnce&& move_from_me) = delete; //Delete Move constructor
		SetOnce& operator=(SetOnce&& move_assign_from_me) = delete; //Delete Move assignment operator
#endif // DELETE_MOVE_CONSTRUCTOR

	public:
		T get(void) const;
		const T& get_const_reference(void) const;
		void set(const T& data);
		bool is_set(void) const;
	};

	template<typename T>
	inline void SetOnce<T>::do_once(const T& data)
	{
		this->data = data;
		this->data_set.store(true);
	}


	/// @brief Returns previously stored data by value. If data is not been set throw data not set exception (DataNotSetException)
	/// @tparam Any POD where data can be stored
	/// @param  None
	/// @return Returns the value that was previously set.
	/// @author Ishaan Karnik
	/// @date 20-08-2023
	template<typename T>
	inline T SetOnce<T>::get(void) const
	{
		if (this->is_set() == true)
		{
			return this->data;
		}
		else
		{
			throw DataNotSetException();
		}
	}

	/// @brief Returns previously stored data as constant reference. If data is not been set throw data not set exception (DataNotSetException)
	/// @tparam Any POD where data can be stored 
	/// @param  None
	/// @return Returns the value that was previously set as constant reference. 
	/// @author Ishaan Karnik
	/// @date 20-08-2023
	template<typename T>
	inline const T& SetOnce<T>::get_const_reference(void) const
	{
		if (this->is_set() == true)
		{
			return this->data;
		}
		else
		{
			throw DataNotSetException();
		}
	}

	/// @brief Sets/Initializes the value to the SetOnce object. This method only runs onces. Any subsequent rus have no effect. on the previously stored value.
	/// @tparam Any POD where data can be stored 
	/// @param Data to be stored
	/// @author Ishaan Karnik
	/// @date 20-08-2023
	template<typename T>
	inline void SetOnce<T>::set(const T& data)
	{
		std::call_once(this->flag, &SetOnce::do_once, this, data);
	}

	/// @brief This method checks if the valoe has been set for the SetOnce object.
	/// @tparam Any POD where data can be stored 
	/// @param  None
	/// @return True or False depending on whether the value has been set.
	template<typename T>
	inline bool SetOnce<T>::is_set(void) const
	{
		return this->data_set.load();
	}
}


