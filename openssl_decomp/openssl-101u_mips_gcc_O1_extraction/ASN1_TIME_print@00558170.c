
int ASN1_TIME_print(BIO *fp,ASN1_TIME *a)

{
  uchar uVar1;
  uchar *puVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  undefined4 in_a3;
  uchar *puVar6;
  int iVar7;
  int iVar8;
  uchar *puVar9;
  
  if (a->type == 0x17) {
    iVar5 = ASN1_UTCTIME_print(fp,a);
    return iVar5;
  }
  if (a->type != 0x18) {
    (*(code *)PTR_BIO_write_006a6e14)(fp,"Bad time value",0xe,in_a3,&_gp);
    return 0;
  }
  iVar5 = a->length;
  if (0xb < iVar5) {
    puVar2 = a->data;
    if (((((((((int)(char)*puVar2 - 0x30U & 0xff) < 10) && ((byte)(puVar2[1] - 0x30) < 10)) &&
           ((byte)(puVar2[2] - 0x30) < 10)) &&
          (((byte)(puVar2[3] - 0x30) < 10 && ((byte)(puVar2[4] - 0x30) < 10)))) &&
         (((byte)(puVar2[5] - 0x30) < 10 &&
          (((byte)(puVar2[6] - 0x30) < 10 && ((byte)(puVar2[7] - 0x30) < 10)))))) &&
        ((byte)(puVar2[8] - 0x30) < 10)) &&
       ((((byte)(puVar2[9] - 0x30) < 10 && ((byte)(puVar2[10] - 0x30) < 10)) &&
        ((byte)(puVar2[0xb] - 0x30) < 10)))) {
      uVar3 = (((char)puVar2[4] + -0x30) * 10 + (int)(char)puVar2[5]) - 0x31;
      if (uVar3 < 0xc) {
        if (((iVar5 < 0xe) || (9 < ((int)(char)puVar2[0xc] - 0x30U & 0xff))) ||
           (9 < ((int)(char)puVar2[0xd] - 0x30U & 0xff))) {
          puVar9 = (uchar *)0x0;
          iVar8 = 0;
          iVar7 = 0;
        }
        else {
          iVar7 = ((int)(char)puVar2[0xc] - 0x30U) * 10 + ((int)(char)puVar2[0xd] - 0x30U);
          if ((iVar5 == 0xe) || (puVar2[0xe] != '.')) {
            iVar8 = 0;
            puVar9 = (uchar *)0x0;
          }
          else {
            puVar9 = puVar2 + 0xe;
            if ((iVar5 == 0xf) || (puVar6 = puVar2 + 0x10, 9 < (byte)(puVar2[0xf] - 0x30))) {
              iVar8 = 1;
            }
            else {
              iVar8 = 1;
              do {
                iVar8 = iVar8 + 1;
                if (iVar8 == iVar5 + -0xe) break;
                uVar1 = *puVar6;
                puVar6 = puVar6 + 1;
              } while ((byte)(uVar1 - 0x30) < 10);
            }
          }
        }
        if (puVar2[iVar5 + -1] == 'Z') {
          pcVar4 = " GMT";
        }
        else {
          pcVar4 = "";
        }
        iVar5 = (*(code *)PTR_BIO_printf_006a6e38)
                          (fp,"%s %2d %02d:%02d:%02d%.*s %d%s",*(undefined4 *)(mon + uVar3 * 4),
                           ((char)puVar2[6] + -0x30) * 10 + (char)puVar2[7] + -0x30,
                           ((char)puVar2[8] + -0x30) * 10 + (char)puVar2[9] + -0x30,
                           ((char)puVar2[10] + -0x30) * 10 + (char)puVar2[0xb] + -0x30,iVar7,iVar8,
                           puVar9,((char)puVar2[1] + -0x30) * 100 +
                                  ((int)(char)*puVar2 - 0x30U) * 1000 +
                                  ((char)puVar2[2] + -0x30) * 10 + (char)puVar2[3] + -0x30,pcVar4);
        return (uint)(0 < iVar5);
      }
    }
  }
  (*(code *)PTR_BIO_write_006a6e14)(fp,"Bad time value",0xe);
  return 0;
}

