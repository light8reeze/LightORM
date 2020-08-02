/**
	@file	orm.hpp
	@brief	LightORM Project's orm class function header
	@date	2020-07-28
	@auther light8reeze(light8reeze@gmail.com)
*/
#pragma once
#include <string_view>
#include <unordered_map>
#include <queue>

#define SET_ORM_CLASS()						\
	public:									\
		template <auto field_info>			\
		static auto&	get_variable()		\
		{									\
			return field_info::get_var();	\
		}									\
		template <auto field_info>				\
		static std::string_view get_colname()	\
		{										\
			return field_info::get_colname();	\
		}										\
		template <auto field_info>				\
		static std::string_view get_varname()	\
		{										\
			return field_info::get_varname();	\
		}\
		template<typename... args>\
		static constexpr auto get_columns(args&&... columns)\
		{\
			return std::make_tuple{ std::forward<args>(columns)... }; \
		}\
		template<typename column>\
		static constexpr auto get_column_name(column& col)\
		{\
			return col::get_colname();\
		}

#define BIND_COLUMN(column, value)		\
	public:								\
		const auto&						get_var_##column##() const	{return(value);}\
		const auto&						get_var_##value##()	const	{return(value);}\
		auto&							get_var_##column##()		{return(value);}\
		auto&							get_var_##value##()			{return(value);}\
		class var_info_##value			\
		{								\
			static constexpr std::string_view	get_varname()	{return(#value);}	\
			static constexpr std::string_view	get_colname()	{return(#column);}	\
		};\
		class column_info_##column		\
		{								\
			static constexpr std::string_view	get_varname()	{return(#value);}	\
			static constexpr std::string_view	get_colname()	{return(#column);}	\
		};

#define SET_KEY_COLUMN(column)		\
	public:							\
		std::string_view	key_column_name() const { return(#column);} \
		auto&				get_key_value() const {return(get_var_##column##());}

#define GET_VARIABLE(col) get_var_##col##()

#define GET_COLUMN(class_name,	variable) class_name::var_info_##variable##::get_colname()

namespace lorm
{
	template<typename db_system>
	class orm_system
	{
	public:
		orm_system() {}
		~orm_system() {}

		template<typename object, typename key_type>
		std::vector<object> fetch_object(key_type key, int top = 0);

		template<typename object, typename key_type>
		void fetch_object(key_type key, std::vector<object>& vec, int top = 0);

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