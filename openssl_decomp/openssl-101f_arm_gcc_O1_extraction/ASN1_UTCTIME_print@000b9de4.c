
int ASN1_UTCTIME_print(BIO *fp,ASN1_UTCTIME *a)

{
  byte *pbVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = a->length;
  pbVar1 = a->data;
  if (9 < iVar2) {
    if ((((((*pbVar1 - 0x30 & 0xff) < 10) && (pbVar1[1] - 0x30 < 10)) && (pbVar1[2] - 0x30 < 10)) &&
        ((((pbVar1[3] - 0x30 < 10 && (pbVar1[4] - 0x30 < 10)) &&
          ((pbVar1[5] - 0x30 < 10 && ((pbVar1[6] - 0x30 < 10 && (pbVar1[7] - 0x30 < 10)))))) &&
         (pbVar1[8] - 0x30 < 10)))) && (pbVar1[9] - 0x30 < 10)) {
      iVar5 = (pbVar1[1] - 0x30) + (*pbVar1 - 0x30) * 10;
      if (iVar5 < 0x32) {
        iVar5 = iVar5 + 100;
      }
      uVar4 = ((uint)pbVar1[3] + (pbVar1[2] - 0x30) * 10) - 0x31;
      if (uVar4 < 0xc) {
        if (((iVar2 < 0xc) || (9 < (pbVar1[10] - 0x30 & 0xff))) || (9 < (pbVar1[0xb] - 0x30 & 0xff))
           ) {
          iVar6 = 0;
        }
        else {
          iVar6 = (pbVar1[0xb] - 0x30) + (pbVar1[10] - 0x30) * 10;
        }
        pcVar3 = " GMT";
        if (pbVar1[iVar2 + -1] != 0x5a) {
          pcVar3 = "";
        }
        iVar2 = BIO_printf(fp,"%s %2d %02d:%02d:%02d %d%s",(&mon)[uVar4],
                           (pbVar1[5] - 0x30) + (pbVar1[4] - 0x30) * 10,
                           (pbVar1[7] - 0x30) + (pbVar1[6] - 0x30) * 10,
                           (pbVar1[9] - 0x30) + (pbVar1[8] - 0x30) * 10,iVar6,iVar5 + 0x76c,pcVar3);
        return (uint)(0 < iVar2);
      }
    }
  }
  BIO_write(fp,"Bad time value",0xe);
  return 0;
}

