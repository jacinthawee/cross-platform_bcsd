
int tls1_heartbeat(SSL *param_1)

{
  undefined *puVar1;
  uint uVar2;
  undefined *buf;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (((uint)param_1->srtp_profile & 3) != 1) {
    uVar5 = 0x16d;
    uVar4 = 0xa62;
LAB_004953a4:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x13b,uVar5,"t1_lib.c",uVar4);
    return -1;
  }
  if (param_1->tlsext_heartbeat != 0) {
    uVar5 = 0x16e;
    uVar4 = 0xa68;
    goto LAB_004953a4;
  }
  uVar2 = SSL_state(param_1);
  if (((uVar2 & 0x3000) != 0) || (param_1->in_handshake != 0)) {
    uVar5 = 0xf4;
    uVar4 = 0xa6e;
    goto LAB_004953a4;
  }
  buf = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x25,"t1_lib.c",0xa82);
  *buf = 1;
  buf[1] = 0;
  puVar1 = PTR_RAND_bytes_006a7574;
  buf[2] = 0x12;
  buf[3] = (char)(param_1->tlsext_hb_pending >> 8);
  buf[4] = (char)param_1->tlsext_hb_pending;
  iVar3 = (*(code *)puVar1)(buf + 5,0x10);
  if (iVar3 < 1) {
    uVar4 = 0xa8c;
  }
  else {
    iVar3 = (*(code *)PTR_RAND_bytes_006a7574)(buf + 0x15,0x10);
    if (0 < iVar3) {
      iVar3 = ssl3_write_bytes(param_1,0x18,buf,0x25);
      if (-1 < iVar3) {
        if (param_1->msg_callback != (_func_3150 *)0x0) {
          (*param_1->msg_callback)
                    (1,param_1->version,0x18,buf,0x25,param_1,param_1->msg_callback_arg);
        }
        param_1->tlsext_heartbeat = 1;
      }
      goto LAB_00495320;
    }
    uVar4 = 0xa92;
  }
  iVar3 = -1;
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x13b,0x44,"t1_lib.c",uVar4);
LAB_00495320:
  (*(code *)PTR_CRYPTO_free_006a6e88)(buf);
  return iVar3;
}

