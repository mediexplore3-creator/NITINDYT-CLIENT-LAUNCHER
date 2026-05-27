#pragma once

#include <QWidget>
#include <QSlider>
#include <QLabel>
#include <QComboBox>
#include <QTextEdit>
#include <QPushButton>
#include <QGroupBox>
#include <QRadioButton>

#include "Application.h"
#include "ui/pages/BasePage.h"

class OptimizationPage : public QWidget, public BasePage {
    Q_OBJECT

   public:
    explicit OptimizationPage(QWidget* parent = 0);
    ~OptimizationPage();

    QString displayName() const override { return tr("Optimization"); }
    QIcon icon() const override { return QIcon::fromTheme("speedometer"); }
    QString id() const override { return "optimization"; }
    QString helpPage() const override { return "Optimization"; }

    bool apply() override;
    void retranslate() override;

   private slots:
    void onMemorySliderChanged(int value);
    void onGCPresetChanged();
    void onQuickOptimize();

   private:
    void loadSettings();
    void updateJvmPreview();
    QString buildJvmArgs() const;
    int recommendMaxMem() const;

    QSlider* m_memorySlider;
    QLabel* m_memoryValueLabel;
    QLabel* m_memoryRecommendLabel;

    QRadioButton* m_gcG1GC;
    QRadioButton* m_gcZGC;
    QRadioButton* m_gcShenandoah;
    QRadioButton* m_gcParallel;

    QTextEdit* m_jvmPreview;
    QPushButton* m_quickOptimizeBtn;
};
