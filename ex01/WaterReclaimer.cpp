
#include "Errors.hpp"
#include "WaterReclaimer.hpp"

WaterReclaimer::WaterReclaimer()
    : _water(0),
      _started(false)
{
}


WaterReclaimer::~WaterReclaimer()
{
}

void
WaterReclaimer::start()
{
    MissionCriticalError mc("Not enough water to achieve the mission.", "WaterReclaimer");
    if (_water == 0)
        throw mc;
    _started = true;
}

void
WaterReclaimer::useWater(int water)
{
    LifeCriticalError lf("Cannot use water, not enough in the reclaimer.", "WaterReclaimer");
    if (water <= 0)
    {
        UserError userError("Water use should be positif.", "WaterReclaimer");
        throw userError;
    }
    if (_started == false)
    {
        UserError errStart("Cannot use water if the reclaimer hasn't started.", "WaterReclaimer");
        throw errStart;
    }
    _water -= water;
    if (_water < 10)
        throw lf;
}

void
WaterReclaimer::generateWater()
{
    NasaError ns("Cannot generate water, reclaimer already full.", "WaterReclaimer");
    if (_water > 90)
        throw ns;
    _water += 10;
}
