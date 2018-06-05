#ifndef ADDELEMENT_H
#define ADDELEMENT_H
#include <QDialog>
#include <QComboBox>
#include <QString>
#include "elements/document.h"
namespace Ui {
class addElement;
}

class addElement : public QDialog
{
    Q_OBJECT
    document *elementsContainer;
    QComboBox *mainWindowElementComboBox;
    QString modificateElem; //the name of modificate element
public:
    explicit addElement(QWidget *parent = 0, document *a = 0, QComboBox *b = 0, QString c = "add");
    ~addElement();
    void addElementBoxIndexChanged();


private slots:
    void on_okPushButton_clicked();

private:
    Ui::addElement *ui;
};


#endif // ADDELEMENT_H
