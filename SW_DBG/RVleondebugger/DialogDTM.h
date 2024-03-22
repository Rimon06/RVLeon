#ifndef DIALOGDTM_H
#define DIALOGDTM_H

#include <QDialog>

namespace Ui {
class DialogDTM;
}

class DialogDTM : public QDialog
{
    Q_OBJECT

public:
    explicit DialogDTM(QWidget *parent = 0);
    ~DialogDTM();

signals:
    //void
    void DTMcnnctd (bool b );
public slots:
    void ConfirmConnection(bool c);
    void ConfirmDBGModeActive(bool c);

private slots:
    void on_BtnCnnctDTM_clicked();

    void on_BtnDiscnntDTM_clicked();


private:
    Ui::DialogDTM *ui;
};

#endif // DIALOGDTM_H
