
uint TS_check_signer_name(int *param_1,int *param_2)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int **ppiVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  uint uVar10;
  int *piVar11;
  undefined4 local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_30 = 0xffffffff;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (*param_1 == 4) {
    piVar9 = *(int **)(*param_2 + 0x14);
    iVar2 = (*(code *)PTR_X509_NAME_cmp_006a8030)(param_1[1]);
    if (iVar2 == 0) {
      uVar3 = 1;
      goto LAB_005c3490;
    }
  }
  piVar9 = (int *)&DAT_00000055;
  iVar2 = (*(code *)PTR_X509_get_ext_d2i_006a9024)(param_2,0x55,0,&local_30);
  uVar3 = 0;
  while (iVar2 != 0) {
    uVar3 = 0;
    do {
      uVar10 = uVar3;
      iVar4 = (*(code *)PTR_sk_num_006a6e2c)(iVar2);
      if (iVar4 <= (int)uVar10) {
        uVar3 = 0;
        goto LAB_005c3458;
      }
      uVar5 = (*(code *)PTR_sk_value_006a6e24)(iVar2,uVar10);
      piVar9 = param_1;
      iVar4 = (*(code *)PTR_GENERAL_NAME_cmp_006a8ef8)(uVar5);
      uVar3 = uVar10 + 1;
    } while (iVar4 != 0);
    uVar3 = ~uVar10 >> 0x1f;
    if (-1 < (int)uVar10) {
      (*(code *)PTR_GENERAL_NAMES_free_006a73a0)(iVar2);
      break;
    }
LAB_005c3458:
    (*(code *)PTR_GENERAL_NAMES_free_006a73a0)(iVar2);
    piVar9 = (int *)&DAT_00000055;
    iVar2 = (*(code *)PTR_X509_get_ext_d2i_006a9024)(param_2,0x55,0,&local_30);
  }
LAB_005c3490:
  if (local_2c == *(int *)puVar1) {
    return uVar3;
  }
  iVar2 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  uVar3 = 0;
  while( true ) {
    iVar4 = (*(code *)PTR_sk_num_006a6e2c)(iVar2);
    if (iVar4 <= (int)uVar3) {
      return 0xffffffff;
    }
    ppiVar6 = (int **)(*(code *)PTR_sk_value_006a6e24)(iVar2,uVar3);
    if (((**ppiVar6 == 0x14) &&
        (iVar4 = (*(code *)PTR_memcmp_006a9ad0)((*ppiVar6)[2],piVar9 + 0x14,0x14), iVar4 == 0)) &&
       ((piVar11 = ppiVar6[1], piVar11 == (int *)0x0 ||
        ((((iVar4 = *piVar9, iVar4 != 0 &&
           (iVar7 = (*(code *)PTR_sk_num_006a6e2c)(*piVar11), iVar7 == 1)) &&
          (piVar8 = (int *)(*(code *)PTR_sk_value_006a6e24)(*piVar11,0), *piVar8 == 4)) &&
         ((iVar7 = (*(code *)PTR_X509_NAME_cmp_006a8030)(piVar8[1],*(undefined4 *)(iVar4 + 0xc)),
          iVar7 == 0 &&
          (iVar4 = (*(code *)PTR_ASN1_INTEGER_cmp_006a8d38)(piVar11[1],*(undefined4 *)(iVar4 + 4)),
          iVar4 == 0)))))))) break;
    uVar3 = uVar3 + 1;
  }
  return uVar3;
}

