
undefined4 dtls1_send_server_certificate(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x34) == 0x2140) {
    iVar2 = ssl_get_server_send_cert();
    if ((iVar2 == 0) &&
       ((iVar3 = *(int *)(*(int *)(param_1 + 0x58) + 0x344), *(int *)(iVar3 + 0xc) != 0x10 ||
        (*(int *)(iVar3 + 0x10) != 0x20)))) {
      ERR_put_error(0x14,0x109,0x44,"d1_srvr.c",0x63a);
      return 0;
    }
    uVar1 = dtls1_output_cert_chain(param_1,iVar2);
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0x2141;
    *(undefined4 *)(param_1 + 0x44) = uVar1;
    dtls1_buffer_message(param_1,0);
  }
  uVar1 = dtls1_do_write(param_1,0x16);
  return uVar1;
}

