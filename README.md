Controle de LEDs com Temporizador no Raspberry Pi Pico, simulanda um semafaro.

Descrição:

Este projeto implementa o controle de três LEDs (vermelho, azul e verde) utilizando um temporizador repetitivo na Raspberry Pi Pico. O sistema alterna entre os LEDs a cada 3 segundos e exibe mensagens na saída serial para indicar os estados do sistema, simulando um semafaro, só que trocando a cor amarela pela azul.

Os estados do LED seguem a seguinte lógica:

Estado 0: LED vermelho aceso, LEDs azul e verde apagados. (Mensagem: "PARE")

Estado 1: LED azul aceso, LEDs vermelho e verde apagados. (Mensagem: "ATENÇÂO")

Estado 2: LED verde aceso, LEDs vermelho e azul apagados. (Mensagem: "SIGA")

Componentes Necessários:

Raspberry Pi Pico

3 LEDs (vermelho, azul e verde)

3 resistores de 330? (para limitar a corrente nos LEDs)

Fios e protoboard

Funcionamento

O programa inicializa os pinos GPIO da Raspberry Pi Pico.

Um temporizador repetitivo é configurado para alternar os LEDs a cada 3 segundos.

O loop principal mantém a execução e imprime mensagens na saída serial conforme o estado atual.

Os LEDs mudam de estado seguindo uma sequência cíclica de três passos.

Estrutura do Código:

Configura os pinos GPIO para os LEDs.

Usa um temporizador repetitivo para alternar os estados.

Imprime mensagens na saída serial para indicar os estados do sistema.

Mantém o ciclo de execução de forma infinita.

Autor: Mateus Moreira da Silva

Este projeto foi desenvolvido e testado pelo autor com base na utilização da Raspberry Pi Pico e suas bibliotecas.
