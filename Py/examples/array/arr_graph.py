

# coding: utf-8
"""
Использование графического модуля graph.py.
"""
import random
from graph import *

MAX_PLATES = 15
WIDTH = 500
HEIGHT = 600
MIN_R = 10
MAX_R = 30
MIN_V = 1
MAX_V = 5
COLORS = ["blue", "red", "yellow","green"]
vel = []
score = 0

plates = []
def init():
    windowSize(WIDTH,HEIGHT)
    canvasSize(WIDTH,HEIGHT)
    for i in range(MAX_PLATES):
        r = random.randint(MIN_R, MAX_R)
        x = random.randint(r, WIDTH-r)
        y = random.randint(r, HEIGHT-r)
        color = random.choice (COLORS)
        brushColor(color)
        p = circle(x, y, r)
        v = random.randint(MIN_V, MAX_V)
        vel.append(v)
        plates.append(p)
        

def update ():
    for i, p in enumerate(plates):
        moveObjectBy( p, -vel[i], 0 )
        x1, y1, x2, y2, = coords ( p )
        if x2 < 0:
            moveObjectBy(p, WIDTH+x2-x1, 0)

def mouseClick ( evetn ):
    for p in plates:
        if hit ( event.x, evetn.y, p):
            removePlate( p )

def hit (x, y, p):
    x1, y1, x2, y2 = coords(p)
    return ( x1 <= x <= x2 ) and (y1 <= y <= y2)

def removePlate ( p ):
    deleteObject( p )
    plates.remove( p )
    
def mouseClick ( event ):
    for p in plates:
        if hit ( event.x, event.y , p):
            removePlate(p)
            incScore ()

def incScore ():
    global score
    score += 1
    scoreLabel ["text"] = "Счет: " + str(score)

init()
scoreLabel = label("Счет: 0", 10, 10)
onMouseClick(mouseClick)
onTimer (update, 50)

run()