#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
//#include "ppch440_72.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

    class QAction;
    class QMenu;
    class QPlainTextEdit;
    class QSessionManager;

    class Chart;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void loadFile(const QString &fileName);
    ~MainWindow();
    void initialize();
    void initCharts();
    void connections();
    void loadCharts();
    void setCell(int table,int row,int column, QString &String);

public slots:
    void tabChange(int i);
    void movePosition(int val);
    void setSize(int val);

private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void about();
    void documentWasModified();
    void commitData(QSessionManager &);
    void calc_diags(int row, int column);
    void pcurrent(const QPolygonF polygon );
    void calc_filter();

private:
    Ui::MainWindow *ui;
        void        closeEvent ( QCloseEvent * e );
        Chart      *chart;
        //Ppch440_72 *ppch440_72;
    void load_arhive440_72(QFile *arhive);
    void calc_filter440_72(int);
        //PPCH8 10termo
    void load_arhive8_10td(QFile *arhive);
    void load_arhive8_32td(QFile *arhive);
    void calc_filter8(int);

    void createActions();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    bool maybeSave();
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);

    QPlainTextEdit *textEdit;
    QString curFile;
};
#endif // MAINWINDOW_H
