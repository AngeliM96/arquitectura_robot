package arquitectura_robot

interface Orden {
    val pin: Int
    fun ejecutarOrden(robot: Robot)
    fun iniciar() {
        // Configurar pin como pulsador
        TODO()
    }
}

class OrdenAvanzar(override val pin: Int): Orden {
    override fun ejecutarOrden(robot: Robot) {
        robot.avanzar(1000)
    }
}

class OrdenGirarDerecha(override val pin: Int): Orden {
    override fun ejecutarOrden(robot: Robot) {
        robot.girarDerecha()
    }
}

class OrdenGirarIzquierda(override val pin: Int): Orden {
    override fun ejecutarOrden(robot: Robot) {
        robot.girarIzquierda()
    }
}