package arquitectura_robot

object Arduino {
    val robot = Robot()
    fun setup() {
        robot.iniciar()
    }
    fun loop() {
        if(robot.pinOrdenes) {
            robot.escucharOrdenes()
        }
    }
}