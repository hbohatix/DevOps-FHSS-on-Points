// DevOps FHSS on Points
// Discovers radio-capable Conflict points through vanilla systems/components.
// Entity names are used only for diagnostics.

class DFOP_RadioDiscovery
{
	static int Discover(array<ref DFOP_RadioNode> nodes)
	{
		if (!nodes)
		{
			Print("[DFOP] ERROR: discovery output array is null");
			return 0;
		}

		nodes.Clear();

		SCR_MilitaryBaseSystem baseSystem = SCR_MilitaryBaseSystem.GetInstance();

		if (!baseSystem)
		{
			Print("[DFOP] ERROR: SCR_MilitaryBaseSystem not available");
			return 0;
		}

		array<SCR_MilitaryBaseComponent> bases = {};
		int baseCount = baseSystem.GetBases(bases);

		PrintFormat("[DFOP] Military bases registered: %1", baseCount);

		foreach (SCR_MilitaryBaseComponent base : bases)
		{
			if (!base)
				continue;

			IEntity owner = base.GetOwner();
			if (!owner)
				continue;

			SCR_CoverageRadioComponent radio =
				SCR_CoverageRadioComponent.Cast(
					owner.FindComponent(SCR_CoverageRadioComponent)
				);

			if (!radio)
				continue;

			nodes.Insert(new DFOP_RadioNode(base, radio));
		}

		PrintFormat("[DFOP] Radio-capable military bases discovered: %1", nodes.Count());
		return nodes.Count();
	}
}
