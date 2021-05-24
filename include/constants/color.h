typedef unsigned char  BYTE;
typedef unsigned short WORD;
typedef unsigned long  DWORD;
typedef long    LONG;
#pragma pack(2)
struct Color{
	BYTE R, G, B;
	Color(){R=G=B=0;}
	Color(BYTE R, BYTE G, BYTE B)
		:R(R),G(G),B(B){}
};
