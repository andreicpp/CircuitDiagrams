#include <fstream>
#include <string>
#include "battery.h"

using namespace std;

battery::battery(unsigned int cxNew, unsigned int cyNew, string inColourNew, bool typeNew, unsigned int powerNew, unsigned int chargingMinNew)
:volSource::volSource(cxNew, cyNew, inColourNew, typeNew, powerNew)
{
  this->chargingMin = chargingMinNew;
}

string battery::listElem(bool b=false)
{
  if (b==true) return (volSource::listElem(true)+ "\n" + to_string(chargingMin));
  else return (volSource::listElem(false)+ " " + to_string(chargingMin));
}

void battery::readElem(std::ifstream &file)
{
  volSource::readElem(file);
  unsigned int timeNew;
  file >> timeNew;
  this->chargingMin = timeNew;
}

void battery::getSVG(ofstream &file)
{
  this->volSource::getSVG(file);
  file << this->chargingMin << "\n";
}

unsigned int battery::id;
unsigned int battery::getFactoryId()
{
  return id;
}
