
undefined4 check_bitlen_rsa(int param_1,int param_2,undefined4 *param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar2 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(param_1 + 0x14));
  if (iVar2 < 0x21) {
    uVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(param_1 + 0x10));
    iVar2 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(param_1 + 0x10));
    iVar4 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(param_1 + 0x10));
    puVar1 = PTR_BN_num_bits_006a82f4;
    if (param_2 != 0) {
      *param_3 = 0x31415352;
      return uVar3;
    }
    uVar6 = *(undefined4 *)(param_1 + 0x18);
    *param_3 = 0x32415352;
    iVar5 = (*(code *)puVar1)(uVar6);
    iVar7 = iVar2 + 7;
    if (iVar2 + 7 < 0) {
      iVar7 = iVar2 + 0xe;
    }
    iVar2 = iVar5 + 7;
    if (iVar5 + 7 < 0) {
      iVar2 = iVar5 + 0xe;
    }
    if (iVar2 >> 3 <= iVar7 >> 3) {
      iVar7 = iVar4 + 0xf >> 4;
      iVar4 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(param_1 + 0x2c));
      iVar2 = iVar4 + 7;
      if (iVar4 + 7 < 0) {
        iVar2 = iVar4 + 0xe;
      }
      if (iVar2 >> 3 <= iVar7) {
        iVar4 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(param_1 + 0x1c));
        iVar2 = iVar4 + 7;
        if (iVar4 + 7 < 0) {
          iVar2 = iVar4 + 0xe;
        }
        if (iVar2 >> 3 <= iVar7) {
          iVar4 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(param_1 + 0x20));
          iVar2 = iVar4 + 7;
          if (iVar4 + 7 < 0) {
            iVar2 = iVar4 + 0xe;
          }
          if (iVar2 >> 3 <= iVar7) {
            iVar4 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(param_1 + 0x24));
            iVar2 = iVar4 + 7;
            if (iVar4 + 7 < 0) {
              iVar2 = iVar4 + 0xe;
            }
            if (iVar2 >> 3 <= iVar7) {
              iVar4 = (*(code *)PTR_BN_num_bits_006a82f4)(*(undefined4 *)(param_1 + 0x28));
              iVar2 = iVar4 + 7;
              if (iVar4 + 7 < 0) {
                iVar2 = iVar4 + 0xe;
              }
              if (iVar2 >> 3 <= iVar7) {
                return uVar3;
              }
            }
          }
        }
      }
    }
  }
  (*(code *)PTR_ERR_put_error_006a9030)(9,0x83,0x7e,FUN_0066ce4c,0x25e);
  return 0;
}

