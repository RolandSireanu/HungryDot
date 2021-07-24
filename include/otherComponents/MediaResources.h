#ifndef MEDIA_RESOURCES_H
#define MEDIA_RESOURCES_H

#include <string>

namespace MediaResources
{
    using namespace std;

    void init();
    string getFont();
    string getLeftDot();
    string getMiddleLeft();
    string getRightDot();
    string getMiddleRight();

    string getArrows();      
    string getVegetable();   
    string getIntroPic();    
    string getCannonLeft();  
    string getCannonRight(); 
    string getCannonUp();    
    string getCannonDown();  



    extern const string CONFIG_PATH;
    extern const string RES_FONT;
    extern string config_file;
};


#endif