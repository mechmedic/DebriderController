/*****************************************************************************
 * \file  emergency_window.h
 * \brief Header file includes emergency window class which includes
 * emergency messages, in case of any error occurence in the software,
 * such as motor driver error, SPI communication error, watchdog error.
 * Additionally clicking emergency button will wake this window as well.
 *
 * Last Updated : 2022.03.15 Chunwoo Kim (CKim) & Veysi ADIN (VysAdn)
 * Contact Info : cwkim@kist.re.kr & veysi.adin@kist.re.kr
 *******************************************************************************/

#ifndef EMERGENCY_WINDOW_H
#define EMERGENCY_WINDOW_H

#include <QDialog>
#include "m_defines.h"

namespace Ui {
class Emergency_Window;
}

class EmergencyWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EmergencyWindow(QWidget *parent = nullptr);
    ~EmergencyWindow();
    int emergency_status_;
    void SetEmergencyText();
private slots:
    void on_ButtonEmergencyExit_clicked();
signals:
    void EmergencyExitClicked(int s);
private:
    Ui::Emergency_Window *ui;
};

#endif // EMERGENCY_WINDOW_H
