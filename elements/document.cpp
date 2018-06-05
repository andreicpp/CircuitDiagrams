#include "document.h"
#include "factory.h"
#include <string>
#include <iostream>
#include <fstream>

document::document()
{
  Factory & f1=Factory::getInstance();
  phototransistor::id=f1.registerElem(phototransistor::createphototransistor);
  volSource::id=f1.registerElem(volSource::createvolScourse);
  battery::id=f1.registerElem(battery::createvolScourse);
  schottkyDiode::id=f1.registerElem(schottkyDiode::createphototransistor);
}

string document::getElemeInfo(int i)
{
  it=Elem_contener.begin() +i;
  string s;
  s=(*it)->listElem(true);
  return s;
}

int document::contSize()
{
  return(Elem_contener.size());
}

void document::txtSave(ofstream &file, QComboBox *a)
{
  int i=0;
  for (it=Elem_contener.begin();it!=Elem_contener.end();++it, ++i)
  {
    file << (*it)->getFactoryId() << " " << a->itemText(i).toStdString() << " " << (*it)->listElem(false);
    if(it+1 != Elem_contener.end()) file << endl;
  }
}

void document::svgSave(ofstream &file, unsigned int width, unsigned int height)
{
  file << "<svg \n baseProfile=\"full\" \n width=\"" << width << "\" height=\"" << height <<"\"\n" << " xmlns=\"http://www.w3.org/2000/svg\">\n";
  for (it=Elem_contener.begin();it!=Elem_contener.end();++it) (*it)->getSVG(file);
  file << "</svg>";
}
void document::txtRead(ifstream &file, QComboBox *a)
{
  Factory & f1=Factory::getInstance();
  f1.read_data(file, Elem_contener, a);
}
