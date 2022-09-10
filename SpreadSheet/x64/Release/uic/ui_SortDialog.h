/********************************************************************************
** Form generated from reading UI file 'SortDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTDIALOG_H
#define UI_SORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SortDialog
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *primaryGroupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *primaryColumnCombo;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QComboBox *primaryOrderCombo;
    QVBoxLayout *verticalLayout;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QSpacerItem *verticalSpacer;
    QPushButton *btnMore;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *secondaryGroupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QComboBox *secondaryColumnCombo;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QComboBox *secondaryOrderCombo;
    QGroupBox *tertiaryGroupBox;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QComboBox *tertiaryColumnCombo;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_6;
    QComboBox *teritaryOrderCombo;

    void setupUi(QDialog *SortDialog)
    {
        if (SortDialog->objectName().isEmpty())
            SortDialog->setObjectName(QString::fromUtf8("SortDialog"));
        SortDialog->resize(337, 381);
        gridLayout_4 = new QGridLayout(SortDialog);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        primaryGroupBox = new QGroupBox(SortDialog);
        primaryGroupBox->setObjectName(QString::fromUtf8("primaryGroupBox"));
        gridLayout = new QGridLayout(primaryGroupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(primaryGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        primaryColumnCombo = new QComboBox(primaryGroupBox);
        primaryColumnCombo->addItem(QString());
        primaryColumnCombo->setObjectName(QString::fromUtf8("primaryColumnCombo"));

        gridLayout->addWidget(primaryColumnCombo, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(54, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_2 = new QLabel(primaryGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        primaryOrderCombo = new QComboBox(primaryGroupBox);
        primaryOrderCombo->addItem(QString());
        primaryOrderCombo->addItem(QString());
        primaryOrderCombo->setObjectName(QString::fromUtf8("primaryOrderCombo"));

        gridLayout->addWidget(primaryOrderCombo, 1, 1, 1, 2);


        gridLayout_4->addWidget(primaryGroupBox, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnOK = new QPushButton(SortDialog);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));

        verticalLayout->addWidget(btnOK);

        btnCancel = new QPushButton(SortDialog);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        verticalLayout->addWidget(btnCancel);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btnMore = new QPushButton(SortDialog);
        btnMore->setObjectName(QString::fromUtf8("btnMore"));
        btnMore->setCheckable(true);

        verticalLayout->addWidget(btnMore);


        gridLayout_4->addLayout(verticalLayout, 0, 1, 2, 1);

        verticalSpacer_2 = new QSpacerItem(20, 69, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 1, 0, 1, 1);

        secondaryGroupBox = new QGroupBox(SortDialog);
        secondaryGroupBox->setObjectName(QString::fromUtf8("secondaryGroupBox"));
        gridLayout_2 = new QGridLayout(secondaryGroupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(secondaryGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        secondaryColumnCombo = new QComboBox(secondaryGroupBox);
        secondaryColumnCombo->addItem(QString());
        secondaryColumnCombo->setObjectName(QString::fromUtf8("secondaryColumnCombo"));

        gridLayout_2->addWidget(secondaryColumnCombo, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        label_4 = new QLabel(secondaryGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        secondaryOrderCombo = new QComboBox(secondaryGroupBox);
        secondaryOrderCombo->addItem(QString());
        secondaryOrderCombo->addItem(QString());
        secondaryOrderCombo->setObjectName(QString::fromUtf8("secondaryOrderCombo"));

        gridLayout_2->addWidget(secondaryOrderCombo, 1, 1, 1, 2);


        gridLayout_4->addWidget(secondaryGroupBox, 2, 0, 1, 1);

        tertiaryGroupBox = new QGroupBox(SortDialog);
        tertiaryGroupBox->setObjectName(QString::fromUtf8("tertiaryGroupBox"));
        gridLayout_3 = new QGridLayout(tertiaryGroupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_5 = new QLabel(tertiaryGroupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 0, 0, 1, 1);

        tertiaryColumnCombo = new QComboBox(tertiaryGroupBox);
        tertiaryColumnCombo->addItem(QString());
        tertiaryColumnCombo->setObjectName(QString::fromUtf8("tertiaryColumnCombo"));

        gridLayout_3->addWidget(tertiaryColumnCombo, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        label_6 = new QLabel(tertiaryGroupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);

        teritaryOrderCombo = new QComboBox(tertiaryGroupBox);
        teritaryOrderCombo->addItem(QString());
        teritaryOrderCombo->addItem(QString());
        teritaryOrderCombo->setObjectName(QString::fromUtf8("teritaryOrderCombo"));

        gridLayout_3->addWidget(teritaryOrderCombo, 1, 1, 1, 2);


        gridLayout_4->addWidget(tertiaryGroupBox, 3, 0, 1, 1);

        QWidget::setTabOrder(primaryColumnCombo, primaryOrderCombo);
        QWidget::setTabOrder(primaryOrderCombo, secondaryColumnCombo);
        QWidget::setTabOrder(secondaryColumnCombo, secondaryOrderCombo);
        QWidget::setTabOrder(secondaryOrderCombo, tertiaryColumnCombo);
        QWidget::setTabOrder(tertiaryColumnCombo, teritaryOrderCombo);
        QWidget::setTabOrder(teritaryOrderCombo, btnOK);
        QWidget::setTabOrder(btnOK, btnCancel);
        QWidget::setTabOrder(btnCancel, btnMore);

        retranslateUi(SortDialog);
        QObject::connect(btnOK, SIGNAL(clicked()), SortDialog, SLOT(accept()));
        QObject::connect(btnCancel, SIGNAL(clicked()), SortDialog, SLOT(reject()));
        QObject::connect(btnMore, SIGNAL(toggled(bool)), secondaryGroupBox, SLOT(setVisible(bool)));
        QObject::connect(btnMore, SIGNAL(toggled(bool)), tertiaryGroupBox, SLOT(setVisible(bool)));

        btnOK->setDefault(true);


        QMetaObject::connectSlotsByName(SortDialog);
    } // setupUi

    void retranslateUi(QDialog *SortDialog)
    {
        SortDialog->setWindowTitle(QCoreApplication::translate("SortDialog", "Sort", nullptr));
        primaryGroupBox->setTitle(QCoreApplication::translate("SortDialog", "&Primary Key", nullptr));
        label->setText(QCoreApplication::translate("SortDialog", "Column:", nullptr));
        primaryColumnCombo->setItemText(0, QCoreApplication::translate("SortDialog", "None", nullptr));

        label_2->setText(QCoreApplication::translate("SortDialog", "Order:", nullptr));
        primaryOrderCombo->setItemText(0, QCoreApplication::translate("SortDialog", "Ascending", nullptr));
        primaryOrderCombo->setItemText(1, QCoreApplication::translate("SortDialog", "Descending", nullptr));

        btnOK->setText(QCoreApplication::translate("SortDialog", " OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("SortDialog", "Cancel", nullptr));
        btnMore->setText(QCoreApplication::translate("SortDialog", "&More", nullptr));
        secondaryGroupBox->setTitle(QCoreApplication::translate("SortDialog", "&Secondary Key", nullptr));
        label_3->setText(QCoreApplication::translate("SortDialog", "Column:", nullptr));
        secondaryColumnCombo->setItemText(0, QCoreApplication::translate("SortDialog", "None", nullptr));

        label_4->setText(QCoreApplication::translate("SortDialog", "Order:", nullptr));
        secondaryOrderCombo->setItemText(0, QCoreApplication::translate("SortDialog", "Ascending", nullptr));
        secondaryOrderCombo->setItemText(1, QCoreApplication::translate("SortDialog", "Descending", nullptr));

        tertiaryGroupBox->setTitle(QCoreApplication::translate("SortDialog", "&Tertiary Key", nullptr));
        label_5->setText(QCoreApplication::translate("SortDialog", "Column:", nullptr));
        tertiaryColumnCombo->setItemText(0, QCoreApplication::translate("SortDialog", "None", nullptr));

        label_6->setText(QCoreApplication::translate("SortDialog", "Order:", nullptr));
        teritaryOrderCombo->setItemText(0, QCoreApplication::translate("SortDialog", "Ascending", nullptr));
        teritaryOrderCombo->setItemText(1, QCoreApplication::translate("SortDialog", "Descending", nullptr));

    } // retranslateUi

};

namespace Ui {
    class SortDialog: public Ui_SortDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTDIALOG_H
