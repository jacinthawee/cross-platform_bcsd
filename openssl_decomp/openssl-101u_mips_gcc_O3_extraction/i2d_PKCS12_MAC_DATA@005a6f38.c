
int i2d_PKCS12_MAC_DATA(PKCS12_MAC_DATA *a,uchar **out)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005a6f48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a8678)(a,out,PKCS12_MAC_DATA_it);
  return iVar1;
}

