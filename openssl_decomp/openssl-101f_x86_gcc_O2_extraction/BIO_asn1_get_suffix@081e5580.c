
int BIO_asn1_get_suffix(BIO *b,undefined1 **psuffix,undefined1 **psuffix_free)

{
  long lVar1;
  int in_GS_OFFSET;
  undefined1 *local_18;
  undefined1 *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  lVar1 = BIO_ctrl(b,0x98,0,&local_18);
  if (0 < lVar1) {
    *psuffix = local_18;
    *psuffix_free = local_14;
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return lVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

