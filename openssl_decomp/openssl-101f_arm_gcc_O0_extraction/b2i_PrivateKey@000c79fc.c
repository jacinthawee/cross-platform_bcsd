
EVP_PKEY * b2i_PrivateKey(uchar **in,long length)

{
  uint uVar1;
  EVP_PKEY *pEVar2;
  int line;
  uint uVar3;
  uchar *local_1c [2];
  
  local_1c[0] = *in;
  if ((uint)length < 0x10) goto LAB_000c7a1a;
  if (*local_1c[0] == '\x06') {
    line = 0x98;
  }
  else {
    if (*local_1c[0] != '\a') goto LAB_000c7a1a;
    if (local_1c[0][1] != '\x02') {
      ERR_put_error(9,0x86,0x75,"pvkfmt.c",0xad);
      goto LAB_000c7a1a;
    }
    uVar1 = (uint)local_1c[0][10] << 0x10 | (uint)local_1c[0][9] << 8 | (uint)local_1c[0][8] |
            (uint)local_1c[0][0xb] << 0x18;
    uVar3 = (uint)local_1c[0][0xe] << 0x10 | (uint)local_1c[0][0xd] << 8 | (uint)local_1c[0][0xc] |
            (uint)local_1c[0][0xf] << 0x18;
    if (uVar1 != 0x31535344) {
      if (uVar1 < 0x31535345) {
        if (uVar1 == 0x31415352) goto LAB_000c7aba;
      }
      else {
        if (uVar1 == 0x32415352) {
          if ((uVar3 + 0xf >> 4) * 5 + ((uVar3 + 7 >> 3) + 2) * 2 <= length - 0x10U) {
            local_1c[0] = local_1c[0] + 0x10;
            pEVar2 = (EVP_PKEY *)b2i_rsa_isra_1(local_1c,uVar3,0);
            return pEVar2;
          }
LAB_000c7b2e:
          local_1c[0] = local_1c[0] + 0x10;
          ERR_put_error(9,0x84,0x7b,"pvkfmt.c",0x105);
          return (EVP_PKEY *)0x0;
        }
        if (uVar1 == 0x32535344) {
          if (((uVar3 + 7 >> 3) + 0x20) * 2 <= length - 0x10U) {
            local_1c[0] = local_1c[0] + 0x10;
            pEVar2 = (EVP_PKEY *)b2i_dss_isra_0(local_1c,uVar3,0);
            return pEVar2;
          }
          goto LAB_000c7b2e;
        }
      }
      ERR_put_error(9,0x86,0x74,"pvkfmt.c",0xcf);
      goto LAB_000c7a1a;
    }
LAB_000c7aba:
    line = 0xbe;
  }
  ERR_put_error(9,0x86,0x77,"pvkfmt.c",line);
LAB_000c7a1a:
  ERR_put_error(9,0x84,0x7a,"pvkfmt.c",0xff);
  return (EVP_PKEY *)0x0;
}

