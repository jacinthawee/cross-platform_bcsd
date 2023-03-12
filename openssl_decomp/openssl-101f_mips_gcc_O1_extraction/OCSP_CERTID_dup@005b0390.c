
OCSP_CERTID * OCSP_CERTID_dup(OCSP_CERTID *id)

{
  OCSP_CERTID *pOVar1;
  
                    /* WARNING: Could not recover jumptable at 0x005b03a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pOVar1 = (OCSP_CERTID *)(*(code *)PTR_ASN1_item_dup_006a9860)(PTR_OCSP_CERTID_it_006aa380,id);
  return pOVar1;
}

