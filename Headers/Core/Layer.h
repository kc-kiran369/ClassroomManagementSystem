#ifndef LAYER_H
#define LAYER_H

namespace cms::Core
{
	class Layer
	{
	public:
		virtual void Attach() = 0;
		virtual void Detach() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnUpdateComplete() = 0;
	};
}

#endif