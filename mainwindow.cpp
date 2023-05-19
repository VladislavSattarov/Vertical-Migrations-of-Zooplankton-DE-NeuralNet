#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    srand(time(0));
    clock_t start = clock();
    bool noise, dif;
    if(ui->checkBox->isChecked())
        noise = true;
    else
        noise = false;
    if(ui->checkBox_2->isChecked())
        dif = true;
    else
        dif = false;
    N.alpha_j = ui->AJ->text().toDouble();
    N.alpha_a = ui->AA->text().toDouble();
    N.beta_a = ui->BA->text().toDouble();
    N.beta_j = ui->BJ->text().toDouble();
    N.delta_a = ui->DA->text().toDouble();
    N.delta_j = ui->DJ->text().toDouble();
    N.gamma_a = ui->GA->text().toDouble();
    N.gamma_j = ui->GJ->text().toDouble();
    settings = Settings(ui->c1->text().toInt(), ui->lineEdit_9c2->text().toInt(), ui->lineEdit_10c3->text().toInt(), ui->eta1->text().toDouble(), ui->eta2->text().toDouble(),
                        ui->lineEdit_2xi1->text().toDouble(), ui->lineEdit_3xi2->text().toDouble(), ui->lineEdit_4x3->text().toDouble(), ui->lineEdit_5x4->text().toDouble(), noise, ui->lineEdit_11per->text().toDouble(), ui->lineEdit_2maxDeep->text().toInt(), dif);
    int PS = ui->line_PS->text().toInt();
    int CDE = ui->line_CDE->text().toInt();
    A = N.process(CDE, PS, settings);
    ui->widget->clearGraphs();
    ui->widget_6->clearGraphs();
    ui->widget->xAxis->setRange(0, 1440);
    ui->widget->xAxis->setLabel("Минуты");
    ui->widget->yAxis->setRange(settings.MaxDeep-5, 10);
    ui->widget->yAxis->setLabel("Высота");
    ui->widget->addGraph();
    /*A.Setx1(A.migrationx1[A.migrationx1.size() - 1]);
    A.Setx2(A.migrationx2[A.migrationx2.size() - 1]);
    A.migrationx1.clear();
    A.migrationx2.clear();
    A.x1dt.clear();
    A.x2dt.clear();
    A.ProcessDay();*/
    for(int i = 0; i < 1440; i++)
    {
        ui->widget->graph(0)->addData(i, A.migrationx1[i]);
    }
    ui->widget->addGraph();
    for(int i = 0; i < 1440; i++)
    {
        ui->widget->graph(1)->addData(i, A.migrationx2[i]);
    }
    ui->widget->graph(1)->setPen(QPen(Qt::red));
    ui->widget->replot();
    ui->widget->setInteraction(QCP::iRangeZoom, true);
    ui->widget->setInteraction(QCP::iRangeDrag, true);
    ui->widget_2->xAxis->setRange(settings.MaxDeep-5, 5);
    ui->widget_2->yAxis->setRange(-2, 2);
    ui->widget_2->addGraph();
    for(int x = settings.MaxDeep-5; x < 2; x++)
    {
        ui->widget_2->graph(0)->addData(x, settings.E(x));
    }
     ui->widget_2->replot();

     ui->widget_3->xAxis->setRange(settings.MaxDeep-5, 5);
     ui->widget_3->yAxis->setRange(-2, 2);
     ui->widget_3->addGraph();
     for(int x = settings.MaxDeep-5; x < 2; x++)
     {
         ui->widget_3->graph(0)->addData(x, settings.Sx(x));
     }
      ui->widget_3->replot();

      ui->widget_4->xAxis->setRange(0, 1440);
      ui->widget_4->yAxis->setRange(-2, 2);
      ui->widget_4->addGraph();
      for(int x = 0; x < 1440; x++)
      {
          ui->widget_4->graph(0)->addData(x, settings.St(x));
      }
       ui->widget_4->replot();

       ui->widget_5->xAxis->setRange(settings.MaxDeep-5, 5);
       ui->widget_5->yAxis->setRange(-2, 2);
       ui->widget_5->addGraph();
       for(int x = settings.MaxDeep-5; x < 2; x++)
       {
           ui->widget_5->graph(0)->addData(x, settings.G(x));
       }
        ui->widget_5->replot();
        ui->widget_6->xAxis->setRange(0, N.Fits.size());
        ui->widget_6->xAxis->setLabel("Операция DE");
        ui->widget_6->yAxis->setRange(2.85, 3.25);
        ui->widget_6->yAxis->setLabel("Значение фитнес функции");
        ui->widget_6->addGraph();
        for(int x = 0; x < N.Fits.size(); x++)
        {
            ui->widget_6->graph(0)->addData(x, N.Fits[x]);
        }
        ui->widget_6->replot();
        ui->widget_6->setInteraction(QCP::iRangeZoom, true);
        ui->widget_6->setInteraction(QCP::iRangeDrag, true);
    ui->label_2->setText(QString::number(N.Fit(&A)));
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    ui->label_8->setText(QString::number(seconds));
}


