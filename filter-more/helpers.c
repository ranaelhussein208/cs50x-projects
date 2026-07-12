#include "helpers.h"

#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            // Calculate the average of red, green, and blue
            int average = round(
                (image[row][column].rgbtRed +
                 image[row][column].rgbtGreen +
                 image[row][column].rgbtBlue) / 3.0
            );

            // Set all three channels to the same value
            image[row][column].rgbtRed = average;
            image[row][column].rgbtGreen = average;
            image[row][column].rgbtBlue = average;
        }
    }

    return;
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        // Only iterate through the first half of each row
        for (int column = 0; column < width / 2; column++)
        {
            int opposite = width - 1 - column;

            RGBTRIPLE temporary = image[row][column];
            image[row][column] = image[row][opposite];
            image[row][opposite] = temporary;
        }
    }

    return;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Store the original image so changed pixels do not affect later calculations
    RGBTRIPLE original[height][width];

    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            original[row][column] = image[row][column];
        }
    }

    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            int total_red = 0;
            int total_green = 0;
            int total_blue = 0;
            int pixel_count = 0;

            // Examine the surrounding 3 × 3 area
            for (int row_offset = -1; row_offset <= 1; row_offset++)
            {
                for (int column_offset = -1;
                     column_offset <= 1;
                     column_offset++)
                {
                    int neighbour_row = row + row_offset;
                    int neighbour_column = column + column_offset;

                    // Only include neighbours inside the image
                    if (neighbour_row >= 0 &&
                        neighbour_row < height &&
                        neighbour_column >= 0 &&
                        neighbour_column < width)
                    {
                        total_red +=
                            original[neighbour_row][neighbour_column].rgbtRed;

                        total_green +=
                            original[neighbour_row][neighbour_column].rgbtGreen;

                        total_blue +=
                            original[neighbour_row][neighbour_column].rgbtBlue;

                        pixel_count++;
                    }
                }
            }

            image[row][column].rgbtRed =
                round((double) total_red / pixel_count);

            image[row][column].rgbtGreen =
                round((double) total_green / pixel_count);

            image[row][column].rgbtBlue =
                round((double) total_blue / pixel_count);
        }
    }

    return;
}


// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE original[height][width];

    // Copy the original image
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            original[row][column] = image[row][column];
        }
    }

    // Sobel kernels
    int gx_kernel[3][3] =
    {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int gy_kernel[3][3] =
    {
        {-1, -2, -1},
        { 0,  0,  0},
        { 1,  2,  1}
    };

    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            int gx_red = 0;
            int gx_green = 0;
            int gx_blue = 0;

            int gy_red = 0;
            int gy_green = 0;
            int gy_blue = 0;

            // Examine the 3 × 3 area around the current pixel
            for (int kernel_row = 0; kernel_row < 3; kernel_row++)
            {
                for (int kernel_column = 0;
                     kernel_column < 3;
                     kernel_column++)
                {
                    int neighbour_row = row + kernel_row - 1;
                    int neighbour_column = column + kernel_column - 1;

                    // Pixels outside the image are treated as black
                    if (neighbour_row >= 0 &&
                        neighbour_row < height &&
                        neighbour_column >= 0 &&
                        neighbour_column < width)
                    {
                        RGBTRIPLE neighbour =
                            original[neighbour_row][neighbour_column];

                        int gx_weight =
                            gx_kernel[kernel_row][kernel_column];

                        int gy_weight =
                            gy_kernel[kernel_row][kernel_column];

                        gx_red += neighbour.rgbtRed * gx_weight;
                        gx_green += neighbour.rgbtGreen * gx_weight;
                        gx_blue += neighbour.rgbtBlue * gx_weight;

                        gy_red += neighbour.rgbtRed * gy_weight;
                        gy_green += neighbour.rgbtGreen * gy_weight;
                        gy_blue += neighbour.rgbtBlue * gy_weight;
                    }
                }
            }

            int red = round(sqrt(gx_red * gx_red + gy_red * gy_red));
            int green = round(
                sqrt(gx_green * gx_green + gy_green * gy_green)
            );
            int blue = round(
                sqrt(gx_blue * gx_blue + gy_blue * gy_blue)
            );

            // RGB values cannot exceed 255
            if (red > 255)
            {
                red = 255;
            }

            if (green > 255)
            {
                green = 255;
            }

            if (blue > 255)
            {
                blue = 255;
            }

            image[row][column].rgbtRed = red;
            image[row][column].rgbtGreen = green;
            image[row][column].rgbtBlue = blue;
        }
    }

    return;
}

