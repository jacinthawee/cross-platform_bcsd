
void timeout_LHASH_DOALL_ARG(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  
  if ((param_2[1] == 0) || (*(int *)(param_1 + 0xac) + *(int *)(param_1 + 0xa8) < param_2[1])) {
    (*(code *)PTR_lh_delete_006a94ac)(param_2[2],param_1);
    iVar1 = *(int *)(param_1 + 0xcc);
    iVar3 = *param_2;
    if (iVar1 != 0) {
      iVar2 = *(int *)(param_1 + 200);
      if (iVar2 != 0) {
        if (iVar1 == iVar3 + 0x1c) {
          if (iVar2 == iVar3 + 0x18) {
            *(undefined4 *)(iVar3 + 0x18) = 0;
            *(undefined4 *)(iVar3 + 0x1c) = 0;
          }
          else {
            *(int *)(iVar3 + 0x1c) = iVar2;
            *(int *)(iVar2 + 0xcc) = iVar1;
          }
        }
        else if (iVar2 == iVar3 + 0x18) {
          *(int *)(iVar3 + 0x18) = iVar1;
          *(int *)(iVar1 + 200) = iVar2;
        }
        else {
          *(int *)(iVar1 + 200) = iVar2;
          *(int *)(*(int *)(param_1 + 200) + 0xcc) = iVar1;
        }
        *(undefined4 *)(param_1 + 0xcc) = 0;
        *(undefined4 *)(param_1 + 200) = 0;
        iVar3 = *param_2;
      }
    }
    pcVar4 = *(code **)(iVar3 + 0x2c);
    *(undefined4 *)(param_1 + 0x94) = 1;
    if (pcVar4 != (code *)0x0) {
      (*pcVar4)(iVar3,param_1);
    }
    iVar1 = CRYPTO_add_lock((int *)(param_1 + 0xa4),-1,0xe,"ssl_sess.c",0x2e4);
    if (iVar1 < 1) {
      SSL_SESSION_free_part_2(param_1);
      return;
    }
  }
  return;
}

