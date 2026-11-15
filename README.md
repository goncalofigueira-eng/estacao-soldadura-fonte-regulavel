# Estação de Soldadura Inteligente e Fonte de Alimentação (PAP)

Projeto desenvolvido no âmbito da Prova de Aptidão Profissional (PAP) do Curso Profissional de Técnico de Eletrónica e Telecomunicações da Escola Profissional de Aveiro (EPA), obtendo a classificação final de 20 valores.

---

## 🚀 Resumo do Projeto
Este projeto consistiu no desenvolvimento de um equipamento multifuncional de bancada que integra uma Fonte de Alimentação regulável e uma Estação de Soldadura com controlo térmico. O sistema foi projetado para permitir o controlo rigoroso da temperatura da ponta de soldadura através de 3 patamares predefinidos, interface com botões e visualização num display digital de 4 dígitos em tempo real.

## 💡 Principais Funcionalidades
- **Estação de Soldadura de Controlo Térmico:** Sistema inteligente com seleção rápida de 3 patamares predefinidos de temperatura adaptados a diferentes trabalhos de soldadura.
- **Interface de Utilizador:** Display digital de 4 dígitos e botões táteis para navegação e ajuste dinâmico da temperatura.
- **Módulo de Alimentação de Bancada:** Fornecimento de energia estável e regulado com display indicador de tensão.
- **Controlo por Microcontrolador:** Arquitetura baseada em Arduino para processamento de sinais, leitura de temperatura e modulação de potência.
- **Montagem Física:** Construção tradicional em placa perfurada de alta fiabilidade, alojada numa caixa protetora transparente em acrílico personalizada.

## 📊 Diagrama de Blocos do Sistema
+-----------------------+       +-------------------------+       +----------------------+
|   Alimentação AC/DC   | ----> |   Controlador Arduino   | ----> |   Etapa de Potência  |
|  (Transformador +     |       |  (Leitura Temp + Botões |       |   (MOSFET IRFZ44N +  |
|   Retificação/Filtro) |       |   + 3 Patamares)        |       |    Ferro de Soldar)  |
+-----------------------+       +-------------------------+       +----------------------+
|
v
+-------------------------+
|    Interface Visual     |
|   (Display 4 Dígitos)   |
+-------------------------+


## 🛠️ Lista de Materiais (BOM) & Componentes
O circuito foi inteiramente montado em placa perfurada, utilizando os seguintes componentes principais:
- **Controlador:** Microcontrolador compatível com Arduino (Uno / Mega).
- **Potência e Comutação:** Transístores MOSFET N-Channel IRFZ44N para o controlo PWM do elemento de aquecimento do ferro de soldar.
- **Filtragem de Alimentação:** Condensadores eletrolíticos de 1000µF 35V.
- **Conetividade:** Bornes de aperto de parafuso (terminais de placa azuis).
- **Interface Visual e Sonora:** Display digital de 4 dígitos, botões táteis e buzzer piezoelétrico para feedback acústico.
- **Processamento e Sinal:** Díodos de comutação/retificação e transístores de sinal TO-92.

## 🖼️ Galeria de Imagens do Projeto

### Unidade de Controlo e Fonte de Alimentação
*(Fonte de alimentação regulável montada na caixa em acrílico transparente)*
![Fonte de Alimentação Montada](./images/fonte-alimentacao-montada.jpg)

### Componentes e Hardware Utilizados
*(Exemplo dos MOSFETs IRFZ44N, condensadores de filtragem e componentes semicondutores)*
![Componentes Eletrónicos](./images/componentes.jpg)

### Conjunto do Ferro de Soldar
*(Detalhe do interior do punho e elemento de aquecimento/sensor integrado)*
![Ferro de Soldar Interno](./images/ferro-soldar.jpg)

## 📂 Organização do Repositório
- `/firmware` - Código fonte em C++/Arduino.
- `/hardware` - Esquemas elétricos e diagramas de ligações.
- `/images` - Fotografias do protótipo final e dos componentes reais.

---
*Autor: Gonçalo Figueira*
