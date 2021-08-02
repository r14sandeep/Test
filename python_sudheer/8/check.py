from flask import Flask, render_template, request
import subprocess
from subprocess import PIPE
import os

testcases = {}
tc_file_path = os.path.join(os.getcwd(), 'Testcases')
tc_files = os.listdir(os.path.join(os.getcwd(), 'Testcases'))
tc_file_count = len(tc_files)

for i in range(1, tc_file_count+1):
	testcases['Testcase'+str(i)] = tc_files[i-1]

app = Flask(__name__)

@app.route("/home", methods=['GET'])
def return_home():
	return render_template("home.html")

@app.route("/audio", methods=['GET'])
def return_audio():
	return render_template("audio.html", tcases=testcases)

@app.route("/testcases", methods=['POST'])
def execute_cases():
	items = request.form.getlist('Testcase')
	print "items:", items
	status = {} 
	for item in items:
		print "testcase name:", testcases[item]
		item = str(item)
		process = subprocess.Popen('python {0}'.format(os.path.join(tc_file_path,testcases[item])), stdout=PIPE, shell=True)  
		status[item] = (process.communicate()[0]).strip()

	return render_template("status.html", status=status)
		
	
	
	
	

if __name__ == "__main__":
	app.run(debug=True)
