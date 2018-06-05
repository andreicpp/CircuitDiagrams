#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <QCombobox>
#include "phototransistor.h"
#include "volSource.h"
#include "battery.h"
#include "schottkyDiode.h"
#include "baseElem.h"

typedef baseElem * (*CreateElem)();
typedef std::vector <baseElem *> My_vector;
typedef std::map<unsigned int, CreateElem> My_map;

using namespace std;

/** @brief This class is used to storing and managing elements

	In this class you have got vector, in which yours elements are situated and functions, witch can manage yours elements
  @author Andrei Dailida
  @date May 2016
  */

class document
{
private:

public:
  My_vector Elem_contener;  /**<Vector, which keeps elements */
  My_vector::iterator it;
/** Default constructor*/
  document();
  int contSize();
  /** Write all existing elements in terminal*/
  string getElemeInfo(int);
  /** Import all existing elements to SVG file
  \param file the name of file
  \param width, height - the width and height of SVG file
  \warning Before you save elements in file, this file should be created successfully
  */
  void svgSave(ofstream &, unsigned int, unsigned int);
  /** Import all existing elements in TXT file
  \param file the name of file
  \warning Before you save elements in file, this file should be created successfully
  */
  void txtSave(ofstream &, QComboBox*);
  /** Export all existing elements from TXT file
  \param file the name of file
  \warning Before you export elements from file, this file should exist
  */
  void txtRead(ifstream &, QComboBox *);
  /** Overloaded operator '+'. It add new element to elements vector.
  \param *new_element a pointer to the element
  */
  document& operator+(baseElem *new_element)
  {
    this->Elem_contener.push_back(new_element);
    return *this;
  }
  /** Overloaded operator '-'. It delite element from elements vector.
  \param id the number of element, which you whant to delite
  \warning if 'id' = 0, this operator will delite all elements
  */
  document& operator-(int id)
  {
    if (id!=0)
    this->Elem_contener.erase(Elem_contener.begin()+(id-1), Elem_contener.begin()+id);
    else
    this->Elem_contener.clear();
    return *this;
  }
};



#endif
