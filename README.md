<h1 align="center">
	<br />
    	<img src="docs/assets/gibbon.png" alt="gibbon-img" />
  	<br />
  		<p>Gibbon Language</p>
  	<br />
</h1>

<h4 align="center">Yet another programming language for all ape species</h4>

## Motivation
Syntatic sugar for cpp, a package manager, project structures, memory safety, builtin memory test.
In hope to help all apes out there. Ape together strong!

## Features
- **Syntatic Syntax**: Write C++ with the familiarity of TypeScript's syntax.
- **Package Manager**: Make life easier with package manager, maybe similary to npm or pip.
- **Project Structure**: A standarize project structure. Ape hate linking.
- **Memory Safety**: Borrowing how rust implement memory safety.
- **Unit Test**: A built in unit test.

## Development


### Pre-requisites
To be able to start development on Amplication, make sure that you have the following.
- Git
- Docker

### Running
```sh
docker build -t gibbon-container -f docker/gibbon-container .
```

```sh
docker run --rm -it -v ./src:/gibbon gibbon-container /bin/bash
```