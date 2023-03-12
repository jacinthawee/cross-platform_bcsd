
undefined4 eckey_pub_cmp(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar1 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(*(undefined4 *)(param_2 + 0x14));
  uVar2 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(*(undefined4 *)(param_1 + 0x14));
  uVar3 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(*(undefined4 *)(param_2 + 0x14));
  iVar4 = (*(code *)PTR_EC_POINT_cmp_006a8610)(uVar1,uVar2,uVar3,0);
  uVar1 = 0xfffffffe;
  if (iVar4 != 0) {
    if (iVar4 == 1) {
      uVar1 = 0;
    }
    return uVar1;
  }
  return 1;
}

