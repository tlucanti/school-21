
import os

for i in range(14):
    code = input()
    os.system(f'mkdir -p level{i:02}/resources')
    os.system(f'echo {code} > level{i:02}/flag')
    os.system(f'touch level{i:02}/resources/.gitkeep')

os.system('cp gdb.txt level00/resources')

