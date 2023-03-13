
int EC_GROUP_get_curve_GFp(EC_GROUP *group,BIGNUM *p,BIGNUM *a,BIGNUM *b,BN_CTX *ctx)

{
  int iVar1;
  
  if (*(code **)(*(int *)group + 0x1c) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00501a68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(*(int *)group + 0x1c))();
    return iVar1;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x82,0x42,"ec_lib.c",0x18e);
  return 0;
}

