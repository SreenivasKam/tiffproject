struct TIFF_header
{
    short int format;
    short int arb;
    int offset;
};

struct IFD_entry
{
    short int tag,field_type;
    int field_count,value_offset;
    int *data;
};

struct IFD
{
    short int entry_count;
    struct IFD_entry *ifd_entry;
    int next_ifd_offset;
};

struct TIFF_header h;
struct IFD ifd1;

void main()
{
    h.format = 18761;
    h.arb = 42;
    h.offset = 8;

    ifd1.entry_count = 13;
    ifd1.ifd_entry = (struct IFD_entry*)malloc(ifd1.entry_count * sizeof(struct IFD_entry));
    

    ifd1.ifd_entry[0].tag = 256;
    ifd1.ifd_entry[0].field_type = 3;
    ifd1.ifd_entry[0].field_count = 1;
    ifd1.ifd_entry[0].value_offset = 1728;

    ifd1.ifd_entry[1].tag = 257;
    ifd1.ifd_entry[1].field_type = 3;
    ifd1.ifd_entry[1].field_count = 1;
    ifd1.ifd_entry[1].value_offset = 2707;
    
    ifd1.ifd_entry[2].tag = 258;
    ifd1.ifd_entry[2].field_type = 3;
    ifd1.ifd_entry[2].field_count = 1;
    ifd1.ifd_entry[2].value_offset = 8;

    ifd1.ifd_entry[3].tag = 259;
    ifd1.ifd_entry[3].field_type = 3;
    ifd1.ifd_entry[3].field_count = 1;
    ifd1.ifd_entry[3].value_offset = 2; //3;
    
    ifd1.ifd_entry[4].tag = 262;
    ifd1.ifd_entry[4].field_type = 3;
    ifd1.ifd_entry[4].field_count = 1;
    ifd1.ifd_entry[4].value_offset = 1;

    ifd1.ifd_entry[5].tag = 273;
    ifd1.ifd_entry[5].field_type = 4;
    ifd1.ifd_entry[5].field_count = 1;
    ifd1.ifd_entry[5].value_offset = 170; //8 + 2 + (13 * 12) + 4

    /*
    ifd1.ifd_entry[6].tag = 274;
    ifd1.ifd_entry[6].field_type = 3;
    ifd1.ifd_entry[6].field_count = 1;
    ifd1.ifd_entry[6].value_offset = 1;
    */

    ifd1.ifd_entry[6].tag = 277;
    ifd1.ifd_entry[6].field_type = 3;
    ifd1.ifd_entry[6].field_count = 1;
    ifd1.ifd_entry[6].value_offset = 1;

    ifd1.ifd_entry[7].tag = 278;
    ifd1.ifd_entry[7].field_type = 3;
    ifd1.ifd_entry[7].field_count = 1;
    ifd1.ifd_entry[7].value_offset = 1; // check this

    ifd1.ifd_entry[8].tag = 279;
    ifd1.ifd_entry[8].field_type = 4;
    ifd1.ifd_entry[8].field_count = 1;
    ifd1.ifd_entry[8].value_offset = 684032; // Check if this should be made as offset

    ifd1.ifd_entry[9].tag = 282;
    ifd1.ifd_entry[9].field_type = 5;
    ifd1.ifd_entry[9].field_count = 1;
    ifd1.ifd_entry[9].value_offset = 200;

    ifd1.ifd_entry[10].tag = 283;
    ifd1.ifd_entry[10].field_type = 5;
    ifd1.ifd_entry[10].field_count = 1;
    ifd1.ifd_entry[10].value_offset = 193;

    ifd1.ifd_entry[11].tag = 284;
    ifd1.ifd_entry[11].field_type = 3;
    ifd1.ifd_entry[11].field_count = 1;
    ifd1.ifd_entry[11].value_offset = 1;

    ifd1.ifd_entry[12].tag = 296;
    ifd1.ifd_entry[12].field_type = 3;
    ifd1.ifd_entry[12].field_count = 1;
    ifd1.ifd_entry[12].value_offset = 2;

    ifd1.next_ifd_offset = 0;

    

}

