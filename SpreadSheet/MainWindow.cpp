#include <QtWidgets>

#include "finddialog.h"
#include "GoToCellDialog.h"
#include "MainWindow.h"
#include "sortdialog.h"
#include "SpreadSheet.h"

MainWindow::MainWindow(QWidget* parent)
{
	spreadSheet = new SpreadSheet;
	setCentralWidget(spreadSheet);

	createActions();
	createMenus();
	createContextMenu();
	createToolBars();
	createStatusBar();

	readSettings();

	findDialog = 0;

	setWindowIcon(QIcon(":/images/Icon/SpreadSheet.png"));
	setCurrentFile("");
	//setAttribute(Qt::WA_DeleteOnClose);
}

void MainWindow::createActions()
{
	newAction = new QAction(tr("&New"), this);
	newAction->setIcon(QIcon(":/images/Icon/New.png"));
	newAction->setShortcut(QKeySequence::New);
	newAction->setStatusTip(tr("Create a new Spreadsheet File"));
	connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));

	openAction = new QAction(tr("&Open..."), this);
	openAction->setIcon(QIcon(":/images/Icon/Open.png"));
	openAction->setShortcut(QKeySequence::Open);
	openAction->setStatusTip(tr("Open an existing file..."));
	connect(openAction, SIGNAL(triggered()), this, SLOT(open()));

	saveAction = new QAction(tr("&Save..."), this);
	saveAction->setIcon(QIcon(":/images/Icon/Save.png"));
	saveAction->setShortcut(QKeySequence::Save);
	saveAction->setStatusTip(tr("Save file"));
	connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));

	saveAsAction = new QAction(tr("Save &As..."), this);
	saveAsAction->setStatusTip(tr("Save as another file format"));
	connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveAs()));

	for (int i = 0;i<MaxRecentFile;++i)
	{
		recentFileActions[i] = new QAction(this);
		recentFileActions[i]->setVisible(false);
		connect(recentFileActions[i], SIGNAL(triggered()), this, SLOT(openRecentFile()));
	}

	exitAction = new QAction(tr("E&xit"), this);
	exitAction->setShortcut(tr("Ctrl+Q"));
	exitAction->setStatusTip(tr("Exit the Application"));
	connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

	cutAction = new QAction(tr("Cu&t"), this);
	cutAction->setIcon(QIcon(":/images/Icon/Cut.png"));
	cutAction->setShortcut(QKeySequence::Cut);
	cutAction->setStatusTip(tr("Cut the current selection's contents to the clipboard"));
	connect(cutAction, SIGNAL(triggered()), spreadSheet, SLOT(cut()));

	copyAction = new QAction(tr("&Copy"), this);
	copyAction->setIcon(QIcon(":/images/Icon/Copy.png"));
	copyAction->setShortcut(QKeySequence::Copy);
	copyAction->setStatusTip(tr("Copy the current selection's contents to the clipboard"));
	connect(copyAction, SIGNAL(triggered()), spreadSheet, SLOT(copy()));

	pasteAction = new QAction(tr("&Paste"), this);
	pasteAction->setIcon(QIcon(":/images/Icon/Paste.png"));
	pasteAction->setShortcut(QKeySequence::Paste);
	pasteAction->setStatusTip(tr("Paste the clipboard's contents into the current selection"));
	connect(pasteAction, SIGNAL(triggered()), spreadSheet, SLOT(paste()));

	deleteAction = new QAction(tr("&Delete"), this);
	deleteAction->setShortcut(QKeySequence::Delete);
	deleteAction->setStatusTip(tr("Delete the current selection's contents"));
	connect(deleteAction, SIGNAL(triggered()), spreadSheet, SLOT(del()));

	selectRowAction = new QAction(tr("&Row"), this);
	selectRowAction->setStatusTip(tr("Select all the cells in the current row"));
	connect(selectRowAction, SIGNAL(triggered()), spreadSheet, SLOT(selectCurrentRow()));

	selectColumnAction = new QAction(tr("&Column"), this);
	selectColumnAction->setStatusTip(tr("Select all the cells in the current column"));
	connect(selectColumnAction, SIGNAL(triggered()), spreadSheet, SLOT(selectCurrentColumn()));

	selectAllAction = new QAction(tr("&All"), this);
	selectAllAction->setShortcut(QKeySequence::SelectAll);
	selectAllAction->setStatusTip(tr("Select all the cells in the spreadsheet"));
	connect(selectAllAction, SIGNAL(triggered()), spreadSheet, SLOT(selectAll()));

	findAction = new QAction(tr("&Find..."), this);
	findAction->setIcon(QIcon(":/images/Icon/Find.png"));
	findAction->setShortcut(QKeySequence::Find);
	findAction->setStatusTip(tr("Find a matching cell"));
	connect(findAction, SIGNAL(triggered()), this, SLOT(find()));

	goToCellAction = new QAction(tr("&Go to Cell..."), this);
	goToCellAction->setIcon(QIcon(":/images/Icon/GoTo.png"));
	goToCellAction->setShortcut(tr("Ctrl+G"));
	goToCellAction->setStatusTip(tr("Go to the specified cell"));
	connect(goToCellAction, SIGNAL(triggered()), this, SLOT(goToCell()));

	recalculateAction = new QAction(tr("&Recalculate"), this);
	recalculateAction->setShortcut(tr("F9"));
	recalculateAction->setStatusTip(tr("Recalculate all the spreadsheet's formulas"));
	connect(recalculateAction, SIGNAL(triggered()), spreadSheet, SLOT(recalculate()));


	sortAction = new QAction(tr("&Sort..."), this);
	sortAction->setStatusTip(tr("Sort the selected cells or all the cells"));
	connect(sortAction, SIGNAL(triggered()), this, SLOT(sort()));

	showGridAction = new QAction(tr("&All"),this);
	showGridAction->setCheckable(true);
	showGridAction->setChecked(spreadSheet->showGrid());
	showGridAction->setStatusTip(tr("Show or Hide the spreadsheet's grid"));
	connect(showGridAction, SIGNAL(toggled(bool)), spreadSheet, SLOT(setShowGrid(bool)));

	autoRecalcAction = new QAction(tr("&Auto-Recalculate"), this);
	autoRecalcAction->setCheckable(true);
	autoRecalcAction->setChecked(spreadSheet->autoRecalculate());
	autoRecalcAction->setStatusTip(tr("Switch auto-recalculation on/off"));
	connect(autoRecalcAction, SIGNAL(toggled(bool)), spreadSheet, SLOT(setAutoRecalculate(bool)));

	aboutAction = new QAction(tr("&About"), this);
	aboutAction->setStatusTip(tr("Show the Application's About box"));
	connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));

	aboutQtAction = new QAction(tr("About &Qt"));
	aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
	connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::createMenus()
{
	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(newAction);
	fileMenu->addAction(copyAction);
	fileMenu->addAction(saveAction);
	fileMenu->addAction(saveAsAction);
	separatorAction = fileMenu->addSeparator();
	for(int i = 0;i < MaxRecentFile;++i)
	{
		fileMenu->addAction(recentFileActions[i]);
	}
	fileMenu->addSeparator();
	fileMenu->addAction(exitAction);

	editMenu = menuBar()->addMenu(tr("&Edit"));
	editMenu->addAction(cutAction);
	editMenu->addAction(copyAction);
	editMenu->addAction(pasteAction);
	editMenu->addAction(deleteAction);

	selectSubMenu = editMenu->addMenu(tr("&Select"));
	selectSubMenu->addAction(selectRowAction);
	selectSubMenu->addAction(selectColumnAction);
	selectSubMenu->addAction(selectAllAction);

	editMenu->addSeparator();
	editMenu->addAction(findAction);
	editMenu->addAction(goToCellAction);

	toolsMenu = menuBar()->addMenu(tr("&Tools"));
	toolsMenu->addAction(recalculateAction);
	toolsMenu->addAction(sortAction);

	optionsMenu = menuBar()->addMenu(tr("&Options"));
	optionsMenu->addAction(showGridAction);
	optionsMenu->addAction(autoRecalcAction);

	menuBar()->addSeparator();

	helpMenu = menuBar()->addMenu(tr("&Help"));
	helpMenu->addAction(aboutAction);
	helpMenu->addAction(aboutQtAction);
}

