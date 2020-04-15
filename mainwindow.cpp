#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFont>
#include <QPushButton>
#include <QSlider>
#include <QString>
#include <QTimer>
#include <QFile>
#include <QTextStream>
#include <QTableWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QToolBar>
#include <QSettings>
#include <QSessionManager>
#include <QDesktopWidget>

#include "chart.h"
#include "chart/datacontainers.h"
//#include "ppch440_72.h"

#include <iostream>
#include <fstream>
#include <list>
#include <vector>

//using namespace std;

typedef vector<int> vint;
typedef list <int>  lint;
typedef list <double> ldouble;

vint  times;
lint  ch0_data;
lint  ch1_data;
lint  ch2_data;
lint  ch3_data;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initialize ();
    connections();
    loadCharts();
}

void MainWindow::initialize()
{
    //http://www.cyberforum.ru/qt/thread238089.html
int row,column;
QLayout * layout1 = new QVBoxLayout();
QWidget * widget = ui->centralwidget;
layout1->addWidget(ui->tabWidget);
widget->setLayout(layout1);

widget = ui->tabWidget->widget(0);//Параметры на время Стоп
QLayout * layout2 = new QVBoxLayout();
layout2->addWidget(ui->table_pars_stop);
widget->setLayout(layout2);

for(row=1;row < ui->table_pars_stop->rowCount();row++)
  for(column=0;column < ui->table_pars_stop->columnCount();column++){
      QTableWidgetItem *newItem = new QTableWidgetItem("----");
                        newItem->setTextAlignment(2);
                        ui->table_pars_stop->setItem(row, column, newItem);
  }

widget = ui->tabWidget->widget(1);//Параметры на время Пуск
QLayout * layout4 = new QVBoxLayout();
layout4->addWidget(ui->table_pars_pusk);
widget->setLayout(layout4);

for(row=1;row < ui->table_pars_pusk->rowCount();row++)
  for(column=0;column < ui->table_pars_pusk->columnCount();column++){
      QTableWidgetItem *newItem = new QTableWidgetItem("----");
                        newItem->setTextAlignment(2);
                        ui->table_pars_pusk->setItem(row, column, newItem);
  }

widget = ui->tabWidget->widget(2);//Настройки
QLayout * layout5 = new QVBoxLayout();
layout5->addWidget(ui->table_sets);
widget->setLayout(layout5);

for(row=1;row < ui->table_sets->rowCount();row++)
  for(column=0;column < ui->table_sets->columnCount();column++){
      QTableWidgetItem *newItem = new QTableWidgetItem("----");
                        newItem->setTextAlignment(2);
                        ui->table_sets->setItem(row, column, newItem);
  }


widget = ui->tabWidget->widget(3);//Данные рам для осциллограммы
QLayout * layout6 = new QVBoxLayout();
layout6->addWidget(ui->table_ram);
widget->setLayout(layout6);
for(row=1;row < ui->table_ram->rowCount();row++)
  for(column=0;column < ui->table_ram->columnCount();column++){
      QTableWidgetItem *newItem = new QTableWidgetItem("----");
                        newItem->setTextAlignment(2);
                        ui->table_ram->setItem(row, column, newItem);
  }

widget = ui->tabWidget->widget(4);//Осциллограммы
chart = new Chart();
chart->setMouseTracking( true );
QLayout * layout3 = new QVBoxLayout();
layout3->addWidget(chart);
QLayout * wert = new QHBoxLayout();
wert->addWidget(ui->chartPosition);
wert->addWidget(ui->zoomBox);
layout3->addItem(wert);
layout3->addWidget(ui->sizeSlider);
layout3->addWidget(ui->label);
//layout3->addWidget(injCombo);
widget->setLayout(layout3);


widget = ui->tabWidget->widget(5);//Драйверы
QLayout * layout7 = new QVBoxLayout();
layout7->addWidget(ui->table_drv);
widget->setLayout(layout7);

for(row=1;row < ui->table_drv->rowCount();row++)
  for(column=0;column < ui->table_drv->columnCount();column++){
      QTableWidgetItem *newItem = new QTableWidgetItem("----");
                        newItem->setTextAlignment(2);
                        ui->table_drv->setItem(row, column, newItem);
  }


widget = ui->tabWidget->widget(6);//Диагностики
QLayout * layout8 = new QVBoxLayout();
layout8->addWidget(ui->table_diags);
widget->setLayout(layout8);

for(row=0;row < ui->table_diags->rowCount();row++)
  for(column=0;column < ui->table_diags->columnCount();column++){
      QTableWidgetItem *newItem = new QTableWidgetItem("----");
                        newItem->setTextAlignment(2);
                        ui->table_diags->setItem(row, column, newItem);
  }

//ppch440_72= new Ppch440_72();

createActions();
createStatusBar();

readSettings();

//connect(textEdit->document(), &QTextDocument::contentsChanged,
//        this, &MainWindow::documentWasModified);


QGuiApplication::setFallbackSessionManagementEnabled(false);
connect(qApp, &QGuiApplication::commitDataRequest,
        this, &MainWindow::commitData);


setCurrentFile(QString());
//setUnifiedTitleAndToolBarOnMac(true);

}

