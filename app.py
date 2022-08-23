from flask import Flask, render_template, request, url_for, redirect
from flask_cors import CORS
import os
app = Flask(__name__,static_folder='/')

global script
script = ""

@app.route('/coder', methods=['GET', 'POST'])
def coder():
    if request.method == 'POST':
        data = request.form['queries']
        file = open('script.txt', 'w')
        file.write(data)
        file.close()
        global script 
        script = data
        # os.system("g++ archivo.cpp")
        os.system("python ../Tortuga/script.py")
        return redirect(url_for("coder"))
    return render_template('user_interface.html')

def return_script():
    return script

@app.context_processor
def context_processor():
    return dict(script=return_script())

if __name__ == "__main__":
    app.run(debug=True)