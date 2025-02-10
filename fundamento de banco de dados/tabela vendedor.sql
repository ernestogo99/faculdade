create table vendedores
(matr smallint not null,
nome varchar(60) not null,
cpf int not null,
ender varchar(55) not null,
salario dec(11,2) not null,
gerencia smallint,
lotacao smallint not null,
constraint pk_vendedores
primary key (matr),
constraint cpf_unico unique (cpf),
constraint fk_gerencia 
foreign key (gerencia)
references filiais 
on delete no action
on update no action,
constraint fk_lotacao
foreign key (lotacao)
references filiais 
on delete no action
on update no action,
constraint sal_minimo
check(salario>2000)
)

