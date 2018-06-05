#include <fstream>
#include <string>
#include "schottkyDiode.h"

using namespace std;

schottkyDiode::schottkyDiode(unsigned int cxNew, unsigned int cyNew, string inColourNew, unsigned int  widthNew, unsigned int stroke_weightNew, unsigned int priceUSDNew)
:phototransistor::phototransistor(cxNew, cyNew, inColourNew, widthNew, stroke_weightNew)
{
  this->priceUSD = priceUSDNew;
}

void schottkyDiode::readElem(std::ifstream &file)
{
  phototransistor::readElem(file);
  unsigned int priceNew;
  file >> priceNew;
  this->priceUSD = priceNew;
}

string schottkyDiode::listElem(bool b=false)
{
  if(b==true) return (phototransistor::listElem(true)+ "\n" + to_string(priceUSD));
  else return (phototransistor::listElem(false)+ " " + to_string(priceUSD));
}
unsigned int schottkyDiode::id;
unsigned int schottkyDiode::getFactoryId()
{
  return id;
}
