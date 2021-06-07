package arquitectura_robot

class Motor(pin: Int) {
    var prendido = false
    fun iniciar() {
        //configurar pin como output
        TODO()
    }
    fun avanzar() {
        prendido = true
    }
    fun parar() {
        prendido = false
    }
}