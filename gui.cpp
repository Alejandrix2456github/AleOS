#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600

// Prototype for put_pixel function
void put_pixel(int x, int y, unsigned int color);

// Draw a simple desktop background
void draw_desktop() {
    for (int y = 0; y < SCREEN_HEIGHT; ++y) {
        for (int x = 0; x < SCREEN_WIDTH; ++x) {
            // Here you would call put_pixel(x, y, color);
        }
    }
    // Optionally draw icons, taskbar, etc.
}

// Dummy implementation of put_pixel for demonstration
void put_pixel(int x, int y, unsigned int color) {
    // Implementation to set a pixel at (x, y) with the given color
    // This should be replaced with actual graphics code
}