void MainWindow::on_SaveButton_clicked()
{
    double Fit = N.Fit(&A);
    std::string str;
    str = std::to_string(Fit);
    A.serialize(str + ".txt");
    ui->SelectedLabel->setText("Сохранено");
    ui->NameSelected->setText(QString::fromStdString(str));
}

void MainWindow::on_LoadButton_clicked()
{
    std::string str;
    str = ui->lineEdit->text().toStdString();
    A = A.deserializeNeuralNet(str);
    ui->SelectedLabel->setText("Загружено");
    ui->NameSelected->setText(QString::fromStdString(str));
 }

void MainWindow::on_ProcessDayButton_clicked()
{
    srand(time(0));
    clock_t start = clock();
    bool noise, dif;
    if(ui->checkBox->isChecked())
        noise = true;
    else
        noise = false;
    if(ui->checkBox_2->isChecked())
        dif = true;
    else
        dif = false;
    N.alpha_j = ui->AJ->text().toDouble();
    N.alpha_a = ui->AA->text().toDouble();
    N.beta_a = ui->BA->text().toDouble();
    N.beta_j = ui->BJ->text().toDouble();
    N.delta_a = ui->DA->text().toDouble();
    N.delta_j = ui->DJ->text().toDouble();
    N.gamma_a = ui->GA->text().toDouble();
    N.gamma_j = ui->GJ->text().toDouble();
    settings = Settings(ui->c1->text().toInt(), ui->lineEdit_9c2->text().toInt(), ui->lineEdit_10c3->text().toInt(), ui->eta1->text().toDouble(), ui->eta2->text().toDouble(),
                        ui->lineEdit_2xi1->text().toDouble(), ui->lineEdit_3xi2->text().toDouble(), ui->lineEdit_4x3->text().toDouble(), ui->lineEdit_5x4->text().toDouble(), noise, ui->lineEdit_11per->text().toDouble(), ui->lineEdit_2maxDeep->text().toInt(), dif);
    A.settings = settings;
    A.ProcessDay();
    ui->widget->clearGraphs();
    ui->widget_6->clearGraphs();
    ui->widget->xAxis->setRange(0, 1440);
    ui->widget->xAxis->setLabel("Минуты");
    ui->widget->yAxis->setRange(settings.MaxDeep-5, 10);
    ui->widget->yAxis->setLabel("Высота");
    ui->widget->addGraph();
    for(int i = 0; i < 1440; i++)
    {
        ui->widget->graph(0)->addData(i, A.migrationx1[i]);
    }
    ui->widget->addGraph();
    for(int i = 0; i < 1440; i++)
    {
        ui->widget->graph(1)->addData(i, A.migrationx2[i]);
    }
    ui->widget->graph(1)->setPen(QPen(Qt::red));
    ui->widget->replot();
    ui->widget->setInteraction(QCP::iRangeZoom, true);
    ui->widget->setInteraction(QCP::iRangeDrag, true);
    ui->widget_2->xAxis->setRange(settings.MaxDeep-5, 5);
    ui->widget_2->yAxis->setRange(-2, 2);
    ui->widget_2->addGraph();
    for(int x = settings.MaxDeep-5; x < 2; x++)
    {
        ui->widget_2->graph(0)->addData(x, settings.E(x));
    }
     ui->widget_2->replot();

     ui->widget_3->xAxis->setRange(settings.MaxDeep-5, 5);
     ui->widget_3->yAxis->setRange(-2, 2);
     ui->widget_3->addGraph();
     for(int x = settings.MaxDeep-5; x < 2; x++)
     {
         ui->widget_3->graph(0)->addData(x, settings.Sx(x));
     }
      ui->widget_3->replot();

      ui->widget_4->xAxis->setRange(0, 1440);
      ui->widget_4->yAxis->setRange(-2, 2);
      ui->widget_4->addGraph();
      for(int x = 0; x < 1440; x++)
      {
          ui->widget_4->graph(0)->addData(x, settings.St(x));
      }
       ui->widget_4->replot();

       ui->widget_5->xAxis->setRange(settings.MaxDeep-5, 5);
       ui->widget_5->yAxis->setRange(-2, 2);
       ui->widget_5->addGraph();
       for(int x = settings.MaxDeep-5; x < 2; x++)
       {
           ui->widget_5->graph(0)->addData(x, settings.G(x));
       }
        ui->widget_5->replot();
        N.settings = settings;
        ui->label_2->setText(QString::number(N.Fit(&A)));
        clock_t end = clock();
        double seconds = (double)(end - start) / CLOCKS_PER_SEC;
        ui->label_8->setText(QString::number(seconds));
}

