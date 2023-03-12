
undefined4 ssl3_send_alert(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = (**(code **)(*(int *)(param_1[2] + 100) + 0x30))(param_3);
  if ((*param_1 == 0x300) && (iVar2 == 0x46)) {
    iVar2 = 0x28;
  }
  else if (iVar2 < 0) {
    return 0xffffffff;
  }
  if ((param_2 == 2) && ((SSL_CTX *)param_1[0x30] != (SSL_CTX *)0x0)) {
    SSL_CTX_remove_session((SSL_CTX *)param_1[0x30],(SSL_SESSION *)param_1[0x39]);
  }
  iVar1 = param_1[0x16];
  *(char *)(iVar1 + 400) = (char)param_2;
  *(undefined4 *)(iVar1 + 0x18c) = 1;
  *(char *)(param_1[0x16] + 0x191) = (char)iVar2;
  if (*(int *)(param_1[0x16] + 0x108) != 0) {
    return 0xffffffff;
  }
                    /* WARNING: Could not recover jumptable at 0x080a8e03. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (**(code **)(param_1[2] + 0x3c))();
  return uVar3;
}

