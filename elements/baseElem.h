#ifndef BASEELEM_H
#define BASEELEM_H
#include <iostream>
#include <QComboBox>
/** @brief The main class

    In this class have got only virtual functions
    @author Andrei Dailida
    @date May 2016
    */

class baseElem
{
  protected:
  unsigned int cx; /**<SVG elements x-coordinate*/
  unsigned int cy; /**<SVG elements y-coordinate*/
  std::string inColour; /**<SVG elements colour*/

public:
  /**Function is necessary for factory*/
  virtual unsigned int getFactoryId() = 0;
  /**SVG file generation
  \param file the name of file
  */
  virtual void getSVG(std::ofstream &file)=0;
  /**Generate concole element's info*/
  virtual std::string listElem(bool)=0;
  /**Read element's info from file
  \param file the name of file
  */
  virtual void readElem(std::ifstream &file)=0;
};

#endif
