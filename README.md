# 🔢 push_swap

## 📌 Description

**push_swap** est un projet du **Common Core de l’école 42**.  
L’objectif est de trier une pile d’entiers en utilisant **un nombre limité
d’opérations**, tout en produisant **le minimum de mouvements possible**.

Ce projet permet de renforcer :
- la compréhension des **algorithmes de tri**
- la manipulation de **structures de données**
- l’optimisation des performances
- la rigueur en **langage C**

---

## 🧠 Principe du projet

Le programme reçoit une liste d’entiers en arguments et doit les trier à l’aide
de **deux piles** :

- **Pile A** : pile principale (entrée)
- **Pile B** : pile auxiliaire

Seules les opérations autorisées par le sujet peuvent être utilisées.

---

## ⚙️ Opérations autorisées

### Swap
- `sa` : échange les deux premiers éléments de la pile A
- `sb` : échange les deux premiers éléments de la pile B
- `ss` : `sa` et `sb` simultanément

### Push
- `pa` : pousse le premier élément de B vers A
- `pb` : pousse le premier élément de A vers B

### Rotate
- `ra` : rotation vers le haut de la pile A
- `rb` : rotation vers le haut de la pile B
- `rr` : `ra` et `rb` simultanément

### Reverse rotate
- `rra` : rotation vers le bas de la pile A
- `rrb` : rotation vers le bas de la pile B
- `rrr` : `rra` et `rrb` simultanément

---

## 🏗️ Implémentation

- Langage : **C**
- Structures de données : **listes chaînées**
- Indexation des valeurs (compression des nombres)
- Gestion stricte de la mémoire
- Respect de la **norme 42**
- Aucune fonction interdite

---

## 🧮 Algorithme de tri : Chunk / Turk Algorithm

Pour les grandes entrées (≥ 100 nombres), le programme utilise une stratégie
basée sur le **découpage en chunks**, aussi appelée **Turk Algorithm** à 42.

### 🔹 1. Indexation

Chaque valeur est remplacée par son **rang dans l’ordre trié**.
---

### 🔹 2. Découpage en chunks

La pile A est divisée en **groupes de valeurs consécutives (chunks)**.

Exemple :
- 100 nombres → ~5 chunks
- 500 nombres → ~11 chunks

Chaque chunk représente une plage d’index :

---

### 🔹 3. Transfert vers la pile B

- On parcourt la pile A
- Si l’élément appartient au chunk courant :
  - `pb` vers la pile B
  - `rb` si l’élément est dans la moitié basse du chunk
- Sinon :
  - `ra` pour continuer la recherche

Objectif :
➡️ organiser la pile B de façon quasi triée.

---

### 🔹 4. Reconstruction de la pile A

Une fois la pile A vide :

- On recherche le **plus grand index** dans la pile B
- On le remonte en tête avec :
  - `rb` ou `rrb` (selon le chemin le plus court)
- Puis `pa`

Cette étape est répétée jusqu’à ce que la pile B soit vide.

Résultat :
➡️ **Pile A entièrement triée**

---

## 📊 Optimisations

- Nombre de chunks ajusté dynamiquement
- Rotations minimales (`ra`, `rra`)
- Utilisation intelligente de `rb`
- Réduction significative du nombre d’opérations

---

## ▶️ Utilisation

### Compilation
```bash
make
# 🔢 push_swap

## ▶️ Exécution

```bash
./push_swap 4 67 3 87 23


Exemple :

