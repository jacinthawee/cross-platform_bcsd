
undefined4 ssl3_send_server_certificate(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x34) != 0x2140) {
LAB_08098791:
    uVar2 = ssl3_do_write(param_1,0x16);
    return uVar2;
  }
  iVar3 = ssl_get_server_send_cert(param_1);
  if ((iVar3 == 0) &&
     ((iVar1 = *(int *)(*(int *)(param_1 + 0x58) + 0x344), *(int *)(iVar1 + 0x10) != 0x20 ||
      ((*(byte *)(iVar1 + 0xc) & 0x10) != 0)))) {
    iVar3 = 0xd1b;
  }
  else {
    iVar3 = ssl3_output_cert_chain(param_1,iVar3);
    if (iVar3 != 0) {
      *(undefined4 *)(param_1 + 0x34) = 0x2141;
      *(int *)(param_1 + 0x44) = iVar3;
      *(undefined4 *)(param_1 + 0x48) = 0;
      goto LAB_08098791;
    }
    iVar3 = 0xd23;
  }
  ERR_put_error(0x14,0x9a,0x44,"s3_srvr.c",iVar3);
  *(undefined4 *)(param_1 + 0x34) = 5;
  return 0;
}

