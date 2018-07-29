# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'calculator.ui'
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
        MainWindow.resize(761, 513)
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.gridLayout = QtGui.QGridLayout(self.centralwidget)
        self.gridLayout.setObjectName(_fromUtf8("gridLayout"))
        self.calcu = QtGui.QPushButton(self.centralwidget)
        self.calcu.setObjectName(_fromUtf8("calcu"))
        self.calcu.clicked.connect(self.calculate)
        self.gridLayout.addWidget(self.calcu, 3, 0, 1, 1)
        self.result = QtGui.QTextEdit(self.centralwidget)
        self.result.setMaximumSize(QtCore.QSize(800, 200))
        self.result.setObjectName(_fromUtf8("result"))
        self.gridLayout.addWidget(self.result, 4, 0, 1, 1)
        self.horizontalLayout = QtGui.QHBoxLayout()
        self.horizontalLayout.setObjectName(_fromUtf8("horizontalLayout"))
        self.label = QtGui.QLabel(self.centralwidget)
        self.label.setMaximumSize(QtCore.QSize(50, 50))
        self.label.setObjectName(_fromUtf8("label"))
        self.horizontalLayout.addWidget(self.label)
        self.cost = QtGui.QTextEdit(self.centralwidget)
        self.cost.setMaximumSize(QtCore.QSize(200, 100))
        self.cost.setObjectName(_fromUtf8("cost"))
        self.horizontalLayout.addWidget(self.cost)
        self.gridLayout.addLayout(self.horizontalLayout, 1, 0, 1, 1)
        self.horizontalLayout_2 = QtGui.QHBoxLayout()
        self.horizontalLayout_2.setObjectName(_fromUtf8("horizontalLayout_2"))
        self.label_2 = QtGui.QLabel(self.centralwidget)
        self.label_2.setObjectName(_fromUtf8("label_2"))
        self.horizontalLayout_2.addWidget(self.label_2)
        self.r = QtGui.QDoubleSpinBox(self.centralwidget)
        self.r.setObjectName(_fromUtf8("r"))
        self.horizontalLayout_2.addWidget(self.r)
        self.gridLayout.addLayout(self.horizontalLayout_2, 2, 0, 1, 1)
        self.label_3 = QtGui.QLabel(self.centralwidget)
        self.label_3.setObjectName(_fromUtf8("label_3"))
        self.gridLayout.addWidget(self.label_3, 0, 0, 1, 1)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtGui.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 761, 21))
        self.menubar.setObjectName(_fromUtf8("menubar"))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtGui.QStatusBar(MainWindow)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def calculate(self):
        percent = float(self.r.value())
        rate_initial = float(self.cost.toPlainText())
        answer = (rate_initial * ((100 + (percent)) / 100))
        self.result.setPlainText(str(float(answer)))

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(_translate(
            "MainWindow", "Tax Calculator", None))
        self.calcu.setText(_translate("MainWindow", "Calculate", None))
        self.label.setText(_translate("MainWindow", "Price", None))
        self.label_2.setText(_translate("MainWindow", "Tax Rate", None))
        self.label_3.setText(_translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:600; text-decoration: underline; color:#00ff7f;\">T</span><span style=\" font-size:24pt; font-weight:600; text-decoration: underline; color:#ffaa7f;\">a</span><span style=\" font-size:24pt; font-weight:600; text-decoration: underline; color:#aa557f;\">x</span><span style=\" font-size:24pt; font-weight:600; text-decoration: underline; color:#aaaaff;\">C</span><span style=\" font-size:24pt; font-weight:600; text-decoration: underline; color:#ff55ff;\">a</span><span style=\" font-size:24pt; font-weight:600; text-decoration: underline; color:#0000ff;\">l</span><span style=\" font-size:24pt; font-weight:600; text-decoration: underline; color:#ffaa00;\">c</span><span style=\" font-size:24pt; font-weight:600; text-decoration: underline; color:#5555ff;\">u</span><span style=\" font-size:24pt; font-weight:600; text-decoration: underline; color:#5500ff;\">l</span><span style=\" font-size:24pt; font-weight:600; text-decoration: underline; color:#aa0000;\">a</span><span style=\" font-size:24pt; font-weight:600; text-decoration: underline; color:#000000;\">t</span><span style=\" font-size:24pt; font-weight:600; text-decoration: underline; color:#55ffff;\">o</span><span style=\" font-size:24pt; font-weight:600; text-decoration: underline; color:#005500;\">r</span></p></body></html>", None))


if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    MainWindow = QtGui.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
