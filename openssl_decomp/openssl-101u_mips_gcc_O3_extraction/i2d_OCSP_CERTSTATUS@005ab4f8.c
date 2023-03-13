
int i2d_OCSP_CERTSTATUS(OCSP_CERTSTATUS *a,uchar **out)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005ab508. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a8678)(a,out,OCSP_CERTSTATUS_it);
  return iVar1;
}

