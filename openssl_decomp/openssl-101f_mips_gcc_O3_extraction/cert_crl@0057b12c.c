
undefined cert_crl(int *param_1,int *param_2,undefined4 param_3)

{
  undefined *puVar1;
  undefined uVar5;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int local_18;
  int *local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(int **)PTR___stack_chk_guard_006aabf0;
  if ((param_2[4] & 0x200U) == 0) {
LAB_0057b1d4:
    piVar7 = &local_18;
    iVar2 = (*(code *)PTR_X509_CRL_get0_by_cert_006aa008)(param_2,piVar7,param_3);
    if (iVar2 != 0) {
      if (*(int *)(local_18 + 0x10) == 8) {
        uVar5 = 2;
      }
      else {
        param_1[0x19] = 0x17;
        iVar2 = (*(code *)param_1[8])(0);
        uVar5 = iVar2 != 0;
        piVar7 = param_1;
      }
      goto LAB_0057b188;
    }
  }
  else {
    piVar7 = param_2;
    if ((*(uint *)(param_1[5] + 0xc) & 0x10) == 0) {
      param_1[0x19] = 0x24;
      piVar7 = param_1;
      iVar2 = (*(code *)param_1[8])(0);
      if (iVar2 == 0) {
        uVar5 = 0;
        goto LAB_0057b188;
      }
      goto LAB_0057b1d4;
    }
  }
  uVar5 = 1;
LAB_0057b188:
  if (local_14 == *(int **)puVar1) {
    return uVar5;
  }
  piVar6 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar8 = piVar7[6];
  iVar2 = 0;
  do {
    iVar4 = (*(code *)PTR_sk_num_006a7f2c)(iVar8);
    if (iVar4 <= iVar2) {
      *piVar6 = 0;
      return 0;
    }
    iVar4 = (*(code *)PTR_sk_value_006a7f24)(iVar8,iVar2);
    iVar3 = (*(code *)piVar7[10])(piVar7,param_3,iVar4);
    iVar2 = iVar2 + 1;
  } while (iVar3 == 0);
  *piVar6 = iVar4;
  if (iVar4 == 0) {
    return 0;
  }
  (*(code *)PTR_CRYPTO_add_lock_006a9080)(iVar4 + 0x10,1,3,"x509_vfy.c",0x1b5);
  return 1;
}
