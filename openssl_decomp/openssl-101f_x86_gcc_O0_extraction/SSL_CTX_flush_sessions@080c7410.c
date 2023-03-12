
void SSL_CTX_flush_sessions(SSL_CTX *ctx,long tm)

{
  ulong uVar1;
  int in_GS_OFFSET;
  SSL_CTX *local_1c;
  long local_18;
  _LHASH *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_1c = ctx;
  local_14 = (_LHASH *)ctx->sessions;
  if (local_14 != (_LHASH *)0x0) {
    local_18 = tm;
    CRYPTO_lock(tm,9,&DAT_0000000c,(int)"ssl_sess.c");
    uVar1 = local_14->down_load;
    local_14->down_load = 0;
    lh_doall_arg(local_14,timeout_LHASH_DOALL_ARG,&local_1c);
    local_14->down_load = uVar1;
    CRYPTO_lock((int)local_14,10,&DAT_0000000c,(int)"ssl_sess.c");
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

