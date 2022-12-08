#include "mainwindow.h"
#include <QDoubleValidator>
QColor main_color;
double Xyz,xYz,xyZ,
       Lab,lAb,laB;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    gridLayout = new QGridLayout(this);
    qApp->installEventFilter(this);
    gridLayout->setAlignment(Qt::AlignCenter);
    setMinimumSize(800, 600);
    setMaximumSize(800, 600);
    QDoubleValidator* validator =  new QDoubleValidator( -1000.0, 1000.0, 4 );
    combFirst = new QComboBox();
    combSecond = new QComboBox();
    combThird = new QComboBox();
    setColor = new QPushButton();
    setColor->setText("Choose color from palette");
    combFirst->addItems(strListFirst);
    combSecond->addItems(strListSecond);
    combThird->addItems(strListThird);
    combFirst->setCurrentIndex(-1);
    combSecond->setCurrentIndex(-1);
    combThird->setCurrentIndex(-1);

    colorPalette = new QLabel(this);
    gridLayout->addWidget(colorPalette, 6, 2, 2, 7);
    colorPalette->setStyleSheet("QLabel{background-color:rgb(0,0,0);border:0px solid black;}");
    colorPalette->setAlignment(Qt::AlignCenter);
    colorPalette->setMinimumSize(100,100);
    colorPalette->setMaximumSize(100,100);

    gridLayout->addWidget(combFirst,0,2,1,2);
    gridLayout->addWidget(combSecond,0,4,1,2);
    gridLayout->addWidget(combThird,0,6,1,2);

    currColor = new QLabel("Choosen color:");
    gridLayout->addWidget(currColor,6,1);
    gridLayout->addWidget(setColor, 6, 5);

    labLeftFirst = new QLabel("R:");
    labLeftSecond = new QLabel("G:");
    labLeftThird = new QLabel("B:");
    labLeftFourth = new QLabel("");
    labCenterFirst = new QLabel("C:");
    labCenterSecond = new QLabel("M:");
    labCenterThird = new QLabel("Y:");
    labCenterFourth = new QLabel("K:");
    labRightFirst = new QLabel("L:");
    labRightSecond = new QLabel("A:");
    labRightThird = new QLabel("B:");
    labRightFourth = new QLabel("");

    lineEdLeftFirst = new QLineEdit(this);
    lineEdLeftSecond = new QLineEdit(this);
    lineEdLeftThird = new QLineEdit(this);
    lineEdLeftFourth = new QLineEdit(this);
    lineEdCenterFirst = new QLineEdit(this);
    lineEdCenterSecond = new QLineEdit(this);
    lineEdCenterThird = new QLineEdit(this);
    lineEdCenterFourth = new QLineEdit(this);
    lineEdRightFirst = new QLineEdit(this);
    lineEdRightSecond = new QLineEdit(this);
    lineEdRightThird = new QLineEdit(this);
    lineEdRightFourth = new QLineEdit(this);
    lineEdLeftFirst->setValidator(validator);
    lineEdLeftSecond->setValidator(validator);
    lineEdLeftThird->setValidator(validator);
    lineEdLeftFourth->setValidator(validator);
    lineEdCenterFirst->setValidator(validator);
    lineEdCenterSecond->setValidator(validator);
    lineEdCenterThird->setValidator(validator);
    lineEdCenterFourth->setValidator(validator);
    lineEdRightFirst->setValidator(validator);
    lineEdRightSecond->setValidator(validator);
    lineEdRightThird->setValidator(validator);
    lineEdRightFourth->setValidator(validator);

    slFirst = new QSlider(this);
    slSecond = new QSlider(this);
    slThird = new QSlider(this);
    slFirst->setOrientation(Qt::Horizontal);
    slSecond->setOrientation(Qt::Horizontal);
    slThird->setOrientation(Qt::Horizontal);
    slFirst->setRange(0, 255);
    slSecond->setRange(0, 255);
    slThird->setRange(0, 255);

    gridLayout->addWidget(slFirst, 1, 2, 1, 2);
    gridLayout->addWidget(slSecond, 1, 4, 1, 2);
    gridLayout->addWidget(slThird, 1, 6, 1, 2);
    gridLayout->addWidget(labLeftFirst, 2,2);
    gridLayout->addWidget(lineEdLeftFirst, 2,3);
    gridLayout->addWidget(labLeftSecond, 3, 2);
    gridLayout->addWidget(lineEdLeftSecond, 3,3);
    gridLayout->addWidget(labLeftThird, 4, 2);
    gridLayout->addWidget(lineEdLeftThird, 4,3);
    gridLayout->addWidget(labLeftFourth, 5, 2);
    gridLayout->addWidget(lineEdLeftFourth, 5,3);
    gridLayout->addWidget(labCenterFirst, 2,4);
    gridLayout->addWidget(lineEdCenterFirst, 2,5);
    gridLayout->addWidget(labCenterSecond, 3, 4);
    gridLayout->addWidget(lineEdCenterSecond, 3,5);
    gridLayout->addWidget(labCenterThird, 4, 4);
    gridLayout->addWidget(lineEdCenterThird, 4,5);
    gridLayout->addWidget(labCenterFourth, 5, 4);
    gridLayout->addWidget(lineEdCenterFourth, 5,5);
    gridLayout->addWidget(labRightFirst, 2,6);
    gridLayout->addWidget(lineEdRightFirst, 2,7);
    gridLayout->addWidget(labRightSecond, 3, 6);
    gridLayout->addWidget(lineEdRightSecond, 3,7);
    gridLayout->addWidget(labRightThird, 4, 6);
    gridLayout->addWidget(lineEdRightThird, 4,7);
    gridLayout->addWidget(labRightFourth, 5, 6);
    gridLayout->addWidget(lineEdRightFourth, 5,7);

    combFirst->setCurrentText("RGB");
    combSecond->setCurrentText("CMYK");
    combThird->setCurrentText("LAB");
    identFirst("RGB");
    identSecond("CMYK");
    identThird("LAB");
    setLayout(gridLayout);

    connect(setColor,SIGNAL(clicked()),this,SLOT(onPallete()));

    connect(slFirst, SIGNAL(valueChanged(int)), this, SLOT(newR()));
    connect(slSecond, SIGNAL(valueChanged(int)), this, SLOT(newR()));
    connect(slThird, SIGNAL(valueChanged(int)), this, SLOT(newR()));

    connect(combFirst,SIGNAL(currentTextChanged(QString)),this,SLOT(identFirst(QString)));
    connect(combSecond,SIGNAL(currentTextChanged(QString)),this,SLOT(identSecond(QString)));
    connect(combThird,SIGNAL(currentTextChanged(QString)),this,SLOT(identThird(QString)));

    connect(lineEdLeftFirst, SIGNAL(editingFinished()), this, SLOT(newLFirst()));
    connect(lineEdLeftSecond, SIGNAL(editingFinished()), this, SLOT(newLSecond()));
    connect(lineEdLeftThird, SIGNAL(editingFinished()), this, SLOT(newLThird()));
    connect(lineEdLeftFourth, SIGNAL(editingFinished()), this, SLOT(newLFourth()));
    connect(lineEdCenterFirst, SIGNAL(editingFinished()), this, SLOT(newCFirst()));
    connect(lineEdCenterSecond, SIGNAL(editingFinished()), this, SLOT(newCSecond()));
    connect(lineEdCenterThird, SIGNAL(editingFinished()), this, SLOT(newCThird()));
    connect(lineEdCenterFourth, SIGNAL(editingFinished()), this, SLOT(newCFourth()));
    connect(lineEdRightFirst, SIGNAL(editingFinished()), this, SLOT(newRFirst()));
    connect(lineEdRightSecond, SIGNAL(editingFinished()), this, SLOT(newRSecond()));
    connect(lineEdRightThird, SIGNAL(editingFinished()), this, SLOT(newRThird()));
    connect(lineEdRightFourth, SIGNAL(editingFinished()), this, SLOT(newRFourth()));

    connect(slFirst, SIGNAL(valueChanged(int)), this, SLOT(newSlider()));
    connect(slSecond, SIGNAL(valueChanged(int)), this, SLOT(newSlider()));
    connect(slThird, SIGNAL(valueChanged(int)), this, SLOT(newSlider()));
}

