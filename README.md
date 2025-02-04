# Controle de LEDs com Temporizador no Raspberry Pi Pico – Simulação de Semáforo

## 📌 Descrição  

Este projeto implementa um sistema de controle para três LEDs (**vermelho, azul e verde**) utilizando um **temporizador repetitivo** na **Raspberry Pi Pico**.  

O objetivo é simular um **semáforo**, mas substituindo a cor **amarela** pela **azul**. Os LEDs alternam de estado a cada **3 segundos**, e mensagens são exibidas na saída serial para indicar o estado atual do sistema.  

## 🔄 Funcionamento  

O sistema segue a seguinte lógica de transição de estados:  

| Estado | LED Ativo | Mensagem Serial |
|--------|----------|----------------|
| **0** | 🔴 Vermelho | **"PARE"** |
| **1** | 🔵 Azul | **"ATENÇÃO"** |
| **2** | 🟢 Verde | **"SIGA"** |

A cada **3 segundos**, o sistema avança para o próximo estado, seguindo uma sequência cíclica.  

## 🛠️ Componentes Necessários  

- **1x Raspberry Pi Pico**  
- **1x LED vermelho**  
- **1x LED azul**  
- **1x LED verde**  
- **3x Resistores de 330Ω** (para limitar a corrente nos LEDs)  
- **Fios jumper e protoboard**  

## ⚙️ Estrutura do Código  

O código segue os seguintes passos:  

1. **Configuração dos pinos GPIO** da Raspberry Pi Pico para controlar os LEDs.  
2. **Configuração de um temporizador repetitivo** para alternar os LEDs a cada **3 segundos**.  
3. **Execução de um loop infinito**, onde:  
   - O temporizador altera os LEDs conforme a lógica do semáforo.  
   - O estado atual é exibido na saída serial.  

## 🚀 Instalação e Execução  

### 1️⃣ **Prepare o ambiente de desenvolvimento**  
- Instale o SDK do **Raspberry Pi Pico**.  
- Configure a **IDE** (VS Code ou outro ambiente compatível).  

### 2️⃣ **Monte o circuito** conforme a seguinte ligação:  

- **LED Vermelho** → GPIO **13**  
- **LED Azul** → GPIO **12**  
- **LED Verde** → GPIO **11**  
- **Resistores de 330Ω** em série com cada LED  
- **GND** comum para os LEDs  

### 3️⃣ **Compile e carregue o código** na Raspberry Pi Pico.  

### 4️⃣ **Monitore a saída serial** para visualizar os estados do semáforo.  

## 📟 Exemplo de Saída Serial  

```plaintext
PARE
3 segundos - Próximo sinal
ATENÇÃO
3 segundos - Próximo sinal
SIGA
3 segundos - Próximo sinal

Autor: Lucas Moreira da Silva
