;echo Building Java...
javac -cp "C:/code/tests/Test OPS IDL Builder/Foo2Project/../Foo1Project/Generated/Foo1Project.jar";lib/OPSJLib.jar;lib/ConfigurationLib.jar; @"C:/code/tests/Test OPS IDL Builder/Foo2Project/Generated/debugger_buildinfo.ops_tmp"
jar cfm "C:/code/tests/Test OPS IDL Builder/Foo2Project/Generated///Foo2Project.jar" "C:/code/tests/Test OPS IDL Builder/Foo2Project/Generated//manifest_adds.ops_tmp" -C "C:/code/tests/Test OPS IDL Builder/Foo2Project/Generated/Java" . 
echo done.
pause
exit
