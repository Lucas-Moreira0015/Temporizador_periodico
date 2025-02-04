Controle de LEDs com Temporizador no Raspberry Pi Pico, simulanda um semafaro.

Descri��o:

Este projeto implementa o controle de tr�s LEDs (vermelho, azul e verde) utilizando um temporizador repetitivo na Raspberry Pi Pico. O sistema alterna entre os LEDs a cada 3 segundos e exibe mensagens na sa�da serial para indicar os estados do sistema, simulando um semafaro, s� que trocando a cor amarela pela azul.

Os estados do LED seguem a seguinte l�gica:

Estado 0: LED vermelho aceso, LEDs azul e verde apagados. (Mensagem: "PARE")

Estado 1: LED azul aceso, LEDs vermelho e verde apagados. (Mensagem: "ATEN��O")

Estado 2: LED verde aceso, LEDs vermelho e azul apagados. (Mensagem: "SIGA")

Componentes Necess�rios:

Raspberry Pi Pico

3 LEDs (vermelho, azul e verde)

3 resistores de 330? (para limitar a corrente nos LEDs)

Fios e protoboard

Funcionamento

O programa inicializa os pinos GPIO da Raspberry Pi Pico.

Um temporizador repetitivo � configurado para alternar os LEDs a cada 3 segundos.

O loop principal mant�m a execu��o e imprime mensagens na sa�da serial conforme o estado atual.

Os LEDs mudam de estado seguindo uma sequ�ncia c�clica de tr�s passos.

Estrutura do C�digo:

Configura os pinos GPIO para os LEDs.

Usa um temporizador repetitivo para alternar os estados.

Imprime mensagens na sa�da serial para indicar os estados do sistema.

Mant�m o ciclo de execu��o de forma infinita.

Autor: Mateus Moreira da Silva

Este projeto foi desenvolvido e testado pelo autor com base na utiliza��o da Raspberry Pi Pico e suas bibliotecas.