Widget::~Widget()
{
}

void Widget::identFirst(QString str)
{
    lineEdLeftFourth->hide();
    if (str == "RGB") {
        labLeftFirst->setText("R:");
        labLeftSecond->setText("G:");
        labLeftThird->setText("B:");
        labLeftFourth->setText("");
    }else if (str == "HSV") {
        labLeftFirst->setText("H:");
        labLeftSecond->setText("S:");
        labLeftThird->setText("V:");
        labLeftFourth->setText("");
    }else if (str == "XYZ") {
        labLeftFirst->setText("X:");
        labLeftSecond->setText("Y:");
        labLeftThird->setText("Z:");
        labLeftFourth->setText("");
    }else if (str == "CMYK") {
        labLeftFirst->setText("C:");
        labLeftSecond->setText("M:");
        labLeftThird->setText("Y:");
        labLeftFourth->setText("K:");
        lineEdLeftFourth->show();
    }
    setInfo();
}

void Widget::identSecond(QString str)
{
    lineEdCenterFourth->hide();
    if (str == "CMYK") {
        labCenterFirst->setText("C:");
        labCenterSecond->setText("M:");
        labCenterThird->setText("Y:");
        labCenterFourth->setText("K:");
        lineEdCenterFourth->show();
    }else if (str == "HLS") {
        labCenterFirst->setText("H:");
        labCenterSecond->setText("L:");
        labCenterThird->setText("S:");
        labCenterFourth->setText("");
    }else if (str == "HSV") {
        labCenterFirst->setText("H:");
        labCenterSecond->setText("S:");
        labCenterThird->setText("V:");
        labCenterFourth->setText("");
    }else if (str == "LAB") {
        labCenterFirst->setText("L:");
        labCenterSecond->setText("A:");
        labCenterThird->setText("B:");
        labCenterFourth->setText("");
    }else if (str == "RGB") {
        labCenterFirst->setText("R:");
        labCenterSecond->setText("G:");
        labCenterThird->setText("B:");
        labCenterFourth->setText("");
    }else if (str == "XYZ") {
        labCenterFirst->setText("X:");
        labCenterSecond->setText("Y:");
        labCenterThird->setText("Z:");
        labCenterFourth->setText("");
    }
    setInfo();
}

