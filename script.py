import serial

serial_port = '/dev/ttyUSB0';
baud_rate = 9600;
write_to_file_path = "output.txt";

while True:
    output_file = open(write_to_file_path, "a");
    ser = serial.Serial(serial_port, baud_rate)
    line = ser.readline();
    line = line.decode("utf-8")
    print(line);
    if 'zapis' in line:
        output_file.write(line);
    if 'exit' in line:
        output_file.close;
        exit(1);