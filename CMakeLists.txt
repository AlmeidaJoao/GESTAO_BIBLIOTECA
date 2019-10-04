cmake_minimum_required(VERSION 3.14)
project(Gestao_Biblioteca)

set(CMAKE_CXX_STANDARD 14)

add_executable(Gestao_Biblioteca main.cpp Documento.cpp Documento.h Leitor.cpp Leitor.h Exemplar.cpp Exemplar.h Revista.cpp Revista.h Livro.cpp Livro.h Autor.cpp Autor.h ExemplarLivro.cpp ExemplarLivro.h CD.cpp CD.h DVD.cpp DVD.h)