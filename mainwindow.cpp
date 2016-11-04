#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <ctime>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    procesos = new std::vector<Proceso*>();
    QStringList encabezados;
    encabezados << "Nombre"<<"T. Inicio"<<"T. Duración";
    this->tiempo=0;
    ui->tabla->setColumnCount(3);
    ui->tabla->setHorizontalHeaderLabels(encabezados);
    ui->tabla->setColumnWidth(0,150);
    ui->tabla->horizontalHeader()->setStretchLastSection(true);
    ui->boton_inicio->setEnabled(false);
    srand (time(nullptr));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_boton_agregar_clicked(){
    if(ui->inicio->value()>=0 && ui->duracion->value()>=0){
        ui->tabla->insertRow(ui->tabla->rowCount());
        procesos->push_back(new Proceso(procesos->size(),ui->nombre->text().toStdString(),ui->inicio->value(),ui->duracion->value()));
        int row = ui->tabla->rowCount()-1;
        ui->tabla->setItem(row,0,new QTableWidgetItem(ui->nombre->text()));
        ui->tabla->setItem(row,1,new QTableWidgetItem(QString::number(ui->inicio->value())));
        ui->tabla->setItem(row,2,new QTableWidgetItem(QString::number(ui->duracion->value())));
        ui->boton_inicio->setEnabled(true);
    }else{
        qDebug() << "Algo no está bien";
    }
}

void MainWindow::on_boton_limpiar_clicked(){
    ui->nombre->setText("");
    ui->inicio->setValue(0);
    ui->duracion->setValue(0);
}

void MainWindow::on_boton_generar_clicked(){
    int inicio = rand() % 50 + 1;
    int duracion = rand() % 50 + 1;
    QString nombre = "P"+QString::number(procesos->size()+1);
    ui->tabla->insertRow(ui->tabla->rowCount());
    procesos->push_back(new Proceso(procesos->size(),nombre.toStdString(),inicio,duracion));
    int row = ui->tabla->rowCount()-1;
    ui->tabla->setItem(row,0,new QTableWidgetItem(nombre));
    ui->tabla->setItem(row,1,new QTableWidgetItem(QString::number(inicio)));
    ui->tabla->setItem(row,2,new QTableWidgetItem(QString::number(duracion)));
    ui->boton_inicio->setEnabled(true);
}

void MainWindow::on_boton_borrar_clicked(){
    if(procesos->size()>0){
        ui->tabla->removeRow(ui->tabla->rowCount());
        ui->tabla->setRowCount(ui->tabla->rowCount()-1);
        procesos->pop_back();
    }
    if(procesos->size()<=0) ui->boton_inicio->setEnabled(false);
}

void MainWindow::on_boton_inicio_clicked(){
    ventana_ejecucion = new Execution(procesos);
    ventana_ejecucion->show();
    QString a = ui->nombre->text();
}

void MainWindow::on_generar_n_clicked(){
    for(int i=0,j=ui->spin_generar->value();i<j;i++){
        int inicio = rand() % 50 + 1;
        int duracion = rand() % 50 + 1;
        QString nombre = "P"+QString::number(procesos->size()+1);
        ui->tabla->insertRow(ui->tabla->rowCount());
        procesos->push_back(new Proceso(procesos->size(),nombre.toStdString(),inicio,duracion));
        int row = ui->tabla->rowCount()-1;
        ui->tabla->setItem(row,0,new QTableWidgetItem(nombre));
        ui->tabla->setItem(row,1,new QTableWidgetItem(QString::number(inicio)));
        ui->tabla->setItem(row,2,new QTableWidgetItem(QString::number(duracion)));
    }
    ui->boton_inicio->setEnabled((procesos->size()<=0?false:true));
}
