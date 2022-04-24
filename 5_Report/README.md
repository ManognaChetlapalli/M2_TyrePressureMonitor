# Report
## OBLECTIVES
Tyre pressure monitor helps to calculate the air pressure in the vehicle tyre and alerts when it is need to be refilled. 
## INTRODUCTION
Many people forget to check the tyres of their vehicle and get burst tyre, to avoid tyre bursting and damage to tyre, this project will help. Tyre pressure monitor helps to calculate the air pressure in the vehicle tyre and alerts when it is need to be refilled. 
### Defining System
* Design and testing operations of tyre pressure monitor using simulide.
### Catergory
Potentiometer is used instead sensor mpx4115a(pressure sensor). 
### Components and supplies
* Atmega328
* Mpx4115a
* led
* resistor
* hd44780-59
### SWOT analysis
**Strengths:** User-friendly, innovative.

**Weakness:** Complexity of the code will increase as features are added.

**Opportunities:** People can just watch the tyre pressure in lcd display and the system also alerts the user, when a refill is needed.

**Threats:** sensor fail, led can be failed and alert cannot be made.
### 4’W and 1’H
**What:** Tyre pressure monitor.

**Where:** bikes,cars,trucks,buses.

**When:** it will alert user when a air refill is needed.

**How:** uses mpx4115a sensor to give the pressure value.
### Block Diagram
![Untitled Diagram drawio](https://user-images.githubusercontent.com/101464023/164989288-8708e0f1-ce4b-4f9a-b5a3-deccd663124b.png)
### Flowchart
![Untitled Diagram drawio (1)](https://user-images.githubusercontent.com/101464023/164989299-340bac3d-f0f3-4c97-b5cb-d479ca4356ed.png)
### Schematic Capture
![schematic](https://user-images.githubusercontent.com/101464023/164989372-1c541093-9eaf-41bb-9106-3982ab3a9569.png)
### High Level Requirements
| ID | Description | Status |
| --- | --- | --- |
| HL1 | Mpx4115a interfacing with atmega328 | Implemented |
| HL2 | lcd interfacing with atmega328 | Implemented |
| HL3 | led interfacing with atmegs328 | Implemented |
### Low Level Requirements
| ID | Description | Status |
| --- | --- | --- |
| HL1-LL1 | calculates the adc pressure by sensor | Implemented |
| HL2-LL2 | display the adc value | Implemented |
| HL3-LL3 | alerts the user when pressure falls below a certain range | Implemented |
### Pressure is normal
![air is there](https://user-images.githubusercontent.com/101464023/164989388-c15fba7e-8644-4adf-bd04-59f8f02c15c5.png)
### Refill of air is needed
![refill](https://user-images.githubusercontent.com/101464023/164989389-156eb975-bd58-434a-81d2-66348b79fba8.png)
