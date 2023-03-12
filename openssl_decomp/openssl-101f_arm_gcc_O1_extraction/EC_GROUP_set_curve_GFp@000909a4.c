
int EC_GROUP_set_curve_GFp(EC_GROUP *group,BIGNUM *p,BIGNUM *a,BIGNUM *b,BN_CTX *ctx)

{
  int iVar1;
  
  if (*(code **)(*(int *)group + 0x18) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000909b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(*(int *)group + 0x18))();
    return iVar1;
  }
  ERR_put_error(0x10,0x6d,0x42,"ec_lib.c",0x19b);
  return 0;
}

