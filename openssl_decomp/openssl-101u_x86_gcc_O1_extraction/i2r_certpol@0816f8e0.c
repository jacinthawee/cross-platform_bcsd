
undefined4 i2r_certpol(undefined4 param_1,_STACK *param_2,BIO *param_3,undefined4 param_4)

{
  ASN1_OBJECT **ppAVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    iVar2 = sk_num(param_2);
    if (iVar2 <= iVar3) break;
    ppAVar1 = (ASN1_OBJECT **)sk_value(param_2,iVar3);
    BIO_printf(param_3,"%*sPolicy: ",param_4,&DAT_081eca46);
    i2a_ASN1_OBJECT(param_3,*ppAVar1);
    BIO_puts(param_3,"\n");
    if (ppAVar1[1] != (ASN1_OBJECT *)0x0) {
      print_qualifiers();
    }
    iVar3 = iVar3 + 1;
  }
  return 1;
}

