# minishell

## Presentation
minishell is little bash shell, this shell will shows you a prompt and you can execute the command you want  
<br/>
![minishell 시연2](https://user-images.githubusercontent.com/79124915/194973966-24d94a70-093f-45df-bcd3-8b58a0648745.jpg)
<br/>

## Build
### 1. Rewrite your gnu readline library path in the Makefile  
<br/>

![misishell_makfile 수정](https://user-images.githubusercontent.com/79124915/194975749-863090fd-eef6-4be2-910a-c60f278b38e4.png)



common path ->
`/usr/local/lib` 
`/usr/local/include`


if you can't find readline library  
`yum install readline-devel`

<br/>

### 2. make
excute `make` command in shell

<br/>

### 3. run ./minishell
`./minishell`
