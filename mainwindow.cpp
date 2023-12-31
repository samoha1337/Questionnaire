#include "mainwindow.h"
#include "ui_mainwindow.h"
struct questions
{
  QString question;
  QString ans[5];
};
questions question[5] =
{
    {
        "Вопрос 1: Какая ты капибара?",
        {
             "Злая",
             "Добрая",
             "Веселая",
             "Плавающая",
             "Голодная",
        }
    },
    {
        "Вопрос 2: Благодаря чему, группа РГБО сдала физику?",
        {
            "Не сдали",
            "С помощью Пригожина",
            "Все все выучили",
            "Наугад",
            "Сходили в церковь",

        }
    },
    {
        "Вопрос 3: Кто всегда больше всех ест в Токио?",
        {
            "Полина",
            "Володя",
            "ПАПАБАДИК",
            "Фома",
            "Ковальский",
        }
    },
    {
        "Вопрос 4: Что хуже?",
        {
            "4 пары ДЗЗ",
            "Английский",
            "Матеша",
            "4 пары физики",
            "3д моделирование",

        }
    },
    {
        "Вопрос 5:  Кто состоит в МГЕР?",
        {
            "Ванек",
            "Володя",
            "Андрей",
            "Фома",
            "Саня",
        }
    },

};
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
//конструктор
{
    ui->setupUi(this);    
    QLayout* layout = ui->verticalLayout_question;
    randomButton(layout);    
    ui->lcdNumber->hide();
    ui->tableWidget->hide();
    setWindowTitle("Questionnaire");//установка названия прогрммы
    timer = new QTimer(this);//выделяем память для таймера
    timer->setInterval(100);    
    connect(timer,SIGNAL(timeout()),this,SLOT(Timeotvet()));//соединяем таймер
    setWindowIcon(QIcon("C:/Qt/project/project_2-2/confused.ico"));//Установка иконки приложения
    for (int i=0; i<5; i++)
    {
        ans[i]="Неверно";
    }
    hide_bt();
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
        hide_bt();
        QMessageBox::critical(this,"Внимание!","Время вышло!Начните тест сначала!");
        return;
    }
}
//клик на вариант ответа
void MainWindow::on_pushButton_1_clicked()
{
    if (question_index==1)
    {
        ans[0]="Верно";
    }

    question_index++;
    SetQuestion();
    QLayout* layout = ui->verticalLayout_question;
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
    QLayout* layout = ui->verticalLayout_question;
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
    QLayout* layout = ui->verticalLayout_question;
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
    QLayout* layout = ui->verticalLayout_question;
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
    QLayout* layout = ui->verticalLayout_question;
    randomButton(layout);
}
//устанавливает вопрос в зависимости от индекса
void MainWindow::SetQuestion()
{       
    switch (question_index)
    {
    case 1:        
        timer_ans->start();
        ui->label_question->setText(question[0].question);
        ui->pushButton_1->setText(question[0].ans[0]);
        ui->pushButton_2->setText(question[0].ans[1]);
        ui->pushButton_3->setText(question[0].ans[2]);
        ui->pushButton_4->setText(question[0].ans[3]);
        ui->pushButton_5->setText(question[0].ans[4]);
        ui->pushButton_back->hide();
        break;
    case 2:
        settime(0);
        timer_ans->start();
        ui->label_question->setText(question[1].question);
        ui->pushButton_1->setText(question[1].ans[0]);
        ui->pushButton_2->setText(question[1].ans[1]);
        ui->pushButton_3->setText(question[1].ans[2]);
        ui->pushButton_4->setText(question[1].ans[3]);
        ui->pushButton_5->setText(question[1].ans[4]);
        ui->pushButton_back->show();
        break;
    case 3:
        settime(1);
        timer_ans->start();
        ui->label_question->setText(question[2].question);
        ui->pushButton_1->setText(question[2].ans[0]);
        ui->pushButton_2->setText(question[2].ans[1]);
        ui->pushButton_3->setText(question[2].ans[2]);
        ui->pushButton_4->setText(question[2].ans[3]);
        ui->pushButton_5->setText(question[2].ans[4]);
        break;
    case 4:
        settime(2);
        timer_ans->start();
        ui->label_question->setText(question[3].question);
        ui->pushButton_1->setText(question[3].ans[0]);
        ui->pushButton_2->setText(question[3].ans[1]);
        ui->pushButton_3->setText(question[3].ans[2]);
        ui->pushButton_4->setText(question[3].ans[3]);
        ui->pushButton_5->setText(question[3].ans[4]);
        break;
    case 5:
        settime(3);
        timer_ans->start();
        ui->label_question->setText(question[4].question);
        ui->pushButton_1->setText(question[4].ans[0]);
        ui->pushButton_2->setText(question[4].ans[1]);
        ui->pushButton_3->setText(question[4].ans[2]);
        ui->pushButton_4->setText(question[4].ans[3]);
        ui->pushButton_5->setText(question[4].ans[4]);
        settime(4);
        break;
     }
    settime(4);
    if (question_index>5)
    {

        timer->stop();
        hide_bt();
        ui->tableWidget->show();
        ui->pushButton_repeat->show();

        for (int i=0;i<5; i++)//запрещаем изменение ячеек
        {
            QTableWidgetItem * new_item; //создаем указатель на ячейку
            new_item = new QTableWidgetItem; //выделяем память
            new_item->setFlags(new_item->flags() & 0xfffffffd);//запрещаем редактирование ячейки
            new_item->setText(ans[i]);//устанавливаем ответ
            ui->tableWidget->setItem(i,0,new_item);//в какую ячейку устанавливаем
        }
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
    question_index=1;
    for (int i=0; i<5; i++)
    {
        ans[i]="Неверно";
    }
    ui->pushButton_easy->show();
    ui->pushButton_middle->show();
    ui->pushButton_hard->show();      
    timer->start();
    counter=0;
    hide_bt();
    SetQuestion();    
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
    show_bt();
    counter = 12000;
    SetQuestion();
    timer->start(10);   
}
//кнопка выбора сложности (средний)
void MainWindow::on_pushButton_middle_clicked()
{
    ui->pushButton_easy->hide();
    ui->pushButton_middle->hide();
    ui->pushButton_hard->hide();
    show_bt();
    counter = 6000;
    SetQuestion();
    timer->start(10);    
}
//кнопка выбора сложности (тяжелый)
void MainWindow::on_pushButton_hard_clicked()
{
    ui->pushButton_easy->hide();
    ui->pushButton_middle->hide();
    ui->pushButton_hard->hide();
    show_bt();
    counter = 3000;
    SetQuestion();
    timer->start(10);   
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
//показ кнопок
void MainWindow::show_bt()
{
    ui->label_question->show();
    ui->pushButton_1->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    ui->pushButton_4->show();
    ui->pushButton_5->show();
    ui->lcdNumber->show();
}
//скрытие кнопок
void MainWindow::hide_bt()
{
    ui->pushButton_1->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->pushButton_4->hide();
    ui->pushButton_5->hide();
    ui->pushButton_back->hide();
    ui->pushButton_repeat->hide();
    ui->label_question->hide();
    ui->tableWidget->hide();
}


