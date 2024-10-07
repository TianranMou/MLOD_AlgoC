#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
    return a == NULL;
}


// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) {
    *a = NULL;
}


// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {
    ArbreBinaire nouveau = (ArbreBinaire)malloc(sizeof(Noeud));  // 1.分配内存
    if (nouveau != NULL) {                                      // 2.检查内存是否分配成功
        nouveau->val = e;                                        // 3.设置节点的值
        nouveau->filsGauche = NULL;                              // 4.左子节点为空
        nouveau->filsDroit = NULL;                               // 5.右子节点为空
    }
    return nouveau;                                              // 6.返回新创建的节点
}


// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
    ArbreBinaire nouveau = creer(e);  // 1. 创建新节点
    if (a == NULL) {                  // 2. 如果树为空，新节点就是根节点
        return nouveau;
    }

    ArbreBinaire courant = a;         // 3. 用来遍历树的指针，开始时指向根节点
    ArbreBinaire parent = NULL;       // 4. 用来保存当前节点的父节点

    while (courant != NULL) {         // 5. 遍历树，直到找到插入的位置
        parent = courant;             // 6. 记录父节点
        if (e < courant->val) {       // 7. 如果新值比当前节点小，去左子树查找
            courant = courant->filsGauche;
        } else if (e > courant->val) { // 8. 如果新值比当前节点大，去右子树查找
            courant = courant->filsDroit;
        } else {                      // 9. 如果新值等于当前节点的值，直接返回（不插入重复值）
            free(nouveau);
            return a;
        }
    }

    // 10. 找到插入位置后，将新节点挂在找到的父节点的相应位置
    if (e < parent->val) {
        parent->filsGauche = nouveau;
    } else {
        parent->filsDroit = nouveau;
    }

    return a;  // 11. 返回根节点
}


// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e) {
    if (a == NULL) {
        return creer(e);
    }

    if (e < a->val) {
        a->filsGauche = insere_r(a->filsGauche, e);
    } else if (e > a->val) {
        a->filsDroit = insere_r(a->filsDroit, e);
    }

    // 如果元素已存在，不插入
    return a;
}



// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a) {
    if (a == NULL) {
        return 0;
    }
    return 1 + nombreDeNoeud(a->filsGauche) + nombreDeNoeud(a->filsDroit);
}



// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e) {
    if (a == NULL) {
        return -1;
    }

    if (e == a->val) {
        return 0;
    } else if (e < a->val) {
        int left_depth = profondeur(a->filsGauche, e);
        return (left_depth == -1) ? -1 : left_depth + 1;
    } else {
        int right_depth = profondeur(a->filsDroit, e);
        return (right_depth == -1) ? -1 : right_depth + 1;
    }
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a) {
    if (a == NULL) {
        return 0;
    }
    int hauteurGauche = hauteur(a->filsGauche);
    int hauteurDroit = hauteur(a->filsDroit);
    return 1 + (hauteurGauche > hauteurDroit ? hauteurGauche : hauteurDroit);
}


ArbreBinaire pere(ArbreBinaire a, Element elem) {
    if (a == NULL || a->val == elem) {
        return NULL; // 如果树为空或当前节点是根节点，返回 NULL
    }

    ArbreBinaire parent = NULL; // 用于存储父节点
    ArbreBinaire courant = a;   // 用于遍历树的指针

    while (courant != NULL) {
        if (elem < courant->val) {
            parent = courant;              // 当前节点可能是父节点
            courant = courant->filsGauche; // 向左子树移动
        } else if (elem > courant->val) {
            parent = courant;              // 当前节点可能是父节点
            courant = courant->filsDroit;  // 向右子树移动
        } else {
            // 找到目标节点，返回其父节点
            return parent;
        }
    }

    // 如果未找到目标节点，返回 NULL
    return NULL;
}


void afficheGRD_r(ArbreBinaire a) {
    if (a != NULL) {
        afficheGRD_r(a->filsGauche);
        printf("%d ", a->val);
        afficheGRD_r(a->filsDroit);
    }
}


void afficheGDR_r(ArbreBinaire a){
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a) {
    if (a == NULL) {
        return NULL;
    }
    while (a->filsGauche != NULL) {
        a = a->filsGauche;
    }
    return a;
}


// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a) {
    if (a == NULL) {
        return NULL;
    }
    while (a->filsDroit != NULL) {
        a = a->filsDroit;
    }
    return a;
}



// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element e) {
    if (a == NULL || a->val == e) {
        return a;
    }

    if (e < a->val) {
        return recherche_r(a->filsGauche, e);
    } else {
        return recherche_r(a->filsDroit, e);
    }
}



// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a, Element e) {
    if (a == NULL) {
        return NULL;
    }

    if (e < a->val) {
        a->filsGauche = supprimer_r(a->filsGauche, e);
    } else if (e > a->val) {
        a->filsDroit = supprimer_r(a->filsDroit, e);
    } else {
        if (a->filsGauche == NULL) {
            ArbreBinaire temp = a->filsDroit;
            free(a);
            return temp;
        } else if (a->filsDroit == NULL) {
            ArbreBinaire temp = a->filsGauche;
            free(a);
            return temp;
        }

        ArbreBinaire temp = min(a->filsDroit);
        a->val = temp->val;
        a->filsDroit = supprimer_r(a->filsDroit, temp->val);
    }

    return a;
}

void detruire_r(ArbreBinaire a) {
    if (a != NULL) {
        detruire_r(a->filsGauche);
        detruire_r(a->filsDroit);
        free(a);
    }
}

void prettyPrint(ArbreBinaire a, int depth) {
    // if null print x!
    if (a == NULL) {
        for (int i = 0; i < depth; i++) {
            printf("|--");
        }
        printf("X\n");
        return;
    }

    // print if not null
    for (int i = 0; i < depth; i++) {
        printf("|--");
    }
    printf("%d\n", a->val);

    prettyPrint(a->filsDroit, depth + 1);

    prettyPrint(a->filsGauche, depth + 1);
}



