
int BIO_asn1_get_prefix(BIO *b,undefined1 **pprefix,undefined1 **pprefix_free)

{
  long lVar1;
  int in_GS_OFFSET;
  undefined1 *local_18;
  undefined1 *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  lVar1 = BIO_ctrl(b,0x96,0,&local_18);
  if (0 < lVar1) {
    *pprefix = local_18;
    *pprefix_free = local_14;
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return lVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}
