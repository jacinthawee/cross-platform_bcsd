
undefined4 __regparm3 bn_rand_range(int param_1,BIGNUM *param_2,BIGNUM *param_3)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 local_20;
  
  pcVar2 = BN_rand;
  if (param_1 != 0) {
    pcVar2 = BN_pseudo_rand;
  }
  if ((param_3->neg == 0) && (param_3->top != 0)) {
    iVar3 = BN_num_bits(param_3);
    if (iVar3 != 1) {
      iVar4 = BN_is_bit_set(param_3,iVar3 + -2);
      if ((iVar4 == 0) && (iVar4 = BN_is_bit_set(param_3,iVar3 + -3), iVar4 == 0)) {
        iVar4 = 100;
        do {
          iVar1 = (*pcVar2)(param_2,iVar3 + 1,0xffffffff,0);
          if (iVar1 == 0) {
            return 0;
          }
          iVar1 = BN_cmp(param_2,param_3);
          if (-1 < iVar1) {
            iVar1 = BN_sub(param_2,param_2,param_3);
            if (iVar1 == 0) {
              return 0;
            }
            iVar1 = BN_cmp(param_2,param_3);
            if ((-1 < iVar1) && (iVar1 = BN_sub(param_2,param_2,param_3), iVar1 == 0)) {
              return 0;
            }
          }
          iVar4 = iVar4 + -1;
          if (iVar4 == 0) {
            iVar4 = 0x10d;
            iVar3 = 0x71;
            goto LAB_080fad79;
          }
          iVar1 = BN_cmp(param_2,param_3);
        } while (-1 < iVar1);
      }
      else {
        iVar4 = 100;
        do {
          iVar1 = (*pcVar2)(param_2,iVar3,0xffffffff,0);
          if (iVar1 == 0) {
            return 0;
          }
          iVar4 = iVar4 + -1;
          if (iVar4 == 0) {
            ERR_put_error(3,0x7a,0x71,"bn_rand.c",0x11d);
            return 0;
          }
          iVar1 = BN_cmp(param_2,param_3);
        } while (-1 < iVar1);
      }
      return 1;
    }
    BN_set_word(param_2,0);
    local_20 = 1;
  }
  else {
    iVar4 = 0xee;
    iVar3 = 0x73;
LAB_080fad79:
    ERR_put_error(3,0x7a,iVar3,"bn_rand.c",iVar4);
    local_20 = 0;
  }
  return local_20;
}

