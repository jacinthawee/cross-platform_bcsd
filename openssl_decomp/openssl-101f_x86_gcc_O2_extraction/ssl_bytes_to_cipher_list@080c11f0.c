
_STACK * ssl_bytes_to_cipher_list(int param_1,char *param_2,int param_3,_STACK **param_4)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  char *pcVar7;
  _STACK *local_20;
  
  if (*(int *)(param_1 + 0x58) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x418) = 0;
  }
  iVar3 = (**(code **)(*(int *)(param_1 + 8) + 0x4c))(0,0);
  if (param_3 % iVar3 != 0) {
    ERR_put_error(0x14,0xa1,0x97,"ssl_lib.c",0x59f);
    return (_STACK *)0x0;
  }
  if (param_4 == (_STACK **)0x0) {
    local_20 = sk_new_null();
    if (param_3 < 1) {
      return local_20;
    }
  }
  else {
    local_20 = *param_4;
    if (local_20 == (_STACK *)0x0) {
      local_20 = sk_new_null();
    }
    else {
      sk_zero(local_20);
    }
    if (param_3 < 1) goto LAB_080c12f4;
  }
  pcVar7 = param_2 + iVar3;
  iVar6 = iVar3;
  pcVar2 = param_2;
  if (iVar3 == 3) {
    do {
      if (((*(int *)(param_1 + 0x58) == 0) || (*param_2 != '\0')) ||
         ((pcVar2[1] != '\0' || (pcVar2[2] != -1)))) {
        pvVar5 = (void *)(**(code **)(*(int *)(param_1 + 8) + 0x48))(param_2);
        if ((pvVar5 != (void *)0x0) && (iVar6 = sk_push(local_20,pvVar5), iVar6 == 0))
        goto LAB_080c1410;
      }
      else {
        if (*(int *)(param_1 + 400) != 0) goto LAB_080c1310;
        *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x418) = 1;
      }
      param_2 = param_2 + 3;
      bVar1 = iVar3 < param_3;
      iVar3 = iVar3 + 3;
      pcVar2 = pcVar2 + 3;
    } while (bVar1);
  }
  else {
    while( true ) {
      if (((*(int *)(param_1 + 0x58) == 0) || (pcVar7[-2] != '\0')) || (pcVar7[-1] != -1)) {
        pvVar5 = (void *)(**(code **)(*(int *)(param_1 + 8) + 0x48))((int)pcVar7 - iVar3);
        if ((pvVar5 != (void *)0x0) && (iVar4 = sk_push(local_20,pvVar5), iVar4 == 0))
        goto LAB_080c1410;
      }
      else {
        if (*(int *)(param_1 + 400) != 0) goto LAB_080c1310;
        *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x418) = 1;
      }
      if (param_3 <= iVar6) break;
      iVar6 = iVar6 + iVar3;
      pcVar7 = pcVar7 + iVar3;
    }
  }
  if (param_4 == (_STACK **)0x0) {
    return local_20;
  }
LAB_080c12f4:
  *param_4 = local_20;
  return local_20;
LAB_080c1410:
  ERR_put_error(0x14,0xa1,0x41,"ssl_lib.c",0x5c6);
  goto LAB_080c133e;
LAB_080c1310:
  ERR_put_error(0x14,0xa1,0x159,"ssl_lib.c",0x5b4);
  ssl3_send_alert(param_1,2,0x28);
LAB_080c133e:
  if ((param_4 == (_STACK **)0x0) || (*param_4 == (_STACK *)0x0)) {
    sk_free(local_20);
  }
  return (_STACK *)0x0;
}

