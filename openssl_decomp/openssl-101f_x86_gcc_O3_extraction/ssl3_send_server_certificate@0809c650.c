
undefined4 ssl3_send_server_certificate(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x34) == 0x2140) {
    iVar3 = ssl_get_server_send_cert(param_1);
    if ((iVar3 == 0) &&
       ((iVar1 = *(int *)(*(int *)(param_1 + 0x58) + 0x344), *(int *)(iVar1 + 0x10) != 0x20 ||
        ((*(byte *)(iVar1 + 0xc) & 0x10) != 0)))) {
      ERR_put_error(0x14,0x9a,0x44,"s3_srvr.c",0xd0a);
      return 0;
    }
    uVar2 = ssl3_output_cert_chain(param_1,iVar3);
    *(undefined4 *)(param_1 + 0x34) = 0x2141;
    *(undefined4 *)(param_1 + 0x44) = uVar2;
    *(undefined4 *)(param_1 + 0x48) = 0;
  }
  uVar2 = ssl3_do_write(param_1,0x16);
  return uVar2;
}

