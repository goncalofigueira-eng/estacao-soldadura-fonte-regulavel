# Estação de Soldadura Inteligente e Fonte de Alimentação (PAP)

Projeto desenvolvido no âmbito da Prova de Aptidão Profissional (PAP) do Curso Profissional de Técnico de Eletrónica e Telecomunicações da Escola Profissional de Aveiro (EPA), obtendo a classificação final de 20 valores.

---

## 🚀 Resumo do Projeto
Este projeto consistiu no desenvolvimento de um equipamento multifuncional de bancada que integra uma Fonte de Alimentação regulável e uma Estação de Soldadura com controlo térmico. O sistema foi projetado para permitir o controlo rigoroso da temperatura da ponta de soldadura através de 3 patamares predefinidos, interface com botões e visualização num display digital de 4 dígitos em tempo real.

## 💡 Principais Funcionalidades
- **Dois Modos de Operação:**
  - **Modo Automático:** Seleção rápida entre 3 patamares predefinidos de temperatura (Standby, Soldadura Standard e Alta Temperatura).
  - **Modo Manual:** Ajuste livre e incremental da temperatura através de botões dedicados (`+` e `-`).
- **Interface de Utilizador:** Display digital de 4 dígitos e botões táteis para navegação e feedback acústico por buzzer.
- **Módulo de Alimentação de Bancada:** Fornecimento de energia estável e regulado com display indicador de tensão.
- **Controlo por Microcontrolador:** Arquitetura baseada em Arduino para processamento de sinais, leitura de temperatura e modulação PWM de potência.
- **Montagem Física:** Construção tradicional em placa perfurada de alta fiabilidade, alojada numa caixa protetora transparente em acrílico personalizada.
  
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
<img width="3024" height="4032" alt="Photo 14-12-2020, 10 05 54" src="https://github.com/user-attachments/assets/42d2fee0-7945-4eed-aed5-b9f55e8a5e16" />


### Componentes e Hardware Utilizados
<img width="4592" height="3056" alt="DSC01843" src="https://github.com/user-attachments/assets/ceb27c5d-45e0-4d3f-bbaf-76762421f289" />
<img width="4592" height="3056" alt="DSC01850" src="https://github.com/user-attachments/assets/87077f9c-4709-4fd7-8f05-f086a4aea728" />
<img width="4592" height="3056" alt="DSC01836" src="https://github.com/user-attachments/assets/94e7ed4d-3c18-476f-bfd3-9da43963dc88" />
<img width="4592" height="3056" alt="DSC01854" src="https://github.com/user-attachments/assets/bf6839db-a2e9-4150-a1ab-50dbc920a2cb" />
<img width="4592" height="3056" alt="DSC01865" src="https://github.com/user-attachments/assets/2f84ce44-9f99-465f-a6ff-7dbce29b5147" />


### Conjunto do Ferro de Soldar
<img width="4592" height="3056" alt="DSC01876" src="https://github.com/user-attachments/assets/ada7bd70-ccc3-47e4-9cf3-db4a084fa2cc" />


## 📂 Organização do Repositório
- `/firmware` - Código fonte em C++/Arduino (`estacao_soldadura.ino`).
- `/hardware` - Esquemas elétricos e diagramas de ligações.
- `/images` - Fotografias do protótipo final e dos componentes reais.

---
*Autor: Gonçalo Figueira*
