#include "ObsidianEdge.h"

#include "Utility/List.h"

class Sandbox : public ObsidianEdge::Application
{
public:
    Sandbox()
    {
        OE_INFO("Application Starting...")
    }

    ~Sandbox()
    {
        OE_INFO("Application Ending...")
    }

    void Run() override
    {
        OE_WARN("Application Running...")

        int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        List<int, int> numList(arr, 10);

        OE_TRACE("First Number: {}", numList[(-1)]->Val())
        numList.DeleteLast();
        OE_TRACE("First Number: {}", numList[(-1)]->Val())
        numList.DeleteLast();
        OE_TRACE("First Number: {}", numList[(-1)]->Val())
        numList.DeleteLast();
    }

private:
};

ObsidianEdge::Application *ObsidianEdge::CreateApplication()
{
    return new Sandbox;
}
