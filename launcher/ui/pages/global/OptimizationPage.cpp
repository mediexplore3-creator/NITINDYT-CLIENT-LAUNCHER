#include "OptimizationPage.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QButtonGroup>
#include <QSpacerItem>
#include <QScrollArea>
#include <QFrame>
#include <QMessageBox>

#include "BuildConfig.h"
#include "HardwareInfo.h"
#include "SysInfo.h"

OptimizationPage::OptimizationPage(QWidget* parent) : QWidget(parent)
{
    auto* scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setFrameShape(QFrame::NoFrame);

    auto* container = new QWidget();
    auto* mainLayout = new QVBoxLayout(container);
    mainLayout->setContentsMargins(20, 16, 20, 16);
    mainLayout->setSpacing(20);

    auto* headerLabel = new QLabel(tr("Optimization Center"));
    headerLabel->setProperty("heading", true);
    mainLayout->addWidget(headerLabel);

    auto* descLabel = new QLabel(tr("Tune your launcher and Minecraft performance with recommended settings based on your system."));
    descLabel->setProperty("subheading", true);
    descLabel->setWordWrap(true);
    mainLayout->addWidget(descLabel);

    /* === Memory Card === */
    auto* memoryCard = new QFrame();
    memoryCard->setObjectName("newsFrame");
    auto* memoryLayout = new QVBoxLayout(memoryCard);
    memoryLayout->setContentsMargins(16, 12, 16, 16);
    memoryLayout->setSpacing(12);

    auto* memoryTitle = new QLabel(tr("Memory Allocation"));
    memoryTitle->setProperty("heading", true);
    memoryLayout->addWidget(memoryTitle);

    auto* memoryDesc = new QLabel(tr("Allocate RAM to Minecraft. Allocating too much can cause stuttering. "
                                      "Allocating too little causes lag spikes."));
    memoryDesc->setProperty("subheading", true);
    memoryDesc->setWordWrap(true);
    memoryLayout->addWidget(memoryDesc);

    auto* sliderRow = new QHBoxLayout();
    m_memorySlider = new QSlider(Qt::Horizontal);
    m_memorySlider->setRange(1024, 16384);
    m_memorySlider->setSingleStep(256);
    m_memorySlider->setPageStep(1024);
    sliderRow->addWidget(m_memorySlider, 1);

    m_memoryValueLabel = new QLabel("4 GB");
    m_memoryValueLabel->setMinimumWidth(60);
    m_memoryValueLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    sliderRow->addWidget(m_memoryValueLabel);
    memoryLayout->addLayout(sliderRow);

    auto* memDetailRow = new QHBoxLayout();
    auto* memMinLabel = new QLabel(tr("1 GB"));
    memMinLabel->setStyleSheet("color: #8b949e; font-size: 11px;");
    memDetailRow->addWidget(memMinLabel);

    m_memoryRecommendLabel = new QLabel();
    m_memoryRecommendLabel->setAlignment(Qt::AlignCenter);
    m_memoryRecommendLabel->setStyleSheet("color: #00d4ff; font-size: 11px; font-weight: 600;");
    memDetailRow->addWidget(m_memoryRecommendLabel, 1);

    auto* memMaxLabel = new QLabel(tr("16 GB"));
    memMaxLabel->setAlignment(Qt::AlignRight);
    memMaxLabel->setStyleSheet("color: #8b949e; font-size: 11px;");
    memDetailRow->addWidget(memMaxLabel);
    memoryLayout->addLayout(memDetailRow);

    mainLayout->addWidget(memoryCard);

    /* === Garbage Collector Card === */
    auto* gcCard = new QFrame();
    gcCard->setObjectName("newsFrame");
    auto* gcLayout = new QVBoxLayout(gcCard);
    gcLayout->setContentsMargins(16, 12, 16, 16);
    gcLayout->setSpacing(12);

    auto* gcTitle = new QLabel(tr("Garbage Collector Presets"));
    gcTitle->setProperty("heading", true);
    gcLayout->addWidget(gcTitle);

    auto* gcDesc = new QLabel(tr("Choose a JVM garbage collector optimized for your use case. "
                                  "Modern Java versions (21+) benefit most from G1GC or ZGC."));
    gcDesc->setProperty("subheading", true);
    gcDesc->setWordWrap(true);
    gcLayout->addWidget(gcDesc);

    auto* gcGroup = new QButtonGroup(this);
#if QT_VERSION >= QT_VERSION_CHECK(5, 15, 0)
    connect(gcGroup, &QButtonGroup::idClicked, this, &OptimizationPage::onGCPresetChanged);
#else
    connect(gcGroup, QOverload<int>::of(&QButtonGroup::buttonClicked), this, &OptimizationPage::onGCPresetChanged);
#endif

    auto makeGCRow = [&](const QString& title, const QString& desc, QRadioButton*& btn, int id) {
        auto* row = new QHBoxLayout();
        btn = new QRadioButton(title);
        gcGroup->addButton(btn, id);
        row->addWidget(btn);
        auto* label = new QLabel(desc);
        label->setWordWrap(true);
        label->setStyleSheet("color: #8b949e; font-size: 11px;");
        row->addWidget(label, 1);
        gcLayout->addLayout(row);
    };

    makeGCRow(tr("G1GC (Recommended)"), tr("Balanced throughput and latency. Best choice for most users."), m_gcG1GC, 0);
    makeGCRow(tr("ZGC"), tr("Ultra-low latency. Best for modern Java (21+) with large RAM."), m_gcZGC, 1);
    makeGCRow(tr("Shenandoah"), tr("Low pause times. Good alternative to ZGC on older Java versions."), m_gcShenandoah, 2);
    makeGCRow(tr("Parallel"), tr("Maximum throughput. Best for older systems or Java 8."), m_gcParallel, 3);

    mainLayout->addWidget(gcCard);

    /* === JVM Preview Card === */
    auto* previewCard = new QFrame();
    previewCard->setObjectName("newsFrame");
    auto* previewLayout = new QVBoxLayout(previewCard);
    previewLayout->setContentsMargins(16, 12, 16, 16);
    previewLayout->setSpacing(12);

    auto* previewTitle = new QLabel(tr("JVM Arguments Preview"));
    previewTitle->setProperty("heading", true);
    previewLayout->addWidget(previewTitle);

    auto* previewDesc = new QLabel(tr("These arguments will be appended to your existing JVM arguments."));
    previewDesc->setProperty("subheading", true);
    previewDesc->setWordWrap(true);
    previewLayout->addWidget(previewDesc);

    m_jvmPreview = new QTextEdit();
    m_jvmPreview->setReadOnly(true);
    m_jvmPreview->setMaximumHeight(100);
    m_jvmPreview->setStyleSheet("QTextEdit { background-color: #0d1117; color: #00d4ff; "
                                 "border: 1px solid #30363d; border-radius: 8px; "
                                 "padding: 8px; font-family: 'Cascadia Code', 'Fira Code', monospace; font-size: 12px; }");
    previewLayout->addWidget(m_jvmPreview);

    mainLayout->addWidget(previewCard);

    /* === Quick Optimize Button === */
    auto* btnLayout = new QHBoxLayout();
    btnLayout->addStretch();

    m_quickOptimizeBtn = new QPushButton(tr("Quick Optimize"));
    m_quickOptimizeBtn->setObjectName("primaryButton");
    m_quickOptimizeBtn->setMinimumHeight(40);
    m_quickOptimizeBtn->setMinimumWidth(200);
    connect(m_quickOptimizeBtn, &QPushButton::clicked, this, &OptimizationPage::onQuickOptimize);
    btnLayout->addWidget(m_quickOptimizeBtn);

    mainLayout->addLayout(btnLayout);
    mainLayout->addStretch();

    scrollArea->setWidget(container);

    auto* outerLayout = new QVBoxLayout(this);
    outerLayout->setContentsMargins(0, 0, 0, 0);
    outerLayout->addWidget(scrollArea);

    connect(m_memorySlider, &QSlider::valueChanged, this, &OptimizationPage::onMemorySliderChanged);

    loadSettings();
}

