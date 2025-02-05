# BitDogLab-Semaforo

## Tarefa 1 - Temporizador Periódico (Semáforo)

## Introdução

Este projeto demonstra o uso de um **temporizador periódico (`add_repeating_timer_ms()`)** no **microcontrolador RP2040**, utilizando a placa **BitDogLab**. O objetivo é desenvolver um sistema de **semáforo** que controla três LEDs (**vermelho, amarelo e verde**) com tempos programados para simular um ciclo real de trânsito.

A aplicação utiliza um **temporizador de repetição (`add_repeating_timer_ms()`)** para alternar as cores do semáforo automaticamente a cada **3 segundos**.

---

## Objetivo do Projeto

O principal objetivo deste projeto é demonstrar o uso do **temporizador periódico** do **Pico SDK** para alternância cíclica dos LEDs do semáforo, garantindo tempos fixos de iluminação para cada cor.

A lógica do sistema segue a seguinte sequência:

1. O **LED Vermelho** inicia ligado por **3 segundos**.
2. O **LED Amarelo** acende e permanece ligado por **3 segundos**.
3. O **LED Verde** acende e permanece ligado por **3 segundos**.
4. O ciclo **se repete continuamente**.

Esse projeto é útil para demonstrar conceitos de **temporização periódica, manipulação de GPIOs e controle de fluxo em sistemas embarcados**.

---

## Componentes Utilizados

- **Microcontrolador:** Raspberry Pi Pico W (BitDogLab)
- **LEDs:** Vermelho, Amarelo e Verde
- **Resistores:** 330Ω para cada LED
- **Software:** VS Code + Pico SDK + Simulador Wokwi

---

## Bibliotecas Utilizadas e Sua Importância

O código deste projeto utiliza as seguintes bibliotecas essenciais para o funcionamento correto no Raspberry Pi Pico W:

### `#include <stdio.h>`
A biblioteca padrão de entrada e saída do C. Utilizada para permitir a comunicação serial com o computador através da função `printf()`, facilitando a depuração e monitoramento do sistema.

### `#include "pico/stdlib.h"`
A biblioteca padrão do SDK do Raspberry Pi Pico. Contém funções essenciais para manipulação de **GPIOs**, **delays (`sleep_ms()`)**, configuração de hardware e comunicação serial.

### `#include "hardware/timer.h"`
Biblioteca fundamental para a implementação do **temporizador periódico (`add_repeating_timer_ms()`)**, que gerencia o tempo de troca dos LEDs no semáforo.

---

## Funcionalidades Implementadas

- **Controle automático do semáforo utilizando um temporizador periódico.**
- **Alternância dos LEDs (vermelho, amarelo e verde) a cada 3 segundos.**
- **Mensagens seriais informando o status do semáforo a cada 1 segundo.**
- **Simulação completa no Wokwi para validação do código.**

### Simulador para a prototipação do projeto

