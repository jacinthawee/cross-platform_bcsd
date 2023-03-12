
int ASN1_STRING_print(BIO *bp,ASN1_STRING *v)

{
  undefined *puVar1;
  uchar uVar3;
  uint uVar2;
  int iVar4;
  ASN1_STRING *pAVar5;
  int iVar6;
  uchar *puVar7;
  int iVar8;
  uchar *puVar9;
  int iVar10;
  ASN1_STRING local_7c [5];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pAVar5 = v;
  if (v == (ASN1_STRING *)0x0) {
LAB_00557b2c:
    uVar2 = 0;
  }
  else {
    iVar4 = v->length;
    puVar9 = v->data;
    if (0 < iVar4) {
      iVar10 = 0;
      iVar8 = 0;
      do {
        while( true ) {
          uVar3 = *puVar9;
          if (uVar3 == '\x7f') {
            uVar3 = '.';
          }
          else if ((((char)uVar3 < ' ') && (uVar3 != '\n')) && (uVar3 != '\r')) {
            uVar3 = '.';
          }
          iVar6 = iVar8 + 1;
          *(uchar *)((int)&local_7c[0].length + iVar8) = uVar3;
          if (0x4f < iVar6) break;
          iVar10 = iVar10 + 1;
          puVar9 = puVar9 + 1;
          iVar8 = iVar6;
          if (iVar4 <= iVar10) goto LAB_00557ac4;
        }
        pAVar5 = local_7c;
        iVar4 = (*(code *)PTR_BIO_write_006a6e14)(bp);
        if (iVar4 < 1) goto LAB_00557b2c;
        iVar4 = v->length;
        iVar10 = iVar10 + 1;
        iVar6 = 0;
        puVar9 = puVar9 + 1;
        iVar8 = iVar6;
      } while (iVar10 < iVar4);
LAB_00557ac4:
      if (iVar6 != 0) {
        pAVar5 = local_7c;
        iVar4 = (*(code *)PTR_BIO_write_006a6e14)(bp);
        uVar2 = (uint)(0 < iVar4);
        goto LAB_00557ae0;
      }
    }
    uVar2 = 1;
  }
LAB_00557ae0:
  if (local_2c == *(int *)puVar1) {
    return uVar2;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar4 = pAVar5->length;
  if (((((iVar4 < 0xc) || (puVar9 = pAVar5->data, 9 < (byte)(*puVar9 - 0x30))) ||
       ((9 < (byte)(puVar9[1] - 0x30) ||
        ((9 < (byte)(puVar9[2] - 0x30) || (9 < (byte)(puVar9[3] - 0x30))))))) ||
      (9 < (byte)(puVar9[4] - 0x30))) ||
     (((((9 < (byte)(puVar9[5] - 0x30) || (9 < (byte)(puVar9[6] - 0x30))) ||
        (9 < (byte)(puVar9[7] - 0x30))) ||
       ((9 < (byte)(puVar9[8] - 0x30) || (9 < (byte)(puVar9[9] - 0x30))))) ||
      ((9 < (byte)(puVar9[10] - 0x30) ||
       ((9 < (byte)(puVar9[0xb] - 0x30) ||
        (0xb < (((char)puVar9[4] + -0x30) * 10 + (int)(char)puVar9[5]) - 0x31U)))))))) {
    (*(code *)PTR_BIO_write_006a6e14)();
    return 0;
  }
  if (((((0xd < iVar4) && ((byte)(puVar9[0xc] - 0x30) < 10)) && ((byte)(puVar9[0xd] - 0x30) < 10))
      && ((iVar4 != 0xe && (puVar9[0xe] == '.')))) &&
     ((iVar4 != 0xf && (puVar7 = puVar9 + 0x10, (byte)(puVar9[0xf] - 0x30) < 10)))) {
    iVar8 = 1;
    do {
      iVar8 = iVar8 + 1;
      if (iVar8 == iVar4 + -0xe) break;
      uVar3 = *puVar7;
      puVar7 = puVar7 + 1;
    } while ((byte)(uVar3 - 0x30) < 10);
  }
  iVar4 = (*(code *)PTR_BIO_printf_006a6e38)();
  return (uint)(0 < iVar4);
}

