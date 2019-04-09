
import filecmp
import os

# constants
path = "./"
dir_input = "test/input_normal/"
dir_output = "test/output_normal/"
dir_input_erwarn = "test/input_warn_errors/"
dir_output_erwarn = "test/output_warn_errors/"
exec_name = "/bin/bash " + path + "mongcc.sh -a -c"
input_ext = '.c'
output_name = '_out.txt'
expect_name = '_exp.txt'

nbTestsOK = 0;
nbTestsFailed = 0;

# execute normal input files
input_files = os.listdir(dir_input)
file_names = []
for input_file in input_files:
	if input_file[len(input_file)-2:len(input_file)] == '.c':
		file_names.append(input_file[:-2])

for in_name in file_names :
	os.system("rm -f "+dir_output+in_name+expect_name)
	os.system("gcc -o " + dir_output+in_name + "_exec " + dir_input+ in_name+input_ext)
	os.system("./"+dir_output+"/"+in_name + "_exec ; echo $? >> "+dir_output+in_name+expect_name + " 2>>"+dir_output+"logs.txt")
	os.system(exec_name+" "+dir_input+in_name+input_ext + " > "+dir_output+in_name+output_name + " 2>>"+dir_output+"logs.txt")

# compare output files with expected output
for name in file_names :
	print "-----------------------------------"
	result = filecmp.cmp(dir_output+name+output_name, dir_output+name+expect_name)
	print name + ": " + str(result)
	if (result) :
		nbTestsOK += 1
	else : 
		nbTestsFailed += 1

	with open(dir_input+"/"+name+input_ext, 'r') as fin:
    		print fin.read()
	with open(dir_output+"/"+name+output_name, 'r') as fout:
    		print "Resultat obtenu: " + fout.read()
	with open(dir_output+"/"+name+expect_name, 'r') as fexp:
    		print "Resultat attendu: " + fexp.read()
	
# execute input files containing warnings and errors
input_files_erwarn = os.listdir(dir_input_erwarn)
file_names_erwarn = []
for input_file in input_files_erwarn:
	if input_file[len(input_file)-2:len(input_file)] == '.c':
		file_names_erwarn.append(input_file[:-2])

for in_name in file_names_erwarn :
	os.system(exec_name+" "+dir_input_erwarn+in_name+input_ext + " > "+dir_output_erwarn+in_name+output_name+ " 2>>"+dir_output_erwarn+"logs.txt")


for name in file_names_erwarn :
	print "-----------------------------------"
	result = filecmp.cmp(dir_output_erwarn+name+output_name, dir_output_erwarn+name+expect_name)
	print name + ": " + str(result)
	if result :
		nbTestsOK += 1
	else : 
		nbTestsFailed += 1
	with open(dir_input_erwarn+"/"+name+input_ext, 'r') as fin:
    		print fin.read()
	with open(dir_output_erwarn+"/"+name+output_name, 'r') as fout:
    		print "Resultat obtenu: \n" + fout.read()
	with open(dir_output_erwarn+"/"+name+expect_name, 'r') as fexp:
    		print "Resultat attendu: \n" + fexp.read()
	

print '********************************'
print "Nb tests OK : " + str(nbTestsOK)
print "Nb tests echoues : " + str(nbTestsFailed)

