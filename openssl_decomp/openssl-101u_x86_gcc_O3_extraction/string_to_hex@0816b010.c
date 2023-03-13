
uchar * string_to_hex(char *str,long *len)

{
  ushort *puVar1;
  size_t sVar2;
  byte *ptr;
  ushort **ppuVar3;
  __int32_t **pp_Var4;
  byte bVar5;
  uint uVar6;
  byte bVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte *pbVar10;
  int iVar11;
  int line;
  
  if (str == (char *)0x0) {
    line = 0x1ba;
    iVar11 = 0x6b;
  }
  else {
    sVar2 = strlen(str);
    ptr = (byte *)CRYPTO_malloc((int)sVar2 >> 1,"v3_utl.c",0x1bd);
    pbVar10 = ptr;
    if (ptr != (byte *)0x0) {
      while (bVar7 = *str, pbVar8 = (byte *)str, pbVar9 = pbVar10, bVar7 != 0) {
        while( true ) {
          uVar6 = (uint)bVar7;
          str = (char *)(pbVar8 + 1);
          pbVar10 = pbVar9;
          if (bVar7 == 0x3a) break;
          bVar7 = pbVar8[1];
          if (bVar7 == 0) {
            ERR_put_error(0x22,0x71,0x70,"v3_utl.c",0x1cb);
            CRYPTO_free(ptr);
            return (uchar *)0x0;
          }
          ppuVar3 = __ctype_b_loc();
          puVar1 = *ppuVar3;
          if ((*(byte *)((int)puVar1 + uVar6 * 2 + 1) & 1) != 0) {
            pp_Var4 = __ctype_tolower_loc();
            uVar6 = (uint)*(byte *)(*pp_Var4 + uVar6);
          }
          if ((*(byte *)((int)puVar1 + (uint)bVar7 * 2 + 1) & 1) != 0) {
            pp_Var4 = __ctype_tolower_loc();
            bVar7 = *(byte *)(*pp_Var4 + bVar7);
          }
          iVar11 = uVar6 - 0x30;
          if (9 < (byte)iVar11) {
            if ((byte)((char)uVar6 + 0x9fU) < 6) {
              iVar11 = uVar6 - 0x57;
              goto LAB_0816b0e0;
            }
LAB_0816b178:
            CRYPTO_free(ptr);
            line = 0x1f2;
            iVar11 = 0x71;
            goto LAB_0816b192;
          }
LAB_0816b0e0:
          bVar5 = bVar7 - 0x30;
          if (9 < bVar5) {
            if (5 < (byte)(bVar7 + 0x9f)) goto LAB_0816b178;
            bVar5 = bVar7 + 0xa9;
          }
          pbVar10 = pbVar9 + 1;
          *pbVar9 = (byte)(iVar11 << 4) | bVar5;
          bVar7 = pbVar8[2];
          pbVar8 = pbVar8 + 2;
          pbVar9 = pbVar10;
          if (bVar7 == 0) goto LAB_0816b10f;
        }
      }
LAB_0816b10f:
      if (len != (long *)0x0) {
        *len = (int)pbVar10 - (int)ptr;
      }
      return ptr;
    }
    line = 0x1ed;
    iVar11 = 0x41;
  }
LAB_0816b192:
  ERR_put_error(0x22,0x71,iVar11,"v3_utl.c",line);
  return (uchar *)0x0;
}

