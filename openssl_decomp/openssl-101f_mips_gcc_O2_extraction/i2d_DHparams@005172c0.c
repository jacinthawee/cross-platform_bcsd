
int i2d_DHparams(DH *a,uchar **pp)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005172d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a979c)(a,pp,DHparams_it);
  return iVar1;
}

