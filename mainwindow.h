#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <QPixmap>
#include <QColorDialog>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QGridLayout *gridLayout;

public slots:
    void setInfo();
    void newR();
    void newG();
    void newB();
    void newSlider();
    void identFirst(QString);
    void identSecond(QString);
    void identThird (QString);
    void newLFirst();
    void newLSecond();
    void newLThird();
    void newLFourth();
    void newCFirst();
    void newCSecond();
    void newCThird();
    void newCFourth();
    void newRFirst();
    void newRSecond();
    void newRThird();
    void newRFourth();
    void onPallete();

private:
    QComboBox *combFirst;
    QComboBox *combSecond;
    QComboBox *combThird;
    QStringList strListFirst = {"CMYK", "HSV", "RGB", "XYZ"};
    QStringList strListSecond = {"CMYK", "RGB", "HSV", "HLS", "LAB", "XYZ"};
    QStringList strListThird = {"CMYK", "HLS", "HSV", "LAB", "RGB"};

    QLabel *colorPalette;
    QLabel *currColor;
    QSlider *slFirst;
    QSlider *slSecond;
    QSlider *slThird;

    QColorDialog *chooseColor;
    QPushButton *setColor;

    void convertQColor();
    void convertHLS();
    void convertLAB();
    void convertXYZ();

    QLineEdit *lineEdLeftFirst;
    QLineEdit *lineEdLeftSecond;
    QLineEdit *lineEdLeftThird;
    QLineEdit *lineEdLeftFourth;
    QLabel *labLeftFirst;
    QLabel *labLeftSecond;
    QLabel *labLeftThird;
    QLabel *labLeftFourth;

    QLineEdit *lineEdCenterFirst;
    QLineEdit *lineEdCenterSecond;
    QLineEdit *lineEdCenterThird;
    QLineEdit *lineEdCenterFourth;
    QLabel *labCenterFirst;
    QLabel *labCenterSecond;
    QLabel *labCenterThird;
    QLabel *labCenterFourth;

    QLineEdit *lineEdRightFirst;
    QLineEdit *lineEdRightSecond;
    QLineEdit *lineEdRightThird;
    QLineEdit *lineEdRightFourth;
    QLabel *labRightFirst;
    QLabel *labRightSecond;
    QLabel *labRightThird;
    QLabel *labRightFourth;
};
#endif // WIDGET_H