void MainWindow::on_pushButton_2_clicked()
{
    std::string str;
    str = ui->lineEdit_2->text().toStdString();
    B = new NeuralNet(B->deserializeNeuralNet(str));
    Population.push_back(B);
    ui->SelectedNameLabel2->setText(QString::fromStdString(str));
    ui->CountNNi->setText(QString::number(Population.size()));
    ui->NameSelected->setText(QString::fromStdString(str));
}

void MainWindow::on_pushButton_3_clicked()
{
    srand(time(0));
    bool noise, dif;
    if(ui->checkBox->isChecked())
        noise = true;
    else
        noise = false;
    if(ui->checkBox_2->isChecked())
        dif = true;
    else
        dif = false;
    N.alpha_j = ui->AJ->text().toDouble();
    N.alpha_a = ui->AA->text().toDouble();
    N.beta_a = ui->BA->text().toDouble();
    N.beta_j = ui->BJ->text().toDouble();
    N.delta_a = ui->DA->text().toDouble();
    N.delta_j = ui->DJ->text().toDouble();
    N.gamma_a = ui->GA->text().toDouble();
    N.gamma_j = ui->GJ->text().toDouble();
    settings = Settings(ui->c1->text().toInt(), ui->lineEdit_9c2->text().toInt(), ui->lineEdit_10c3->text().toInt(), ui->eta1->text().toDouble(), ui->eta2->text().toDouble(),
                        ui->lineEdit_2xi1->text().toDouble(), ui->lineEdit_3xi2->text().toDouble(), ui->lineEdit_4x3->text().toDouble(), ui->lineEdit_5x4->text().toDouble(), noise, ui->lineEdit_11per->text().toDouble(), ui->lineEdit_2maxDeep->text().toInt(), dif);
    for(int i = 0; i < Population.size(); i++)
    {
    Population[i]->settings = settings;
    Population[i]->ProcessDay();
    }
    ui->widget_7->clearGraphs();
    ui->widget_7->xAxis->setRange(0, 1440);
    ui->widget_7->xAxis->setLabel("Минуты");
    ui->widget_7->yAxis->setRange(settings.MaxDeep-5, 10);
    ui->widget_7->yAxis->setLabel("Высота");
    int ii = 0;
    for(int i = 0; i < Population.size(); i++)
    {
    ui->widget_7->addGraph();
    for(int i = 0; i < 1440; i++)
    {
        ui->widget_7->graph(ii)->addData(i, A.migrationx1[i]);
    }
    ui->widget_7->graph(ii)->setPen(QPen(QColor(RandomVal(255), RandomVal(255), RandomVal(255))));
    ii++;
    ui->widget_7->addGraph();
    for(int i = 0; i < 1440; i++)
    {
        ui->widget_7->graph(ii)->addData(i, A.migrationx2[i]);
    }
    ui->widget_7->graph(ii)->setPen(QPen(QColor(RandomVal(255), RandomVal(255), RandomVal(255))));
    ii++;
    }
    ui->widget_7->replot();
    ui->widget_7->setInteraction(QCP::iRangeZoom, true);
    ui->widget_7->setInteraction(QCP::iRangeDrag, true);
    ui->widget_2->xAxis->setRange(settings.MaxDeep-5, 5);
    ui->widget_2->yAxis->setRange(-2, 2);
    ui->widget_2->addGraph();
    for(int x = settings.MaxDeep-5; x < 2; x++)
    {
        ui->widget_2->graph(0)->addData(x, settings.E(x));
    }
     ui->widget_2->replot();

     ui->widget_3->xAxis->setRange(settings.MaxDeep-5, 5);
     ui->widget_3->yAxis->setRange(-2, 2);
     ui->widget_3->addGraph();
     for(int x = settings.MaxDeep-5; x < 2; x++)
     {
         ui->widget_3->graph(0)->addData(x, settings.Sx(x));
     }
      ui->widget_3->replot();

      ui->widget_4->xAxis->setRange(0, 1440);
      ui->widget_4->yAxis->setRange(-2, 2);
      ui->widget_4->addGraph();
      for(int x = 0; x < 1440; x++)
      {
          ui->widget_4->graph(0)->addData(x, settings.St(x));
      }
       ui->widget_4->replot();

       ui->widget_5->xAxis->setRange(settings.MaxDeep-5, 5);
       ui->widget_5->yAxis->setRange(-2, 2);
       ui->widget_5->addGraph();
       for(int x = settings.MaxDeep-5; x < 2; x++)
       {
           ui->widget_5->graph(0)->addData(x, settings.G(x));
       }
        ui->widget_5->replot();
        N.settings = settings;
        double fit = 0;
        for(int i = 0; i < Population.size(); i++)
        {
        fit += N.Fit(Population[i]);
        }
        ui->jlabel2->setText(QString::number(fit));
}

