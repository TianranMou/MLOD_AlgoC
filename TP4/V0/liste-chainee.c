#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
    return l == NULL;
}


// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v) {
    // 分配内存给新节点
    Liste new_node = (Liste)malloc(sizeof(Cellule));

    // 检查内存分配是否成功
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    // 初始化节点的值和指针
    new_node->val = v;
    new_node->suiv = NULL;

    return new_node;
}


Liste ajoutTete(Element v, Liste l) {
    // 创建一个新节点
    Liste new_node = creer(v);

    // 检查是否成功创建节点
    if (new_node == NULL) {
        return l;  // 如果内存分配失败，返回原链表
    }

    // 新节点指向当前链表头部
    new_node->suiv = l;

    // 返回新的链表头部
    return new_node;
}






// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheElement(Element e) {
    printf("%d ", e);
}


// version recursive
void afficheListe_i(Liste l) {
    while (l != NULL) {
        afficheElement(l->val);  // 打印当前节点的值
        l = l->suiv;  // 移动到下一个节点
    }
    printf("\n");
}

void afficheListe_r(Liste l) {
    if (l == NULL) {
        return;
    }
    afficheElement(l->val);
    afficheListe_r(l->suiv); // 递归调用
}

void detruireElement(Element e) {}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
    while (l != NULL) {
        Liste temp = l;  // 保存当前节点
        l = l->suiv;  // 移动到下一个节点
        free(temp);  // 释放当前节点的内存
    }
}


// version récursive
void detruire_r(Liste l) {
    if (l == NULL) {
        return;  // 如果链表为空，直接返回
    }
    detruire_r(l->suiv);  // 递归销毁下一个节点
    free(l);  // 释放当前节点
}


// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
    // 创建一个新节点
    Liste new_node = creer(v);
    if (new_node == NULL) {
        return l;  // 如果内存分配失败，返回原链表
    }

    // 如果链表为空，新节点就是链表的头
    if (l == NULL) {
        return new_node;
    }

    // 遍历链表，找到最后一个节点
    Liste temp = l;
    while (temp->suiv != NULL) {
        temp = temp->suiv;
    }

    // 将新节点加到链表尾部
    temp->suiv = new_node;
    return l;
}


// version recursive
Liste ajoutFin_r(Element v, Liste l) {
    // 如果链表为空，直接返回新创建的节点
    if (l == NULL) {
        return creer(v);
    }
    // 递归地处理链表的下一个节点
    l->suiv = ajoutFin_r(v, l->suiv);
    return l;  // 返回链表头
}


// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v, Liste l) {
    while (l != NULL) {
        if (l->val == v) {
            return l;  // 找到元素，返回该节点
        }
        l = l->suiv;  // 移动到下一个节点
    }
    return NULL;  // 如果没找到，返回NULL
}


// version récursive
Liste cherche_r(Element v, Liste l) {
    // 如果链表为空或者找到匹配的元素，返回该节点
    if (l == NULL || l->val == v) {
        return l;
    }
    // 递归查找下一个节点
    return cherche_r(v, l->suiv);
}


// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
    // 如果链表为空，直接返回
    if (l == NULL) {
        return l;
    }

    // 如果头节点就是要删除的节点
    if (l->val == v) {
        Liste temp = l->suiv;  // 保存下一个节点
        free(l);  // 释放当前节点
        return temp;  // 返回新的链表头
    }

    // 遍历链表，找到要删除的节点
    Liste prev = l;
    Liste curr = l->suiv;
    while (curr != NULL) {
        if (curr->val == v) {
            prev->suiv = curr->suiv;  // 断开当前节点
            free(curr);  // 释放当前节点
            return l;  // 返回修改后的链表
        }
        prev = curr;
        curr = curr->suiv;
    }

    return l;  // 如果没找到要删除的节点，返回原链表
}



// version recursive
Liste retirePremier_r(Element v, Liste l) {
    // 如果链表为空，直接返回
    if (l == NULL) {
        return l;
    }

    // 如果当前节点是要删除的节点
    if (l->val == v) {
        Liste temp = l->suiv;  // 保存下一个节点
        free(l);  // 释放当前节点
        return temp;  // 返回新链表头
    }

    // 递归地处理链表的下一个节点
    l->suiv = retirePremier_r(v, l->suiv);
    return l;
}



void afficheEnvers_r(Liste l) {
    // 如果链表为空，直接返回
    if (l == NULL) {
        return;
    }

    // 先递归处理下一个节点
    afficheEnvers_r(l->suiv);

    // 然后打印当前节点的值
    afficheElement(l->val);
}




