
undefined4 bn_rand_range(int param_1,BIGNUM *param_2,BIGNUM *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  code *pcVar6;
  
  if (param_1 == 0) {
    pcVar6 = BN_rand;
  }
  else {
    pcVar6 = BN_pseudo_rand;
  }
  if ((param_3->neg == 0) && (param_3->top != 0)) {
    iVar2 = BN_num_bits(param_3);
    if (iVar2 == 1) {
      BN_set_word(param_2,0);
      return 1;
    }
    iVar3 = BN_is_bit_set(param_3,iVar2 + -2);
    if (iVar3 == 0) {
      iVar3 = BN_is_bit_set(param_3,iVar2 + -3);
      iVar4 = 100;
      if (iVar3 == 0) {
        while( true ) {
          iVar3 = (*pcVar6)(param_2,iVar2 + 1,0xffffffff,0);
          iVar4 = iVar4 + -1;
          if (iVar3 == 0) {
            return 0;
          }
          iVar3 = BN_cmp(param_2,param_3);
          if (-1 < iVar3) {
            iVar3 = (*(code *)PTR_BN_sub_006a96cc)(param_2,param_2,param_3);
            if (iVar3 == 0) {
              return 0;
            }
            iVar3 = BN_cmp(param_2,param_3);
            if ((-1 < iVar3) &&
               (iVar3 = (*(code *)PTR_BN_sub_006a96cc)(param_2,param_2,param_3), iVar3 == 0)) {
              return 0;
            }
          }
          if (iVar4 == 0) break;
          iVar3 = BN_cmp(param_2,param_3);
          if (iVar3 < 0) {
            return 1;
          }
        }
        uVar5 = 0x71;
        uVar1 = 0x10d;
        goto LAB_004fb738;
      }
    }
    iVar3 = 100;
    while( true ) {
      iVar4 = (*pcVar6)(param_2,iVar2,0xffffffff,0);
      iVar3 = iVar3 + -1;
      if (iVar4 == 0) {
        return 0;
      }
      if (iVar3 == 0) break;
      iVar4 = BN_cmp(param_2,param_3);
      if (iVar4 < 0) {
        return 1;
      }
    }
    (*(code *)PTR_ERR_put_error_006a9030)(3,0x7a,0x71,"bn_rand.c",0x11d);
    return 0;
  }
  uVar5 = 0x73;
  uVar1 = 0xee;
LAB_004fb738:
  (*(code *)PTR_ERR_put_error_006a9030)(3,0x7a,uVar5,"bn_rand.c",uVar1);
  return 0;
}