void Widget::identThird(QString str)
{
    lineEdRightFourth->hide();
    if (str == "CMYK") {
        labRightFirst->setText("C:");
        labRightSecond->setText("M:");
        labRightThird->setText("Y:");
        labRightFourth->setText("K:");
        lineEdRightFourth->show();
    }else if (str == "HLS") {
        labRightFirst->setText("H:");
        labRightSecond->setText("L:");
        labRightThird->setText("S:");
        labRightFourth->setText("");
    }else if (str == "HSV") {
        labRightFirst->setText("H:");
        labRightSecond->setText("S:");
        labRightThird->setText("V:");
        labRightFourth->setText("");
    }else if (str == "LAB") {
        labRightFirst->setText("L:");
        labRightSecond->setText("A:");
        labRightThird->setText("B:");
        labRightFourth->setText("");
    }else if (str == "RGB") {
        labRightFirst->setText("R:");
        labRightSecond->setText("G:");
        labRightThird->setText("B:");
        labRightFourth->setText("");
    }
    setInfo();
}

void Widget::newLFirst()
{
    if (labLeftFirst->text() == "C:") {
        main_color.setCmyk(lineEdLeftFirst->text().toInt(), main_color.magenta(), main_color.yellow(), main_color.black());
        convertQColor();
    } else if (labLeftFirst->text() == "H:") {
        main_color.setHsv(lineEdLeftFirst->text().toInt(), main_color.saturation(), main_color.value());
        convertQColor();
    } else if (labLeftFirst->text() == "R:") {
        main_color.setRed(lineEdLeftFirst->text().toInt());
        convertQColor();
    } else if (labLeftFirst->text() == "X:") {
        Xyz = lineEdLeftFirst->text().toDouble();
        convertXYZ();
    }
    setInfo();
    newSlider();
}

void Widget::newLSecond()
{
    if (labLeftSecond->text() == "G:") {
        main_color.setGreen(lineEdLeftSecond->text().toInt());
        convertQColor();
    } else if (labLeftSecond->text() == "M:") {
        main_color.setCmyk(main_color.cyan(), lineEdLeftSecond->text().toInt(), main_color.yellow(), main_color.black());
        convertQColor();
    } else if (labLeftSecond->text() == "S:") {
        main_color.setHsv(main_color.hue(), lineEdLeftSecond->text().toInt(), main_color.value());
        convertQColor();
    } else if (combSecond->currentText() == "XYZ") {
        xYz = lineEdLeftSecond->text().toDouble();
        convertXYZ();
    }
    setInfo();
    newSlider();
}

