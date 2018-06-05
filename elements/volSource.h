#ifndef VOLSOURCE_H
#define VOLSOURCE_H

#include <iostream>
#include "baseElem.h"
/** @brief The voltage source class

	In this class there are voltage source characteristics
  @author Andrei Dailida
  @date May 2016
  */
class volSource:public baseElem
{
protected:
  bool type; /**<Shows is voltage source AC or DC \warning '0' - DC or '1' - AC */
  unsigned int power; /**<Voltage source power w [V]*/

public:
  /**This function is necessary for factory work*/
  unsigned int getFactoryId();
  /** Default constructor*/
  volSource();
  /** My constructor. Initializes all voltage source characteristics*/
  volSource(unsigned int, unsigned int, std::string, bool, unsigned int);
  void getSVG(std::ofstream &file);
  void readElem(std::ifstream &file);
  std::string listElem(bool);
  /**This function is necessary for factory work*/
  static baseElem * createvolScourse(){return new volSource();}
  /**This is factory id. It is necessary for factory work*/
  static unsigned int id;
};

#endif
