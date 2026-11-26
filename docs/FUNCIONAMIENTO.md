# Funcionamiento de Proyecto-STL2-2022A

Mapa inicial para Zabdi. Observado el 26 de noviembre de 2026 sobre el código
[4474b19930f1aa504ba952614028ecaa43b2d8af](https://github.com/ZabdielSalazar/Proyecto-STL2-2022A/commit/4474b19930f1aa504ba952614028ecaa43b2d8af), rama principal main.
Esta es una revisión estática de entradas y contratos; no acredita compilación ni ejecución.

| Proceso | Activador → resultado | Ficha |
| --- | --- | --- |
| Análisis léxico | Entrada de consola terminada en # → categorías en compilador.txt | [Compilación](funcionamiento/compilacion.md) |
| Comprobaciones sintácticas y semánticas | Lectura del archivo de categorías → diagnósticos de consola | [Compilación](funcionamiento/compilacion.md) |

## Versiones y alcance

- La entrada integrada de la raíz es main.cpp → tokens.cpp → comprobaciones.cpp.
  El nombre «Proyecto STL2.cpp» mencionado por el README no existe en este árbol.
- Hay programas separados en Analizador Léxico, Analizador Sintactico,
  Analizador Semantico y Mini analizador sintáctico. Son antecedentes/variantes;
  no hay un sistema de build que seleccione automáticamente entre ellos.
- La rama analizadorLexico apunta a 039faddcd29e61fcd1f4e5a06ea82ddbab841a39.
  El [PR 1](https://github.com/ZabdielSalazar/Proyecto-STL2-2022A/pull/1) sigue abierto:
  no se considera integrado.
- No se encontró configuración de despliegue ni CI en main. El ejecutable
  versionado no aporta una correspondencia verificable con este SHA.

## Checkpoint documental

Al continuar, comparar el SHA anterior con main y listar nombres cambiados.
Releer únicamente la entrada, scanner o consumidor afectados. No ejecutar el .exe
para verificar documentación. Cambiar esta fecha sin un cambio útil no requiere commit.
