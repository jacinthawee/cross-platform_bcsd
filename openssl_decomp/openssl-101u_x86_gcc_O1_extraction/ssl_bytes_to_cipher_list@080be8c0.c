
_STACK * ssl_bytes_to_cipher_list(int param_1,char *param_2,int param_3,_STACK **param_4)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  void *data;
  int iVar4;
  char *pcVar5;
  int local_24;
  _STACK *local_20;
  
  if (*(int *)(param_1 + 0x58) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x418) = 0;
  }
  iVar3 = (**(code **)(*(int *)(param_1 + 8) + 0x4c))(0,0);
  if ((iVar3 == 0) || (param_3 % iVar3 != 0)) {
    iVar4 = 0x5a0;
    iVar3 = 0x97;
LAB_080beb22:
    ERR_put_error(0x14,0xa1,iVar3,"ssl_lib.c",iVar4);
    return (_STACK *)0x0;
  }
  pcVar5 = param_2;
  local_24 = iVar3;
  if ((param_4 == (_STACK **)0x0) || (local_20 = *param_4, local_20 == (_STACK *)0x0)) {
    local_20 = sk_new_null();
    if (local_20 == (_STACK *)0x0) {
      iVar4 = 0x5a6;
      iVar3 = 0x41;
      goto LAB_080beb22;
    }
    if (0 < param_3) goto LAB_080be99c;
  }
  else {
    sk_zero(local_20);
    if (param_3 < 1) goto LAB_080beaf4;
LAB_080be99c:
    do {
      pcVar5 = pcVar5 + iVar3;
      if (*(int *)(param_1 + 0x58) == 0) {
        if ((iVar3 != 3) || (*param_2 == '\0')) {
LAB_080be9ed:
          cVar1 = pcVar5[-2];
joined_r0x080be9f4:
          if ((cVar1 == 'V') && (pcVar5[-1] == '\0')) {
            iVar4 = (**(code **)(*(int *)(param_1 + 8) + 0x40))(param_1,0x77,0,0);
            if (iVar4 == 0) {
              ERR_put_error(0x14,0xa1,0x175,"ssl_lib.c",0x5cd);
              if (*(int *)(param_1 + 0x58) != 0) {
                ssl3_send_alert(param_1,2,0x56);
              }
              goto LAB_080bea9e;
            }
            goto LAB_080be982;
          }
        }
LAB_080be959:
        data = (void *)(**(code **)(*(int *)(param_1 + 8) + 0x48))(param_2);
        if ((data != (void *)0x0) && (iVar4 = sk_push(local_20,data), iVar4 == 0)) {
          ERR_put_error(0x14,0xa1,0x41,"ssl_lib.c",0x5db);
LAB_080bea9e:
          if ((param_4 != (_STACK **)0x0) && (*param_4 != (_STACK *)0x0)) {
            return (_STACK *)0x0;
          }
          sk_free(local_20);
          return (_STACK *)0x0;
        }
      }
      else {
        if (iVar3 == 3) {
          if (*param_2 != '\0') goto LAB_080be959;
          if ((pcVar5[-2] != '\0') || (pcVar5[-1] != -1)) goto LAB_080be9ed;
        }
        else {
          cVar1 = pcVar5[-2];
          if (cVar1 != '\0') goto joined_r0x080be9f4;
          if (pcVar5[-1] != -1) goto LAB_080be959;
        }
        if (*(int *)(param_1 + 400) != 0) {
          ERR_put_error(0x14,0xa1,0x159,"ssl_lib.c",0x5b6);
          ssl3_send_alert(param_1,2,0x28);
          goto LAB_080bea9e;
        }
        *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x418) = 1;
      }
LAB_080be982:
      param_2 = param_2 + iVar3;
      bVar2 = local_24 < param_3;
      local_24 = local_24 + iVar3;
    } while (bVar2);
  }
  if (param_4 == (_STACK **)0x0) {
    return local_20;
  }
LAB_080beaf4:
  *param_4 = local_20;
  return local_20;
}

