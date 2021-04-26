#include <reg52.h>
#define KEYPORT P3
bit IsKeyInput()
{
	unsigned char temp;
	KEYPORT=0x0f;
	temp=KEYPORT;
	temp &=0x0f;
	if(temp==0x0f)
	{
		return 0;
	}
	else
		return 1;
}
unsigned char KeyScan(void)
{
		unsigned char row_code=0;
	unsigned char column_code=0;
		unsigned char scan_code=0;
			unsigned char i;
				unsigned char temp;
			for(i=0;i<4;++i){
			 KEYPORT=scan_code;
				temp=KEYPORT;
				if((temp&0x0f)==0x0f){
					scan_node=(scan_code>>1)|0x80;
					++column_code;
			}
				else{
					switch(temp&0x0f){
						case 0x0e:row_code=1;
						break;
						case 0x0d:row_code=5;
						break;
						case 0x0b:row_code=9;
						break;
						case 0x07:row_code=13;
						break;
						
					}
					break;
				
				}
				return row_code+column_code;
}
/*unsigned char KeyScan(void)
	{
		unsigned char keycode=0xFF;
		KEYPORT=0x7F;
		if(KEYPROT==0x7E)		keycode=1;
	if(KEYPROT==0x7D)			keycode=5;
	if(KEYPROT==0x7B)			keycode=9;
		if(KEYPROT==0x77)		keycode=13;
		KEYPORT=0xBF;
		if(KEYPROT==0xBE)		keycode=2;
	if(KEYPROT==0xBD)			keycode=6;
	if(KEYPROT==0xBB)			keycode=10;
		if(KEYPROT==0xB7)		keycode=14;
		KEYPORT=0xDF;
			if(KEYPROT==0xDE)		keycode=3;
	if(KEYPROT==0xDD)			keycode=7;
	if(KEYPROT==0xDB)			keycode=11;
		if(KEYPROT==0xD7)		keycode=15;
		KEYPROT=0xEF;
		if(KEYPROT==0xEE)		keycode=4;
	if(KEYPROT==0xED)			keycode=8;
	if(KEYPROT==0xEB)			keycode=12;
		if(KEYPROT==0xE7)		keycode=16;
		return keycode;
	}
	*/
void main(void){
	unsigned char KeyCode;
	while(1){
	while(!IsKeyInput()){;}
		DelayMs(10);
		if(!IsKeyInput()){
		P1=0x00;
			
		}
		else{
		KeyCode=KeyScan();
			WaitKeyRelease();
			P1=~KeyCode();
		}
	}
}
