#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "elements/document.h"
#include <QMainWindow>
#include <QGraphicsScene>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    document elementsContainer;
public:
    explicit MainWindow(QWidget *parent = 0);
    void elementBoxComboIndexChanged();
    ~MainWindow();
private slots:
    void on_action_QT_triggered();

    void on_actionAuthor_triggered();

    void on_pushButton_add_clicked();

    void on_pushButton_delite_clicked();

    void on_actionClear_triggered();

    void on_action_Save_triggered();

    void on_action_Open_triggered();

    void on_pushButton_mofificate_clicked();

private:
    void paintMainSvg();
    void paintElemSvg(int i);
    QGraphicsScene *scene;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
