#include<bits/stdc++.h>

using namespace std;

typedef struct Tarefa {
	int lucro;
	int tempo;
} tarefa;

bool sortL(const tarefa t1, const tarefa t2) {
	if(t1.lucro == t2.lucro) {
		if(t1.tempo < t2.tempo) {
			return true;
		} else {
			return false;
		}
	}
	return t1.lucro > t2.lucro;
}

int main(){
	tarefa tarefas[1000], tarefasH[1000];
	int N, H, loss, res;
	
    while(~scanf("%d %d", &N, &H)) {
        loss = 0;
        
        for(int i = 0; i < N; i++) {
            scanf("%d %d", &(tarefas[i].lucro), &(tarefas[i].tempo));
            tarefasH[i].lucro = -1;
        }
        
        sort(tarefas, tarefas + N, sortL);
		
		// pra cada tarefa, começando da que dá mais lucro
		for(int i = 0; i < N; i++) {
			// olha as que dá pra fazer na mesma hora que a i que foram armazenadas em tarefasH
			int j = tarefas[i].tempo - 1;
			// não entra se for a primeira iteração, j >= 0
            while(j >= 0 && tarefasH[j].lucro != -1) {
            	j--;
            }
            // se j < 0, não compensa fazer essa tarefa e a gente perde ela
            if(j < 0) {
                loss += tarefas[i].lucro;
            } else { // senão, a tarefa é adicionada à "fila"
                tarefasH[j] = tarefas[i];
            }
        }
        
        printf("%d\n", loss);
    }
    
    return 0;
}
