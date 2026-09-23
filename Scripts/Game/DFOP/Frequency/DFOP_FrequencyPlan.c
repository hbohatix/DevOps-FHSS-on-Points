// DevOps FHSS on Points
// Frequency-plan constants.
//
// User-facing design target:
// - frequency transitions use 0.2 MHz or 0.3 MHz deltas
// - expressed internally as 200 kHz and 300 kHz
// - actual mutation policy will be server-authoritative

class DFOP_FrequencyPlan
{
	static int GetStep200KHz()
	{
		return 200;
	}

	static int GetStep300KHz()
	{
		return 300;
	}
}
