# -*- coding: utf-8 -*-
import distutils
from distutils.core import setup, Extension

setup(name = "Simple example from the SWIG website",
     version = "0.007",
     ext_modules = [Extension(
	"_stringClass", 			# грабель первый: не забываем подчеркивание
	["stringClass.i","stringClass.cpp"], 
	swig_opts=['-threads', '-c++'], # грабель второй: опции swig тут
     )]
);