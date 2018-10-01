# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'compound.ui'
#
# Created by: PyQt4 UI code generator 4.11.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    def _fromUtf8(s):
        return s

try:
    _encoding = QtGui.QApplication.UnicodeUTF8

    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig, _encoding)
except AttributeError:
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig)


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName(_fromUtf8("MainWindow"))
        MainWindow.resize(800, 600)
        MainWindow.setAutoFillBackground(True)
        MainWindow.setToolButtonStyle(QtCore.Qt.ToolButtonIconOnly)
        MainWindow.setTabShape(QtGui.QTabWidget.Rounded)
        MainWindow.setDockNestingEnabled(False)
        MainWindow.setUnifiedTitleAndToolBarOnMac(False)
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.gridLayout_2 = QtGui.QGridLayout(self.centralwidget)
        self.gridLayout_2.setObjectName(_fromUtf8("gridLayout_2"))
        self.Calc = QtGui.QPushButton(self.centralwidget)
        self.Calc.setObjectName(_fromUtf8("Calc"))
        self.Calc.clicked.connect(self.calculate)
        self.gridLayout_2.addWidget(self.Calc, 9, 0, 1, 2)
        self.Rate = QtGui.QLabel(self.centralwidget)
        self.Rate.setMinimumSize(QtCore.QSize(0, 100))
        self.Rate.setMaximumSize(QtCore.QSize(100, 100))
        self.Rate.setObjectName(_fromUtf8("Rate"))
        self.gridLayout_2.addWidget(self.Rate, 3, 0, 1, 1)
        self.label = QtGui.QLabel(self.centralwidget)
        self.label.setObjectName(_fromUtf8("label"))
        self.gridLayout_2.addWidget(self.label, 1, 0, 1, 2)
        self.Principal = QtGui.QLabel(self.centralwidget)
        self.Principal.setMaximumSize(QtCore.QSize(100, 100))
        self.Principal.setObjectName(_fromUtf8("Principal"))
        self.gridLayout_2.addWidget(self.Principal, 2, 0, 1, 1)
        self.Amount = QtGui.QLabel(self.centralwidget)
        self.Amount.setMaximumSize(QtCore.QSize(100, 100))
        self.Amount.setObjectName(_fromUtf8("Amount"))
        self.gridLayout_2.addWidget(self.Amount, 5, 0, 1, 1)
        self.Years = QtGui.QLabel(self.centralwidget)
        self.Years.setMinimumSize(QtCore.QSize(0, 100))
        self.Years.setMaximumSize(QtCore.QSize(100, 100))
        self.Years.setObjectName(_fromUtf8("Years"))
        self.gridLayout_2.addWidget(self.Years, 4, 0, 1, 1)
        self.Years_2 = QtGui.QDoubleSpinBox(self.centralwidget)
        self.Years_2.setAccelerated(True)
        self.Years_2.setMaximum(1e+17)
        self.Years_2.setObjectName(_fromUtf8("Years_2"))
        self.gridLayout_2.addWidget(self.Years_2, 4, 1, 1, 1)
        self.Principal_2 = QtGui.QDoubleSpinBox(self.centralwidget)
        self.Principal_2.setAccelerated(True)
        self.Principal_2.setMaximum(1e+26)
        self.Principal_2.setObjectName(_fromUtf8("Principal_2"))
        self.gridLayout_2.addWidget(self.Principal_2, 2, 1, 1, 1)
        self.Rate_2 = QtGui.QDoubleSpinBox(self.centralwidget)
        self.Rate_2.setAccelerated(True)
        self.Rate_2.setMaximum(1e+27)
        self.Rate_2.setObjectName(_fromUtf8("Rate_2"))
        self.gridLayout_2.addWidget(self.Rate_2, 3, 1, 1, 1)
        self.Result = QtGui.QLCDNumber(self.centralwidget)
        self.Result.setFrameShape(QtGui.QFrame.StyledPanel)
        self.Result.setFrameShadow(QtGui.QFrame.Sunken)
        self.Result.setSmallDecimalPoint(True)
        self.Result.setSegmentStyle(QtGui.QLCDNumber.Filled)
        self.Result.setObjectName(_fromUtf8("Result"))
        self.gridLayout_2.addWidget(self.Result, 5, 1, 1, 1)
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtGui.QStatusBar(MainWindow)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def calculate(self):
        percent = float(self.Rate_2.value())
        prince = float(self.Principal_2.value())
        time = float(self.Years_2.value())
        answer = prince*(1+(percent/100))**time
        self.Result.display(str(float(answer)))

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(_translate("MainWindow", "Compound Interest Calculator", None))
        self.Calc.setText(_translate("MainWindow", "Calculate", None))
        self.Rate.setText(_translate(
            "MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600;\">Rate</span></p></body></html>", None))
        self.label.setText(_translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt; font-weight:600; text-decoration: underline;\">Compound</span><span style=\" font-size:20pt; font-weight:600; text-decoration: underline; color:#aa0000; vertical-align:super;\">Interest</span><span style=\" font-size:20pt; font-weight:600; text-decoration: underline; color:#55aa00; vertical-align:sub;\">Calculator</span><span style=\" font-size:20pt; font-weight:600; text-decoration: underline; color:#55aa00;\"/></p></body></html>", None))
        self.Principal.setText(_translate(
            "MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600;\">Principal</span></p></body></html>", None))
        self.Amount.setText(_translate(
            "MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600;\">Amount</span></p></body></html>", None))
        self.Years.setText(_translate(
            "MainWindow", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600;\">Years</span></p></body></html>", None))
        self.Years_2.setSuffix(_translate("MainWindow", " Years", None))
        self.Principal_2.setPrefix(_translate("MainWindow", "$ ", None))
        self.Rate_2.setSuffix(_translate("MainWindow", " %", None))


if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    MainWindow = QtGui.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
