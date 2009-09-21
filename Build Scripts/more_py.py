import os
try:
    retcode = os.system("ant -buildfile ../Libs/ConfigurationLib/build.xml")
    retcode = os.system("ant -buildfile ../Libs/JarSearch/build.xml")
    numb = input("Done")
    if retcode < 0:
        print >>sys.stderr, "Child was terminated by signal", -retcode
    else:
        print >>sys.stderr, "Child returned", retcode
except OSError, e:
    print >>sys.stderr, "Execution failed:", e