OptimizationPage::~OptimizationPage() {}

void OptimizationPage::loadSettings()
{
    auto s = APPLICATION->settings();
    int currentMem = s->get("MaxMemAlloc").toInt();
    if (currentMem < 1024)
        currentMem = recommendMaxMem();
    m_memorySlider->setValue(currentMem);
    onMemorySliderChanged(currentMem);

    QString jvmArgs = s->get("JvmArgs").toString();
    if (jvmArgs.contains("ZGC") || jvmArgs.contains("zgc"))
        m_gcZGC->setChecked(true);
    else if (jvmArgs.contains("Shenandoah") || jvmArgs.contains("shenandoah"))
        m_gcShenandoah->setChecked(true);
    else if (jvmArgs.contains("Parallel") || jvmArgs.contains("parallel"))
        m_gcParallel->setChecked(true);
    else
        m_gcG1GC->setChecked(true);

    updateJvmPreview();
}

bool OptimizationPage::apply()
{
    auto s = APPLICATION->settings();
    int mem = m_memorySlider->value();
    if (mem < 512)
        mem = 512;
    s->set("MaxMemAlloc", mem);
    if (mem < 512)
        s->set("MinMemAlloc", mem);
    else
        s->set("MinMemAlloc", 512);

    QString currentArgs = s->get("JvmArgs").toString();
    QStringList parts = currentArgs.split(' ', Qt::SkipEmptyParts);
    QStringList cleaned;
    for (const auto& arg : parts) {
        if (arg.startsWith("-XX:+Use") || arg.startsWith("-XX:ConcGCThreads=") ||
            arg.startsWith("-XX:ParallelGCThreads=") || arg.startsWith("-XX:+UnlockExperimentalVMOptions"))
            continue;
        cleaned.append(arg);
    }
    cleaned.append(buildJvmArgs());
    s->set("JvmArgs", cleaned.join(' '));
    return true;
}

