/********************************************************************************
** Form generated from reading UI file 'browsepicture.ui'
**
** Created: Fri Sep 2 16:19:44 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BROWSEPICTURE_H
#define UI_BROWSEPICTURE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BrowsePictureClass
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *open_btn;
    QPushButton *split_btn;
    QGridLayout *gridLayout_2;
    QPushButton *open_dir_btn;
    QLineEdit *dir_edit;
    QPushButton *auto_merge_btn;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_8;
    QSpinBox *row_spinbox;
    QLabel *label_14;
    QSpinBox *col_spinbox;
    QLabel *label_10;
    QSpinBox *grey_start_spinbox;
    QLabel *label;
    QSpinBox *grey_end_spinbox;
    QPushButton *show_pic_btn;
    QLabel *label_5;
    QLabel *label_13;
    QLabel *label_16;
    QSpinBox *row_spinbox_2;
    QLabel *label_15;
    QSpinBox *col_spinbox_2;
    QLabel *label_9;
    QComboBox *channel_cbox;
    QWidget *widget_view;

    void setupUi(QWidget *BrowsePictureClass)
    {
        if (BrowsePictureClass->objectName().isEmpty())
            BrowsePictureClass->setObjectName(QString::fromUtf8("BrowsePictureClass"));
        BrowsePictureClass->resize(1032, 709);
        horizontalLayout_2 = new QHBoxLayout(BrowsePictureClass);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        open_btn = new QPushButton(BrowsePictureClass);
        open_btn->setObjectName(QString::fromUtf8("open_btn"));
        open_btn->setMinimumSize(QSize(50, 50));
        open_btn->setMaximumSize(QSize(50, 50));

        horizontalLayout->addWidget(open_btn);

        split_btn = new QPushButton(BrowsePictureClass);
        split_btn->setObjectName(QString::fromUtf8("split_btn"));
        split_btn->setMinimumSize(QSize(50, 50));
        split_btn->setMaximumSize(QSize(50, 50));

        horizontalLayout->addWidget(split_btn);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        open_dir_btn = new QPushButton(BrowsePictureClass);
        open_dir_btn->setObjectName(QString::fromUtf8("open_dir_btn"));
        open_dir_btn->setMinimumSize(QSize(40, 50));
        open_dir_btn->setMaximumSize(QSize(40, 50));

        gridLayout_2->addWidget(open_dir_btn, 0, 0, 1, 1);

        dir_edit = new QLineEdit(BrowsePictureClass);
        dir_edit->setObjectName(QString::fromUtf8("dir_edit"));
        dir_edit->setEnabled(true);
        dir_edit->setMinimumSize(QSize(200, 30));
        dir_edit->setMaximumSize(QSize(200, 30));

        gridLayout_2->addWidget(dir_edit, 0, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        auto_merge_btn = new QPushButton(BrowsePictureClass);
        auto_merge_btn->setObjectName(QString::fromUtf8("auto_merge_btn"));
        auto_merge_btn->setMinimumSize(QSize(50, 50));
        auto_merge_btn->setMaximumSize(QSize(50, 50));

        horizontalLayout->addWidget(auto_merge_btn);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(BrowsePictureClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(BrowsePictureClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        label_8 = new QLabel(BrowsePictureClass);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 0, 3, 1, 1);

        row_spinbox = new QSpinBox(BrowsePictureClass);
        row_spinbox->setObjectName(QString::fromUtf8("row_spinbox"));
        row_spinbox->setEnabled(true);
        row_spinbox->setMinimum(0);
        row_spinbox->setMaximum(9999);

        gridLayout->addWidget(row_spinbox, 0, 4, 1, 1);

        label_14 = new QLabel(BrowsePictureClass);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 0, 5, 1, 1);

        col_spinbox = new QSpinBox(BrowsePictureClass);
        col_spinbox->setObjectName(QString::fromUtf8("col_spinbox"));
        col_spinbox->setEnabled(true);
        col_spinbox->setMinimum(0);
        col_spinbox->setMaximum(9999);

        gridLayout->addWidget(col_spinbox, 0, 6, 1, 1);

        label_10 = new QLabel(BrowsePictureClass);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 0, 7, 1, 1);

        grey_start_spinbox = new QSpinBox(BrowsePictureClass);
        grey_start_spinbox->setObjectName(QString::fromUtf8("grey_start_spinbox"));
        grey_start_spinbox->setEnabled(true);
        grey_start_spinbox->setMinimum(0);
        grey_start_spinbox->setMaximum(9999);
        grey_start_spinbox->setValue(0);

        gridLayout->addWidget(grey_start_spinbox, 0, 8, 1, 2);

        label = new QLabel(BrowsePictureClass);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 10, 1, 1);

        grey_end_spinbox = new QSpinBox(BrowsePictureClass);
        grey_end_spinbox->setObjectName(QString::fromUtf8("grey_end_spinbox"));
        grey_end_spinbox->setEnabled(true);
        grey_end_spinbox->setMinimum(0);
        grey_end_spinbox->setMaximum(256);
        grey_end_spinbox->setValue(256);

        gridLayout->addWidget(grey_end_spinbox, 0, 11, 1, 1);

        show_pic_btn = new QPushButton(BrowsePictureClass);
        show_pic_btn->setObjectName(QString::fromUtf8("show_pic_btn"));
        show_pic_btn->setEnabled(true);
        show_pic_btn->setMinimumSize(QSize(40, 50));
        show_pic_btn->setMaximumSize(QSize(40, 50));

        gridLayout->addWidget(show_pic_btn, 0, 12, 2, 1);

        label_5 = new QLabel(BrowsePictureClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(label_5, 1, 1, 1, 1);

        label_13 = new QLabel(BrowsePictureClass);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 1, 2, 1, 1);

        label_16 = new QLabel(BrowsePictureClass);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout->addWidget(label_16, 1, 3, 1, 1);

        row_spinbox_2 = new QSpinBox(BrowsePictureClass);
        row_spinbox_2->setObjectName(QString::fromUtf8("row_spinbox_2"));
        row_spinbox_2->setEnabled(true);
        row_spinbox_2->setMinimum(0);
        row_spinbox_2->setMaximum(9999);
        row_spinbox_2->setValue(1);

        gridLayout->addWidget(row_spinbox_2, 1, 4, 1, 1);

        label_15 = new QLabel(BrowsePictureClass);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout->addWidget(label_15, 1, 5, 1, 1);

        col_spinbox_2 = new QSpinBox(BrowsePictureClass);
        col_spinbox_2->setObjectName(QString::fromUtf8("col_spinbox_2"));
        col_spinbox_2->setEnabled(true);
        col_spinbox_2->setMinimum(0);
        col_spinbox_2->setMaximum(9999);
        col_spinbox_2->setValue(1);

        gridLayout->addWidget(col_spinbox_2, 1, 6, 1, 1);

        label_9 = new QLabel(BrowsePictureClass);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 1, 7, 1, 2);

        channel_cbox = new QComboBox(BrowsePictureClass);
        channel_cbox->setObjectName(QString::fromUtf8("channel_cbox"));

        gridLayout->addWidget(channel_cbox, 1, 9, 1, 3);


        horizontalLayout->addLayout(gridLayout);


        verticalLayout->addLayout(horizontalLayout);

        widget_view = new QWidget(BrowsePictureClass);
        widget_view->setObjectName(QString::fromUtf8("widget_view"));
        widget_view->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_view->sizePolicy().hasHeightForWidth());
        widget_view->setSizePolicy(sizePolicy);
        widget_view->setMinimumSize(QSize(0, 100));
        widget_view->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(widget_view);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(BrowsePictureClass);

        QMetaObject::connectSlotsByName(BrowsePictureClass);
    } // setupUi

    void retranslateUi(QWidget *BrowsePictureClass)
    {
        BrowsePictureClass->setWindowTitle(QApplication::translate("BrowsePictureClass", "Form", 0, QApplication::UnicodeUTF8));
        open_btn->setText(QApplication::translate("BrowsePictureClass", "\346\211\223\345\274\200\n"
"\345\233\276\347\211\207", 0, QApplication::UnicodeUTF8));
        split_btn->setText(QApplication::translate("BrowsePictureClass", "\345\210\206\345\211\262\n"
"\345\233\276\345\203\217", 0, QApplication::UnicodeUTF8));
        open_dir_btn->setText(QApplication::translate("BrowsePictureClass", "\346\211\223\345\274\200\n"
"\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        auto_merge_btn->setText(QApplication::translate("BrowsePictureClass", "\350\207\252\345\212\250\n"
"\345\220\210\345\271\266", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BrowsePictureClass", "\345\220\210\345\271\266\345\214\272\345\237\237", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BrowsePictureClass", "\345\267\246\344\270\212", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("BrowsePictureClass", "\350\241\214", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("BrowsePictureClass", "\345\210\227", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("BrowsePictureClass", "\347\201\260\351\230\266\357\274\232", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BrowsePictureClass", "---", 0, QApplication::UnicodeUTF8));
        show_pic_btn->setText(QApplication::translate("BrowsePictureClass", "\345\220\210\345\271\266", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("BrowsePictureClass", "\345\217\263\344\270\213", 0, QApplication::UnicodeUTF8));
        label_13->setText(QString());
        label_16->setText(QApplication::translate("BrowsePictureClass", "\350\241\214", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("BrowsePictureClass", "\345\210\227", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("BrowsePictureClass", "\345\233\276\345\203\217\351\200\232\351\201\223\357\274\232", 0, QApplication::UnicodeUTF8));
        channel_cbox->clear();
        channel_cbox->insertItems(0, QStringList()
         << QApplication::translate("BrowsePictureClass", "\346\267\267\345\220\210\351\200\232\351\201\223", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BrowsePictureClass", "R\351\200\232\351\201\223", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BrowsePictureClass", "G\351\200\232\351\201\223", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("BrowsePictureClass", "B\351\200\232\351\201\223", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class BrowsePictureClass: public Ui_BrowsePictureClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BROWSEPICTURE_H
