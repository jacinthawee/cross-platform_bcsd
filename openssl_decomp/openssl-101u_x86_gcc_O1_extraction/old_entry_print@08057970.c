
undefined4 old_entry_print(BIO *param_1,ASN1_OBJECT *param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  size_t __n;
  char *pcVar3;
  char *pcVar4;
  int in_GS_OFFSET;
  char local_39 [22];
  char acStack_23 [3];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar2 = i2a_ASN1_OBJECT(param_1,param_2);
  __n = 0x16 - iVar2;
  if ((int)__n < 1) {
    pcVar3 = local_39;
  }
  else {
    pcVar3 = local_39 + __n;
    memset(local_39,0x20,__n);
  }
  *pcVar3 = ':';
  pcVar3[1] = '\0';
  BIO_puts(param_1,local_39);
  iVar2 = param_3[1];
  if (iVar2 == 0x13) {
    BIO_printf(param_1,"PRINTABLE:\'");
  }
  else if (iVar2 == 0x14) {
    BIO_printf(param_1,"T61STRING:\'");
  }
  else if (iVar2 == 0x16) {
    BIO_printf(param_1,"IA5STRING:\'");
  }
  else if (iVar2 == 0x1c) {
    BIO_printf(param_1,"UNIVERSALSTRING:\'");
  }
  else {
    BIO_printf(param_1,"ASN.1 %2d:\'",iVar2);
  }
  pcVar4 = (char *)param_3[2];
  pcVar3 = pcVar4 + *param_3;
  if (0 < *param_3) {
    do {
      while( true ) {
        cVar1 = *pcVar4;
        iVar2 = (int)cVar1;
        if (0x5e < (byte)(cVar1 - 0x20U)) break;
        pcVar4 = pcVar4 + 1;
        BIO_printf(param_1,"%c",iVar2);
        if (pcVar4 == pcVar3) goto LAB_08057a64;
      }
      if (cVar1 < '\0') {
        BIO_printf(param_1,"\\0x%02X",iVar2);
      }
      else {
        BIO_printf(param_1,"^%c",iVar2 + 0x40);
      }
      pcVar4 = pcVar4 + 1;
    } while (pcVar4 != pcVar3);
  }
LAB_08057a64:
  BIO_printf(param_1,"\'\n");
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}

