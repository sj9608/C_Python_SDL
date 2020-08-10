from turtle import *
import turtle as t

t.speed(10)
t.pencolor("Red")

for i in range(9):
       t.circle(60, steps = 10)
       t.lt(40)

t.pencolor("Blue")

for j in range(6):
       t.lt(60)
       t.circle(60, steps = 5)

input()