void MainWindow::connections()
{
    connect(ui->chartPosition,SIGNAL(valueChanged(int)),this,SLOT(movePosition(int)));
    connect(ui->sizeSlider,SIGNAL(sliderMoved(int)),this,SLOT(setSize(int)));
    //connect(injCombo, SIGNAL(activated( const QString & )), this,SLOT(loadInjection(const QString& ))) ;
    connect(ui->zoomBox,SIGNAL(valueChanged(double)),chart,SLOT(setZoom(double)));
    connect(chart,SIGNAL(curPosChanged(QPolygonF)),this,SLOT(pcurrent(QPolygonF)));

    connect(ui->tabWidget,SIGNAL(currentChanged(int)),this,SLOT(tabChange(int)));

    connect(ui->table_diags,SIGNAL(cellChanged(int,int)),this,SLOT(calc_diags(int ,int)));
    connect(ui->pushButton_test,SIGNAL(clicked()),this,SLOT(calc_filter()));
}

void MainWindow::closeEvent ( QCloseEvent * /* event */)
{
  qApp->quit();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tabChange(int i)
{

}

void MainWindow::initCharts()
{
  QPen vPen;
  vPen.setColor(Qt::red);
  vPen.setWidthF(2.0);
  vPen.setColor(Qt::green);
  chart->setXMesh(16);
  chart->setYMesh(17);
  Channel ch0 (-130,110,new DoubleDataContainer<vint,lint>(times,ch0_data),
                      trUtf8("ch_0 Напряж"),vPen);
  vPen.setColor(Qt::magenta);
  Channel ch1 (-130,110,new DoubleDataContainer<vint,lint>(times,ch1_data),
                      trUtf8("Ch_1 Ток"),vPen);

  vPen.setColor(Qt::red);
  Channel ch2 (-130,110,new DoubleDataContainer<vint,lint>(times,ch2_data),
                      trUtf8("Ch_2"),vPen);
  vPen.setColor(Qt::blue);
  Channel ch3 (-130,110,new DoubleDataContainer<vint,lint>(times,ch3_data),
                      trUtf8("Ch_3"),vPen);

  ch0.setShowScale(true);
  ch1.setShowScale(false);
  ch2.setShowScale(false);
  ch3.setShowScale(false);
//chart->scaleGrid().showScale=false;
//chart->scaleGrid().showGrid=false;
  chart->addChannel(ch0);
  chart->addChannel(ch1);
  chart->addChannel(ch2);
  chart->addChannel(ch3);
  chart->setZoom(ui->zoomBox->value());
}

void MainWindow::movePosition(int val)
{
  chart->setPosition(val);
}

void MainWindow::setSize(int val)
{
  chart->setSize(val);
}

void MainWindow::loadCharts()
{
  int time = 0;
  int ch0_byte=0,ch1_byte=0,ch2_byte=0,ch3_byte=0;
  times.clear(); // vint
  ch0_data.clear(); // vint;
  ch1_data.clear();
  ch2_data.clear();
  ch3_data.clear();
  for(int row=1;row<ui->table_ram->rowCount();row++){
      if(ui->table_ram->item(row,0)==nullptr) break;
      if(ui->table_ram->item(row,1)==nullptr) break;
      if(ui->table_ram->item(row,2)==nullptr) break;
      if(ui->table_ram->item(row,3)==nullptr) break;
        QString ch_0_text=ui->table_ram->item(row,0)->text();
        QString ch_1_text=ui->table_ram->item(row,1)->text();
        QString ch_2_text=ui->table_ram->item(row,2)->text();
        QString ch_3_text=ui->table_ram->item(row,3)->text();
        ch0_byte=ch_0_text.toInt();
        ch1_byte=ch_1_text.toInt();
        ch2_byte=ch_2_text.toInt();
        ch3_byte=ch_3_text.toInt();
        times.push_back(time);
        ch0_data.push_back(ch0_byte);
        ch1_data.push_back(ch1_byte);
        ch2_data.push_back(ch2_byte);
        ch3_data.push_back(ch3_byte);
        ++time;
    }
  chart->channels().clear();
  initCharts();
  chart->update();
}
void MainWindow::pcurrent(const QPolygonF polygon )
  {
    QPointF p=polygon[0];
    int x=p.x();
    int y[8];

    for(int i=0;i<1;i++){
        p=polygon[i];
        y[i]=p.y();
    }
    QString cup="cur:";
    //cup.append(QString::number(x, 'f',0));
    cup.append(QString::number(x));
    //cup.append("; ");
    //if(x && x< timesabs.size()) cup.append(timesabs.at(x)/*.toLocal8Bit().constData()*/);
    for (int i=0;i<1;i++){//<<<<<<<<<<<<<<<<<<<<<<<<
        cup.append("; ");
        //cup.append(QString::number(y[i], 'f',0));
        cup.append(QString::number(y[i]));
    }
    ui->label->setText(cup);
    }

void MainWindow::newFile()
{
    if (maybeSave()) {
        //textEdit->clear();
        setCurrentFile(QString());
    }
}

void MainWindow::open()
{
    if (maybeSave()) {
        QString fileName = QFileDialog::getOpenFileName(this);
        if (!fileName.isEmpty())
            loadFile(fileName);
    }
}

bool MainWindow::save()
{ return true;
    if (curFile.isEmpty()) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }
}