void Widget::newLThird()
{
    if (labLeftThird->text() == "B:") {
        main_color.setBlue(lineEdLeftThird->text().toInt());
        convertQColor();
    } else if (labLeftThird->text() == "V:") {
        main_color.setHsv(main_color.hue(), main_color.saturation(), lineEdLeftThird->text().toInt());
        convertQColor();
    } else if (labLeftThird->text() == "Y:") {
        main_color.setCmyk(main_color.cyan(), main_color.magenta(), lineEdLeftThird->text().toInt(), main_color.black());
        convertQColor();
    } else if (labLeftThird->text() == "Z:") {
        xyZ = lineEdLeftThird->text().toDouble();
        convertXYZ();
    }
    setInfo();
    newSlider();
}

void Widget::newLFourth()
{
    main_color.setCmyk(main_color.cyan(), main_color.magenta(), main_color.yellow(), lineEdLeftFourth->text().toInt());
    convertQColor();
    setInfo();
    newSlider();
}

void Widget::newCFirst()
{
    if (combSecond->currentText() == "CMYK") {
            main_color.setCmyk(lineEdCenterFirst->text().toInt(), main_color.magenta(), main_color.yellow(), main_color.black());
            convertQColor();
    } else if (combSecond->currentText() == "LAB") {
        Lab = lineEdCenterFirst->text().toDouble();
        convertLAB();
    } else if (combSecond->currentText() == "HSV") {
        main_color.setHsv(lineEdCenterFirst->text().toInt(), main_color.saturation(), main_color.value());
        convertQColor();
    } else if (combSecond->currentText() == "HLS") {
        main_color.setHsl(lineEdCenterFirst->text().toDouble(), main_color.lightness(), main_color.hslSaturation());
        convertQColor();
    } else if (labCenterFirst->text() == "R:") {
        main_color.setRed(lineEdCenterFirst->text().toInt());
        convertQColor();
    }else if (labCenterFirst->text() == "X:") {
        Xyz = lineEdCenterFirst->text().toDouble();
        convertXYZ();
    }
    setInfo();
    newSlider();
}

void Widget::newCSecond()
{
    if (labCenterSecond->text() == "G:") {
        main_color.setGreen(lineEdCenterSecond->text().toInt());
        convertQColor();
    } else if (combSecond->currentText() == "HLS") {
        main_color.setHsl(main_color.hslHue(), lineEdCenterSecond->text().toDouble(), main_color.hslSaturation());
        convertQColor();
    } else if (combSecond->currentText() == "HSV") {
        main_color.setHsv(main_color.hue(), lineEdCenterSecond->text().toInt(), main_color.value());
        convertQColor();
    } else if (combSecond->currentText() == "LAB") {
        lAb = lineEdCenterSecond->text().toDouble();
        convertLAB();
    } else if (labCenterSecond->text() == "M:") {
        main_color.setCmyk(main_color.cyan(),lineEdCenterSecond->text().toInt(),  main_color.yellow(), main_color.black());
        convertQColor();
    } else if (labCenterSecond->text() == "Y:") {
        xYz = lineEdCenterSecond->text().toDouble();
        convertXYZ();
    }
    setInfo();
    newSlider();
}

void Widget::newCThird()
{
    if (combSecond->currentText() == "CMYK") {
        main_color.setCmyk(main_color.cyan(), main_color.magenta(), lineEdCenterThird->text().toInt(), main_color.black());
        convertQColor();
    } else if (combSecond->currentText() == "HLS") {
        main_color.setHsl(main_color.hslHue(), main_color.lightness(), lineEdRightThird->text().toDouble());
        convertQColor();
    } else if (combSecond->currentText() == "HSV") {
        main_color.setHsv(main_color.hue(), main_color.saturation(), lineEdCenterThird->text().toInt());
        convertQColor();
    } else if (combSecond->currentText() == "LAB") {
        laB = lineEdCenterThird->text().toDouble();
        convertLAB();
    } else if (combSecond->currentText() == "RGB") {
        main_color.setBlue(lineEdCenterThird->text().toInt());
        convertQColor();
    } else if (combSecond->currentText() == "XYZ") {
        xyZ = lineEdCenterThird->text().toDouble();
        convertXYZ();
    }
    setInfo();
    newSlider();
}

