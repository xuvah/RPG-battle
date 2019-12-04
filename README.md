# RPG-battle 1.0(manual)
É um jogo que simula Batalhas 1v1 no estilo RPG de texto, no qual o jogador esconlhe entre as ações possíveis e vai enfrentando oponentes cada vez mais fortes.
Para compilar o programa e so baixar o arquivo main e os arquivos ".h" deixar na mesma pasta e compilar. Tambem pode ser jogado pelo link https://onlinegdb.com/HJbWblmpB executando a compilação online.
Ao executar o jogo o jogador deverá escolher sua classe de acordo com o menu apertando a opçao desejada e "ENTER"em seguida.As classes disponíveis até o momento são:
1 Lutador : classe padrão de RPG Combatente equilibrado que pode aumentar alguns atributos basicos atravéz de sua fúria (que gasta mana)
2 Mago : Frágil e fraco, porem tem um multiplicador de 2X em sua mana e sua fúria causa muito dano.
3 Tank : Combatente mediano porém com muita vida. Sua fúria aumenta ainda mais sua resistêcia.
4 Curandeiro: Encantador com atributos medianos. Mas sua fúria regenera uma grande quantidade considerável de sua vida, além de sua fúria causar dano baseado em seu hp atual
Sobre o combate:
É realizado em turnos, voce escolhe a ação e seu oponente tomara outra ação em contrapartida cada turno e calculado em dano cusado e dano automitigado ao final de cada rodada. Conjurar sua habilidade especial causará alteraçoes no seu dano causado e dano automitigado.Os personagens ganham 5 pontos de mana por rodada. No final de cada Rodada é possivel apertar (Y) na confirmação para rever seus atributos e os atributos de seu oponente.
Sobre a Furia:
A fúria é o ataque especial dos personagens Usá-la consome mana e se sua mana não for suficiente voçê perdera sua vez na rodada. Cada classe possui uma furia diferente mas ao conjuralá saiba que estará mais vunerável a ataques.
Sobre o jogo:
Ao derrotar um oponente voçê terá a opção de continuar jogando ao apertar (Y) na janela de confirmação, o que gerará outro oponente,provavelmente mais forte que o anterior ou de finalizar o jogo e ver seu score. Ao zerar seus pontos de vida seu score é zerado, porém voce terá a opção de começar um novo jogo ao apertar (y) na confirmação ou de fechar o jogo.
******************************************************************************************************************************************
Informações técnicas:
Trabalho de PDS2 Aluno Filipe Augusto Marques de Paula Turma TF
O uso de OO foi dado na criação da classe Camp e de sua classe herdeira que possui elemento private, Inimigo no qual houve polimorfismo de métodos. No codigo pode ser observado o uso de Construtores do destrutor delete metodos de iniciação e modularização.
