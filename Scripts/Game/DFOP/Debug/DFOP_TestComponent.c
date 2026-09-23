// DevOps FHSS on Points
// Temporary Workbench test harness.
// Attach to a GenericEntity in a test/scenario world.

class DFOP_TestComponentClass : ScriptComponentClass
{
}

class DFOP_TestComponent : ScriptComponent
{
	protected bool m_bScanScheduled;

	override void OnPostInit(IEntity owner)
	{
		super.OnPostInit(owner);

		if (m_bScanScheduled)
			return;

		m_bScanScheduled = true;

		Print("[DFOP] Scheduling world radio scan");

		GetGame().GetCallqueue().CallLater(
			DFOP_FrequencyManager.ScanWorld,
			3000,
			false
		);
	}
}
