
int tls1_heartbeat(SSL *param_1)

{
  uint uVar1;
  undefined *buf;
  int iVar2;
  
  if (((uint)param_1->srtp_profile & 3) == 1) {
    if (param_1->tlsext_heartbeat == 0) {
      uVar1 = SSL_state(param_1);
      if (((uVar1 & 0x3000) == 0) && (param_1->in_handshake == 0)) {
        buf = (undefined *)CRYPTO_malloc(0x25,"t1_lib.c",0xa6a);
        buf[1] = 0;
        *buf = 1;
        buf[2] = 0x12;
        buf[3] = (char)(param_1->tlsext_hb_pending >> 8);
        buf[4] = (char)param_1->tlsext_hb_pending;
        RAND_pseudo_bytes(buf + 5,0x10);
        RAND_pseudo_bytes(buf + 0x15,0x10);
        iVar2 = ssl3_write_bytes(param_1,0x18,buf,0x25);
        if (-1 < iVar2) {
          if (param_1->msg_callback != (_func_3150 *)0x0) {
            (*param_1->msg_callback)
                      (1,param_1->version,0x18,buf,0x25,param_1,param_1->msg_callback_arg);
          }
          param_1->tlsext_heartbeat = 1;
        }
        CRYPTO_free(buf);
      }
      else {
        ERR_put_error(0x14,0x13b,0xf4,"t1_lib.c",0xa58);
        iVar2 = -1;
      }
    }
    else {
      ERR_put_error(0x14,0x13b,0x16e,"t1_lib.c",0xa51);
      iVar2 = -1;
    }
  }
  else {
    ERR_put_error(0x14,0x13b,0x16d,"t1_lib.c",0xa4a);
    iVar2 = -1;
  }
  return iVar2;
}

