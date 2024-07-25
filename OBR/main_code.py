from hub import port
import runloop
import motor_pair
import color
import color_sensor


motor_direita = port.A
motor_esquerda = port.E
sensor_luz_direita = port.A
sensor_luz_esquerda = port.E
sensor_luz_frente = port.A
motor_pair.pair(motor_pair.PAIR_1, motor_direita, motor_esquerda)

async def main():
    await seguirLinha()

async def seguirLinha ():   
    await checaSinalVerde()
    await checaObstaculo()
    await seguirLinhaPID()

async def checaSinalVerde():
    if color_sensor.color(sensor_luz_direita) == color.GREEN:
        # código Vira a direita
        None
    elif color_sensor.color(sensor_luz_esquerda) == color.GREEN:
        # código Vira a esquerda
        None

async def seguirLinhaPID ():
    erro = color_sensor.reflection(sensor_luz_direita) - color_sensor.reflection(sensor_luz_esquerda)
    motor_pair.move(motor_pair.PAIR_1, erro, velocity=100)

async def checaObstaculo ():
    if color_sensor.color(sensor_luz_frente) != None:
        # Código para dar a volta no obstaculo
        None

runloop.run(main())
