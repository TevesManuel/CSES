from pathlib import Path

def line(n):
    print("-" * n)

print("""# CSES Problem Set

¡Hola! Este es mi repositorio personal para resolver los problemas del [CSES Problem Set](https://cses.fi/problemset/).

Acá voy registrando mi progreso y soluciones en C++, organizadas por categoría.

## Progreso
""")


line(60)
print("### Problemas por categoría:")
line(60)

print("| Categoría | Problemas |")
print("|:----------|----------:|")

counter = 0

for folder in Path(".").iterdir():

    if not folder.is_dir():
        continue

    if folder.name.startswith(("0", ".")):
        continue

    problems = len(list(folder.iterdir()))
    counter += problems

    name = folder.name[2:].replace("_", " ")

    print(f"| {name} | {problems} |")

line(60)
print("### Total:", counter)