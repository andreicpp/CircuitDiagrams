#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <string>
#include <fstream>
#include <QComboBox>
#include "baseElem.h"
#include "document.h"
/** @brief The factory method pattern class

	This class is deal with the problem of creating objects without having to specify the exact class of the object that will be created
  @author Andrei Dailida
  @date May 2016
  */
class Factory {
public:

	static Factory & getInstance(){return factory_;};
	/** Register the type of element in factory*/
	unsigned int registerElem(CreateElem fun);
	/** Read elements characteristics from file
	\param input the name of file
	\param v elements vector
	*/
    void read_data (std::ifstream &input, My_vector &v , QComboBox *);
	baseElem * Create(unsigned int id);
		Factory(){};
private:
	static unsigned int ID_;
	static Factory factory_;

	My_map fig_creators_;


};
#endif
