# 🃏 Super Trunfo: Comparações Avançadas com Atributos Múltiplos

Este é o desafio **nível mestre** do Super Trunfo em linguagem C!  
Aqui, o jogador pode comparar cartas de países usando **dois atributos numéricos diferentes**, com menus dinâmicos, lógica de soma e tratamento de empates.

---

## 📦 Sobre o Projeto

Este programa foi desenvolvido como parte do desafio final proposto no curso de programação em C.  
O objetivo é comparar **duas cartas de países** com base em **dois atributos escolhidos pelo jogador**, somar os valores e declarar o vencedor com base na maior soma.

---

## ✅ Funcionalidades

- Escolha interativa de **dois atributos diferentes** para comparação.
- **Comparação com regras especiais**, como "menor vence" para Densidade Demográfica.
- **Soma dos dois atributos** para determinar a carta vencedora.
- **Menus dinâmicos** com `switch` que evitam a seleção duplicada de atributos.
- **Mensagens claras e organizadas** com:
  - Nome dos países
  - Valores dos dois atributos escolhidos
  - Soma dos atributos
  - Resultado final da rodada
- **Tratamento de empates e entradas inválidas** com `default` nos menus.

---

## ⚙️ Como Compilar e Executar

### 🔧 Pré-requisitos

Você precisa ter um compilador C instalado (como GCC).

- **Windows:** [MinGW](https://www.mingw-w64.org/)
- **Linux/macOS:** GCC geralmente já está instalado

### 🧪 Compilando e executando

```bash
gcc super_trunfo.c -o super_trunfo
./super_trunfo
