/*
podiceps2 - pocket dictionary

Copyright (C) 2022 S.V.I 'Vilcrow', <vilcrow.net>
--------------------------------------------------------------------------------
LICENCE:
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
--------------------------------------------------------------------------------
*/

#include <QMenuBar>
#include <QFileDialog>
#include "mainwindow.h"

MainWindow::MainWindow()
{
	setWindowTitle("podiceps2");
	createMenus();
	dictWidget = new DictionaryWidget;
	setCentralWidget(dictWidget);
	statusBar = new QStatusBar;
	setStatusBar(statusBar);
	connect(dictWidget, &DictionaryWidget::sendMessage, this, &MainWindow::showMessage);
}

void MainWindow::createMenus()
{
	fileMenu = menuBar()->addMenu(tr("&File"));
	openAct = new QAction(tr("&Open..."), this);
	openAct->setShortcut(Qt::CTRL + Qt::Key_O);
	fileMenu->addAction(openAct);
	connect(openAct, &QAction::triggered, this, &MainWindow::openFile);
	saveAct = new QAction(tr("&Save As..."), this);
	saveAct->setShortcut(Qt::CTRL + Qt::Key_S);
	fileMenu->addAction(saveAct);
	connect(saveAct, &QAction::triggered, this, &MainWindow::saveFile);
	fileMenu->addSeparator();
	exitAct = new QAction(tr("E&xit"), this);
	exitAct->setShortcut(Qt::CTRL + Qt::Key_W);
	fileMenu->addAction(exitAct);
	connect(exitAct, &QAction::triggered, this, &QWidget::close);
	toolsMenu = menuBar()->addMenu(tr("&Tools"));
	openStatisticsAct = new QAction(tr("&Statistics"), this);
	toolsMenu->addAction(openStatisticsAct);
	connect(openStatisticsAct, &QAction::triggered, this,
			&MainWindow::openStatistics);
	openHelpAct = new QAction(tr("&Help"), this);
	toolsMenu->addAction(openHelpAct);
	connect(openHelpAct, &QAction::triggered, this,
			&MainWindow::openHelp);
	toolsMenu->addSeparator();
	openAboutAct = new QAction(tr("&About"), this);
	toolsMenu->addAction(openAboutAct);
	connect(openAboutAct, &QAction::triggered, this,
			&MainWindow::openAbout);
/*need fix
	connect(dictWidget, &DictionaryWidget::selectionChanged,
			this, &MainWindow::updateActions);
*/
}

void MainWindow::openFile()
{
	QString fileName = QFileDialog::getOpenFileName(this);
	if(!fileName.isEmpty())
		dictWidget->readFromFile(fileName);
}

void MainWindow::saveFile()
{
	QString fileName = QFileDialog::getSaveFileName(this);
	if(!fileName.isEmpty())
		dictWidget->writeToFile(fileName);
}
/* moved to DictionaryWidget
void MainWindow::updateActions(const QItemSelection &selection)
{
	QModelIndexList indexes = selection.indexes();
	if(!indexes.isEmpty()) {
		dictWidget->getDeleteButton()->setEnabled(true);
		dictWidget->getEditButton()->setEnabled(true);
	}
	else {
		dictWidget->getDeleteButton()->setEnabled(false);
		dictWidget->getEditButton()->setEnabled(false);
	}
}
*/
void MainWindow::showMessage(const QString &msg)
{
	statusBar->showMessage(msg);
}

void MainWindow::openStatistics()
{

}

void MainWindow::openHelp()
{

}

void MainWindow::openAbout()
{

}
