<?php
// Configuración de conexión
$host = "localhost";
$user = "tu_usuario";
$password = "tu_contraseña";
$database = "tu_base_de_datos";

// Crear conexión
$conn = new mysqli($host, $user, $password, $database);

// Verificar conexión
if ($conn->connect_error) {
    die("Conexión fallida: " . $conn->connect_error);
}

// Consulta básica
$sql = "SELECT fecha, time, temperatura, humedad, indicecalor, lux, uv, presion, temperatura2 FROM meteo ORDER BY ID DESC LIMIT 10";
$result = $conn->query($sql);

// Mostrar resultados
if ($result->num_rows > 0) {
    echo "<table border='1'>";
    echo "<tr><th>Fecha</th><th>Hora</th><th>Temp</th><th>Humedad</th><th>Índice Calor</th><th>Lux</th><th>UV</th><th>Presión</th><th>Temp2</th></tr>";
    while($row = $result->fetch_assoc()) {
        echo "<tr>
                <td>{$row['fecha']}</td>
                <td>{$row['time']}</td>
                <td>{$row['temperatura']}°C</td>
                <td>{$row['humedad']}%</td>
                <td>{$row['indicecalor']}</td>
                <td>{$row['lux']}</td>
                <td>{$row['uv']}</td>
                <td>{$row['presion']}</td>
                <td>{$row['temperatura2']}</td>
              </tr>";
    }
    echo "</table>";
} else {
    echo "No hay datos disponibles.";
}

$conn->close();
?>
