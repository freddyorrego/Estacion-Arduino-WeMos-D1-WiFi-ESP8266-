-- phpMyAdmin SQL Dump
-- version 5.2.2
-- https://www.phpmyadmin.net/
--
-- Servidor: localhost:3306
-- Tiempo de generación: 01-09-2025 a las 11:32:47
-- Versión del servidor: 10.6.22-MariaDB-cll-lve
-- Versión de PHP: 8.3.23

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `nombre de tu base de datos`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `meteo`
--

CREATE TABLE `meteo` (
  `ID` bigint(8) NOT NULL,
  `fecha` date NOT NULL,
  `temperatura` float NOT NULL,
  `humedad` varchar(250) NOT NULL,
  `indicecalor` mediumtext NOT NULL,
  `time` time NOT NULL,
  `lux` mediumtext NOT NULL,
  `uv` varchar(250) NOT NULL,
  `presion` varchar(250) NOT NULL,
  `temperatura2` varchar(250) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_swedish_ci;

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `meteo`
--
ALTER TABLE `meteo`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `meteo`
--
ALTER TABLE `meteo`
  MODIFY `ID` bigint(8) NOT NULL AUTO_INCREMENT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
