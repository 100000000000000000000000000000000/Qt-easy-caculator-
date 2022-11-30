#ifndef SURPRISE_WINDOW_H
#define SURPRISE_WINDOW_H

#include <QMainWindow>


namespace Ui {
class surprise_window;
}

class surprise_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit surprise_window(QWidget *parent = nullptr);
    ~surprise_window();

private slots:
    void on_yes_clicked();

    void on_no_clicked();

private:
    Ui::surprise_window *ui;
};

#endif // SURPRISE_WINDOW_H