void Widget::newCFourth()
{
    main_color.setCmyk(main_color.cyan(), main_color.magenta(), main_color.yellow(), lineEdCenterFourth->text().toInt());
    convertQColor();
    setInfo();
    newSlider();
}

void Widget::newRFirst()
{
    if (combThird->currentText() == "CMYK") {
        main_color.setCmyk(lineEdRightFirst->text().toInt(), main_color.magenta(), main_color.yellow(), main_color.black());
        convertQColor();
    } else if (combThird->currentText() == "HLS") { // H
        main_color.setHsl(lineEdRightFirst->text().toDouble(), main_color.lightness(), main_color.hslHue());
        convertQColor();
    } else if (combThird->currentText() == "HSV") {
        main_color.setHsv(lineEdRightFirst->text().toInt(), main_color.saturation(), main_color.value());
        convertQColor();
    } else if (combThird->currentText() == "LAB") {
        Lab = lineEdRightFirst->text().toDouble();
        convertLAB();
    } else if (combThird->currentText() == "RGB") {
        main_color.setRed(lineEdRightFirst->text().toInt());
        convertQColor();
    }
    setInfo();
    newSlider();
}

void Widget::newRSecond()
{
    if (combThird->currentText() == "CMYK") {
        main_color.setCmyk(main_color.cyan(),lineEdRightSecond->text().toInt(),  main_color.yellow(), main_color.black());
        convertQColor();
    } else if (combThird->currentText() == "HLS") {
        main_color.setHsl(main_color.hslHue(), lineEdRightSecond->text().toDouble(), main_color.hslSaturation());
        convertQColor();
    } else if (combThird->currentText() == "LAB") {
        lAb = lineEdRightSecond->text().toDouble();
        convertLAB();
    } else if (combThird->currentText() == "HSV") {
        main_color.setHsv(main_color.hue(),lineEdRightFirst->text().toInt(),  main_color.value());
        convertQColor();
    } else if (combThird->currentText() == "RGB") {
        main_color.setGreen(lineEdRightSecond->text().toInt());
        convertQColor();
    }
    setInfo();
    newSlider();

}

void Widget::newRThird()
{
    if (combThird->currentText() == "CMYK") {
        main_color.setCmyk(main_color.cyan(),  main_color.magenta(),lineEdRightThird->text().toInt(), main_color.black());
        convertQColor();
    } else if (combThird->currentText() == "HLS") {
        main_color.setHsl(main_color.hslHue(), main_color.lightness(), lineEdRightThird->text().toInt());
        convertQColor();
    } else if (combThird->currentText() == "LAB") {
        laB = lineEdRightThird->text().toDouble();
        convertLAB();
    } else if (combThird->currentText() == "HSV") {
        main_color.setHsv(main_color.hue(), main_color.saturation(), lineEdRightSecond->text().toDouble());
        convertQColor();
    } else if (combThird->currentText() == "RGB") {
        main_color.setBlue(lineEdRightThird->text().toInt());
        convertQColor();
    }
    setInfo();
    newSlider();
}

void Widget::newRFourth()
{
    main_color.setCmyk(main_color.cyan(), main_color.magenta(), main_color.yellow(), lineEdRightFourth->text().toInt());
    convertQColor();
    setInfo();
    newSlider();
}

void Widget::onPallete()
{
    QColorDialog dlg(this);

            dlg.setWindowTitle("Color Editor");
            dlg.setCurrentColor (QColor (100, 111, 222));

            if( dlg.exec() == QColorDialog::Accepted )
            {
                QColor color = dlg.selectedColor();
                main_color.setRed(color.red());
                main_color.setGreen(color.green());
                main_color.setBlue(color.blue());
                convertQColor();
                QString r = QString::number(main_color.red());
                QString g = QString::number(main_color.green());
                QString b = QString::number(main_color.blue());
                colorPalette->setStyleSheet("QLabel{background-color:rgb("+r+","+g+","+b+");}");
                setInfo();
                newSlider();
            }
}

