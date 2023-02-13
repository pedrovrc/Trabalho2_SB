Alunos envolvidos no trabalho:
    - Pedro Victor Rodrigues de Carvalho - 17/0113043
    - Pedro Augusto Coelho Nunes - 16/0141044

Sistema operacional utilizado: Ubuntu Linux (desenvolvido via Microsoft WSL)

Passos para a compilação do programa:
    - Extraia todos os conteúdos do arquivo zip.
    - Abra o diretório atual no terminal e navegue para o diretório "codigo".
    - Certifique-se de ter instalado o "make". (Caso não esteja, vide seção a seguir)
    - Entre "make" no terminal.
    - (IMPORTANTE) Caso já se tenha compilado o programa uma vez, e deseje compilá-lo
      novamente, é necessário deletar os arquivos "main.o", "preprocessamento.o",
      "macros.o" e "tradutor.o" antes de se executar o makefile.

    (Caso necessário) Instalação do make:
    Entre no terminal as seguintes linhas de comando, em ordem:
        - sudo apt update
        - sudo apt install make
        - sudo apt install build-essential
    
Para executar o programa, coloque o arquivo de entrada (com extensão .asm) no
diretório "codigo" e então digite no terminal:
    - ./tradutor <nome_arquivo>
em que:
    <nome_arquivo>  - Nome do arquivo de código .asm, sem a extensão.
