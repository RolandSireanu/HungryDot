/*
 * DataBase.cpp
 *
 *  Created on: May 19, 2019
 *      Author: roland
 */


//dataBase.open("Media/Score" , std::ios::out|std::ios::in);

#include "DataBase.h"
#include <iostream>

std::weak_ptr<DataBase> DataBase::privateObject;

DataBase::DataBase()
{
	/*
	std::cout<<"DataBase constructor !"<<std::endl;
	dataBase.open("Media/Score" , std::ios::out|std::ios::in);

	if(dataBase.is_open())
	{
		std::cout<<"Succesfully opened the Score file "<<std::endl;
		std::cout<<"dataBase addr = "<<&dataBase<<std::endl;
	}
	else
	{
		std::cout<<"Error at open Score file ! "<<std::endl;
	}
	*/	
}


unsigned int DataBase::ReadBestScore()
{
	// unsigned int bs = 0;
	// std::string player;
	// std::string topPlayer;
	// unsigned int score = 0x00;
	// dataBase.open("Media/Score" , std::ios::in);
	// dataBase.seekg(0 , std::ios::beg);
	// while(dataBase>>player>>score)
	// {
	// 	if(score > bs)
	// 	{
	// 		bs = score;
	// 		topPlayer = player;
	// 	}
	// 	std::cout<<"player = "<<player<<" score = "<<score<<std::endl;
	// }
	
	// dataBase.close();
	return 0;
}

void DataBase::WriteScore(unsigned int arg_bestScore , const std::string& arg_player)
{
	auto it = db.find(arg_player);
	if(it != db.end())
	{
		db[arg_player] = (db[arg_player] < arg_bestScore ? arg_bestScore : db[arg_player]);
	}
	else
	{
		db[arg_player] = arg_bestScore;
	}
	
}

std::shared_ptr<DataBase> DataBase::GetObject()
{
    if (!privateObject.expired())
    {
    	std::cout<<"privateObject is not expired so lock and return "<<std::endl;
        return privateObject.lock();
    }

    std::cout<<"Make_shared private object , lock and reutrn !"<<std::endl;
    std::shared_ptr<DataBase> spdb = std::make_shared<DataBase>();
	spdb->LoadDbInternalRep();

    privateObject = spdb;

    return (privateObject.lock());
}

std::vector<DataBase::Player> DataBase::GetLeaderBoard()
{
	std::string playerName;
	unsigned int playerScore;
	std::vector<DataBase::Player> temp;
	
	for(auto& p : db)
	{
		temp.push_back(DataBase::Player(p.first , p.second));
	}

	std::sort(temp.begin() , temp.end() , TPlayer::compare);

	return temp;
}

void DataBase::LoadDbInternalRep()
{
	std::string pname;
	unsigned int pscore;
	dataBase.open("Media/Score" , std::ios::in);
	dataBase.seekg(0 , std::ios::beg);

	while(dataBase>>pname>>pscore)
	{
		//std::pair<std::string , unsigned int> p = std::make_pair(pname , pscore);
		auto it = db.find(pname);
		if(it != db.end())
		{
			unsigned int currentScore = db[pname];
			db[pname] = (currentScore < pscore) ? pscore : currentScore;
		}
		else
		{
			db[pname] = pscore;
		}		
	}

	dataBase.close();
}

void DataBase::ClearDataBase()
{	
	dataBase.open("Media/Score" , std::ios::out | std::ios::trunc);
	dataBase.close();

}

DataBase::~DataBase()
{
	std::cout<<"DataBase destructor !"<<std::endl;
	dataBase.open("Media/Score" , std::ios::out | std::ios::trunc);
	for(const auto& p : db)
	{
		dataBase<<p.first<<" "<<p.second<<std::endl;
	}
	dataBase.close();
}
