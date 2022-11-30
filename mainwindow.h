#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QString>
#include <QMainWindow>
#include <string>
#include <stack>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void get_result();

    void sur_win();
private slots:

    void on_p1_clicked();

    void on_p2_clicked();

    void on_p3_clicked();

    void on_p4_clicked();

    void on_p5_clicked();

    void on_p6_clicked();

    void on_p7_clicked();

    void on_p8_clicked();

    void on_p9_clicked();

    void on_p0_clicked();

    void on_AC_clicked();

    void on_backspace_clicked();

    void on_padd_clicked();

    void on_psubstract_clicked();

    void on_pmultiple_clicked();

    void on_pequal_clicked();

    void on_pdivide_clicked();

    void on_pdot_clicked();

    void on_ppow_clicked();

    void on_jingxi_clicked();

    void on_brackestl_clicked();

    void on_brackestr_clicked();

    void on_pequal2_clicked();
private:
    Ui::MainWindow *ui;
    QString input = "", ans = "";
    std::string s = "";
    int tag = 1;    //tag = 1表示刚输入了一个符号，再输入符号的时候会直接替换刚才输入的符号
};
#endif // MAINWINDOW_H
