
_STACK * ssl_bytes_to_cipher_list(int param_1,char *param_2,int param_3,_STACK **param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  int extraout_r1;
  _STACK *st;
  
  if (*(int *)(param_1 + 0x58) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x418) = 0;
  }
  iVar2 = (**(code **)(*(int *)(param_1 + 8) + 0x4c))(0,0);
  __aeabi_idivmod(param_3,iVar2);
  if (extraout_r1 != 0) {
    ERR_put_error(0x14,0xa1,0x97,"ssl_lib.c",0x59f);
    return (_STACK *)0x0;
  }
  if ((param_4 == (_STACK **)0x0) || (st = *param_4, st == (_STACK *)0x0)) {
    st = sk_new_null();
  }
  else {
    sk_zero(st);
  }
  if (0 < param_3) {
    if (iVar2 == 3) {
      do {
        if (((*(int *)(param_1 + 0x58) == 0) || (*param_2 != '\0')) ||
           ((param_2[1] != '\0' || (param_2[2] != -1)))) {
          pvVar4 = (void *)(**(code **)(*(int *)(param_1 + 8) + 0x48))(param_2);
          if ((pvVar4 != (void *)0x0) && (iVar5 = sk_push(st,pvVar4), iVar5 == 0))
          goto LAB_000611ae;
        }
        else {
          if (*(int *)(param_1 + 400) != 0) goto LAB_00061118;
          *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x418) = 1;
        }
        bVar1 = iVar2 < param_3;
        iVar2 = iVar2 + 3;
        param_2 = param_2 + 3;
      } while (bVar1);
    }
    else {
      param_2 = param_2 + iVar2;
      iVar5 = iVar2;
      do {
        while( true ) {
          if (((*(int *)(param_1 + 0x58) == 0) || (param_2[-2] != '\0')) || (param_2[-1] != -1))
          break;
          if (*(int *)(param_1 + 400) != 0) goto LAB_00061118;
          iVar5 = iVar5 + iVar2;
          *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x418) = 1;
          param_2 = param_2 + iVar2;
          if (param_3 <= iVar5 - iVar2) goto LAB_00061106;
        }
        pvVar4 = (void *)(**(code **)(*(int *)(param_1 + 8) + 0x48))((int)param_2 - iVar2);
        if ((pvVar4 != (void *)0x0) && (iVar3 = sk_push(st,pvVar4), iVar3 == 0)) goto LAB_000611ae;
        iVar5 = iVar5 + iVar2;
        param_2 = param_2 + iVar2;
      } while (iVar5 - iVar2 < param_3);
    }
  }
LAB_00061106:
  if (param_4 != (_STACK **)0x0) {
    *param_4 = st;
  }
  return st;
LAB_000611ae:
  ERR_put_error(0x14,0xa1,0x41,"ssl_lib.c",0x5c6);
  goto LAB_0006113c;
LAB_00061118:
  ERR_put_error(0x14,0xa1,0x159,"ssl_lib.c",0x5b4);
  ssl3_send_alert(param_1,2,0x28);
LAB_0006113c:
  if ((param_4 == (_STACK **)0x0) || (*param_4 == (_STACK *)0x0)) {
    sk_free(st);
  }
  return (_STACK *)0x0;
}

