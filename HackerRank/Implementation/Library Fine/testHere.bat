@ECHO OFF
for %%f in (in*) do (
	echo Output for %%f
	code.exe < "%%f" 
)
code.exe < in.txt > out.txt
PAUSE