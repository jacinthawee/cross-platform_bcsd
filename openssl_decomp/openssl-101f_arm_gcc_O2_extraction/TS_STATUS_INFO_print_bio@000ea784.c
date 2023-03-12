
undefined4
TS_STATUS_INFO_print_bio(BIO *param_1,ASN1_INTEGER **param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  ASN1_STRING *str;
  int iVar2;
  int iVar3;
  int *piVar4;
  ASN1_BIT_STRING *a;
  
  BIO_printf(param_1,"Status: ",param_3,param_4,param_4);
  uVar1 = ASN1_INTEGER_get(*param_2);
  if (uVar1 < 6) {
    BIO_printf(param_1,"%s\n",(&status_map_16743)[uVar1],&status_map_16743,param_4);
  }
  else {
    BIO_printf(param_1,"out of bounds\n");
  }
  BIO_printf(param_1,"Status description: ");
  for (iVar3 = 0; iVar2 = sk_num((_STACK *)param_2[1]), iVar3 < iVar2; iVar3 = iVar3 + 1) {
    if (0 < iVar3) {
      BIO_puts(param_1,"\t");
    }
    str = (ASN1_STRING *)sk_value((_STACK *)param_2[1],iVar3);
    ASN1_STRING_print_ex(param_1,str,0);
    BIO_puts(param_1,"\n");
  }
  if (iVar3 == 0) {
    BIO_printf(param_1,"unspecified\n");
  }
  BIO_printf(param_1,"Failure info: ");
  a = param_2[2];
  if (a != (ASN1_BIT_STRING *)0x0) {
    if (-1 < failure_map_16744) {
      iVar2 = 0;
      iVar3 = failure_map_16744;
      piVar4 = &failure_map_16744;
      do {
        iVar3 = ASN1_BIT_STRING_get_bit(a,iVar3);
        if (iVar3 != 0) {
          iVar2 = iVar2 + 1;
          if (iVar2 != 1) {
            BIO_printf(param_1,", ");
          }
          BIO_printf(param_1,"%s",piVar4[1]);
        }
        iVar3 = piVar4[2];
        piVar4 = piVar4 + 2;
      } while (-1 < iVar3);
      if (iVar2 != 0) goto LAB_000ea86a;
    }
  }
  BIO_printf(param_1,"unspecified");
LAB_000ea86a:
  BIO_printf(param_1,"\n");
  return 1;
}

