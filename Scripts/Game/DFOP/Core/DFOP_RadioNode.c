// DevOps FHSS on Points
// Generic wrapper around a vanilla Conflict military-base radio node.
// IMPORTANT: no behaviour in this class depends on entity names.

class DFOP_RadioNode
{
	protected SCR_MilitaryBaseComponent m_Base;
	protected SCR_CoverageRadioComponent m_Radio;
	protected IEntity m_Owner;

	void DFOP_RadioNode(SCR_MilitaryBaseComponent base, SCR_CoverageRadioComponent radio)
	{
		m_Base = base;
		m_Radio = radio;

		if (m_Base)
			m_Owner = m_Base.GetOwner();
	}

	SCR_MilitaryBaseComponent GetBase()
	{
		return m_Base;
	}

	SCR_CoverageRadioComponent GetRadio()
	{
		return m_Radio;
	}

	IEntity GetOwner()
	{
		return m_Owner;
	}

	string GetDebugName()
	{
		if (!m_Owner)
			return "<no-owner>";

		return m_Owner.GetName();
	}

	bool IsPowered()
	{
		if (!m_Radio)
			return false;

		return m_Radio.IsPowered();
	}

	bool IsSource()
	{
		if (!m_Radio)
			return false;

		return m_Radio.IsSource();
	}

	string GetEncryptionKey()
	{
		if (!m_Radio)
			return "";

		return m_Radio.GetEncryptionKey();
	}

	int GetTransceiverCount()
	{
		if (!m_Radio)
			return 0;

		return m_Radio.TransceiversCount();
	}

	BaseTransceiver GetTransceiver(int index)
	{
		if (!m_Radio)
			return null;

		if (index < 0 || index >= m_Radio.TransceiversCount())
			return null;

		return m_Radio.GetTransceiver(index);
	}
}
