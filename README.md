# Proyecto_Progra02
SISTEMA DE RESERVAS CALENDAR-PRO





Restricciones Técnicas:
    -Según establece el documento: "Puede incluir y utilizar iostream, fstream, string, y librerías que le permitan jugar con fechas". Por tanto, se utilizó <ctime> para trabajar con fechas y la función strftime para mostrar la fecha.


Suposiciones: 
    -Se asume que el usuario ingresará un día de un mes válido para hacer las reservaciones.
    -Se restringen las horas a horas laborales (8-17, o sea 8am-5pm)


PENDIENTE:
    -En el menu reservación de calendario, hacerlo a prueba de errores. Por ejemplo, que ingrese texto
    -Que las horas no sean laborales, sino, todo el día.
    -Al hacer una reservación, indicar hasta el minuto
    -Explicar el Reservacion::verFechas()
    -Try catch para la recepción de datos en calendario (menu, fechas, etc)
    -Hacer que los eventos no choquen
    -Hacer que los eventos se vayan agregando en orden
    -Condición de creación de eventos: la fecha final debe ser posterior a la fecha inicial.