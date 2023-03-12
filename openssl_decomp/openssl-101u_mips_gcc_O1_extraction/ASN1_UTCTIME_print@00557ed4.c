
int ASN1_UTCTIME_print(BIO *fp,ASN1_UTCTIME *a)

{
  uchar *puVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = a->length;
  if (iVar5 < 10) {
LAB_00558134:
    (*(code *)PTR_BIO_write_006a6e14)(fp,"Bad time value",0xe);
    return 0;
  }
  puVar1 = a->data;
  if ((((((9 < ((int)(char)*puVar1 - 0x30U & 0xff)) || (9 < (byte)(puVar1[1] - 0x30))) ||
        (9 < (byte)(puVar1[2] - 0x30))) ||
       ((9 < (byte)(puVar1[3] - 0x30) || (9 < (byte)(puVar1[4] - 0x30))))) ||
      ((9 < (byte)(puVar1[5] - 0x30) ||
       ((9 < (byte)(puVar1[6] - 0x30) || (9 < (byte)(puVar1[7] - 0x30))))))) ||
     ((9 < (byte)(puVar1[8] - 0x30) || (9 < (byte)(puVar1[9] - 0x30))))) goto LAB_00558134;
  iVar3 = ((int)(char)*puVar1 - 0x30U) * 10 + (char)puVar1[1] + -0x30;
  uVar4 = (((char)puVar1[2] + -0x30) * 10 + (int)(char)puVar1[3]) - 0x31;
  if (iVar3 < 0x32) {
    iVar3 = iVar3 + 100;
  }
  if (0xb < uVar4) goto LAB_00558134;
  if (0xb < iVar5) {
    iVar6 = 0;
    if (9 < ((int)(char)puVar1[10] - 0x30U & 0xff)) goto LAB_005580cc;
    if (((int)(char)puVar1[0xb] - 0x30U & 0xff) < 10) {
      iVar6 = ((int)(char)puVar1[10] - 0x30U) * 10 + ((int)(char)puVar1[0xb] - 0x30U);
      goto LAB_005580cc;
    }
  }
  iVar6 = 0;
LAB_005580cc:
  if (puVar1[iVar5 + -1] == 'Z') {
    pcVar2 = " GMT";
  }
  else {
    pcVar2 = "";
  }
  iVar5 = (*(code *)PTR_BIO_printf_006a6e38)
                    (fp,"%s %2d %02d:%02d:%02d %d%s",*(undefined4 *)(mon + uVar4 * 4),
                     ((char)puVar1[4] + -0x30) * 10 + (char)puVar1[5] + -0x30,
                     ((char)puVar1[6] + -0x30) * 10 + (char)puVar1[7] + -0x30,
                     ((char)puVar1[8] + -0x30) * 10 + (char)puVar1[9] + -0x30,iVar6,iVar3 + 0x76c,
                     pcVar2);
  return (uint)(0 < iVar5);
}

