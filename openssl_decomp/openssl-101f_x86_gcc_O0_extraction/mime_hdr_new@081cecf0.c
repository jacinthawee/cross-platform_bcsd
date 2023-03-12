
byte ** __regparm3 mime_hdr_new(char *param_1,char *param_2)

{
  byte bVar1;
  ushort **ppuVar2;
  __int32_t **pp_Var3;
  byte **ppbVar4;
  _STACK *p_Var5;
  byte *pbVar6;
  byte *pbVar7;
  byte *local_20;
  
  if (param_1 == (char *)0x0) {
    local_20 = (byte *)0x0;
  }
  else {
    local_20 = (byte *)BUF_strdup(param_1);
    if (local_20 == (byte *)0x0) {
      return (byte **)0x0;
    }
    bVar1 = *local_20;
    if (bVar1 != 0) {
      ppuVar2 = __ctype_b_loc();
      pbVar6 = local_20;
      do {
        if ((*(byte *)((int)*ppuVar2 + (uint)bVar1 * 2 + 1) & 1) != 0) {
          pp_Var3 = __ctype_tolower_loc();
          *pbVar6 = (byte)(*pp_Var3)[bVar1];
        }
        pbVar6 = pbVar6 + 1;
        bVar1 = *pbVar6;
      } while (bVar1 != 0);
    }
  }
  if (param_2 == (char *)0x0) {
    pbVar6 = (byte *)0x0;
  }
  else {
    pbVar6 = (byte *)BUF_strdup(param_2);
    if (pbVar6 == (byte *)0x0) {
      return (byte **)0x0;
    }
    bVar1 = *pbVar6;
    if (bVar1 != 0) {
      ppuVar2 = __ctype_b_loc();
      pbVar7 = pbVar6;
      do {
        if ((*(byte *)((int)*ppuVar2 + (uint)bVar1 * 2 + 1) & 1) != 0) {
          pp_Var3 = __ctype_tolower_loc();
          *pbVar7 = (byte)(*pp_Var3)[bVar1];
        }
        pbVar7 = pbVar7 + 1;
        bVar1 = *pbVar7;
      } while (bVar1 != 0);
    }
  }
  ppbVar4 = (byte **)CRYPTO_malloc(0xc,"asn_mime.c",0x339);
  if (ppbVar4 != (byte **)0x0) {
    ppbVar4[1] = pbVar6;
    *ppbVar4 = local_20;
    p_Var5 = sk_new(mime_param_cmp);
    ppbVar4[2] = (byte *)p_Var5;
    if (p_Var5 != (_STACK *)0x0) {
      return ppbVar4;
    }
  }
  return (byte **)0x0;
}

