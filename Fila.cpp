#include <iostream>
#include <conio.h>
#include <string.h>
#define MAX_FILA 5 //constante
using namespace std;

struct DADOS_ALUNO {
    int CodAluno;
    char Nome[100], Turma;
    bool Removido;
};

bool Enfileirar(DADOS_ALUNO Fila[], int CodAluno, char Nome[], char Turma, int &FimFila, int &TotalFila);
bool Exibir(DADOS_ALUNO Fila[], int IniFila, int FimFila, int TotalFila);
bool Desenfileirar(DADOS_ALUNO Fila[], int &IniFila, int &TotalFila);
bool ExibirTurmaA (DADOS_ALUNO Fila [], int IniFila, int FimFila, int TotalFila);
bool ExibirTurmaB (DADOS_ALUNO Fila [], int IniFila, int FimFila, int TotalFila);
main() {

struct DADOS_ALUNO FilaAlunos [MAX_FILA]; 
int IniFila= 0;
int TotalFila =0; 
int FimFila = 0; 
bool Ret; int CodAluno, opcao;

char Nome[100], Turma;


do {

cout << "\n1 - Enfieirar \n";
cout<<"\n2 - Exibir \n";
cout<<"\n3 - Desenfileirar \n";
cout<<"\n4 - Sair \n";
cout<<"\nDigite a opcao: ";
cin >> opcao;
switch (opcao) {
case 1: cout << "Insercao: " << endl;
cout << "Digite o codigo do aluno: ";
cin >> CodAluno;
cout << "Digite o nome do aluno: ";
cin >> Nome;
cout<<"Digite a turma: (A) ou (B)";
cin >> Turma;
Ret = Enfileirar (FilaAlunos, CodAluno, Nome, Turma, FimFila, TotalFila);
if (Ret == true) {
cout<<"\nInsercao efetuada com sucesso!" << endl;
}
system ("cls");
break;
case 2: Ret = Exibir (FilaAlunos, IniFila, FimFila, TotalFila);
if (Ret == false) {
cout<<"\nNao foi possivel exibir a fila." << endl;
}
break;
case 3: Ret = Desenfileirar (FilaAlunos, IniFila, TotalFila); if (Ret == false) {
cout<<"\nNão foi possível desenfileirar a fila." << endl; }
break;
case 4: cout<<"\nSaindo do programa!!!";
break;
default: cout << "\n\nERRO: A opcao digitada nao eh valida. Tente novamente...\n";
} 
} while (opcao!=4);
getch();
} 

bool Enfileirar (DADOS_ALUNO Fila [], int CodAluno, char Nome [], char Turma, int &FimFila,
int &TotalFila) {
if (TotalFila == MAX_FILA) {
cout<<"ERRO: Fila cheia.";
return false;
}
else{
Fila [FimFila].CodAluno = CodAluno; strcpy (Fila [FimFila].Nome, Nome);
Fila [FimFila].Turma = Turma;
Fila [FimFila]. Removido = false;
FimFila++;

if (FimFila == MAX_FILA)
FimFila = 0;
TotalFila++;
}
return true;
}

bool Exibir (DADOS_ALUNO Fila[], int IniFila, int FimFila, int TotalFila){

int ind;
if(TotalFila == 0) { 
cout<<"ERRO: Fila vazia.";
return false;
}
if (IniFila< FimFila) {
for (ind = IniFila; ind< FimFila; ind++) { 
cout << "Codigo do Aluno: " << Fila [ind].CodAluno <<endl;
cout << "Nome: " << Fila [ind].Nome <<endl;
cout << "Turma: " << Fila [ind].Turma <<endl;
}
}else{
for (ind = IniFila; ind< MAX_FILA; ind++) {
if (Fila[ind].Removido == false) {
cout<<"Codigo do Aluno: " << Fila [ind].CodAluno << endl;
cout << "Nome: " << Fila [ind].Nome <<endl; cout << "Turma: " << Fila [ind].Turma <<endl;
}
}
for (ind = 0; ind < FimFila; ind++) {
if (Fila [ind].Removido == false) {
cout<<"Codigo do Aluno: " << Fila [ind].CodAluno <<endl; cout << "Nome: " << Fila [ind].Nome <<endl; }
cout << "Turma: " << Fila [ind].Turma <<endl;
}
}
return true;
}

bool Desenfileirar (DADOS_ALUNO Fila [], int &IniFila, int &TotalFila) {
int ind;
int PosRem;
if (TotalFila == 0) { cout<<"ERRO: Fila vazia.";
return false;
}

Fila [IniFila]. Removido = true;
cout<<"\nElemento desenfileirado com sucesso!\n";
IniFila++;

if(IniFila == MAX_FILA){
IniFila = 0;
TotalFila--;
return true;
}
}