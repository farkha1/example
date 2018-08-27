#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>
#include<QLineEdit >
#include<QLCDNumber>
#include<QSlider>

int main(int argc, char *argv[])
{

    // Section Constructeur

    QApplication a(argc, argv);

    MainWindow w;
    QWidget f(&w);
     w.setWindowTitle("Inteface Utilisateur");
       f.setFixedSize(500, 500);
 QFont maPolice("Courier",16, QFont::Bold,true);


 // Section Nom & Prénom

     QLabel l1("Nom",&f), l2("Prénom",&f);
     l1.move(30,30);l2.move(30,60);
     l1.setFont(maPolice);l2.setFont(maPolice);


    QLineEdit  e1(&f), e2(&f);
    e1.move(150,30);e2.move(150,60);

    // Section Genre

     QRadioButton rb("Homme" ,&f);
    // rb.show();
    rb.move(30, 110);
    rb.setFont(maPolice);


    QRadioButton rb1("Femme" ,&f);
   // rb.show();
   rb1.move(250, 110);
   rb1.setFont(maPolice);

//   Section Age

    QLabel l3("Age",&f);
    l3.move(30,140);
    l3.setFont(maPolice);


  QLCDNumber  m (&f);
        m.setSegmentStyle(QLCDNumber::Flat);
        m.move(90, 140);
        QSlider s(Qt::Horizontal, &f);
        s.move(250, 140);

        //Buttons

   QPushButton Q("Quitter", &f);
    Q.move(50, 250);
    Q.setToolTip("quitter");
    Q.setFont(maPolice);
   Q.setCursor(Qt::PointingHandCursor);


    QPushButton bouton("Confirmer",&f);
    bouton.setToolTip("ajouter un utilisateur");
    bouton.setFont(maPolice);
    bouton.setCursor(Qt::PointingHandCursor);
    //QIcon icon(QCoreApplication::applicationDirPath() + "/jpeg.jpg");
      //bouton.setIcon(icon);
    bouton.move(200,250);



    // Section Affichage

        w.show();

        //Signal & Slot

      QObject::connect(&Q, SIGNAL(clicked()), &a, SLOT(quit()));
      QObject::connect(&s, SIGNAL(valueChanged(int)),&m, SLOT(display(int))) ;

       //  QObject::connect(&bouton, SIGNAL(clicked()), &a, SLOT( QDialog()));




    return a.exec();
}