bool MainWindow::saveAs()
{
    QFileDialog dialog(this);
    dialog.setWindowModality(Qt::WindowModal);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    if (dialog.exec() != QDialog::Accepted)
        return false;
    return saveFile(dialog.selectedFiles().first());
}

void MainWindow::about()
{
   QMessageBox::about(this, tr("About Application"),
            tr("Это приложение предназначено для "
               "анализа записей сделаных логгером "
               "встроенным в преобразователь частоты ППЧ"
               "производства Завода преобразователей ТВЧ"));
}

void MainWindow::documentWasModified()
{
    //setWindowModified(textEdit->document()->isModified());
}

void MainWindow::createActions()
{

    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QToolBar *fileToolBar = addToolBar(tr("File"));
    const QIcon newIcon = QIcon::fromTheme("document-new", QIcon(":/images/new.png"));
    QAction *newAct = new QAction(newIcon, tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);
    fileMenu->addAction(newAct);
    fileToolBar->addAction(newAct);

    const QIcon openIcon = QIcon::fromTheme("document-open", QIcon(":/images/open.png"));
    QAction *openAct = new QAction(openIcon, tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, &QAction::triggered, this, &MainWindow::open);
    fileMenu->addAction(openAct);
    fileToolBar->addAction(openAct);


    const QIcon saveIcon = QIcon::fromTheme("document-save", QIcon(":/images/save.png"));
    QAction *saveAct = new QAction(saveIcon, tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, &QAction::triggered, this, &MainWindow::save);
    fileMenu->addAction(saveAct);
    fileToolBar->addAction(saveAct);

    const QIcon saveAsIcon = QIcon::fromTheme("document-save-as");
    QAction *saveAsAct = fileMenu->addAction(saveAsIcon, tr("Save &As..."), this, &MainWindow::saveAs);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    saveAsAct->setStatusTip(tr("Save the document under a new name"));



    fileMenu->addSeparator();

    const QIcon exitIcon = QIcon::fromTheme("application-exit");
    QAction *exitAct = fileMenu->addAction(exitIcon, tr("E&xit"), this, &QWidget::close);
    exitAct->setShortcuts(QKeySequence::Quit);

    exitAct->setStatusTip(tr("Exit the application"));


    QMenu *editMenu = menuBar()->addMenu(tr("&Edit"));
    QToolBar *editToolBar = addToolBar(tr("Edit"));


    const QIcon cutIcon = QIcon::fromTheme("edit-cut", QIcon(":/images/cut.png"));
    QAction *cutAct = new QAction(cutIcon, tr("Cu&t"), this);

    cutAct->setShortcuts(QKeySequence::Cut);
    cutAct->setStatusTip(tr("Cut the current selection's contents to the "
                            "clipboard"));
    //connect(cutAct, &QAction::triggered, textEdit, &QPlainTextEdit::cut);
    editMenu->addAction(cutAct);
    editToolBar->addAction(cutAct);

    const QIcon copyIcon = QIcon::fromTheme("edit-copy", QIcon(":/images/copy.png"));
    QAction *copyAct = new QAction(copyIcon, tr("&Copy"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip(tr("Copy the current selection's contents to the "
                             "clipboard"));
    //connect(copyAct, &QAction::triggered, textEdit, &QPlainTextEdit::copy);
    editMenu->addAction(copyAct);
    editToolBar->addAction(copyAct);

    const QIcon pasteIcon = QIcon::fromTheme("edit-paste", QIcon(":/images/paste.png"));
    QAction *pasteAct = new QAction(pasteIcon, tr("&Paste"), this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
                              "selection"));
    //connect(pasteAct, &QAction::triggered, textEdit, &QPlainTextEdit::paste);
    editMenu->addAction(pasteAct);
    editToolBar->addAction(pasteAct);

    menuBar()->addSeparator();


    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
    QAction *aboutAct = helpMenu->addAction(tr("&About"), this, &MainWindow::about);
    aboutAct->setStatusTip(tr("Show the application's About box"));


    QAction *aboutQtAct = helpMenu->addAction(tr("About &Qt"), qApp, &QApplication::aboutQt);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));

    cutAct->setEnabled(true);
    copyAct->setEnabled(true);
    //connect(textEdit, &QPlainTextEdit::copyAvailable, cutAct, &QAction::setEnabled);
    //connect(textEdit, &QPlainTextEdit::copyAvailable, copyAct, &QAction::setEnabled);

}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::readSettings()
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    const QByteArray geometry = settings.value("geometry", QByteArray()).toByteArray();
    if (geometry.isEmpty()) {
        const QRect availableGeometry = QApplication::desktop()->availableGeometry(this);
        resize(availableGeometry.width() / 3, availableGeometry.height() / 2);
        move((availableGeometry.width() - width()) / 2,
             (availableGeometry.height() - height()) / 2);
    } else {
        restoreGeometry(geometry);
    }
}

