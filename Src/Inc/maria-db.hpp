/**
	@file	MariaDB.hpp
	@brief	LightORM Project's Maria DB connection header
	@date	2020-07-19
	@auther light8reeze(light8reeze@gmail.com)
*/
#pragma once
#ifndef LORM_MARIADB
	#define LORM_MARIADB
#endif //LORM_MARIADB
#include <mysql.h>
#include <string>
#include "light-orm.hpp"

namespace lorm
{
	/**
		@brief				Maria DB system class
		@date				2020-07-21
		@auther				light8reeze(light8reeze@gmail.com)
	*/
	class maria_db
	{
	public:
		using db_type	= MYSQL;
		using row_type	= MYSQL_ROW;
		using res_type	= MYSQL_RES;

		maria_db();
		~maria_db();

		void connect();
		void command(std::string& query);
		void close();

	private:


	private:
		db_type mysql;
	};
}