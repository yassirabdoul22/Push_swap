*This project has been created as part of the 42 curriculum by yaabdoul.*

# 🔢 push_swap

## 📌 Description

**push_swap** est un projet du **Common Core de l’école 42**.  
L’objectif est de trier une pile d’entiers en utilisant **un ensemble limité
d’opérations**, tout en générant **le nombre minimal de mouvements possible**.

Le programme reçoit une liste d’entiers en arguments et doit produire sur la sortie
standard la suite d’instructions permettant de trier la pile.

Ce projet permet de développer :
- la compréhension des **algorithmes de tri**
- la manipulation de **structures de données**
- l’optimisation des performances
- la rigueur en **langage C**
- la gestion fine de la mémoire

---

## 🧠 Principe du projet

Le tri est réalisé à l’aide de **deux piles** :

- **Pile A** : pile principale (entrée)
- **Pile B** : pile auxiliaire

Au départ, tous les nombres sont dans la pile A.  
L’objectif est d’obtenir une pile A triée par ordre croissant, en utilisant
exclusivement les opérations autorisées par le sujet.

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
- Gestion stricte de la mémoire (pas de leaks)
- Respect de la **Norme 42**
- Aucune fonction interdite

---

## 🧮 Algorithme de tri — Chunk / Turk Algorithm

Pour les entrées de grande taille (≥ 100 nombres), une stratégie basée sur le
**découpage en chunks**, aussi appelée **Turk Algorithm**, est utilisée.

### 🔹 1. Indexation

Chaque nombre est remplacé par son **index dans la version triée du tableau**.
Cela permet de simplifier les comparaisons et d’optimiser le tri.

---

### 🔹 2. Découpage en chunks

La pile A est divisée en **groupes de valeurs consécutives (chunks)**.

Exemples :
- 100 nombres → ~5 chunks
- 500 nombres → ~11 chunks

Chaque chunk correspond à une plage d’index précise.

---

### 🔹 3. Transfert vers la pile B

- Parcours de la pile A
- Si l’élément appartient au chunk courant :
  - `pb` vers la pile B
  - `rb` si l’élément est dans la moitié basse du chunk
- Sinon :
  - `ra` pour continuer la recherche

Objectif :
➡️ organiser la pile B de manière presque triée.

---

### 🔹 4. Reconstruction de la pile A

Une fois la pile A vide :
- Recherche du **plus grand index** dans la pile B
- Rotation optimale (`rb` ou `rrb`)
- `pa` pour le remettre dans la pile A

Cette étape est répétée jusqu’à ce que la pile B soit vide.

➡️ Résultat : **pile A entièrement triée**

---

## 📊 Optimisations

- Nombre de chunks ajusté dynamiquement
- Choix intelligent entre rotations (`ra` / `rra`)
- Utilisation optimisée de `rb`
- Réduction significative du nombre total d’opérations

---

## ▶️ Instructions

### Compilation
```bash
make
