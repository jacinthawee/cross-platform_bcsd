
undefined4
ssl_parse_serverhello_use_srtp_ext(int param_1,short *param_2,int param_3,undefined4 *param_4)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  if (param_3 != 5) {
    uVar4 = 0x161;
    uVar3 = 0x18e;
    goto LAB_004a5ef0;
  }
  if (*param_2 != 2) {
    uVar4 = 0x161;
    uVar3 = 0x196;
    goto LAB_004a5ef0;
  }
  uVar1 = param_2[1];
  if (*(char *)(param_2 + 2) != '\0') {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x137,0x160,"d1_srtp.c",0x19e);
    *param_4 = 0x2f;
    return 1;
  }
  if (param_1 != 0) {
    iVar6 = *(int *)(param_1 + 0x17c);
    iVar5 = 0;
    if (iVar6 != 0) {
LAB_004a5ea0:
      while( true ) {
        iVar2 = (*(code *)PTR_sk_num_006a6e2c)(iVar6);
        if (iVar2 <= iVar5) break;
        iVar2 = (*(code *)PTR_sk_value_006a6e24)(iVar6,iVar5);
        iVar5 = iVar5 + 1;
        if ((uint)uVar1 == *(uint *)(iVar2 + 4)) {
          *(int *)(param_1 + 0x180) = iVar2;
          *param_4 = 0;
          return 0;
        }
      }
      uVar4 = 0x161;
      uVar3 = 0x1bc;
      goto LAB_004a5ef0;
    }
    if (*(int *)(param_1 + 0xe4) != 0) {
      iVar6 = *(int *)(*(int *)(param_1 + 0xe4) + 0x1b4);
      iVar5 = 0;
      if (iVar6 != 0) goto LAB_004a5ea0;
    }
  }
  uVar4 = 0x167;
  uVar3 = 0x1a8;
LAB_004a5ef0:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x137,uVar4,"d1_srtp.c",uVar3);
  *param_4 = 0x32;
  return 1;
}
