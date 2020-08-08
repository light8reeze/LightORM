/**
	@file	maria-db.hpp
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

		template <size_t size>
		std::string_view get_update_query(const std::array<std::string_view, size>& columns, const std::array<std::string_view, size>& values);
		template <size_t size, typename key_type = void>
		std::string_view get_select_query(const std::array<std::string_view, size>& columns, std::string_view key_column, key_type key);
		template <size_t size>
		std::string_view get_select_query(const std::array<std::string_view, size>& columns);
		template <size_t size>
		std::string_view get_insert_query(const std::array<std::string_view, size>& columns, const std::array<std::string_view, size>& values);
		template <typename object>
		object fetch();

	private:
		db_type		mysql;
		res_type	result;
	};
}