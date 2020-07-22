/**
	@file	reflection.hpp
	@brief	LightORM Project's reflection class header
	@date	2020-07-22
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
		class_type_info();
		~class_type_info();

		void add_field(std::string_view var_name);
		std::string_view find(std::string_view var_name);

		std::string class_name;
	};
}