
undefined4 i2r_pci(undefined4 param_1,ASN1_INTEGER **param_2,BIO *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  puVar3 = &DAT_081ec74a;
  uVar2 = param_4;
  BIO_printf(param_3,"%*sPath Length Constraint: ",param_4,&DAT_081ec74a);
  if (*param_2 == (ASN1_INTEGER *)0x0) {
    BIO_printf(param_3,"infinite",uVar2,puVar3);
  }
  else {
    i2a_ASN1_INTEGER(param_3,*param_2);
  }
  BIO_puts(param_3,"\n");
  BIO_printf(param_3,"%*sPolicy Language: ",param_4,&DAT_081ec74a);
  i2a_ASN1_OBJECT(param_3,(ASN1_OBJECT *)param_2[1]->length);
  BIO_puts(param_3,"\n");
  if ((param_2[1]->type != 0) && (iVar1 = *(int *)(param_2[1]->type + 8), iVar1 != 0)) {
    BIO_printf(param_3,"%*sPolicy Text: %s\n",param_4,&DAT_081ec74a,iVar1);
  }
  return 1;
}

