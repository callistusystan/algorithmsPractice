@ECHO OFF
for %%f in (*.exe) do "%%f" < in.txt;
for %%f in (*.exe) do "%%f" < in.txt > out.txt
PAUSE