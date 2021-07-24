#include "MediaResources.h"
#include <fstream>
#include <iostream>

namespace MediaResources
{
    using namespace std;

    void init()
    {
        ifstream f(CONFIG_PATH);
        getline(f, config_file);
        f.close();
        std::cout << "config_file = " << config_file << endl;
    }

    const string CONFIG_PATH = "../configFile";
    const string RES_FONT = "/arial.ttf";
    const string RES_LEFT_DOT = "/LeftDot.png";
    const string RES_MIDDLE_LEFT = "/MiddleLeft.png";
    const string RES_RIGHT_DOT = "/RightDot.png";
    const string RES_MIDDLE_RIGHT = "/MiddleRight.png";

    const string RES_ARROWS = "/Arrows.png";
    const string RES_VEGETABLE = "/Vegetable.png";
    const string RES_INTRO_PIC = "/IntroPic.png";

    const string RES_CANNON_LEFT = "/CannonLeft.png";
    const string RES_CANNON_RIGHT = "/CannonRight.png";
    const string RES_CANNON_UP = "/CannonUp.png";
    const string RES_CANNON_DOWN = "/CannonDown.png";

    string getFont()            { return config_file+RES_FONT; }
    string getLeftDot()         { return config_file+RES_LEFT_DOT; }
    string getMiddleLeft()      { return config_file+RES_MIDDLE_LEFT; }
    string getRightDot()        { return config_file+RES_RIGHT_DOT; }
    string getMiddleRight()     { return config_file+RES_MIDDLE_RIGHT; }
    
    string getArrows()          { return config_file+RES_ARROWS; }
    string getVegetable()       { return config_file+RES_VEGETABLE; }
    string getIntroPic()        { return config_file+RES_INTRO_PIC; }

    string getCannonLeft()      { return config_file+RES_CANNON_LEFT; }
    string getCannonRight()     { return config_file+RES_CANNON_RIGHT; }
    string getCannonUp()        { return config_file+RES_CANNON_UP; }
    string getCannonDown()      { return config_file+RES_CANNON_DOWN; }





    string config_file;

};