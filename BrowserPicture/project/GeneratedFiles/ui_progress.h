/********************************************************************************
** Form generated from reading UI file 'progress.ui'
**
** Created: Fri Sep 2 16:23:26 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESS_H
#define UI_PROGRESS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Progress
{
public:
    QProgressBar *progress;
    QPushButton *cancel_btn;
    QLabel *left_size;
    QLabel *left_time;
    QLabel *lbFileName;

    void setupUi(QWidget *Progress)
    {
        if (Progress->objectName().isEmpty())
            Progress->setObjectName(QString::fromUtf8("Progress"));
        Progress->resize(407, 83);
        Progress->setMaximumSize(QSize(407, 83));
        progress = new QProgressBar(Progress);
        progress->setObjectName(QString::fromUtf8("progress"));
        progress->setGeometry(QRect(10, 30, 331, 21));
        progress->setLayoutDirection(Qt::LeftToRight);
        progress->setValue(24);
        progress->setTextDirection(QProgressBar::BottomToTop);
        cancel_btn = new QPushButton(Progress);
        cancel_btn->setObjectName(QString::fromUtf8("cancel_btn"));
        cancel_btn->setGeometry(QRect(350, 30, 51, 21));
        left_size = new QLabel(Progress);
        left_size->setObjectName(QString::fromUtf8("left_size"));
        left_size->setGeometry(QRect(10, 60, 71, 21));
        left_time = new QLabel(Progress);
        left_time->setObjectName(QString::fromUtf8("left_time"));
        left_time->setGeometry(QRect(80, 60, 131, 21));
        lbFileName = new QLabel(Progress);
        lbFileName->setObjectName(QString::fromUtf8("lbFileName"));
        lbFileName->setGeometry(QRect(10, 10, 301, 21));

        retranslateUi(Progress);

        QMetaObject::connectSlotsByName(Progress);
    } // setupUi

    void retranslateUi(QWidget *Progress)
    {
        Progress->setWindowTitle(QApplication::translate("Progress", "\346\255\243\345\234\250\345\244\204\347\220\206...", 0, QApplication::UnicodeUTF8));
        cancel_btn->setText(QApplication::translate("Progress", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        left_size->setText(QString());
        left_time->setText(QString());
        lbFileName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Progress: public Ui_Progress {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESS_H