void MainWindow::on_pushButton_4_clicked()
{
    settings.Col = true;
    bool noise, dif;
    if(ui->checkBox->isChecked())
        noise = true;
    else
        noise = false;
    if(ui->checkBox_2->isChecked())
        dif = true;
    else
        dif = false;
    N.alpha_j = ui->AJ->text().toDouble();
    N.alpha_a = ui->AA->text().toDouble();
    N.beta_a = ui->BA->text().toDouble();
    N.beta_j = ui->BJ->text().toDouble();
    N.delta_a = ui->DA->text().toDouble();
    N.delta_j = ui->DJ->text().toDouble();
    N.gamma_a = ui->GA->text().toDouble();
    N.gamma_j = ui->GJ->text().toDouble();
    settings = Settings(ui->c1->text().toInt(), ui->lineEdit_9c2->text().toInt(), ui->lineEdit_10c3->text().toInt(), ui->eta1->text().toDouble(), ui->eta2->text().toDouble(),
                        ui->lineEdit_2xi1->text().toDouble(), ui->lineEdit_3xi2->text().toDouble(), ui->lineEdit_4x3->text().toDouble(), ui->lineEdit_5x4->text().toDouble(), noise, ui->lineEdit_11per->text().toDouble(), ui->lineEdit_2maxDeep->text().toInt(), dif);
    int CDE = ui->line_CDE->text().toInt();
    Population = N.process(Population, CDE, settings);
    ui->widget_7->clearGraphs();
    ui->widget_7->xAxis->setRange(0, 1440);
    ui->widget_7->xAxis->setLabel("Минуты");
    ui->widget_7->yAxis->setRange(settings.MaxDeep-5, 10);
    ui->widget_7->yAxis->setLabel("Высота");
    int ii = 0;
    for(int i = 0; i < Population.size(); i++)
    {
    ui->widget_7->addGraph();
    for(int i = 0; i < 1440; i++)
    {
        ui->widget->graph(ii)->addData(i, A.migrationx1[i]);
    }
    ui->widget_7->graph(ii)->setPen(QPen(QColor(RandomVal(255), RandomVal(255), RandomVal(255))));
    ii++;
    ui->widget->addGraph();
    for(int i = 0; i < 1440; i++)
    {
        ui->widget->graph(ii)->addData(i, A.migrationx2[i]);
    }
    ui->widget_7->graph(ii)->setPen(QPen(QColor(RandomVal(255), RandomVal(255), RandomVal(255))));
    ii++;
    }
    ui->widget_7->replot();
    ui->widget_7->setInteraction(QCP::iRangeZoom, true);
    ui->widget_7->setInteraction(QCP::iRangeDrag, true);
    ui->widget_2->xAxis->setRange(settings.MaxDeep-5, 5);
    ui->widget_2->yAxis->setRange(-2, 2);
    ui->widget_2->addGraph();
    for(int x = settings.MaxDeep-5; x < 2; x++)
    {
        ui->widget_2->graph(0)->addData(x, settings.E(x));
    }
     ui->widget_2->replot();

     ui->widget_3->xAxis->setRange(settings.MaxDeep-5, 5);
     ui->widget_3->yAxis->setRange(-2, 2);
     ui->widget_3->addGraph();
     for(int x = settings.MaxDeep-5; x < 2; x++)
     {
         ui->widget_3->graph(0)->addData(x, settings.Sx(x));
     }
      ui->widget_3->replot();

      ui->widget_4->xAxis->setRange(0, 1440);
      ui->widget_4->yAxis->setRange(-2, 2);
      ui->widget_4->addGraph();
      for(int x = 0; x < 1440; x++)
      {
          ui->widget_4->graph(0)->addData(x, settings.St(x));
      }
       ui->widget_4->replot();

       ui->widget_5->xAxis->setRange(settings.MaxDeep-5, 5);
       ui->widget_5->yAxis->setRange(-2, 2);
       ui->widget_5->addGraph();
       for(int x = settings.MaxDeep-5; x < 2; x++)
       {
           ui->widget_5->graph(0)->addData(x, settings.G(x));
       }
        ui->widget_5->replot();
        N.settings = settings;
        double fit = 0;
        for(int i = 0; i < Population.size(); i++)
        {
        fit += N.Fit(Population[i]);
        }
        ui->jlabel2->setText(QString::number(fit));
}
