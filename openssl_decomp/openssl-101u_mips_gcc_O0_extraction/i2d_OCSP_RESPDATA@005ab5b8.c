
int i2d_OCSP_RESPDATA(OCSP_RESPDATA *a,uchar **out)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005ab5c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a8678)(a,out,OCSP_RESPDATA_it);
  return iVar1;
}

