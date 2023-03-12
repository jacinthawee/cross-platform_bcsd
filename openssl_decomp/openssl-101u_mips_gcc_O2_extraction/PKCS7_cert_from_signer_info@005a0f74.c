
X509 * PKCS7_cert_from_signer_info(PKCS7 *p7,PKCS7_SIGNER_INFO *si)

{
  int iVar1;
  X509 *pXVar2;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7->type);
  if (iVar1 == 0x16) {
                    /* WARNING: Could not recover jumptable at 0x005a0fd4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pXVar2 = (X509 *)(*(code *)PTR_X509_find_by_issuer_and_serial_006a9138)
                               (((p7->d).data)->data,si->issuer_and_serial->issuer,
                                si->issuer_and_serial->serial);
    return pXVar2;
  }
  return (X509 *)0x0;
}

