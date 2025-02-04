# **BitDogLab-Semaforo**

**Tarefa 1 - Temporizador Periódico (Semáforo)**


 **Controle de Temporizador Periódico no RP2040 - BitDogLab**

Este projeto demonstra o uso de um **temporizador periódico (`add_repeating_timer_ms()`)** no **microcontrolador RP2040**, utilizando a placa **BitDogLab**. A implementação consiste em um **sistema de semáforo**, onde os LEDs alternam suas cores em intervalos fixos, simulando um ciclo real de trânsito.

---

## **Funcionalidades Implementadas**

### **Atividade 1: Temporizador Periódico (Semáforo)**

- Utiliza a função **add_repeating_timer_ms()** para alternar os LEDs do semáforo (**vermelho, amarelo e verde**) a cada **3 segundos**.
- Implementação da função **repeating_timer_callback()** para controle dos estados dos LEDs.
- Impressão de mensagens na **porta serial** a cada **1 segundo**.
- Simulação e testes com **LED RGB na ferramenta BitDogLab**.

---

##  **Tecnologias e Conceitos Utilizados**

- Uso de **temporizadores periódicos** no **RP2040**.
- Manipulação de **GPIOs para controle dos LEDs**.
- **Mensagens seriais** para monitoramento do sistema.
- Integração com o **simulador Wokwi** para validação do código.

### Simulador para a prototipação do projeto

[Simulador no WOKWI deste projeto](https://wokwi.com/projects/421920880908973057 "Simulador no WOKWI deste projeto")

---

## **Organização do Código**

O código está estruturado e comentado para facilitar a compreensão e reutilização.

 Código-fonte do semáforo
 Documentação complementar
 Testes para validação das funcionalidades

---

## **Demonstração do professor**

Vídeo demonstrativo do funcionamento do projeto(Video do Professor):
 **[Semáforo no Wokwi - Vídeo](https://www.dropbox.com/scl/fi/6w37qxzdq4ytljqvqzr6h/2025-01-25-17-48-11.mkv?rlkey=yjj1iqcfkx444xigglaxqw81e&dl=0)**

---

## **Requisitos**

- **Placa de desenvolvimento BitDogLab (RP2040)**
- **LEDs** (Vermelho, Amarelo, Verde)
- **Resistores de 330Ω para cada LED**
- **VS Code com Pico SDK e Simulador Wokwi** configurados

---

## **Como Usar**

Clone o repositório, compile e faça o upload do código para a placa para testar as funcionalidades!

```bash
git clone https://github.com/hsantosdias/BitDogLab-Semaforo.git
```
