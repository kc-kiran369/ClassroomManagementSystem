#include"Data/StudentRegistry.h"

cms::Data::StudentRegistry::StudentRegistry()
{

}

cms::Data::StudentRegistry::~StudentRegistry()
{

}

void cms::Data::StudentRegistry::FillWithRandomData()
{
	cms::Benchmark::Timer time;

	Class09.FillWithRandomStudents();
	Class10.FillWithRandomStudents();
	Class11.FillWithRandomStudents();
	Class12.FillWithRandomStudents();

	std::string msg = "Random Fill Took : " + std::to_string(time.Stop()) + "sec";
	cms::Windows::PromptBox::Open(msg.c_str(), MB_OK | MB_ICONINFORMATION);
}

UINT cms::Data::StudentRegistry::GetTotalStudents()
{
	return (UINT)Class09.GetTotalStudents() + Class10.GetTotalStudents() + Class11.GetTotalStudents() + Class12.GetTotalStudents();
}