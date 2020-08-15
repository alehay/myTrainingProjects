#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from PyQt5 import QtWidgets , QtCore 
import time
import queue

class MyThread (QtCore.QThread) :
    task_done = QtCore.pyqtSignal(int, int, name = 'taskDone!!!')
    def  __init__ (self, id, queue , parent = None) :
        QtCore.QThread.__init__(self, parent)
        self.id = id
        self.queue = queue
    def run (self):
        while True:
            task = self.queue.get () # get a task 
            self.sleep(2)            # calculate! calculate!! calculate!!!
            self.task_done.emit(task, self.id) # set result
            self.queue.task_done()

class MyWindow (QtWidgets.QPushButton) :
    def __init__(self) :
        QtWidgets.QPushButton.__init__(self)
        self.setText(" distribute tasks ")
        self.my_queue = queue.Queue() # queue initialization
        self.threads = []
        for i in range(1,4):           # generated Thread
            thread = MyThread (i, self.my_queue)
            self.threads.append(thread)
            thread.task_done.connect(self.OnTaskDone, QtCore.Qt.QueuedConnection)
            thread.start()
        self.clicked.connect(self.onAddTask)
    
    def onAddTask (self):
        for i in range (0, 20) :
            self.my_queue.put(i)       # add task to queue
    def OnTaskDone (self, data, id) :
        print(" data  calck ", data, "; id thread = " , id)

if __name__ == "__main__" :
    import sys 
    app = QtWidgets.QApplication(sys.argv)
    window = MyWindow()
    window.setWindowTitle(" module queue ")
    window.resize(300, 150)
    window.move(100, 100)
    window.show()
    sys.exit(app.exec_())
        
