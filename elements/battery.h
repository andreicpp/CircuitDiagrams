#ifndef BATTERY_H
#define BATTERY_H

#include <iostream>
#include "volSource.h"

/** @brief The battery class

    In this class there are battery characteristics
    @author Andrei Dailida
    @date May 2016
    */

class battery:public volSource
{
  protected:
    unsigned int chargingMin;  /**<Time to charge battery*/
  public:
    /** Default constructor*/
    battery();
    /** My constructor. Initializes all battery characteristics*/
    battery(unsigned int, unsigned int, std::string, bool, unsigned int, unsigned int);
    std::string listElem(bool);
    void readElem(std::ifstream &file);
    unsigned int getFactoryId();
    void getSVG(std::ofstream &file);
    /**This is factory id. It is necessary for factory work*/
    static unsigned int id;
};

#endif
