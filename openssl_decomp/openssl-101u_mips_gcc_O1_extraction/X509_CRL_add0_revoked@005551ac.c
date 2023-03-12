
int X509_CRL_add0_revoked(X509_CRL *crl,X509_REVOKED *rev)

{
  int iVar1;
  stack_st_X509_REVOKED *psVar2;
  X509_CRL_INFO *pXVar3;
  
  pXVar3 = crl->crl;
  psVar2 = pXVar3->revoked;
  if (psVar2 == (stack_st_X509_REVOKED *)0x0) {
    psVar2 = (stack_st_X509_REVOKED *)(*(code *)PTR_sk_new_006a806c)(X509_REVOKED_cmp);
    pXVar3->revoked = psVar2;
    if (psVar2 == (stack_st_X509_REVOKED *)0x0) goto LAB_00555224;
  }
  iVar1 = (*(code *)PTR_sk_push_006a6fa8)(psVar2,rev);
  if (iVar1 != 0) {
    (pXVar3->enc).modified = 1;
    return 1;
  }
LAB_00555224:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xa9,0x41,"x_crl.c",0x16c);
  return 0;
}

