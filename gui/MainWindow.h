#pragma once

#include <QMainWindow>
#include <QDockWidget>
#include <QTreeView>
#include <QGroupBox>
#include <QAction>
#include "GLViewport.h"  // include full definition

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

private slots:
    void openMeshFile();

private:
    void setupDocks();
    void setupMenu();

    QDockWidget* fileDock;
    QDockWidget* paramsDock;
    QTreeView* fileTree;
    GLViewport* previewWidget;  // complete type available
    QWidget* paramsWidget;
    QAction* openAction;
};
