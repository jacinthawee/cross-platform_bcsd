
int ASN1_UTCTIME_print(BIO *fp,ASN1_UTCTIME *a)

{
  uint uVar1;
  uchar *puVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = a->length;
  if (9 < iVar4) {
    puVar2 = a->data;
    if ((((((byte)(*puVar2 - 0x30) < 10) && ((byte)(puVar2[1] - 0x30) < 10)) &&
         ((byte)(puVar2[2] - 0x30) < 10)) &&
        (((((byte)(puVar2[3] - 0x30) < 10 && ((byte)(puVar2[4] - 0x30) < 10)) &&
          (((byte)(puVar2[5] - 0x30) < 10 &&
           (((byte)(puVar2[6] - 0x30) < 10 && ((byte)(puVar2[7] - 0x30) < 10)))))) &&
         ((byte)(puVar2[8] - 0x30) < 10)))) && ((byte)(puVar2[9] - 0x30) < 10)) {
      iVar5 = (char)puVar2[1] + -0x30 + ((char)*puVar2 * 5 + -0xf0) * 2;
      if (iVar5 < 0x32) {
        iVar5 = iVar5 + 100;
      }
      uVar1 = (char)puVar2[3] + -0x31 + ((char)puVar2[2] * 5 + -0xf0) * 2;
      if (uVar1 < 0xc) {
        iVar6 = 0;
        if (((0xb < iVar4) && ((byte)(puVar2[10] - 0x30) < 10)) && ((byte)(puVar2[0xb] - 0x30) < 10)
           ) {
          iVar6 = (char)puVar2[0xb] + -0x30 + ((char)puVar2[10] * 5 + -0xf0) * 2;
        }
        puVar3 = &DAT_08227d62;
        if (puVar2[iVar4 + -1] != 'Z') {
          puVar3 = &DAT_081eca46;
        }
        iVar4 = BIO_printf(fp,"%s %2d %02d:%02d:%02d %d%s",*(undefined4 *)(mon + uVar1 * 4),
                           (char)puVar2[5] + -0x30 + ((char)puVar2[4] * 5 + -0xf0) * 2,
                           (char)puVar2[7] + -0x30 + ((char)puVar2[6] * 5 + -0xf0) * 2,
                           (char)puVar2[9] + -0x30 + ((char)puVar2[8] * 5 + -0xf0) * 2,iVar6,
                           iVar5 + 0x76c,puVar3);
        return (uint)(0 < iVar4);
      }
    }
  }
  BIO_write(fp,"Bad time value",0xe);
  return 0;
}

