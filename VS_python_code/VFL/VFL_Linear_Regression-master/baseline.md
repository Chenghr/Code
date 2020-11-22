## Sklearn linear regression on diabetes dataset [code](./test/plain_regression.py)
### W 
``` 
[ 3.03499549e-01 -2.37639315e+02  5.10530605e+02  3.27736980e+02
 -8.14131709e+02  4.92814588e+02  1.02848452e+02  1.84606489e+02
  7.43519617e+02  7.60951722e+01]
```
### testing MSE error
```
2004.5676026898207
```
### testing r2 score
```
0.5850753022690575
```

## Manually implemented linear regression without L2 regularization and PHE [code](./test/linreg.py)
### W
```
[   3.66157035 -234.66444184  519.394868    325.58162657 -176.1260995
  -16.42297065 -180.05365129  108.05924825  502.79199745   78.9700069 ]
```
### testing MSE error
```
1993.53
```
### testing r2 score
```
0.5873601124796597
```

## out implementation with L2 regularization and Paillier HE

### W
```
[ 37.53897738 -31.42766103 201.96561441 141.67894383  25.41910473 
5.26300892 -113.99436921  103.48282523  178.71961336  100.08677604]
```
### training MSE error

```
4385.224210773564
```

### testing MSE error 
```
3217.8873933925765
```

### r2 score
```
0.33393069296140554
```