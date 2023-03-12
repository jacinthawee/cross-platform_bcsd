
int ECDSA_sign(int type,uchar *dgst,int dgstlen,uchar *sig,uint *siglen,EC_KEY *eckey)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uchar **buf;
  int iVar5;
  code *pcVar6;
  uchar *puStack_34;
  undefined4 *local_30;
  undefined4 uStack_2c;
  undefined *local_28;
  undefined4 uStack_24;
  uchar *local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_28 = &_gp;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  buf = (uchar **)dgstlen;
  iVar5 = dgstlen;
  local_20 = sig;
  RAND_seed(dgst,dgstlen);
  iVar2 = (**(code **)(local_28 + -0x6650))(eckey);
  if (iVar2 != 0) {
    sig = (uchar *)0x0;
    local_30 = (undefined4 *)eckey;
    iVar5 = 0;
    iVar2 = (**(code **)(*(int *)(iVar2 + 0xc) + 4))(dgst);
    buf = (uchar **)dgstlen;
    if (iVar2 != 0) {
      buf = &local_20;
      uVar3 = (**(code **)(local_28 + -0x664c))(iVar2);
      pcVar6 = *(code **)(local_28 + -0x6648);
      *siglen = uVar3;
      (*pcVar6)(iVar2);
      iVar2 = 1;
      goto LAB_00516ea4;
    }
  }
  *siglen = 0;
  iVar2 = 0;
LAB_00516ea4:
  if (local_1c == *(int *)puVar1) {
    return iVar2;
  }
  (**(code **)(local_28 + -0x5328))();
  puStack_34 = sig;
  RAND_seed(buf,iVar5);
  iVar2 = (*(code *)PTR_ecdsa_check_006a9890)(uStack_24);
  if (iVar2 != 0) {
    iVar5 = (**(code **)(*(int *)(iVar2 + 0xc) + 4))(buf,iVar5,uStack_2c,local_28,uStack_24);
    if (iVar5 != 0) {
      uVar4 = (*(code *)PTR_i2d_ECDSA_SIG_006a9894)(iVar5,&puStack_34);
      puVar1 = PTR_ECDSA_SIG_free_006a9898;
      *local_30 = uVar4;
      (*(code *)puVar1)(iVar5);
      return 1;
    }
  }
  *local_30 = 0;
  return 0;
}

