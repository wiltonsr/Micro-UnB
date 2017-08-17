# Atividade 02 - Data: 11/08/2017

### 1. **Quais as diferenças entre os barramentos de dados e de endereços?**
```
Barramentos são linhas de comunicação (condutor elétrico ou fibra optica) que
permitem a interligação entre dispositivos de um sistema de computação. O
Barramento de Dados (Data Bus) transmite dados entre as unidades e normalmente
é bi-direcional, isto é, pode transmitir em ambas as direções.
Já o Barramento de Endereço (Address Bus) é usado para selecionar a origem ou
destino de sinais transmitidos num dos outros barramentos ou numa de suas linhas.
Ele conduz endereços. Uma função típica do Barramento de Endereço é selecionar
um registrador num dos dispositivos do sistema que é usado como a fonte ou o
destino do dado.
```

### 2. **Quais são as diferenças entre as memórias RAM e ROM?**
```
A memória RAM (Random Access Memory), ou memória de acesso randômico, é uma memória
volátil que, normalmente, perde o conteúdo quando há o corte de energia. Tem uma
alta velocidade de escrita.
A memória ROM (Read Only Memory), memória apenas de leitura, é uma memória não-volátil
que mantém o conteúdo mesmo quando não há fonte de alimentação. Embora sua velocidade
de escrita seja bem menor que na RAM.
```

### 3. **Considere o código abaixo:**

```C
#include <stdio.h>
int main(void)
{
	int i;
	printf("Insira um número inteiro: ");
	scanf("%d", &i);
	if(i%2)
		printf("%d eh impar.\n");
	else
		printf("%d eh par.\n");
	return 0;
}
```

Para este código, responda:
- ### **(a) A variável `i` é armazenada na memória RAM ou ROM? Por quê?**
```
Na memória RAM, pois recomenda-se que variáveis e coisas com alta mudança sejam
gravadas na memória RAM.
```

- ### **(b) O programa compilado a partir deste código é armazenado na memória RAM ou ROM? Por quê?**
```
Uma vez que variáveis são gravadas na memória RAM, dados importantes como: senhas,
programas compilados, constantes e etc devem ser gravados na memória ROM.
```

### 4. **Quais são as diferenças, vantagens e desvantagens das arquiteturas Harvard e Von Neumann?**
```
A arquitetura Harvard permite leitura simultânea de dados e de programa, pois
possui um barramento dedicado para cada uma das memórias. Para isso, ela separa
as memória RAM e ROM de forma otimizada além de armazenar dados constantes na
memória de programa.
Já na arquitetura Von Neumann há apenas uma pilha única de memórias, com isso não
é possível a leitura simultânea de dados. Dessa forma a arquitetura se torna mais
simples, mas menos eficiente que a anterior.
```

### 5. **Considere a variável inteira `i`, armazenando o valor `0x8051ABCD`. Se `i` é armazenada na memória a partir do endereço `0x0200`, como ficam este byte e os seguintes, considerando que a memória é:**
- ### **(a) Little-endian;**
```
Nas memórias do tipo Little-endian o termo menos representativo da palavra, nesse
caso o `CD`, são armazenados a partir do primeiro endereço. Ou seja:
```
End. Memória | Valor armazenado
:---------:  | :------:
0x0200       | 0xCD
0x0201       | 0xAB
0x0202       | 0x51
0x0203       | 0x80

- ### **(b) Big-endian.**
```
Nas memórias do tipo Big-endian o termo mais representativo da palavra, nesse
caso o `80`, são armazenados a partir do primeiro endereço. Ou seja:
```
End. Memória | Valor armazenado
:---------:  | :------:
0x0200       | 0x80
0x0201       | 0x51
0x0202       | 0xAB
0x0203       | 0xCD

### 6. **Sabendo que o processador do MSP430 tem registradores de 16 bits, como ele soma duas variáveis de 32 bits?**
```
Como a arquitetura do processador do MSP430 não possui registradores capazes de
lidar diretamente com palavras maiores que 16 bits, há um bit especial chamado
carry bit que o MSP430 utiliza para realizar essas operações.
```
