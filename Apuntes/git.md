# Guía Actualización de Repositorio

## Primer Uso del Repositorio

Inicialización de Git:

```bash
Git init
```

Verificamos el estado del repositorio local y si existe algún cambio este lo mostrará:

```bash
git status
```

Agregamos todos los archivos que se subirán:

```bash
git add.
```

En caso de que se quisiera solo agregar un archivo o archivo modificado se hace lo siguiente:

```bash
git add <Nombre_archivo>
```

Creación de commit:

```bash
git commit -m "Texto para el commit"
```

Conexión o vinculo con repositorio remoto:

```bash
git remote add origin https://github.com/XXXXX/XXXXX.git
```

Actualización del repositorio en rama master, sin embargo puede ser creada alguna subrama:
```bash
git push -u origin master
```

## Actualización del Repositorio

Creación de commit para marcar cambio:

```bash
git commit -m "Texto para el commit"
```

Actualización repositorio local:

```bash
git fetch origin
```

Aplicar Cambios encima de lo existente:
```bash
git rebase origin/master
```

Agregamos todos los archivos que se subirán:

```bash
git add.
```

Actualización del repositorio en rama master, sin embargo puede ser creada alguna subrama:
```bash
git push -u origin master
```