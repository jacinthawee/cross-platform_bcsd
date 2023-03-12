
undefined * SRP_check_known_gN_param(BIGNUM *param_1,BIGNUM *param_2)

{
  int iVar1;
  BIGNUM **ppBVar2;
  int iVar3;
  
  if (param_2 != (BIGNUM *)0x0 && param_1 != (BIGNUM *)0x0) {
    iVar3 = 0;
    ppBVar2 = (BIGNUM **)PTR_PTR_bn_generator_19_000ee128;
    do {
      iVar1 = BN_cmp(*ppBVar2,param_1);
      if ((iVar1 == 0) && (iVar1 = BN_cmp(ppBVar2[1],param_2), iVar1 == 0)) {
        return (&knowngN)[iVar3 * 3];
      }
      iVar3 = iVar3 + 1;
      ppBVar2 = ppBVar2 + 3;
    } while (iVar3 != 7);
  }
  return (undefined *)0x0;
}

