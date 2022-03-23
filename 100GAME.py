# 100GAME
# 2 player play by choosing numbers from 1 to 10
# the one who reachs 100 fisrt win
# Author: Salma Mohammed Mahmoud
# Date: 8/3/2022
# Version:1.0

from operator import pos
import pygame as py# call the libarary
import math
py.init()

black=(0,0,0)#declare some colors(optional)
white=(255,255,255)
mov=(75,0,130)
silver=(192,192,192)
font1=py.font.SysFont("corbel",30) # different font's size 
font2=py.font.SysFont("corbel",150)
font3=py.font.SysFont("corbel", 50)
sum=0

screen_width=800 # width of the screen 
screen_height=500 # height of the screen 
wn=py.display.set_mode((screen_width,screen_height)) #to open the window 
py.display.set_caption("100GAME")#to type a caption

def choosennumber(posx,posy,text):# to make a bottun 
    btn=py.Rect(posx,posy,40,40)# make rect the height and width of it are equal
    py.draw.rect(wn,silver,btn)#draw the rect
    tx=font1.render(f"{text}",True,mov)#print on the rect the text in mov color
    wn.blit(tx,(posx+13,posy+10)) # set the text in the position (posx+13,posy+10)
    return btn

turn = 1
def playerturn(turn):# to switch turn between player1 and player2 
    if turn!=0:
        if turn == 1:
            playerone = font3.render("player 1 turn",True, black)# print on the screen player 1 turn 
            wn.blit(playerone,(100,200))# in position x=100 y=200
        else:
            playertwo = font3.render("player 2 turn",True, black)# print on the screen player 2 turn 
            wn.blit(playertwo,(500,200))# in position x=500 y=200

def iswinner(turn):
    p1=font3.render("player 1 winnnnnnnn",True,black)# print on the screen player 1 win 
    p2=font3.render("player 2 winnnnnnnn",True,black)# print on the screen player 2 win
    if sum>=100:
        if turn==1:
            wn.blit(p2,(260,380))# print p2 in postion x=260 y=380
        elif turn==2:
            wn.blit(p1,(260,380))# print p1 in postion x=260 y=380
        return True    

state=True
while state:#to let the window open all the time  
    for event in py.event.get():
        if event.type==py.QUIT:#if we click on exit
            state=False#make the state = false to get out of the loop and close the window
        mouse=py.mouse.get_pos()    
        if event.type==py.MOUSEBUTTONDOWN:#if we click by the mouse 
            for i in list1:
                if i.collidepoint(mouse):
                    index1=list1.index(i)# index() built in function return the index of the value
                    sum+=(index1+1) # the new sum = the old sum + index+1
                    if turn == 1:# if the turn equal 1 make it equal 2 to let player2 play
                        turn=2
                    else:# if the turn equal 2 make it equal 1 to let player1 play
                        turn = 1
    wn.fill(white)#the color of the windo is white 
    tx=font2.render(f"{sum}",True,mov)
    wn.blit(tx,(370,250))#show sum on the screen in position x=370 y=250
    btn1=choosennumber(150,100,"1")#declare the 10 bottun 
    btn2=choosennumber(200,100,"2")
    btn3=choosennumber(250,100,"3")
    btn4=choosennumber(300,100,"4")
    btn5=choosennumber(350,100,"5")
    btn6=choosennumber(400,100,"6")
    btn7=choosennumber(450,100,"7")
    btn8=choosennumber(500,100,"8")
    btn9=choosennumber(550,100,"9")
    btn10=choosennumber(600,100,"10")
    list1=[btn1,btn2,btn3,btn4,btn5,btn6,btn7,btn8,btn9,btn10]
    if iswinner(turn):#if iswinner function return true that means one of the players win 
        list1=[]#make list1 equal [] 
    else:#non of players win 
        playerturn(turn)#call the function again to continue the game   

    py.display.update()#always update the window 
py.quit()    

    







  

