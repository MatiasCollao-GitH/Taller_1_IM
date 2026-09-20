# Taller 01: Estructura de Datos – Hospital Marmaja

Sistema en C++ para la administración del flujo hospitalario de pacientes mediante estructuras lineales enlazadas manuales (sin uso de la librería estándar STL), programación orientada a objetos (POO), aritmética de punteros y gestión dinámica de memoria en el Heap.

---

## Integrantes
* **Nombre:** Matías Collao | **RUT:** 22.060.152-8 | **Usuario GitHub:** MatiasCollao-GitH (https://github.com/MatiasCollao-GitH) | **Carrera:** Ingeniería Civil en Computación e Informática
* **Nombre:** Ignacio Pastén | **RUT:** 22.067.577-7 | **Usuario GitHub:** Tallarin51 (https://github.com/Tallarin51) | **Carrera:** Ingeniería Civil en Computación e Informática

---

## Estructuras de Datos y Decisiones Técnicas

El proyecto prescinde estrictamente de contenedores de la STL (`std::vector`, `std::list`, `std::queue`, `std::stack`). Todas las estructuras lineales fueron implementadas desde cero mediante clases nodales enlazadas y memoria dinámica:

1. **Cola de Espera (`Cola<T>` - FIFO):**
   * Gestiona el orden de llegada de los pacientes leídos desde `Pacientes.txt`.
   * Implementa las operaciones clásicas de encolar al final (`push`) y desencolar desde el frente (`pop`), garantizando la disciplina First-In, First-Out.

2. **Lista Enlazada Multinivel (`Lista<T>`):**
   * **Nivel Principal:** Lista enlazada simple que alberga los 8 departamentos fijos del hospital (`Urgencias`, `Medicina General`, `Cardiología`, `Neurología`, `Traumatología`, `Cirugía`, `Pediatría`, `Hospitalización`).
   * **Sublistas por Departamento:** Cada objeto `Servicio` administra su propia instancia de `Lista<Paciente*>`, almacenando a los pacientes derivados a dicha especialidad luego de ser atendidos.

3. **Historial de Atenciones (`Stack<T>` - LIFO):**
   * Pila enlazada manual donde se registra cada evento de atención médica completado.
   * Permite consultar en orden inverso (desde la atención más reciente a la más antigua) el historial hospitalario.

4. **Programación Orientada a Objetos (POO):**
   * Jerarquía de herencia con clase base `Persona` (atributos protegidos `nombre`, `edad` y método polimórfico virtual `datos()`).
   * Clase derivada `Paciente` que extiende la información con identificador único (`id`) y el departamento requerido (`servicio`).

5. **Aritmética de Punteros:**
   * Utilizada de manera funcional en el método `Sistema::inicializarServicios()`, empleando un puntero `const std::string*` que se desplaza en memoria continua para inicializar los 8 departamentos sin usar indexación tradicional de corchetes (`[]`).

---

## Estructura del Repositorio

```text
.
├── CMakeLists.txt
├── README.md
├── Pacientes.txt
├── main.cpp
├── logica/
│   ├── Sistema.h
│   ├── Sistema.cpp
└── dominio/
│   ├── Persona.h
│   ├── Persona.cpp
│   ├── Paciente.h
│   ├── Paciente.cpp
│   ├── Servicio.h
│   ├── Servicio.cpp
│   ├── Historial.h
│   └── Historial.cpp
└── estructuras/
    ├── Nodo.h
    ├── Nodo.cpp
    ├── Lista.h
    ├── Cola.h
    ├── Cola.cpp
    └── Stack.h
```

---

## Requisitos del Entorno

* Compilador de C++ con soporte para **C++17** o superior (`g++`, `clang++` o MSVC).
* **CMake** versión 3.20 o superior.
* Compatible con Linux (Ubuntu / GitHub Codespaces), macOS y Windows (MinGW / MSVC).

---

## Instrucciones de Compilación y Ejecución

> **Importante:** El archivo `Pacientes.txt` debe ubicarse en el mismo directorio donde se ejecute el binario compilado para permitir su lectura.

### Opción 1: Compilación manual con G++ (Recomendada para GitHub Codespaces / Terminal Linux)

1. Abrir una terminal en el directorio raíz del proyecto.
2. Compilar todos los archivos fuente con soporte de C++17:
   ```bash
   g++ -std=c++17 -Wall main.cpp logica/Sistema.cpp dominio/Persona.cpp dominio/Paciente.cpp dominio/Servicio.cpp dominio/Historial.cpp -o hospital
   ```
3. Ejecutar el binario generado:
   * En Linux, macOS o GitHub Codespaces:
     ```bash
     ./hospital
     ```
   * En Windows (CMD o PowerShell):
     ```cmd
     hospital.exe
     ```

---

### Opción 2: Compilación y Ejecución mediante CMake

1. Crear la carpeta de compilación temporal y posicionarse en ella:
   ```bash
   mkdir build
   cd build
   ```
2. Generar los archivos de construcción y compilar:
   ```bash
   cmake ..
   cmake --build .
   ```
3. Copiar el archivo de datos al directorio de ejecución:
   * En Linux / macOS / Codespaces:
     ```bash
     cp ../Pacientes.txt .
     ./Taller_1_IM
     ```
   * En Windows:
     ```cmd
     copy ..\Pacientes.txt .
     Taller_1_IM.exe
     ```

---

## Manejo de Casos Borde y Validaciones

* **Control de Archivo:** Validación previa de apertura de `Pacientes.txt`; si no existe o la ruta es inválida, se emite un mensaje descriptivo y se evita la caída del sistema.
* **Formato de Líneas y Tipos:** Descarte de registros incompletos o con edades no numéricas mediante control de excepciones (`std::invalid_argument`).
* **Servicios Inválidos:** Verificación frente a los 8 departamentos permitidos; si el servicio solicitado no pertenece al catálogo hospitalario, la línea se rechaza.
* **Pacientes Duplicados:** Validación de identificador único (`id`); si un paciente ya está en cola, el duplicado es descartado.
* **Robustez en Entrada de Usuario:** Limpieza defensiva del buffer de entrada (`cin.clear()` y `cin.ignore()`) en la navegación de menús para evitar bucles infinitos ante ingresos de caracteres alfanuméricos no esperados.
* **Estructuras Vacías:** Comprobación previa de tamaño antes de ejecutar operaciones de desencolado, desapilado o listado de pacientes en departamentos sin derivaciones.
* **Liberación de Memoria:** Destructores recursivos en cada estructura dinámica (`Cola`, `Lista`, `Stack` y `Servicio`), asegurando que todos los nodos e instancias de `Paciente` creados con `new` sean liberados con `delete` al cerrar la aplicación, previniendo fugas de memoria (*memory leaks*).