void OptimizationPage::retranslate() {}

void OptimizationPage::onMemorySliderChanged(int value)
{
    double gb = value / 1024.0;
    m_memoryValueLabel->setText(QString("%1 GB").arg(gb, 0, 'f', 1));

    uint64_t totalRAM = HardwareInfo::totalRamMiB();
    int recommended = recommendMaxMem();
    if (value == recommended)
        m_memoryRecommendLabel->setText(tr("Recommended"));
    else if (value > totalRAM / 2)
        m_memoryRecommendLabel->setText(tr("High (>50%% of RAM)"));
    else
        m_memoryRecommendLabel->setText(QString());
}

int OptimizationPage::recommendMaxMem() const
{
    uint64_t totalRAM = HardwareInfo::totalRamMiB();
    if (totalRAM >= 32768)
        return 8192;
    if (totalRAM >= 16384)
        return 6144;
    if (totalRAM >= 12288)
        return 5120;
    if (totalRAM >= 8192)
        return 4096;
    if (totalRAM >= 6144)
        return 3072;
    return 2048;
}

void OptimizationPage::onGCPresetChanged()
{
    updateJvmPreview();
}

void OptimizationPage::onQuickOptimize()
{
    int mem = recommendMaxMem();
    m_memorySlider->setValue(mem);
    m_gcG1GC->setChecked(true);
    updateJvmPreview();
    QMessageBox::information(this, tr("Quick Optimize"),
                             tr("Settings have been tuned for your system.\n"
                                "Click \"Apply\" or \"OK\" to save them."));
}

QString OptimizationPage::buildJvmArgs() const
{
    QStringList args;
    args << "-XX:+UnlockExperimentalVMOptions";
    if (m_gcZGC->isChecked())
        args << "-XX:+UseZGC" << "-XX:ConcGCThreads=2";
    else if (m_gcShenandoah->isChecked())
        args << "-XX:+UseShenandoahGC";
    else if (m_gcParallel->isChecked())
        args << "-XX:+UseParallelGC" << "-XX:ParallelGCThreads=4";
    else
        args << "-XX:+UseG1GC" << "-XX:ConcGCThreads=2" << "-XX:ParallelGCThreads=4";
    return args.join(' ');
}

void OptimizationPage::updateJvmPreview()
{
    m_jvmPreview->setPlainText(buildJvmArgs());
}
