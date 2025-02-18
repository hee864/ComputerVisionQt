/********************************************************************************
** Form generated from reading UI file 'mainframe.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFRAME_H
#define UI_MAINFRAME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainFrame
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *buttonOpen;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *buttonDeleteContents;
    QSpacerItem *horizontalSpacer;
    QToolButton *buttonShowList;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QPushButton *contrastTransform;
    QSpinBox *spinContrastA;
    QSpinBox *spinContrastB;
    QLabel *label;
    QLabel *label_2;
    QWidget *tab_4;
    QPushButton *pushDilation;
    QPushButton *pushErosion;
    QRadioButton *Kernel3;
    QRadioButton *Kernel5;
    QPushButton *pushOstu;
    QPushButton *pushThresholding;
    QSpinBox *spinOstu;
    QLabel *label_3;
    QGroupBox *groupBox;
    QRadioButton *neighbor4;
    QRadioButton *neighbor8;
    QPushButton *pushLabel;
    QSpinBox *spinLabel;
    QWidget *tab_5;
    QGroupBox *groupBox_2;
    QRadioButton *KernelSize3;
    QRadioButton *KernelSize5;
    QGroupBox *groupBox_3;
    QRadioButton *Neighbor4;
    QRadioButton *Neighbor8;
    QPushButton *pushOpen;
    QPushButton *pushClose;
    QGroupBox *groupBox_4;
    QRadioButton *foreground;
    QRadioButton *background;
    QPushButton *pushBoundary;
    QWidget *tab_2;
    QPushButton *button_HE;
    QPushButton *button_HM;
    QPushButton *button_Source;
    QPushButton *button_REF;
    QListWidget *listWidget;

    void setupUi(QDialog *MainFrame)
    {
        if (MainFrame->objectName().isEmpty())
            MainFrame->setObjectName("MainFrame");
        MainFrame->resize(622, 461);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainFrame->sizePolicy().hasHeightForWidth());
        MainFrame->setSizePolicy(sizePolicy);
        MainFrame->setMinimumSize(QSize(0, 461));
        MainFrame->setModal(false);
        verticalLayout = new QVBoxLayout(MainFrame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        frame = new QFrame(MainFrame);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(0, 41));
        frame->setMaximumSize(QSize(16777215, 41));
        frame->setFrameShape(QFrame::Shape::Panel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        buttonOpen = new QToolButton(frame);
        buttonOpen->setObjectName("buttonOpen");
        buttonOpen->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(buttonOpen->sizePolicy().hasHeightForWidth());
        buttonOpen->setSizePolicy(sizePolicy2);
        buttonOpen->setMinimumSize(QSize(41, 41));
        buttonOpen->setMaximumSize(QSize(41, 41));
        buttonOpen->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        buttonOpen->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/open.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        buttonOpen->setIcon(icon);
        buttonOpen->setIconSize(QSize(41, 41));
        buttonOpen->setCheckable(false);
        buttonOpen->setAutoRepeat(false);
        buttonOpen->setAutoExclusive(false);
        buttonOpen->setPopupMode(QToolButton::ToolButtonPopupMode::DelayedPopup);
        buttonOpen->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
        buttonOpen->setAutoRaise(false);

        horizontalLayout_3->addWidget(buttonOpen);

        toolButton_2 = new QToolButton(frame);
        toolButton_2->setObjectName("toolButton_2");
        sizePolicy2.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy2);
        toolButton_2->setMinimumSize(QSize(41, 41));
        toolButton_2->setMaximumSize(QSize(41, 41));

        horizontalLayout_3->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(frame);
        toolButton_3->setObjectName("toolButton_3");
        sizePolicy2.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy2);
        toolButton_3->setMinimumSize(QSize(41, 41));
        toolButton_3->setMaximumSize(QSize(41, 41));

        horizontalLayout_3->addWidget(toolButton_3);

        buttonDeleteContents = new QToolButton(frame);
        buttonDeleteContents->setObjectName("buttonDeleteContents");
        sizePolicy2.setHeightForWidth(buttonDeleteContents->sizePolicy().hasHeightForWidth());
        buttonDeleteContents->setSizePolicy(sizePolicy2);
        buttonDeleteContents->setMinimumSize(QSize(41, 41));
        buttonDeleteContents->setMaximumSize(QSize(41, 41));
        buttonDeleteContents->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/1-21.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        buttonDeleteContents->setIcon(icon1);
        buttonDeleteContents->setIconSize(QSize(41, 41));

        horizontalLayout_3->addWidget(buttonDeleteContents);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        buttonShowList = new QToolButton(frame);
        buttonShowList->setObjectName("buttonShowList");
        sizePolicy2.setHeightForWidth(buttonShowList->sizePolicy().hasHeightForWidth());
        buttonShowList->setSizePolicy(sizePolicy2);
        buttonShowList->setMinimumSize(QSize(41, 41));
        buttonShowList->setMaximumSize(QSize(41, 41));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/2-3.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        buttonShowList->setIcon(icon2);
        buttonShowList->setIconSize(QSize(82, 41));

        horizontalLayout_3->addWidget(buttonShowList);


        verticalLayout->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(2, -1, -1, -1);
        tabWidget = new QTabWidget(MainFrame);
        tabWidget->setObjectName("tabWidget");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy3);
        tabWidget->setMinimumSize(QSize(299, 394));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush1(QColor(0, 120, 212, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Accent, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        QBrush brush2(QColor(240, 240, 240, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Accent, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Accent, brush3);
        tabWidget->setPalette(palette);
        tabWidget->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabPosition(QTabWidget::TabPosition::North);
        tabWidget->setTabShape(QTabWidget::TabShape::Rounded);
        tabWidget->setIconSize(QSize(31, 31));
        tabWidget->setElideMode(Qt::TextElideMode::ElideMiddle);
        tab_1 = new QWidget();
        tab_1->setObjectName("tab_1");
        contrastTransform = new QPushButton(tab_1);
        contrastTransform->setObjectName("contrastTransform");
        contrastTransform->setGeometry(QRect(60, 60, 161, 29));
        spinContrastA = new QSpinBox(tab_1);
        spinContrastA->setObjectName("spinContrastA");
        spinContrastA->setGeometry(QRect(110, 130, 43, 26));
        spinContrastA->setMaximum(256);
        spinContrastB = new QSpinBox(tab_1);
        spinContrastB->setObjectName("spinContrastB");
        spinContrastB->setGeometry(QRect(180, 130, 43, 26));
        spinContrastB->setMaximum(256);
        label = new QLabel(tab_1);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 110, 21, 16));
        label_2 = new QLabel(tab_1);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(180, 110, 21, 16));
        tabWidget->addTab(tab_1, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        pushDilation = new QPushButton(tab_4);
        pushDilation->setObjectName("pushDilation");
        pushDilation->setGeometry(QRect(170, 130, 93, 29));
        pushErosion = new QPushButton(tab_4);
        pushErosion->setObjectName("pushErosion");
        pushErosion->setGeometry(QRect(170, 160, 93, 29));
        Kernel3 = new QRadioButton(tab_4);
        Kernel3->setObjectName("Kernel3");
        Kernel3->setGeometry(QRect(30, 130, 112, 24));
        Kernel5 = new QRadioButton(tab_4);
        Kernel5->setObjectName("Kernel5");
        Kernel5->setGeometry(QRect(30, 160, 112, 24));
        pushOstu = new QPushButton(tab_4);
        pushOstu->setObjectName("pushOstu");
        pushOstu->setGeometry(QRect(60, 10, 131, 29));
        pushThresholding = new QPushButton(tab_4);
        pushThresholding->setObjectName("pushThresholding");
        pushThresholding->setGeometry(QRect(200, 60, 51, 29));
        spinOstu = new QSpinBox(tab_4);
        spinOstu->setObjectName("spinOstu");
        spinOstu->setGeometry(QRect(110, 60, 43, 26));
        label_3 = new QLabel(tab_4);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 60, 71, 20));
        groupBox = new QGroupBox(tab_4);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(40, 220, 120, 80));
        neighbor4 = new QRadioButton(groupBox);
        neighbor4->setObjectName("neighbor4");
        neighbor4->setGeometry(QRect(0, 20, 112, 24));
        neighbor8 = new QRadioButton(groupBox);
        neighbor8->setObjectName("neighbor8");
        neighbor8->setGeometry(QRect(0, 50, 112, 24));
        pushLabel = new QPushButton(tab_4);
        pushLabel->setObjectName("pushLabel");
        pushLabel->setGeometry(QRect(170, 250, 93, 29));
        spinLabel = new QSpinBox(tab_4);
        spinLabel->setObjectName("spinLabel");
        spinLabel->setGeometry(QRect(180, 290, 43, 26));
        spinLabel->setMaximum(300);
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        groupBox_2 = new QGroupBox(tab_5);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(20, 60, 120, 80));
        KernelSize3 = new QRadioButton(groupBox_2);
        KernelSize3->setObjectName("KernelSize3");
        KernelSize3->setGeometry(QRect(10, 20, 112, 24));
        KernelSize5 = new QRadioButton(groupBox_2);
        KernelSize5->setObjectName("KernelSize5");
        KernelSize5->setGeometry(QRect(10, 50, 112, 24));
        groupBox_3 = new QGroupBox(tab_5);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(20, 210, 120, 80));
        Neighbor4 = new QRadioButton(groupBox_3);
        Neighbor4->setObjectName("Neighbor4");
        Neighbor4->setGeometry(QRect(0, 20, 112, 24));
        Neighbor8 = new QRadioButton(groupBox_3);
        Neighbor8->setObjectName("Neighbor8");
        Neighbor8->setGeometry(QRect(0, 50, 112, 24));
        pushOpen = new QPushButton(tab_5);
        pushOpen->setObjectName("pushOpen");
        pushOpen->setGeometry(QRect(160, 70, 93, 29));
        pushClose = new QPushButton(tab_5);
        pushClose->setObjectName("pushClose");
        pushClose->setGeometry(QRect(160, 110, 93, 29));
        groupBox_4 = new QGroupBox(tab_5);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(150, 210, 120, 80));
        foreground = new QRadioButton(groupBox_4);
        foreground->setObjectName("foreground");
        foreground->setGeometry(QRect(0, 20, 112, 24));
        background = new QRadioButton(groupBox_4);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 40, 112, 24));
        pushBoundary = new QPushButton(tab_5);
        pushBoundary->setObjectName("pushBoundary");
        pushBoundary->setGeometry(QRect(60, 310, 161, 29));
        tabWidget->addTab(tab_5, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        button_HE = new QPushButton(tab_2);
        button_HE->setObjectName("button_HE");
        button_HE->setGeometry(QRect(50, 60, 171, 31));
        button_HM = new QPushButton(tab_2);
        button_HM->setObjectName("button_HM");
        button_HM->setGeometry(QRect(50, 120, 171, 31));
        button_Source = new QPushButton(tab_2);
        button_Source->setObjectName("button_Source");
        button_Source->setGeometry(QRect(30, 190, 93, 29));
        button_REF = new QPushButton(tab_2);
        button_REF->setObjectName("button_REF");
        button_REF->setGeometry(QRect(140, 190, 93, 29));
        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        listWidget = new QListWidget(MainFrame);
        listWidget->setObjectName("listWidget");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy4);
        listWidget->setMinimumSize(QSize(0, 394));
        QPalette palette1;
        QBrush brush4(QColor(255, 255, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush5(QColor(0, 0, 127, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush5);
        QBrush brush6(QColor(255, 255, 255, 128));
        brush6.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        QBrush brush7(QColor(255, 255, 255, 128));
        brush7.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush7);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        QBrush brush8(QColor(255, 255, 255, 128));
        brush8.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        listWidget->setPalette(palette1);
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(10);
        listWidget->setFont(font);

        horizontalLayout->addWidget(listWidget);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MainFrame);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainFrame);
    } // setupUi

    void retranslateUi(QDialog *MainFrame)
    {
        MainFrame->setWindowTitle(QCoreApplication::translate("MainFrame", "Practice CV", nullptr));
#if QT_CONFIG(tooltip)
        buttonOpen->setToolTip(QCoreApplication::translate("MainFrame", "open an image file", nullptr));
#endif // QT_CONFIG(tooltip)
        buttonOpen->setText(QString());
        toolButton_2->setText(QCoreApplication::translate("MainFrame", "...", nullptr));
        toolButton_3->setText(QCoreApplication::translate("MainFrame", "...", nullptr));
#if QT_CONFIG(tooltip)
        buttonDeleteContents->setToolTip(QCoreApplication::translate("MainFrame", "close all forms", nullptr));
#endif // QT_CONFIG(tooltip)
        buttonDeleteContents->setText(QString());
#if QT_CONFIG(tooltip)
        buttonShowList->setToolTip(QCoreApplication::translate("MainFrame", "show the list view", nullptr));
#endif // QT_CONFIG(tooltip)
        buttonShowList->setText(QString());
        contrastTransform->setText(QCoreApplication::translate("MainFrame", "contrastTransform", nullptr));
        label->setText(QCoreApplication::translate("MainFrame", "a'", nullptr));
        label_2->setText(QCoreApplication::translate("MainFrame", "b'", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QCoreApplication::translate("MainFrame", "1 ", nullptr));
        pushDilation->setText(QCoreApplication::translate("MainFrame", "dialtion", nullptr));
        pushErosion->setText(QCoreApplication::translate("MainFrame", "erosion", nullptr));
        Kernel3->setText(QCoreApplication::translate("MainFrame", "3x3", nullptr));
        Kernel5->setText(QCoreApplication::translate("MainFrame", "5x5", nullptr));
        pushOstu->setText(QCoreApplication::translate("MainFrame", "Ostu Threshold", nullptr));
        pushThresholding->setText(QCoreApplication::translate("MainFrame", ">>", nullptr));
        label_3->setText(QCoreApplication::translate("MainFrame", "Threshold", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainFrame", "GroupBox", nullptr));
        neighbor4->setText(QCoreApplication::translate("MainFrame", "4-neighbor", nullptr));
        neighbor8->setText(QCoreApplication::translate("MainFrame", "8-neighbor", nullptr));
        pushLabel->setText(QCoreApplication::translate("MainFrame", "Labeling", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainFrame", "2", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainFrame", "GroupBox", nullptr));
        KernelSize3->setText(QCoreApplication::translate("MainFrame", "3x3", nullptr));
        KernelSize5->setText(QCoreApplication::translate("MainFrame", "5x5", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainFrame", "GroupBox", nullptr));
        Neighbor4->setText(QCoreApplication::translate("MainFrame", "Mb4", nullptr));
        Neighbor8->setText(QCoreApplication::translate("MainFrame", "Mb8", nullptr));
        pushOpen->setText(QCoreApplication::translate("MainFrame", "opening", nullptr));
        pushClose->setText(QCoreApplication::translate("MainFrame", "closing", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainFrame", "GroupBox", nullptr));
        foreground->setText(QCoreApplication::translate("MainFrame", "foreground", nullptr));
        background->setText(QCoreApplication::translate("MainFrame", "background", nullptr));
        pushBoundary->setText(QCoreApplication::translate("MainFrame", "boundary-extraction", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainFrame", "3", nullptr));
        button_HE->setText(QCoreApplication::translate("MainFrame", "histogram-equalize", nullptr));
        button_HM->setText(QCoreApplication::translate("MainFrame", "histogram-matching", nullptr));
        button_Source->setText(QCoreApplication::translate("MainFrame", "source", nullptr));
        button_REF->setText(QCoreApplication::translate("MainFrame", "reference", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainFrame", "4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainFrame: public Ui_MainFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFRAME_H
