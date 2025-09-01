<?php
$servername = "localhost";
$database = "nombre_base_de_datos";
$username = "usuario_base_de_datos";
$password = "contraseña_base_de_datos";

//******asignacion de variables******

$temperatura=$_GET['temp'];
$humedad=$_GET['hum'];
$indicecalor=$_GET['indc'];
$lux=$_GET['lux'];
$dviento=$_GET['dv'];
$presion=$_GET['pres'];
$temperatura2=$_GET['temp2'];

// Create connection

$conn = mysqli_connect($servername, $username, $password, $database);

// Check connection

if (!$conn) {

      die("Connection failed: " . mysqli_connect_error());

}

echo "BD Ok/";
// Ajusta tu zona horaria en mi caso
date_default_timezone_set("America/Santiago"); 
//asigno los valores de fecha y hora 
$fecha1=date("Ymd");
$hora1=date("His"); 
//inserto datos 
$sql = "INSERT INTO meteo (fecha, temperatura, humedad, indicecalor, time, lux, uv, presion, temperatura2) VALUES (".$fecha1.",".$temperatura.", ".$humedad.",".$indicecalor.",".$hora1.",".$lux.",".$dviento.",".$presion.",".$temperatura2.");";

if (mysqli_query($conn, $sql)) {

      echo "Ingreso Ok";

} else {

      echo "Error: " . $sql . "<br>" . mysqli_error($conn);

}

mysqli_close($conn);

?>
