# Agile for Package Manager

- the `tool` client will be developed in both haskell and cpp
- will be converted into LaTex because i already have a suitable workflow, but for now will be on Markdown

## Formats

### Types

| name            | type   | node |
|-----------------|--------|------|
| `<platform>`    | string |      |
| `<package>`     | string |      |
| `<license>`     | spdx   |      |
| `<file>`        | string |      |
| `<software>`    | string |      |
| `<command>`     | string |      |
| `<url>`         | string |      |
| `<description>` | string |      |

### Source

#### Structure

| folder                             | notes |
|------------------------------------|-------|
| `/`                                |       |
| `/<platform>/`                     |       |
| `/<platform>/<package>/`           |       |
| `/<platform>/<package>/<version>/` |       |

#### Config Files

| index file                                  | notes |
|---------------------------------------------|-------|
| `/index.yml`                                |       |
| `/<platform>/index.yml`                     |       |
| `/<platform>/<package>/index.yml`           |       |
| `/<platform>/<package>/<version>/index.yml` |       |

##### `/index.yml`

```yaml
platforms:
- <platform>
- <platform>
- <platform>
```

##### `/<platform>/index.yml`

```yaml
packages:
- <package>
- <package>
- <package>
```

##### `/<platform>/<package>/index.yml`

```yaml
license: <license>
description: <description>
url: <url>
depends:
- <package>
- <package>
- <package>
versions:
- <version>
- <version>
- <version>
```

##### `/<platform>/<package>/<version>/index.yml`

```yaml
files:
    install:
    - <file>
    - <file>
    - <file>
    support:
    - <file>
    - <file>
    - <file>
softwares:
- <software>
- <software>
- <software>
install:
- <command>
- <command>
- <command>
uninstall:
- <command>
- <command>
- <command>
```

## Command Line

| alias        | extended     | description |
|--------------|--------------|-------------|
| `tool-src`   | `tool src`   |             |
| `tool-repo`  | `tool repo`  |             |
| `tool-cache` | `tool cache` |             |
| `tool-local` | `tool local` |             |

### Source

#### `tool-src`

##### actions

###### root

| command                                                               | description                                                                                  |
|-----------------------------------------------------------------------|----------------------------------------------------------------------------------------------|
| `tool-src init`                                                       | create a new empty source folder, if path is not supplied it's created in the current folder |
| `tool-src check`                                                      | run quick check on consistency on whole source folder                                        |
| `tool-src list [platform]`                                            | list platforms in source folder, and eventually filter by name                               |
| `tool-src add <platform>`                                             | add a new platform                                                                           |
| `tool-src del <platform>`                                             | delete a platform                                                                            |
| `tool-src rename <platform>`                                          | rename a platform                                                                            |
| `tool-src dist <repository-uri> [<platform> [<package> [<version>]]]` | build, setup or update existing repository on the same machine                               |

###### platform

| command                                         | description                                                           |
|-------------------------------------------------|-----------------------------------------------------------------------|
| `tool-src <platform> check`                     | run quick check on consistency of a single platform                   |
| `tool-src <platform> list [package]`            | list packages, and eventually filter by name                          |
| `tool-src <platform> add <package> [<license>]` | add a new package, if license is not supplied it's defaulted with GPL |
| `tool-src <platform> del <package>`             | delete a package                                                      |
| `tool-src <platform> rename <package>`          | rename a package                                                      |

###### package

| command                                           | description                                        |
|---------------------------------------------------|----------------------------------------------------|
| `tool-src <platform> <package> check`             | run quick check on consistency of a single package |
| `tool-src <platform> <package> license <license>` | change license of a package                        |
| `tool-src <platform> <package> versions`          | list versions of a package                         |
| `tool-src <platform> <package> add <version>`     | add a version of a package                         |
| `tool-src <platform> <package> del <version>`     | delete a version of a package                      |
| `tool-src <platform> <package> rename <version>`  | rename a version of a package                      |

###### version

| command                                         | description                                        |
|-------------------------------------------------|----------------------------------------------------|
| `tool-src <platform> <package> <version> check` | run quick check on consistency of a single version |
|                                                 |                                                    |

##### options

| option | description                  |
| ------ | ---------------------------- |
| `-p`   | supply path of source folder |

### Repository

#### `tool-repo`

### Cache

#### `tool-cache`

### Local

#### `tool-local`
