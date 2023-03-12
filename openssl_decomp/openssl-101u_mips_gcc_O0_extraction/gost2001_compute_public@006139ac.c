
undefined4 gost2001_compute_public(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  iVar1 = (*(code *)PTR_EC_KEY_get0_group_006a7690)();
  if (iVar1 == 0) {
    ERR_GOST_error(0x68,0x72,"gost2001.c",0x187);
    return 0;
  }
  iVar2 = (*(code *)PTR_BN_CTX_new_006a794c)();
  if (iVar2 == 0) {
    ERR_GOST_error(0x68,0x41,"gost2001.c",0x18c);
    return 0;
  }
  (*(code *)PTR_BN_CTX_start_006a8528)(iVar2);
  iVar3 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(param_1);
  if (iVar3 == 0) {
    uVar6 = 0;
    ERR_GOST_error(0x68,0x10,"gost2001.c",0x191);
    goto LAB_00613a9c;
  }
  iVar4 = (*(code *)PTR_EC_POINT_new_006a7fc0)(iVar1);
  if (iVar4 == 0) {
    uVar6 = 0;
    ERR_GOST_error(0x68,0x41,"gost2001.c",0x197);
    goto LAB_00613a9c;
  }
  iVar1 = (*(code *)PTR_EC_POINT_mul_006a8648)(iVar1,iVar4,iVar3,0,0,iVar2);
  if (iVar1 == 0) {
    uVar5 = 0x19b;
LAB_00613a70:
    uVar6 = 0;
    ERR_GOST_error(0x68,0x10,"gost2001.c",uVar5);
  }
  else {
    iVar1 = (*(code *)PTR_EC_KEY_set_public_key_006a8068)(param_1,iVar4);
    if (iVar1 == 0) {
      uVar5 = 0x19f;
      goto LAB_00613a70;
    }
    uVar6 = 0x100;
  }
  (*(code *)PTR_EC_POINT_free_006a7fac)(iVar4);
LAB_00613a9c:
  (*(code *)PTR_BN_CTX_end_006a8530)(iVar2);
  (*(code *)PTR_BN_CTX_free_006a7954)(iVar2);
  return uVar6;
}

