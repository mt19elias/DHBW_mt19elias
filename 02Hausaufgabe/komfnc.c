#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
double rea;
double ima;
}number;


number add(number num1, number num2){
    number res= {0, 0};
    res.rea=num1.rea + num2.rea;
    res.ima=num1.ima + num2.ima;
    return res;
}

number sub(number num1, number num2){
    number res= {0, 0};
    res.rea=num1.rea - num2.rea;
    res.ima=num1.ima - num2.ima;
    return res;
}

number mul(number num1, number num2){
    number res= {0, 0};
    res.rea=num1.rea * num2.rea - num1.ima * num2.ima;
    res.ima=num1.rea * num2.ima + num1.ima * num2.rea;
    return res;
}

number divi(number num1, number num2){
    number res= {0, 0};
    res.rea= (num1.rea * num2.rea - num1.ima * -num2.ima) / (num2.rea * num2.rea + num2.ima * num2.ima);
    res.ima= (num1.rea * -num2.ima + num1.ima * num2.rea) / (num2.rea * num2.rea + num2.ima * num2.ima);
    return res;
}
