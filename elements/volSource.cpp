#include <iostream>
#include <fstream>
#include <string>
#include "volSource.h"
using namespace std;

volSource::volSource(){}

volSource::volSource(unsigned int cxNew, unsigned int cyNew, string inColourNew, bool typeNew, unsigned int powerNew)
{
  cx=cxNew;
  cy=cyNew;
  inColour=inColourNew;
  type=typeNew;
  power=powerNew;
}

string volSource::listElem(bool b=false)
{
  string s, p;
  if (b==true) p="\n";
  else p=" ";
  s = to_string(cx)+ p + to_string(cy) + p + inColour + p;
  if(type == 1 && b==true) s+="A.C." + p;
  if(type == 0 && b==true) s+="D.C." + p;
  if(type == 1 && b==false) s+="1" + p;
  if(type == 0 && b==false) s+="1" + p;
  s+= to_string(power);
  return s;
}

void volSource::getSVG(std::ofstream &file)
{
  file << "<circle cx=\"" << cx << "\" cy=\"" << cy << "\" r=\"20\" stroke=\"black\"";
  file << " stroke-width=\"3\" fill=\"" << inColour << "\" />\n";
  file << "<text x=\"" << (cx-20) << "\" y=\"" << (cy+40) << "\">" << power << " V</text>\n";
  if(type==1) file << "<line x1=\"" << (cx-10) << "\" y1=\"" << (cy) << "\" x2=\"" <<  (cx+10)<<"\" y2=\""<< (cy)<<"\" stroke=\"black\" stroke-width=\"2\" />\n";
  if(type==0) file << "<polyline points=\""<< (cx-10)<<","<< (cy+5)<<" "<< (cx-5)<<","<< (cy-5)<<" "<< (cx+5)<<","<< (cy+5)<<" "<< (cx+10)<<","<< (cy-5) << "\" fill=\"none\" stroke=\"black\" />\n//\n";
}

void volSource::readElem(std::ifstream &file)
{
  unsigned int cxNew, cyNew, powerNew;
  string inColourNew;
  bool typeNew;
  file >> cxNew >> cyNew >> inColourNew >> typeNew >> powerNew;
  cx=cxNew;
  cy=cyNew;
  inColour=inColourNew;
  type=typeNew;
  power=powerNew;
}
unsigned int volSource::id;
unsigned int volSource::getFactoryId()
{
  return id;
}
