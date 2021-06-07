package arquitectura_robot

class Robot {
    val motor0: Motor = Motor(4)
    val motor1: Motor = Motor(5)
    val pinOrdenes = false
    val ordenes = mutableListOf<Orden>()
    val botonAvance = OrdenAvanzar(6)
    val botonGiroDerecha = OrdenGirarDerecha(7)
    val botonGiroIzquierda = OrdenGirarIzquierda(7)

    fun iniciar() {
        motor0.iniciar()
        motor1.iniciar()
        botonAvance.iniciar()
        botonGiroDerecha.iniciar()
        botonGiroIzquierda.iniciar()
    }
    fun avanzar(tiempo: Int) {
        motor0.avanzar()
        motor1.avanzar()
        esperar(tiempo)
        motor0.parar()
        motor1.parar()
    }
    fun girarDerecha() {
        motor0.avanzar()
        esperar(15) // Tiempo necesario para girar 90 grados
        motor0.parar()
    }
    fun girarIzquierda() {
        motor1.avanzar()
        esperar(15) // Tiempo necesario para girar 90 grados
        motor1.parar()
    }
    fun esperar(tiempo: Int) {
        //Delay
        TODO()
    }
    fun escucharOrdenes() {
        var pinPresionado = 0
        while(ordenes.size < 4) {
            if(pinPresionado == 1) {
                ordenes.add(botonAvance)
            }
            if(pinPresionado == 2) {
                ordenes.add(botonGiroDerecha)
            }
            if(pinPresionado == 3) {
                ordenes.add(botonGiroIzquierda)
            }
        }
        ejecutarOrdenes()
    }
    fun ejecutarOrdenes() {
        ordenes.forEach { it.ejecutarOrden(this) }
        ordenes.clear()
    }
}
