#include "addelement.h"
#include "ui_addelement.h"
#include <mainwindow.h>
#include <QString>
#include<QTextStream>
#include <QDebug>
#include <QMessageBox>
addElement::addElement(QWidget *parent, document *a, QComboBox *b, QString c) :
    QDialog(parent),
    ui(new Ui::addElement)
{
    elementsContainer = a;
    mainWindowElementComboBox = b;
    modificateElem = c;
    ui->setupUi(this);
    connect( ui->addElementBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &addElement::addElementBoxIndexChanged );
    if(c != "add")
    {
        ui->addElementBox->clear();
        ui->addElementBox->addItem(modificateElem.left(modificateElem.indexOf(':')));
        ui->nameLineEdit->setText(modificateElem.right(modificateElem.length() - modificateElem.indexOf(':')-2));
        ui->addElementBox->setEnabled(false);
        setWindowTitle(c + " (modificate mode)");
    }
}
addElement::~addElement()
{
    delete ui;
}


void addElement::addElementBoxIndexChanged()
{
    if( QString::compare(ui->addElementBox->currentText(), "Phototransistor", Qt::CaseInsensitive) == 0 || QString::compare(ui->addElementBox->currentText(), "Schottky Diode", Qt::CaseInsensitive) == 0)
        {
            ui->lineSizeBox->setEnabled(true);
            ui->elementRadiusSpinBox->setEnabled(true);
            ui->elementPriceSpinBox->setEnabled(false);
            ui->currentComboBox->setEnabled(false);
            ui->elementPowerPinBox->setEnabled(false);
            ui->elementTimePinBox->setEnabled(false);
        }
    if( QString::compare(ui->addElementBox->currentText(), "Schottky Diode", Qt::CaseInsensitive) == 0)
        {
            ui->elementPriceSpinBox->setEnabled(true);
        }
    if( QString::compare(ui->addElementBox->currentText(), "Voltage Source", Qt::CaseInsensitive) == 0 || QString::compare(ui->addElementBox->currentText(), "Battery", Qt::CaseInsensitive) == 0)
        {
            ui->lineSizeBox->setEnabled(false);
            ui->elementRadiusSpinBox->setEnabled(false);
            ui->elementPriceSpinBox->setEnabled(false);
            ui->currentComboBox->setEnabled(true);
            ui->elementPowerPinBox->setEnabled(true);
            ui->elementTimePinBox->setEnabled(false);
        }
    if( QString::compare(ui->addElementBox->currentText(), "Battery", Qt::CaseInsensitive) == 0)
        {
            ui->elementTimePinBox->setEnabled(true);
        }
}

void addElement::on_okPushButton_clicked()
{
    if(ui->nameLineEdit->text().trimmed() != "" )
    {

    bool current = false;
    if(QString::compare(ui->currentComboBox->currentText(), "Alternating Current (A.C.)", Qt::CaseInsensitive) == 0)
        current = true;

    if( QString::compare(ui->addElementBox->currentText(), "Voltage Source", Qt::CaseInsensitive) == 0 || modificateElem.left(1) == "V")
    {
        if(modificateElem.left(1) == "V")
            elementsContainer->Elem_contener[mainWindowElementComboBox->currentIndex()] = (new volSource((ui->xSpinBox->cleanText()).toInt(), (ui->ySpinBox->cleanText()).toInt(), (ui->colourBox->currentText()).toStdString(), current, (ui->elementPowerPinBox->cleanText()).toInt()));
        else
            *elementsContainer+(new volSource((ui->xSpinBox->cleanText()).toInt(), (ui->ySpinBox->cleanText()).toInt(), (ui->colourBox->currentText()).toStdString(), current, (ui->elementPowerPinBox->cleanText()).toInt()));
    }
    if(( QString::compare(ui->addElementBox->currentText(), "Phototransistor", Qt::CaseInsensitive) == 0 && modificateElem == "add") || modificateElem.left(1) == "P")
    {
        if(modificateElem.left(1) == "P")
            elementsContainer->Elem_contener[mainWindowElementComboBox->currentIndex()] = new phototransistor((ui->xSpinBox->cleanText()).toInt(), (ui->ySpinBox->cleanText()).toInt(), (ui->colourBox->currentText()).toStdString(), (ui->elementRadiusSpinBox->cleanText()).toInt(), (ui->lineSizeBox->currentText()).toInt());
        else
            *elementsContainer+(new phototransistor((ui->xSpinBox->cleanText()).toInt(), (ui->ySpinBox->cleanText()).toInt(), (ui->colourBox->currentText()).toStdString(), (ui->elementRadiusSpinBox->cleanText()).toInt(), (ui->lineSizeBox->currentText()).toInt()));
    }

    if( QString::compare(ui->addElementBox->currentText(), "Schottky Diode", Qt::CaseInsensitive) == 0 || modificateElem.left(1) == "S")
    {
        if(modificateElem.left(1) == "S")
            elementsContainer->Elem_contener[mainWindowElementComboBox->currentIndex()] = new schottkyDiode((ui->xSpinBox->cleanText()).toInt(), (ui->ySpinBox->cleanText()).toInt(), (ui->colourBox->currentText()).toStdString(), (ui->elementRadiusSpinBox->cleanText()).toInt(), (ui->lineSizeBox->currentText()).toInt(), (ui->elementPriceSpinBox->cleanText()).toInt());
        else
            *elementsContainer+(new schottkyDiode((ui->xSpinBox->cleanText()).toInt(), (ui->ySpinBox->cleanText()).toInt(), (ui->colourBox->currentText()).toStdString(), (ui->elementRadiusSpinBox->cleanText()).toInt(), (ui->lineSizeBox->currentText()).toInt(), (ui->elementPriceSpinBox->cleanText()).toInt()));
    }
    if( QString::compare(ui->addElementBox->currentText(), "Battery", Qt::CaseInsensitive) == 0 || modificateElem.left(1) == "B")
    {
        if(modificateElem.left(1) == "B")
            elementsContainer->Elem_contener[mainWindowElementComboBox->currentIndex()]=new battery((ui->xSpinBox->cleanText()).toInt(), (ui->ySpinBox->cleanText()).toInt(), (ui->colourBox->currentText()).toStdString(), current, (ui->elementPowerPinBox->cleanText()).toInt(), (ui->elementTimePinBox->cleanText()).toInt());
        else
            *elementsContainer+(new battery((ui->xSpinBox->cleanText()).toInt(), (ui->ySpinBox->cleanText()).toInt(), (ui->colourBox->currentText()).toStdString(), current, (ui->elementPowerPinBox->cleanText()).toInt(), (ui->elementTimePinBox->cleanText()).toInt()));
    }
    if((QString::compare(mainWindowElementComboBox->currentText(), "<none>", Qt::CaseInsensitive) == 0) && (ui->nameLineEdit->text().trimmed() != ""))
       mainWindowElementComboBox->clear();

    if(modificateElem == "add")
        {
            mainWindowElementComboBox->addItem(ui->addElementBox->currentText()+": "+ui->nameLineEdit->text());
            QMessageBox::information(this, "Successful!", "Successful! "+ui->addElementBox->currentText()+" element was added!");
        }
    else
        {
            mainWindowElementComboBox->setItemText(mainWindowElementComboBox->currentIndex(),ui->addElementBox->currentText()+": "+ui->nameLineEdit->text());
            QMessageBox::information(this, "Successful!", "Successful! "+modificateElem+" was modificated!");
        }
    }

    else
      QMessageBox::critical(this, "Error!", "Error! Pass the name! Element don't added!");

}

