#include <iostream>
#include <string>
#include <QComboBox>
#include <QDebug>
#include "Factory.h"

unsigned int Factory::registerElem(CreateElem fun)
{
//metoda automatycznie zwieksza licznikk ID_ i
//zapisuje pare
fig_creators_.insert(std::pair<unsigned int,CreateElem>(++ID_,fun));
//wynik zwracany przechowywany  przez kazda klase w polu statycznym id_
return ID_;
}

baseElem * Factory::Create(unsigned int id)
{
	//Metoda  na  podstawie id tworzy nowy obiekt
	My_map::iterator it=fig_creators_.find(id);
	if (it!=fig_creators_.end())
	{
		return (it->second)();
	}
return 0L;
}

void Factory::read_data (std::ifstream &input, My_vector & v, QComboBox *a)
{
    a->clear();
	//zmienne lokalne
    unsigned int type;
    string typeName, name, name2 = "";
	baseElem * tempElem;
    while(!input.eof())
    {
	//odczytujemy id_ klasy
    input >> type >> typeName >> name;
    if (name == "Diode:" || name == "Source:")
    {
        input >> name2;
        name+=" "+name2;
    }
    qDebug() << type;
	//tu tworzymy nowy obiekt
	tempElem=Create(type);
	//cout << tempElem->listElem();
    if (tempElem!=NULL)
        {
		//odczytanie danych juz do konkretnego obiektu
		//kozystamy tu z potegi funkcji wiryalnych
		tempElem->readElem(input);
		//wczytany obiekt (tak naprawde wskaznik do niego) umieszczamy w wektorze
		v.push_back(tempElem);
        a->addItem(QString::fromStdString(typeName) + " " + QString::fromStdString(name));
		}
	}
}
unsigned int Factory::ID_=1;
Factory Factory::factory_;
