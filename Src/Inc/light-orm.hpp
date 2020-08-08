/**
	@file	light-orm.hpp
	@brief	LightORM Project's macro header
	@date	2020-07-19
	@auther light8reeze(light8reeze@gmail.com)
*/
#pragma once
#include <type_traits>

/**
	@brief	Platform definition Macro
	@date	2020-07-19
*/
#define LORM_WINDOW
#define LORM_LINUX

/**
	@brief	Develop mode Macro
	@date	2020-07-19
*/
#define LORM_DEVELOP_MODE

namespace lorm
{
	template <typename element, typename f, std::size_t... i>
	void for_each_tuple_impl(const element& elem, f function, std::index_sequence<i...>)
	{
		(function(std::get<I>(elem)), ...);
	}

	template <typename f, typename... args>
	void for_each_tuple(std::tuple<args...>& tuple, f function)
	{
		for_each_tuple_impl(tuple, function, std::index_sequence_for<args...>{});
	}
}