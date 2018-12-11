/********************************************************************************
** Form generated from reading UI file 'zumbracontroldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZUMBRACONTROLDIALOG_H
#define UI_ZUMBRACONTROLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ZUmbraControlDialog
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *labelQuantity;
    QLabel *labelQuantity_int;
    QLabel *labelZUmbra;
    QLabel *labelZUmbra_int;
    QPushButton *pushButtonAll;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ZUmbraControlDialog)
    {
        if (ZUmbraControlDialog->objectName().isEmpty())
            ZUmbraControlDialog->setObjectName(QStringLiteral("ZUmbraControlDialog"));
        ZUmbraControlDialog->resize(681, 384);
        ZUmbraControlDialog->setMinimumSize(QSize(681, 384));
        gridLayout = new QGridLayout(ZUmbraControlDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        labelQuantity = new QLabel(ZUmbraControlDialog);
        labelQuantity->setObjectName(QStringLiteral("labelQuantity"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelQuantity);

        labelQuantity_int = new QLabel(ZUmbraControlDialog);
        labelQuantity_int->setObjectName(QStringLiteral("labelQuantity_int"));

        formLayout->setWidget(0, QFormLayout::FieldRole, labelQuantity_int);

        labelZUmbra = new QLabel(ZUmbraControlDialog);
        labelZUmbra->setObjectName(QStringLiteral("labelZUmbra"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelZUmbra);

        labelZUmbra_int = new QLabel(ZUmbraControlDialog);
        labelZUmbra_int->setObjectName(QStringLiteral("labelZUmbra_int"));

        formLayout->setWidget(1, QFormLayout::FieldRole, labelZUmbra_int);

        pushButtonAll = new QPushButton(ZUmbraControlDialog);
        pushButtonAll->setObjectName(QStringLiteral("pushButtonAll"));

        formLayout->setWidget(2, QFormLayout::LabelRole, pushButtonAll);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treeWidget = new QTreeWidget(ZUmbraControlDialog);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(3, QStringLiteral("Confirmations"));
        __qtreewidgetitem->setText(2, QStringLiteral("zUmbra Public ID"));
        __qtreewidgetitem->setText(1, QStringLiteral("Denomination"));
        __qtreewidgetitem->setText(0, QStringLiteral("Select"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setMinimumSize(QSize(0, 250));
        treeWidget->setAlternatingRowColors(true);
        treeWidget->setSortingEnabled(true);
        treeWidget->setColumnCount(5);
        treeWidget->header()->setDefaultSectionSize(100);

        verticalLayout->addWidget(treeWidget);

        buttonBox = new QDialogButtonBox(ZUmbraControlDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);


        retranslateUi(ZUmbraControlDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ZUmbraControlDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ZUmbraControlDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ZUmbraControlDialog);
    } // setupUi

    void retranslateUi(QDialog *ZUmbraControlDialog)
    {
        ZUmbraControlDialog->setWindowTitle(QApplication::translate("ZUmbraControlDialog", "Select zUmbra to Spend", Q_NULLPTR));
        labelQuantity->setText(QApplication::translate("ZUmbraControlDialog", "Quantity", Q_NULLPTR));
        labelQuantity_int->setText(QApplication::translate("ZUmbraControlDialog", "0", Q_NULLPTR));
        labelZUmbra->setText(QApplication::translate("ZUmbraControlDialog", "zUmbra", Q_NULLPTR));
        labelZUmbra_int->setText(QApplication::translate("ZUmbraControlDialog", "0", Q_NULLPTR));
        pushButtonAll->setText(QApplication::translate("ZUmbraControlDialog", "Select/Deselect All", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(4, QApplication::translate("ZUmbraControlDialog", "Is Spendable", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ZUmbraControlDialog: public Ui_ZUmbraControlDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZUMBRACONTROLDIALOG_H
