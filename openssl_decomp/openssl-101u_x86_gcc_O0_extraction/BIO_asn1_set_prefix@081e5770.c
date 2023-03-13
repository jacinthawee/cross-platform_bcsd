
int BIO_asn1_set_prefix(BIO *b,undefined1 *prefix,undefined1 *prefix_free)

{
  long lVar1;
  int in_GS_OFFSET;
  undefined1 *local_18;
  undefined1 *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_18 = prefix;
  local_14 = prefix_free;
  lVar1 = BIO_ctrl(b,0x95,0,&local_18);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return lVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

