# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'guess.ui'
#
# Created by: PyQt4 UI code generator 4.11.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui
from PyQt4.QtCore import QTimer
from PyQt4.QtGui import QApplication
import random
import time
from multiprocessing import Process

colors = ["Pink", "Green", "Red", "Blue", "Orange", "Yellow", "Black", "Purple", "Brown", "Grey"]
value = colors[random.randrange(len(colors))]
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
        MainWindow.resize(1013, 764)
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.verticalLayout = QtGui.QVBoxLayout(self.centralwidget)
        self.verticalLayout.setObjectName(_fromUtf8("verticalLayout"))
        self.label_2 = QtGui.QLabel(self.centralwidget)
        self.label_2.setObjectName(_fromUtf8("label_2"))
        self.verticalLayout.addWidget(self.label_2)
        self.label = QtGui.QLabel(self.centralwidget)
        self.label.setObjectName(_fromUtf8("label"))
        self.verticalLayout.addWidget(self.label)
        self.disp = QtGui.QLabel(self.centralwidget)
        self.disp.setObjectName(_fromUtf8("disp"))
        self.verticalLayout.addWidget(self.disp)
        self.lbl = QtGui.QTextEdit(self.centralwidget)
        self.lbl.setMaximumSize(QtCore.QSize(16777215, 100))
        self.lbl.setObjectName(_fromUtf8("lbl"))
        self.verticalLayout.addWidget(self.lbl)
        self.btn = QtGui.QPushButton(self.centralwidget)
        self.btn.setObjectName(_fromUtf8("btn"))
        self.btn.setShortcut("Ctrl+Q")
        self.verticalLayout.addWidget(self.btn)
        self.btn.clicked.connect(self.disp_text)
        self.btn.clicked.connect(self.download)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtGui.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 1013, 21))
        self.menubar.setObjectName(_fromUtf8("menubar"))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtGui.QStatusBar(MainWindow)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow", None))
        self.label_2.setText(_translate(
            "MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">Enter name of color not what is written.</span></p></body></html>", None))
        self.label.setText(_translate(
            "MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">Time left</span></p></body></html>", None))
        self.disp.setText(_translate(
            "MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:48pt; font-weight:600;\"><font color='" + random.choice(colors) + "'>" + "Type Start and press next" + "</font></p></body></html>", None))
        self.btn.setText(_translate("MainWindow", "Next", None))

    def disp_text(self):
        global value
        if str(self.lbl.toPlainText()).lower() == str(value).lower() or str(self.lbl.toPlainText()).lower() == ("Start").lower():
            pass
        else:
            sys.exit()
        value = colors[random.randrange(len(colors))]
        self.disp.setText(_translate(
            "MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:48pt; font-weight:600;\"><font color='" + value + "'>" + random.choice(colors) + "</font></p></body></html>", None))
        self.lbl.setText("")

    def download(self):

        for x in range(-1, 152):
            x -= 1
            if 150-x == 0:
                self.btn.click()
            else:
                pass
            time.sleep(0.01)
            QApplication.processEvents()
            self.label.setText(_translate(
                "MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">Time left: " + str(150 - x) + "</span></p></body></html>", None))


if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    MainWindow = QtGui.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
