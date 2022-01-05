#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <string>
#include <iostream>
#include <QTextStream>
#include <QFile>
#include <QDebug>
using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i=0;i<9;i++){  //initialisation de la matrice à 0
        for (int j=0;j<9;j++){
            matrice[i][j]=0;
            matriceEtats[i][j] = "stop";
        }
    }
    int x0;
    int y0;
    for (int i=0; i<9;i++){
        for (int j=0; j<9;j++){
            x0=(i/3)*3;
            y0=(j/3)*3;
            if (((x0==0)&&(y0==0)) || ((x0==0)&&(y0==6)) || ((x0==3)&&(y0==3)) || ((x0==6)&&(y0==0)) || ((x0==6)&&(y0==6))){
                matriceCouleur[i][j] = "lightblue";
            }
            else {
                matriceCouleur[i][j] = "white";
            }
            QTableWidgetItem* Cell = ui->tableWidget->item(i, j);
            Cell->setBackground(QColor(matriceCouleur[i][j]));
        }
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton1_clicked()
{
    chiffre_souhaite="1";
    chiffre_souhaite_numerique=1;
    on_tableWidget_cellClicked(Row, Column);
}

void MainWindow::on_pushButton2_clicked()
{
    chiffre_souhaite="2";
    chiffre_souhaite_numerique=2;
    on_tableWidget_cellClicked(Row, Column);
}

void MainWindow::on_pushButton3_clicked()
{
    chiffre_souhaite="3";
    chiffre_souhaite_numerique=3;
    on_tableWidget_cellClicked(Row, Column);
}

void MainWindow::on_pushButton4_clicked()
{
    chiffre_souhaite="4";
    chiffre_souhaite_numerique=4;
    on_tableWidget_cellClicked(Row, Column);
}

void MainWindow::on_pushButton5_clicked()
{
    chiffre_souhaite="5";
    chiffre_souhaite_numerique=5;
    on_tableWidget_cellClicked(Row, Column);
}

void MainWindow::on_pushButton6_clicked()
{
    chiffre_souhaite="6";
    chiffre_souhaite_numerique=6;
    on_tableWidget_cellClicked(Row, Column);
}

void MainWindow::on_pushButton7_clicked()
{
    chiffre_souhaite="7";
    chiffre_souhaite_numerique=7;
    on_tableWidget_cellClicked(Row, Column);
}

void MainWindow::on_pushButton8_clicked()
{
    chiffre_souhaite="8";
    chiffre_souhaite_numerique=8;
    on_tableWidget_cellClicked(Row, Column);
}

void MainWindow::on_pushButton9_clicked()
{
    chiffre_souhaite="9";
    chiffre_souhaite_numerique=9;
    on_tableWidget_cellClicked(Row, Column);
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    if (matriceEtats[row][column] == "stop"){
        return;
    }
    cases_a_ne_plus_considerer();
    Row = row;
    Column = column;
    if (matriceEtats[row][column] == ""){
        cases_a_considerer(row, column);
        if (chiffre_souhaite_numerique != 10 ){
            chiffre_valable(row,column,chiffre_souhaite_numerique); //le chiffre peut être placé dans la case
            QTableWidgetItem* Cell = ui->tableWidget->item(row, column);
            Cell->setText(chiffre_souhaite);
            //solution pour placement interdit, dans chiffre_valable on vérifie la matrice, donc faut remplacer
            // l'élément correspondant,
            matrice[row][column] = chiffre_souhaite_numerique;
            chiffre_souhaite_numerique = 10;
        }
    }
    chiffre_souhaite_numerique=10;

}

void MainWindow::cases_a_ne_plus_considerer()
{
    for (int i=0;i<9;i++){
        QTableWidgetItem* CellColumn = ui->tableWidget->item(i, Column);
        QTableWidgetItem* CellRow = ui->tableWidget->item(Row, i);
        CellColumn->setBackground(QColor(matriceCouleur[i][Column]));
        CellRow->setBackground(QColor(matriceCouleur[Row][i]));
    }
    int x0=(Column/3)*3;
    int y0=(Row/3)*3;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            QTableWidgetItem* Cell = ui->tableWidget->item(y0+i,x0+j);
            Cell ->setBackground(QColor(matriceCouleur[y0+i][x0+j]));
        }

        }
}

void MainWindow::cases_a_considerer(int row, int column)
{
    for (int i=0;i<9;i++){
        QTableWidgetItem* CellColumn = ui->tableWidget->item(i, column);
        CellColumn->setBackground(QColor("lightgray"));
        QTableWidgetItem* CellRow = ui->tableWidget->item(row, i);
        CellRow->setBackground(QColor("lightgray"));
    }
    int x0=(column/3)*3;
    int y0=(row/3)*3;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            QTableWidgetItem* Cell = ui->tableWidget->item(y0+i,x0+j);
            Cell ->setBackground(QColor("lightgray"));
        }

        }
}


