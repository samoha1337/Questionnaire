#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QMessageBox>
#include <QString>
#include <QElapsedTimer>
#include <QPushButton>
#include <QLayout>

#include <QRandomGenerator>
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
    void on_pushButton_clicked();//1 вариант ответа

    void on_pushButton_2_clicked();//2 вариант ответа

    void on_pushButton_3_clicked();//3 вариант ответа

    void on_pushButton_4_clicked();//4 варинт ответа

    void on_pushButton_5_clicked();//5 варинт ответа

    void Timeotvet();//таймер

    void SetQuestion();//вставляем вопрос и варианты ответа или результаты тестирования

    void on_pushButton_back_clicked();//кнопка обратно

    void on_pushButton_repeat_clicked();//повторить опрос

    void settime(int k);//функция для вывода времени в таблицу

    void on_pushButton_easy_clicked();//кнопка выбора сложности(легкий)

    void on_pushButton_middle_clicked();//кнопка выбора сложности (средний)

    void on_pushButton_hard_clicked();//кнопка выбора сложности (тяжелый)

    //void best_time();

    void randomButton(QLayout *layout);

private:
    Ui::MainWindow *ui;
    QTime *timer_ans;//создаем таймер для скорости ответа
    QTimer *timer;//таймер
    int counter;
    QString ans[5];
    int question_index=1;
    QTime tablemas[5];

};
#endif // MAINWINDOW_H
