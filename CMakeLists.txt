cmake_minimum_required(VERSION 3.14)
project(Gestao_Biblioteca)

set(CMAKE_CXX_STANDARD 14)

add_executable(Gestao_Biblioteca Encapsuladores/EntradaExemplar.cpp Encapsuladores/EntradaLeitor.h EstruturasDados/PilhaExemplar.cpp EstruturasDados/PilhaExemplar.h Encapsuladores/EntradaLeitor.cpp Encapsuladores/EntradaLeitor.h EstruturasDados/FilaLeitor.cpp EstruturasDados/FilaLeitor.h Autor.cpp Autor.h Encapsuladores/EntradaFila.cpp Encapsuladores/EntradaFila.h Encapsuladores/EntradaAutor.cpp Encapsuladores/EntradaAutor.h Encapsuladores/EntradaDoc.cpp Encapsuladores/EntradaDoc.h main.cpp Biblioteca.cpp Biblioteca.h Documento.cpp Documento.h Leitor.cpp Leitor.h Exemplar.cpp Exemplar.h Revista.cpp Revista.h Livro.cpp Livro.h ExemplarLivro.cpp ExemplarLivro.h CD.cpp CD.h DVD.cpp DVD.h)

