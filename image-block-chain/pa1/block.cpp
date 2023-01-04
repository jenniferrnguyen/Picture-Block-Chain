#include "block.h"
#include <cmath>
#include <iostream>

int Block::width() const
{
/*!!!*/
    // width == the number of vectors in data 

    return data.size();
}
int Block::height() const
{
/* !!! */

    // height == the size of each vector in data 
    return data[0].size();
}

void Block::render(PNG &im, int column, int row) const
{
/* !!! */
unsigned int datax = 0;
unsigned int datay = 0;

for(int x = column; x < column + width(); x++) {
    for(int y = row; y < row + height(); y++) {
        if(x > im.width() || y > im.height()) {
            break;
        }

        // get pixel 
        RGBAPixel* pixel = im.getPixel(x,y);

        // change pixel to the right pixel from data
        *pixel = data[datax][datay];
        
        datay++;
    }
    datax++;
    datay = 0;
}
}

void Block::build(PNG &im, int column, int row, int width, int height)
{
/* YOUR CODE HERE */
// collection of vector<RGBAPixel>. Each vector element represents a column of pixels
/* block_data[0]  block_data[1]  block_data[2]
        0               0               0
        1               1               1
        2               2               2
*/ 
    vector<vector<RGBAPixel>> block_data;

    for(int x = column; x < column + width; x++) {
        vector<RGBAPixel> column_data;

        for(int y = row; y < row + height; y++) {
            RGBAPixel* px = im.getPixel(x,y);
            column_data.push_back(*px);
        }
        block_data.push_back(column_data);
    }
    data = block_data;
}

void Block::flipVert()
{
/* !!! */
vector<vector<RGBAPixel>> flip_data;

for(int x = 0; x < width(); x++) {
    vector<RGBAPixel> old_column = data[x];
    vector<RGBAPixel> flip_column;
    for (int y = height() - 1; y >= 0; y--) {
        flip_column.push_back(old_column[y]);
    }
    flip_data.push_back(flip_column);
}
data = flip_data;
}

void Block::flipHoriz()
{
/* !!! */
vector<vector<RGBAPixel>> flip_data;
for (int x = width() - 1 ; x >= 0 ; x--) {
    flip_data.push_back(data[x]);
}
data = flip_data;

}

void Block::rotateRight()
{
/* !!! */
vector<vector<RGBAPixel>> rotate_data;

for (int y = height() - 1; y >= 0; y--) {
    vector<RGBAPixel> new_column;

    for (int x = 0; x < width(); x++) {
        new_column.push_back(data[x][y]);
    }

    rotate_data.push_back(new_column);
}
data = rotate_data;
}
