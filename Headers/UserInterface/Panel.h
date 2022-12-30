#ifndef PANEL_H
#define PANEL_H

#include"Data/StudentRegistry.h"

namespace cms::UI
{
	class Panel
	{
	protected:
		bool m_PanelEnabled = true;
		Data::StudentRegistry* m_Registry = nullptr;
	public:
		virtual void Draw() = 0;
		virtual void SetRegistry(Data::StudentRegistry* Registry) = 0;
	};
}

#endif