// --------------------------------------------------------------- //
// CKim - Class generated by QT. Implements most of GUI interactions
// Last Updated : 2020.10.19 CKim & VysADN
// --------------------------------------------------------------- //
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// CKim - Headers
#include "epos4_can.h"
#include <motorthread.h>
#include <QElapsedTimer>
#include <m_defines.h>
#include "emergency_window.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // CKim - GUI callbacks (button click, toggle, etc.)
    void on_btnDecreaseRPM_clicked();

    void on_btnIncreaseRPM_clicked();

    void on_radioCW_toggled(bool checked);

    void on_radioCCW_toggled(bool checked);

    void on_radioOSC_toggled(bool checked);

    void on_btnDecreaseFlow_clicked();

    void on_btnIncreaseFlow_clicked();

    void on_btnIrrigationMove_clicked();

    void on_btnIrrigationStop_clicked();
    
    void on_btnCloseBlade_clicked();

    void on_radioMAXRPM_clicked();

    // CKim - Slot handling UpdateGUI() signal
    void stateChanged(int state);

    // CKim - Opens Emergency Dialog
    void callEmergencyWindow();

    // CKim - Called on exit of emrgency dialog
    void exitEmergencyWindow(int a);

private:
      Ui::MainWindow *ui;

      // CKim - QString for messages that will be displayed
      QString speedLabel;
      QString statusLabel;

      // CKim - Variables updated from GUI input
      float pumpMotorTargetSpeed=0.0;
      int pumpMotorSpeedPrintVal=0;
      bool pumpRunningStatus=false;
      int debriderMotorTargetSpeed;

      Emergency_Window emergencyWindow;
      motorThread m_Thread;

private:
      void printStatus(int dSpeed, int pSpeed);

      // CKim - Pump motor on/off
      void stopPumpMotor();
      void movePumpMotor();

      // CKim - Enable / Disable GUI
      void enableGUI();
      void disableGUI();

      // CKim - Processes foot pedal inputs
      void showPedalBtnStates();

};

#endif // MAINWINDOW_H
