#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dtmcontroller.h"
#include <QMessageBox>
#include "DialogDTM.h"
#include "pipelinereg.h"
#include <QFrame>
#include "coresegmentacion.h"
#include <QColor>
#include <QBrush>
#include <QFile>
#include <QFileDialog>
#include <QDir>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void receptor(QByteArray data, qint16 DTMState);

    void LeerGPRegs();
    void LeerCSRs();
    void LeerPIPEregs();

    const QColor F_color = QColor(Qt::red).lighter(170),
                 D_color = QColor(Qt::yellow).lighter(170),
                 E_color = QColor(Qt::blue).lighter(170),
                 M_color = QColor(Qt::magenta).lighter(170),
                 W_color = QColor(Qt::cyan).lighter(170);

private slots:

    void ConnectPort(bool c);

    void on_HexCheckBox_stateChanged(int arg1);

    void on_BtnPlay_clicked();

    void on_BtnPause_clicked();
    
    void on_BtnRestart_clicked();
    
    void on_BtnNext_clicked();

    void on_OpenCodeBtn_clicked();

private:
    Ui::MainWindow *ui;
    QList <qint32> GPregs; // 32 Registros del sistema
    QList <qint32> PIPEregs; // Registros  de segmentación
    quint64 cycle = 0, instret = 0;
    quint32 dcsr = 0, data0 = 0;
    DTMController * _port;
    DialogDTM * DTMBtnGroup;
    qint8 count;
    PipelineReg *  F_widget,
                * FD_widget,
                * DE_widget,
                * EM_widget,
                * MW_widget;
    bool HexActivated;
    QString elfHexFile;
    CoreSegmentacion * _Core;
    int HGRows[5] = {-1,-1,-1,-1,-1};
    bool TablaActualizada = false;


    void CreateDialogDTM();
    void CreateRegs();
    void CreatePiperegs();
    void ActualizarRegsTable(bool hex);

    inline static QString ConvertToString(quint32 num,bool hex){
        return (hex ? QString("0x%1").arg((quint32) num,8,16,QLatin1Char('0'))
                    : QString("%1").arg((qint32) num));
    }
    inline QString ConvertToString(quint32 num) {
        return ConvertToString(num, HexActivated);
    }

    inline static QString ConvertToString(quint64 num,bool hex){
        return (hex ? QString("0x%1").arg((quint64) num,16,16,QLatin1Char('0'))
                    : QString("%1").arg((qint64) num));
    }

    void ActualizarValCycle(bool hex);
    void ActualizarValInstret(bool hex);
    void ActualizarValdcsr(bool hex);
    void CreatePipeLayout(QFrame *fr, PipelineReg *pipe);
    void SetPipeline();
    void ChangeBackgroundItems(int InstrRow, QColor PipeColor);
    void ResaltarInstruccion(int pipe, QColor color);
    void SetBackgroundByPipeline();
    void ChangeBackgroundPalette(QLabel *lbl, Qt::BrushStyle r);
};

#endif // MAINWINDOW_H
