#include "MainWindow.h"
#include <QTreeView>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QMenuBar>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setWindowTitle("S9Slicer");
    resize(1200, 800);
    setupMenu();
    setupDocks();
}

MainWindow::~MainWindow() = default;

void MainWindow::setupMenu() {
    QMenu* fileMenu = menuBar()->addMenu(tr("&File"));
    openAction = fileMenu->addAction(tr("&Open Mesh..."));
    connect(openAction, &QAction::triggered, this, &MainWindow::openMeshFile);
}

void MainWindow::setupDocks() {
    fileTree = new QTreeView;
    fileDock = new QDockWidget(tr("Project & Files"), this);
    fileDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    fileDock->setWidget(fileTree);
    addDockWidget(Qt::LeftDockWidgetArea, fileDock);

    previewWidget = new GLViewport(this);
    QDockWidget* previewDock = new QDockWidget(tr("Preview"), this);
    previewDock->setAllowedAreas(Qt::AllDockWidgetAreas);
    previewDock->setWidget(previewWidget);
    addDockWidget(Qt::RightDockWidgetArea, previewDock);

    paramsWidget = new QWidget;
    QVBoxLayout* paramsLayout = new QVBoxLayout;
    QGroupBox* layerGroup = new QGroupBox(tr("Layer Settings"));
    paramsLayout->addWidget(layerGroup);
    paramsWidget->setLayout(paramsLayout);
    paramsDock = new QDockWidget(tr("Slice Parameters"), this);
    paramsDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    paramsDock->setWidget(paramsWidget);
    addDockWidget(Qt::RightDockWidgetArea, paramsDock);
}

void MainWindow::openMeshFile() {
    QString filter = tr("Mesh Files (*.obj *.stl)");
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Mesh"), {}, filter);
    if (!fileName.isEmpty()) {
        if (!previewWidget->loadMesh(fileName)) {
            QMessageBox::warning(this, tr("Error"), tr("Failed to load mesh."));
        }
    }
}
