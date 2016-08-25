//
// Created by huxf on 2016/8/3.
//

#include "colour_value.h"

namespace magic
{

    const ColourValue ColourValue::ZERO = ColourValue(.0f, .0f, .0f, .0f);
    const ColourValue ColourValue::Black = ColourValue(0.0, 0.0, 0.0);
    const ColourValue ColourValue::White = ColourValue(1.0, 1.0, 1.0);
    const ColourValue ColourValue::Red = ColourValue(1.0, 0.0, 0.0);
    const ColourValue ColourValue::Green = ColourValue(0.0, 1.0, 0.0);
    const ColourValue ColourValue::Blue = ColourValue(0.0, 0.0, 1.0);

}