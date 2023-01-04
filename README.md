# Picture-Block-Chain

A Linked List is a dynamic linear structure designed to hold any type of data. In this exercise, we develop and use a linked list to manipulate blocks of pixels from an image.
We have broken the image below into 9 Blocks.

![Screen Shot 2023-01-03 at 10 26 20 PM](https://user-images.githubusercontent.com/119923836/210496570-79259790-6ca4-466b-a2bf-7a6ce9c4699c.png)

Each Block is placed into a Node of a Chain, as shown here:

![Screen Shot 2023-01-03 at 10 27 12 PM](https://user-images.githubusercontent.com/119923836/210496628-2e8ca9eb-47f7-435e-8a2a-2f919682604c.png)


The Chain can be rearranged, and the image reassembled to create fascinating visual results.

## In block.cpp
int width() const; Returns the width of the current block.
int height() const; Returns the height of the current block.
void build(PNG & im, int column, int row, int width, int height); From im, grabs the rectangular block of pixels whose upper left corner is at position (column,row), whose width is width, and whose height is height.
void render(PNG & im, int column , int row) const; Draws the current block at position (column,row) in im.
void rotateRight(); This function rotates the block by 90 degrees. Assumes square blocks.
void flipVert(); This function flips the block along its center horizontal axis.
void flipHoriz(); This function flips the block along its center vertical axis.

## In chain.cpp
void clear(); Helper function for destructor and assignment operator.
void copy(const Chain & other); Helper function for copy constructor and assignment operator.
~Chain(); Destructor.
void insertBack(const Block & ndata); Insert a new node at the end of the Chain.
void reverse() reverses the order of the nodes in the Chain.
void rotate(int k); for every group of k nodes in the Chain, take the first of that group and move it to the end of the group.
void swap(int i, int j); switch the node in position i with the node in position j.
