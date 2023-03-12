
int i2d_DSAPrivateKey(DSA *a,uchar **pp)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00513890. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a8678)(a,pp,DSAPrivateKey_it);
  return iVar1;
}

