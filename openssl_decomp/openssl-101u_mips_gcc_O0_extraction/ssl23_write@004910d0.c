
int ssl23_write(SSL *param_1,void *param_2,int param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)(*(code *)PTR___errno_location_006a99e8)();
  *puVar1 = 0;
  uVar2 = SSL_state(param_1);
  if (((uVar2 & 0x3000) == 0) || (param_1->in_handshake != 0)) {
    ssl_undefined_function(param_1);
    iVar3 = -1;
  }
  else {
    iVar3 = (*param_1->handshake_func)(param_1);
    if (-1 < iVar3) {
      if (iVar3 != 0) {
        iVar3 = SSL_write(param_1,param_2,param_3);
        return iVar3;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x79,0xe5,"s23_lib.c",0xb1);
      iVar3 = -1;
    }
  }
  return iVar3;
}

