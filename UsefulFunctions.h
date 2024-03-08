namespace UsefulFunctions
{
    float findNeededResistorParallel(float R1, float Rtot)
    {
        float R2 = -R1 * Rtot / (Rtot - R1);
        return R2;
    }

    // Voltage Divider Functions: VCC - - R1 - - R2 - - GND
    // VCC can also stand for drop in voltaage across R1 and R2 combined

    // find the resistance needed to achieve the desired voltage in between resistors based on R1
    float voltageDividerToGround(float R1, float VCC, float desiredVoltage)
    {
        return R1 / (1.0 / (VCC / desiredVoltage - 1));
    }

    // find the resistance needed to achieve the desired voltage in between resistors based on R2
    float voltageDividerToVCC(float R2, float VCC, float desiredVoltage)
    {
        return 1.0 / (VCC / desiredVoltage - 1) * R2;
    }
};
