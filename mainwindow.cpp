#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addelement.h"
#include <QMessageBox>
#include <QTextStream>
#include <QString>
#include <QFileDialog>
#include <QDebug>
#include <fstream>
#include <QGraphicsScene>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect( ui->elementsComboBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &MainWindow::elementBoxComboIndexChanged );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintMainSvg()
{
    //ofstream file("/Users/admin/Desktop/build-PROJECT_3-Desktop_Qt_5_6_0_clang_64bit-Release/temp.svg");
    //if(file.is_open())
    //elementsContainer.svgSave(file, 600, 600);
    //scene->addPixmap(QPixmap("/Users/admin/Desktop/build-PROJECT_3-Desktop_Qt_5_6_0_clang_64bit-Release/temp.svg"));
    //ui->mainSVG->show();
}

void MainWindow::paintElemSvg(int i)
{

}

void MainWindow::elementBoxComboIndexChanged()
{

    if( QString::compare((ui->elementsComboBox->currentText()).left(1), "P", Qt::CaseInsensitive) == 0 || QString::compare((ui->elementsComboBox->currentText()).left(1), "S", Qt::CaseInsensitive) == 0)
    {
        ui->currentLabel->setText("Line size:");
        ui->powerLabel->setText("Radius:");
        ui->timeLabel->setText("");
    }
    if( QString::compare((ui->elementsComboBox->currentText()).left(1), "V", Qt::CaseInsensitive) == 0 || QString::compare((ui->elementsComboBox->currentText()).left(1), "B", Qt::CaseInsensitive) == 0)
    {
        ui->currentLabel->setText("Current:");
        ui->powerLabel->setText("Power:");
        ui->timeLabel->setText("");
    }
    if( QString::compare((ui->elementsComboBox->currentText()).left(1), "S", Qt::CaseInsensitive) == 0)
    {
        ui->timeLabel->setText("Price:");
    }
    if( QString::compare((ui->elementsComboBox->currentText()).left(1), "B", Qt::CaseInsensitive) == 0)
    {
        ui->timeLabel->setText("Time to charge:");
    }

    if(ui->elementsComboBox->currentIndex() >= 0)
    {
        ui->characteristicLabel->setText(QString::fromStdString(elementsContainer.getElemeInfo(ui->elementsComboBox->currentIndex())));
        ui->characteristicLabel->repaint();
    }
}

void MainWindow::on_action_QT_triggered()
{
    QMessageBox::aboutQt(this, "About QT");
}

void MainWindow::on_actionAuthor_triggered()
{
    QMessageBox::information(this, "Elements", "Elements\nVersion 1.0\n\nAndrei Dailida\ndailidaandrei@gmail.com\nJune 2016");
}

void MainWindow::on_pushButton_add_clicked()
{
    addElement addelem(this, &elementsContainer, ui->elementsComboBox, "add");
    addelem.setModal(true);
    addelem.exec();
}

void MainWindow::on_pushButton_mofificate_clicked()
{
    if(elementsContainer.contSize()==0)
        QMessageBox::critical(this, "Error!", "Error! You have no elements yet!");
    else
    {
        addElement addelem(this, &elementsContainer, ui->elementsComboBox, ui->elementsComboBox->currentText());
        addelem.setModal(true);
        addelem.exec();
        elementBoxComboIndexChanged();
    }
}

void MainWindow::on_pushButton_delite_clicked()
{
     if(elementsContainer.contSize()==0)
         QMessageBox::critical(this, "Error!", "Error! You have no elements yet!");
     else
     {
        elementsContainer - (ui->elementsComboBox->currentIndex()+1);
        ui->elementsComboBox->removeItem(ui->elementsComboBox->currentIndex());
        if(elementsContainer.contSize()==0)
        {
            ui->elementsComboBox->addItem("<none>");
            ui->characteristicLabel->setText("");
            ui->characteristicLabel->repaint();
        }
     }
}


void MainWindow::on_actionClear_triggered()
{
    elementsContainer - (0);
    ui->elementsComboBox->clear();
    ui->elementsComboBox->addItem("<none>");
    ui->characteristicLabel->setText("");
    ui->characteristicLabel->repaint();
}

void MainWindow::on_action_Save_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), "/", tr("Text File (*.txt);; SVG (*.svg)"));
    ofstream file(fileName.toStdString());
    if(!file.is_open()) QMessageBox::critical(this, "Error!", "Error! Can't open this file!");
    else
    {
    if(fileName[fileName.length()-1]=='t')
    elementsContainer.txtSave(file, ui->elementsComboBox);
    if(fileName[fileName.length()-1]=='g')
    elementsContainer.svgSave(file, 2000, 2000);
    file.close();
    }
}

void MainWindow::on_action_Open_triggered()
{
     QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "/", "Text File (*.txt)");
     ifstream file(fileName.toStdString());
     if(!file.is_open()) QMessageBox::critical(this, "Error!", "Error! Can't open this file!");
     else
     elementsContainer.txtRead(file, ui->elementsComboBox);
}
