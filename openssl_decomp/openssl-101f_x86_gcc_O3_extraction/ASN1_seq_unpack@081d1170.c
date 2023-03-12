
stack_st_OPENSSL_BLOCK * ASN1_seq_unpack(uchar *buf,int len,undefined1 *d2i,free_func *free_func)

{
  stack_st_OPENSSL_BLOCK *psVar1;
  int in_GS_OFFSET;
  uchar *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = buf;
  psVar1 = d2i_ASN1_SET((stack_st_OPENSSL_BLOCK **)0x0,&local_14,len,d2i,free_func,0x10,0);
  if (psVar1 == (stack_st_OPENSSL_BLOCK *)0x0) {
    ERR_put_error(0xd,0x7f,0x6e,"asn_pack.c",0x4d);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return psVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

