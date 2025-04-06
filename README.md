# Production Line Control System 
This project simulates a **production line control system**, designed using **AT89C52** microcontrollers, clocked at **1.3824 MHz**, communicating with each other via the **RS485/RS422** serial bus.
The system was built and tested in the Proteus environment, allowing for a realistic simulation of the system's behavior.
The system simulates the operation of a real production line: it enables access control, process start, counting of produced items, and visualization of operational parameters.

## System Operation Description
### 1. Waiting Mode (Inactive State)
After powering on the system:
- The **LCD** displays the message: **“PODAJ PIN”**.
- The system waits for the entry of the four-digit PIN (**9876**) from the keypad.
### 2. PIN Verification
- **If the PIN is incorrect**:
  - The status LED flashes, signaling an error.
  - The **LCD** still shows: **"PODAJ PIN"**.
  - The system remains inactive.
- **If the PIN is correct (9876)**:
  - The system switches to the active mode.
  - The status LED remains ON, signaling activity.
  - The **LCD** updates to:
    - First line: **"STAN AKTYWNY"**
    - Other lines: **"Prędkość napędu:     134 obr/min"**
### 3. Active Mode
In active mode:
- The production line simulation begins.
- The **simulated motor** runs, representing the movement of the conveyor belt.
- The **BCD counter** starts counting the produced items.
- The motor's speed is displayed on the **LCD**.
### 4. Button Handling
- **INT0 – BCD Counter Reset:**
  - Pressing the button connected to the **INT0** line of the microcontroller (labeled **U3**) resets the **BCD counter**.
- **INT1 – Toggle Speed Display:**
  - Pressing the **INT1** button will toggle the display of the motor speed on the LCD.
  - If disabled, the LCD will only show **"STAN AKTYWNY"**.
### 5. Production Process Completion
- Pressing the **“*”** button on the keypad will **stop the system**.
- The **LCD** will display: **"ZAKOŃCZONO"**.
- The **BCD counter is disabled**.
## File Descriptions
- **silnik.c** – This file is responsible for controlling the motor operation.  
- **bcd.c** – This file handles the BCD counter for tracking the produced items.  
- **lcd.c** – This file is responsible for controlling the LCD display.  
- **klawiatura.c** – This file manages the keypad input for entering the PIN and interacting with the system.  
- **Produkcja.mp4** – A short video demonstrating the operation of the system is included in this file.
- **produkcja.pdsprj** – Proteus project file that contains the complete simulation setup of the system, including microcontrollers, LCD, keypad, motor, LEDs, and all wiring.
- **produkcja.uvmpw** – Keil µVision project workspace file that includes all source files (`.c`, `.h`) and settings required to compile the firmware for the AT89C52 microcontrollers.

