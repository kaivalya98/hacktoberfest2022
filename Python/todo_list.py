import tkinter as tk
from tkinter import ttk
from tkinter import *
from tkinter import messagebox
from tkinter import simpledialog
import mysql.connector as sq
import datetime
import time
import schedule
from tkcalendar import Calendar, DateEntry
    
root = tk.Tk()

root.title('Todoist: The To-Do List')
root.geometry("400x250+500+300")
root.configure(bg='thistle') 
style = ttk.Style()
style.configure("TButton",foreground="white", background='#000000')

 # connecting to mysql   

conn = sq.connect(host = 'localhost', user= 'root', password ='' )
cur = conn.cursor()

r2 = cur.execute('use project;')

cur.execute('create table if not exists tasks(todo varchar(100), dateoftask DATETIME NOT NULL DEFAULT(current_timestamp()),Priority Varchar(100))')
cur.execute('alter table tasks add category varchar(100);')
cur.execute('alter table tasks add Priority varchar(100);')

task = []
category=[]
mode=[]

    #------------------------------- Functions--------------------------------
def hide():
    top.withdraw()
    #root=Toplevel()
    
m= "Welcome to Todoist!"    
top = tk.Toplevel(root)
msg = tk.Message(top, text = m)

msg.config( anchor=CENTER,width=200,font=('times', 24, 'italic'))   #for creating the welcome window
msg.pack()
button=tk.Button(top, text='Get started', width=20 ,command=hide)
button.pack()

v = IntVar()

def selected():
   
    s=v.get()
    print(s)
    word=e1.get()
    print(word)
    
    l1.forget() 
       
    #adding priority to the table 
    cur.execute("insert into tasks (priority) values ('{}')".format(v))
    conn.commit()
    listUpdate() 
    v.delete(0,'end')

def addTask():
    word = e1.get()
    if len(word)==0:
        messagebox.showinfo('Empty Entry', 'Enter task name')
    else:

        l1=Label(root, text="Choose priority")
        r1=Radiobutton(l1, text="1st Priority",padx = 50, variable=v, value=1,command=selected)
        r2=Radiobutton(l1, text="2nd Priority",padx = 50,  variable=v, value=2,command=selected)
        r3=Radiobutton(l1, text="3rd Priority",padx = 50,  variable=v, value=3,command=selected)
        r4=Radiobutton(l1, text="4th Priority",padx = 50,  variable=v, value=4,command=selected)
        b = Button(l1,text="Ok",command=clicked)
        
        l1.pack()
        l1.grid(row=10,column=100)
        r1.pack()
        r2.pack()
        r3.pack()
        r4.pack()
        b.pack()
       
def clicked(): #after pressing 'ok' in priority
    word = e1.get()
    task.append(word)
    cur.execute("insert into tasks (todo) values ('{}')".format(word))
    conn.commit()
    listUpdate()
    e1.delete(0,'end')
 
# ------------------functions for habits ---------------------------

def scheduler():
    schedule.every().day.at(answer).do(job)
    while True:
        schedule.run_pending()
        time.sleep(1)




def Habitpicker():
    try:
        global uniq
        uniq= t.get(t.curselection())
        print (uniq)
        messagebox.showinfo('Habits','Setting habit for {}'.format(uniq))
        global answer
        answer = simpledialog.askstring("Habits", "Enter time of reminder in 00:00 format",parent=root)
        print(answer)
        scheduler()
        
        
    except:
         messagebox.showinfo('Habits','Please Select Task Item For Building Habits')

def job():
    messagebox.showinfo('Habits', 'It is time to work on {}!'.format(uniq))  #Notification for habit builder

 #----------------functions for scheduler---------------------


def calendar_Schedule():
    messagebox.showinfo('Calendar','Select date to schedule task reminder on')
    try:
        global unique
        unique= t.get(t.curselection())
    except:
        messagebox.showinfo('Calendar','Please Select Task Item For Scheduling')
      
    def example1():
        def print_sel():
            global dt
            dt = cal.selection_get()
            root.quit()
           # print(dt)

        top = tk.Toplevel(root)

        cal = Calendar(top,
                       font="Arial 14", selectmode='day',
                       cursor="hand1", year=2020, month=11, day=23)
        cal.pack(fill="both", expand=True)
        ttk.Button(top, text="ok", command=print_sel).pack()
        
       

    def example2():
        top = tk.Toplevel(root)

        ttk.Label(top, text='Choose date').pack(padx=10, pady=10)

        cal = DateEntry(top, width=12, background='darkblue',
                    foreground='white', borderwidth=2)
        cal.pack(padx=10, pady=10)


    root = tk.Tk()
    s = ttk.Style(root)
    s.theme_use('clam')

    ttk.Button(root, text='Calendar', command=example1).pack(padx=10, pady=10)
    root.quit()


    root.mainloop()

def job2():
    messagebox.showinfo('Schedule', 'Task: {}'.format(unique))  #Notification for scheduler

def final_sched():
    calendar_Schedule()
    from datetime import date

    from apscheduler.schedulers.blocking import BlockingScheduler
    messagebox.showinfo('Schedule', 'Setting a reminder for {} on {}'.format(unique,dt))
    
    


    sched = BlockingScheduler()
    sched.add_job(job2)
    sched.start()

#-----------------------------functions for scheduler-----------------------
    
