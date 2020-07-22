/**
	@file	database-system.hpp
	@brief	LightORM Project's DB module header
	@date	2020-07-19
	@auther light8reeze(light8reeze@gmail.com)
*/
#pragma once
#include "light-orm.hpp"

namespace lorm
{
	/**
		@brief				DB system class
		@param TDataBase	DataBase implement class
		@date				2020-07-19
		@auther				light8reeze(light8reeze@gmail.com)
	*/
	template <typename Tdatabase>
	class database_system
	{
	public:
		database_system();
		~database_system();

	private:
		Tdatabase	dbs;
	};
}