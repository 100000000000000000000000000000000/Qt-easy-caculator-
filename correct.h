#ifndef CORRECT_H
#define CORRECT_H

#include <QWidget>

namespace Ui {
class correct;
}

class correct : public QWidget
{
    Q_OBJECT

public:
    explicit correct(QWidget *parent = nullptr);
    ~correct();
    Ui::correct *ui;
public slots:
    void on_ok_clicked();
private:
    QFont f;
};

#endif // CORRECT_H
