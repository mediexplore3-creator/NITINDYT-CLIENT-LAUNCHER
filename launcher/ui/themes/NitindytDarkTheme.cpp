#include "NitindytDarkTheme.h"

#include <QObject>

QString NitindytDarkTheme::id()
{
    return "nitindyt-dark";
}

QString NitindytDarkTheme::name()
{
    return QObject::tr("Nitindyt Dark");
}

QPalette NitindytDarkTheme::colorScheme()
{
    QPalette p;
    p.setColor(QPalette::Window, QColor(13, 17, 23));
    p.setColor(QPalette::WindowText, QColor(230, 237, 243));
    p.setColor(QPalette::Base, QColor(22, 27, 34));
    p.setColor(QPalette::AlternateBase, QColor(28, 35, 49));
    p.setColor(QPalette::ToolTipBase, QColor(31, 41, 55));
    p.setColor(QPalette::ToolTipText, QColor(243, 244, 246));
    p.setColor(QPalette::Text, QColor(230, 237, 243));
    p.setColor(QPalette::Button, QColor(33, 38, 45));
    p.setColor(QPalette::ButtonText, QColor(201, 209, 217));
    p.setColor(QPalette::BrightText, QColor(255, 68, 102));
    p.setColor(QPalette::Link, QColor(0, 212, 255));
    p.setColor(QPalette::LinkVisited, QColor(168, 85, 247));
    p.setColor(QPalette::Highlight, QColor(0, 212, 255));
    p.setColor(QPalette::HighlightedText, Qt::black);
    p.setColor(QPalette::PlaceholderText, QColor(107, 114, 128));
    return fadeInactive(p, fadeAmount(), fadeColor());
}

double NitindytDarkTheme::fadeAmount()
{
    return 0.4;
}

QColor NitindytDarkTheme::fadeColor()
{
    return QColor(13, 17, 23);
}

bool NitindytDarkTheme::hasStyleSheet()
{
    return true;
}

QString NitindytDarkTheme::tooltip()
{
    return QObject::tr("A modern dark theme with neon gaming accents");
}

