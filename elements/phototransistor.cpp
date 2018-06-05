#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "phototransistor.h"

using namespace std;

phototransistor::phototransistor(){}

phototransistor::phototransistor(unsigned int cxNew, unsigned int cyNew, string inColourNew, unsigned int  widthNew, unsigned int stroke_weightNew)
{
	this->cx=cxNew;
	this->cy=cyNew;
	this->inColour=inColourNew;
	this->width=widthNew;
	this->stroke_weight=stroke_weightNew;
}

string phototransistor::listElem(bool b=false)//wypisuje specyfikacje tego elementu w terminalu
{
	string s,p;
	if (b==true) p="\n";
  else p=" ";
	s = to_string(cx) + p + to_string(cy) + p + inColour + p + to_string(width) + p + to_string(stroke_weight);
	return s;
}

void phototransistor::getSVG(std::ofstream &file)
{

//kolo
	file<<"<circle cx=\""<<cx<<"\" cy=\""<<cy<<"\" r=\""<<width<<"\" style=\"stroke:black; stroke-width:"<<stroke_weight;
   	file<<"; fill:"<<inColour <<"\" />";
//linia w kole
 	file<<endl<<" <line x1=\""<<(cx-width/4)<<"\" y1=\""<<(cy-3*width/4)<<"\" x2=\""<<(cx-width/4)<<"\" y2=\"";
	file<<(cy+3*width/4)<<"\""<<endl<<"style=\"stroke:black; stroke-width:"<<5*stroke_weight<<"\" />"<<endl;
//polyline strzalka z lewej bez strzalki
	file<<"<polyline points=\"";int x1=(cx-width/4)-5*stroke_weight; file<<x1<<",";
	int y1=cy; file<<y1<<" "; int x2=x1-3*width/4; file<<x2<<","; int y2=y1-3*width/4;
	file<<y2<<" ";
	int ll=sqrt(pow(x1-x2,2) + pow(y1-y2,2)); //dlugosc lini od od punkt x do y
	int x3=x2;
	file<<x3<<","; int y3=y2+ll/4; file<<y3<<" "<<x3-ll/3<<","<<y3-ll/3<<"\""<<endl;
 	file<<"style=\"fill:none; stroke:black; stroke-width:"<<stroke_weight<<"\" />"<<endl;
//polyline strzalka z lewej
	file<<"<polyline points=\""<<x1-5*stroke_weight/3<<","<<y1-5*stroke_weight<<" "<<x1<<","<<y1<<" "<<x1-5*stroke_weight<<",";
	file<<y1-5*stroke_weight/3<<" "<<x1-5*stroke_weight/3<<","<<y1-5*stroke_weight<<endl;
 	file<<"\" style=\"fill:"<<inColour << "; stroke:black; stroke-width:"<<stroke_weight<<"\" />"<<endl;

}

void phototransistor::readElem(std::ifstream &file)
{
	unsigned int cxNew, cyNew, widthNew, stroke_weightNew;
	string inColourNew;
	file >> cxNew >> cyNew >> inColourNew >> widthNew >> stroke_weightNew;
	this->cx=cxNew;
	this->cy=cyNew;
	this->inColour=inColourNew;
	this->width=widthNew;
	this->stroke_weight=stroke_weightNew;
}

unsigned int phototransistor::id = 0;

unsigned int phototransistor::getFactoryId()
{
  return id;
}
