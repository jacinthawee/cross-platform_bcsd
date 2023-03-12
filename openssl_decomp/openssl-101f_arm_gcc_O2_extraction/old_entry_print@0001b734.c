
void old_entry_print(BIO *param_1,ASN1_OBJECT *param_2,int *param_3)

{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  byte *pbVar4;
  size_t __n;
  char *pcVar6;
  byte *pbVar7;
  char local_38 [28];
  int local_1c;
  byte *pbVar5;
  
  pcVar6 = local_38;
  local_1c = __TMC_END__;
  iVar1 = i2a_ASN1_OBJECT(param_1,param_2);
  __n = 0x16 - iVar1;
  if (0 < (int)__n) {
    pvVar2 = memset(local_38,0x20,__n);
    pcVar6 = (char *)(__n + (int)pvVar2);
  }
  *pcVar6 = 0x3a;
  pcVar6[1] = 0;
  BIO_puts(param_1,local_38);
  iVar1 = param_3[1];
  if (iVar1 == 0x13) {
    BIO_printf(param_1,"PRINTABLE:\'");
  }
  else if (iVar1 == 0x14) {
    BIO_printf(param_1,"T61STRING:\'");
  }
  else if (iVar1 == 0x16) {
    BIO_printf(param_1,"IA5STRING:\'");
  }
  else if (iVar1 == 0x1c) {
    BIO_printf(param_1,"UNIVERSALSTRING:\'");
  }
  else {
    BIO_printf(param_1,"ASN.1 %2d:\'");
  }
  if (0 < *param_3) {
    pbVar7 = (byte *)param_3[2] + *param_3;
    pbVar5 = (byte *)param_3[2];
    do {
      while( true ) {
        pbVar4 = pbVar5 + 1;
        uVar3 = (uint)*pbVar5;
        pbVar5 = pbVar4;
        if (0x5e < uVar3 - 0x20) break;
        BIO_printf(param_1,"%c");
        if (pbVar4 == pbVar7) goto LAB_0001b7de;
      }
      if ((int)(uVar3 << 0x18) < 0) {
        pcVar6 = "\\0x%02X";
      }
      else {
        uVar3 = uVar3 + 0x40;
        pcVar6 = "^%c";
      }
      BIO_printf(param_1,pcVar6,uVar3);
    } while (pbVar4 != pbVar7);
  }
LAB_0001b7de:
  BIO_printf(param_1,"\'\n");
  if (local_1c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(1);
}