void MainWindow::chiffre_valable(int row, int column, int chiffre)
{
    int a=0;
    for (int i=0;i<9;i++){  //le chiffre est-il déjà dans la colonne?
        if (matrice[i][column] == chiffre){
            a=a+1;
            }
        }

    for (int j=0;j<9;j++){  //le chiffre est-il déjà dans la ligne?
            if (matrice[row][j] == chiffre){
                a=a+1;
            }
        }
    int x0=(column/3)*3;
    int y0=(row/3)*3;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (matrice[y0+i][x0+j] == chiffre){
                a=a+1;
            }
        }
    }
    if (a==0){
        QString etat = "vrai";
        matriceEtats[row][column] = etat;
    }
    else {
        QString etat = "faux";
        matriceEtats[row][column] = etat;

    }

}


void MainWindow::on_valider_clicked() {
    bool gagnant=true;
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            if (matriceEtats[i][j] == "faux" || matriceEtats[i][j] == ""){
                QTableWidgetItem* Cell = ui->tableWidget->item(i,j);
                Cell ->setForeground(QColor("red"));
                gagnant = false;
            }
        }
    }
    if (gagnant){
        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                matrice[i][j] = 10;
                QTableWidgetItem* Cell = ui->tableWidget->item(i, j);
                Cell->setText("");
                Cell->setBackground(QColor("green"));
                matriceEtats[i][j] = "stop";

            }
        }
        cout<<"VOUS AVEZ GAGNÉ"<<endl;

    }
    else {
        cout<<"VOUS N'AVEZ PAS GAGNÉ"<<endl;
    }
}

void MainWindow::on_reset_clicked()
{
    //Reinitialisation de la grille à "zéro"
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            matrice[i][j] = 10;
            QTableWidgetItem* Cell = ui->tableWidget->item(i, j);
            Cell->setText("");
            matriceEtats[i][j] = "";
            Cell->setBackground(QColor(matriceCouleur[i][j]));
        }
    }
    Q_INIT_RESOURCE(grilles);
    QFile fichier(":/new/prefix2/" + nomFichier);   // on définit le nom du fichier sous 'fichier'

    if (!fichier.exists())
        cout<<"ERREUR1: Le fichier n'existe pas"<<endl;

    if (!fichier.open(QIODevice::ReadOnly | QIODevice::Text)){
        cout<<"ERREUR2: Ouverture du fichier impossible"<<endl;
        return;
    }

    QTextStream in(&fichier);
    int ligneIndice = 0;
    while (!in.atEnd()) {
        QString ligneText = in.readLine();   // on lit ligne par ligne
        if (ligneText[0] == '#'){        //on ne veut pas traiter la description qui commence par '#'
            continue;
        }
        traitement_ligne(ligneText, ligneIndice);    //appel à une fonction pour afficher la grille
        ligneIndice++;
    }
    fichier.close();        //important de fermer le fichier
}

void MainWindow::traitement_ligne(QString ligneTexte, int ligneIndice) {
    int k = 0;                      //indice de la colonne à traiter
    for (int i = 0; i<17;i++){
        if (ligneTexte[i] == "."){        //On oublie les points
            continue;
        }
        if (ligneTexte[i] == "|"){        //idem pour les traits verticales
            k++;                    //un trait signifie qu'on passe à la colonne prochaine
            continue;
        }
        matrice[ligneIndice][i-k] = ligneTexte[i].digitValue();       // i-k parce que les traits verticales ont été comptés avec i
        QString chiffreSouhaite = QChar(ligneTexte[i]);           //line[i] est de type QChar, setText prend en entrée le type string/Qstring, faut convertir
        QTableWidgetItem* Cell = ui->tableWidget->item(ligneIndice, i-k);
        Cell->setText(chiffreSouhaite);
        matriceEtats[ligneIndice][i-k] = "fix";
    }
}

int MainWindow::nulle(int row, int column)  //voir si la case est vide
{
    int a=0;
    for (int i=1;i<10;i++){
        if (matrice[row][column] == i){
            a=a+1;
        }
    }
    if (a==0){  //la case est vide
        return 0;
    }
    else {
        return 1;
    }

}


void MainWindow::on_Delete_clicked()  //supprimer un chiffre
{
    //attention il ne faudra pas modifier les chiffres de la grille initiale
    if (matriceEtats[Row][Column] != "fix"){   //la case est non nulle
        matrice[Row][Column] = 10;
        QTableWidgetItem* Cell = ui->tableWidget->item(Row, Column);
        Cell->setText("");
        Cell->setBackground(QColor(matriceCouleur[Row][Column]));
        Cell->setForeground(QColor("black"));

        matriceEtats[Row][Column] = "";
    }

}

void MainWindow::on_actionGrille_D_butant_triggered()
{
    nomFichier = "grilleDebutant.csv";
    on_reset_clicked();
}

void MainWindow::on_actionGrille_Facile_triggered()
{
    nomFichier = "grilleFacile.csv";
    on_reset_clicked();
}

void MainWindow::on_actionGrille_Interm_diaire_triggered()
{
    nomFichier = "grilleIntermediaire.csv";
    on_reset_clicked();
}

void MainWindow::on_actionGrille_Expert_triggered()
{
    nomFichier = "grilleExpert.csv";
    on_reset_clicked();
}


