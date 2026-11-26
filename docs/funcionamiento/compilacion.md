# Consola, tokens y comprobaciones

Propósito: analizar un subconjunto de un lenguaje tipo C. No genera ejecutables.
Entrada integrada: [main.cpp](../../main.cpp), que llama a Lexico() y luego lee
compilador.txt. Alcance y SHA: [índice](../FUNCIONAMIENTO.md).

## Contratos locales

No hay HTTP, autenticación, proveedor de IA ni procesos remotos.

| Quién → quién | Requisitos y entrada exacta | Salida y errores |
| --- | --- | --- |
| Usuario → Lexico() en tokens.cpp | Consola disponible y carpeta de trabajo escribible. Caracteres hasta el primer #, obligatorio como terminador; no hay parámetros opcionales | Categorías impresas y archivo compilador.txt reescrito con modo wt. Carácter no reconocido: texto input error y categoría error |
| scaner() en comprobaciones.cpp → Lexico() | Variables globales input, p, token, fg y num. fg=8 identificador; 9 entero; 5/6/7 tipo; 99 fin | Lexico transforma las marcas internas en etiquetas; los números fg no son los códigos del README |
| Lexico() → main() | Archivo de texto en el directorio de ejecución. Etiquetas separadas por el carácter barra vertical; no es JSON ni una tabla de lexemas | main acumula una etiqueta hasta el separador, compara estado/token anterior y muestra diagnósticos. Sin esquema de códigos de salida por error |

Etiquetas emitidas por tokens.cpp: identificador, entero, tipo, opSuma, opMul,
opRelac, opOr, opAnd, opNot, opIgualdad, signos ; , ( ) { } =,
palabras if/while/return/else, $ y punto. La marca # termina el scanner y no
se guarda como token de entrada del comprobador.

## Reglas que cambian el resultado

- El scanner omite espacios y reconoce letras ASCII con dígitos posteriores.
  Las palabras int, float y void se convierten a la misma categoría tipo.
- Se pierden los nombres concretos de identificadores en el archivo intermedio:
  una etiqueta identificador no demuestra que exista una tabla de símbolos completa.
- Las comprobaciones usan tokenPosicion, tokenAnterior y tokenCondicion para
  declaraciones, if, while y else. Un mensaje de éxito parcial no prueba la
  validez de todo un programa.
- El README enumera real y cadena; tokens.cpp no tiene emisión específica de
  esas dos categorías. No asumir cobertura del lenguaje solo por esa lista.
- Las variantes en subcarpetas tienen su propio main y scanner: no mezclar sus
  números internos o sus archivos compilador.txt con la entrada integrada.

## Límites propios y estado operativo

input[200] y token[20] son tamaños de buffers, **no límites validados**:
la captura hasta # y la acumulación de token no comprueban capacidad antes de escribir.
El consumidor usa limiteLectura < 200; no es una garantía de procesar 200 tokens.
No se observan controles robustos de EOF ni de apertura de fichero.
No hay timeout, cancelación de aplicación, reintentos, idempotencia, limpieza
automática ni aislamiento entre ejecuciones simultáneas: comparten el mismo nombre
compilador.txt. Cada llamada léxica sobrescribe el resultado anterior.

Tokens de modelos, RPM/TPM/RPD, cuotas de plataforma y fallback no aplican.
No hay consumo medido ni llamadas a proveedores. Se conserva el archivo local
hasta sobrescribirlo o borrarlo manualmente; stdout contiene los diagnósticos.
No poner en ejemplos código privado del usuario.

## Diagnóstico por frontera

| Síntoma | Primer archivo y comprobación |
| --- | --- |
| No acaba de pedir código | tokens.cpp, Lexico(): verificar que se recibió #; no hay plazo automático |
| Archivo ausente o resultado de otra ejecución | main.cpp y tokens.cpp: directorio de trabajo, apertura de compilador.txt y ejecución concurrente |
| Categoría inesperada | comprobaciones.cpp, scaner(), y tabla de transformación en Lexico(); separar marca fg de código visible |
| Error de sintaxis tras léxico correcto | main.cpp: etiqueta realmente emitida, tokenPosicion y tokenAnterior |
| Compila otra versión o difiere el .exe | Selección del main de la raíz frente a los main de subcarpetas; no hay build canónico comprobado |

Evidencia: inspección de las tres unidades de la raíz y de las entradas sintáctica
y semántica históricas. No se compiló, ejecutó ni probó el binario.
Siguiente paso pequeño: acordar cuál entrada es la referencia antes de proponer
pruebas o correcciones funcionales en un encargo distinto.
