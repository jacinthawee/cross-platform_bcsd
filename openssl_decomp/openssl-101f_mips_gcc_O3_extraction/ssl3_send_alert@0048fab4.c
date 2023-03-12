
undefined4 ssl3_send_alert(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined uVar3;
  
  iVar1 = (**(code **)(*(int *)(param_1[2] + 100) + 0x30))(param_3);
  if ((*param_1 == 0x300) && (iVar1 == 0x46)) {
    uVar3 = 0x28;
  }
  else {
    uVar3 = (undefined)iVar1;
    if (iVar1 < 0) {
      return 0xffffffff;
    }
  }
  if ((param_2 == 2) && (param_1[0x30] != 0)) {
    (*(code *)PTR_SSL_CTX_remove_session_006a9250)(param_1[0x39]);
  }
  iVar1 = param_1[0x16];
  *(char *)(iVar1 + 400) = (char)param_2;
  *(undefined4 *)(iVar1 + 0x18c) = 1;
  *(undefined *)(param_1[0x16] + 0x191) = uVar3;
  if (*(int *)(param_1[0x16] + 0x108) != 0) {
    return 0xffffffff;
  }
                    /* WARNING: Could not recover jumptable at 0x0048fb54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(param_1[2] + 0x3c))(param_1);
  return uVar2;
}