void Widget::setInfo()
{
    if (combFirst->currentText() == "CMYK") {
        lineEdLeftFirst -> setText(QString::number(main_color.cyan()));
        lineEdLeftSecond->setText(QString::number(main_color.magenta()));
        lineEdLeftThird->setText(QString::number(main_color.yellow()));
        lineEdLeftFourth->setText(QString::number(main_color.black()));
    } else if (combFirst->currentText() == "HSV") {
        lineEdLeftFirst->setText(QString::number(main_color.hue()));
        lineEdLeftSecond->setText(QString::number(main_color.saturationF()));
        lineEdLeftThird->setText(QString::number(main_color.valueF()));
    } else if (combFirst->currentText() == "RGB") {
        lineEdLeftFirst->setText(QString::number(main_color.red()));
        lineEdLeftSecond->setText(QString::number(main_color.green()));
        lineEdLeftThird->setText(QString::number(main_color.blue()));
    } else if (combFirst->currentText() == "XYZ") {
        lineEdLeftFirst -> setText(QString::number(Xyz));
        lineEdLeftSecond -> setText(QString::number(xYz));
        lineEdLeftThird -> setText(QString::number(xyZ));
    }


    if (combSecond->currentText() == "CMYK") {
        lineEdCenterFirst -> setText(QString::number(main_color.cyan()));
        lineEdCenterSecond->setText(QString::number(main_color.magenta()));
        lineEdCenterThird->setText(QString::number(main_color.yellow()));
        lineEdCenterFourth->setText(QString::number(main_color.black()));
    } else if (combSecond->currentText() == "HLS") {
        lineEdCenterFirst->setText(QString::number(main_color.hslHue()));
        lineEdCenterSecond->setText(QString::number(main_color.lightness()));
        lineEdCenterThird->setText(QString::number(main_color.hslSaturation()));
    } else if (combSecond->currentText() == "HSV") {
        lineEdCenterFirst->setText(QString::number(main_color.hue()));
        lineEdCenterSecond->setText(QString::number(main_color.saturationF()));
        lineEdCenterThird->setText(QString::number(main_color.valueF()));
    } else if (combSecond->currentText() == "LAB") {
        lineEdCenterFirst -> setText(QString::number(Lab));
        lineEdCenterSecond->setText(QString::number(lAb));
        lineEdCenterThird->setText(QString::number(laB));
    } else if (combSecond->currentText() == "RGB") {
        lineEdCenterFirst->setText(QString::number(main_color.red()));
        lineEdCenterSecond->setText(QString::number(main_color.green()));
        lineEdCenterThird->setText(QString::number(main_color.blue()));
    } else if (combSecond->currentText() == "XYZ") {
        lineEdCenterFirst -> setText(QString::number(Xyz));
        lineEdCenterSecond -> setText(QString::number(xYz));
        lineEdCenterThird -> setText(QString::number(xyZ));
    }


    if (combThird->currentText() == "CMYK") {
        lineEdRightFirst->setText(QString::number(main_color.cyan()));
        lineEdRightSecond->setText(QString::number(main_color.magenta()));
        lineEdRightThird->setText(QString::number(main_color.yellow()));
        lineEdRightFourth->setText(QString::number(main_color.black()));
    } else if (combThird->currentText() == "HLS") {
        lineEdRightFirst->setText(QString::number(main_color.hslHue()));
        lineEdRightSecond->setText(QString::number(main_color.lightness()));
        lineEdRightThird->setText(QString::number(main_color.hslSaturation()));
    } else if (combThird->currentText() == "HSV") {
        lineEdRightFirst->setText(QString::number(main_color.hue()));
        lineEdRightSecond->setText(QString::number(main_color.saturationF()));
        lineEdRightThird->setText(QString::number(main_color.valueF()));
    } else if (combThird->currentText() == "LAB") {
        lineEdRightFirst -> setText(QString::number(Lab));
        lineEdRightSecond->setText(QString::number(lAb));
        lineEdRightThird->setText(QString::number(laB));
    } else if (combThird->currentText() == "RGB") {
        lineEdRightFirst->setText(QString::number(main_color.red()));
        lineEdRightSecond->setText(QString::number(main_color.green()));
        lineEdRightThird->setText(QString::number(main_color.blue()));
    }
}

void Widget::newR()
{
    main_color.setRed(slFirst->value());
    main_color.setGreen(slSecond->value());
    main_color.setBlue(slThird->value());
    convertQColor();
    QString r = QString::number(main_color.red());
    QString g = QString::number(main_color.green());
    QString b = QString::number(main_color.blue());
    colorPalette->setStyleSheet("QLabel{background-color:rgb("+r+","+g+","+b+");}");
    setInfo();
}

void Widget::newG()
{
    QString g = QString::number(slSecond->value());
}

