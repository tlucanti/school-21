##
#	Author:		antikostya
#	Created:	2022-01-04 22:05:30
#	Modified:	2022-01-04 22:08:57
##

with open('names.txt', 'r') as f:
	for i in range(101):
		st = f.readline()
		st = st[st.index('.') + 1:].strip()
		st = st[:st.index(',')]
		print(st)
