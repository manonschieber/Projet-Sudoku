#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QTableWidget>
#include "include.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_pushButton1_clicked();
    void on_pushButton2_clicked();
    void on_pushButton3_clicked();
    void on_pushButton4_clicked();
    void on_pushButton5_clicked();
    void on_pushButton6_clicked();
    void on_pushButton7_clicked();
    void on_pushButton8_clicked();
    void on_pushButton9_clicked();

    void chiffre_valable(int row, int column, int chiffre);

    void on_tableWidget_cellClicked(int row, int column);

    void on_reset_clicked();

    void on_valider_clicked();

    void traitement_ligne(QString ligneTexte, int ligneIndice);

    void cases_a_considerer(int row, int column);

    void cases_a_ne_plus_considerer();

    void on_Delete_clicked();

    int nulle(int row, int column) ;


    void on_actionGrille_D_butant_triggered();
    void on_actionGrille_Facile_triggered();
    void on_actionGrille_Interm_diaire_triggered();
    void on_actionGrille_Expert_triggered();



private:
    Ui::MainWindow *ui;
    int Column=0, Row=0;
    void click__on_pb(int num);
    QString chiffre_souhaite;
    int chiffre_souhaite_numerique = 10;
    int matrice [9][9];
    QString matriceCouleur[9][9];
    QString nomFichier;
    QString matriceEtats[9][9];
};
#endif // MAINWINDOW_H
