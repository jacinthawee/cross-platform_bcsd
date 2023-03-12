
X509_EXTENSION * OCSP_accept_responses_new(char **oids)

{
  int iVar1;
  int iVar2;
  X509_EXTENSION *pXVar3;
  
  iVar1 = (*(code *)PTR_sk_new_null_006a80a4)();
  if (iVar1 == 0) {
    pXVar3 = (X509_EXTENSION *)0x0;
  }
  else {
    while (oids != (char **)0x0) {
      while( true ) {
        if (*oids == (char *)0x0) goto LAB_005aebc4;
        oids = oids + 1;
        iVar2 = (*(code *)PTR_OBJ_txt2nid_006a805c)();
        if ((iVar2 == 0) || (iVar2 = (*(code *)PTR_OBJ_nid2obj_006a8240)(iVar2), iVar2 == 0)) break;
        (*(code *)PTR_sk_push_006a80a8)(iVar1,iVar2);
        if (oids == (char **)0x0) goto LAB_005aebc4;
      }
    }
LAB_005aebc4:
    pXVar3 = (X509_EXTENSION *)(*(code *)PTR_X509V3_EXT_i2d_006aa130)(0x170,0,iVar1);
    (*(code *)PTR_sk_pop_free_006a8158)(iVar1,PTR_ASN1_OBJECT_free_006a8104);
  }
  return pXVar3;
}

