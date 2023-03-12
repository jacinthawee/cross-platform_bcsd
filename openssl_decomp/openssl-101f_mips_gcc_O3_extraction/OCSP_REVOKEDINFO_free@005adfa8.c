
void OCSP_REVOKEDINFO_free(OCSP_REVOKEDINFO *a)

{
                    /* WARNING: Could not recover jumptable at 0x005adfb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_ASN1_item_free_006a977c)(a,OCSP_REVOKEDINFO_it);
  return;
}

