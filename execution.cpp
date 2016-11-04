#include "execution.h"
#include "ui_execution.h"
#include "controlador.h"
#include <QDebug>

#define TAMANIO_TOTAL 1000
#define LIMITE_INF -500
#define LIMITE_SUP 500
#define PROFUNDIDAD 500

Execution::Execution(std::vector<Proceso*>* procesos,QWidget *parent) :QWidget(parent),ui(new Ui::Execution){
    this->procesos=procesos;
    this->procesos_pendientes = new std::vector<Proceso*>();;
    this->procesos_terminados = new std::vector<Proceso*>();
    ui->setupUi(this);
    init_tablas();
    llena_tablas();
    ui->lcd->setAutoFillBackground(true);
    ui->lcd->setStyleSheet("background-color:white ;color: red");
    panel = new QGraphicsScene(this);
    ui->panel_grafico->setScene(panel);
    colores = new std::vector<QColor>();
    contador=0;
}
void Execution::init_tablas(){
    QStringList encabezado_lista,encabezado_pendientes,encabezado_terminados;
    encabezado_lista <<"Nombre"<<"T. inicio"<<"T. duración";
    encabezado_pendientes <<"Nombre"<<"TI"<<"TD"<<"TR"<<"TT";
    encabezado_terminados <<"Nombre"<<"T. Fin";
    ui->tabla_lista->setColumnCount(3);
    ui->tabla_lista->setHorizontalHeaderLabels(encabezado_lista);
    ui->tabla_lista->setColumnWidth(1,50);
    ui->tabla_lista->setColumnWidth(2,50);
    ui->tabla_lista->horizontalHeader()->setStretchLastSection(true);
    ui->tabla_pendientes->setColumnCount(5);
    ui->tabla_pendientes->setHorizontalHeaderLabels(encabezado_pendientes);
    ui->tabla_pendientes->setColumnWidth(1,50);
    ui->tabla_pendientes->setColumnWidth(2,50);
    ui->tabla_pendientes->setColumnWidth(3,50);
    ui->tabla_pendientes->setColumnWidth(4,50);
    ui->tabla_pendientes->horizontalHeader()->setStretchLastSection(true);
    ui->tabla_terminados->setColumnCount(2);
    ui->tabla_terminados->setHorizontalHeaderLabels(encabezado_terminados);
    ui->tabla_terminados->horizontalHeader()->setStretchLastSection(true);
}
void Execution::llena_tablas(){
    for(int i=0,j=procesos->size();i<j;i++){
        ui->tabla_lista->insertRow(ui->tabla_lista->rowCount());
        int row = ui->tabla_lista->rowCount()-1;
        ui->tabla_lista->setItem(row,0,new QTableWidgetItem(QString::fromStdString(procesos->at(i)->get_nombre())));
        ui->tabla_lista->setItem(row,1,new QTableWidgetItem(QString::number(procesos->at(i)->get_inicio())));
        ui->tabla_lista->setItem(row,2,new QTableWidgetItem(QString::number(procesos->at(i)->get_duracion())));
    }
}
Execution::~Execution(){
    delete ui;
}
bool sort(Proceso* e,Proceso* ex){
    return e->get_inicio()<ex->get_inicio();
}

void Execution::inicializarGraficas(){
       int division=PROFUNDIDAD/procesos->size();
       qreal anchuraLinea=division/2;
       QBrush blueBrush(Qt::white);
       int  x=-316;

       QGraphicsTextItem *text;
       qreal p=LIMITE_INF-80;
       qreal size=80;
       int sizeFont=9;
       qreal q;
       for(int i=0,j=procesos->size();i<j;i++){
           q=x+(anchuraLinea/2);
           colores->push_back(QColor(rand()%256,rand()%256,rand()%256));
           qDebug() << colores->size();
           if(procesos->size()>40){
                         sizeFont=7;
                         division=15;
                         anchuraLinea=8;
                     }
          rectangle=new QGraphicsRectItem(LIMITE_INF,x,500,anchuraLinea);
          rectangle->setBrush(blueBrush);
          rectangle->setPen(Qt::NoPen);
          text=panel->addText(QString::fromStdString(procesos->at(i)->get_nombre()),QFont("Arial",sizeFont));
          text->setPos(p,q);
          text->setTextWidth(size);
          panel->addItem(rectangle);
          x+=division;
       }
}
void Execution::on_iniciar_procesos_clicked(){
    if(procesos->size()>0){
        ui->iniciar_procesos->setEnabled(false);
        controlador = new Controlador();
        int *counter=&contador;
        controlador->inicializar(counter,ui->lcd,ui->tabla_pendientes,ui->tabla_terminados,procesos
                                 ,procesos_pendientes,procesos_terminados,panel,colores);
        controlador->init();
        //std::sort(procesos->begin(),procesos->end(),sort);
        inicializarGraficas();
    }
}
