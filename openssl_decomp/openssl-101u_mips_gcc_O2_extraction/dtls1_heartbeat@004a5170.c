
int dtls1_heartbeat(SSL *param_1)

{
  undefined *puVar1;
  uint uVar2;
  undefined *buf;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (((uint)param_1->srtp_profile & 3) == 1) {
    if (param_1->tlsext_heartbeat == 0) {
      uVar2 = SSL_state(param_1);
      if (((uVar2 & 0x3000) == 0) && (param_1->in_handshake == 0)) {
        buf = (undefined *)CRYPTO_malloc(0x25,"d1_both.c",0x687);
        *buf = 1;
        buf[1] = 0;
        puVar1 = PTR_RAND_bytes_006a7574;
        buf[2] = 0x12;
        buf[3] = (char)(param_1->tlsext_hb_pending >> 8);
        buf[4] = (char)param_1->tlsext_hb_pending;
        iVar3 = (*(code *)puVar1)(buf + 5,0x10);
        if ((iVar3 < 1) || (iVar3 = (*(code *)PTR_RAND_bytes_006a7574)(buf + 0x15,0x10), iVar3 < 1))
        {
          iVar3 = -1;
        }
        else {
          iVar3 = dtls1_write_bytes(param_1,0x18,buf,0x25);
          if (-1 < iVar3) {
            if (param_1->msg_callback != (_func_3150 *)0x0) {
              (*param_1->msg_callback)
                        (1,param_1->version,0x18,buf,0x25,param_1,param_1->msg_callback_arg);
            }
            dtls1_start_timer(param_1);
            param_1->tlsext_heartbeat = 1;
          }
        }
        CRYPTO_free(buf);
        return iVar3;
      }
      uVar5 = 0xf4;
      uVar4 = 0x673;
    }
    else {
      uVar5 = 0x16e;
      uVar4 = 0x66d;
    }
  }
  else {
    uVar5 = 0x16d;
    uVar4 = 0x667;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x131,uVar5,"d1_both.c",uVar4);
  return -1;
}

