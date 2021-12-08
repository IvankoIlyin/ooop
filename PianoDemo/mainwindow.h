#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QKeyEvent>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_keyC_pressed();

    void on_keyC_released();

    void on_keyD_pressed();

    void on_keyD_released();

    void on_keyE_pressed();

    void on_keyE_released();

    void on_keyF_pressed();

    void on_keyF_released();

    void on_keyG_pressed();

    void on_keyG_released();

    void on_keyA_pressed();

    void on_keyA_released();

    void on_keyB_pressed();

    void on_keyB_released();

    void on_keydiezC_pressed();

    void on_keydiezC_released();

    void on_keydiezD_pressed();

    void on_keydiezD_released();

    void on_keydiezF_pressed();

    void on_keydiezF_released();

    void on_keydiezG_pressed();

    void on_keydiezG_released();

    void on_keydiezA_pressed();

    void on_keydiezA_released();

    void on_GrandPiano_clicked();

    void on_Synth_clicked();

    void on_Guitar_clicked();

    void on_Cthree_clicked();

    void on_Cfour_clicked();

    void on_Cfive_clicked();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
