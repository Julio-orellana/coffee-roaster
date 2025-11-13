# 🔧 Sistema de Monitoreo de Tostado de Café

Este programa permite **supervisar el proceso de tostado de granos de café** utilizando un **sensor de temperatura MAX6675** y un **Arduino UNO**.  
El sistema detecta cuándo inicia el tostado, muestra información en tiempo real sobre la temperatura y el tiempo transcurrido, y advierte si se alcanzan temperaturas peligrosas.

---

## 🧠 Funcionalidad General

El programa realiza las siguientes acciones:

1. **Lectura continua** de la temperatura mediante el sensor **MAX6675**.  
2. Cuando se detectan **más de 50 °C**, el sistema muestra el mensaje:  
   🔥 Sistema activo, iniciando temporizador  
3. **Inicia un cronómetro** (en minutos y segundos) que muestra el tiempo desde el inicio del tostado.  
4. En pantalla se muestran los siguientes datos en tiempo real:  
   - 🌡️ **Temperatura actual**  
   - ⏱️ **Tiempo transcurrido**  
   - ⚙️ **Estado del sistema** (normal, ideal, advertencia)

---

## 🌡️ Rangos de Temperatura y Estados del Sistema

| Rango de Temperatura | Estado del Sistema | Descripción |
|----------------------:|:------------------:|-------------|
| 🔹 < 50 °C            | **Frío / Apagado** | Sistema en reposo, sin actividad de tostado. |
| 🔸 200 °C – 250 °C     | **Ideal** | Zona óptima de tostado del café. |
| 🟠 250 °C – 270 °C     | **Alta (Precaución)** | Temperatura elevada, se recomienda vigilancia. |
| 🔴 > 270 °C           | **Advertencia** | ⚠️ Temperatura demasiado alta — apagar sistema manualmente. |

---

## 🖥️ Interfaz en Pantalla

Durante el funcionamiento, la pantalla mostrará información como:

🌡️ Temp: 235 °C  
⏱️ Tiempo: 02:15  
⚙️ Estado: Zona ideal  

En caso de advertencia:  
⚠️ Temperatura demasiado alta — apagar sistema manualmente

---

## 🧩 Componentes Principales

- Arduino UNO  
- Sensor de temperatura **MAX6675 + Termocupla tipo K**  
- Módulo de pantalla (LCD o Serial Monitor)  
- Fuente de alimentación  
- Cableado básico  

---

## ⚙️ Conexiones del Sensor MAX6675 al Arduino UNO

| Pin MAX6675 | Pin Arduino UNO | Descripción |
|-------------|----------------|--------------|
| VCC         | 5V             | Alimentación del módulo |
| GND         | GND            | Tierra común |
| SCK         | Pin 13         | Señal de reloj SPI |
| CS          | Pin 10         | Chip Select |
| SO          | Pin 12         | Salida de datos del sensor |

---

## 🚀 Próximas Mejoras (Opcional)

- Control automático del apagado mediante **relé**.  
- Registro de temperaturas y tiempos en **archivo CSV**.  
- Interfaz gráfica en PC para visualizar el proceso de tostado.  
- Sistema de alerta sonora para sobrecalentamiento.  

---

## 🧾 Autor

Proyecto desarrollado como parte de un sistema experimental de **control de tostado de café con Arduino**.  
📍 Universidad del Valle de Guatemala  
💡 Versión inicial sin control automático del apagado.

---
