#distancia = int(input()) input the distance
#velocidade = int(input()) input the speed
horas = (distancia / velocidade)
hora_decimais = (horas - int(horas)) * 60
minutos = int(hora_decimais)
hora = int(horas)
print(f'{hora:02d}:{minutos:02d}') #Return Time in model: HH:MM