void Widget::newB()
{
    QString b = QString::number(slSecond->value());
}

void Widget::newSlider()
{
    slFirst->setValue(main_color.red());
    slSecond->setValue(main_color.green());
    slThird->setValue(main_color.blue());
}

double RGB_to_XYZ(double x) {
    if (x>=0.04045) {
        return pow((x+0.055)/1.055, 2.4);
    }
    return x/12.92;
}
double XYZ_to_LAB(double x) {
    if (x >= 0.008856) {
        return pow(x, 1.0/3.0);
    }
    return 7.787 * x + 16.0 /(double) 116.0;
}
double XYZ_to_RGB(double x) {
    if (abs(x)<0.0031308) {
        return 12.92 * x;
    }

    return 1.055 * pow(x, 0.41666) - 0.055;
}
double LAB_to_XYZ(double x) {
    if (pow(x,3)>=0.008856) {
        return pow(x,3);
    }
    return (x-16.0/116.0)/7.878;
}

void Widget::convertQColor() {
    Xyz = 0.412453*RGB_to_XYZ(main_color.red()/255.0)*100 + 0.357580 * RGB_to_XYZ(main_color.green()/255.0)*100 + 0.180423 * RGB_to_XYZ(main_color.blue()/255.0)*100;
    xYz = 0.212671*RGB_to_XYZ(main_color.red()/255.0)*100 + 0.715160 * RGB_to_XYZ(main_color.green()/255.0)*100 + 0.072169 * RGB_to_XYZ(main_color.blue()/255.0)*100;
    xyZ = 0.019334*RGB_to_XYZ(main_color.red()/255.0)*100 * 0.119193 * RGB_to_XYZ(main_color.green()/255.0)*100 + 0.950227 * RGB_to_XYZ(main_color.blue()/255.0)*100;
    Lab = 116 * XYZ_to_LAB(xYz / 100.0) - 16;
    lAb = 500 * (XYZ_to_LAB(Xyz / 95.047) - XYZ_to_LAB(xYz / 100.0));
    laB = 200 * (XYZ_to_LAB(xYz / 100.0) - XYZ_to_LAB(xyZ / 108.883));
}

void Widget::convertXYZ() {
    double Rn = 3.2404542 * Xyz / 100.0 - 1.5371385 * xYz/ 100.0  - 0.4985314 * xyZ/ 100.0 ;
    double Gn = -0.9692660 * Xyz / 100.0 + 1.8760108 * xYz/ 100.0  + 0.0415560 * xyZ/ 100.0 ;
    double Bn = 0.0556434 * Xyz / 100.0 - 0.2040259 * xYz/ 100.0  + 1.0572252 * xyZ/ 100.0 ;
    double R = XYZ_to_RGB(Rn) * 255;
    double G = XYZ_to_RGB(Gn) * 255;
    double B = XYZ_to_RGB(Bn) * 255;

    main_color.setRed(round(R));
    main_color.setGreen(round(G));
    main_color.setBlue(round(B));
    Lab = 116 * XYZ_to_LAB(xYz/(double) 100.0)-16;
    lAb = 500 * (XYZ_to_LAB(Xyz/95.047)-XYZ_to_LAB(xYz/(double) 100.0));
    laB = 200 * (XYZ_to_LAB(xYz/(double) 100.0)- XYZ_to_LAB(xyZ/(double) 108.883));

}

void Widget::convertLAB() {
    Xyz = LAB_to_XYZ(lAb/500.0+(LAB_to_XYZ(Lab)+16.0)/116.0) * 95.047;
    xYz = LAB_to_XYZ((Lab+16.0)/116.0) * 100.0;
    xyZ = LAB_to_XYZ((Lab+16.0)/116.0-laB/200) * 108.883;
    double Rn = 3.2406 * Xyz / 100 - 1.5372 * xYz / 100 - 0.4986 * xyZ / 100;
    double Gn = -0.9689 * Xyz / 100 + 1.8758 * xYz / 100 + 0.0415 * xyZ / 100;
    double Bn = 0.0557 * Xyz / 100 - 0.2040 * xYz / 100 + 1.0570 * xyZ / 100;
    main_color.setRed(round(XYZ_to_RGB(Rn)*255));
    main_color.setGreen(round(XYZ_to_RGB(Gn)*255));
    main_color.setBlue(round(XYZ_to_RGB(Bn)*255));
    setInfo();
}
