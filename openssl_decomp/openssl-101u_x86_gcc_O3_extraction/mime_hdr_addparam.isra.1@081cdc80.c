
undefined4 __regparm3 mime_hdr_addparam_isra_1(_STACK **param_1,char *param_2,char *param_3)

{
  byte bVar1;
  byte *pbVar2;
  ushort **ppuVar3;
  __int32_t **pp_Var4;
  byte **data;
  byte *pbVar5;
  
  if (param_2 == (char *)0x0) {
    pbVar2 = (byte *)0x0;
  }
  else {
    pbVar2 = (byte *)BUF_strdup(param_2);
    if (pbVar2 == (byte *)0x0) {
      return 0;
    }
    bVar1 = *pbVar2;
    if (bVar1 != 0) {
      ppuVar3 = __ctype_b_loc();
      pbVar5 = pbVar2;
      do {
        if ((*(byte *)((int)*ppuVar3 + (uint)bVar1 * 2 + 1) & 1) != 0) {
          pp_Var4 = __ctype_tolower_loc();
          *pbVar5 = (byte)(*pp_Var4)[bVar1];
        }
        pbVar5 = pbVar5 + 1;
        bVar1 = *pbVar5;
      } while (bVar1 != 0);
    }
  }
  if (param_3 == (char *)0x0) {
    pbVar5 = (byte *)0x0;
  }
  else {
    pbVar5 = (byte *)BUF_strdup(param_3);
    if (pbVar5 == (byte *)0x0) {
      return 0;
    }
  }
  data = (byte **)CRYPTO_malloc(8,"asn_mime.c",0x360);
  if (data == (byte **)0x0) {
    return 0;
  }
  *data = pbVar2;
  data[1] = pbVar5;
  sk_push(*param_1,data);
  return 1;
}

