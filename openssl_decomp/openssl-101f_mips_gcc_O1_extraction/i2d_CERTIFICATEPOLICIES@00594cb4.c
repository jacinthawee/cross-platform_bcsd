
int i2d_CERTIFICATEPOLICIES(CERTIFICATEPOLICIES *a,uchar **out)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00594cc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a979c)(a,out,CERTIFICATEPOLICIES_it);
  return iVar1;
}

