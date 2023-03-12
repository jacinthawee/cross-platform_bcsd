
int i2d_RSA_PSS_PARAMS(RSA_PSS_PARAMS *a,uchar **out)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00513350. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a979c)(a,out,RSA_PSS_PARAMS_it);
  return iVar1;
}

