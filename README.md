# Minigame

Este projeto implementa um Minigame feito com microcontrolador PIC18F4685 e conta com dois jogos clássicos: tetris e snake.
O display do dispositivo são duas matrizes de led 8x8 em série formando uma tela de 16x8. O dispositivo não possui botões a 
não ser por um botão de power, a interação com o jogo se dá por meio de comandos enviados via bluetooth que podem ser enviados 
por qualquer dispositivo pareado com o módulo bluetooth (HC05) ligado ao MCU, desde que os sinais enviados sigam o seguinte 
padrão de caracteres:
p - Start
b - Select
d - Direita
a - Esquerda
w - Cima
s - Baixo
Os sinais são recebidos pelo módulo bluetooth e enviados serialmente para o pic que interpretará seguindo o padrão e executará
as devidas ações no minigame. A alimentação é feita por 3 pilhas AA em série, fornecendo cerca de 4.5V.
