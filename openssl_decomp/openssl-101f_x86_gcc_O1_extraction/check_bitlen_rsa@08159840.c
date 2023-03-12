
int __regparm3 check_bitlen_rsa(int param_1,int param_2,undefined4 *param_3)

{
  BIGNUM *a;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = BN_num_bits(*(BIGNUM **)(param_1 + 0x14));
  if (iVar1 < 0x21) {
    iVar1 = BN_num_bits(*(BIGNUM **)(param_1 + 0x10));
    iVar2 = BN_num_bits(*(BIGNUM **)(param_1 + 0x10));
    iVar3 = BN_num_bits(*(BIGNUM **)(param_1 + 0x10));
    if (param_2 != 0) {
      *param_3 = 0x31415352;
      return iVar1;
    }
    a = *(BIGNUM **)(param_1 + 0x18);
    *param_3 = 0x32415352;
    iVar4 = BN_num_bits(a);
    iVar5 = iVar2 + 7;
    if (iVar2 + 7 < 0) {
      iVar5 = iVar2 + 0xe;
    }
    iVar2 = iVar4 + 7;
    if (iVar4 + 7 < 0) {
      iVar2 = iVar4 + 0xe;
    }
    if (iVar2 >> 3 <= iVar5 >> 3) {
      iVar5 = BN_num_bits(*(BIGNUM **)(param_1 + 0x2c));
      iVar3 = iVar3 + 0xf >> 4;
      iVar2 = iVar5 + 7;
      if (iVar5 + 7 < 0) {
        iVar2 = iVar5 + 0xe;
      }
      if (iVar2 >> 3 <= iVar3) {
        iVar5 = BN_num_bits(*(BIGNUM **)(param_1 + 0x1c));
        iVar2 = iVar5 + 7;
        if (iVar5 + 7 < 0) {
          iVar2 = iVar5 + 0xe;
        }
        if (iVar2 >> 3 <= iVar3) {
          iVar5 = BN_num_bits(*(BIGNUM **)(param_1 + 0x20));
          iVar2 = iVar5 + 7;
          if (iVar5 + 7 < 0) {
            iVar2 = iVar5 + 0xe;
          }
          if (iVar2 >> 3 <= iVar3) {
            iVar5 = BN_num_bits(*(BIGNUM **)(param_1 + 0x24));
            iVar2 = iVar5 + 7;
            if (iVar5 + 7 < 0) {
              iVar2 = iVar5 + 0xe;
            }
            if ((iVar2 >> 3 <= iVar3) &&
               (iVar2 = BN_num_bits(*(BIGNUM **)(param_1 + 0x28)), (iVar2 + 7) / 8 <= iVar3)) {
              return iVar1;
            }
          }
        }
      }
    }
  }
  ERR_put_error(9,0x83,0x7e,"pvkfmt.c",0x25e);
  return 0;
}

