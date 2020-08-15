#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt5 import QtWidgets , QtCore 

class MyWindow (QtWidgets.QWidget):
    def __init__(self, parent= None):
        # calling the parents constructor
        QtWidgets.QWidget.__init__(self, parent)
        # creating a button 
        self.btnMin = QtWidgets.QPushButton("Свернут")
        self.btnMax = QtWidgets.QPushButton("Развернуть")
        self.btnFull = QtWidgets.QPushButton(" full screen")
        self.btnNormal = QtWidgets.QPushButton("Normalize screen")
        self.btnOpacity = QtWidgets.QPushButton("Opacity")
        self.btnNonOpacity = QtWidgets.QPushButton("non Opacity")
        # creating box layout
        vbox = QtWidgets.QVBoxLayout()
        # add buttons to the box layout
        vbox.addWidget(self.btnMin)
        vbox.addWidget(self.btnMax)
        vbox.addWidget(self.btnFull)
        vbox.addWidget(self.btnNormal)
        vbox.addWidget(self.btnOpacity)
        vbox.addWidget(self.btnNonOpacity)
        # add boxLayout to the Layout
        self.setLayout(vbox)
        # calling to methods of a class
        self.btnMin.clicked.connect(self.on_min)
        self.btnMax.clicked.connect(self.on_max)
        self.btnFull.clicked.connect(self.on_full)
        self.btnNormal.clicked.connect(self.on_normal)
        self.btnOpacity.clicked.connect(self.on_opacity)
        self.btnNonOpacity.clicked.connect(self.off_opacity)
    #methods of a class
    def on_min(self):
        self.showMinimized()
    def on_max(self):
        self.showMaximized()
    def on_full(self):
        self.showFullScreen()
    def on_normal(self):
        self.showNormal()
    def on_opacity(self):
        self.setWindowOpacity(0.5)
    def off_opacity(self):
        self.setWindowOpacity(1)

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    window = MyWindow()
    window.setWindowTitle("maximazing and minimazing window")
    window.resize (300, 100)
    window.show()
    sys.exit(app.exec_())

