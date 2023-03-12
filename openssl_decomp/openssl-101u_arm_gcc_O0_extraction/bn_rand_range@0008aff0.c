
int bn_rand_range(int param_1,BIGNUM *param_2,BIGNUM *param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  pcVar1 = BN_rand;
  if (param_1 != 0) {
    pcVar1 = BN_pseudo_rand;
  }
  if ((param_3->neg == 0) && (param_3->top != 0)) {
    iVar4 = BN_num_bits(param_3);
    if (iVar4 != 1) {
      iVar2 = BN_is_bit_set(param_3,iVar4 + -2);
      if ((iVar2 == 0) && (iVar2 = BN_is_bit_set(param_3,iVar4 + -3), iVar2 == 0)) {
        iVar2 = 100;
        do {
          iVar3 = (*(pcVar1 + 1))(param_2,iVar4 + 1,0xffffffff,0);
          if (iVar3 == 0) {
            return 0;
          }
          iVar3 = BN_cmp(param_2,param_3);
          if (-1 < iVar3) {
            iVar3 = BN_sub(param_2,param_2,param_3);
            if (iVar3 == 0) {
              return 0;
            }
            iVar3 = BN_cmp(param_2,param_3);
            if ((-1 < iVar3) && (iVar3 = BN_sub(param_2,param_2,param_3), iVar3 == 0)) {
              return 0;
            }
          }
          iVar2 = iVar2 + -1;
          if (iVar2 == 0) {
            ERR_put_error(3,0x7a,0x71,"bn_rand.c",0x103);
            return 0;
          }
          iVar3 = BN_cmp(param_2,param_3);
        } while (-1 < iVar3);
      }
      else {
        iVar2 = 100;
        do {
          iVar3 = (*(pcVar1 + 1))(param_2,iVar4,0xffffffff,0);
          if (iVar3 == 0) {
            return 0;
          }
          iVar2 = iVar2 + -1;
          if (iVar2 == 0) {
            ERR_put_error(3,0x7a,0x71,"bn_rand.c",0x110);
            return 0;
          }
          iVar3 = BN_cmp(param_2,param_3);
        } while (-1 < iVar3);
      }
      return 1;
    }
    BN_set_word(param_2,0);
  }
  else {
    iVar4 = 0;
    ERR_put_error(3,0x7a,0x73,"bn_rand.c",0xe2);
  }
  return iVar4;
}

