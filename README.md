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
| `<hash>`        | sha256 |      |

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

### Repository

#### Structure

| folder                                   | notes |
|------------------------------------------|-------|
| `/`                                      |       |
| `/<platform>/`                           |       |
| `/<platform>/<package>/`                 |       |
| `/<platform>/<package>/<version>/`       |       |
| `/<platform>/<package>/<version>.tar.gz` |       |

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
platform: <platform>
package: <package>
version: <version>
license: <license>
description: <description>
url: <url>
depends:
- <package>
- <package>
- <package>
files:
    install:
    - <file>
    - <file>
    - <file>
    support:
    - <file>
    - <file>
    - <file>
    hashes:
    - <hash>
    - <hash>
    - <hash>
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

### Repository

#### `tool-repo`

### Cache

#### `tool-cache`

### Local

#### `tool-local`
