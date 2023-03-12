
X509 * X509_find_by_issuer_and_serial(stack_st_X509 *sk,X509_NAME *name,ASN1_INTEGER *serial)

{
  int iVar1;
  X509 *pXVar2;
  int iVar3;
  X509_CINF *pXVar4;
  X509_NAME *pXVar5;
  
  if (sk == (stack_st_X509 *)0x0) {
    return (X509 *)0x0;
  }
  iVar3 = 0;
  iVar1 = (*(code *)PTR_sk_num_006a6e2c)(sk);
  if (0 < iVar1) {
    do {
      pXVar2 = (X509 *)(*(code *)PTR_sk_value_006a6e24)(sk,iVar3);
      pXVar4 = pXVar2->cert_info;
      iVar1 = ASN1_STRING_cmp(pXVar4->serialNumber,serial);
      if (iVar1 == 0) {
        pXVar5 = pXVar4->issuer;
        if ((pXVar5->canon_enc == (uchar *)0x0) || (pXVar5->modified != 0)) {
          iVar1 = (*(code *)PTR_i2d_X509_NAME_006a76ec)(pXVar5,0);
          if (iVar1 < 0) goto LAB_00576008;
        }
        if ((name->canon_enc == (uchar *)0x0) || (name->modified != 0)) {
          iVar1 = (*(code *)PTR_i2d_X509_NAME_006a76ec)(name,0);
          if (iVar1 < 0) goto LAB_00576008;
        }
        if (pXVar5->canon_enclen == name->canon_enclen) {
          iVar1 = (*(code *)PTR_memcmp_006a9ad0)(pXVar5->canon_enc,name->canon_enc);
          if (iVar1 == 0) {
            return pXVar2;
          }
        }
      }
LAB_00576008:
      iVar3 = iVar3 + 1;
      iVar1 = (*(code *)PTR_sk_num_006a6e2c)(sk);
    } while (iVar3 < iVar1);
  }
  return (X509 *)0x0;
}

