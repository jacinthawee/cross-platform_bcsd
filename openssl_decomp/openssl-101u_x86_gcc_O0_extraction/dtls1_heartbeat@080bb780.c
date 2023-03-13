
int dtls1_heartbeat(SSL *param_1)

{
  uint uVar1;
  undefined *buf;
  int iVar2;
  int line;
  
  if (((uint)param_1->srtp_profile & 3) != 1) {
    line = 0x667;
    iVar2 = 0x16d;
LAB_080bb8a2:
    ERR_put_error(0x14,0x131,iVar2,"d1_both.c",line);
    return -1;
  }
  if (param_1->tlsext_heartbeat != 0) {
    line = 0x66d;
    iVar2 = 0x16e;
    goto LAB_080bb8a2;
  }
  uVar1 = SSL_state(param_1);
  if (((uVar1 & 0x3000) != 0) || (param_1->in_handshake != 0)) {
    line = 0x673;
    iVar2 = 0xf4;
    goto LAB_080bb8a2;
  }
  buf = (undefined *)CRYPTO_malloc(0x25,"d1_both.c",0x687);
  *buf = 1;
  buf[1] = 0;
  buf[2] = 0x12;
  buf[3] = (char)(param_1->tlsext_hb_pending >> 8);
  buf[4] = (char)param_1->tlsext_hb_pending;
  iVar2 = RAND_bytes(buf + 5,0x10);
  if (0 < iVar2) {
    iVar2 = RAND_bytes(buf + 0x15,0x10);
    if (0 < iVar2) {
      iVar2 = dtls1_write_bytes(param_1,0x18,buf,0x25);
      if (-1 < iVar2) {
        if (param_1->msg_callback != (_func_3150 *)0x0) {
          (*param_1->msg_callback)
                    (1,param_1->version,0x18,buf,0x25,param_1,param_1->msg_callback_arg);
        }
        dtls1_start_timer(param_1);
        param_1->tlsext_heartbeat = 1;
      }
      goto LAB_080bb875;
    }
  }
  iVar2 = -1;
LAB_080bb875:
  CRYPTO_free(buf);
  return iVar2;
}

