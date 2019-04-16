Nome :
	Victor Henrique de Souza Rodrigues

NUSP:
	9791027


Como usar o programa:

	-> No makefile há 3 comandos:
		-> make all para compilar;
		->make example para rodar um exemplo com valores fixos (não altera o d nem o número de elementos);
		->make debug para checar vazamentos de memória com a mesma entrada do make example (não altera o d nem o número de elementos);
	
	-> Para rodar o código:
		Digite na linha de comando o ./heap seguido do valor de "d" desejado, seguido do número de elementos a serem inseridos, seguido do valor mínimo e do valor máximo (range).

		Exemplo:
			./heap 4 17 0 100
		
		No exemplo acima estou criando uma heap-4-ária, inserindo 17 elementos aleatórios no intervalo de 0 a 100.
