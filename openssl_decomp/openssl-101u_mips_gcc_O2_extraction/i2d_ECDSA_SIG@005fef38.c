
int i2d_ECDSA_SIG(ECDSA_SIG *sig,uchar **pp)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005fef48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_ASN1_item_i2d_006a8678)(sig,pp,ECDSA_SIG_it);
  return iVar1;
}
