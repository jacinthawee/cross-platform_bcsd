
undefined4 ssl3_send_server_certificate(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x34) != 0x2140) {
    uVar1 = ssl3_do_write(param_1,0x16);
    return uVar1;
  }
  iVar2 = (*(code *)PTR_ssl_get_server_send_cert_006a7ff0)();
  if ((iVar2 == 0) &&
     ((iVar3 = *(int *)(*(int *)(param_1 + 0x58) + 0x344), *(int *)(iVar3 + 0x10) != 0x20 ||
      ((*(uint *)(iVar3 + 0xc) & 0x10) != 0)))) {
    uVar1 = 0xd1b;
  }
  else {
    iVar2 = ssl3_output_cert_chain(param_1,iVar2);
    if (iVar2 != 0) {
      *(int *)(param_1 + 0x44) = iVar2;
      *(undefined4 *)(param_1 + 0x48) = 0;
      *(undefined4 *)(param_1 + 0x34) = 0x2141;
      uVar1 = ssl3_do_write(param_1,0x16);
      return uVar1;
    }
    uVar1 = 0xd23;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x9a,0x44,"s3_srvr.c",uVar1);
  *(undefined4 *)(param_1 + 0x34) = 5;
  return 0;
}

