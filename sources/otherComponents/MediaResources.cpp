#include "MediaResources.h"
#include <fstream>
#include <iostream>

namespace MediaResources
{
    using namespace std;

    string getFont()            { return getConfigFile()+"/arial.ttf"; }
    string getLeftDot()         { return getConfigFile()+"/LeftDot.png"; }
    string getMiddleLeft()      { return getConfigFile()+"/MiddleLeft.png"; }
    string getRightDot()        { return getConfigFile()+"/RightDot.png"; }
    string getMiddleRight()     { return getConfigFile()+"/MiddleRight.png"; }
    
    string getArrows()          { return getConfigFile()+"/Arrows.png"; }
    string getVegetable()       { return getConfigFile()+"/Vegetable.png"; }
    string getIntroPic()        { return getConfigFile()+"/IntroPic.png"; }

    string getCannonLeft()      { return getConfigFile()+"/CannonLeft.png"; }
    string getCannonRight()     { return getConfigFile()+"/CannonRight.png"; }
    string getCannonUp()        { return getConfigFile()+"/CannonUp.png"; }
    string getCannonDown()      { return getConfigFile()+"/CannonDown.png"; }

    string getMenuMusic()       { return getConfigFile()+"/StateMenuMusic.ogg"; }
    string getGameMusic()       { return getConfigFile()+"/StateGameMusic.ogg"; }

    string getScore()           { return getConfigFile()+"/Score"; }

    string getConfigFile()
    {
        static bool firstRun = true;
        static string config_file;
        if(firstRun)
        {
            const string CONFIG_PATH = "../configFile";
            ifstream f(CONFIG_PATH);
            getline(f, config_file);
            f.close();
            std::cout << "config_file = " << config_file << endl;
            firstRun = false;
        }

        return config_file;
        // static const string getConfigFile() = "/Users/sireanuroland/Work/FastRampUp/C++_Ramp_up/SFML_Projects/HungryDot/Media";
    }
    

};