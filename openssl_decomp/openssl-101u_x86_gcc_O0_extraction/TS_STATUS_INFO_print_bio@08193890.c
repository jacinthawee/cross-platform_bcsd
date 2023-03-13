
undefined4 TS_STATUS_INFO_print_bio(BIO *param_1,ASN1_INTEGER **param_2)

{
  ASN1_BIT_STRING *a;
  uint uVar1;
  ASN1_STRING *str;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  
  BIO_printf(param_1,"Status: ");
  uVar1 = ASN1_INTEGER_get(*param_2);
  if (uVar1 < 6) {
    BIO_printf(param_1,"%s\n",*(undefined4 *)(status_map_14102 + uVar1 * 4));
  }
  else {
    BIO_printf(param_1,"out of bounds\n");
  }
  BIO_printf(param_1,"Status description: ");
  iVar3 = 0;
  while( true ) {
    iVar2 = sk_num((_STACK *)param_2[1]);
    if (iVar2 <= iVar3) break;
    if (0 < iVar3) {
      BIO_puts(param_1,"\t");
    }
    str = (ASN1_STRING *)sk_value((_STACK *)param_2[1],iVar3);
    ASN1_STRING_print_ex(param_1,str,0);
    BIO_puts(param_1,"\n");
    iVar3 = iVar3 + 1;
  }
  if (iVar3 == 0) {
    BIO_printf(param_1,"unspecified\n");
  }
  BIO_printf(param_1,"Failure info: ");
  a = param_2[2];
  if ((a != (ASN1_BIT_STRING *)0x0) && (-1 < failure_map_14103._0_4_)) {
    puVar4 = failure_map_14103;
    iVar2 = 0;
    iVar3 = failure_map_14103._0_4_;
    do {
      iVar3 = ASN1_BIT_STRING_get_bit(a,iVar3);
      if (iVar3 != 0) {
        iVar2 = iVar2 + 1;
        if (iVar2 != 1) {
          BIO_printf(param_1,", ");
        }
        BIO_printf(param_1,"%s",*(int *)((int)puVar4 + 4));
      }
      puVar4 = (undefined1 *)((int)puVar4 + 8);
      iVar3 = *(int *)puVar4;
    } while (-1 < iVar3);
    if (iVar2 != 0) goto LAB_081939cb;
  }
  BIO_printf(param_1,"unspecified");
LAB_081939cb:
  BIO_printf(param_1,"\n");
  return 1;
}

