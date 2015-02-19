#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <QWidget>
#include <QStringList>
#include <QString>

namespace Ui {
class Timetable;
}

class Timetable : public QWidget
{
    Q_OBJECT

public:
    explicit Timetable(QWidget *parent = 0);
    ~Timetable();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Timetable *ui;
    QStringList lst;
    QString total;
};

#endif // TIMETABLE_H
