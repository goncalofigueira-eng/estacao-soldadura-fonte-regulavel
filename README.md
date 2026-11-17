# Estação de Soldadura Inteligente e Fonte de Alimentação

Projeto desenvolvido no âmbito da Prova de Aptidão Profissional (PAP) do Curso Profissional de Técnico de Eletrónica e Telecomunicações da Escola Profissional de Aveiro. A PAP obteve a classificação final de 20 valores.

## Problema

O projeto procurou reunir num único equipamento de bancada duas funções úteis para trabalhos de eletrónica: uma estação de soldadura com controlo de temperatura e uma fonte de alimentação regulável.

A necessidade identificada foi desenvolver um solução de uma estação de soldadura robusta, viável e prática a baixo custo, e perceber a tecnologia envolvida no processo de aquecimento dos ferros de soldar.

## Requisitos e limitações

O equipamento foi concebido para incluir:

- Controlo da temperatura do ferro de soldar, com três patamares predefinidos e ajuste manual.
- Interface local com botões, display digital e sinalização visual de temperatura.
- Fonte de alimentação regulável com indicação da tensão.
- Controlo eletrónico do aquecimento através de um microcontrolador e modulação PWM.
- Montagem do circuito da estação numa placa perfurada e integração numa caixa de metal. E montagem da PCB e do circuito da fonte de alimentação regulável numa caixa acrílica.

Os valores de funcionamento e as limitações do projeto foram:

- Temperaturas dos três patamares: 120ºC, 240ºC e 320ºC, sendo este facilmente parametrizados para outros valores.
- Intervalo e resolução do ajuste manual: 0,1ºC.
- Intervalo de tensão e corrente máxima da fonte: 24,5 VDC.
- Orçamento, dimensões ou outras limitações: 35€ por unidade.

## Abordagem

O sistema foi organizado em dois módulos principais: a estação de soldadura e a fonte de alimentação.

Na estação de soldadura, um microcontrolador Arduino processa os comandos dos botões, apresenta informação no display e controla a potência aplicada ao elemento de aquecimento por PWM. A comutação é realizada com MOSFETs de canal N IRFZ44N.

A interface permite selecionar entre dois modos de operação:

- **Automático:** seleção de três patamares de temperatura — Standby, Soldadura Standard e Alta Temperatura.
- **Manual:** ajuste incremental da temperatura através de botões dedicados.

A fonte de alimentação fornece uma saída regulável e apresenta a tensão num segmento de 4 digitos. Os circuitos foram montados em placa perfurada e instalados numa caixa de metal personalizada, no caso da estação. E a PCB numa caixa acrílica.

## Dificuldades e decisões

Durante o desenvolvimento, tive dificuldade com a parametrização da temperatura, uma vez que nem sempre a temperatura do ferro correspondia à temperatura exibida no display.

Uma decisão técnica relevante foi separar a alimentação da estação de soldadura da fonte de alimentação, em dois módulos distintos.

## Resultado

Foi construído um protótipo funcional que integra uma estação de soldadura com controlo de temperatura e uma fonte de alimentação regulável. A PAP obteve a classificação final de 20 valores.

Os valores medidos durante os testes foram:

- Temperatura mínima e máxima verificadas: 30ºC - 360ºC.
- Intervalo de tensão da fonte: 3V - 24,5V.
- Outros testes realizados: O modo standby, verificou-se funcional.

## Aprendizagem e melhorias futuras

O projeto permitiu aplicar conhecimentos de eletrónica, controlo por microcontrolador, comutação de potência, interface com o utilizador e montagem de circuitos. Também envolveu a integração dos módulos numa estrutura física em acrílico.

Numa próxima versão, acrescentaria proteção contra sobrecorrente, melhoraria a precisão da temperatura e usaria uma placa de circuito impresso.

## Componentes principais

- Microcontrolador Arduino Mega.
- MOSFETs de canal N IRFZ44N.
- Condensadores eletrolíticos de 1000 µF e 35 V.
- Display digital de quatro dígitos.
- Botões táteis e buzzer piezoelétrico.
- Díodos de comutação.
- Díodos de retificação.
- Transístores de sinal.
- Bornes de ligação por parafuso.
- Placa perfurada.
- Entre outros.

## Organização do repositório

- `firmware/` — código-fonte C++/Arduino (`estacao_soldadura.ino`).
- `hardware/` — esquemas elétricos e diagramas de ligações.
- `images/` — fotografias do protótipo e dos componentes.

## Autor

Gonçalo Figueira
