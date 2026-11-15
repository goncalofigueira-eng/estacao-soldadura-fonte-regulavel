# Arquitetura de Hardware e Tabela de Ligações (Pinout)

## 1. Arquitetura de Alimentação Unificada
O sistema foi projetado para funcionar de forma autónoma e centralizada a partir de uma única entrada de rede a **220V AC**:
* **Secção de Potência:** A tensão da rede passa por um transformador redutor e uma ponte retificadora, seguida por condensadores eletrolíticos de filtragem de grande capacidade (1000µF 35V), criando o barramento de alta potência que alimenta diretamente o elemento de aquecimento do ferro de soldar através do transístor MOSFET de potência.
* **Secção de Controlo (Baixa Tensão):** Para alimentar o microcontrolador Arduino, o display digital de 4 dígitos e os circuitos lógicos, o projeto integra um circuito redutor/regulador interno de tensão (como um regulador linear ou conversor buck) derivado da mesma fonte principal, garantindo um isolamento e estabilidade adequados a toda a lógica de controlo.

---

## 2. Tabela de Ligações (Pinout) - Controlo e Periféricos

| Componente / Periférico | Pino / Terminal | Pino no Arduino | Descrição da Ligação / Notas Técnicas |
| :--- | :--- | :--- | :--- |
| **Transístor MOSFET (IRFZ44N)** | Gate (G) | `D3` (PWM) | Ligado através de uma resistência de $220\,\Omega$ em série e uma resistência de pull-down de $10\,\text{k}\Omega$ ao GND. |
| **Sensor de Temperatura** | Pino de Sinal | `A0` (Analógico) | Leitura analógica da tensão proporcional à temperatura da ponta do ferro. |
| **Display 4 Dígitos (TM1637)** | CLK / DIO | `D9` / `D10` | Linhas de comunicação digital para controlo do ecrã de 4 dígitos. |
| **Buzzer Piezoelétrico** | Terminal Positivo (+) | `D2` | Terminal negativo ligado diretamente ao GND comum. |
| **Botão Modo (Auto/Manual)** | Terminal 1 | `D4` | Terminal 2 ligado ao GND (utiliza o modo `INPUT_PULLUP` interno do Arduino). |
| **Botão Patamar (1/2/3)** | Terminal 1 | `D5` | Terminal 2 ligado ao GND (utiliza `INPUT_PULLUP` interno). |
| **Botão Aumentar (+)** | Terminal 1 | `D6` | Terminal 2 ligado ao GND (utiliza `INPUT_PULLUP` interno). |
| **Botão Diminuir (-)** | Terminal 1 | `D7` | Terminal 2 ligado ao GND (utiliza `INPUT_PULLUP` interno). |

---

## 3. Etapa de Potência e Atuação
* **Drain (D) do IRFZ44N:** Conectado ao terminal negativo da resistência de aquecimento do ferro de soldar.
* **Source (S) do IRFZ44N:** Conectado ao plano de massa (GND) comum do circuito.
* **Alimentação da Resistência:** O terminal positivo da resistência de aquecimento recebe a tensão contínua retificada da fonte principal, protegida por um díodo de roda livre (*flyback*, ex: 1N4007) em antiparalelo.
