#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            BYTE blue = pixel.rgbtBlue;
            BYTE green = pixel.rgbtGreen;
            BYTE red = pixel.rgbtRed;

            if (blue == green && green == red)
            {
                image[i][j] = pixel;
            }
            else
            {
                BYTE Average = (BYTE) round((blue + green + red) / 3.0);
                image[i][j].rgbtBlue = Average;
                image[i][j].rgbtGreen = Average;
                image[i][j].rgbtRed = Average;
            }
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            BYTE originalBlue = pixel.rgbtBlue;
            BYTE originalGreen = pixel.rgbtGreen;
            BYTE originalRed = pixel.rgbtRed;

            double sepiaRed = round(0.393 * (double) originalRed + 0.769 * (double) originalGreen + 0.189 * (double) originalBlue);
            double sepiaGreen =
                round(0.349 * (double) originalRed + 0.686 * (double) originalGreen + 0.168 * (double) originalBlue);
            double sepiaBlue = round(0.272 * (double) originalRed + 0.534 * (double) originalGreen + 0.131 * (double) originalBlue);

            sepiaRed = (sepiaRed > 255) ? 255 : sepiaRed;
            sepiaGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            sepiaBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            ;
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // copy image
    RGBTRIPLE imageCopy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imageCopy[i][j] = image[i][j];
        }
    }

    // peymayesh on imageCopy
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // peymayesh on neighbours
            int currentX;
            int currentY;
            double totalRed = 0;
            double totalGreen = 0;
            double totalBlue = 0;
            int pixelCount = 0;

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    currentX = i + x;
                    currentY = j + y;

                    if (!(currentX < 0 || currentY < 0 || currentX >= height || currentY >= width))
                    {
                        totalRed += imageCopy[currentX][currentY].rgbtRed;
                        totalGreen += imageCopy[currentX][currentY].rgbtGreen;
                        totalBlue += imageCopy[currentX][currentY].rgbtBlue;
                        pixelCount++;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            image[i][j].rgbtRed = (BYTE) round(totalRed / pixelCount);
            image[i][j].rgbtGreen = (BYTE) round(totalGreen / pixelCount);
            image[i][j].rgbtBlue = (BYTE) round(totalBlue / pixelCount);
        }
    }
    return;
}
