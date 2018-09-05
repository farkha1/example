#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>
#include<QLineEdit >
#include<QLCDNumber>
#include<QSlider>
#include<QMessageBox>
#include<QLibraryInfo>
#include<QTranslator>
#include<QGroupBox>
#include<QVBoxLayout>
#include<QFormLayout>



int main(int argc, char *argv[])
{

    // Section Constructeur

    QApplication a(argc, argv);
    QString locale = QLocale::system().name().section('_', 0, 0);
       QTranslator translator;
       translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
       a.installTranslator(&translator);

    MainWindow *w=new MainWindow();

    // Section Affichage

       (*w).show();


    //Signal & Slot

   // QObject:: connect(&e1, SIGNAL(textEdited(QString)), &e2, SLOT(setText(this.parent())));
      //QObject:: connect(&e1, SIGNAL(textEdited(QString)), &e2, SLOT(setText(QString)));
     // QObject:: connect(&e2, SIGNAL(textEdited(QString)),&w, SLOT(InfoBulle()));

    //  QObject::connect(&rb1, SIGNAL(toggled(bool)), &w, SLOT(InfoBulle()));

    return a.exec();
}






















/*

int main(int argc, char *argv[])
{

    // Section Constructeur

    QApplication a(argc, argv);
    QString locale = QLocale::system().name().section('_', 0, 0);
       QTranslator translator;
       translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
       a.installTranslator(&translator);



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

     QRadioButton rb("Homme",&f );
    // rb.show();
    rb.move(30, 110);
    rb.setFont(maPolice);


    QRadioButton rb1("Femme" ,&f);
   // rb.show();
   rb1.move(250, 110);
   rb1.setFont(maPolice);

   rb.setChecked(true);




//   Section Age

    QLabel l3("Age",&f);
    l3.move(30,140);
    l3.setFont(maPolice);


  QLCDNumber  m (&f);
        m.setSegmentStyle(QLCDNumber::Flat);
        m.move(90, 140);
        QSlider s(Qt::Horizontal, &f);
        s.move(250, 140);
//QString::number(m.intValue())


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

        //quitter app
      QObject::connect(&Q, SIGNAL(clicked()), &a, SLOT(quit()));
        //ajouter user
      QObject::connect(&bouton, SIGNAL(clicked()), &w, SLOT(InfoBulle()));
        //set age
      QObject::connect(&s, SIGNAL(valueChanged(int)),&m, SLOT(display(int))) ;


    QObject:: connect(&e1, SIGNAL(textEdited(QString)), &e2, SLOT(setText(this.parent() )));
      //QObject:: connect(&e1, SIGNAL(textEdited(QString)), &e2, SLOT(setText(QString)));
     // QObject:: connect(&e2, SIGNAL(textEdited(QString)),&w, SLOT(InfoBulle()));

    //  QObject::connect(&rb1, SIGNAL(toggled(bool)), &w, SLOT(InfoBulle()));


    return a.exec();
}
*/
