// DevOps FHSS on Points
// Current v0.1-dev manager: discovery + diagnostic dump.
// Frequency mutation/scheduling will be implemented in the Frequency layer.

class DFOP_FrequencyManager
{
	protected static ref array<ref DFOP_RadioNode> s_Nodes = {};

	static void RefreshNodes()
	{
		DFOP_RadioDiscovery.Discover(s_Nodes);
	}

	static void ScanWorld()
	{
		RefreshNodes();
		DumpNodes();
	}

	static void DumpNodes()
	{
		PrintFormat("[DFOP] Dumping %1 radio nodes", s_Nodes.Count());

		int nodeIndex = 0;

		foreach (DFOP_RadioNode node : s_Nodes)
		{
			if (!node)
				continue;

			nodeIndex++;

			PrintFormat(
				"[DFOP] NODE #%1 | Entity=%2 | Powered=%3 | Source=%4 | Key='%5' | TRX=%6",
				nodeIndex,
				node.GetDebugName(),
				node.IsPowered(),
				node.IsSource(),
				node.GetEncryptionKey(),
				node.GetTransceiverCount()
			);

			for (int i = 0; i < node.GetTransceiverCount(); i++)
			{
				BaseTransceiver trx = node.GetTransceiver(i);

				if (!trx)
					continue;

				PrintFormat(
					"[DFOP]   TRX #%1 | Freq=%2 kHz | Range=%3 m | Min=%4 | Max=%5 | Step=%6 kHz",
					i,
					trx.GetFrequency(),
					trx.GetRange(),
					trx.GetMinFrequency(),
					trx.GetMaxFrequency(),
					trx.GetFrequencyResolution()
				);
			}
		}

		PrintFormat("[DFOP] Scan complete | Radios=%1", s_Nodes.Count());
	}
}
