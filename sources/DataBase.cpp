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
	unsigned int bs = 0;
	std::string player;
	std::string topPlayer;
	unsigned int score = 0x00;
	dataBase.open("Media/Score" , std::ios::in);
	dataBase.seekg(0 , std::ios::beg);
	while(dataBase>>player>>score)
	{
		if(score > bs)
		{
			bs = score;
			topPlayer = player;
		}
		std::cout<<"player = "<<player<<" score = "<<score<<std::endl;
	}
	
	dataBase.close();
	return bs;
}

void DataBase::WriteBestScore(unsigned int arg_bestScore , const std::string& arg_player)
{
	dataBase.open("Media/Score" , std::ios::app);	
	
	if(dataBase.is_open())
	{
		dataBase<<arg_player<<" "<<arg_bestScore<<std::endl;		
	}
	else
	{
		std::cout<<"Score file is not opened anymore !"<<std::endl;
	}
	dataBase.close();	
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
    privateObject = spdb;

    return (privateObject.lock());
}

DataBase::~DataBase()
{
	std::cout<<"DataBase destructor !"<<std::endl;
	dataBase.close();
}
