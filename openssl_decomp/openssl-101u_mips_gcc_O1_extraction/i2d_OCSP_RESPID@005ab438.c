
int i2d_OCSP_RESPID(OCSP_RESPID *a,uchar **out)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005ab448. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a8678)(a,out,OCSP_RESPID_it);
  return iVar1;
}
