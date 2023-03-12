
undefined4 ssl_add_clienthello_use_srtp_ext(int param_1,undefined *param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  
  if (param_1 == 0) {
    iVar7 = 0;
    iVar1 = (*(code *)PTR_sk_num_006a7f2c)(0);
  }
  else {
    iVar7 = *(int *)(param_1 + 0x17c);
    if ((iVar7 == 0) && (*(int *)(param_1 + 0xe4) != 0)) {
      iVar7 = *(int *)(*(int *)(param_1 + 0xe4) + 0x1b4);
    }
    iVar1 = (*(code *)PTR_sk_num_006a7f2c)(iVar7);
  }
  if (param_2 != (undefined *)0x0) {
    if (iVar1 == 0) {
      uVar4 = 0x162;
      uVar3 = 0x116;
    }
    else {
      iVar8 = (iVar1 + 1) * 2;
      if (iVar8 < param_4) {
        puVar9 = param_2 + 2;
        param_2[1] = (char)(iVar1 * 2);
        *param_2 = (char)((uint)(iVar8 + -2) >> 8);
        if (0 < iVar1) {
          iVar6 = 0;
          puVar5 = puVar9;
          do {
            iVar2 = (*(code *)PTR_sk_value_006a7f24)(iVar7,iVar6);
            iVar6 = iVar6 + 1;
            *puVar5 = (char)((uint)*(undefined4 *)(iVar2 + 4) >> 8);
            puVar5[1] = (char)*(undefined4 *)(iVar2 + 4);
            puVar5 = puVar5 + 2;
          } while (iVar1 != iVar6);
          puVar9 = puVar9 + iVar1 * 2;
        }
        *puVar9 = 0;
        goto LAB_004a8b68;
      }
      uVar4 = 0x16b;
      uVar3 = 0x11c;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x133,uVar4,"d1_srtp.c",uVar3);
    return 1;
  }
  iVar8 = (iVar1 + 1) * 2;
LAB_004a8b68:
  *param_3 = iVar8 + 1;
  return 0;
}

