#ifndef EXECUTION_H
#define EXECUTION_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <vector>
#include <iostream>
#include "proceso.h"
#include "controlador.h"

namespace Ui {
    class Execution;
}

class Execution : public QWidget{
Q_OBJECT
public:
    explicit Execution(std::vector<Proceso*>* procesos,QWidget *parent = 0);
    ~Execution();
    Controlador *controlador;
    QGraphicsScene* panel;
    QGraphicsRectItem* rectangle;
    std::vector<QColor>* colores;
    void inicializarGraficas();
    int contador;
private slots:
    void on_iniciar_procesos_clicked();

private:
    std::vector<Proceso*>* procesos;
    std::vector<Proceso*>* procesos_pendientes;
    std::vector<Proceso*>* procesos_terminados;
    Ui::Execution *ui;
    void init_tablas();
    void llena_tablas();
};

#endif // EXECUTION_H
