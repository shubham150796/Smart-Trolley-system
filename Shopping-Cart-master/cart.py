from time import sleep
import serial
from flask import *
import sqlite3, hashlib, os
from werkzeug.utils import secure_filename

ser = serial.Serial('COM6', 9600) # Establish the connection on a specific port

while True:
    
    productId=-1
    productId=int(ser.readline())  #print('text') #productId = text #text int(request.args.get('text'))
    print(productId)
    if productId!=-1:
        conn= sqlite3.connect('database.db') 
        cur = conn.cursor()
        cur.execute("SELECT userId FROM users WHERE email = 'shubham150796@gmail.com'")
        userId = cur.fetchone()[0]
        try:
            print("try")
            cur.execute("SELECT count(*) FROM kart WHERE productId = ?", (productId,))
            data=cur.fetchone()[0]
            print(data)
            if data==0:
             print('add')
             cur.execute("INSERT INTO kart (userId, productId) VALUES (?, ?)", (userId, productId))
             conn.commit()
             msg = "Added successfully"
            else:
             print('remove  ')
             cur.execute("DELETE FROM kart WHERE productId = ?", (productId,))
             conn.commit()
                
        except:
            conn.rollback()
            msg = "Error occured"
    
        #cur.execute("DELETE FROM kart")
        conn.close()
