
undefined4 mime_hdr_addparam_isra_1(_STACK **param_1,byte *param_2,byte *param_3)

{
  byte *pbVar1;
  ushort **ppuVar2;
  __int32_t **pp_Var3;
  byte **data;
  ushort uVar4;
  
  if (param_2 != (byte *)0x0) {
    param_2 = (byte *)BUF_strdup((char *)param_2);
    if (param_2 == (byte *)0x0) {
      return 0;
    }
    uVar4 = (ushort)*param_2;
    if (uVar4 != 0) {
      ppuVar2 = __ctype_b_loc();
      pbVar1 = param_2;
      do {
        if ((int)((uint)(*ppuVar2)[(short)uVar4] << 0x17) < 0) {
          pp_Var3 = __ctype_tolower_loc();
          *pbVar1 = (byte)(*pp_Var3)[(short)uVar4];
        }
        uVar4 = (ushort)pbVar1[1];
        pbVar1 = pbVar1 + 1;
      } while (uVar4 != 0);
    }
  }
  if (((param_3 == (byte *)0x0) ||
      (param_3 = (byte *)BUF_strdup((char *)param_3), param_3 != (byte *)0x0)) &&
     (data = (byte **)CRYPTO_malloc(8,"asn_mime.c",0x360), data != (byte **)0x0)) {
    *data = param_2;
    data[1] = param_3;
    sk_push(*param_1,data);
    return 1;
  }
  return 0;
}