QString NitindytDarkTheme::appStyleSheet()
{
    return QStringLiteral(R"(
        * {
            font-family: "Segoe UI", "SF Pro", "Helvetica Neue", Arial, sans-serif;
        }

        QMainWindow, QDialog, QWidget#centralWidget {
            background-color: #0d1117;
        }

        /* === SIDEBAR === */
        QListView#pageList {
            background-color: #11161e;
            border: none;
            border-right: 1px solid #1c2331;
            outline: none;
            padding: 6px 0;
        }

        QListView#pageList::item {
            padding: 10px 16px;
            border-radius: 8px;
            margin: 2px 8px;
            color: #8b949e;
        }

        QListView#pageList::item:selected {
            background-color: rgba(0, 212, 255, 0.1);
            color: #00d4ff;
            border-left: 3px solid #00d4ff;
            margin-left: 5px;
        }

        QListView#pageList::item:hover:!selected {
            background-color: rgba(255, 255, 255, 0.04);
            color: #c9d1d9;
        }

        /* === HEADERS === */
        QLabel#pageHeader {
            font-size: 20px;
            font-weight: 700;
            color: #e6edf3;
            padding: 8px 0 4px 0;
            border-bottom: 2px solid qlineargradient(x1:0, y1:0, x2:1, y2:0,
                stop:0 rgba(0,212,255,0.6),
                stop:0.5 rgba(0,212,255,0.3),
                stop:1 transparent);
            margin-bottom: 12px;
        }

        /* === GLASS CARDS === */
        QGroupBox, QFrame[class="card"], #newsFrame {
            background-color: rgba(22, 27, 34, 0.85);
            border: 1px solid rgba(48, 54, 61, 0.6);
            border-radius: 12px;
            padding: 20px 16px 12px 16px;
            font-weight: 600;
            color: #e6edf3;
        }

        QGroupBox::title {
            subcontrol-origin: margin;
            subcontrol-position: top left;
            padding: 6px 12px;
            margin-left: 8px;
            background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                stop:0 #1c2331,
                stop:1 #161b22);
            border: 1px solid rgba(0, 212, 255, 0.25);
            border-radius: 8px;
            color: #00d4ff;
            font-size: 11px;
            font-weight: 700;
            letter-spacing: 0.8px;
            text-transform: uppercase;
        }

        /* === PUSH BUTTONS === */
        QPushButton {
            background-color: #21262d;
            color: #c9d1d9;
            border: 1px solid #30363d;
            border-radius: 8px;
            padding: 8px 18px;
            font-weight: 500;
        }

        QPushButton:hover {
            background-color: #2a2f38;
            border-color: rgba(0, 212, 255, 0.5);
            color: #e6edf3;
        }

        QPushButton:pressed {
            background-color: #161b22;
        }

        QPushButton:disabled {
            background-color: #161b22;
            color: #484f58;
            border-color: #21262d;
        }

        QPushButton#primaryButton, QPushButton[class="primary"] {
            background: qlineargradient(x1:0, y1:0, x2:1, y2:1,
                stop:0 #00d4ff,
                stop:1 #0099cc);
            color: #0d1117;
            border: none;
            font-weight: 700;
        }

        QPushButton#primaryButton:hover, QPushButton[class="primary"]:hover {
            background: qlineargradient(x1:0, y1:0, x2:1, y2:1,
                stop:0 #33ddff,
                stop:1 #00b8d9);
        }

        QPushButton#primaryButton:pressed, QPushButton[class="primary"]:pressed {
            background: qlineargradient(x1:0, y1:0, x2:1, y2:1,
                stop:0 #00b8d9,
                stop:1 #0088aa);
        }

        /* === LINE EDITS === */
        QLineEdit {
            background-color: #0d1117;
            color: #e6edf3;
            border: 1px solid #30363d;
            border-radius: 8px;
            padding: 8px 12px;
            selection-background-color: rgba(0, 212, 255, 0.3);
        }

        QLineEdit:focus {
            border-color: #00d4ff;
            background-color: #11161e;
        }

        /* === COMBO BOX === */
        QComboBox {
            background-color: #21262d;
            color: #c9d1d9;
            border: 1px solid #30363d;
            border-radius: 8px;
            padding: 8px 12px;
        }

        QComboBox:hover {
            border-color: rgba(0, 212, 255, 0.5);
        }

        QComboBox::drop-down {
            border: none;
            padding-right: 8px;
        }

        QComboBox::down-arrow {
            image: none;
            border: solid #8b949e;
            border-width: 0 2px 2px 0;
            padding: 3px;
            transform: rotate(45deg);
            margin-right: 4px;
        }

        QComboBox QAbstractItemView {
            background-color: #161b22;
            color: #c9d1d9;
            border: 1px solid rgba(0, 212, 255, 0.3);
            border-radius: 8px;
            padding: 4px;
            selection-background-color: rgba(0, 212, 255, 0.12);
            selection-color: #00d4ff;
            outline: none;
        }

        QComboBox QAbstractItemView::item {
            padding: 6px 10px;
            border-radius: 6px;
        }

        QComboBox QAbstractItemView::item:hover {
            background-color: rgba(255, 255, 255, 0.04);
        }

        /* === SPIN BOX === */
        QSpinBox, QDoubleSpinBox {
            background-color: #0d1117;
            color: #e6edf3;
            border: 1px solid #30363d;
            border-radius: 8px;
            padding: 6px 10px;
        }

        QSpinBox:focus, QDoubleSpinBox:focus {
            border-color: #00d4ff;
        }

        QSpinBox::up-button, QDoubleSpinBox::up-button {
            border-left: 1px solid #30363d;
            border-bottom: 1px solid #30363d;
            border-top-right-radius: 8px;
        }

        QSpinBox::down-button, QDoubleSpinBox::down-button {
            border-left: 1px solid #30363d;
            border-bottom-right-radius: 8px;
        }

        /* === CHECK BOX === */
        QCheckBox {
            color: #c9d1d9;
            spacing: 8px;
        }

        QCheckBox::indicator {
            width: 18px;
            height: 18px;
            border: 2px solid #30363d;
            border-radius: 4px;
            background-color: #0d1117;
        }

        QCheckBox::indicator:checked {
            background-color: #00d4ff;
            border-color: #00d4ff;
        }

        QCheckBox::indicator:hover {
            border-color: #00d4ff;
        }

        QCheckBox:hover {
            color: #e6edf3;
        }

        /* === RADIO BUTTON === */
        QRadioButton {
            color: #c9d1d9;
            spacing: 8px;
        }

        QRadioButton::indicator {
            width: 18px;
            height: 18px;
            border: 2px solid #30363d;
            border-radius: 10px;
            background-color: #0d1117;
        }

        QRadioButton::indicator:checked {
            background-color: #00d4ff;
            border-color: #00d4ff;
        }

        QRadioButton::indicator:hover {
            border-color: #00d4ff;
        }

        /* === TABLES & LISTS === */
        QTableView, QTreeView {
            background-color: #0d1117;
            color: #c9d1d9;
            border: 1px solid #21262d;
            border-radius: 10px;
            selection-background-color: rgba(0, 212, 255, 0.1);
            selection-color: #00d4ff;
            outline: none;
        }

        QTableView::item, QTreeView::item {
            padding: 8px 10px;
            border-radius: 4px;
        }

        QTableView::item:hover, QTreeView::item:hover {
            background-color: rgba(255, 255, 255, 0.03);
        }

        QTableView::item:selected, QTreeView::item:selected {
            background-color: rgba(0, 212, 255, 0.1);
            color: #00d4ff;
        }

        QHeaderView::section {
            background-color: #11161e;
            color: #8b949e;
            border: none;
            border-bottom: 1px solid #21262d;
            padding: 10px 12px;
            font-weight: 600;
            font-size: 11px;
            text-transform: uppercase;
            letter-spacing: 0.5px;
        }

        QHeaderView::section:hover {
            color: #c9d1d9;
        }

        /* === SCROLL BARS === */
        QScrollBar:vertical {
            background: transparent;
            width: 8px;
            border: none;
        }

        QScrollBar::handle:vertical {
            background: #30363d;
            min-height: 30px;
            border-radius: 4px;
        }

        QScrollBar::handle:vertical:hover {
            background: #484f58;
        }

        QScrollBar::handle:vertical:pressed {
            background: #00d4ff;
        }

        QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {
            height: 0;
            border: none;
        }

        QScrollBar:horizontal {
            background: transparent;
            height: 8px;
            border: none;
        }

        QScrollBar::handle:horizontal {
            background: #30363d;
            min-width: 30px;
            border-radius: 4px;
        }

        QScrollBar::handle:horizontal:hover {
            background: #484f58;
        }

        QScrollBar::handle:horizontal:pressed {
            background: #00d4ff;
        }

        QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {
            width: 0;
            border: none;
        }

        /* === TAB WIDGET === */
        QTabWidget::pane {
            background-color: rgba(22, 27, 34, 0.85);
            border: 1px solid #21262d;
            border-radius: 10px;
            padding: 4px;
        }

        QTabBar::tab {
            background-color: #21262d;
            color: #8b949e;
            border: 1px solid #30363d;
            border-bottom: none;
            border-top-left-radius: 8px;
            border-top-right-radius: 8px;
            padding: 8px 18px;
            margin-right: 2px;
            font-weight: 500;
        }

        QTabBar::tab:selected {
            background-color: rgba(22, 27, 34, 0.85);
            color: #00d4ff;
            border-bottom: 2px solid #00d4ff;
        }

        QTabBar::tab:hover:!selected {
            background-color: #2a2f38;
            color: #c9d1d9;
        }

        /* === PROGRESS BAR === */
        QProgressBar {
            background-color: #21262d;
            border: none;
            border-radius: 6px;
            text-align: center;
            color: #e6edf3;
            font-size: 11px;
            font-weight: 600;
            height: 14px;
        }

        QProgressBar::chunk {
            background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                stop:0 #00d4ff,
                stop:0.5 #7c3aed,
                stop:1 #ec4899);
            border-radius: 6px;
        }

        /* === SLIDER === */
        QSlider::groove:horizontal {
            background: #21262d;
            height: 6px;
            border-radius: 3px;
        }

        QSlider::handle:horizontal {
            background: qlineargradient(x1:0, y1:0, x2:1, y2:1,
                stop:0 #00d4ff,
                stop:1 #0099cc);
            width: 20px;
            height: 20px;
            margin: -7px 0;
            border-radius: 10px;
            border: 2px solid #0d1117;
        }

        QSlider::handle:horizontal:hover {
            background: qlineargradient(x1:0, y1:0, x2:1, y2:1,
                stop:0 #33ddff,
                stop:1 #00b8d9);
            width: 22px;
            height: 22px;
            margin: -8px 0;
            border-radius: 11px;
        }

        QSlider::sub-page:horizontal {
            background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                stop:0 #00d4ff,
                stop:1 #7c3aed);
            border-radius: 3px;
        }

        /* === TOOLTIP === */
        QToolTip {
            color: #f3f4f6;
            background-color: rgba(31, 41, 55, 0.95);
            border: 1px solid rgba(0, 212, 255, 0.3);
            border-radius: 8px;
            padding: 8px 12px;
            font-size: 12px;
        }

        /* === MENU === */
        QMenuBar {
            background-color: #0d1117;
            border-bottom: 1px solid #1c2331;
            padding: 2px 4px;
        }

        QMenuBar::item {
            background: transparent;
            color: #8b949e;
            padding: 6px 12px;
            border-radius: 6px;
        }

        QMenuBar::item:selected {
            background-color: #21262d;
            color: #e6edf3;
        }

        QMenu {
            background-color: rgba(22, 27, 34, 0.97);
            border: 1px solid rgba(0, 212, 255, 0.2);
            border-radius: 10px;
            padding: 6px;
        }

        QMenu::item {
            padding: 8px 32px 8px 14px;
            border-radius: 6px;
            color: #c9d1d9;
        }

        QMenu::item:selected {
            background-color: rgba(0, 212, 255, 0.1);
            color: #00d4ff;
        }

        QMenu::separator {
            height: 1px;
            background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                stop:0 transparent,
                stop:0.5 #30363d,
                stop:1 transparent);
            margin: 4px 8px;
        }

        /* === STATUS BAR === */
        QStatusBar {
            background-color: #11161e;
            border-top: 1px solid #1c2331;
            color: #8b949e;
            font-size: 12px;
        }

        /* === SPLITTER === */
        QSplitter::handle {
            background-color: #1c2331;
        }

        QSplitter::handle:horizontal {
            width: 1px;
        }

        QSplitter::handle:vertical {
            height: 1px;
        }

        /* === DIALOGS === */
        QDialog {
            background-color: #0d1117;
        }

        /* === LABELS === */
        QLabel {
            color: #c9d1d9;
        }

        QLabel[heading="true"] {
            font-size: 16px;
            font-weight: 700;
            color: #e6edf3;
        }

        QLabel[subheading="true"] {
            font-size: 13px;
            font-weight: 500;
            color: #8b949e;
        }

        /* === TEXT EDIT / PLAIN TEXT === */
        QTextEdit, QPlainTextEdit {
            background-color: #0d1117;
            color: #e6edf3;
            border: 1px solid #30363d;
            border-radius: 8px;
            padding: 8px;
            selection-background-color: rgba(0, 212, 255, 0.3);
        }

        QTextEdit:focus, QPlainTextEdit:focus {
            border-color: #00d4ff;
        }

        /* === INSTANCE VIEW === */
        #instanceView {
            background-color: #0d1117;
            border: none;
            border-radius: 12px;
        }

        /* === TOOL BUTTONS === */
        QToolButton {
            background-color: transparent;
            color: #8b949e;
            border: none;
            border-radius: 6px;
            padding: 6px;
        }

        QToolButton:hover {
            background-color: rgba(255, 255, 255, 0.06);
            color: #c9d1d9;
        }

        QToolButton:pressed {
            background-color: rgba(0, 212, 255, 0.1);
            color: #00d4ff;
        }
    )");
}
