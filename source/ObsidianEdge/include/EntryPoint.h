#ifndef OE_ENTRY_POINT_H
#define OE_ENTRY_POINT_H

extern ObsidianEdge::Application *ObsidianEdge::CreateApplication();

int main(int argc, char **argv)
{
    ObsidianEdge::Logger::Init();

    auto app = ObsidianEdge::CreateApplication();
    app->Run();
    delete app;
}

#endif