[Simulador no WOKWI deste projeto](https://wokwi.com/projects/421920880908973057 "Simulador no WOKWI deste projeto")

[![Diagrama de conexões](imgs/imagem_simulador.png "Diagrama de conexões")](https://github.com/hsantosdias/BitDogLab-Semaforo/blob/main/imgs/imagem_simulador.png?raw=true "Diagrama de conexões")
---

## **Fluxograma do projeto**

### **Fluxograma simplificado para a execução do projeto**


> Diagrama fornecido pelo Professor

[![Diagrama simplificado para a construção do projeto Semaforo](imgs/fluxograma_simplificado.png "Diagrama simplificado para a construção do projeto Semaforo")](https://github.com/hsantosdias/BitDogLab-Semaforo/blob/main/imgs/fluxograma_simplificado.png?raw=true "Diagrama simplificado para a construção do projeto Semaforo")

### **Fluxograma completo para a construção do codigo do projeto**

[![Fluxograma do projeto](imgs/fluxograma_principal.png "Fluxograma do projeto")](https://github.com/hsantosdias/BitDogLab-Semaforo/blob/main/imgs/fluxograma_principal.png?raw=true "Fluxograma do projeto")

### Lógica do Semáforo
A seguinte lógica representa o funcionamento do código:

1. **Início**
   - Inicializa a comunicação serial.
   - Configura os GPIOs dos LEDs.

2. **Ciclo do Semáforo**
   - O LED **vermelho** acende e aguarda **3 segundos**.
   - O LED **amarelo** acende e aguarda **3 segundos**.
   - O LED **verde** acende e aguarda **3 segundos**.
   - O ciclo se **reinicia automaticamente**.

3. **Monitoramento na Serial**
   - A cada 1 segundo, uma mensagem é enviada pela comunicação serial para depuração.

---

## Organização do Código

| Diretório / Arquivo          | Descrição                                       |
|------------------------------|-------------------------------------------------|
| **BitDogLab-Semaforo/**      | Diretório raiz do projeto                      |
| ├── **.vscode/**             | Configurações do VS Code                        |
| ├── **docs/**                | Documentação e diagramas                        |
| │   ├── diagram.json         | Representação do fluxograma                    |
| │   ├── README.md            | Documentação do projeto                        |
| ├── **src/**                 | Código-fonte do projeto                        |
| │   ├── BitDogLab-Semaforo.c | Código principal                               |
| │   ├── CMakeLists.txt       | Configuração do CMake                          |
| ├── **build/**               | Diretório para compilação                      |
| ├── **imgs/**                | Imagens e diagramas                            |
| │   ├── fluxograma.png       | Imagem do fluxograma do projeto               |
| ├── pico_sdk_import.cmake    | Arquivo para importar o SDK do Pico           |
| ├── .gitignore               | Arquivo para ignorar arquivos no Git          |
| ├── wokwi-project.txt        | Configuração do projeto no Wokwi              |
| ├── wokwi.toml               | Arquivo de configuração do Wokwi              |

O código está bem **comentado e estruturado** para facilitar modificações futuras.

---

## Demonstração

**Vídeo demonstrativo do professor:**  

[Simulação sugerida no Wokwi](https://www.dropbox.com/scl/fi/6w37qxzdq4ytljqvqzr6h/2025-01-25-17-48-11.mkv?rlkey=yjj1iqcfkx444xigglaxqw81e&e=1&st=9q2qz7vw&dl=0)

---

## Atividades de Teste Realizadas

Durante o desenvolvimento, foram realizados diversos testes para validar a funcionalidade do sistema.

### 1. Teste de Temporização do Semáforo
**Objetivo:** Verificar se os LEDs alternam corretamente a cada **3 segundos**.  
**Resultado:** LEDs alternam corretamente conforme o ciclo esperado.

### 2. Teste de Inicialização
**Objetivo:** Garantir que o LED vermelho começa **ligado** no início da execução.  
**Resultado:** O LED vermelho inicia ligado, indicando que o ciclo está correto.

### 3. Teste de Monitoramento Serial
**Objetivo:** Verificar se mensagens são enviadas corretamente na serial.  
**Resultado:** Mensagens são exibidas corretamente a cada **1 segundo**.

### 4. Teste no Simulador Wokwi
**Objetivo:** Validar o funcionamento completo antes da execução no hardware real.  
**Resultado:** O comportamento no Wokwi reflete a operação esperada do semáforo.

---

## Requisitos

- **Placa BitDogLab (RP2040)**
- **LEDs (Vermelho, Amarelo, Verde)**
- **Resistores de 330Ω para cada LED**
- **VS Code + Pico SDK + Wokwi configurados**

---

## Como Usar

Clone o repositório, compile e faça o upload do código para a placa para testar as funcionalidades!

```bash
git clone https://github.com/hsantosdias/BitDogLab-Semaforo.git
