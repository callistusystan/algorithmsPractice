@ECHO OFF
for %%f in (in*) do (
	echo Output for %%f
	code.exe < "%%f" 
)
code.exe < in1.txt > out.txt
PAUSE