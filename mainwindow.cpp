#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

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

MainWindow::MainWindow()
{
    ////////////
 QFont maPolice("Courier",16, QFont::Bold,true);
 setWindowTitle("Inteface Utilisateur");
 // Section Nom & Prénom
        (*l1).setFont(maPolice);
        (*l2).setFont(maPolice);
e1->setValidator(new QRegExpValidator( QRegExp("[A-Za-z]*")  ));
e2->setValidator(new QRegExpValidator( QRegExp("[A-Za-z]*")  ));
        layout->addRow(l1, e1);
        layout->addRow(l2, e2);
   // Section Genre
       (*rb).setFont(maPolice);
       (*rb1).setFont(maPolice);
       (*rb).setChecked(true);
       (*lh).addWidget(rb);
       (*lh).addWidget(rb1);
          layout->addRow(lh);
  //   Section Age
          (*l3).setFont(maPolice);
              (*m).setSegmentStyle(QLCDNumber::Flat);
              (*lh1).addWidget(m);
              (*lh1).addWidget(s);
              layout->addRow(l3,lh1);
//Buttons
             (*Q).setToolTip("quitter");
              (*Q).setFont(maPolice);
              (*Q).setCursor(Qt::PointingHandCursor);
              (*bouton).setToolTip("ajouter un utilisateur");
              (*bouton).setFont(maPolice);
              (*bouton).setCursor(Qt::PointingHandCursor);
               layout->addRow(Q,bouton);

 //Affichage
                       (*f).setLayout(layout);
                 this->setCentralWidget(f);
//Signal & Slot

                //quitter app
                   QObject::connect(Q, SIGNAL(clicked()), qApp, SLOT(quit()));
                //ajouter user
                     QObject::connect(bouton, SIGNAL(clicked()),this, SLOT(VerifFonc()));
                //set age
                 QObject::connect(s, SIGNAL(valueChanged(int)),m, SLOT(display(int))) ;
    /////////////
}
/*MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}*/
/*
MainWindow::~MainWindow()
{
    delete ui;
}
*/
void MainWindow::VerifFonc()
{

    if (e1->text().isEmpty())
    {
        QMessageBox::critical(this, "Erreur", "Veuillez entrer votre nom");
        return;
    }
  else  if (e2->text().isEmpty())
    {
        QMessageBox::critical(this, "Erreur", "Veuillez entrer votre prénom");
        return; // Arrêt de la méthode
    }
    else  if (m->intValue()==0)
      {
          QMessageBox::critical(this, "Erreur", "Veuillez entrer votre age");
          return; // Arrêt de la méthode
      }
    else  if (m->intValue()<18)
      {
          QMessageBox::critical(this, "Erreur", "Vous avez moins de 18 ans, vous ne pouvez pas vous inscrire");
          return; // Arrêt de la méthode
      }
    InfoBulle(e2->text());
    // Si tout va bien, on génère le code
    QString code;

    // Génération du code à l'aide des informations de la fenêtre
    // …

    // On crée puis affiche la fenêtre qui affichera le code généré, qu'on lui envoie en paramètre
   // FenCodeGenere *fenetreCode = new FenCodeGenere(code, this);
   // fenetreCode->exec();
}
void MainWindow::InfoBulle()
{
int response=  QMessageBox::information(this, "Bienvenue","Utilisateur Ajouté !");
  if (response )
    {
    response = QMessageBox::question(this, "Important", "Est-ce que vous acceptez que nous concervons vos données personnelles ?", QMessageBox ::Yes | QMessageBox::No);


           if (response == QMessageBox::Yes)
            {
                QMessageBox::information(this, "Merci", "Votre demande a bien été enregistrée !");
            }
            else if  (response == QMessageBox::No)
            {
                QMessageBox::information(this, "Merci", "Votre demande a bien été enregistrée !");
            }
           else
           {
               QMessageBox::warning(this, "Important", "Nous n'avons pas pu enregistrer votre demande !");
           }

     }
}

void MainWindow::InfoBulle(QString s)
{
int response=  QMessageBox::information(this, "Bienvenue,"+s,"Utilisateur Ajouté !");
  if (response )
    {
    response = QMessageBox::question(this, "Important", "Est-ce que vous acceptez que nous concervons vos données personnelles ?", QMessageBox ::Yes | QMessageBox::No);


           if (response == QMessageBox::Yes)
            {
                QMessageBox::information(this, "Merci", "Votre demande a bien été enregistrée !");
            }
            else if  (response == QMessageBox::No)
            {
                QMessageBox::information(this, "Merci", "Votre demande a bien été enregistrée !");
            }
           else
           {
               QMessageBox::warning(this, "Important", "Nous n'avons pas pu enregistrer votre demande !");
           }

     }
}



