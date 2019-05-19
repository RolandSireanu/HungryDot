/*
 * DataBase.h
 *
 *  Created on: May 19, 2019
 *      Author: roland
 */

#ifndef HUNGRYDOT_INCLUDE_DATABASE_H_
#define HUNGRYDOT_INCLUDE_DATABASE_H_

#include <fstream>
#include <memory>

class DataBase
{

	public:
		static std::shared_ptr<DataBase> GetObject();
		unsigned int ReadBestScore();
		void WriteBestScore(unsigned int );
		DataBase();
		~DataBase();

	private:

		DataBase(const DataBase&) = delete;
		DataBase(const DataBase&&) = delete;
		DataBase& operator=(const DataBase&) = delete;


		static std::weak_ptr<DataBase> privateObject;
		std::fstream dataBase;


};



#endif /* HUNGRYDOT_INCLUDE_DATABASE_H_ */
