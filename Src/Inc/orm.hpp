/**
	@file	orm.hpp
	@brief	LightORM Project's orm class function header
	@date	2020-07-28
	@auther light8reeze(light8reeze@gmail.com)
*/
#pragma once
#include <string_view>
#include <unordered_map>

namespace lorm
{
	/**
		@brief				Class type info class
		@detail				Store class type info in runtime
		@date				2020-07-22
		@auther				light8reeze(light8reeze@gmail.com)
	*/
	class class_type_info
	{
	private:
		using field_list = std::unordered_map<std::string, std::string>;

	public:
		class_type_info(std::string_view _class_name) : class_name(_class_name){}
		~class_type_info(){}

		void add_field(std::string_view property_name, std::string_view var_name)
		{
			field_name_list.emplace(property_name, var_name);
		}
		std::string_view find(std::string_view property_name)
		{
			auto iter = field_name_list.find(std::string(property_name));
			if (iter == field_name_list.end())
				return std::string_view{};
			
			return std::string_view{ iter->second };
		}

		std::string class_name{};
		field_list	field_name_list{};
	};

	/**
		@brief				Class type info add helper class
		@detail				Help add class type for user
		@date				2020-07-27
		@auther				light8reeze(light8reeze@gmail.com)
	*/
	class class_reflection_helper
	{
	};
}