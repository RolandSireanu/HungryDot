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
	std::cout<<"DataBase constructor !"<<std::endl;
	dataBase.open("Media/Score" , std::ios::out|std::ios::in);
}


unsigned int DataBase::ReadBestScore()
{
	unsigned int bs = 0;
	dataBase>>bs;
	dataBase.seekg(0 , std::ios::beg);

	return bs;

}

void DataBase::WriteBestScore(unsigned int arg_bestScore)
{
	dataBase<<arg_bestScore<<std::endl;
	dataBase.seekg(0 , std::ios::beg);
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
