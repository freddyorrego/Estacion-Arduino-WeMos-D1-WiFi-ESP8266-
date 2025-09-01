# 🌦️ Estación Meteorológica Educativa

Siempre quise tener una estación meteorológica en casa, mi problema como el de muchos es el elevado costo de esta. Esto me llevó a plantearme un desafío construir una estación meteorológica de bajo coste con partes que sean fáciles de encontrar y que enviara los datos a una página web.

Los pasos que seguí fueron:

Seleccionar y adquirir los componentes necesarios, que en el caso de mi estación fueron, WeMos R1 D1 (compatible) que es una placa de desarrollo que incluye conexión a wifi, sensor de temperatura y humedad DHT22 , sensor UV análogo GUVA-S12SD , sensor de intensidad lumínica BH1750 y opcionalmente un LCD de 16x2.
Conectar los sensores a la placa WeMos R1 D1 según las instrucciones del fabricante.
Escribir el código para leer los datos de los sensores, procesarlos y la eliminación de valores anómalos o erróneos.
Opcional conectar LCD para que los datos se presenten de manera clara y fácil de leer (solo en face de pruebas).
Decidir la fuente de alimentación, en mi caso un panel solar y batería pero podría ser enchufado a la corriente a través de un cargador de celular .
Escribir el código html y crear las bases de datos para almacenar la información en un sitio web.

## 🔧 Hardware utilizado
- Sensor DHT22 (Temperatura y Humedad)
- Sensor RTC DS3231
- Sensor UV GUVA-S12SD
- Sensor GY-68 BMP180
- Sensor BH1750
- Pantalla LCD I2C 16x2 ( solo para desarrollo o opcional )
- Módulo SD
- WeMos R1 D1 (compatible)
- Hosting / dominio

## 🔧 Material adicional 
- Cautín de soldar
- Soldadura
- Cables Dupont o similares
- Caja para contener el proyecto
- Fuente de alimentación ( batería portátil o sistema solar de alimentación o cargador de móvil )

## 📊 Funcionalidades
- visualización de Temperatura
- visualización de presión atmosférica
- visualización de  humedad
- visualización intensidad  lumínica
- visualización de radiación UV
- Registro en base de datos miSQL

## 📁 Archivos
- `src/estacion_meteo.ino`: Código principal
- `docs/`: Diagramas y explicaciones
- `data/`: Ejemplos de registros
- `web/`: montaje en servidor web

## 🧠 Lógica educativa
El sistema esta pensado para montar un proyecto educativo, que los estudiantes puedan comprender la logica de la programacion y adquieran destresas necesarias para el trabajo con el hardware .

## 📷 Ejemplo de visualización
sitio web http://www.2g.cl/meteo/

## 📈 Ejemplo de registro
```csv
Fecha,Hora,Temp,Humedad,TempRTC,PuntoRocio,RiesgoRocio
2025-09-01,09:30:00,18.5,92,19.0,17.9,SI
