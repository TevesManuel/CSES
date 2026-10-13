import argparse
from pathlib import Path
import re

# Diccionario de casteo para nombres de lenguajes
LANGUAGE_NAMES = {
    "cpp": "C++",
    "c++": "C++",
    "rust": "Rust",
    "rs": "Rust",
    "py": "Python",
    "python": "Python",
    "go": "Go",
    "golang": "Go",
    "java": "Java",
    "c": "C",
    "cs": "C#",
    "csharp": "C#",
    "js": "JavaScript",
    "javascript": "JavaScript",
    "ts": "TypeScript",
    "typescript": "TypeScript",
}


def line(n: int = 60) -> str:
    return "-" * n


def get_language_display_name(folder_name: str) -> str:
    return LANGUAGE_NAMES.get(folder_name.lower(), folder_name.capitalize())


def get_language_sort_key(folder: Path):
    keys = list(LANGUAGE_NAMES.keys())
    lower = folder.name.lower()
    if lower in keys:
        return (0, keys.index(lower))
    return (1, lower)


def format_languages_list(languages: list[str]) -> str:
    if not languages:
        return ""
    if len(languages) == 1:
        return languages[0]
    return f"{', '.join(languages[:-1])} y {languages[-1]}"


def category_sort_key(folder: Path):
    match = re.match(r"^(\d+)", folder.name)
    if match:
        return (int(match.group(1)), folder.name)
    return (999, folder.name)


def format_category_name(folder_name: str) -> str:
    cleaned = re.sub(r"^\d+_", "", folder_name)
    return cleaned.replace("_", " ")


def count_problems_in_category(category_folder: Path) -> int:
    return sum(
        1
        for item in category_folder.iterdir()
        if item.is_dir() and not item.name.startswith((".", "_"))
    )


def is_language_folder(folder: Path) -> bool:
    if not folder.is_dir() or folder.name.startswith((".", "_")):
        return False

    # Verifica si contiene al menos una carpeta de categorías válida
    for item in folder.iterdir():
        if item.is_dir() and not item.name.startswith(("0", ".")):
            return True
    return False


def generate_markdown(root: Path) -> tuple[str, int]:
    # Detectar carpetas de lenguajes ordenadas
    language_folders = [
        f for f in root.iterdir() if is_language_folder(f)
    ]
    language_folders.sort(key=get_language_sort_key)

    languages_display = [
        get_language_display_name(f.name) for f in language_folders
    ]
    lang_str = format_languages_list(languages_display)

    lines = [
        "# CSES Problem Set",
        "",
        "¡Hola! Este es mi repositorio personal para resolver los problemas del [CSES Problem Set](https://cses.fi/problemset/).",
        "",
        f"Acá voy registrando mi progreso y soluciones en {lang_str}, organizadas por categoría.",
        "",
        "### Progreso",
    ]

    total_global = 0

    for folder in language_folders:
        lang_name = get_language_display_name(folder.name)
        categories = [
            c
            for c in folder.iterdir()
            if c.is_dir() and not c.name.startswith(("0", "."))
        ]
        categories.sort(key=category_sort_key)

        lines.append(line(60))
        lines.append(f"### {lang_name}")
        lines.append(line(60))
        lines.append("| Categoría | Problemas |")
        lines.append("|:----------|----------:|")

        lang_total = 0
        for cat in categories:
            problems = count_problems_in_category(cat)
            lang_total += problems
            cat_name = format_category_name(cat.name)
            lines.append(f"| {cat_name} | {problems} |")

        lines.append(line(60))
        lines.append(f"### Total {lang_name}: {lang_total}")
        lines.append("")

        total_global += lang_total

    lines.append(line(60))
    lines.append(f"### Total Global: {total_global}")
    lines.append("")

    return "\n".join(lines), total_global


def main():
    parser = argparse.ArgumentParser(
        description="Genera el reporte de progreso de problemas CSES resueltos por lenguaje."
    )
    parser.add_argument(
        "-w",
        "--write",
        action="store_true",
        help="Escribe el resultado directamente en README.md en lugar de stdout.",
    )
    args = parser.parse_args()

    root = Path(__file__).resolve().parent
    content, total = generate_markdown(root)

    if args.write:
        readme_path = root / "README.md"
        readme_path.write_text(content, encoding="utf-8")
        print(f"README.md actualizado exitosamente (Total: {total} problemas).")
    else:
        print(content)


if __name__ == "__main__":
    main()