//
// Created by huxf on 2016/8/3.
//

#ifndef MAGIC_COLOUR_VALUE_H
#define MAGIC_COLOUR_VALUE_H

namespace magic {

    class ColourValue
    {

    public:
        static const ColourValue ZERO;
        static const ColourValue Black;
        static const ColourValue White;
        static const ColourValue Red;
        static const ColourValue Green;
        static const ColourValue Blue;

        explicit ColourValue( float red = 1.0f,
                              float green = 1.0f,
                              float blue = 1.0f,
                              float alpha = 1.0f ) : r(red), g(green), b(blue), a(alpha)
        { }

        float r,g,b,a;
    };

}

#endif //MAGIC_COLORVALUE_H
