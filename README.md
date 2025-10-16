# Algoritmo K-means em C

Implementação do algoritmo de clusterização não-supervisionado K-means em linguagem C. Este projeto foi desenvolvido com foco em eficiência e clareza, oferecendo uma solução robusta para segmentação de dados.

## 📖 Sobre o Projeto

O K-means é um dos algoritmos de aprendizado de máquina não-supervisionado mais populares. Seu objetivo é particionar um conjunto de `n` observações em `k` clusters, onde cada observação pertence ao cluster com a média (centroide) mais próxima. O algoritmo busca minimizar a variância dentro de cada cluster, agrupando dados com base em suas similaridades.

Este projeto oferece uma implementação a partir do zero, ideal para fins de estudo e para aplicações que requerem uma solução de clusterização leve e portável.

## ✨ Funcionalidades

* **Implementado em C puro:** Garante alta performance e portabilidade entre diferentes sistemas operacionais.
* **Métrica de Distância Euclidiana:** Utiliza a distância euclidiana para medir a similaridade entre os pontos e os centroides.
* **Saída Organizada:** Saída contendo cada ponto de dado e o ID do cluster ao qual ele foi atribuído.

## 🛠️ Pré-requisitos

Para compilar e executar este projeto, você precisará de:

* Um compilador C (recomenda-se **GCC**).
* **Git** para clonar o repositório.
* **Make** para facilitar o processo de compilação.

## 🚀 Instalação e Compilação

Siga os passos abaixo para obter uma cópia local e compilar o projeto.

1.  **Clone o repositório:**
    ```sh
    git clone [https://github.com/usuario/repositorio.git](https://github.com/usuario/repositorio.git)
    ```

2.  **Navegue até o diretório do projeto:**
    ```sh
    cd repositorio
    ```

3.  **Compile o código-fonte:**
      **Usando Make:**
        Se houver um `Makefile` no projeto, basta executar:
        ```sh
        make
        ```

## 💻 Como Usar

Após a compilação, você pode executar o programa a partir do terminal. A sintaxe básica de uso é:

```sh
./kmeans <coordenadas do primeiro ponto>
```

Em seguida, aparecerá para você colocar o segundo ponto e assim continuará até o máximo definido no código.

**Exemplo:**

```sh
./kmeans 3.3 4
```

### Formato do Arquivo de Entrada

O arquivo de dados de entrada deve ser números pertencentes ao conjunto dos reais menos irracionais, onde:
* Cada linha representa um ponto de dado.
* Cada coluna representa uma dimensão/feature do ponto.
* Os valores devem ser separados por espaço.

**Exemplo:**
```
1.2 3.4
1.5 3.8
5.0 8.1
8.5 7.5
9.1 7.9
```

## 🎯 Melhorias Futuras (Roadmap)

* [ ] **Implementar K-means++:** Substituir a inicialização aleatória dos centroides pelo algoritmo K-means++ para obter melhores resultados e convergência mais rápida.
* [ ] **Determinação do `k` ideal:** Incluir métodos para ajudar a determinar o número ótimo de clusters, como o "Método do Cotovelo" (Elbow Method).
* [ ] **Otimização de performance:** Analisar e otimizar os laços principais do algoritmo para lidar com datasets maiores.
