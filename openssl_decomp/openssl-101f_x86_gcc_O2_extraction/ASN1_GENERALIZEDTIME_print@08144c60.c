
int ASN1_GENERALIZEDTIME_print(BIO *fp,ASN1_GENERALIZEDTIME *a)

{
  uint uVar1;
  uchar *puVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  uchar *puVar8;
  int local_28;
  
  iVar4 = a->length;
  if (0xb < iVar4) {
    puVar2 = a->data;
    if ((((((((byte)(*puVar2 - 0x30) < 10) && ((byte)(puVar2[1] - 0x30) < 10)) &&
           ((byte)(puVar2[2] - 0x30) < 10)) &&
          (((byte)(puVar2[3] - 0x30) < 10 && ((byte)(puVar2[4] - 0x30) < 10)))) &&
         (((byte)(puVar2[5] - 0x30) < 10 &&
          (((byte)(puVar2[6] - 0x30) < 10 && ((byte)(puVar2[7] - 0x30) < 10)))))) &&
        ((byte)(puVar2[8] - 0x30) < 10)) &&
       (((((byte)(puVar2[9] - 0x30) < 10 && ((byte)(puVar2[10] - 0x30) < 10)) &&
         ((byte)(puVar2[0xb] - 0x30) < 10)) &&
        (uVar1 = (char)puVar2[5] + -0x31 + ((char)puVar2[4] * 5 + -0xf0) * 2, uVar1 < 0xc)))) {
      if (((iVar4 < 0xe) || (9 < (byte)(puVar2[0xc] - 0x30))) || (9 < (byte)(puVar2[0xd] - 0x30))) {
        iVar6 = 0;
        puVar8 = (uchar *)0x0;
        local_28 = 0;
      }
      else {
        local_28 = (char)puVar2[0xd] + -0x30 + ((char)puVar2[0xc] * 5 + -0xf0) * 2;
        puVar8 = (uchar *)0x0;
        iVar6 = 0;
        if ((iVar4 != 0xe) && (puVar2[0xe] == '.')) {
          puVar8 = puVar2 + 0xe;
          if ((iVar4 == 0xf) || (9 < (byte)(puVar2[0xf] - 0x30))) {
            iVar6 = 1;
          }
          else {
            iVar7 = 1;
            do {
              iVar6 = iVar7 + 1;
              if (iVar6 == iVar4 + -0xe) break;
              iVar3 = iVar7 + 0xf;
              iVar7 = iVar6;
            } while ((byte)(puVar2[iVar3] - 0x30) < 10);
          }
        }
      }
      puVar5 = &DAT_08227b02;
      if (puVar2[iVar4 + -1] != 'Z') {
        puVar5 = &DAT_081ec74a;
      }
      iVar4 = BIO_printf(fp,"%s %2d %02d:%02d:%02d%.*s %d%s",*(undefined4 *)(mon + uVar1 * 4),
                         (char)puVar2[7] + -0x30 + ((char)puVar2[6] * 5 + -0xf0) * 2,
                         (char)puVar2[9] + -0x30 + ((char)puVar2[8] * 5 + -0xf0) * 2,
                         (char)puVar2[0xb] + -0x30 + ((char)puVar2[10] * 5 + -0xf0) * 2,local_28,
                         iVar6,puVar8,
                         ((char)*puVar2 + -0x30) * 1000 + ((char)puVar2[1] + -0x30) * 100 +
                         ((char)puVar2[2] * 5 + -0xf0) * 2 + -0x30 + (int)(char)puVar2[3],puVar5);
      return (uint)(0 < iVar4);
    }
  }
  BIO_write(fp,"Bad time value",0xe);
  return 0;
}

