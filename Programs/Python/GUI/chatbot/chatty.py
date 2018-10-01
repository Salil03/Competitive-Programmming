# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'untitled.ui'
#
# Created by: PyQt4 UI code generator 4.11.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui
from chatterbot import ChatBot
from chatterbot.utils import input_function
import easygui
import win32com.client as wincl

speak = wincl.Dispatch("SAPI.SpVoice")

bot = ChatBot("Chatty")

CONVERSATION_ID = bot.storage.create_conversation()


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
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.verticalLayout = QtGui.QVBoxLayout(self.centralwidget)
        self.verticalLayout.setObjectName(_fromUtf8("verticalLayout"))
        self.label = QtGui.QLabel(self.centralwidget)
        self.label.setMaximumSize(QtCore.QSize(16777215, 80))
        self.label.setObjectName(_fromUtf8("label"))
        self.verticalLayout.addWidget(self.label)
        self.label_2 = QtGui.QLabel(self.centralwidget)
        self.label_2.setObjectName(_fromUtf8("label_2"))
        self.verticalLayout.addWidget(self.label_2)
        self.disp = QtGui.QLabel(self.centralwidget)
        self.disp.setObjectName(_fromUtf8("disp"))
        self.verticalLayout.addWidget(self.disp)
        self.line = QtGui.QFrame(self.centralwidget)
        self.line.setFrameShape(QtGui.QFrame.HLine)
        self.line.setFrameShadow(QtGui.QFrame.Sunken)
        self.line.setObjectName(_fromUtf8("line"))
        self.verticalLayout.addWidget(self.line)
        self.response = QtGui.QTextEdit(self.centralwidget)
        self.response.setObjectName(_fromUtf8("response"))
        self.response.setMaximumSize(QtCore.QSize(16777215, 40))
        self.verticalLayout.addWidget(self.response)
        self.btn = QtGui.QPushButton(self.centralwidget)
        self.btn.setObjectName(_fromUtf8("btn"))
        self.btn.clicked.connect(self.send)
        self.verticalLayout.addWidget(self.btn)
        self.speech = QtGui.QPushButton(self.centralwidget)
        self.speech.setObjectName(_fromUtf8("speech"))
        self.speech.clicked.connect(self.text_speech)
        self.speech.setIcon(QtGui.QIcon('speak.png'))
        self.verticalLayout.addWidget(self.speech)
        self.improve = QtGui.QPushButton(self.centralwidget)
        self.improve.setObjectName(_fromUtf8("improve"))
        self.improve.clicked.connect(self.learning)
        self.verticalLayout.addWidget(self.improve)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtGui.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 21))
        self.menubar.setObjectName(_fromUtf8("menubar"))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtGui.QStatusBar(MainWindow)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def send(self):
        global input_statement
        global statement
        user = self.response.toPlainText()
        input_statement = bot.input.process_input_statement(user)
        statement, response = bot.generate_response(input_statement, CONVERSATION_ID)
        bot.output.process_response(response)
        self.label_2.setText(_translate(
            "MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">You: " + user + "</span></p></body></html>", None))
        self.disp.setText(_translate(
            "MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">Chatty: " + str(response) + "</span></p></body></html>", None))
        self.response.setText("")

    def text_speech(self):
        to_speak = self.disp.text()
        to_speak = to_speak.replace("Chatty: ", "")
        speak.Speak(str(to_speak))

    def learning(self):
        global statement
        global input_statement
        alternate = easygui.enterbox(msg="Please enter the correct response",
                                     title="Improvisation", default="", strip=True, image=None, root=None)
        response1 = bot.input.process_input_statement(alternate)
        bot.learn_response(response1, input_statement)
        bot.storage.add_to_conversation(CONVERSATION_ID, statement, response1)
        self.disp.setText(_translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">Chatty: " +
                                     "Response is recorded" + "< /span > </p > </body > </html >", None))

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(_translate("MainWindow", "Chatty the bot", None))
        self.label.setText(_translate(
            "MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; color:#0000ff;\">Chatty the Chatbot</span></p></body></html>", None))
        self.label_2.setText(_translate(
            "MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">You: </span></p></body></html>", None))
        self.disp.setText(_translate(
            "MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">Chatty: Enter anything to ask me. Enter nothin' to correct my response</span></p></body></html>", None))
        self.btn.setText(_translate("MainWindow", "Say to Chatty", None))
        self.speech.setText(_translate("MainWindow", "", None))
        self.improve.setText(_translate("MainWindow", "Improve Chatty's response", None))


if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    MainWindow = QtGui.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
