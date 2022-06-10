
//Numero de corpos com gravidade no cenário
const static int Numero_De_Corpos = 50;

//Distribuição dos corpos aleatório. 1 > ou < -1 = Tamanho do cenário. 0 = Centro
const static double Distribuicao_Dos_Corpos = 0.1;

//Massa/Peso dos corpos
const static int Massa_Maxima_Dos_Corpos = 10;
const static int Massa_Minima_Dos_Corpos = 5;

//1 = 60 ticks por segundo, 0.5 = 30 ticks por segundo
const static double Time_Warp_Inicial = 1; //Mínimo: 0.05

//Multiplicador da velocidade X e Y da camera
const static double Velocidade_Da_Camera = 10; //Padrão: 10

//"Luzes" faz um efeito de luz de cores aleatórias nos corpos.
//"Luzes_E_Sombras" efeito de luz com as sombras de acordo com as posições das paredes
//Escolha somente 1! :) Caso contrário o codigo só vai considerar Luzes_E_Sombras
const bool Luzes = false;
const bool Luzes_E_Sombras = true;

//Mover os objetos com o mouse, segurando o botão esquerdo do mouse
const bool Controles_Do_Mouse = true;
