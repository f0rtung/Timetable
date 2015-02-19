#include "timetable.h"
#include "ui_timetable.h"
#include <QTextDocument>
#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

Timetable::Timetable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Timetable)
{
    ui->setupUi(this);
}

Timetable::~Timetable()
{
    delete ui;
}

void Timetable::on_pushButton_3_clicked()
{
    QTextDocument* doc = ui->textEdit->document();
    QString str = doc->toPlainText();
    str.remove(0,1);
    str.remove(str.count()-1,1);
    ui->textEdit->setText(str);
    lst = str.split('\n');
}

void Timetable::on_pushButton_2_clicked()
{
    QTextDocument* doc = ui->textEdit->document();
    QString str = doc->toPlainText();
    ui->textEdit->setText(str);
    lst = str.split('\n');
    total = "Subject,Start Date,Start Time,End Date,End Time,All Day Event,Description,Location,Private";
    for(int i = 0; i < lst.count()/8; ++i){
        total +='\n';
        QString data = lst.at(i*8 + 1);
        int index = data.indexOf('.');
        while(index != -1){
            data[index] = '/';
            index = data.indexOf('.');
        }
        QString time = lst.at(i*8 + 3);
        QString timestart = time.split('-').at(0);
        QString timeend = time.split('-').at(1);
        timestart.insert(2,':');
        timeend.insert(2,':');
        QString all = lst.at(i*8 + 5) + "," + data + "," + timestart + "," + data + "," + timeend + "," + "False" + "," + lst.at(i*8 + 4) + "," + lst.at(i*8 + 6) + ",True";
        total += all;
    }
    ui->textEdit->setText(total);
}

void Timetable::on_pushButton_clicked()
{
     QString filename = QFileDialog::getSaveFileName(  // открываем файл для сохранения
                    this,
                    "Save File",
                    ".",
                    "cvs File (*.csv)");
     QFile file(filename);
     file.open(QIODevice::WriteOnly|QIODevice::Text);
     QTextStream out(&file);
     out << total;
}
