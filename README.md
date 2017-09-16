# Robótica Industrial

Utilização de controle PID na robótica

    Sistemas dinâmicos podem ser de forma generalizada vista como abstrações que descrevem algo que muda ao longo do tempo. Um veículo se 
 movendo e etc. Esses sistemas dinâmicos podem ser controlados, para isso é necessário primeiramente uma forma de descrever o que o 
 sistema está fazendo ou atuando, como é o seu comportamento ao longo do tempo. Entre as formas de controle de sistemas que existe temos, 
 o controle proporcional-integrativo-derivativo (PID), que é composto por três variáveis: Kp; Ki; Kd; que são respectivamente ganho 
 proporcional, ganho integral, e o ganho derivativo, estes coeficientes são empregados para a obtenção de um resultado mais satisfatório. 
 Controle PID podem ser empregados em sistemas de malha fechada, ou seja, sistemas com realimentação que são sistemas onde a partir de uma 
 comparação entre o estado esperado na saída com o seu estado real, o controlador recebe os dados e atua de forma a fazer com que a saída 
 seja alterada para o seu valor esperado, no melhor caso, ou o mais próximo possível.
    O projeto que está sendo desenvolvido na Disciplina de Robótica Industrial é um Robô seguidor de linha têm como um dos objetivos 
 mostrar o controle PID e evidenciar algumas das vantagens de sua utilização na robótica.


Métodos

    Para a realização deste projeto foi realizada a montagem de um Robô seguidor de linha, e após a montagem física dos componentes foram
 desenvolvidos os códigos de programação e realizados alguns testes em um circuito para que o Robô tente completar todo o circuito 
 seguindo a linha com uma determinada velocidade, controlando a aceleração e frenagem.

Resultados

    As principais necessidades de um sistema de controle estão: estabilidade, alcançar o objetivo e robustez. No controle PID, o 
 coeficiente proporcional contribuí para a estabilidade do sistema, o coeficiente integral contribui com para a rejeição de distúrbios, 
 mas têm uma taxa lenta de resposta, o que pode causar oscilações.
    Enquanto que o componente derivativo contribui com respostas mais rápidas aos distúrbios. Um fato curioso é o de que a estabilidade 
 não é garantida para todos os casos. Vale a pena salientar que a complexidade do controlador na grande maioria dos casos depende da 
 complexidade do modelo usado, no entanto é possível a obtenção de modelos simples que comportem as funcionalidades básicas de um sistema, 
 facilitando sua implementação, sem que existam grandes perdas de eficiência. O uso de controles PID e uma correta modelagem do sistema é 
 possível mesmo com poucos recursos que sistemas relativamente complexos sejam representados e controlados com o uso de controladores PID 
 sendo possível obter um bom sistema com estabilidade e robustez alcançando assim o objetivo principal do projeto até aqui desenvolvido.


