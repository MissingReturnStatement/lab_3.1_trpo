import pylidlight

# Подключаемся к базе
db = pylidlight.DB("data.db")
# Загружаем данные о месте (оно одно, пока что)
place = db.get_place('Lidar(Tomsk)')

# Загружем список доступных данных
data = db.get_data(place)
# Берем любой порядковый номер в данных
N = 110

print("t    = ", data[N].timestamp)
print("date = ", data[N].date)

# pylidlight.Measure.PRESSURE
# pylidlight.Measure.TEMPERATURE
# pylidlight.Measure.REL_HUMIDITY
# pylidlight.Measure.ABS_HUMIDITY
# pylidlight.Measure.WIND_DIRECTION
# pylidlight.Measure.WIND_SPEED
# Загружаем конкретное измерение
altitudes, measurements = db.get_measurements(data[N], pylidlight.Measure.PRESSURE)

# А можем просто сразу же получить интерполяцию на заданной сетке высот 
# в заданный момент времени
# в заданном месте
altitudes, measurements = db.get_measurements_approx(
    timestamp=1231187000, measure=pylidlight.Measure.PRESSURE, 
    place=place,
    altitudes=[100, 200, 300, 400, 500, 600, 6000, 10000])


lidar_data = db.get_lidar_data(place)
db.get_lidar_data(lidar_data[0])
xs, snrs, ms = db.get_lidar_measurements(
    data=lidar_data[0], channel=pylidlight.Channel.MAIN, only_in_border=True)

# Можно просто получить DataFrame со всеми данными
df = db.get_lidar_dataframe(place)
