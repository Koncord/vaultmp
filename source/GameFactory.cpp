#include "GameFactory.hpp"

using namespace std;
using namespace RakNet;

Guarded<> GameFactory::cs;
GameFactory::BaseList GameFactory::instances;
GameFactory::BaseIndex GameFactory::index;
GameFactory::BaseCount GameFactory::typecount;
GameFactory::BaseDeleted GameFactory::delrefs;

#ifdef VAULTMP_DEBUG
DebugInput<GameFactory> GameFactory::debug;
#endif

vector<NetworkID> GameFactory::GetByType(unsigned int type) noexcept
{
	return cs.Operate([type]() {
		vector<NetworkID> result;
		result.reserve(typecount[type]);

		for (const auto& reference : instances)
			if (reference.second & type)
				result.emplace_back(reference.first->GetNetworkID());

		return result;
	});
}

unsigned int GameFactory::GetCount(unsigned int type) noexcept
{
	return cs.Operate([type]() {
		return typecount[type];
	});
}

bool GameFactory::IsDeleted(NetworkID id) noexcept
{
	return cs.Operate([id]() {
		return delrefs.find(id) != delrefs.end();
	});
}

unsigned int GameFactory::GetType(NetworkID id) noexcept
{
	return cs.Operate([id]() {
		auto it = GetShared(id);
		return it != instances.end() ? it->second : 0x00000000;
	});
}

void GameFactory::DestroyAll() noexcept
{
	BaseList copy;

	cs.Operate([&copy]() {
		copy = move(instances);
		index.clear();
		typecount.clear();
		delrefs.clear();
	});

	for (const auto& instance : copy)
	{
		Base* reference = static_cast<Base*>(instance.first->StartSession());
		reference->freecontents();

#ifdef VAULTMP_DEBUG
		debug.print("Base ", std::dec, instance.first->GetNetworkID(), " (type: ", typeid(*(instance.first)).name(), ") to be destructed (", instance.first.get(), ")");
#endif

		reference->Finalize();
	}

	Lockable::Reset();
}

bool GameFactory::Destroy(NetworkID id)
{
	return Destroy(Get<Base>(id).get());
}
