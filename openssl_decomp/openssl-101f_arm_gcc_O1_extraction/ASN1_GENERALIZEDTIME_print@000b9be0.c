
int ASN1_GENERALIZEDTIME_print(BIO *fp,ASN1_GENERALIZEDTIME *a)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  
  iVar3 = a->length;
  pbVar2 = a->data;
  if (0xb < iVar3) {
    if (((((((*pbVar2 - 0x30 & 0xff) < 10) && (pbVar2[1] - 0x30 < 10)) && (pbVar2[2] - 0x30 < 10))
         && ((pbVar2[3] - 0x30 < 10 && (pbVar2[4] - 0x30 < 10)))) &&
        ((pbVar2[5] - 0x30 < 10 && ((pbVar2[6] - 0x30 < 10 && (pbVar2[7] - 0x30 < 10)))))) &&
       ((pbVar2[8] - 0x30 < 10 &&
        (((((pbVar2[9] - 0x30 & 0xff) < 10 && ((pbVar2[10] - 0x30 & 0xff) < 10)) &&
          ((pbVar2[0xb] - 0x30 & 0xff) < 10)) &&
         (uVar7 = ((uint)pbVar2[5] + (pbVar2[4] - 0x30) * 10) - 0x31, uVar7 < 0xc)))))) {
      if (((iVar3 < 0xe) || (9 < (pbVar2[0xc] - 0x30 & 0xff))) || (9 < (pbVar2[0xd] - 0x30 & 0xff)))
      {
        iVar4 = 0;
        pbVar9 = (byte *)0x0;
        iVar8 = 0;
      }
      else {
        iVar8 = (pbVar2[0xd] - 0x30) + (pbVar2[0xc] - 0x30) * 10;
        if ((iVar3 == 0xe) || (pbVar2[0xe] != 0x2e)) {
          iVar4 = 0;
          pbVar9 = (byte *)0x0;
        }
        else {
          pbVar9 = pbVar2 + 0xe;
          if ((iVar3 == 0xf) || (9 < pbVar2[0xf] - 0x30)) {
            iVar4 = 1;
          }
          else {
            iVar5 = 1;
            do {
              iVar4 = iVar5 + 1;
              if (iVar4 == iVar3 + -0xe) break;
              iVar1 = iVar5 + 0xf;
              iVar5 = iVar4;
            } while (pbVar2[iVar1] - 0x30 < 10);
          }
        }
      }
      pcVar6 = " GMT";
      if (pbVar2[iVar3 + -1] != 0x5a) {
        pcVar6 = "";
      }
      iVar3 = BIO_printf(fp,"%s %2d %02d:%02d:%02d%.*s %d%s",(&mon)[uVar7],
                         (pbVar2[7] - 0x30) + (pbVar2[6] - 0x30) * 10,
                         (pbVar2[9] - 0x30) + (pbVar2[8] - 0x30) * 10,
                         (pbVar2[0xb] - 0x30) + (pbVar2[10] - 0x30) * 10,iVar8,iVar4,pbVar9,
                         (*pbVar2 - 0x30) * 1000 + (pbVar2[1] - 0x30) * 100 +
                         (pbVar2[2] - 0x30) * 10 + (pbVar2[3] - 0x30),pcVar6);
      return (uint)(0 < iVar3);
    }
  }
  BIO_write(fp,"Bad time value",0xe);
  return 0;
}

