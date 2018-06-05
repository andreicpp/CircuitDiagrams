#ifndef SCHOTTKYDIODE_H
#define SCHOTTKYDIODE_H

#include <iostream>
#include "phototransistor.h"

/** @brief The schottky diode class

	In this class there are schottky diode characteristics
  @author Andrei Dailida
  @date May 2016
  */

class schottkyDiode:public phototransistor
{
  protected:
    unsigned int priceUSD;/**<Price of schottky diode in USD*/
  public:
    /**This function is necessary for factory work*/
    unsigned int getFactoryId();
    /** Default constructor*/
    schottkyDiode();
    /** My constructor. Initializes all schottky diode characteristics*/
    schottkyDiode(unsigned int, unsigned int, std::string, unsigned int, unsigned int, unsigned int);
    std::string listElem(bool);
    void readElem(std::ifstream &file);
    /**This function is necessary for factory work*/
    static baseElem * createschottkyDiode(){return new schottkyDiode();}
    /**This is factory id. It is necessary for factory work*/
    static unsigned int id;
};

#endif
