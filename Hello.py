from turtle import Screen, Turtle

LEVELS = 8  # recursion depth limit
MAX_LIMB_LENGTH = 120  # pixels
LIMB_ANGLE = 34  # degrees

def draw_tree(length, level):
    if level > LEVELS:
        return

    turtle.left(LIMB_ANGLE)
    turtle.forward(length)
    draw_tree(3/4 * length, level + 1)
    turtle.backward(length)

    turtle.right(LIMB_ANGLE)
    turtle.forward(length)
    draw_tree(3/4 * length, level + 1)
    turtle.backward(length)

    turtle.right(LIMB_ANGLE)
    turtle.forward(length)
    draw_tree(3/4 * length, level + 1)
    turtle.backward(length)

    turtle.left(LIMB_ANGLE)

screen = Screen()
screen.tracer(False)

turtle = Turtle()
turtle.setheading(90)

turtle.penup()
turtle.backward(2 * MAX_LIMB_LENGTH)
turtle.pendown()
turtle.forward(MAX_LIMB_LENGTH)

draw_tree(MAX_LIMB_LENGTH, 1)

turtle.hideturtle()
screen.tracer(True)
screen.exitonclick()