void MainWindow::writeSettings()
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    settings.setValue("geometry", saveGeometry());
}

bool MainWindow::maybeSave()
{
    return true;
    //if (!textEdit->document()->isModified())
    //    return true;
    const QMessageBox::StandardButton ret
        = QMessageBox::warning(this, tr("Application"),
                               tr("The document has been modified.\n"
                                  "Do you want to save your changes?"),
                               QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    switch (ret) {
    case QMessageBox::Save:
        return save();
    case QMessageBox::Cancel:
        return false;
    default:
        break;
    }
    return true;
}

void MainWindow::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(fileName), file.errorString()));
        return;
    }

//ppch440_72->load_arhive(&file);
         if(ui->comboBox_conv->currentIndex()==0)
           load_arhive440_72(&file);
    else if(ui->comboBox_conv->currentIndex()==1)
           load_arhive8_32td(&file);
    else if(ui->comboBox_conv->currentIndex()==2)
           load_arhive8_10td(&file);

/*    QGuiApplication::setOverrideCursor(Qt::WaitCursor);
    //textEdit->setPlainText(in.readAll());
    QGuiApplication::restoreOverrideCursor();
*/

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File loaded"), 2000);
    loadCharts();
}

bool MainWindow::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(fileName),
                                  file.errorString()));
        return false;
    }

    QTextStream out(&file);
    QGuiApplication::setOverrideCursor(Qt::WaitCursor);
    //out << textEdit->toPlainText();
    QGuiApplication::restoreOverrideCursor();

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}

void MainWindow::setCurrentFile(const QString &fileName)
{
    curFile = fileName;
    //textEdit->document()->setModified(false);
    setWindowModified(false);

    QString shownName = curFile;
    if (curFile.isEmpty())
        shownName = "untitled.txt";
    setWindowFilePath(shownName);
}

QString MainWindow::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

void MainWindow::commitData(QSessionManager &manager)
{
    if (manager.allowsInteraction()) {
        if (!maybeSave())
            manager.cancel();
    } else {
        // Non-interactive: save without asking
        //if (textEdit->document()->isModified())
           // save();
    }
}
/*
void MainWindow::setCell(int table,int row,int column, QString &String )
{
if(ui->table_ram->item(row,column)==nullptr) return;
ui->table_ram->item(row,column)->setText(String);
}
*/
//*************************************************************************
//Немного откровенного говнокода
//*************************************************************************
#include "ppch440_72.hh"
#include "ppch8_10td.hh"
#include "ppch8_32td.hh"

void MainWindow::calc_diags(int row, int column){
    int diags;
    QString cell="test";
    int u=0;
    //row=1;
    column=17;
    //for(int u=0; u<14; u++){
        diags=0;
        for(int i=0; i<16; i++){
            int bit=ui->table_diags->item(row+u,16-i)->text().toInt();
            //int bit=1;
            diags<<=1;
            diags|=bit;
        }
        cell = "0x"+QString::number(diags,16);
        ui->table_diags->item(row+u,column)->setText(cell);
        cell = QString::number(diags);
        ui->table_diags->item(row+u,column+1)->setText(cell);
    //}
}

void MainWindow::calc_filter(){
    int flt=ui->comboBox_flt->currentIndex();
    if(ui->comboBox_conv->currentIndex()==0)
            calc_filter440_72(flt);
    else    calc_filter8(flt);

    loadCharts();
}





