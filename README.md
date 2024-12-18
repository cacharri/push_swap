# Push Swap

El proyecto **Push Swap** forma parte del currículo de 42 y está diseñado para desafiar tus habilidades en algoritmos, estructuras de datos y optimización. El objetivo principal es ordenar un conjunto de números en un stack utilizando un conjunto limitado de operaciones.

---

## 🚀 Descripción del Proyecto

El proyecto consiste en implementar un programa que ordena un stack de enteros con la menor cantidad posible de operaciones. El programa debe ser eficiente y cumplir con las reglas específicas del proyecto.

---

## 🔧 Requisitos

### Entrada
- Una lista de números enteros pasados como argumentos al programa.

### Salida
- Una secuencia de operaciones que transformen el stack inicial en un stack ordenado de forma ascendente.

### Operaciones permitidas
- **sa**: Intercambia los dos primeros elementos de `stack A`.
- **sb**: Intercambia los dos primeros elementos de `stack B`.
- **ss**: Ejecuta `sa` y `sb` simultáneamente.
- **pa**: Pasa el primer elemento de `stack B` a `stack A`.
- **pb**: Pasa el primer elemento de `stack A` a `stack B`.
- **ra**: Rota todos los elementos de `stack A` hacia arriba.
- **rb**: Rota todos los elementos de `stack B` hacia arriba.
- **rr**: Ejecuta `ra` y `rb` simultáneamente.
- **rra**: Rota todos los elementos de `stack A` hacia abajo.
- **rrb**: Rota todos los elementos de `stack B` hacia abajo.
- **rrr**: Ejecuta `rra` y `rrb` simultáneamente.

---

## 📁 Estructura del Proyecto

```plaintext
push_swap/
├── srcs/           # Código fuente principal
├── includes/       # Archivos de cabecera
├── Makefile        # Sistema de compilación
└── README.md       # Documentación
```

---

## 🛠️ Uso

1. Clona el repositorio:
   ```bash
   git clone https://github.com/cacharri/push_swap.git
   cd push_swap
   ```

2. Compila el proyecto:
   ```bash
   make
   ```

3. Ejecuta el programa con una lista de números:
   ```bash
   ./push_swap 2 1 3 6 5 8
   ```

4. Para verificar la salida:
   - Utiliza el programa `checker` proporcionado por el proyecto.
   ```bash
   ./push_swap 2 1 3 6 5 8 | ./checker 2 1 3 6 5 8
   ```

---

## 🌟 Características

- Implementación eficiente para stacks pequeños (3-5 elementos).
- Uso de algoritmos avanzados para stacks más grandes.
- Optimización del número de operaciones.

---

## 🧪 Testing

Incluye un script para generar y probar permutaciones aleatorias:

```bash
ARG=$(seq 1 100 | shuf | tr '\n' ' ')
./push_swap $ARG | ./checker $ARG
```

---

## 📜 Licencia

Este proyecto forma parte del currículo de 42 y está destinado exclusivamente a fines educativos.

---



