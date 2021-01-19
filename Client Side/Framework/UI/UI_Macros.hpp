// Geometry

#define SAFEZONE_X(value) x = (value) * safezoneW + safezoneX
#define SAFEZONE_Y(value) y = (value) * safezoneH + safezoneY
#define SAFEZONE_W(value) w = (value) * safezoneW
#define SAFEZONE_H(value) h = (value) * safezoneH

#define MARGIN_X 0.00515625
#define MARGIN_Y 0.011

// Used for creating a line of equal width boxes.
#define HORIZONTAL_GRID_X(x, width, itemNumber) (x + (width * (itemNumber - 1))) + (MARGIN_X * itemNumber)
#define HORIZONTAL_GRID_W(width, items) ((width / items) - MARGIN_X)

// Colours

#define NO_COLOUR {0, 0, 0, 0}

// Structure
#define HEADER_COLOUR {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", 1}
#define BODY_COLOUR {0.204, 0.2, 0.204, 1}
#define FOOTER_COLOUR {0.125, 0.122, 0.125, 1}

// Content
#define INNER_BODY_COLOUR {0.098, 0.094, 0.098, 1}