void MainWindow::createContextMenu()
{
	spreadSheet->addAction(cutAction);
	spreadSheet->addAction(copyAction);
	spreadSheet->addAction(pasteAction);
	spreadSheet->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void MainWindow::createToolBars()
{
	fileToolBar = addToolBar(tr("&File"));
	fileToolBar->addAction(newAction);
	fileToolBar->addAction(openAction);
	fileToolBar->addAction(saveAction);

	editToolBar = addToolBar(tr("&Edit"));
	editToolBar->addAction(cutAction);
	editToolBar->addAction(copyAction);
	editToolBar->addAction(pasteAction);
	editToolBar->addSeparator();
	editToolBar->addAction(findAction);
	editToolBar->addAction(goToCellAction);
}

void MainWindow::createStatusBar()
{
	locationLabel = new QLabel(" W999 ");
	locationLabel->setAlignment(Qt::AlignHCenter);
	locationLabel->setMinimumSize(locationLabel->sizeHint());

	formulaLabel = new QLabel;
	formulaLabel->setIndent(3);

	statusBar()->addWidget(locationLabel);
	statusBar()->addWidget(formulaLabel, 1);

	connect(spreadSheet, SIGNAL(currentCellChanged(int, int, int, int)), this, SLOT(updateStatusBar()));
	connect(spreadSheet, SIGNAL(modified()), this, SLOT(spreadsheetModified()));

	updateStatusBar();
}


void MainWindow::updateStatusBar()
{
	locationLabel->setText(spreadSheet->currentLocation());
	formulaLabel->setText(spreadSheet->currentFormula());
}

void MainWindow::spreadsheetModified()
{
	setWindowModified(true);
	updateStatusBar();
}

void MainWindow::newFile()
{
	MainWindow* mainWin = new MainWindow;
	mainWin->show();
}

bool MainWindow::okToContinue()
{
	if(isWindowModified())
	{
		int r = QMessageBox::warning(this, tr("SpreadSheet"), tr("The document has been modified.\n""Do you want to save your changes?"),QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
		if(r == QMessageBox::Yes)
		{
			return save();
		}
		else if(r == QMessageBox::Cancel)
		{
			return false;
		}
	}
	return true;
}

void MainWindow::open()
{
	if(okToContinue())
	{
		QString fileName = QFileDialog::getOpenFileName(this, tr("Open Spreadsheet"), ".", tr("Spreadsheet files (*.sp)\n""Comma-Separated Values files (*.csv)\n""Lotus 1-2-3 files (*.wk1 *.wks)"));
		if(!fileName.isEmpty())
		{
			loadFile(fileName);
		}
	}
}

bool MainWindow::loadFile(const QString& fileName)
{
	if (!spreadSheet->readFile(fileName))
	{
		statusBar()->showMessage(tr("Loading Canceled!"), 2000);
		return false;
	}

	setCurrentFile(fileName);
	statusBar()->showMessage(tr("File Loaded"), 2000);
	return true;
}

bool MainWindow::saveFile(const QString& fileName)
{
	if (!spreadSheet->writeFile(fileName)) {
		statusBar()->showMessage(tr("Saving canceled"), 2000);
		return false;
	}

	setCurrentFile(fileName);
	statusBar()->showMessage(tr("File saved"), 2000);
	return true;
}

bool MainWindow::save()
{
	if (curFile.isEmpty()) {
		return saveAs();
	}
	else {
		return saveFile(curFile);
	}
}

bool MainWindow::saveAs()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save SpreadSheet"), ".", tr("Spreadsheet files (*.sp)"));
	if(fileName.isEmpty())
	{
		return false;
	}

	return saveFile(fileName);
}

void MainWindow::closeEvent(QCloseEvent* event)
{
	if(okToContinue())
	{
		writeSettings();
		event->accept();
	}
	else
	{
		event->ignore();
	}
}

void MainWindow::setCurrentFile(const QString& fileName)
{
	curFile = fileName;
	setWindowModified(false);

	QString shownName = tr("Untitled");
	if(!curFile.isEmpty())
	{
		shownName = strippedName(curFile);
		recentFiles.removeAll(curFile);
		recentFiles.prepend(curFile);
		updateRecentFileActions();
	}

	setWindowTitle(tr("%1[*] - %2").arg(shownName).arg(tr("Spreadsheet")));
}

QString MainWindow::strippedName(const QString& fullFileName)
{
	return QFileInfo(fullFileName).fileName();
}

void MainWindow::updateRecentFileActions()
{
	QMutableStringListIterator it(recentFiles);

	while(it.hasNext())
	{
		if(!QFile::exists(it.next()))
		{
			it.remove();
		}
	}


	for (int j = 0; j < MaxRecentFile; ++j)
	{
		if(j < recentFiles.count())
		{
			QString text = tr("&%1 %2").arg(j + 1).arg(strippedName(recentFiles[j]));
			recentFileActions[j]->setText(text);
			recentFileActions[j]->setData(recentFiles[j]);
			recentFileActions[j]->setVisible(true);
		}
		else
		{
			recentFileActions[j]->setVisible(false);
		}
	}
	separatorAction->setVisible(!recentFiles.empty());
}

void MainWindow::openRecentFile()
{
	if(okToContinue())
	{
		QAction* action = qobject_cast<QAction*>(sender());
		if(action)
		{
			loadFile(action->data().toString());
		}
	}
}

void MainWindow::find()
{
	if(!findDialog)
	{
		findDialog = new finddialog(this);
		connect(findDialog, SIGNAL(findNext(const QString & Qt::CaseSensitivity)), spreadSheet, SLOT(findNext(const QString & Qt::CaseSensitivity)));
		connect(findDialog, SIGNAL(findPrevious(const QString & Qt::CaseSensitivity)), spreadSheet, SLOT(findPrevious(const QString & Qt::CaseSensitivity)));

	}

	findDialog->show();
	findDialog->raise();
	findDialog->activateWindow();
}

void MainWindow::goToCell()
{
	GoToCellDialog* dialog = new GoToCellDialog(this);
	if(dialog->exec())
	{
		QString str = dialog->lineEdit->text().toUpper();
		spreadSheet->setCurrentCell(str.mid(1).toInt() - 1, str[0].unicode() - 'A');
	}
	delete dialog;
}

void MainWindow::sort()
{
	SortDialog dialog(this);
	QTableWidgetSelectionRange range = spreadSheet->selectedRange();
	dialog.SetColumnRange('A' + range.leftColumn(), 'A' + range.rightColumn());

	if (dialog.exec()) {
		SpreadsheetCompare compare;
		compare.keys[0] =
			dialog.primaryColumnCombo->currentIndex();
		compare.keys[1] =
			dialog.secondaryColumnCombo->currentIndex() - 1;
		compare.keys[2] =
			dialog.tertiaryColumnCombo->currentIndex() - 1;
		compare.ascending[0] =
			(dialog.primaryOrderCombo->currentIndex() == 0);
		compare.ascending[1] =
			(dialog.secondaryOrderCombo->currentIndex() == 0);
		compare.ascending[2] =
			(dialog.teritaryOrderCombo->currentIndex() == 0);
		spreadSheet->sort(compare);
	}
}

void MainWindow::about()
{
	QMessageBox::about(this, tr("About SpreadSheet"), tr("<h2>SpreadSheet 1.0</h2>""<p>Copyright &copy; 2022 Individual Work""<p>Spreadsheet is a small application that demonstrates QAction,QMainWindow,QMenuBar""QStatusBar,QTableWidget,QToolBar, and many other ""Qt classes."));
}

void MainWindow::writeSettings()
{
	QSettings settings("Individual Work.", "SpreadSheet");

	settings.setValue("geometry", saveGeometry());
	settings.setValue("recentFiles", recentFiles);
	settings.setValue("showGrid", showGridAction->isChecked());
	settings.setValue("autoRecalc", autoRecalcAction->isChecked());
}

void MainWindow::readSettings()
{
	QSettings settings("Individual Work", "SpreadSheet");

	restoreGeometry(settings.value("geometry").toByteArray());

	recentFiles = settings.value("recentFiles").toStringList();
	updateRecentFileActions();

	bool autoRecalc = settings.value("autoRecalc", true).toBool();
	autoRecalcAction->setChecked(autoRecalc);
}

