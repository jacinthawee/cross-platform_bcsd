
undefined4 ssl_get_handshake_digest(uint param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_1 < 6) {
    iVar1 = *(int *)(ssl_handshake_digest_flag + param_1 * 4);
    *param_2 = iVar1;
    if (iVar1 != 0) {
      *param_3 = *(undefined4 *)(ssl_digest_methods + param_1 * 4);
      return 1;
    }
    *param_3 = 0;
    uVar2 = 1;
  }
  return uVar2;
}

