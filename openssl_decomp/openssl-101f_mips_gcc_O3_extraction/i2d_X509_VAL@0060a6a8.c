
int i2d_X509_VAL(X509_VAL *a,uchar **out)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x0060a6b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a979c)(a,out,X509_VAL_it);
  return iVar1;
}

