
int tls1_heartbeat(SSL *param_1)

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
        buf = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x25,"t1_lib.c",0xa6a);
        *buf = 1;
        buf[1] = 0;
        buf[2] = 0x12;
        puVar1 = PTR_RAND_pseudo_bytes_006a8664;
        buf[3] = (char)(param_1->tlsext_hb_pending >> 8);
        buf[4] = (char)param_1->tlsext_hb_pending;
        (*(code *)puVar1)(buf + 5,0x10);
        (*(code *)PTR_RAND_pseudo_bytes_006a8664)(buf + 0x15,0x10);
        iVar3 = ssl3_write_bytes(param_1,0x18,buf,0x25);
        if (-1 < iVar3) {
          if (param_1->msg_callback != (_func_3150 *)0x0) {
            (*param_1->msg_callback)
                      (1,param_1->version,0x18,buf,0x25,param_1,param_1->msg_callback_arg);
          }
          param_1->tlsext_heartbeat = 1;
        }
        (*(code *)PTR_CRYPTO_free_006a7f88)(buf);
        return iVar3;
      }
      uVar5 = 0xf4;
      uVar4 = 0xa58;
    }
    else {
      uVar5 = 0x16e;
      uVar4 = 0xa51;
    }
  }
  else {
    uVar5 = 0x16d;
    uVar4 = 0xa4a;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x13b,uVar5,"t1_lib.c",uVar4);
  return -1;
}

