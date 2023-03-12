
_STACK * ssl_bytes_to_cipher_list(int param_1,int param_2,int param_3,_STACK **param_4)

{
  int iVar1;
  void *data;
  int iVar2;
  int extraout_r1;
  int iVar3;
  _STACK *st;
  
  if (*(int *)(param_1 + 0x58) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x418) = 0;
  }
  iVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x4c))(0,0);
  if ((iVar1 == 0) || (__aeabi_idivmod(param_3,iVar1), extraout_r1 != 0)) {
    ERR_put_error(0x14,0xa1,0x97,"ssl_lib.c",0x5a0);
    return (_STACK *)0x0;
  }
  if ((param_4 == (_STACK **)0x0) || (st = *param_4, st == (_STACK *)0x0)) {
    st = sk_new_null();
    if (st == (_STACK *)0x0) {
      ERR_put_error(0x14,0xa1,0x41,"ssl_lib.c",0x5a6);
      return (_STACK *)0x0;
    }
  }
  else {
    sk_zero(st);
  }
  if (0 < param_3) {
    param_2 = param_2 + iVar1;
    iVar3 = iVar1;
    do {
      while( true ) {
        if (*(int *)(param_1 + 0x58) != 0) break;
LAB_0005ee00:
        if ((((iVar1 == 3) && (*(char *)(param_2 + -3) != '\0')) || (*(char *)(param_2 + -2) != 'V')
            ) || (*(char *)(param_2 + -1) != '\0')) {
LAB_0005ee0c:
          data = (void *)(**(code **)(*(int *)(param_1 + 8) + 0x48))(param_2 - iVar1);
          if ((data != (void *)0x0) && (iVar2 = sk_push(st,data), iVar2 == 0)) {
            ERR_put_error(0x14,0xa1,0x41,"ssl_lib.c",0x5db);
LAB_0005ee8c:
            if ((param_4 != (_STACK **)0x0) && (*param_4 != (_STACK *)0x0)) {
              return (_STACK *)0x0;
            }
            sk_free(st);
            return (_STACK *)0x0;
          }
        }
        else {
          iVar2 = (**(code **)(*(int *)(param_1 + 8) + 0x40))(param_1,0x77,0,0);
          if (iVar2 == 0) {
            ERR_put_error(0x14,0xa1,0x175,"ssl_lib.c",0x5cd);
            if (*(int *)(param_1 + 0x58) != 0) {
              ssl3_send_alert(param_1,2,0x56);
            }
            goto LAB_0005ee8c;
          }
        }
        iVar3 = iVar3 + iVar1;
        param_2 = param_2 + iVar1;
        if (param_3 <= iVar3 - iVar1) goto LAB_0005eec2;
      }
      if ((iVar1 == 3) && (*(char *)(param_2 + -3) != '\0')) goto LAB_0005ee0c;
      if ((*(char *)(param_2 + -2) != '\0') || (*(char *)(param_2 + -1) != -1)) goto LAB_0005ee00;
      if (*(int *)(param_1 + 400) != 0) {
        ERR_put_error(0x14,0xa1,0x159,"ssl_lib.c",0x5b6);
        ssl3_send_alert(param_1,2,0x28);
        goto LAB_0005ee8c;
      }
      iVar3 = iVar3 + iVar1;
      *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x418) = 1;
      param_2 = param_2 + iVar1;
    } while (iVar3 - iVar1 < param_3);
  }
LAB_0005eec2:
  if (param_4 != (_STACK **)0x0) {
    *param_4 = st;
  }
  return st;
}

