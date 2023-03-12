
int ssl_bytes_to_cipher_list(int param_1,char *param_2,int param_3,int *param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  
  if (*(int *)(param_1 + 0x58) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x418) = 0;
  }
  iVar2 = (**(code **)(*(int *)(param_1 + 8) + 0x4c))(0,0);
  if (iVar2 == 0) {
    trap(7);
  }
  if (param_3 % iVar2 != 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xa1,0x97,"ssl_lib.c",0x59f);
    return 0;
  }
  if (param_4 == (int *)0x0) {
    iVar5 = (*(code *)PTR_sk_new_null_006a80a4)();
    if (param_3 < 1) {
      return iVar5;
    }
LAB_004abe6c:
    if (iVar2 != 3) goto LAB_004abe78;
LAB_004abffc:
    pcVar6 = param_2 + 3;
    iVar4 = 3;
    do {
      if ((((*(int *)(param_1 + 0x58) == 0) || (*param_2 != '\0')) || (pcVar6[-2] != '\0')) ||
         (pcVar6[-1] != -1)) {
        iVar3 = (**(code **)(*(int *)(param_1 + 8) + 0x48))(param_2);
        if ((iVar3 != 0) && (iVar3 = (*(code *)PTR_sk_push_006a80a8)(iVar5,iVar3), iVar3 == 0))
        goto LAB_004ac094;
      }
      else {
        if (*(int *)(param_1 + 400) != 0) goto LAB_004abf50;
        *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x418) = 1;
      }
      bVar1 = iVar4 < param_3;
      pcVar6 = pcVar6 + iVar2;
      iVar4 = iVar4 + 3;
      param_2 = param_2 + iVar2;
    } while (bVar1);
  }
  else {
    iVar5 = *param_4;
    if (iVar5 != 0) {
      (*(code *)PTR_sk_zero_006a9454)(iVar5);
      if (param_3 < 1) goto LAB_004abf18;
      goto LAB_004abe6c;
    }
    iVar5 = (*(code *)PTR_sk_new_null_006a80a4)();
    if (param_3 < 1) goto LAB_004abf18;
    if (iVar2 == 3) goto LAB_004abffc;
LAB_004abe78:
    param_2 = param_2 + iVar2;
    iVar4 = iVar2;
    do {
      while( true ) {
        if (((*(int *)(param_1 + 0x58) == 0) || (param_2[-2] != '\0')) || (param_2[-1] != -1))
        break;
        param_2 = param_2 + iVar2;
        if (*(int *)(param_1 + 400) != 0) goto LAB_004abf50;
        *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x418) = 1;
        bVar1 = param_3 <= iVar4;
        iVar4 = iVar4 + iVar2;
        if (bVar1) goto LAB_004abf10;
      }
      iVar3 = (**(code **)(*(int *)(param_1 + 8) + 0x48))((int)param_2 - iVar2);
      if ((iVar3 != 0) && (iVar3 = (*(code *)PTR_sk_push_006a80a8)(iVar5,iVar3), iVar3 == 0))
      goto LAB_004ac094;
      bVar1 = iVar4 < param_3;
      param_2 = param_2 + iVar2;
      iVar4 = iVar4 + iVar2;
    } while (bVar1);
  }
LAB_004abf10:
  if (param_4 == (int *)0x0) {
    return iVar5;
  }
LAB_004abf18:
  *param_4 = iVar5;
  return iVar5;
LAB_004ac094:
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xa1,0x41,"ssl_lib.c",0x5c6);
  goto LAB_004abf90;
LAB_004abf50:
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xa1,0x159,"ssl_lib.c",0x5b4);
  ssl3_send_alert(param_1,2,0x28);
LAB_004abf90:
  if ((param_4 == (int *)0x0) || (*param_4 == 0)) {
    (*(code *)PTR_sk_free_006a7f80)(iVar5);
  }
  return 0;
}

