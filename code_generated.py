import turtle
from TurtleGIF import TurtleGIF
def draw_func(self):
	turtle.shape("circle")
	turtle.color("green")
	turtle.pencolor("green")
	turtle.forward(100)
	turtle.left(120)
	turtle.forward(100)
	turtle.left(120)
	turtle.forward(100)
	turtle.left(120)
	turtle.forward(100)
	turtle.bye()
TurtleGIF.draw = draw_func
newturtle = TurtleGIF(2, name = "img")
turtle.Screen().setup(1500,1500)
newturtle.record(fps=10)