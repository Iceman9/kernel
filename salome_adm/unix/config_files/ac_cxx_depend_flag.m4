dnl @synopsis AC_C_DEPEND_FLAG
dnl
dnl define C_DEPEND_FLAG
dnl define CXX_DEPEND_FLAG
dnl
dnl @version $Id$
dnl @author Marc Tajchman
dnl
AC_DEFUN(AC_DEPEND_FLAG,
[AC_CACHE_CHECK(which flag for dependency information generation,
ac_cv_depend_flag,
[AC_LANG_SAVE
 AC_LANG_C
 echo "conftest.o: conftest.c" > conftest.verif
 echo "int  main() { return 0; }" > conftest.c

 C_DEPEND_FLAG=
 for ac_C_DEPEND_FLAG in -xM -MM -M ; do

    rm -f conftest.d conftest.err
    ${CC-cc} ${ac_C_DEPEND_FLAG} -c conftest.c 1> conftest.d 2> conftest.err
    if test -f conftest.u ; then
       mv conftest.u conftest.d
    fi

    rm -f conftest
    diff -b -B conftest.d conftest.verif > conftest
    if test ! -s conftest ; then
       C_DEPEND_FLAG=${ac_C_DEPEND_FLAG}
       break
    fi
 done

dnl use gcc option -MG : asume unknown file will be construct later
 rm -f conftest.d conftest.err
 ${CC-cc} ${C_DEPEND_FLAG} -MG -c conftest.c 1> conftest.d 2> conftest.err
 if test -f conftest.u ; then
    mv conftest.u conftest.d
 fi
 rm -f conftest
 diff -b -B conftest.d conftest.verif > conftest
 if test ! -s conftest ; then
    C_DEPEND_FLAG=${C_DEPEND_FLAG}" -MG"
 fi

 rm -f conftest*
 if test "x${C_DEPEND_FLAG}" = "x" ; then
    echo "cannot determine flag (C language)"
    exit
 fi

 echo -n " C : " ${C_DEPEND_FLAG}

 AC_LANG_CPLUSPLUS
 echo "conftest.o: conftest.cxx" > conftest.verif
 echo "int  main() { return 0; }" > conftest.cxx

 CXX_DEPEND_FLAG=
 for ac_CXX_DEPEND_FLAG in -xM -MM -M ; do

    rm -f conftest.d conftest.err
    ${CXX-c++} ${ac_CXX_DEPEND_FLAG} -c conftest.cxx 1> conftest.d 2> conftest.err
    if test -f conftest.u ; then
       mv conftest.u conftest.d
    fi

    rm -f conftest
    diff -b -B conftest.d conftest.verif > conftest
    if test ! -s conftest ; then
       CXX_DEPEND_FLAG=${ac_CXX_DEPEND_FLAG}
       break
    fi
 done

dnl use g++ option -MG : asume unknown file will be construct later
 rm -f conftest.d conftest.err
 ${CXX-c++} ${CXX_DEPEND_FLAG} -MG -c conftest.cxx 1> conftest.d 2> conftest.err
 if test -f conftest.u ; then
    mv conftest.u conftest.d
 fi
 rm -f conftest
 diff -b -B conftest.d conftest.verif > conftest
 if test ! -s conftest ; then
    CXX_DEPEND_FLAG=${CXX_DEPEND_FLAG}" -MG"
 fi


 rm -f conftest*
 if test "x${CXX_DEPEND_FLAG}" = "x" ; then
    echo "cannot determine flag (C++ language)"
    exit
 fi

 echo -n " C++ : " ${CXX_DEPEND_FLAG}
 AC_LANG_RESTORE

 AC_SUBST(C_DEPEND_FLAG)
 AC_SUBST(CXX_DEPEND_FLAG)
])
])
