
uchar * ASN1_seq_pack(stack_st_OPENSSL_BLOCK *safes,undefined1 *i2d,uchar **buf,int *len)

{
  int iVar1;
  uchar *puVar2;
  int in_GS_OFFSET;
  int line;
  uchar *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = i2d_ASN1_SET(safes,(uchar **)0x0,i2d,0x10,0,0);
  if (iVar1 == 0) {
    line = 0x5f;
    iVar1 = 0x70;
  }
  else {
    puVar2 = (uchar *)CRYPTO_malloc(iVar1,"asn_pack.c",0x62);
    if (puVar2 != (uchar *)0x0) {
      local_24 = puVar2;
      i2d_ASN1_SET(safes,&local_24,i2d,0x10,0,0);
      if (len != (int *)0x0) {
        *len = iVar1;
      }
      if (buf != (uchar **)0x0) {
        *buf = puVar2;
      }
      goto LAB_081d0cac;
    }
    line = 99;
    iVar1 = 0x41;
  }
  ERR_put_error(0xd,0x7e,iVar1,"asn_pack.c",line);
  puVar2 = (uchar *)0x0;
LAB_081d0cac:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return puVar2;
}

