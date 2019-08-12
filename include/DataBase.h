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
#include <utility>
#include <map>
#include <vector>
#include <algorithm>


class DataBase
{

	public:
		struct TPlayer
		{
			TPlayer(const std::string &arg_name , unsigned int arg_score)
			{
				this->name = arg_name;
				this->score = arg_score;
			}

			std::string name;
			unsigned int score;

			static bool compare(TPlayer p1 , TPlayer p2)
			{
				return p1.score > p2.score;
			}
		};

	using Player = struct TPlayer;

	public:
		static std::shared_ptr<DataBase> GetObject();
		unsigned int ReadBestScore();

		std::vector<Player> GetLeaderBoard();
		void WriteScore(unsigned int , const std::string&);
		void ClearDataBase();

		DataBase();
		~DataBase();

	private:

		struct comparator
		{
			bool operator() (std::pair<std::string , unsigned int> a , std::pair<std::string , unsigned int> b)
			{
				return a.first == b.first;
			}
		};

		void LoadDbInternalRep();
		DataBase(const DataBase&) = delete;
		DataBase(const DataBase&&) = delete;
		DataBase& operator=(const DataBase&) = delete;


		static std::weak_ptr<DataBase> privateObject;
		std::fstream dataBase;
		std::map<std::string , unsigned int> db;


};



#endif /* HUNGRYDOT_INCLUDE_DATABASE_H_ */
