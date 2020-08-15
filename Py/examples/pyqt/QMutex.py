#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Mutex Demo 
x в myTread общий атрибут для всех потоков, 
его одновременное изменнеие потоками может повлечь 
непредсказуемое поведение

экземпляр класа QMutex сохраняет в АТРИБУТЕ ОБЬЕКТА КЛАССА
А не в атрибуте экземпляра 

атрибут и mutex должны быть в одной области видимости

код в change помещяется между вызовами Lock и Anclock
мьютекса.  что гарантирует что сначала будет выполнена
работа одного потока потом другого 


@author: alehay
"""
from PyQt5 import QtCore, QtWidgets 
import  random


class MyThread(QtCore.QThread):
    x = 111
    mutex = QtCore.QMutex()
    def __init__(self, id , parent = None):
        QtCore.QThread.__init__(self, parent)
        self.id = id
    def run(self):
        self.changed_x()
    def changed_x(self):       
        MyThread.mutex.lock()     # Blocked
        print ("block id = ", self.id)
        print ("x = " , MyThread.x, " ", "id =", self.id)
        MyThread.x += 5
        self.sleep(2)               # extremely complex calculations
        print ("x = " , MyThread.x, " ", "id =", self.id)
        MyThread.x = MyThread.x * random.randint(1,5) 
        print ("x = " , MyThread.x, " ", "id =", self.id)
        MyThread.mutex.unlock()
        
class MyWindow (QtWidgets.QPushButton):
    def __init__(self):
        QtWidgets.QPushButton.__init__(self)
        self.setText(" Run ")
        self.thread1 = MyThread(1)
        self.thread2 = MyThread(2)
        self.thread3 = MyThread(3)
        self.clicked.connect(self.onStart)
    def onStart (self) :
        if not self.thread1.isRunning():
            self.thread1.start()
        if not self.thread2.isRunning():
            self.thread2.start()
        if not self.thread3.isRunning():
            self.thread3.start()

if __name__ == "__main__" :
    import sys
    app = QtWidgets.QApplication(sys.argv)
    window = MyWindow()
    window.setWindowTitle(" class Qmutex ")
    window.resize( 300 , 50)
    window.show ()
    sys.exit(app.exec_())
    
    
    

    
    
    
    
    
    
    
    
    
    
    
    
    