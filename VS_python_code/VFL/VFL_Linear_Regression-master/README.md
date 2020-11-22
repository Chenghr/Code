## Introduction
This is a simple implementation on **Vertical Federated Linear Regression** model. The algorithm can be find [here](https://www.oreilly.com/library/view/federated-learning/9781681737188/), and we use the [scikit-learn](https://scikit-learn.org/) build-in dataset [diabetes](https://scikit-learn.org/stable/modules/generated/sklearn.datasets.load_diabetes.html) to test our implementation.

## Usage
``` shell
1. python3 aggregator.py
2. python3 client_b.py
3. python3 client_a.py
```
You can change the training parameters (such as *learning rate*, *training epochs*, etc.) in both `client_a.py` and `client_b.py`.

## TODO
- [ ] merge all configurations into a `config.py`, allow command line parameters using `args parser`.
- [ ] improve computation efficiency of Paillier encryption on float numbers as suggested by official documentation.
   
