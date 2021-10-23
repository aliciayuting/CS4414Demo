#include "controller/color.hpp"
#include "pngwriter/pngwriter.hpp"

const uint32_t DIMENSION = 64;
const int MAX_COLOR_VALUE = 65535;

void draw_horizontal(pngwriter& image, const std::string& color);
void draw_vertical(pngwriter& image, const std::string& color);
void draw_diagonal1(pngwriter& image, const std::string& color);
void draw_diagonal2(pngwriter& image, const std::string& color);

int main() {
    for(const std::string& color1 : controller::SHORT_COLORS) {
        for(const std::string& color2 : controller::SHORT_COLORS) {
            std::string file_name = "files/i2" + color1 + color2 + ".png";
            pngwriter image(DIMENSION, DIMENSION, 0, file_name.c_str());
            draw_horizontal(image, color1);
            draw_vertical(image, color2);
            image.close();

            for(const std::string& color3 : controller::SHORT_COLORS) {
                std::string file_name = "files/i3" + color1 + color2 + color3 + ".png";
                pngwriter image(DIMENSION, DIMENSION, 0, file_name.c_str());
                draw_horizontal(image, color1);
                draw_diagonal1(image, color2);
                draw_diagonal2(image, color3);
                image.close();

                for(const std::string& color4 : controller::SHORT_COLORS) {
                    std::string file_name = "files/i4" + color1 + color2 + color3 + color4 + ".png";
                    pngwriter image(DIMENSION, DIMENSION, 0, file_name.c_str());
                    draw_horizontal(image, color1);
                    draw_vertical(image, color2);
                    draw_diagonal1(image, color3);
                    draw_diagonal2(image, color4);
                    image.close();
                }
            }
        }
    }
}

int32_t r_comp(const std::string& color) {
    if(color == "r" || color == "y") {
        return MAX_COLOR_VALUE;
    }
    return 0;
}

int32_t g_comp(const std::string& color) {
    if(color == "g" || color == "y") {
        return MAX_COLOR_VALUE;
    }
    return 0;
}

int32_t b_comp(const std::string& color) {
    return 0;
}

void draw_horizontal(pngwriter& image, const std::string& color) {
    for(int32_t offset = -3; offset <= 3; ++offset) {
        image.line(0, DIMENSION / 2 + offset, DIMENSION, DIMENSION / 2 + offset,
                   r_comp(color), g_comp(color), b_comp(color));
    }
}

void draw_vertical(pngwriter& image, const std::string& color) {
    for(int32_t offset = -3; offset <= 3; ++offset) {
        image.line(DIMENSION / 2 + offset, 0, DIMENSION / 2 + offset, DIMENSION,
                   r_comp(color), g_comp(color), b_comp(color));
    }
}

void draw_diagonal1(pngwriter& image, const std::string& color) {
    image.line(0, 0, DIMENSION, DIMENSION,
               r_comp(color), g_comp(color), b_comp(color));
    for(int32_t offset = 1; offset <= 3; ++offset) {
        image.line(0, offset, DIMENSION - offset, DIMENSION,
                   r_comp(color), g_comp(color), b_comp(color));
    }
    for(int32_t offset = 1; offset <= 3; ++offset) {
        image.line(offset, 0, DIMENSION, DIMENSION - offset,
                   r_comp(color), g_comp(color), b_comp(color));
    }
}

void draw_diagonal2(pngwriter& image, const std::string& color) {
    image.line(0, DIMENSION, DIMENSION, 0,
               r_comp(color), g_comp(color), b_comp(color));
    for(int32_t offset = 1; offset <= 3; ++offset) {
        image.line(offset, DIMENSION, DIMENSION, offset,
                   r_comp(color), g_comp(color), b_comp(color));
    }
    for(int32_t offset = 1; offset <= 3; ++offset) {
        image.line(0, DIMENSION - offset, DIMENSION - offset, 0,
                   r_comp(color), g_comp(color), b_comp(color));
    }
}
