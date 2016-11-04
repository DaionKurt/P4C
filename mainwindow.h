#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "execution.h"

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
    void on_boton_agregar_clicked();
    void on_boton_inicio_clicked();
    void on_boton_limpiar_clicked();
    void on_boton_generar_clicked();
    void on_boton_borrar_clicked();

    void on_generar_n_clicked();

private:
    std::vector<Proceso*>* procesos;
    Ui::MainWindow *ui;
    Execution* ventana_ejecucion;
    int tiempo;
};

#endif // MAINWINDOW_H
