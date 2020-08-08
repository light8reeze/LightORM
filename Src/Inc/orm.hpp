/**
	@file	orm.hpp
	@brief	LightORM Project's orm class function header
	@date	2020-07-28
	@auther light8reeze(light8reeze@gmail.com)
*/
#pragma once
#include "light-orm.hpp"
#include <string_view>
#include <array>
#include <unordered_map>
#include <queue>

#define SET_ORM_CLASS()\
	public:\
		template <auto field_info>\
		static auto&	get_variable()\
		{\
			return field_info::get_var();\
		}\
		template <auto field_info>\
		static std::string_view get_colname()\
		{\
			return field_info::get_colname();\
		}\
		template <auto field_info>\
		static std::string_view get_varname()\
		{\
			return field_info::get_varname();\
		}\
		template<typename... args>\
		static constexpr auto get_columns(args&&... columns)\
		{\
			return std::make_tuple{ std::forward<args>(columns)... };\
		}\
		template<typename... args>\
		static constexpr auto get_column_size_impl(args&&... columns)\
		{\
			return sizeof...(columns);\
		}

#define BIND_COLUMN(column, value)	\
	public:\
		const auto&	get_var_##column##() const	{return(value);}\
		const auto&	get_var_##value##()	const	{return(value);}\
		auto&		get_var_##column##()		{return(value);}\
		auto&		get_var_##value##()			{return(value);}\
		class var_info_##value \
		{\
		public:\
			static constexpr std::string_view	get_varname()	{return(#value);}\
			static constexpr std::string_view	get_colname()	{return(#column);}\
		};\
		class column_info_##column	\
		{\
		public:\
			static constexpr std::string_view	get_varname()	{return(#value);}\
			static constexpr std::string_view	get_colname()	{return(#column);}\
		};\
		const	column_info_##column	column;

#define SET_KEY_COLUMN(column)	\
	public:\
		std::string_view	key_column_name() const { return(#column);}\
		const auto&			get_key_value() const {return(get_var_##column##());}\
		const auto&			get_key_column() const { return(##column##); }

#define BIND_ORM_CLASS(...)	\
	public:\
		constexpr auto	get_column_size()	{ return get_column_size_impl(##__VA_ARGS__); }\
		constexpr auto	get_columns()		{ return std::make_tuple(__VA_ARGS__); }

#define COLUMN_INFO(class_name,	variable) class_name::var_info_##variable

namespace lorm
{
	template<typename db_system>
	class orm_system
	{
	public:
		orm_system() {}
		~orm_system() {}

		template<typename object, typename key_type, typename key_column>
		std::vector<object> fetch_object(key_type key, int top = 0)
		{
			std::vector<object> result;
			fetch_object(key, result, top);
			return result;
		}

		template<typename object, typename key_type>
		void fetch_object(key_type key, std::vector<object>& vec, int top = 0)
		{
		}

		template<typename object>
		void insert_object(const object& obj);

		template<typename object>
		void insert_object(std::vector<object>& vec);

		template<typename object, size_t size>
		void insert_object(std::array<object, size>& arr);

		template<typename object>
		void update_object(object& obj);

		template<typename object>
		void update_object(std::vector<object>& vec);

		template<typename object, size_t size>
		void update_object(std::array<object, size>& arr);
	};
}