#ifndef AUDIOSREENVIEW_HPP
#define AUDIOSREENVIEW_HPP
#include <gui_generated/audiosreen_screen/AudioSreenViewBase.hpp>
#include <gui/audiosreen_screen/AudioSreenPresenter.hpp>

class AudioSreenView : public AudioSreenViewBase
{
public:
    AudioSreenView();
    virtual ~AudioSreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void gainChange(int value);
    virtual void handleTickEvent();
protected:
};

#endif // AUDIOSREENVIEW_HPP
