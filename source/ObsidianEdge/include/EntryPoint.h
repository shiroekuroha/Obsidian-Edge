#ifndef OE_ENTRY_POINT_H
#define OE_ENTRY_POINT_H

extern ObsidianEdge::Application *ObsidianEdge::createApplication();

int main(int argc, char **argv)
{
    ObsidianEdge::Logger::init();

    auto app = ObsidianEdge::createApplication();
    app->run();
    delete app;
}

#endif