#this function inserts the task into the listbox    
def listUpdate():
    clearList()
    cnt=0
    for i in task:
        s=v.get()
       
    
        if s==1:
            t.insert('end', i)
            cnt=0
            
        elif s==2:
            t.insert('end', i)
            cnt=0
        elif s==3:
            t.insert('end', i)
        else:
            t.insert('end', i)
        cnt+=1    
    
def delOne():
    try:
        val = t.get(t.curselection())
        if val in task:
            task.remove(val)
            listUpdate()
            cur.execute('delete from tasks where todo = {}'.format(val,))
    
    except:
         messagebox.showinfo('Cannot Delete', 'No Task Item Selected')
      
def deleteAll():
       mb = messagebox.askyesno('Delete All','Are you sure?')
       if mb==True:
            while(len(task)!=0):
                task.pop()
            cur.execute('delete from tasks')
            listUpdate()

def num_tasks():
    num_tasks = len(task)
    
    msg = "There are {} tasks in the list".format(num_tasks)
    l6["text"]=msg
  
def clearList():
        t.delete(0,'end')
    
def bye():
        print(task)
        root.destroy()
    
def retrieveDB():
        while(len(task)!=0):
            task.pop()
            cur.execute('select todo from tasks')
            x = cur.fetchone()
            task.append(x[0])

#-------------------------------------Timer functions-------------------------------------

def timer_new():
    import tkinter as tk
    import time
    messagebox.showinfo('Timer','Set a timer to build up mindfulness')
    win = tk.Toplevel(root)
    win.geometry('400x300')
    win.resizable(0,0)
    win.config(bg ='blanched almond')
    win.title('Countdown Clock And Timer')
    l = tk.Label(win, text = 'Countdown Clock and Timer' , font = 'arial 20 bold',  bg ='papaya whip').pack()

    la = tk.Label(win, font ='arial 15 bold', text = 'current time :', bg = 'papaya whip').place(x = 40 ,y = 70)

    def clock():
        clock_time = time.strftime('%H:%M:%S %p')
        curr_time.config(text = clock_time)
        curr_time.after(1000,clock)

    curr_time = tk.Label(win, font ='arial 15 bold', text = '', fg = 'gray25' ,bg ='papaya whip')
    curr_time.place(x = 190 , y = 70)
    clock()

    sec = StringVar()
    tk.Entry(win, textvariable = sec, width = 2, font = 'arial 12').place(x=250, y=155)
    sec.set('00')

    mins= StringVar()
    tk.Entry(win, textvariable = mins, width =2, font = 'arial 12').place(x=225, y=155)
    mins.set('00')

    hrs= StringVar()
    tk.Entry(win, textvariable = hrs, width =2, font = 'arial 12').place(x=200, y=155)
    hrs.set('00')

    def countdown():
        times = int(hrs.get())*3600+ int(mins.get())*60 + int(sec.get())
        while times > -1:
            minute,second = (times // 60 , times % 60)
        
            hour = 0
            if minute > 60:
                hour , minute = (minute // 60 , minute % 60)
      
            sec.set(second)
            mins.set(minute)
            hrs.set(hour)
   
            root.update()
            time.sleep(1)

            if(times == 0):
                sec.set('00')
                mins.set('00')
                hrs.set('00')
            times -= 1
        
    tk.Label(win, font ='arial 15 bold', text = 'set the time',   bg ='papaya whip').place(x = 40 ,y = 150)

    tk.Button(win, text='START', bd ='5', command = countdown, bg = 'antique white', font = 'arial 10 bold').place(x=150, y=210) 
          
    #------------------------------- Functions-------------------------------- 

l1 = ttk.Label(root, text = 'To-Do List')
l2 = ttk.Label(root, text='Enter task title: ')
e1 = ttk.Entry(root, width=21)
t = tk.Listbox(root, height=9, selectmode='SINGLE',width=25)
b1 = tk.Button(root, text='Add task',bg='#000000',fg='white',width=20,command=addTask)
b2 = tk.Button(root, text='Delete', width=20,bg='#000000',fg='white', command=delOne)
b3 = tk.Button(root, text='Delete all', width=20,bg='#000000',fg='white', command=deleteAll)
b8 = tk.Button(root, text='Number of tasks', width=20,bg='#000000',fg='white', command=num_tasks)
l6 = ttk.Label(root, width=25)
b4 = tk.Button(root, text='Exit', width=20,bg='#000000',fg='white', command=bye)
b5 = tk.Button(root, text ='Timer',width = 20,bg='#000000',fg='white', command = timer_new)
b6 = tk.Button(root, text ='Habit Builder',width = 20,bg='#000000',fg='white', command = Habitpicker)
b7 = tk.Button(root, text ='Scheduler',width = 20,bg='#000000',fg='white', command = final_sched) 


    
retrieveDB()
listUpdate()

    
    #Place geometry
l2.place(x=490, y=50)  #'To-Do List'
e1.place(x=490, y=80)
b1.place(x=490, y=110)   #Add task
b2.place(x=490, y=150)
b3.place(x=490, y=190)
b8.place(x=490, y=230)
l6.place(x=650, y=80)
b4.place(x=650, y =380) #exit
b5.place(x=650, y=340)
b6.place(x=490, y=380)
b7.place(x=490,y=340) #scheduler
l1.place(x=610, y=10)
t.place(x=650, y = 110)

root.mainloop()
conn.commit()
cur.close()
