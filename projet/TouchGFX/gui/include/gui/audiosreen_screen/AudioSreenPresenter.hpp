#ifndef AUDIOSREENPRESENTER_HPP
#define AUDIOSREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class AudioSreenView;

class AudioSreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    AudioSreenPresenter(AudioSreenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~AudioSreenPresenter() {}

private:
    AudioSreenPresenter();

    AudioSreenView& view;
};

#endif // AUDIOSREENPRESENTER_HPP
