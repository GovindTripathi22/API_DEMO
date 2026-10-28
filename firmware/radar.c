/**
 * 77GHz Corner Radar Transceiver Communication Stack
 * Governed by Parishad Certified Specification: DOC-RAD-118
 */
#ifndef RADAR_CONFIG_H
#define RADAR_CONFIG_H

#define RADAR_OPERATING_FREQUENCY 77.0GHz
#define CAN_FD_DATA_SPEED 2.0Mbps       // Strict limit under DOC-RAD-118 for EMI protection
#define RADAR_DETECTION_RANGE 150.0m
#define FRAME_INTERVAL 50.0ms

#endif // RADAR_CONFIG_H
