
void timeout_LHASH_DOALL_ARG(void *param_1,int *param_2)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  
  if ((param_2[1] == 0) ||
     (*(int *)((int)param_1 + 0xa8) + *(int *)((int)param_1 + 0xac) < param_2[1])) {
    lh_delete((_LHASH *)param_2[2],param_1);
    iVar4 = *(int *)((int)param_1 + 0xcc);
    iVar3 = *param_2;
    if ((iVar4 != 0) && (iVar1 = *(int *)((int)param_1 + 200), iVar1 != 0)) {
      if (iVar4 == iVar3 + 0x1c) {
        if (iVar1 == iVar3 + 0x18) {
          *(undefined4 *)(iVar3 + 0x18) = 0;
          *(undefined4 *)(iVar3 + 0x1c) = 0;
        }
        else {
          *(int *)(iVar3 + 0x1c) = iVar1;
          *(int *)(iVar1 + 0xcc) = iVar4;
        }
      }
      else if (iVar1 == iVar3 + 0x18) {
        *(int *)(iVar3 + 0x18) = iVar4;
        *(int *)(iVar4 + 200) = iVar1;
      }
      else {
        *(int *)(iVar4 + 200) = iVar1;
        *(int *)(*(int *)((int)param_1 + 200) + 0xcc) = iVar4;
      }
      *(undefined4 *)((int)param_1 + 0xcc) = 0;
      *(undefined4 *)((int)param_1 + 200) = 0;
      iVar3 = *param_2;
    }
    pcVar2 = *(code **)(iVar3 + 0x2c);
    *(undefined4 *)((int)param_1 + 0x94) = 1;
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(iVar3,param_1);
    }
    iVar4 = CRYPTO_add_lock((int *)((int)param_1 + 0xa4),-1,0xe,"ssl_sess.c",0x2e4);
    if (iVar4 < 1) {
      SSL_SESSION_free_part_2();
      return;
    }
  }
  return;
}

