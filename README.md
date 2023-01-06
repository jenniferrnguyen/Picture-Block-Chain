# Picture-Block-Chain

A Linked List is a dynamic linear structure designed to hold any type of data. In this project, a linked list is developed and used to manipulate blocks of pixels from an image.
The image below has been broken into 9 Blocks.

![Screen Shot 2023-01-03 at 10 26 20 PM](https://user-images.githubusercontent.com/119923836/210496570-79259790-6ca4-466b-a2bf-7a6ce9c4699c.png)

Each Block is placed into a Node of a Chain, as shown here:

![Screen Shot 2023-01-03 at 10 27 12 PM](https://user-images.githubusercontent.com/119923836/210496628-2e8ca9eb-47f7-435e-8a2a-2f919682604c.png)


The Chain can be rearranged, and the image reassembled to create fascinating visual results.

## In block.cpp
int width() const; Returns the width of the current block.<br />
int height() const; Returns the height of the current block.<br />
void build(PNG & im, int column, int row, int width, int height); From im, grabs the rectangular block of pixels whose upper left corner is at position (column,row), whose width is width, and whose height is height.<br />
void render(PNG & im, int column , int row) const; Draws the current block at position (column,row) in im.<br />
void rotateRight(); This function rotates the block by 90 degrees. Assumes square blocks.<br />
void flipVert(); This function flips the block along its center horizontal axis.<br />
void flipHoriz(); This function flips the block along its center vertical axis.<br />

## In chain.cpp
void clear(); Helper function for destructor and assignment operator.<br />
void copy(const Chain & other); Helper function for copy constructor and assignment operator.<br />
~Chain(); Destructor.<br />
void insertBack(const Block & ndata); Insert a new node at the end of the Chain.<br />
void reverse() reverses the order of the nodes in the Chain.<br />
void rotate(int k); for every group of k nodes in the Chain, take the first of that group and move it to the end of the group.<br />
void swap(int i, int j); switch the node in position i with the node in position j.<br />
