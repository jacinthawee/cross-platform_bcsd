
int SSL_get_wfd(SSL *s)

{
  BIO *bp;
  int in_GS_OFFSET;
  int local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = -1;
  bp = BIO_find_type(s->wbio,0x100);
  if (bp != (BIO *)0x0) {
    BIO_ctrl(bp,0x69,0,&local_14);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_14;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

