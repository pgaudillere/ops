@echo off
echo Building Java...
javac -cp lib/OPSJLib.jar;lib/ConfigurationLib.jar  @"C:/Code/OPS_google_code/Examples/TestAll/Generated/debugger_buildinfo.ops_tmp"
jar cfm "C:/Code/OPS_google_code/Examples/TestAll/Generated///TestAll.jar" "C:/Code/OPS_google_code/Examples/TestAll/Generated//manifest_adds.ops_tmp" -C "C:/Code/OPS_google_code/Examples/TestAll/Generated/Java" . 
echo done.
pause
exit
