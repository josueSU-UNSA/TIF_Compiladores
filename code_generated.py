import turtle
from TurtleGIF import TurtleGIF

def draw_func():
    pass

TurtleGIF.draw = draw_func
newturtle = TurtleGIF(2, name = "img")
turtle.Screen().setup()
newturtle.record(fps=10)