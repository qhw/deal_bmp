/********************************************************************************
** Form generated from reading UI file 'SplitDialog.ui'
**
** Created: Fri Sep 2 16:19:43 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPLITDIALOG_H
#define UI_SPLITDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UiSplitDialog
{
public:
    QPushButton *ok_btn;
    QLabel *label_2;
    QLineEdit *path_edit;
    QPushButton *open_btn;
    QGroupBox *groupBox;
    QRadioButton *radio_method1_btn;
    QRadioButton *radio_method2_btn;
    QRadioButton *radio_method3_btn;
    QGroupBox *groupBox_4;
    QComboBox *grey_combox;
    QCheckBox *grey_box;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QCheckBox *geometry_box;
    QLabel *label_6;
    QSpinBox *row_spinbox;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_3;
    QSpinBox *height_spinbox;
    QSpinBox *width_spinbox;
    QSpinBox *col_spinbox;
    QGroupBox *groupBox_3;
    QCheckBox *rgb_box;

    void setupUi(QDialog *UiSplitDialog)
    {
        if (UiSplitDialog->objectName().isEmpty())
            UiSplitDialog->setObjectName(QString::fromUtf8("UiSplitDialog"));
        UiSplitDialog->resize(370, 380);
        UiSplitDialog->setMinimumSize(QSize(370, 380));
        UiSplitDialog->setMaximumSize(QSize(370, 380));
        ok_btn = new QPushButton(UiSplitDialog);
        ok_btn->setObjectName(QString::fromUtf8("ok_btn"));
        ok_btn->setEnabled(false);
        ok_btn->setGeometry(QRect(277, 340, 75, 23));
        ok_btn->setMinimumSize(QSize(75, 23));
        ok_btn->setMaximumSize(QSize(75, 23));
        label_2 = new QLabel(UiSplitDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 31, 16));
        path_edit = new QLineEdit(UiSplitDialog);
        path_edit->setObjectName(QString::fromUtf8("path_edit"));
        path_edit->setGeometry(QRect(50, 10, 271, 20));
        open_btn = new QPushButton(UiSplitDialog);
        open_btn->setObjectName(QString::fromUtf8("open_btn"));
        open_btn->setGeometry(QRect(330, 10, 30, 23));
        open_btn->setMinimumSize(QSize(30, 23));
        open_btn->setMaximumSize(QSize(30, 23));
        open_btn->setSizeIncrement(QSize(30, 23));
        open_btn->setBaseSize(QSize(30, 20));
        groupBox = new QGroupBox(UiSplitDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 40, 341, 111));
        groupBox->setCheckable(false);
        radio_method1_btn = new QRadioButton(groupBox);
        radio_method1_btn->setObjectName(QString::fromUtf8("radio_method1_btn"));
        radio_method1_btn->setEnabled(false);
        radio_method1_btn->setGeometry(QRect(80, 20, 191, 16));
        radio_method1_btn->setCheckable(true);
        radio_method1_btn->setChecked(true);
        radio_method2_btn = new QRadioButton(groupBox);
        radio_method2_btn->setObjectName(QString::fromUtf8("radio_method2_btn"));
        radio_method2_btn->setEnabled(false);
        radio_method2_btn->setGeometry(QRect(80, 50, 191, 16));
        radio_method3_btn = new QRadioButton(groupBox);
        radio_method3_btn->setObjectName(QString::fromUtf8("radio_method3_btn"));
        radio_method3_btn->setEnabled(false);
        radio_method3_btn->setGeometry(QRect(80, 80, 191, 16));
        groupBox_4 = new QGroupBox(UiSplitDialog);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 290, 341, 41));
        grey_combox = new QComboBox(groupBox_4);
        grey_combox->setObjectName(QString::fromUtf8("grey_combox"));
        grey_combox->setEnabled(false);
        grey_combox->setGeometry(QRect(190, 10, 69, 22));
        grey_box = new QCheckBox(groupBox_4);
        grey_box->setObjectName(QString::fromUtf8("grey_box"));
        grey_box->setEnabled(false);
        grey_box->setGeometry(QRect(80, 10, 71, 16));
        groupBox_2 = new QGroupBox(UiSplitDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 150, 341, 101));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(89, 38, 181, 51));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        geometry_box = new QCheckBox(groupBox_2);
        geometry_box->setObjectName(QString::fromUtf8("geometry_box"));
        geometry_box->setEnabled(false);
        geometry_box->setGeometry(QRect(79, 8, 71, 16));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(177, 40, 27, 20));
        row_spinbox = new QSpinBox(groupBox_2);
        row_spinbox->setObjectName(QString::fromUtf8("row_spinbox"));
        row_spinbox->setEnabled(false);
        row_spinbox->setGeometry(QRect(123, 67, 48, 20));
        row_spinbox->setMinimum(1);
        row_spinbox->setMaximum(9999);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(177, 67, 21, 20));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(90, 67, 27, 20));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 40, 27, 20));
        height_spinbox = new QSpinBox(groupBox_2);
        height_spinbox->setObjectName(QString::fromUtf8("height_spinbox"));
        height_spinbox->setEnabled(false);
        height_spinbox->setGeometry(QRect(210, 67, 51, 20));
        height_spinbox->setMinimum(1);
        height_spinbox->setMaximum(99999);
        width_spinbox = new QSpinBox(groupBox_2);
        width_spinbox->setObjectName(QString::fromUtf8("width_spinbox"));
        width_spinbox->setEnabled(false);
        width_spinbox->setGeometry(QRect(210, 40, 51, 20));
        width_spinbox->setMinimum(1);
        width_spinbox->setMaximum(99999);
        col_spinbox = new QSpinBox(groupBox_2);
        col_spinbox->setObjectName(QString::fromUtf8("col_spinbox"));
        col_spinbox->setEnabled(false);
        col_spinbox->setGeometry(QRect(123, 40, 48, 20));
        col_spinbox->setMinimum(1);
        col_spinbox->setMaximum(9999);
        groupBox_3 = new QGroupBox(UiSplitDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 250, 341, 41));
        rgb_box = new QCheckBox(groupBox_3);
        rgb_box->setObjectName(QString::fromUtf8("rgb_box"));
        rgb_box->setEnabled(false);
        rgb_box->setGeometry(QRect(80, 10, 71, 16));

        retranslateUi(UiSplitDialog);
        QObject::connect(grey_box, SIGNAL(toggled(bool)), grey_combox, SLOT(setEnabled(bool)));
        QObject::connect(geometry_box, SIGNAL(toggled(bool)), row_spinbox, SLOT(setEnabled(bool)));
        QObject::connect(geometry_box, SIGNAL(toggled(bool)), col_spinbox, SLOT(setEnabled(bool)));
        QObject::connect(rgb_box, SIGNAL(toggled(bool)), grey_box, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(UiSplitDialog);
    } // setupUi

    void retranslateUi(QDialog *UiSplitDialog)
    {
        UiSplitDialog->setWindowTitle(QApplication::translate("UiSplitDialog", "\345\233\276\347\211\207\345\210\206\345\211\262\345\261\236\346\200\247\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        ok_btn->setText(QApplication::translate("UiSplitDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("UiSplitDialog", "\345\233\276\347\211\207\357\274\232", 0, QApplication::UnicodeUTF8));
        open_btn->setText(QApplication::translate("UiSplitDialog", "...", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("UiSplitDialog", "\345\244\204\347\220\206\351\241\272\345\272\217", 0, QApplication::UnicodeUTF8));
        radio_method1_btn->setText(QApplication::translate("UiSplitDialog", "\345\207\240\344\275\225\345\210\206\345\211\262->rgb\345\210\206\347\246\273->\347\201\260\345\272\246\345\210\206\347\246\273", 0, QApplication::UnicodeUTF8));
        radio_method2_btn->setText(QApplication::translate("UiSplitDialog", "rgb\345\210\206\347\246\273->\345\207\240\344\275\225\345\210\206\345\211\262->\347\201\260\345\272\246\345\210\206\347\246\273", 0, QApplication::UnicodeUTF8));
        radio_method3_btn->setText(QApplication::translate("UiSplitDialog", "rgb\345\210\206\347\246\273->\347\201\260\345\272\246\345\210\206\347\246\273->\345\207\240\344\275\225\345\210\206\345\211\262", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QString());
        grey_combox->clear();
        grey_combox->insertItems(0, QStringList()
         << QApplication::translate("UiSplitDialog", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UiSplitDialog", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UiSplitDialog", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UiSplitDialog", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UiSplitDialog", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UiSplitDialog", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UiSplitDialog", "7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("UiSplitDialog", "8", 0, QApplication::UnicodeUTF8)
        );
        grey_box->setText(QApplication::translate("UiSplitDialog", "\347\201\260\351\230\266", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        geometry_box->setText(QApplication::translate("UiSplitDialog", "\345\207\240\344\275\225", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("UiSplitDialog", "\345\256\275\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("UiSplitDialog", "\351\253\230\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("UiSplitDialog", "\345\210\227\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("UiSplitDialog", "\350\241\214\357\274\232", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QString());
        rgb_box->setText(QApplication::translate("UiSplitDialog", "RGB\351\200\232\351\201\223", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UiSplitDialog: public Ui_UiSplitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPLITDIALOG_H
