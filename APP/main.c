u8 return_key(){
	
	u8 key=0xff ;
	do
	{
		key=KEYPAD_u8GetKey() ;
	} while (key==0xff);
	
	return key ;
}



u8  cal(u8 op1 ,u8 op2 ,u8 op){
	
	u8 result=0 ;
	switch(op){
		
		case '+' :result= op1+op2 ; break;
		case '-' :result= op1-op2 ; break;
		case '*' :result= op1*op2 ; break;
		case '/' :result= op1/op2 ; break;
		
		
	}
	
	return result ;
}

int main(void)
{
	
	u8 op1 ,op2 ,op, result=0 ;
	u8 key=0xff ;
	
	/* lcd init */
	
	DIO_voidSetPortDir(DIO_PORTA,0xFF) ;
	LCD_voidInit() ;
	
	/* KEYPAD INIT */
	KEYPAD_voidInit() ;

	while (1)
	{
		
		op1=return_key() ;
		LCD_voidGotoxy(0,0) ;
		LCD_voidSendNumber(op1) ;
		op=return_key() ;
		LCD_voidGotoxy(1,0) ;
		LCD_voidSendData(op) ;
		op2=return_key() ;
		LCD_voidGotoxy(2,0) ;
		LCD_voidSendNumber(op2) ;
		
		result=cal(op1,op2,op) ;
		
		key=return_key() ;
		
		if (key=='=')
		{
			LCD_voidGotoxy(3,0) ;
			LCD_voidSendData('=') ;
			LCD_voidGotoxy(4,0) ;
			LCD_voidSendNumber(result) ;
		}
		
		key=return_key() ;
		
		if(key=='c'){
			
			LCD_voidSendCommand(1) ;
		}
		
		
		
		
		
		
	}
}
