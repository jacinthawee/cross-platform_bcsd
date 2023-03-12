
int X509_CRL_get0_by_cert(X509_CRL *crl,X509_REVOKED **ret,X509 *x)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(crl->meth + 0xc);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
    uVar1 = (*(code *)PTR_X509_get_serialNumber_006a809c)(x);
    uVar2 = (*(code *)PTR_X509_get_issuer_name_006a87d0)(x);
                    /* WARNING: Could not recover jumptable at 0x005583e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar3 = (*UNRECOVERED_JUMPTABLE)(crl,ret,uVar1,uVar2);
    return iVar3;
  }
  return 0;
}

