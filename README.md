# AnelMultithread

Programa em C cria 30 threads e faça com que uma mensagem circule entre os mesmos.
A mensagem é uma string aleatória de pelo menos 80 caracteres.
A cada vez que um thread recebe a mensagem ele a imprime, modifica o primeiro caractere minúsculo para maiúsculo, caso exista, dorme por 1 segundo, e repassa a mensagem.
Quando todos os caracteres forem maiúsculos, o processo repassa a mensagem e então termina.
No fim o processo imprime a mensagem resultante.
