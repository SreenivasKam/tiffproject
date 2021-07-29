----------------------------------------- Group 3  - 1D compression -----------------------------------------

Hello ,


The folder consists of the following contents,
There are a total of 8 Files in the Folder.

-------------------------------------------------------------------------------------------------------------

There are 5 textfiles, The first 4 text files listed below are used for creating the huffman tables. The 5th
file is the readme text file you are currently reading.

1.  makeup_cw_w.txt
2.  makeup_cw_b.txt
3.  terminal_cw_w.txt
4.  terminal_cw_b.txt
5.  readme.txt 

NOTE : The above files should not be modefied.

-------------------------------------------------------------------------------------------------------------

There is 1 tiff file, This is the sample tiff file on which the compression is performed.

The name of the tiff file mentioned above is "sample_uc.tiff".

NOTE : If you would like to perform 1D compression on another tiff file , Just delete or remove the existing 
tiff file from the folder and paste the tiff file you would like to perform compression on inside the folder. 
Now you must rename the tiff file you have added in the folder as "sample_uc".

-------------------------------------------------------------------------------------------------------------

There are 2 C codes namely

1.  1d_encoder.c
    This code performs 2 operations. First it extracts the tags and the Uncompressed image data from the 
    "sample_uc.tiff" tiff file. Second it performs 1D encoding on the extracted Image to produce the 
    compressed image in the form of codewords from the huffman table.

    NOTE : When you run this program , The program generates 2 additional text files in the folder.
           1. img_bin.txt - This file is created by the program to store the Uncompressed image 
                            extracted from the tiff file in the form of 0's and 1's.

           2. encoded_img_bin.txt - This file is created by the program to store the Image in its 
                                    1D encoded compressed form with codewords consisting of  0's and 1's.
    
    
           Only the tiff file with the name sample_uc will be compressed.

2.  tiff_remake.C
    This code is used to recreate a viewable compressed tiff file. This program must be edited according 
    to the Users choice. (User choice is nothing hardcoding the required tag values)
 
    Once all the tag values are updated according to the required choice. 
    Note: Important Tags to be updated are
	Tag name                    Tag Values           Description
       ImageWidth                        256             The width of the unompressed image
       Imagelength                       257		 The length of the uncompressed image
       Compression                       259             The compression values as per the compression algorithm used
       Stripoffset                       273             The offset byte value from where the image data is written
       Stripoffsetbytecount              279             The total number of bytes of the encoded data
       Rowsperstrip                      278             Number of rows in strip( 1 Full strip then this tag has similar value as Imagelength)
    
    You can now run the program.
    to generate a viewable compressed tiff file.

    NOTE : This will generate a tiff file in the same folder with the name "sample_compressed.tiff".
-------------------------------------------------------------------------------------------------------------

Thank you for using our service.