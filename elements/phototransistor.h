#ifndef PHOTOTRANSISTOR_H
#define PHOTOTRANSISTOR_H

#include <iostream>
#include "baseElem.h"

/** @brief The phototransistor class

	In this class there are phototransistor characteristics
  @author Andrei Dailida
  @date May 2016
  */

class phototransistor:public baseElem
{
protected:
  unsigned int width; /**<Phototransistor size */
  unsigned int stroke_weight; /**<Phototransistor SVG line size */

public:
  /** Default constructor*/
  phototransistor();
  /** My constructor. Initializes all phototransistor characteristics*/
  phototransistor(unsigned int, unsigned int, std::string, unsigned int, unsigned int);
  void getSVG(std::ofstream &file);
  void readElem(std::ifstream &file);
  unsigned int getFactoryId();
  std::string listElem(bool);
  /**This function is necessary for factory work*/
  static baseElem * createphototransistor(){return new phototransistor();}
  /**This is factory id. It is necessary for factory work*/
  static unsigned int id;
};

#endif
