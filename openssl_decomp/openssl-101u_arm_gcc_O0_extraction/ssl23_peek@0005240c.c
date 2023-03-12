
int ssl23_peek(SSL *param_1,void *param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  piVar1 = __errno_location();
  *piVar1 = 0;
  uVar2 = SSL_state(param_1);
  if (((uVar2 & 0x3000) != 0) && (param_1->in_handshake == 0)) {
    iVar3 = (*param_1->handshake_func)(param_1);
    if (-1 < iVar3) {
      if (iVar3 != 0) {
        iVar3 = SSL_peek(param_1,param_2,param_3);
        return iVar3;
      }
      ERR_put_error(0x14,0xed,0xe5,"s23_lib.c",0x9d);
      iVar3 = -1;
    }
    return iVar3;
  }
  ssl_undefined_function(param_1);
  return -1;
}

