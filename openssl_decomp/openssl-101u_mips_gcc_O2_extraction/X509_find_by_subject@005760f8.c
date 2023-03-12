
X509 * X509_find_by_subject(stack_st_X509 *sk,X509_NAME *name)

{
  bool bVar1;
  int iVar2;
  X509 *pXVar3;
  X509_NAME *pXVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar2 = (*(code *)PTR_sk_num_006a6e2c)(sk);
  bVar1 = 0 < iVar2;
  while( true ) {
    if (!bVar1) {
      return (X509 *)0x0;
    }
    pXVar3 = (X509 *)(*(code *)PTR_sk_value_006a6e24)(sk,iVar5);
    pXVar4 = pXVar3->cert_info->subject;
    if ((((pXVar4->canon_enc != (uchar *)0x0) && (pXVar4->modified == 0)) ||
        (iVar2 = (*(code *)PTR_i2d_X509_NAME_006a76ec)(pXVar4,0), -1 < iVar2)) &&
       ((((name->canon_enc != (uchar *)0x0 && (name->modified == 0)) ||
         (iVar2 = (*(code *)PTR_i2d_X509_NAME_006a76ec)(name,0), -1 < iVar2)) &&
        ((pXVar4->canon_enclen == name->canon_enclen &&
         (iVar2 = (*(code *)PTR_memcmp_006a9ad0)(pXVar4->canon_enc,name->canon_enc), iVar2 == 0)))))
       ) break;
    iVar5 = iVar5 + 1;
    iVar2 = (*(code *)PTR_sk_num_006a6e2c)(sk);
    bVar1 = iVar5 < iVar2;
  }
  return pXVar3;
}

