
uchar * string_to_hex(char *str,long *len)

{
  int iVar1;
  byte *pbVar2;
  int *piVar3;
  byte bVar5;
  undefined4 uVar4;
  uint uVar6;
  undefined4 uVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte *pbVar10;
  uint uVar11;
  uint uVar12;
  
  if (str == (char *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x71,0x6b,"v3_utl.c",0x1ba);
    pbVar2 = (byte *)0x0;
  }
  else {
    iVar1 = (*(code *)PTR_strlen_006a9a24)();
    pbVar2 = (byte *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar1 >> 1,"v3_utl.c",0x1bd);
    pbVar10 = pbVar2;
    if (pbVar2 == (byte *)0x0) {
      uVar7 = 0x41;
      uVar4 = 0x1ed;
LAB_0058b148:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x71,uVar7,"v3_utl.c",uVar4);
      return (uchar *)0x0;
    }
    while (uVar11 = (uint)(byte)*str, pbVar8 = (byte *)str, pbVar9 = pbVar10, uVar11 != 0) {
      while (str = (char *)(pbVar8 + 1), pbVar10 = pbVar9, uVar11 != 0x3a) {
        uVar12 = (uint)pbVar8[1];
        pbVar8 = pbVar8 + 2;
        if (uVar12 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x71,0x70,"v3_utl.c",0x1cb);
          (*(code *)PTR_CRYPTO_free_006a6e88)(pbVar2);
          return (uchar *)0x0;
        }
        piVar3 = (int *)(*(code *)PTR___ctype_b_loc_006a9938)();
        iVar1 = *piVar3;
        if ((*(ushort *)(iVar1 + uVar11 * 2) & 1) != 0) {
          piVar3 = (int *)(*(code *)PTR___ctype_tolower_loc_006a9940)();
          uVar11 = (uint)*(byte *)(*piVar3 + uVar11 * 4 + 3);
        }
        if ((*(ushort *)(iVar1 + uVar12 * 2) & 1) != 0) {
          piVar3 = (int *)(*(code *)PTR___ctype_tolower_loc_006a9940)();
          uVar12 = (uint)*(byte *)(*piVar3 + uVar12 * 4 + 3);
        }
        uVar6 = uVar11 - 0x30 & 0xff;
        if (9 < uVar6) {
          if (uVar11 - 0x61 < 6) {
            uVar6 = uVar11 - 0x57 & 0xff;
            goto LAB_0058b038;
          }
LAB_0058b124:
          (*(code *)PTR_CRYPTO_free_006a6e88)(pbVar2);
          uVar7 = 0x71;
          uVar4 = 0x1f2;
          goto LAB_0058b148;
        }
LAB_0058b038:
        uVar11 = uVar12 - 0x30 & 0xff;
        bVar5 = (byte)uVar11;
        if ((9 < uVar11) && (bVar5 = (char)uVar12 + 0xa9, 5 < uVar12 - 0x61)) goto LAB_0058b124;
        pbVar10 = pbVar9 + 1;
        *pbVar9 = (byte)(uVar6 << 4) | bVar5;
        uVar11 = (uint)*pbVar8;
        pbVar9 = pbVar10;
        if (uVar11 == 0) goto LAB_0058b078;
      }
    }
LAB_0058b078:
    if (len != (long *)0x0) {
      *len = (int)pbVar10 - (int)pbVar2;
    }
  }
  return pbVar2;
}

