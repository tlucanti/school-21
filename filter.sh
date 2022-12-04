cat out.txt | grep '(gdb) (gdb)' | cut -c 13- > flags.txt
python3 dirs.py < flags.txt

