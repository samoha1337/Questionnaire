#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
//конструктор
{
    ui->setupUi(this);

    QLayout* layout = ui->verticalLayout;
    randomButton(layout);

    setWindowTitle("Questionnaire");//установка названия прогрммы
    timer = new QTimer(this);//выделяем память для таймера
    timer->setInterval(100);
    connect(timer,SIGNAL(timeout()),this,SLOT(Timeotvet()));//соединяем таймер
    setWindowIcon(QIcon("C:/Qt/project/project_2-2/confused.ico"));//Установка иконки приложения
    for (int i=0; i<5; i++)
    {
        ans[i]="Неверно";
    }
    ui->pushButton_back->hide();
    ui->tableWidget->hide();
    ui->pushButton_repeat->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
}
//деструктор
MainWindow::~MainWindow()
{
    delete ui;
}
//таймер для подчсета времени ответа
void MainWindow::Timeotvet()
{    
    counter--;
    QTime time = QTime::fromMSecsSinceStartOfDay(counter*10);//перевод времени
    QString text = time.toString("mm:ss.zzz");//создаем маску для вывода чисел
    ui->lcdNumber->display(text);//выводим
    if (counter==0)
    {
        timer->stop();
        ui->pushButton->hide();
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        ui->pushButton_4->hide();
        ui->pushButton_5->hide();
        ui->pushButton_back->hide();
        ui->label->hide();
        QMessageBox::critical(this,"Внимание!","Время вышло!Начните тест сначала!");
        return;
    }
}
//клик на вариант ответа
void MainWindow::on_pushButton_clicked()
{
    if (question_index==1)
    {
        ans[0]="Верно";
    }

    question_index++;
    SetQuestion();
    QLayout* layout = ui->verticalLayout;
    randomButton(layout);
}
//клик на вариант ответа
void MainWindow::on_pushButton_2_clicked()
{
    if (question_index==2)
    {
        ans[1]="Верно";
    }

    question_index++;
    SetQuestion();
    QLayout* layout = ui->verticalLayout;
    randomButton(layout);
}
//клик на вариант ответа
void MainWindow::on_pushButton_3_clicked()
{
    if (question_index==3)
    {
        ans[2]="Верно";
    }
    question_index++;
    SetQuestion();
    QLayout* layout = ui->verticalLayout;
    randomButton(layout);
}
//клик на вариант ответа
void MainWindow::on_pushButton_4_clicked()
{
    if (question_index==4)
    {
        ans[3]="Верно";
    }
    question_index++;
    SetQuestion();
    QLayout* layout = ui->verticalLayout;
    randomButton(layout);
}
//клик на вариант ответа
void MainWindow::on_pushButton_5_clicked()
{    
    if (question_index==5)
    {
        ans[4]="Верно";
    }

    question_index++;
    SetQuestion();
    QLayout* layout = ui->verticalLayout;
    randomButton(layout);
}
//устанавливает вопрос в зависимости от индекса
void MainWindow::SetQuestion()
{
    QString lab,p1,p2,p3,p4,p5;
    switch (question_index)
    {
    case 1:
        timer_ans->start();
       lab="Вопрос 1: Какая ты капибара?";
        p1="Злая";
        p2="Добрая";
        p3="Веселая";
        p4="Плавающая";
        p5="Голодная";        
        ui->pushButton_back->hide();
        break;
    case 2:
        settime(0);
        timer_ans->start();
        lab="Вопрос 2: Благодаря чему, группа РГБО сдала физику?";
        p1="Не сдали";
        p2="С помощью Пригожина";
        p3="Все все выучили";
        p4="Наугад";
        p5="Сходили в церковь";        
        ui->pushButton_back->show();
        break;
    case 3:
        settime(1);
        timer_ans->start();
        lab="Вопрос 3: Кто всегда больше всех ест в Токио?";
        p1="Полина";
        p2="Володя";
        p3="ПАПАБАДИК";
        p4="Фома";
        p5="Ковальский";        
        break;
    case 4:
        settime(2);
        timer_ans->start();
        lab="Вопрос 4: Что хуже?";
        p1="4 пары ДЗЗ";
        p2="Английский";
        p3="Матеша";
        p4="4 пары физики";
        p5="3д моделирование";        
        break;
    case 5:
        settime(3);
        timer_ans->start();
        lab="Вопрос 5: Кто состоит в МГЕР?";
        p1="Ванек";
        p2="Володя";
        p3="Андрей";
        p4="Фома";
        p5="Саня";
        settime(4);
        break;
     }
    settime(4);
    if (question_index>5)
    {

        ui->tableWidget->show();
        ui->pushButton->hide();
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        ui->pushButton_4->hide();
        ui->pushButton_5->hide();
        ui->pushButton_back->hide();
        ui->label->hide();
        ui->pushButton_repeat->show();
        timer->stop();


        for (int i=0;i<5; i++)//запрещаем изменение ячеек
        {
            QTableWidgetItem * new_item; //создаем указатель на ячейку
            new_item = new QTableWidgetItem; //выделяем память
            new_item->setFlags(new_item->flags() & 0xfffffffd);//запрещаем редактирование ячейки
            new_item->setText(ans[i]);//устанавливаем ответ
            ui->tableWidget->setItem(i,0,new_item);//в какую ячейку устанавливаем
        }
     }
     else
     {
        ui->label->setText(lab);
        ui->pushButton->setText(p1);
        ui->pushButton_2->setText(p2);
        ui->pushButton_3->setText(p3);
        ui->pushButton_4->setText(p4);
        ui->pushButton_5->setText(p5);
     }
}
//кнопка для возврата к предыдущему вопросу
void MainWindow::on_pushButton_back_clicked()
{
    question_index--;
    SetQuestion();
}
//кнопка заново
void MainWindow::on_pushButton_repeat_clicked()
{    
    //QLayout* layout = ui->verticalLayout;
    //randomButton(layout);
    question_index=1;
    for (int i=0; i<5; i++)
    {
        ans[i]="Неверно";
    }
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    ui->pushButton_easy->show();
    ui->pushButton_middle->show();
    ui->pushButton_hard->show();
    ui->pushButton_back->hide();
    ui->label->hide();
    ui->tableWidget->hide();
    timer->start();
    counter=0;
    ui->pushButton_repeat->hide();
    SetQuestion();
    ui->pushButton_back->hide();
}
//функция для вывода времени ответа на вопрос в таблицу
void MainWindow::settime(int k)
{
    QTime elapsedTime = QTime::fromMSecsSinceStartOfDay(timer_ans->elapsed());//времени прошло с выбора ответа
    QString text = elapsedTime.toString("mm:ss.zzz");//создаем маску для вывода чисел
    QTableWidgetItem *item = new QTableWidgetItem(text);//выделяем память
    item->setFlags(item->flags() & 0xfffffffd);//запрещаем редактирование ячейки
    ui->tableWidget->setItem(k,1,item);//вносим ячейку таблицы
}
//кнопка выбора сложности (легкий)
void MainWindow::on_pushButton_easy_clicked()
{
    ui->pushButton_easy->hide();
    ui->pushButton_middle->hide();
    ui->pushButton_hard->hide();
    ui->label->show();
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->pushButton_4->show();
    ui->pushButton_5->show();
    counter = 12000;
    SetQuestion();
    timer->start(10);
    //best_time();
}
//кнопка выбора сложности (средний)
void MainWindow::on_pushButton_middle_clicked()
{
    ui->pushButton_easy->hide();
    ui->pushButton_middle->hide();
    ui->pushButton_hard->hide();
    ui->label->show();
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->pushButton_4->show();
    ui->pushButton_5->show();
    counter = 6000;
    SetQuestion();
    timer->start(10);
    //best_time();
}
//кнопка выбора сложности (тяжелый)
void MainWindow::on_pushButton_hard_clicked()
{
    ui->pushButton_easy->hide();
    ui->pushButton_middle->hide();
    ui->pushButton_hard->hide();
    ui->label->show();
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->pushButton_4->show();
    ui->pushButton_5->show();
    counter = 3000;
    SetQuestion();
    timer->start(10);
    //best_time();
}

void MainWindow::randomButton(QLayout *layout)
{
    // Создание списка виджетов из макета
        QList<QWidget*> widgets;
        for (int i = 0; i < layout->count(); i++)
        {
            QWidget* widget = layout->itemAt(i)->widget();
            if (widget)
            {
                widgets.append(widget);
            }
        }

        // Перемешивание списка виджетов
        int n = widgets.size();
        for (int i = 0; i < n - 1; i++)
        {
            int j = QRandomGenerator::global()->bounded(n - i);
            if (i != j)
            {
                QWidget* temp = widgets[i];
                widgets[i] = widgets[j];
                widgets[j] = temp;
            }
        }

        // Удаление виджетов из макета
        while (QLayoutItem* item = layout->takeAt(0))
        {
            delete item;
        }
        // Добавление виджетов вновь в макет в случайном порядке
        foreach (QWidget* widget, widgets)
        {
            layout->addWidget(widget);
        }
}
//void MainWindow::best_time()
//{
//    QTime star;
//    QTime Time = QTime::currentTime();
//    int blabla = star.msecsTo(Time);
//    /*QString text = blabla.toString("mm:ss.zzz");*///создаем маску для вывода чисел
//    ui->label_2->setText(QString::number(blabla));
//}
