from pathlib import Path

def line(n):
    print("-" * n)

print("""# CSES Problem Set

¡Hola! Este es mi repositorio personal para resolver los problemas del [CSES Problem Set].

Acá voy registrando mi progreso y soluciones en C++, organizadas por categoría.

## Progreso

<!-- Este contenido es generado automáticamente por counter.py -->
""")


line(60)
print("### Problems for category:")
line(60)

counter = 0

for folder in Path(".").iterdir():

    if not folder.is_dir():
        continue

    if folder.name.startswith(("0", ".")):
        continue

    problems = len(list(folder.iterdir()))

    print(f"\t- {folder.name.replace('_', ' '):<25} {problems:>22}")

    counter += problems

line(60)
print("### Total:", counter)