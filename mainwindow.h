#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
 //   explicit MainWindow(QWidget *parent = nullptr);
 //   ~MainWindow();
public slots:
 void InfoBulle();
 void InfoBulle(QString);
 void VerifFonc();
private:
  //  Ui::MainWindow *ui;
 QWidget *f= new QWidget();
  QFormLayout *layout = new QFormLayout;

  QLabel    *l1=new QLabel("Nom"), *l2=new QLabel("Prénom");
  QLineEdit  *e1=new  QLineEdit(), *e2=new  QLineEdit();

QRadioButton *rb =new  QRadioButton("Homme" ),*rb1 =new  QRadioButton("Femme");
 QHBoxLayout *lh = new  QHBoxLayout;

 QLabel *l3= new    QLabel("Age");
  QLCDNumber  *m =new  QLCDNumber();
 QSlider *s=new   QSlider(Qt::Horizontal);
 QHBoxLayout *lh1 = new  QHBoxLayout;

 QPushButton *Q= new QPushButton("Quitter" ), *bouton= new QPushButton("Confirmer" );





};

#endif // MAINWINDOW_H
